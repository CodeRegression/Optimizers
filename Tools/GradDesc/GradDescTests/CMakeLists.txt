#--------------------------------------------------------
# CMake for generating GradDescLib Testing Suite
#
# @author: Wild Boar
#
# Date Created: 2023-03-31
#--------------------------------------------------------

# Add Google Test to the test group
find_package(GTest REQUIRED)

# Setup the includes
include_directories("../")

# Add the UnitTestLib library to the folder
add_library(UnitTestLib STATIC IMPORTED)
set_target_properties(UnitTestLib PROPERTIES
    IMPORTED_LOCATION "${LIBRARY_BASE}/UnitTestLib/build/UnitTestLib/libUnitTestLib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_BASE}/UnitTestLib"
)

# Create the executable
add_executable (GradDescTests
	Tests/Example_Tests.cpp
	Tests/Refiner_Tests.cpp
)

# Add link libraries
target_link_libraries(GradDescTests GradDescLib NVLib ${OpenCV_LIBS} UnitTestLib minpack GTest::Main)

# Find the associated unit tests
gtest_discover_tests(GradDescTests)
