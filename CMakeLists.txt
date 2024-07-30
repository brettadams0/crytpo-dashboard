cmake_minimum_required(VERSION 3.10)
project(CryptoDashboard)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/nlohmann)

add_executable(CryptoDashboard
    src/main.cpp
    src/data_fetcher.cpp
    src/data_visualizer.cpp
    src/alerts.cpp
)

target_link_libraries(CryptoDashboard ${CURL_LIBRARIES})
