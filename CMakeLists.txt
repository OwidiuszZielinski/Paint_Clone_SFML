cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(SFML)

add_executable(main
        main.cpp
        Tool.cpp
        Toolbar.cpp
        FillPen.cpp
        CirclePen.cpp
        SquarePen.cpp
        TrianglePen.cpp
        EraserTool.cpp
        circle.cpp
        square.cpp
        triangle.cpp
)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE sfml-graphics)

set(PAINT_ASSETS
        arial.ttf
        canvas.jpeg
        canvas.png
        circle.jpg
        Cirklo.png
        eraser.jpg
        eraser.png
        fill.jpg
        GhostDied.otf
        GhostDied.ttf
        kolo.png
        Montserrat-Bold.ttf
        Montserrat-Regular.ttf
        OFL.txt
        square.jpg
        square2.png
        triangle.jpg
        Triangle.png
)

foreach(asset IN LISTS PAINT_ASSETS)
    add_custom_command(TARGET main POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_SOURCE_DIR}/${asset}"
            "$<TARGET_FILE_DIR:main>/${asset}"
    )
endforeach()

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)
