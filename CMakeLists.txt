cmake_minimum_required(VERSION 3.25)
project(PacMan)

set(CMAKE_CXX_STANDARD 17)
if (UNIX)
    # CMake dla MacOS z procesorem M2.... nie jestem w stanie zrobić aby był
    # uniwersalny dla każdego komputera
set(SFML_INCLUDE_DIR "/usr/local/include")  #zamienić ścieżkę w razie konieczności
set(SFML_LIBRARY_DIR "/Users/kamilbasiorka/Downloads/1/lib")    #zamienić ścieżkę w razie konieczności
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
        src/GameBoard.cpp
        src/GameBoard.h
        src/characters.cpp
        src/characters.h
        src/PacMan.cpp
        src/PacMan.h
        src/Ghost.cpp
        src/Ghost.h
        src/Game_contrl.cpp
        src/Game_contrl.h)
target_link_libraries (2 sfml-graphics sfml-window sfml-system)