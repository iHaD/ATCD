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


#include "IOP_IORC.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"

#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#if !defined (__ACE_INLINE__)
#include "IOP_IORC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be\be_visitor_arg_traits.cpp:66

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
IOP::TaggedProfile::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  TaggedProfile *_tao_tmp_pointer =
    static_cast<TaggedProfile *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IOP_TAGGEDPROFILESEQ_CS_)
#define _IOP_TAGGEDPROFILESEQ_CS_

IOP::TaggedProfileSeq::TaggedProfileSeq (void)
{}

IOP::TaggedProfileSeq::TaggedProfileSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedProfile
      >
    (max)
{}

IOP::TaggedProfileSeq::TaggedProfileSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    IOP::TaggedProfile * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedProfile
      >
    (max, length, buffer, release)
{}

IOP::TaggedProfileSeq::TaggedProfileSeq (
    const TaggedProfileSeq &seq
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedProfile
      >
    (seq)
{}

IOP::TaggedProfileSeq::~TaggedProfileSeq (void)
{}

void IOP::TaggedProfileSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  TaggedProfileSeq * _tao_tmp_pointer =
    static_cast<TaggedProfileSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
IOP::IOR::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  IOR *_tao_tmp_pointer =
    static_cast<IOR *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
IOP::TaggedComponent::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  TaggedComponent *_tao_tmp_pointer =
    static_cast<TaggedComponent *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IOP_MULTIPLECOMPONENTPROFILE_CS_)
#define _IOP_MULTIPLECOMPONENTPROFILE_CS_

IOP::MultipleComponentProfile::MultipleComponentProfile (void)
{}

