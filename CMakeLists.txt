cmake_minimum_required(VERSION 3.22)
project(tree_shower)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Use root-config to get ROOT configuration
execute_process(COMMAND /home/nikolfax/opt/root/bin/root-config --cflags
        OUTPUT_VARIABLE ROOT_CFLAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND /home/nikolfax/opt/root/bin/root-config --libs
        OUTPUT_VARIABLE ROOT_LIBS
        OUTPUT_STRIP_TRAILING_WHITESPACE)

# Include directories for ROOT
include_directories(
        /home/nikolfax/opt/root/include # Explicit path to ROOT includes
)

# Add ROOT flags to the compile options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CFLAGS} -O2 -pedantic -W -Wall -Wshadow -fPIC -pthread")

# Add executable
add_executable(tree_shower main.cpp)

# Fix the linking process: properly handle ROOT_LIBS
# Convert ROOT_LIBS string to a list of libraries
separate_arguments(ROOT_LIB_LIST UNIX_COMMAND "${ROOT_LIBS}")

# Link the necessary libraries
target_link_libraries(tree_shower PRIVATE
        ${ROOT_LIB_LIST}
)