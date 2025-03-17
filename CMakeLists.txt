cmake_minimum_required(VERSION 3.25)

project(lvs-doca)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-permissive")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ENV{PKG_CONFIG_PATH} "/opt/mellanox/dpdk/lib/x86_64-linux-gnu/pkgconfig:$ENV{PKG_CONFIG_PATH}")
find_package(PkgConfig REQUIRED)

pkg_check_modules(DOCA_COMMON REQUIRED doca-common)
pkg_check_modules(DOCA_FLOW REQUIRED doca-flow)
pkg_check_modules(DOCA_ARGP REQUIRED doca-argp)
pkg_check_modules(DPDK REQUIRED libdpdk)

include_directories(
    ${DOCA_COMMON_INCLUDE_DIRS}
    ${DOCA_FLOW_INCLUDE_DIRS}
    ${DOCA_ARGP_INCLUDE_DIRS}
    ${DPDK_INCLUDE_DIRS}
)
link_directories(
    ${DOCA_COMMON_LIBRARY_DIRS}
    ${DOCA_FLOW_LIBRARY_DIRS}
    ${DOCA_ARGP_LIBRARY_DIRS}
    ${DPDK_LIBRARY_DIRS}
)

add_subdirectory(src)
