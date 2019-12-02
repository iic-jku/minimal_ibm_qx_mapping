#[[
Minimal Mapping of Quantum Circuits to IBM QX Architectures by JKU Linz, Austria

Developer: Robert Wille, Lukas Burgholzer, Alwin Zulehner

For more information, please visit http://iic.jku.at/eda/research/ibm_qx_mapping

If you have any questions feel free to contact us using
robert.wille@jku.at, lukas.burgholzer@jku.at or alwin.zulehner@jku.at

If you use the compiler for your research, we would be thankful if you referred to it
by citing the following publication:

@inproceedings{wille2019mapping,
title={Mapping Quantum Circuits to {IBM QX} Architectures Using the Minimal Number of {SWAP} and {H} Operations},
author={Wille, Robert and Burgholzer, Lukas and Zulehner, Alwin},
booktitle={Design Automation Conference},
year={2019}
}
]]

cmake_minimum_required(VERSION 3.12)
project(minimal_mapping)

add_executable(minimal_mapping
               minimal_ibm_qx_mapping/Circuit.cpp
               minimal_ibm_qx_mapping/Circuit.hpp
               minimal_ibm_qx_mapping/main.cpp
               parser/QASMparser.cpp
               parser/QASMscanner.cpp
               parser/QASMtoken.cpp
               parser/QASMparser.h
               parser/QASMscanner.hpp
               parser/QASMtoken.hpp)

set_property(TARGET minimal_mapping PROPERTY CXX_STANDARD 11)
set_property(TARGET minimal_mapping PROPERTY CXX_EXTENSIONS OFF)
target_compile_options(minimal_mapping PRIVATE -DNDEBUG -g -mtune=native -march=native -pipe -flto)

target_include_directories(minimal_mapping PUBLIC /usr/local/include minimal_ibm_qx_mapping parser)
target_link_directories(minimal_mapping PUBLIC /usr/local/lib)
target_link_libraries(minimal_mapping z3)
