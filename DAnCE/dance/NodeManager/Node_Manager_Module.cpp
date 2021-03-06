// -*- C++ -*-
// $Id$

#include "ace/Get_Opt.h"
#include "ace/OS_NS_stdio.h"
#include "ace/Env_Value_T.h"
#include "tao/StringSeqC.h"
#include "tao/IORTable/IORTable.h"
#include "tao/Utils/PolicyList_Destroyer.h"
#include "orbsvcs/CosNamingC.h"
#include "dance/Logger/Log_Macros.h"
#include "dance/DAnCE_PropertiesC.h"
#include "Node_Manager_Module.h"
#include "NodeManager_Impl.h"
#include "Artifact_Installation/Artifact_Installation_Impl.h"
#include "Artifact_Installation/Artifact_Installation_Handler_Svc.h"
#include "Artifact_Installation/Installation_Repository_Manager_Impl.h"
#include "Artifact_Installation/File_Installation_Handler.h"
#include "Artifact_Installation/Http_Installation_Handler.h"

namespace DAnCE
{
  namespace Node_Manager
  {
    bool
    write_IOR (const ACE_TCHAR * ior_file_name, const char* ior)
    {
      FILE* ior_output_file_ = ACE_OS::fopen (ior_file_name, ACE_TEXT("w"));

      if (ior_output_file_)
        {
          ACE_OS::fprintf (ior_output_file_, "%s", ior);
          ACE_OS::fclose (ior_output_file_);
          return true;
        }
      return false;
    }
  }
}

DAnCE_NodeManager_Module::SOptions::SOptions(void)
  : process_ns_ (false),
    process_ns_file_ (0),
    create_plan_ns_ (false),
    create_plan_ns_ior_ (0),
    rebind_plan_ns_ (false),
    rebind_plan_ns_ior_ (0),
    cs_path_ (ACE_TEXT("dance_locality_manager")),
    timeout_ (5),
    server_args_ (0),
    domain_nc_ (0),
    instance_nc_ (0),
    locality_config_("")
{
  ACE_Env_Value<const ACE_TCHAR *> dance_env (ACE_TEXT ("DANCE_ROOT"),
                                              ACE_TEXT (""));
  node_config_ = ACE_TEXT_ALWAYS_CHAR (dance_env);
  node_config_ += "/bin/nodemanager.localityconfig";
}

DAnCE_NodeManager_Module::DAnCE_NodeManager_Module (void)
{
  DANCE_TRACE("DAnCE_NodeManager_Module::DAnCE_NodeManager_Module");
}

DAnCE_NodeManager_Module::~DAnCE_NodeManager_Module (void)
{
  DANCE_TRACE ("DAnCE_NodeManager_Module::~DAnCE_NodeManager_Module");

  for (Servant_Map::iterator it = this->nm_map_.begin ();
       it != this->nm_map_.end ();
       ++it)
    {
      delete (*it).int_id_;
    }
}

const char *
DAnCE_NodeManager_Module::usage (void)
{
  DANCE_TRACE ("DAnCE_NodeManager_Module::usage");
  return "Node Manager Options:\n"
    "\t-e|--exec-mgr\t\t [execution manager ior file name]\n"
    "\t-n|--node-mgr\t\t <node name> [=node manager ior file name]\n"
    "\t-c|--create-plan-ns [NC] create plan objects (components and ports) representation in name context with ior NC\n"
    "\t-r|--rebind-plan-ns [NC] bind plan representation name context to NC\n"
    "\t-i|--port-indirection\t enable plan objects indirection via servant locator\n"
    "\t-s|--server-executable\t default component server executable\n"
    "\t--server-args\t\t additional arguments to supply to the component server\n"
    "\t-t|--timeout\t\t default timeout in seconds to wait for component server spawn\n"
    "\t-d|--domain-nc [NC]\t Default naming context for domain objects.\n"
    "\t--instance-nc [NC]\t Default naming context for instance registration directives. No argument indicates Domain NC.\n"
    "\t--locality-config\t\t Provide a locality configuration file that is passed to all spawned locality managers.\n"
    "\t--node-config\t\t Provide a locality configuration file used to initialize the NodeManager.\n"
    "\t-h|help\t\t\t print this help message\n";
}

