cmake_minimum_required(VERSION 3.20)
project(OpenTransitEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(OTE_BUILD_TOOLS "Build content tools" ON)

include(FetchContent)

# Dependencies
FetchContent_Declare(glm GIT_REPOSITORY https://github.com/g-truc/glm.git GIT_TAG 0.9.9.8)
FetchContent_Declare(entt GIT_REPOSITORY https://github.com/skypjack/entt.git GIT_TAG v3.13.0)
FetchContent_Declare(sol2 GIT_REPOSITORY https://github.com/ThePhD/sol2.git GIT_TAG v3.3.0)
FetchContent_MakeAvailable(glm entt sol2)

# SDL2 and Vulkan are expected on the system for the MVP. If unavailable, fallback stubs are used for continuous integration.
find_package(SDL2 QUIET)
if(NOT SDL2_FOUND)
  add_library(SDL2::SDL2 INTERFACE IMPORTED)
endif()

find_package(Vulkan QUIET)
if(NOT Vulkan_FOUND)
  add_library(Vulkan::Vulkan INTERFACE IMPORTED)
endif()

add_subdirectory(Engine)
add_subdirectory(Apps/Sandbox)
add_subdirectory(Tools/ContentCooker)
add_subdirectory(Tests/SanityTests)
