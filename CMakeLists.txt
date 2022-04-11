cmake_minimum_required(VERSION 3.0)
project(MDEditor)

set(CMAKE_CXX_STANDARD 98)

set(CMARK_STATIC ON)
set(CMARK_TESTS OFF)

set(wxWidgets_ROOT_DIR=/usr/)

add_subdirectory(lib/scidown)

find_package(wxWidgets COMPONENTS core base adv stc html REQUIRED)

include(${wxWidgets_USE_FILE})
include_directories(lib/scidown/src)

add_executable(MDEditor src/main/main.cpp src/main/MainApp.cpp src/main/MainFrame.cpp src/main/MainFrameCust.cpp src/main/Converter.cpp src/main/Settings.cpp)

target_link_libraries(MDEditor scidown ${wxWidgets_LIBRARIES})