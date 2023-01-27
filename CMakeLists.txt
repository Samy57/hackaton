cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17) #on va compiler du cpp 17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # il est nécessaire qu'on compile avec du cpp17 au moins

set(CMAKE_CXX_EXTENSIONS OFF) #Désactiver pour être sûr que ça marche sur multiplateforme

project ( Hackaton )


add_subdirectory( src )

include_directories( src ) #Sinon vs code va râler qu'il ne trouve pas les .hpp qu'on include dans main.cpp

add_executable(hackaton.exe main.cpp) #Extension de l'executable au choix (facultative, elle est seulement indicative, ça peut être rien, .exe ou .out par exemple)
target_link_libraries(hackaton.exe maLib)

# pour faire comprendre à vs code qu'on fait un projet cmake ctrl+maj+p configure projet cmake