bool
DAnCE_NodeManager_Module::parse_args (int argc, ACE_TCHAR * argv[])
{
  ACE_Get_Opt get_opts (argc,
                        argv,
                        ACE_TEXT("e:n:p::c::r::is:t:h"),
                        0,
                        0,
                        ACE_Get_Opt::RETURN_IN_ORDER);

  get_opts.long_option (ACE_TEXT("exec-mgr"), 'e', ACE_Get_Opt::ARG_REQUIRED);
  get_opts.long_option (ACE_TEXT("node-mgr"), 'n', ACE_Get_Opt::ARG_REQUIRED);
  get_opts.long_option (ACE_TEXT("process-ns"), 'p', ACE_Get_Opt::ARG_OPTIONAL);
  get_opts.long_option (ACE_TEXT("create-plan-ns"), 'c', ACE_Get_Opt::ARG_OPTIONAL);
  get_opts.long_option (ACE_TEXT("rebind-plan-ns"), 'r', ACE_Get_Opt::ARG_OPTIONAL);
  get_opts.long_option (ACE_TEXT("port-indirection"), 'i', ACE_Get_Opt::NO_ARG);
  get_opts.long_option (ACE_TEXT("server-executable"), 's', ACE_Get_Opt::ARG_REQUIRED);
  get_opts.long_option (ACE_TEXT("server-args"), ACE_Get_Opt::ARG_REQUIRED);
  get_opts.long_option (ACE_TEXT("timeout"), 't', ACE_Get_Opt::ARG_REQUIRED);
  get_opts.long_option (ACE_TEXT("domain-nc"), 'd', ACE_Get_Opt::ARG_REQUIRED);
  get_opts.long_option (ACE_TEXT("locality-config"), ACE_Get_Opt::ARG_REQUIRED);
  get_opts.long_option (ACE_TEXT("help"), 'h', ACE_Get_Opt::NO_ARG);
  get_opts.long_option (ACE_TEXT("instance-nc"), ACE_Get_Opt::ARG_REQUIRED);
  get_opts.long_option (ACE_TEXT("node-config"), ACE_Get_Opt::ARG_REQUIRED);

  int c;
  while ( (c = get_opts ()) != -1)
    {
      switch (c)
        {
        case 'n':
          DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Provided Node Manager name: %s\n"), get_opts.opt_arg ()));
          this->options_.node_managers_.push_back (get_opts.opt_arg ());
          break;

        case 'p':
          DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Instructed to create process ns with file %s\n"), get_opts.opt_arg ()));
          this->options_.process_ns_ = true;
          this->options_.process_ns_file_ = get_opts.opt_arg ();
          break;

        case 'c':
          DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Instructed to create plan NS in context: %s\n"), get_opts.opt_arg ()));
          this->options_.create_plan_ns_ = true;
          this->options_.create_plan_ns_ior_ = get_opts.opt_arg ();
          break;

        case 'r':
          DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Instructed to rebind plan NS in context: %s\n"), get_opts.opt_arg ()));
          this->options_.rebind_plan_ns_ = true;
          this->options_.rebind_plan_ns_ior_ = get_opts.opt_arg ();
          break;

        case 'i':
          DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Instructed to create port indirection service\n")));
          this->options_.port_indirection_ = true;
          break;

        case 's':
          DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Using provided component server executable:%s\n"),
                        get_opts.opt_arg ()));
          this->options_.cs_path_ = get_opts.opt_arg ();
          break;

        case 't':
          DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Using provided component server spawn timeout:%s\n"),
                        get_opts.opt_arg ()));
          this->options_.timeout_ = ACE_OS::atoi (get_opts.opt_arg ());
          break;

        case 'd':
          DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Binding to provided Domain Naming Context: '%s'\n"),
                        get_opts.opt_arg ()));
          this->options_.domain_nc_ = get_opts.opt_arg ();
          break;

        case 'h':
          DANCE_ERROR (DANCE_LOG_EMERGENCY,
                       (LM_ERROR,
                        this->usage (), argv [0], c));
          return false;
          break;

        case 0:
          if (ACE_OS::strcmp (get_opts.long_option (),
                              ACE_TEXT("server-args")) == 0)
            {
              DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                           (LM_DEBUG, DLINFO
                            ACE_TEXT("Node_Manager_Module::parse_args - ")
                            ACE_TEXT("Using provided component server arguments: '%s'\n"),
                            get_opts.opt_arg ()));
              this->options_.server_args_ = get_opts.opt_arg ();
            }
          else if (ACE_OS::strcmp (get_opts.long_option (),
                                   ACE_TEXT("locality-config")) == 0)
            {
              DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                           (LM_DEBUG, DLINFO
                            ACE_TEXT("Node_Manager_Module::parse_args - ")
                            ACE_TEXT("Using locality configuration file <%s>\n"),
                            get_opts.opt_arg ()));
              this->options_.locality_config_ = ACE_TEXT_ALWAYS_CHAR (get_opts.opt_arg ());
            }
          else if (ACE_OS::strcmp (get_opts.long_option (),
                                   ACE_TEXT("node-config")) == 0)
            {
              DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Using locality configuration file for node: <%s>\n"),
                        get_opts.opt_arg ()));
              this->options_.node_config_ = ACE_TEXT_ALWAYS_CHAR (get_opts.opt_arg ());
            }
          else if (ACE_OS::strcmp (get_opts.long_option (),
                                   ACE_TEXT("instance-nc")) == 0)
            {
              if (get_opts.opt_arg () == 0)
                {
                  if (this->options_.domain_nc_ == 0)
                    {
                      DANCE_ERROR (DANCE_LOG_EMERGENCY,
                                   (LM_ERROR, DLINFO ACE_TEXT("Node_Manager_Module::parse_args - ")
                                    ACE_TEXT("ERROR: instance-nc provided no argument, ")
                                    ACE_TEXT("but domain-nc did not appear before.\n")));
                      DANCE_ERROR (DANCE_LOG_EMERGENCY,
                                   (LM_ERROR, this->usage (), argv[0], c));
                      return false;
                    }
                  DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Instance NC defaulting to Domain NC\n")));
                  this->options_.instance_nc_ = this->options_.domain_nc_;
                }
              else
                {
                  DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_DEBUG, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ")
                        ACE_TEXT("Using provided instance NC: %s\n"),
                        get_opts.opt_arg ()));
                  this->options_.instance_nc_ = get_opts.opt_arg ();
                }
            }
          else
            {
              DANCE_ERROR (DANCE_LOG_WARNING,
                           (LM_ERROR, DLINFO ACE_TEXT("Node_Manager_Module::parse_args - ")
                            ACE_TEXT("Ignoring unknown long option %s\n"),
                            get_opts.long_option ()));
            }

          break;

        default:
          DANCE_DEBUG (DANCE_LOG_WARNING,
                       (LM_TRACE, DLINFO
                        ACE_TEXT("Node_Manager_Module::parse_args - ignoring unknown option %c\n"),
                        c));
        }
    }
  return true;
}

