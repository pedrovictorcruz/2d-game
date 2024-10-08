cmake_minimum_required(VERSION "3.25.1")

project("2d-game")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Criar uma variavel e atribui o diretorio a ela
set(SFML_DIR "${CMAKE_SOURCE_DIR}/vendor/SFML/lib/cmake/SFML")
set(SPDLOG_DIR "${CMAKE_SOURCE_DIR}/vendor/spdlog/cmake")

# Encontre os pacotes da SFML
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Adicione os arquivos de origem
add_executable(${PROJECT_NAME} src/Main.cpp src/Game.cpp src/Events.cpp src/Enemy.cpp src/Player.cpp src/input_system.cpp)

# Incluir os diretórios de cabeçalhos da SFML
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/vendor/SFML/include ${CMAKE_SOURCE_DIR}/vendor/spdlog/include)

# Incluir subdiretorios do spdlog
add_subdirectory("${CMAKE_SOURCE_DIR}/vendor/spdlog")

# Link com as bibliotecas da SFML
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network spdlog::spdlog)

