cmake_minimum_required(VERSION 3.16)

project(SafetyAnalysis LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(SafetyAnalysis SHARED
  SafetyAnalysis_global.h
  safetyanalysis.cpp
  safetyanalysis.h
)

target_link_libraries(SafetyAnalysis PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(SafetyAnalysis PRIVATE SAFETYANALYSIS_LIBRARY)
