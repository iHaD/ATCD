// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

#include "PolicyC.h"
#include "tao/Typecode.h"
#include "tao/CDR.h"
#include "tao/Any.h"
#include "tao/Any_Impl_T.h"
#include "tao/Any_Dual_Impl_T.h"

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_PolicyErrorCode[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  38,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x4572726f), 
  ACE_NTOHL (0x72436f64), 
  ACE_NTOHL (0x653a312e), 
  ACE_NTOHL (0x30000000),  // repository ID = IDL:omg.org/CORBA/PolicyErrorCode:1.0
    16,
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63794572), 
  ACE_NTOHL (0x726f7243), 
  ACE_NTOHL (0x6f646500),  // name = PolicyErrorCode
    CORBA::tk_short,

};

static CORBA::TypeCode _tc_TAO_tc_CORBA_PolicyErrorCode (
    CORBA::tk_alias,
    sizeof (_oc_CORBA_PolicyErrorCode),
    (char *) &_oc_CORBA_PolicyErrorCode,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_PolicyErrorCode =
    &_tc_TAO_tc_CORBA_PolicyErrorCode;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_Policy[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  29,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x3a312e30), 
  ACE_NTOHL (0x0),  // repository ID = IDL:omg.org/CORBA/Policy:1.0
    7,
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63790000),  // name = Policy
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_Policy (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_Policy),
    (char *) &_oc_CORBA_Policy,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_Policy =
    &_tc_TAO_tc_CORBA_Policy;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_PolicyManager[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x4d616e61), 
  ACE_NTOHL (0x6765723a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/PolicyManager:1.0
    14,
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63794d61), 
  ACE_NTOHL (0x6e616765), 
  ACE_NTOHL (0x72000000),  // name = PolicyManager
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_PolicyManager (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_PolicyManager),
    (char *) &_oc_CORBA_PolicyManager,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_PolicyManager =
    &_tc_TAO_tc_CORBA_PolicyManager;
}

// TAO_IDL - Generated from
// be\be_visitor_typecode/typecode_defn.cpp:295

static const CORBA::Long _oc_CORBA_PolicyCurrent[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  36,
  ACE_NTOHL (0x49444c3a), 
  ACE_NTOHL (0x6f6d672e), 
  ACE_NTOHL (0x6f72672f), 
  ACE_NTOHL (0x434f5242), 
  ACE_NTOHL (0x412f506f), 
  ACE_NTOHL (0x6c696379), 
  ACE_NTOHL (0x43757272), 
  ACE_NTOHL (0x656e743a), 
  ACE_NTOHL (0x312e3000),  // repository ID = IDL:omg.org/CORBA/PolicyCurrent:1.0
    14,
  ACE_NTOHL (0x506f6c69), 
  ACE_NTOHL (0x63794375), 
  ACE_NTOHL (0x7272656e), 
  ACE_NTOHL (0x74000000),  // name = PolicyCurrent
  };

static CORBA::TypeCode _tc_TAO_tc_CORBA_PolicyCurrent (
    CORBA::tk_objref,
    sizeof (_oc_CORBA_PolicyCurrent),
    (char *) &_oc_CORBA_PolicyCurrent,
    0,
    0
  );