IOP::MultipleComponentProfile::MultipleComponentProfile (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >
    (max)
{}

IOP::MultipleComponentProfile::MultipleComponentProfile (
    CORBA::ULong max,
    CORBA::ULong length,
    IOP::TaggedComponent * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >
    (max, length, buffer, release)
{}

IOP::MultipleComponentProfile::MultipleComponentProfile (
    const MultipleComponentProfile &seq
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >
    (seq)
{}

IOP::MultipleComponentProfile::~MultipleComponentProfile (void)
{}

void IOP::MultipleComponentProfile::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  MultipleComponentProfile * _tao_tmp_pointer =
    static_cast<MultipleComponentProfile *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IOP_TAGGEDCOMPONENTLIST_CS_)
#define _IOP_TAGGEDCOMPONENTLIST_CS_

IOP::TaggedComponentList::TaggedComponentList (void)
{}

IOP::TaggedComponentList::TaggedComponentList (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >
    (max)
{}

IOP::TaggedComponentList::TaggedComponentList (
    CORBA::ULong max,
    CORBA::ULong length,
    IOP::TaggedComponent * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >
    (max, length, buffer, release)
{}

IOP::TaggedComponentList::TaggedComponentList (
    const TaggedComponentList &seq
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >
    (seq)
{}

IOP::TaggedComponentList::~TaggedComponentList (void)
{}

void IOP::TaggedComponentList::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  TaggedComponentList * _tao_tmp_pointer =
    static_cast<TaggedComponentList *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IOP_TAGGEDCOMPONENTSEQ_CS_)
#define _IOP_TAGGEDCOMPONENTSEQ_CS_

IOP::TaggedComponentSeq::TaggedComponentSeq (void)
{}

IOP::TaggedComponentSeq::TaggedComponentSeq (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >
    (max)
{}

IOP::TaggedComponentSeq::TaggedComponentSeq (
    CORBA::ULong max,
    CORBA::ULong length,
    IOP::TaggedComponent * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >
    (max, length, buffer, release)
{}

IOP::TaggedComponentSeq::TaggedComponentSeq (
    const TaggedComponentSeq &seq
  )
  : TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >
    (seq)
{}

IOP::TaggedComponentSeq::~TaggedComponentSeq (void)
{}

void IOP::TaggedComponentSeq::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  TaggedComponentSeq * _tao_tmp_pointer =
    static_cast<TaggedComponentSeq *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// be\be_visitor_structure/structure_cs.cpp:66

void 
IOP::ServiceContext::_tao_any_destructor (
    void *_tao_void_pointer
  )
{
  ServiceContext *_tao_tmp_pointer =
    static_cast<ServiceContext *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

// TAO_IDL - Generated from 
// be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_IOP_SERVICECONTEXTLIST_CS_)
#define _IOP_SERVICECONTEXTLIST_CS_

IOP::ServiceContextList::ServiceContextList (void)
{}

IOP::ServiceContextList::ServiceContextList (
    CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        IOP::ServiceContext
      >
    (max)
{}

IOP::ServiceContextList::ServiceContextList (
    CORBA::ULong max,
    CORBA::ULong length,
    IOP::ServiceContext * buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        IOP::ServiceContext
      >
    (max, length, buffer, release)
{}

IOP::ServiceContextList::ServiceContextList (
    const ServiceContextList &seq
  )
  : TAO_Unbounded_Sequence<
        IOP::ServiceContext
      >
    (seq)
{}

IOP::ServiceContextList::~ServiceContextList (void)
{}

void IOP::ServiceContextList::_tao_any_destructor (
    void * _tao_void_pointer
  )
{
  ServiceContextList * _tao_tmp_pointer =
    static_cast<ServiceContextList *> (_tao_void_pointer);
  delete _tao_tmp_pointer;
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedProfile &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.tag) &&
    (strm << _tao_aggregate.profile_data);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedProfile &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.tag) &&
    (strm >> _tao_aggregate.profile_data);
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_IOP_TaggedProfileSeq_CPP_
#define _TAO_CDR_OP_IOP_TaggedProfileSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedProfileSeq &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedProfileSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_IOP_TaggedProfileSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::IOR &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.type_id.in ()) &&
    (strm << _tao_aggregate.profiles);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::IOR &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.type_id.out ()) &&
    (strm >> _tao_aggregate.profiles);
}

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedComponent &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.tag) &&
    (strm << _tao_aggregate.component_data);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedComponent &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.tag) &&
    (strm >> _tao_aggregate.component_data);
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_IOP_MultipleComponentProfile_CPP_
#define _TAO_CDR_OP_IOP_MultipleComponentProfile_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::MultipleComponentProfile &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::MultipleComponentProfile &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_IOP_MultipleComponentProfile_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_IOP_TaggedComponentList_CPP_
#define _TAO_CDR_OP_IOP_TaggedComponentList_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedComponentList &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedComponentList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_IOP_TaggedComponentList_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_IOP_TaggedComponentSeq_CPP_
#define _TAO_CDR_OP_IOP_TaggedComponentSeq_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::TaggedComponentSeq &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::TaggedComponentSeq &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_IOP_TaggedComponentSeq_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_structure/cdr_op_cs.cpp:61

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::ServiceContext &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.context_id) &&
    (strm << _tao_aggregate.context_data);
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::ServiceContext &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.context_id) &&
    (strm >> _tao_aggregate.context_data);
}

// TAO_IDL - Generated from
// be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_IOP_ServiceContextList_CPP_
#define _TAO_CDR_OP_IOP_ServiceContextList_CPP_

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const IOP::ServiceContextList &_tao_sequence
  )
{
  const CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    IOP::ServiceContextList &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      CORBA::Boolean _tao_marshal_flag = true;
      
      for (CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_IOP_ServiceContextList_CPP_ */

// TAO_IDL - Generated from
// be\be_visitor_root/root.cpp:1629

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

  template class
    TAO_Var_Var_T<
        IOP::TaggedProfile
      >;

  template class
    TAO_Var_Base_T<
        IOP::TaggedProfile
      >;

  template class
    TAO_Out_T<
        IOP::TaggedProfile,
        IOP::TaggedProfile_var
      >;

  template class
    TAO_VarSeq_Var_T<
        IOP::TaggedProfileSeq,
        IOP::TaggedProfile
      >;

  template class
    TAO_Seq_Var_Base_T<
        IOP::TaggedProfileSeq,
        IOP::TaggedProfile
      >;

  template class
    TAO_Seq_Out_T<
        IOP::TaggedProfileSeq,
        IOP::TaggedProfileSeq_var,
        IOP::TaggedProfile
      >;

#if !defined (_IOP_TAGGEDPROFILE__EXPLICIT_CS_)
#define _IOP_TAGGEDPROFILE__EXPLICIT_CS_

  template class
    TAO_Unbounded_Sequence<
        IOP::TaggedProfile
      >;

#endif /* end #if !defined */

  template class
    TAO_Var_Var_T<
        IOP::IOR
      >;

  template class
    TAO_Var_Base_T<
        IOP::IOR
      >;

  template class
    TAO_Out_T<
        IOP::IOR,
        IOP::IOR_var
      >;

  template class
    TAO_Var_Var_T<
        IOP::TaggedComponent
      >;

  template class
    TAO_Var_Base_T<
        IOP::TaggedComponent
      >;

  template class
    TAO_Out_T<
        IOP::TaggedComponent,
        IOP::TaggedComponent_var
      >;

  template class
    TAO_VarSeq_Var_T<
        IOP::MultipleComponentProfile,
        IOP::TaggedComponent
      >;

  template class
    TAO_Seq_Var_Base_T<
        IOP::MultipleComponentProfile,
        IOP::TaggedComponent
      >;

  template class
    TAO_Seq_Out_T<
        IOP::MultipleComponentProfile,
        IOP::MultipleComponentProfile_var,
        IOP::TaggedComponent
      >;

#if !defined (_IOP_TAGGEDCOMPONENT__EXPLICIT_CS_)
#define _IOP_TAGGEDCOMPONENT__EXPLICIT_CS_

  template class
    TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >;

#endif /* end #if !defined */

  template class
    TAO_VarSeq_Var_T<
        IOP::TaggedComponentList,
        IOP::TaggedComponent
      >;

  template class
    TAO_Seq_Var_Base_T<
        IOP::TaggedComponentList,
        IOP::TaggedComponent
      >;

  template class
    TAO_Seq_Out_T<
        IOP::TaggedComponentList,
        IOP::TaggedComponentList_var,
        IOP::TaggedComponent
      >;

#if !defined (_IOP_TAGGEDCOMPONENT__EXPLICIT_CS_)
#define _IOP_TAGGEDCOMPONENT__EXPLICIT_CS_

  template class
    TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >;

#endif /* end #if !defined */

  template class
    TAO_VarSeq_Var_T<
        IOP::TaggedComponentSeq,
        IOP::TaggedComponent
      >;

  template class
    TAO_Seq_Var_Base_T<
        IOP::TaggedComponentSeq,
        IOP::TaggedComponent
      >;

  template class
    TAO_Seq_Out_T<
        IOP::TaggedComponentSeq,
        IOP::TaggedComponentSeq_var,
        IOP::TaggedComponent
      >;

#if !defined (_IOP_TAGGEDCOMPONENT__EXPLICIT_CS_)
#define _IOP_TAGGEDCOMPONENT__EXPLICIT_CS_

  template class
    TAO_Unbounded_Sequence<
        IOP::TaggedComponent
      >;

#endif /* end #if !defined */

  template class
    TAO_Var_Var_T<
        IOP::ServiceContext
      >;

  template class
    TAO_Var_Base_T<
        IOP::ServiceContext
      >;

  template class
    TAO_Out_T<
        IOP::ServiceContext,
        IOP::ServiceContext_var
      >;

  template class
    TAO_VarSeq_Var_T<
        IOP::ServiceContextList,
        IOP::ServiceContext
      >;

  template class
    TAO_Seq_Var_Base_T<
        IOP::ServiceContextList,
        IOP::ServiceContext
      >;

  template class
    TAO_Seq_Out_T<
        IOP::ServiceContextList,
        IOP::ServiceContextList_var,
        IOP::ServiceContext
      >;

#if !defined (_IOP_SERVICECONTEXT__EXPLICIT_CS_)
#define _IOP_SERVICECONTEXT__EXPLICIT_CS_

  template class
    TAO_Unbounded_Sequence<
        IOP::ServiceContext
      >;

#endif /* end #if !defined */

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
    TAO_Var_Var_T< \
        IOP::TaggedProfile \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        IOP::TaggedProfile \
      >

# pragma instantiate \
    TAO_Out_T< \
        IOP::TaggedProfile, \
        IOP::TaggedProfile_var \
      >

# pragma instantiate \
    TAO_VarSeq_Var_T< \
        IOP::TaggedProfileSeq, \
        IOP::TaggedProfile \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        IOP::TaggedProfileSeq, \
        IOP::TaggedProfile \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        IOP::TaggedProfileSeq, \
        IOP::TaggedProfileSeq_var, \
        IOP::TaggedProfile \
      >

#if !defined (_IOP_TAGGEDPROFILE__EXPLICIT_CS_)
#define _IOP_TAGGEDPROFILE__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Sequence< \
        IOP::TaggedProfile \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_Var_Var_T< \
        IOP::IOR \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        IOP::IOR \
      >

# pragma instantiate \
    TAO_Out_T< \
        IOP::IOR, \
        IOP::IOR_var \
      >

# pragma instantiate \
    TAO_Var_Var_T< \
        IOP::TaggedComponent \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        IOP::TaggedComponent \
      >

# pragma instantiate \
    TAO_Out_T< \
        IOP::TaggedComponent, \
        IOP::TaggedComponent_var \
      >

# pragma instantiate \
    TAO_VarSeq_Var_T< \
        IOP::MultipleComponentProfile, \
        IOP::TaggedComponent \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        IOP::MultipleComponentProfile, \
        IOP::TaggedComponent \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        IOP::MultipleComponentProfile, \
        IOP::MultipleComponentProfile_var, \
        IOP::TaggedComponent \
      >

#if !defined (_IOP_TAGGEDCOMPONENT__EXPLICIT_CS_)
#define _IOP_TAGGEDCOMPONENT__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Sequence< \
        IOP::TaggedComponent \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_VarSeq_Var_T< \
        IOP::TaggedComponentList, \
        IOP::TaggedComponent \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        IOP::TaggedComponentList, \
        IOP::TaggedComponent \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        IOP::TaggedComponentList, \
        IOP::TaggedComponentList_var, \
        IOP::TaggedComponent \
      >

#if !defined (_IOP_TAGGEDCOMPONENT__EXPLICIT_CS_)
#define _IOP_TAGGEDCOMPONENT__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Sequence< \
        IOP::TaggedComponent \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_VarSeq_Var_T< \
        IOP::TaggedComponentSeq, \
        IOP::TaggedComponent \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        IOP::TaggedComponentSeq, \
        IOP::TaggedComponent \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        IOP::TaggedComponentSeq, \
        IOP::TaggedComponentSeq_var, \
        IOP::TaggedComponent \
      >

#if !defined (_IOP_TAGGEDCOMPONENT__EXPLICIT_CS_)
#define _IOP_TAGGEDCOMPONENT__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Sequence< \
        IOP::TaggedComponent \
      >

#endif /* end #if !defined */

# pragma instantiate \
    TAO_Var_Var_T< \
        IOP::ServiceContext \
      >

# pragma instantiate \
    TAO_Var_Base_T< \
        IOP::ServiceContext \
      >

# pragma instantiate \
    TAO_Out_T< \
        IOP::ServiceContext, \
        IOP::ServiceContext_var \
      >

# pragma instantiate \
    TAO_VarSeq_Var_T< \
        IOP::ServiceContextList, \
        IOP::ServiceContext \
      >

# pragma instantiate \
    TAO_Seq_Var_Base_T< \
        IOP::ServiceContextList, \
        IOP::ServiceContext \
      >

# pragma instantiate \
    TAO_Seq_Out_T< \
        IOP::ServiceContextList, \
        IOP::ServiceContextList_var, \
        IOP::ServiceContext \
      >

#if !defined (_IOP_SERVICECONTEXT__EXPLICIT_CS_)
#define _IOP_SERVICECONTEXT__EXPLICIT_CS_

# pragma instantiate \
    TAO_Unbounded_Sequence< \
        IOP::ServiceContext \
      >

#endif /* end #if !defined */

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */ 
