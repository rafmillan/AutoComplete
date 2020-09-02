cmake_minimum_required(VERSION 3.15)
project(AutoComplete)

set(CMAKE_CXX_STANDARD 14)

add_executable(AutoComplete main.cpp TrieNode.h TrieNode.cpp)