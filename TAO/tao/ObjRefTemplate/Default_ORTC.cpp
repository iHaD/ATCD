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

// TAO_IDL - Generated from
// be\be_codegen.cpp:302


#include "Default_ORTC.h"
#include "tao/CDR.h"
#include "tao/Valuetype/ValueFactory.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "Default_ORTC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:66

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from
// be\be_visitor_valuetype/valuetype_cs.cpp:66

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION 
void
TAO::Value_Traits<TAO_Default_ORT::ObjectReferenceTemplate>::add_ref (
    TAO_Default_ORT::ObjectReferenceTemplate * p
  )
{
  CORBA::add_ref (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION 
void
TAO::Value_Traits<TAO_Default_ORT::ObjectReferenceTemplate>::remove_ref (
    TAO_Default_ORT::ObjectReferenceTemplate * p
  )
{
  CORBA::remove_ref (p);
}

ACE_TEMPLATE_CLASS_MEMBER_SPECIALIZATION 
void
TAO::Value_Traits<TAO_Default_ORT::ObjectReferenceTemplate>::release (
    TAO_Default_ORT::ObjectReferenceTemplate * p
  )
{
  CORBA::remove_ref (p);
}

TAO_Default_ORT::ObjectReferenceTemplate *
TAO_Default_ORT::ObjectReferenceTemplate::_downcast (CORBA::ValueBase *v)
{
  return dynamic_cast< ::TAO_Default_ORT::ObjectReferenceTemplate * > (v);
}

const char *
TAO_Default_ORT::ObjectReferenceTemplate::_tao_obv_repository_id (void) const
{
  return this->_tao_obv_static_repository_id ();
}

void
TAO_Default_ORT::ObjectReferenceTemplate::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectReferenceTemplate *_tao_tmp_pointer =
    static_cast<
        ObjectReferenceTemplate *> (
        _tao_void_pointer
      );
  CORBA::remove_ref (_tao_tmp_pointer);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal_v (TAO_OutputCDR & strm)
{
  return this->_tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal_v (TAO_InputCDR & strm)
{
  return this->_tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (strm);
}

CORBA::Boolean TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal (
    TAO_InputCDR &strm,
    ObjectReferenceTemplate *&new_object
  )
{
  CORBA::ValueBase *base = 0;
  CORBA::ValueFactory_var factory;
  CORBA::Boolean retval =
    CORBA::ValueBase::_tao_unmarshal_pre (
        strm,
        factory.out (),
        base,
        ObjectReferenceTemplate::_tao_obv_static_repository_id ()
      );
  
  if (retval == 0)
    {
      return 0;
    }
  
  if (factory.in () != 0)
    {
      base = factory->create_for_unmarshal ();
      
      if (base == 0)
        {
          return 0;  // %! except.?
        }
      
      retval = base->_tao_unmarshal_v (strm);
      
      if (retval == 0)
        {
          return 0;
        }
    }
  
  // Now base must be null or point to the unmarshaled object.
  // Align the pointer to the right subobject.
  new_object = ObjectReferenceTemplate::_downcast (base);
  return retval;
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/valuetype_obv_cs.cpp:58

OBV_TAO_Default_ORT::ObjectReferenceTemplate::ObjectReferenceTemplate (void)
{}

OBV_TAO_Default_ORT::ObjectReferenceTemplate::~ObjectReferenceTemplate (void)
{}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_OutputCDR &strm)
{
  return _tao_marshal_state (strm);
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal__TAO_Default_ORT_ObjectReferenceTemplate (TAO_InputCDR &strm)
{
  return _tao_unmarshal_state (strm);
}

// TAO_IDL - Generated from
// be\be_valuetype.cpp:488

void
CORBA::add_ref (TAO_Default_ORT::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_add_ref ();
    }
}

void
CORBA::remove_ref (TAO_Default_ORT::ObjectReferenceTemplate * vt)
{
  if (vt != 0)
    {
      vt->_remove_ref ();
    }
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/cdr_op_cs.cpp:73

CORBA::Boolean
operator<< (
    TAO_OutputCDR &strm,
    const TAO_Default_ORT::ObjectReferenceTemplate *_tao_valuetype
  )
{
  return
    CORBA::ValueBase::_tao_marshal (
        strm,
        const_cast<TAO_Default_ORT::ObjectReferenceTemplate *> (_tao_valuetype),
        reinterpret_cast<ptrdiff_t> (&TAO_Default_ORT::ObjectReferenceTemplate::_downcast)
      );
}

CORBA::Boolean
operator>> (
    TAO_InputCDR &strm,
    TAO_Default_ORT::ObjectReferenceTemplate *&_tao_valuetype
  )
{
  return TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal (strm, _tao_valuetype);
}

// TAO_IDL - Generated from
// be\be_visitor_valuetype/marshal_cs.cpp:44

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_marshal_state (TAO_OutputCDR &)
{
  return (
      1
    );
}

CORBA::Boolean
OBV_TAO_Default_ORT::ObjectReferenceTemplate::_tao_unmarshal_state (TAO_InputCDR &)
{
  return (
    1
  );
}

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO::Value_Traits<
        TAO_Default_ORT::ObjectReferenceTemplate
      >;

  template class
    TAO_Value_Var_T<
        TAO_Default_ORT::ObjectReferenceTemplate
        
      >;
  
  template class
    TAO_Value_Out_T<
        TAO_Default_ORT::ObjectReferenceTemplate
        
      >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO::Value_Traits< \
        TAO_Default_ORT::ObjectReferenceTemplate \
      >

# pragma instantiate \
    TAO_Value_Var_T< \
        TAO_Default_ORT::ObjectReferenceTemplate \
        
      >
  
# pragma instantiate \
    TAO_Value_Out_T< \
        TAO_Default_ORT::ObjectReferenceTemplate \
        
      >

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
