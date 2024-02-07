# ~~~
# Summary:      Local, non-generic plugin setup
# Copyright (c) 2020-2021 Mike Rossiter
# License:      GPLv3+
# ~~~

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.


# -------- Options ----------

set(OCPN_TEST_REPO
    "opencpn/TradNav-alpha"
    CACHE STRING "Default repository for untagged builds"
)
set(OCPN_BETA_REPO
    "opencpn/TradNav-beta"
    CACHE STRING
    "Default repository for tagged builds matching 'beta'"
)
set(OCPN_RELEASE_REPO
    "opencpn/TradNav-prod"
    CACHE STRING
    "Default repository for tagged builds not matching 'beta'"
)

option(TradNav_USE_SVG "Use SVG graphics" ON)

#
#
# -------  Plugin setup --------
#
set(PKG_NAME TradNav_pi)
set(PKG_VERSION  0.1.0)
set(PKG_PRERELEASE "")  # Empty, or a tag like 'beta'

set(DISPLAY_NAME TradNav)    # Dialogs, installer artifacts, ...
set(PLUGIN_API_NAME TradNav) # As of GetCommonName() in plugin API
set(PKG_SUMMARY "make GPX files for dead reckoning positions")
set(PKG_DESCRIPTION [=[
Create GPX files for dead reckoning positions using existing GPX route files
]=])

set(PKG_AUTHOR "Mike Rossiter")
set(PKG_IS_OPEN_SOURCE "yes")
set(PKG_HOMEPAGE https://github.com/Rasbats/TradNav_pi)
set(PKG_INFO_URL https://opencpn.org/OpenCPN/plugins/TradNaveckoning.html)

set(SRC
    src/TradNav_pi.h
    src/TradNav_pi.cpp
    src/icons.h
    src/icons.cpp
    src/TradNavgui.h
    src/TradNavgui.cpp
    src/TradNavgui_impl.cpp
    src/TradNavgui_impl.h
    src/NavFunc.cpp
    src/NavFunc.h
    src/gl_private.h
    src/pidc.cpp
    src/pidc.h
    src/doc.cpp
    src/doc.h
    src/globals.h
    src/tdEventHandler.cpp
    src/tdEventHandler.h
    src/range.cpp
    src/range.h
    src/tdPath.cpp
    src/tdPath.h
    src/bearing.cpp
    src/bearing.h

)

set(PKG_API_LIB api-17)  #  A directory in libs/ e. g., api-17 or api-16

macro(late_init)
  # Perform initialization after the PACKAGE_NAME library, compilers
  # and ocpn::api is available.
  if (TradNav_USE_SVG)
    target_compile_definitions(${PACKAGE_NAME} PUBLIC TradNav_USE_SVG)
  endif ()

  add_definitions(-DocpnUSE_GL)

  if (QT_ANDROID)
    add_definitions(-DUSE_ANDROID_GLES2)
  endif ()

endmacro ()

macro(add_plugin_libraries)
  # Add libraries required by this plugin
  add_subdirectory("libs/tinyxml")
  target_link_libraries(${PACKAGE_NAME} ocpn::tinyxml)

  add_subdirectory("libs/plugingl")
  target_link_libraries(${PACKAGE_NAME} ocpn::plugingl)

  add_subdirectory("${CMAKE_SOURCE_DIR}/opencpn-libs/pugixml")
  target_link_libraries(${PACKAGE_NAME} ocpn::pugixml)

endmacro ()
