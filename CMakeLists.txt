cmake_minimum_required(VERSION 2.6)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules/")

project(game)

find_package(PkgConfig)
pkg_check_modules(ALLEGRO allegro-5) 

find_package(PugiXML)

#find_package(Boost COMPONENTS system)

file(GLOB_RECURSE sources ${CMAKE_SOURCE_DIR}/src/*.cpp src/*.h)
file(GLOB_RECURSE resources ${CMAKE_SOURCE_DIR}/res/*)

set(destination "${CMAKE_CURRENT_BINARY_DIR}/res")

add_executable(game ${sources})

include_directories(game PUBLIC ${ALLEGRO_INCLUDE_DIRS} ${PUGIXML_INCLUDE_DIRS}) #${Boost_INCLUDE_DIRS})
target_compile_options(game PUBLIC ${ALLEGRO_CFLAGS_OTHER})

target_link_libraries(game ${ALLEGRO_LIBRARIES} ${PUGIXML_LIBRARIES} allegro_image allegro_font allegro_ttf allegro_primitives -lpthread)

#if(APPLE)
    #target_link_libraries(game ${ALLEGRO_LIBRARIES} ${Boost_LIBRARIES} allegro_image -lallegro_main)
#else()
    #target_link_libraries(game ${ALLEGRO_LIBRARIES} ${Boost_LIBRARIES} allegro_image -lpthread)
#endif()

add_custom_command(
    TARGET game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res
    $<TARGET_FILE_DIR:game>/res
)