namespace CORBA
{
  ::CORBA::TypeCode_ptr _tc_PolicyCurrent =
    &_tc_TAO_tc_CORBA_PolicyCurrent;
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<CORBA::PolicyError>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if (!(cdr >> id.out ()))
    {
      return false;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;
  
  return true;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::PolicyError &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::PolicyError>::insert_copy (
      _tao_any,
      CORBA::PolicyError::_tao_any_destructor,
      CORBA::_tc_PolicyError,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyError *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::PolicyError>::insert (
      _tao_any,
      CORBA::PolicyError::_tao_any_destructor,
      CORBA::_tc_PolicyError,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyError *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::PolicyError *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::PolicyError *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::PolicyError>::extract (
        _tao_any,
        CORBA::PolicyError::_tao_any_destructor,
        CORBA::_tc_PolicyError,
        _tao_elem
      );
}

// TAO_IDL - Generated from 
// be\be_visitor_exception/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Dual_Impl_T<CORBA::InvalidPolicies>::demarshal_value (
    TAO_InputCDR & cdr
  )
{
  CORBA::String_var id;
  
  if (!(cdr >> id.out ()))
    {
      return false;
    }
  
  ACE_TRY_NEW_ENV
    {
      this->value_->_tao_decode (cdr ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      return false;
    }
  ACE_ENDTRY;
  
  return true;
}

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const CORBA::InvalidPolicies &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::InvalidPolicies>::insert_copy (
      _tao_any,
      CORBA::InvalidPolicies::_tao_any_destructor,
      CORBA::_tc_InvalidPolicies,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    CORBA::InvalidPolicies *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<CORBA::InvalidPolicies>::insert (
      _tao_any,
      CORBA::InvalidPolicies::_tao_any_destructor,
      CORBA::_tc_InvalidPolicies,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::InvalidPolicies *&_tao_elem
  )
{
  return _tao_any >>= const_cast<
      const CORBA::InvalidPolicies *&> (
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const CORBA::InvalidPolicies *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<CORBA::InvalidPolicies>::extract (
        _tao_any,
        CORBA::InvalidPolicies::_tao_any_destructor,
        CORBA::_tc_InvalidPolicies,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::Policy>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Policy_ptr _tao_elem
  )
{
  CORBA::Policy_ptr _tao_objptr =
    CORBA::Policy::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::Policy_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::Policy>::insert (
      _tao_any,
      CORBA::Policy::_tao_any_destructor,
      CORBA::_tc_Policy,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::Policy_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::Policy>::extract (
        _tao_any,
        CORBA::Policy::_tao_any_destructor,
        CORBA::_tc_Policy,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyManager>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyManager>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyManager>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyManager_ptr _tao_elem
  )
{
  CORBA::PolicyManager_ptr _tao_objptr =
    CORBA::PolicyManager::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyManager_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::PolicyManager>::insert (
      _tao_any,
      CORBA::PolicyManager::_tao_any_destructor,
      CORBA::_tc_PolicyManager,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyManager_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::PolicyManager>::extract (
        _tao_any,
        CORBA::PolicyManager::_tao_any_destructor,
        CORBA::_tc_PolicyManager,
        _tao_elem
      );
}

// TAO_IDL - Generated from
// be\be_visitor_interface/any_op_cs.cpp:50

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyCurrent>::to_object (
    CORBA::Object_ptr &_tao_elem
  ) const
{
  _tao_elem = CORBA::Object::_duplicate (this->value_);
  return 1;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyCurrent>::marshal_value (TAO_OutputCDR &)
{
  return false;
}

ACE_TEMPLATE_SPECIALIZATION
CORBA::Boolean
TAO::Any_Impl_T<CORBA::PolicyCurrent>::demarshal_value (TAO_InputCDR &)
{
  return false;
}

// Copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyCurrent_ptr _tao_elem
  )
{
  CORBA::PolicyCurrent_ptr _tao_objptr =
    CORBA::PolicyCurrent::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

// Non-copying insertion.
void
operator<<= (
    CORBA::Any &_tao_any,
    CORBA::PolicyCurrent_ptr *_tao_elem
  )
{
  TAO::Any_Impl_T<CORBA::PolicyCurrent>::insert (
      _tao_any,
      CORBA::PolicyCurrent::_tao_any_destructor,
      CORBA::_tc_PolicyCurrent,
      *_tao_elem
    );
}

CORBA::Boolean
operator>>= (
    const CORBA::Any &_tao_any,
    CORBA::PolicyCurrent_ptr &_tao_elem
  )
{
  return
    TAO::Any_Impl_T<CORBA::PolicyCurrent>::extract (
        _tao_any,
        CORBA::PolicyCurrent::_tao_any_destructor,
        CORBA::_tc_PolicyCurrent,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Any_Impl_T<
        CORBA::Policy
      >;

  template class
    TAO::Any_Impl_T<
        CORBA::PolicyCurrent
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::PolicyError
      >;

  template class
    TAO::Any_Dual_Impl_T<
        CORBA::InvalidPolicies
      >;

  template class
    TAO::Any_Impl_T<
        CORBA::PolicyManager
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::Policy \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::PolicyCurrent \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::PolicyError \
      >

# pragma instantiate \
    TAO::Any_Dual_Impl_T< \
        CORBA::InvalidPolicies \
      >

# pragma instantiate \
    TAO::Any_Impl_T< \
        CORBA::PolicyManager \
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
