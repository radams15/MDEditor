cmake_minimum_required(VERSION 3.0)
project(MDEditor)

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

add_executable(MDEditor MACOSX_BUNDLE src/main/main.cpp src/main/MainApp.cpp src/main/MainFrame.cpp src/main/MainFrameCust.cpp src/main/Converter.cpp src/main/Settings.cpp src/main/SettingsDlgCust.cpp)

if(USE_WEBVIEW)
    target_compile_definitions(MDEditor PRIVATE USE_WEBVIEW)
endif()

if(USE_STYLED_CTRL)
    target_compile_definitions(MDEditor PRIVATE USE_STYLED_CTRL)
endif()

target_link_libraries(MDEditor scidown ${wxWidgets_LIBRARIES})