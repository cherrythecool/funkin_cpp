cmake_minimum_required(VERSION 4.1)

project(funkin_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_SOURCE_DIR}/bin>)

add_executable(${PROJECT_NAME}
    src/main.cpp

    src/crystal/assets/asset_server.cpp
    src/crystal/assets/image.cpp
    src/crystal/assets/png.cpp
    src/crystal/assets/sparrow.cpp

    src/crystal/core/audio/audio_server.cpp
    src/crystal/core/audio/audio_stream.cpp

    src/crystal/core/debug/debug_info.cpp

    src/crystal/core/input/input_server.cpp

    src/crystal/core/rendering/rendering_server.cpp
    src/crystal/core/rendering/shader.cpp
    src/crystal/core/rendering/texture.cpp
    src/crystal/core/rendering/window.cpp

    src/crystal/core/clock.cpp
    src/crystal/core/color.cpp
    src/crystal/core/engine.cpp
    src/crystal/core/file_system.cpp
    src/crystal/core/math.cpp
    src/crystal/core/ref_counted.cpp
    src/crystal/core/string.cpp
    src/crystal/core/timer.cpp

    src/crystal/scene/audio_stream_player.cpp
    src/crystal/scene/batched_sprites.cpp
    src/crystal/scene/color_rect.cpp
    src/crystal/scene/scene.cpp
    src/crystal/scene/sprite.cpp
    src/crystal/scene/startup_scene.cpp

    src/funkin/debug/console_debug_info.cpp

    src/funkin/scene/title_screen.cpp

    src/funkin/audio.cpp

    thirdparty/glad/glad.c
    thirdparty/stb/stb_vorbis.c
    thirdparty/stb/stb_image.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
    src
    src/crystal
    src/funkin
    thirdparty
)

set(ZLIB_BUILD_TESTING OFF)
set(ZLIB_BUILD_SHARED OFF)
set(ZLIB_BUILD_STATIC ON)
add_subdirectory(thirdparty/zlib-1.3.2)
target_link_libraries(${PROJECT_NAME} PUBLIC zlibstatic)

set(PNG_SHARED OFF)
set(PNG_STATIC ON)
add_subdirectory(thirdparty/libpng16)
target_link_libraries(${PROJECT_NAME} PUBLIC png_static)

if (WIN32)
    target_link_directories(${PROJECT_NAME} PRIVATE
        lib/win64
    )

    target_link_libraries(${PROJECT_NAME} PRIVATE
        glfw3dll
        OpenAL32
        freetype
    )

    configure_file(lib/win64/freetype.dll ../bin/freetype.dll COPYONLY)
    configure_file(lib/win64/glfw3.dll ../bin/glfw3.dll COPYONLY)
    configure_file(lib/win64/OpenAL32.dll ../bin/OpenAL32.dll COPYONLY)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE
        glfw
        openal
        freetype
        m
    )
endif()

add_dependencies(${PROJECT_NAME} copy_assets)

add_custom_target(copy_assets ALL
COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/assets
${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
COMMENT "COPYING ASSETS"
)
