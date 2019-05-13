cmake_minimum_required(VERSION 3.10)
project(cplusplus_zhengli_tsinghua)

set(CMAKE_CXX_STANDARD 11)
include_directories(./)
include_directories(basic)
include_directories(advanced)
add_executable(cplusplus_zhengli_tsinghua
        main.cpp
        basic/programming_assginments/programmingAssignment02.h
        basic/programming_assginments/programmingAssignment03.h
        basic/programming_assginments/programmingAssignment04.h
        basic/programming_assginments/programmingAssignment05.h
        basic/programming_assginments/programmingAssignment06.h
        advanced/programming_assignments/advanced_pa07.h
        advanced/programming_assignments/advanced_pa08.h
        advanced/programming_assignments/advanced_pa09.h
        advanced/programming_assignments/advanced_pa10.h
        advanced/programming_assignments/advanced_pa11.h
        advanced/programming_assignments/advanced_pa12.h)
