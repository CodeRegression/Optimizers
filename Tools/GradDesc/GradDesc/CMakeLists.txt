#--------------------------------------------------------
# CMake for generating the main executable
#
# @author: Wild Boar
#
# Date Created: 2023-03-31
#--------------------------------------------------------

# Setup the includes
include_directories("../")

# Create the executable
add_executable(GradDesc
    Engine.cpp
    Source.cpp
)

# Add link libraries                               
target_link_libraries(GradDesc GradDescLib  NVLib ${OpenCV_LIBS})

# Copy Resources across
add_custom_target(resource_copy ALL
	COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/Resources ${CMAKE_BINARY_DIR}/GradDesc 
    DEPENDS ${MY_TARGET}
)
