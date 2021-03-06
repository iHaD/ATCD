// $Id$
#include "Start.h"

#include "tao/AnyTypeCode/ExceptionA.h"
#include "dance/Logger/Log_Macros.h"
#include "dance/Deployment/Deployment_StartErrorC.h"
#include "dance/DAnCE_DeploymentInterceptorsC.h"
#include "dance/DAnCE_LocalityManagerC.h"
#include "dance/DAnCE_Utility.h"
#include "dance/LocalityManager/Scheduler/Deployment_Event.h"
#include "dance/LocalityManager/Scheduler/Plugin_Manager.h"

namespace DAnCE
{
  Start_Instance::Start_Instance (::Deployment::DeploymentPlan & plan,
                                  ::CORBA::ULong instanceRef,
                                  const CORBA::Any &ref,
                                  const char *inst_type,
                                  Event_Future holder)
    : Deployment_Event (holder,
                        plan.instance[instanceRef].name.in (),
                        inst_type),
      Action_Base (holder,
                   plan.instance[instanceRef].name.in (),
                   inst_type),
      plan_ (plan),
      instanceRef_ (instanceRef),
      ref_ (ref)
  {
  }

  Start_Instance::~Start_Instance (void)
  {
  }

  void
  Start_Instance::invoke_pre_interceptor (Plugin_Manager::INTERCEPTORS::const_iterator &)
  {
    DANCE_TRACE ("Start_Instance::invoke_pre_interceptor");

    //no-op
  }


  void
  Start_Instance::invoke (::DAnCE::InstanceDeploymentHandler_ptr handler)
  {
    DANCE_TRACE ("Start_Instance::invoke");

    DANCE_DEBUG (DANCE_LOG_TRACE,
                 (LM_TRACE, DLINFO
                  ACE_TEXT ("Start_Instance::invoke - ")
                  ACE_TEXT ("Invoking activate_instance on handler for type <%C>\n"),
                  this->instance_type_.c_str ()));
    handler->activate_instance (this->plan_,
                                this->instanceRef_,
                                this->ref_);
    DANCE_DEBUG (DANCE_LOG_DETAILED_TRACE,
                 (LM_TRACE, DLINFO
                  ACE_TEXT ("Start_Instance::invoke - ")
                  ACE_TEXT ("activate_instance completed\n")));
  }


  void
  Start_Instance::invoke_post_interceptor (Plugin_Manager::INTERCEPTORS::const_iterator &i)
  {
    DANCE_TRACE ("Start_Instance::invoke_post_interceptor");

    (*i)->post_activate (this->plan_,
                         this->instanceRef_,
                         this->instance_excep_.in ());
  }


  void
  Start_Instance::create_unexpected_exception (const std::string &name,
                                                 const std::string &reason)
  {
    DANCE_TRACE ("Start_Instance::create_unexpected_exception");

    ::Deployment::StartError ex_tmp (name.c_str (),
                                     reason.c_str ());
    this->instance_excep_ =
      DAnCE::Utility::create_any_from_exception (ex_tmp);
  }

  void
  Start_Instance::create_valid_result (Event_Result &)
  {
    DANCE_TRACE ("Start_Instance::create_valid_result");
    // no-op
  }
}
