
cmake_minimum_required(VERSION 3.10)
project(VirtuumP2P)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2")

# Include Boost
find_package(Boost REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIRS} include)

add_executable(virtuum_p2p
    src/main.cpp
    src/network/peer_connection.cpp
    src/network/server.cpp
    src/network/client.cpp
)

target_link_libraries(virtuum_p2p ${Boost_LIBRARIES})
