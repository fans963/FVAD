cmake_minimum_required(VERSION 4.0)

set (CMAKE_C_COMPILER clang)
set (CMAKE_CXX_COMPILER clang++)

project(vad VERSION 1.0 LANGUAGES CXX)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 26)
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -flto=full -DQCP_OPENGL_FBO -DQCP_OPENGL_OFFSCREENSURFACE -DQCP_OPENGL_PBUFFER")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets OpenGL Multimedia)
find_package(yaml-cpp REQUIRED)
find_package(Eigen3 REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.hpp" "src/*.cc" "include/*.cpp" "include/*.cc" "include/*.hpp" "res/*.qrc")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries (${PROJECT_NAME} PUBLIC
    Qt5::Widgets
    Qt5::Multimedia
    Qt5::OpenGL
    qcustomplot
    yaml-cpp
    Eigen3::Eigen
)

include_directories(include)