CORBA::Object_ptr
DAnCE_NodeManager_Module::init (CORBA::ORB_ptr orb,
                                int argc,
                                ACE_TCHAR *argv[])
{
  try
    {
      if (CORBA::is_nil(orb))
        {
          DANCE_ERROR (DANCE_LOG_EMERGENCY,
                       (LM_ERROR, DLINFO
                        ACE_TEXT("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT("Attempted to create Node Manager with a nil orb.\n")));
          return CORBA::Object::_nil();
        }

      if (CORBA::is_nil(this->orb_.in()))
        {
          DANCE_TRACE_LOG (DANCE_LOG_DETAILED_TRACE,
                           (LM_TRACE, DLINFO ACE_TEXT("DAnCE_NodeManager_Module::init - ")
                            ACE_TEXT("NM's orb is nil.\n")));
          this->orb_ = CORBA::ORB::_duplicate (orb);
        }
      else if (ACE_OS::strcmp(orb->id(), this->orb_->id()) != 0)
        {
          DANCE_DEBUG (DANCE_LOG_DETAILED_TRACE,
                       (LM_TRACE, DLINFO
                        ACE_TEXT("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT("Resetting NM's orb.\n")));
          this->orb_ = CORBA::ORB::_duplicate (orb);
          this->domain_nc_ = CosNaming::NamingContext::_nil();
        }

      if (!this->parse_args (argc, argv))
        {
          DANCE_ERROR (DANCE_LOG_EMERGENCY,
                       (LM_ERROR, DLINFO
                        ACE_TEXT("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT("Unable to parse the commandline arguments.\n")));
          return CORBA::Object::_nil ();
        }

      this->register_value_factories ();
      this->create_poas ();

      if (this->options_.domain_nc_)
        {
          try
            {
              DANCE_TRACE_LOG (DANCE_LOG_TRACE,
                               (LM_TRACE, DLINFO ACE_TEXT("DAnCE_NodeManager_Module::init - ")
                                ACE_TEXT("Resolving DomainNC.\n")));
              CORBA::Object_var domain_obj = this->orb_->string_to_object (this->options_.domain_nc_);
              if (!CORBA::is_nil (domain_obj.in ()))
                {
                  this->domain_nc_ = CosNaming::NamingContext::_narrow (domain_obj.in());
                  if (CORBA::is_nil (this->domain_nc_.in ()))
                    {
                      DANCE_ERROR (DANCE_LOG_EMERGENCY,
                                   (LM_ERROR, DLINFO
                                    ACE_TEXT("DAnCE_NodeManager_Module::init - ")
                                    ACE_TEXT("Narrow to NamingContext return nil for DomainNC.\n")));
                      return CORBA::Object::_nil ();
                    }
                }
            }
          catch (const CORBA::Exception&)
            {
              DANCE_ERROR (DANCE_LOG_WARNING, (LM_WARNING, DLINFO
                                               ACE_TEXT("DAnCE_NodeManager_Module::init - ")
                                               ACE_TEXT("DomainNC context not found!\n")));
            }
        }

      DANCE_TRACE_LOG (DANCE_LOG_TRACE,
                       (LM_TRACE, DLINFO
                        ACE_TEXT("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT("Resolving plan NS naming context.\n")));

      CosNaming::NamingContext_var rebind_nc;
      if (this->options_.rebind_plan_ns_)
        {
          if (!this->options_.create_plan_ns_)
            {
              DANCE_ERROR (DANCE_LOG_EMERGENCY,
                           (LM_ERROR, DLINFO
                            ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                            ACE_TEXT ("Rebind_plan_ns option is enabled but Create_plan_ns is not.\n")));
              return CORBA::Object::_nil();
            }
          CORBA::Object_var tmp_obj;
          if (0 != this->options_.rebind_plan_ns_ior_)
            {
              tmp_obj = orb->string_to_object (this->options_.rebind_plan_ns_ior_);
              rebind_nc = CosNaming::NamingContext::_narrow (tmp_obj);
            }
          else
            {
              if (CORBA::is_nil (this->domain_nc_.in ()))
                {
                  DANCE_ERROR (DANCE_LOG_EMERGENCY,
                               (LM_ERROR, DLINFO
                                ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                                ACE_TEXT ("The rebind plan is enabled but neither NC ")
                                ACE_TEXT ("nor DomainNC are not supplied. No rebinding will be done.\n")
                                ACE_TEXT ("Use the \"-rebind-plan-ns NC ior\" ")
                                ACE_TEXT ("or \"-ORBInitRef DomainNC\" option.\n")));
                  return CORBA::Object::_nil ();
                }
              rebind_nc = CosNaming::NamingContext::_duplicate (this->domain_nc_.in ());
            }
        }

      // Initialize IOR table
      CORBA::Object_var table_object = orb->resolve_initial_references ("IORTable");

      IORTable::Table_var adapter = IORTable::Table::_narrow (table_object.in ());

      if (CORBA::is_nil (adapter.in ()))
        {
          DANCE_ERROR (DANCE_LOG_EMERGENCY,
                       (LM_ERROR, DLINFO
                        ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT ("Unable to RIR the IORTable.\n")));
          return CORBA::Object::_nil ();
        }

      // Creating in process nameservice
      CosNaming::NamingContext_var plan_nc;
      if (this->options_.create_plan_ns_)
        {
          DANCE_DEBUG (DANCE_LOG_TRACE,
                       (LM_TRACE, DLINFO
                        ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT ("Resolving plan-specific naming context.\n")));
          CORBA::Object_var naming_obj;
          if (0 != this->options_.create_plan_ns_ior_)
            {
              naming_obj = orb->string_to_object (this->options_.create_plan_ns_ior_);
              plan_nc = CosNaming::NamingContext::_narrow (naming_obj.in());
              if (CORBA::is_nil (plan_nc.in()))
                {
                  DANCE_ERROR (DANCE_LOG_EMERGENCY,
                               (LM_ERROR, DLINFO
                                ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                                ACE_TEXT ("Failed trying to narrow naming context ")
                                ACE_TEXT ("for dance creating plan NC.\n")
                                ACE_TEXT ("Use the \"--create-plan-ns NC ior\" ")
                                ACE_TEXT ("or \"--process-ns\" option.\n")));
                  return CORBA::Object::_nil ();
                }
            }
          else if (this->options_.process_ns_)
            {
              naming_obj = orb->resolve_initial_references ("NameService");
              if (0 != this->options_.process_ns_file_)
                {
                  CORBA::String_var ior = orb->object_to_string (naming_obj.in ());
                  DAnCE::Node_Manager::write_IOR (this->options_.process_ns_file_, ior.in ());
                }
              plan_nc = CosNaming::NamingContext::_narrow (naming_obj.in ());
              if (CORBA::is_nil (plan_nc.in ()))
                {
                  DANCE_ERROR (DANCE_LOG_EMERGENCY,
                               (LM_ERROR, DLINFO
                                ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                                ACE_TEXT ("Fails trying to narrow naming context ")
                                ACE_TEXT ("for dance creating plan NC.\n")
                                ACE_TEXT ("Use the \"--create-plan-ns NC ior\" ")
                                ACE_TEXT ("or \"--process-ns\" option.\n")));
                  return CORBA::Object::_nil ();
                }
            }
          else if (CORBA::is_nil (this->domain_nc_.in ()))
            {
              DANCE_ERROR (DANCE_LOG_EMERGENCY,
                           (LM_ERROR, DLINFO
                            ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                            ACE_TEXT ("The create plan is enabled but neither NC ior ")
                            ACE_TEXT ("nor --process-ns or DomainNC option are not supplied.\n")
                            ACE_TEXT ("Use the \"--create-plan-ns NC ior\", \"--process-ns\" ")
                            ACE_TEXT ("or \"-ORBInitRef DomainNC\" option.\n")));
              return CORBA::Object::_nil ();
            }
          else
            {
              plan_nc = CosNaming::NamingContext::_duplicate (this->domain_nc_.in ());
            }
        }

      // Parsing Node name and node manager ior file name
      ACE_TString node_name = this->options_.node_managers_[0].c_str ();
      ACE_TString node_file;
      size_t npos = node_name.find ('=');
      if (ACE_CString::npos != npos)
        {
          node_file = node_name.substring (npos + 1, node_name.length() - npos + 1);
          node_name = node_name.substring (0, npos);
        }

      // load service modules for artifact installation service
      load_artifact_installation_modules (argc, argv);

      // Creating in process artifact installation service
      DAnCE::ArtifactInstallation_Impl* installer = 0;
      ACE_NEW_RETURN (installer,
                      DAnCE::ArtifactInstallation_Impl (),
                      CORBA::Object::_nil ());
      PortableServer::Servant_var<DAnCE::ArtifactInstallation_Impl> safe_installer (installer);

      ACE_CString installer_oid_str = ACE_TEXT_ALWAYS_CHAR ((node_name + ACE_TEXT (".ArtifactInstaller")).c_str ());

      // Registering servant in poa
      PortableServer::ObjectId_var installer_oid =
        PortableServer::string_to_ObjectId (installer_oid_str.c_str());
      this->nm_poa_->activate_object_with_id (installer_oid, safe_installer._retn ());

      CORBA::Object_var installer_object = this->nm_poa_->id_to_reference (installer_oid.in ());
      this->installer_ = DAnCE::ArtifactInstallation::_narrow (installer_object.in ());

      // Getting node manager ior
      CORBA::String_var installer_ior = orb->object_to_string (installer_object.in ());

      // Binding ior to IOR Table
      adapter->bind (installer_oid_str.c_str (), installer_ior.in ());

      // Make sure that we have only one Node Manager
      if (this->options_.node_managers_.size () != 1)
        {
          DANCE_ERROR (DANCE_LOG_EMERGENCY,
                       (LM_ERROR, DLINFO
                        ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT ("For now only one node manager creation is supported.\n")));
          return CORBA::Object::_nil ();
        }

      DANCE_DEBUG (DANCE_LOG_MINOR_EVENT,
                   (LM_DEBUG, DLINFO
                    ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                    ACE_TEXT ("DAnCE_NodeManager::run_main - creating NodeManager for node %C\n"),
                    this->options_.node_managers_[0].c_str()));

      //Creating node manager servant
      DAnCE::NodeManager_Impl * nm = 0;
      if (this->nm_map_.find (node_name, nm) == -1)
        {
          DANCE_DEBUG (DANCE_LOG_EVENT_TRACE,
                       (LM_TRACE, DLINFO
                        ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT ("Allocating new NodeManager servant instance for NodeManager\n")));
          int size = 64;
          DAnCE::Utility::PROPERTY_MAP properties (size);
          this->create_nm_properties (properties);

          ACE_NEW_RETURN (nm,
                          DAnCE::NodeManager_Impl (orb,
                                                   this->root_poa_.in (),
                                                   this->installer_.in (),
                                                   ACE_TEXT_ALWAYS_CHAR (node_name.c_str()),
                                                   this->options_.node_config_,
                                                   properties),
                          CORBA::Object::_nil ());
          DANCE_TRACE_LOG (DANCE_LOG_TRACE,
                           (LM_TRACE, DLINFO
                            ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                            ACE_TEXT ("New NodeManager servant instance for NodeManager allocated.\n")));
          this->nm_map_.bind (node_name, nm);
        }

      ACE_CString node_manager_oid = ACE_TEXT_ALWAYS_CHAR ((node_name + ACE_TEXT (".NodeManager")).c_str ());

      // Registering servant in poa
      PortableServer::ObjectId_var oid =
        PortableServer::string_to_ObjectId (node_manager_oid.c_str());
      this->nm_poa_->activate_object_with_id (oid, nm);

      // Getting node manager ior
      CORBA::Object_var nm_obj = this->nm_poa_->id_to_reference (oid.in ());
      CORBA::String_var ior = orb->object_to_string (nm_obj.in ());

      // Binding ior to IOR Table
      adapter->bind (node_manager_oid.c_str (), ior.in ());

      // Binding node manager to DomainNC
      if (!CORBA::is_nil (this->domain_nc_.in ()))
        {
          DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                       (LM_TRACE, DLINFO
                        ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT ("Registering NM in NC as \"%C.NodeManager\".\n"), node_name.c_str ()));
          CosNaming::Name name (1);
          name.length (1);
          name[0].id = CORBA::string_dup (ACE_TEXT_ALWAYS_CHAR (node_name.c_str ()));
          name[0].kind = CORBA::string_dup ("NodeManager");
          this->domain_nc_->rebind (name, nm_obj.in ());
        }

      // Writing ior to file
      if (0 != node_file.length ())
        {
          DANCE_DEBUG (DANCE_LOG_EVENT_TRACE,
                       (LM_TRACE,  DLINFO
                        ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                        ACE_TEXT ("Writing node IOR %C to file %C.\n"), node_file.c_str (), ior.in ()));
          if (!DAnCE::Node_Manager::write_IOR (node_file.c_str (), ior.in ()))
            DANCE_ERROR (DANCE_LOG_NONFATAL_ERROR,
                         (LM_ERROR, DLINFO
                          ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                          ACE_TEXT ("Error: Unable to write IOR to file %C\n"),
                          node_file.c_str ()));
        }

      // Activate POA manager
      PortableServer::POAManager_var mgr = this->root_poa_->the_POAManager ();
      mgr->activate ();

      // Finishing Deployment part
      DANCE_DEBUG (DANCE_LOG_MAJOR_EVENT,
                   (LM_NOTICE, DLINFO
                    ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                    ACE_TEXT ("DAnCE_NodeManager is running...\n")));

      DANCE_DEBUG (DANCE_LOG_MAJOR_DEBUG_INFO,
                   (LM_DEBUG, DLINFO
                    ACE_TEXT ("DAnCE_NodeManager_Module::init - ")
                    ACE_TEXT ("NodeManager IOR: %C\n"), ior.in ()));

      return nm_obj._retn ();
    }
  catch (const CORBA::Exception& ex)
    {
      ex._tao_print_exception ("DAnCE_NodeManager::main\t\n");
      return CORBA::Object::_nil ();
    }
}

void
DAnCE_NodeManager_Module::register_value_factories (void)
{
  DANCE_TRACE("DAnCE_NodeManager_Module::register_value_factories");
}

void
DAnCE_NodeManager_Module::create_poas (void)
{
  DANCE_TRACE("DAnCE_NodeManager_Module::create_poas");
  // Get reference to Root POA.
  DANCE_TRACE_LOG (DANCE_LOG_DETAILED_TRACE,
                   (LM_TRACE, DLINFO
                    ACE_TEXT ("DAnCE_NodeManager_Module::create_poas - ")
                    ACE_TEXT ("Resolving root POA\n")));
  CORBA::Object_var obj = this->orb_->resolve_initial_references ("RootPOA");

  this->root_poa_ = PortableServer::POA::_narrow (obj.in ());

  DANCE_TRACE_LOG (DANCE_LOG_DETAILED_TRACE,
                   (LM_TRACE, DLINFO
                    ACE_TEXT ("DAnCE_NodeManager_Module::create_poas - ")
                    ACE_TEXT ("Obtaining the POAManager\n")));
  PortableServer::POAManager_var mgr = this->root_poa_->the_POAManager ();

  TAO::Utils::PolicyList_Destroyer policies (2);
  policies.length (2);

  try
    {
      DANCE_TRACE_LOG (DANCE_LOG_TRACE,
                       (LM_TRACE, DLINFO
                        ACE_TEXT ("DAnCE_NodeManager_Module::create_poas - ")
                        ACE_TEXT ("DAnCE_NodeManager_Module::create_poas - ")
                        ACE_TEXT ("Creating the \"Managers\" POA.\n")));

      policies[0] = this->root_poa_->create_id_assignment_policy (PortableServer::USER_ID);
      policies[1] = this->root_poa_->create_lifespan_policy (PortableServer::PERSISTENT);
      this->nm_poa_ = this->root_poa_->create_POA ("Managers",
                                       mgr.in(),
                                       policies);
    }
  catch (const PortableServer::POA::AdapterAlreadyExists &)
    {
      DANCE_TRACE_LOG (DANCE_LOG_TRACE,
                       (LM_INFO, DLINFO
                        ACE_TEXT ("DAnCE_NodeManager_Module::create_poas - ")
                        ACE_TEXT ("Using existing \"Managers\" POA\n")));
      this->nm_poa_ = this->root_poa_->find_POA ("Managers", 0);
    }
}

void
DAnCE_NodeManager_Module::create_nm_properties (DAnCE::Utility::PROPERTY_MAP &props)
{
  {
    CORBA::Any val;
    val <<= this->options_.timeout_;
    props.bind (DAnCE::LOCALITY_TIMEOUT, val);
  }
  {
    CORBA::Any val;
    val <<= this->root_poa_.in ();
    props.bind (DAnCE::ENTITY_POA, val);
  }
  {
    CORBA::Any val;
    val <<= CORBA::Any::from_string (CORBA::string_dup (ACE_TEXT_ALWAYS_CHAR (this->options_.cs_path_)),0);
    props.bind (DAnCE::LOCALITY_EXECUTABLE, val);
  }
  {
    CORBA::Any val;
    val <<= CORBA::Any::from_string (CORBA::string_dup (ACE_TEXT_ALWAYS_CHAR (this->options_.server_args_)),0);
    props.bind (DAnCE::LOCALITY_ARGUMENTS, val);
  }
  if (this->options_.locality_config_ != "")
    {
      CORBA::Any val;
      val <<= CORBA::Any::from_string (CORBA::string_dup (this->options_.locality_config_.c_str ()), 0);
      props.bind (DAnCE::DANCE_LM_CONFIGFILE, val);
    }
  if (this->options_.instance_nc_)
    {
      CORBA::Any val;
      val <<= CORBA::Any::from_string (CORBA::string_dup (ACE_TEXT_ALWAYS_CHAR (this->options_.instance_nc_)), 0);
      props.bind (DAnCE::INSTANCE_NC, val);
    }
  if (this->options_.domain_nc_)
    {
      CORBA::Any val;
      val <<= CORBA::Any::from_string (CORBA::string_dup (ACE_TEXT_ALWAYS_CHAR (this->options_.domain_nc_)), 0);
      props.bind (DAnCE::DOMAIN_NC, val);
    }
}

void
DAnCE_NodeManager_Module::load_artifact_installation_modules (int argc, ACE_TCHAR *argv [])
{
  DAnCE::InstallationRepositoryManagerSvc
    * dirms = ACE_Dynamic_Service<DAnCE::InstallationRepositoryManagerSvc>::instance ("InstallationRepositoryManager");

  if (dirms)
    {
      dirms->init (argc, argv);
    }

  DAnCE::ArtifactInstallationHandlerSvc
    * dfihs = ACE_Dynamic_Service<DAnCE::ArtifactInstallationHandlerSvc>::instance ("FileInstallationHandler");

  if (dfihs)
    {
      dfihs->init (argc, argv);
    }

  DAnCE::ArtifactInstallationHandlerSvc
    * dhihs = ACE_Dynamic_Service<DAnCE::ArtifactInstallationHandlerSvc>::instance ("HttpInstallationHandler");

  if (dhihs)
    {
      dhihs->init (argc, argv);
    }
}
