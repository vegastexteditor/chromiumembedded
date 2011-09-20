// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing static and
// virtual method implementations. See the translator.README.txt file in the
// tools directory for more information.
//

#include "libcef_dll/cpptoc/v8value_cpptoc.h"
#include "libcef_dll/ctocpp/v8accessor_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

bool CefV8AccessorCToCpp::Get(const CefString& name,
    const CefRefPtr<CefV8Value> object, CefRefPtr<CefV8Value>& retval,
    CefString& exception)
{
  if(CEF_MEMBER_MISSING(struct_, get))
    return false;

  cef_v8value_t* retvalStruct = NULL;

  int rv = struct_->get(struct_, name.GetStruct(), 
                        CefV8ValueCppToC::Wrap(object), &retvalStruct,
                        exception.GetWritableStruct());
  if(retvalStruct)
    retval = CefV8ValueCppToC::Unwrap(retvalStruct);

  return rv ? true : false;
}

bool CefV8AccessorCToCpp::Set(const CefString& name,
    const CefRefPtr<CefV8Value> object, const CefRefPtr<CefV8Value> value,
    CefString& exception)
{
  if(CEF_MEMBER_MISSING(struct_, set))
    return false;

  int rv = struct_->set(struct_, name.GetStruct(), 
                        CefV8ValueCppToC::Wrap(object), 
                        CefV8ValueCppToC::Wrap(value),
                        exception.GetWritableStruct());

  return rv ? true : false;
}


#ifndef NDEBUG
template<> long CefCToCpp<CefV8AccessorCToCpp, CefV8Accessor,
    cef_v8accessor_t>::DebugObjCt = 0;
#endif

