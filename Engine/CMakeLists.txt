file(GLOB ENGINE_SOURCES
    Core/*.cpp
    Platform/*.cpp
    Renderer/*.cpp
    Renderer/VulkanBackend/*.cpp
    Scene/*.cpp
    Physics/*.cpp
    Vehicles/*.cpp
    TransitSim/*.cpp
    Scripting/*.cpp
    UI/*.cpp
    Telemetry/*.cpp)

add_library(OpenTransitEngine STATIC ${ENGINE_SOURCES})

target_include_directories(OpenTransitEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(OpenTransitEngine PUBLIC glm::glm entt sol2 SDL2::SDL2 Vulkan::Vulkan)

target_compile_definitions(OpenTransitEngine PUBLIC GLM_FORCE_RADIANS GLM_FORCE_DEPTH_ZERO_TO_ONE)
