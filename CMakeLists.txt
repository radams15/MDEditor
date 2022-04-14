cmake_minimum_required(VERSION 3.0)
project(MDEditor)

set(CMAKE_PROJECT_VERSION 0.2.1)

set(CMAKE_CXX_STANDARD 98)

option(USE_WEBVIEW "Use wxWebView instead of wxHTML (Allows css & Js)" OFF)
option(USE_STYLED_CTRL "Use wxStyledTextCtrl instead of wxTextCtrl (Allows nicer look)" OFF)

add_subdirectory(lib/scidown)

if(USE_WEBVIEW)
    message("Using wxWebView")
    set(DISP_COMP webview)
else()
    message("Using wxHTML")
    set(DISP_COMP html)
endif()

if(USE_STYLED_CTRL)
    message("Using wxStyledTextCtrl")
    set(STYLE_COMP stc)
else()
    message("Using wxTextCtrl")
    set(STYLE_COMP)
endif()

find_package(wxWidgets COMPONENTS core base adv ${STYLE_COMP} ${DISP_COMP} REQUIRED)

include(${wxWidgets_USE_FILE})
include_directories(lib/scidown/src)

if(APPLE)
    set(EXTRAS src/main/tweaks/Cocoa.mm)
endif()

add_executable(MDEditor MACOSX_BUNDLE src/main/main.cpp src/main/MainApp.cpp src/main/MainFrame.cpp src/main/MainFrameCust.cpp src/main/Converter.cpp src/main/Settings.cpp src/main/SettingsDlgCust.cpp ${EXTRAS})

if(USE_WEBVIEW)
    target_compile_definitions(MDEditor PRIVATE USE_WEBVIEW)
endif()

if(USE_STYLED_CTRL)
    target_compile_definitions(MDEditor PRIVATE USE_STYLED_CTRL)
endif()

if(UNIX AND NOT APPLE)
    target_compile_definitions(MDEditor PRIVATE DATA_DIR="/usr/local/share/MDEditor/data/")
endif()

if(WIN32)
    add_custom_command(TARGET MDEditor POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/res/MDEditor.exe.manifest ${CMAKE_BINARY_DIR})
    add_custom_command(TARGET MDEditor POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/lib/scidown/libscidown.dll ${CMAKE_BINARY_DIR})
endif()

if(APPLE)
    add_custom_command(TARGET MDEditor PRE_BUILD
            COMMAND mkdir -p ${CMAKE_BINARY_DIR}/MDEditor.app/Contents/Resources/
            COMMAND sh -c "cp -r ${CMAKE_CURRENT_SOURCE_DIR}/data/* ${CMAKE_BINARY_DIR}/MDEditor.app/Contents/Resources/"
            VERBATIM)

    add_custom_command(TARGET MDEditor POST_BUILD
            COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/complete.sh
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            VERBATIM)

    set_target_properties(MDEditor PROPERTIES
            BUNDLE True
            MACOSX_BUNDLE_GUI_IDENTIFIER uk.co.therhys.MDEditor
            MACOSX_BUNDLE_BUNDLE_NAME MDEditor
            MACOSX_BUNDLE_BUNDLE_VERSION "${CMAKE_PROJECT_VERSION}"
            MACOSX_BUNDLE_SHORT_VERSION_STRING "${CMAKE_PROJECT_VERSION}"
            MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/res/Info.plist
            MACOSX_BUNDLE_ICON_FILE "${CMAKE_SOURCE_DIR}/res/MDEditor.icns"
            )
endif()

target_link_libraries(MDEditor scidown ${wxWidgets_LIBRARIES})

install(TARGETS MDEditor DESTINATION bin)
install(DIRECTORY data DESTINATION share/MDEditor)