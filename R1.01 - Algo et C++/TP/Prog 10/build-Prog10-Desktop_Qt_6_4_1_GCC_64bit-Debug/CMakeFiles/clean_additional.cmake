# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Prog10_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Prog10_autogen.dir/ParseCache.txt"
  "Prog10_autogen"
  )
endif()
