cmake_minimum_required(VERSION 3.14)

project(2024-02-06_DB_Network CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Sql)

add_executable(2024-02-06_DB_Network
  main.cpp
  ${TS_FILES}
)
target_link_libraries(2024-02-06_DB_Network Qt${QT_VERSION_MAJOR}::Core Qt6::Network Qt6::Sql)

install(TARGETS 2024-02-06_DB_Network
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
