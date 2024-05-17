cmake_minimum_required(VERSION 3.25)
project(PacMan)

set(CMAKE_CXX_STANDARD 17)
if (UNIX)
    # CMake dla MacOS z procesorem M2.... nie jestem w stanie zrobić aby był
    # uniwersalny dla każdego komputera
set(SFML_INCLUDE_DIR "/usr/local/include")
set(SFML_LIBRARY_DIR "/Users/kamilbasiorka/Downloads/1/lib")
link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
endif(UNIX)



if (WIN32)
    # próbujemy linkować statycznie (nie trzeba kopiować plików dll do katalogu projektu)
    set( SFML_STATIC_LIBRARIES TRUE )

    # Jeśli zainstalowaliście w innym miejscu to trzeba tu zmienić katalog na właściwy
    set ( SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML/")
endif(WIN32)

find_package(SFML 2.6.0 COMPONENTS system window graphics network audio)
add_executable(2 main.cpp
        files/GameBoard.cpp
        files/GameBoard.h
        files/characters.cpp
        files/characters.h
        files/PacMan.cpp
        files/PacMan.h
        files/Ghost.cpp
        files/Ghost.h
        files/Game_contrl.cpp
        files/Game_contrl.h)
target_link_libraries (2 sfml-graphics sfml-window sfml-system)