cmake_minimum_required(VERSION 3.8)

project(Proj_final)

#add_executable(zal test.cpp)
#add_executable(projekt Proj_gra.cpp)
add_executable(graf VechBib.cpp)
#target_include_directories(zal PUBLIC include)
set_target_properties(graf PROPERTIES
    CXX_STANDARD 17
)
