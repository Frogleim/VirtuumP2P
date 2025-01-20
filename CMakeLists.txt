cmake_minimum_required(VERSION 3.10)
project(VirtuumP2P)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-O2")
set(BOOST_ROOT "/opt/homebrew/Cellar/boost/1.87.0")
set(BOOST_INCLUDEDIR "/opt/homebrew/Cellar/boost/1.87.0/include")
set(BOOST_LIBRARYDIR "/opt/homebrew/Cellar/boost/1.87.0/lib")
# Include Boost
find_package(Boost REQUIRED COMPONENTS system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "Boost found: ${Boost_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "Boost not found!")
endif()

# Include project headers
include_directories(include)

# Add source files
add_executable(virtuum_p2p
    src/main.cpp
    src/network/peer_connection.cpp
    src/network/server.cpp
    src/network/client.cpp
    src/network/logger.cpp
)

# Link against Boost libraries
target_link_libraries(virtuum_p2p PRIVATE Boost::system)
