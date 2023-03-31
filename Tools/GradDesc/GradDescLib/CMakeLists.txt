#--------------------------------------------------------
# CMake for generating the GradDescLib
#
# @author: Wild Boar
#
# Date Created: 2023-03-31
#--------------------------------------------------------

# Setup includes directories
include_directories("../" "${LIBRARY_BASE}/NVLib")

# Create Library
add_library (GradDescLib STATIC
	ArgUtils.cpp
)