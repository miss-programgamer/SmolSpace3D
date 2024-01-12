cmake_minimum_required(VERSION 3.21.0)
project(SmolSpace3D VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# Main Target
add_library(SmolSpace3D
	"source/smol/space3d/vector.hpp"
	"source/smol/space3d/vector.cpp"
	"source/smol/space3d/ray.hpp"
	"source/smol/space3d/ray.cpp"
	"source/smol/space3d/line.hpp"
	"source/smol/space3d/line.cpp"
	"source/smol/space3d/block.hpp"
	"source/smol/space3d/block.cpp"
	"source/smol/space3d/region.hpp"
	"source/smol/space3d/region.cpp"
	"source/smol/space3d/bounds.hpp"
	"source/smol/space3d/bounds.cpp"
	"source/smol/space3d.hpp"
)
target_include_directories(SmolSpace3D PUBLIC "source")

# Testing
find_package(Catch2 3 REQUIRED)
include(CTest)
include(Catch)

add_executable(SmolSpace3DUnitTests
	"tests/unit/vector.cpp"
)
target_link_libraries(SmolSpace3DUnitTests PRIVATE Catch2::Catch2WithMain SmolSpace3D)
catch_discover_tests(SmolSpace3DUnitTests)

# Packing
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)