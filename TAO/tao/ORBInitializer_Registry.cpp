#include "ORBInitializer_Registry.h"
#include "ORBInitializer_Registry_Adapter.h"
#include "PortableInterceptorC.h"
#include "ORB.h"
#include "ORB_Constants.h"
#include "TAO_Singleton_Manager.h"
#include "SystemException.h"

#include "ace/Service_Config.h"
#include "ace/Dynamic_Service.h"
#include "ace/Static_Object_Lock.h"
#include "ace/Recursive_Thread_Mutex.h"
#include "ace/Log_Msg.h"

ACE_RCSID (tao,
           ORBInitializer_Registry,
           "$Id$")


// ****************************************************************

void
PortableInterceptor::register_orb_initializer (
  PortableInterceptor::ORBInitializer_ptr init
  ACE_ENV_ARG_DECL)
{
  {
    // Using ACE_Static_Object_Lock::instance() precludes
    // register_orb_initializer() from being called within a static
    // object CTOR.
    ACE_MT (ACE_GUARD (TAO_SYNCH_RECURSIVE_MUTEX,
                       guard,
                       *ACE_Static_Object_Lock::instance ()));

    // Make sure TAO's singleton manager is initialized.
    if (TAO_Singleton_Manager::instance ()->init () == -1)
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("(%P|%t) register_orb_initializer: ")
                    ACE_TEXT ("Unable to pre-initialize TAO\n")));
      }

    TAO::ORB::init_orb_globals (ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_CHECK;
  }

  // If not, lookup it up.
  TAO::ORBInitializer_Registry_Adapter *orbinitializer_registry_ =
    ACE_Dynamic_Service<TAO::ORBInitializer_Registry_Adapter>::instance
    ("ORBInitializer_Registry");

#if !defined (TAO_AS_STATIC_LIBS)
  if (orbinitializer_registry_ == 0)
    {
      ACE_Service_Config::process_directive (
        ACE_DYNAMIC_SERVICE_DIRECTIVE("ORBInitializer_Registry",
                                      "TAO_PI",
                                      "_make_ORBInitializer_Registry",
                                      ""));
      orbinitializer_registry_ =
        ACE_Dynamic_Service<TAO::ORBInitializer_Registry_Adapter>::instance
          ("ORBInitializer_Registry");
    }
#endif /* !TAO_AS_STATIC_LIBS */

  if (orbinitializer_registry_ != 0)
    {
      orbinitializer_registry_->register_orb_initializer (
        init
        ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("(%P|%t) %p\n"),
                  ACE_TEXT ("ERROR: ORBInitializer Registry unable to find the ")
                  ACE_TEXT ("ORBInitializer Registry instance")));

      ACE_THROW (CORBA::INTERNAL ());
    }
}


