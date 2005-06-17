// -*- C++ -*-

//=============================================================================
/**
 *  @file     Messaging_ORBInitializer.h
 *
 *  $Id$
 *
 *  @author  Ossama Othman <ossama@uci.edu>
 */
//=============================================================================


#ifndef TAO_MESSAGING_ORB_INITIALIZER_H
#define TAO_MESSAGING_ORB_INITIALIZER_H

#include /**/ "ace/pre.h"

#include "messaging_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/PI/PI.h"
#include "tao/LocalObject.h"

// This is to remove "inherits via dominance" warnings from MSVC.
// MSVC is being a little too paranoid.
#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#endif /* _MSC_VER */


/// Messaging ORB initializer.
class TAO_Messaging_Export TAO_Messaging_ORBInitializer
  : public virtual PortableInterceptor::ORBInitializer,
    public virtual TAO_Local_RefCounted_Object
{
public:

  /**
   * @name PortableInterceptor::ORBInitializer Methods
   *
   * The following methods are required by the
   * PortableInterceptor::ORBInitializer interface.
   */
  //@{

  virtual void pre_init (PortableInterceptor::ORBInitInfo_ptr info
                         ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  virtual void post_init (PortableInterceptor::ORBInitInfo_ptr info
                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  //@}

private:

  /// Register Messaging policy factories.
  void register_policy_factories (
    PortableInterceptor::ORBInitInfo_ptr info
    ACE_ENV_ARG_DECL);
};

#if defined(_MSC_VER)
#pragma warning(pop)
#endif /* _MSC_VER */



#include /**/ "ace/post.h"

#endif /* TAO_MESSAGING_ORB_INITIALIZER_H */
