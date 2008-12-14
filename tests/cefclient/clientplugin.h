// Copyright (c) 2008 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2006-2008 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Portions of this implementation are borrowed from webkit\default_plugin\
// plugin_impl.h

#pragma once

#include <atlbase.h>
#include <atlwin.h>
#include "cef_nplugin.h"

extern NPNetscapeFuncs* g_browser;

NPError API_CALL NP_GetEntryPoints(NPPluginFuncs* pFuncs);
NPError API_CALL NP_Initialize(NPNetscapeFuncs* pFuncs);
NPError API_CALL NP_Shutdown(void);

// Structure providing information about the client plugin.
const CefPluginInfo ClientPluginInfo = {
  {
    L"client_plugin",
    L"Client Plugin",
    L"My Example Client Plugin",
    L"1, 0, 0, 1",
    L"application/x-client-plugin",
    L"*",
    L""
  },
  NP_GetEntryPoints,
  NP_Initialize,
  NP_Shutdown
};

// Provides the client plugin functionality.
class ClientPlugin : public CWindowImpl<ClientPlugin> {
 public:
  // mode is the plugin instantiation mode, i.e. whether it is a full
  // page plugin (NP_FULL) or an embedded plugin (NP_EMBED)
  explicit ClientPlugin(int16 mode);
  virtual ~ClientPlugin();

  BEGIN_MSG_MAP(ClientPlugin)
    MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackGround)
    MESSAGE_HANDLER(WM_PAINT, OnPaint)
    MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
  END_MSG_MAP()

  // Initializes the plugin with the instance information, mime type
  // and the list of parameters passed down to the plugin from the webpage.
  //
  // Parameters:
  // module_handle
  //   The handle to the dll in which this object is instantiated.
  // instance
  //   The plugins opaque instance handle.
  // mime_type
  //   Identifies the third party plugin which would be eventually installed.
  // argc
  //   Indicates the count of arguments passed in from the webpage.
  // argv
  //   Pointer to the arguments.
  // Returns true on success.
  bool Initialize(HINSTANCE module_handle, NPP instance, NPMIMEType mime_type,
                  int16 argc, char* argn[], char* argv[]);

  // Displays the default plugin UI.
  //
  // Parameters:
  // parent_window
  //   Handle to the parent window.
  bool SetWindow(HWND parent_window);

  // Destroys the install dialog and the plugin window.
  void Shutdown();

  HWND window() const { return m_hWnd; }

  // Getter for the NPP instance member.
  const NPP instance() const {
    return instance_;
  }

 protected:
  // Window message handlers.
  LRESULT OnPaint(UINT message, WPARAM wparam, LPARAM lparam, BOOL& handled);
  LRESULT OnEraseBackGround(UINT message, WPARAM wparam, LPARAM lparam,
                            BOOL& handled);
  LRESULT OnLButtonDown(UINT message, WPARAM wparam, LPARAM lparam,
                        BOOL& handled);
  
  // Enables the plugin window if required and initiates an update of the
  // the plugin window.
  void RefreshDisplay();

 private:
  // The plugins opaque instance handle
  NPP instance_;
  // The plugin instantiation mode (NP_FULL or NP_EMBED)
  int16 mode_;
};