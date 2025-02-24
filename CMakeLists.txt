# CMakeLists.txt project file for Raylib projects
#
cmake_minimum_required(VERSION 3.30)
project(Textures&Sprites_Assignment CXX)

set(CMAKE_CXX_STANDARD 20)

# Include the command that downloads libraries
include(FetchContent)

# define a function for adding git dependencies
function(include_dependency libName gitURL gitTag)
    # setup the declare
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )

    FetchContent_MakeAvailable(${libName})
endfunction()
# add raylib support
set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    message(STATUS "Getting ${LIB1} from Github")
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.5)
else()
    message(STATUS "Using local ${LIB1}")
endif()

add_executable(Textures&Sprites_Assignment main.cpp)

# set the include directory
target_include_directories(Textures&Sprites_Assignment PRIVATE ${raylib_INCLUDE_DIRS})

# link all libraries to the project
target_link_libraries(Textures&Sprites_Assignment PRIVATE ${LIB1})

target_link_libraries()

