cmake_minimum_required(VERSION 3.31)
project(hamon)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GNUInstallDirs)
find_package(Intl REQUIRED)
find_package(Threads REQUIRED)

set(GCC_WARNING_FLAGS
        -Wall -Wextra -Wpedantic -Wshadow -Wformat=2
        -Wconversion -Wsign-conversion -Werror
)
add_library(cube STATIC
        src/Shell.cpp
        src/Make.cpp
        src/Command.cpp
)
target_link_libraries(cube PUBLIC Intl::Intl Threads::Threads)
target_compile_options(cube PRIVATE ${GCC_WARNING_FLAGS})

add_executable(hamon apps/hamon/main.cpp)
target_link_libraries(hamon PRIVATE cube)
target_compile_options(hamon PRIVATE ${GCC_WARNING_FLAGS})

install(TARGETS hamon DESTINATION bin)
install(FILES include/Shell.hpp include/Make.hpp include/Command.hpp DESTINATION include)
install(TARGETS cube DESTINATION lib)
