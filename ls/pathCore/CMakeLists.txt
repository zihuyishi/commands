set(PathCore_FILES Path.h Path.cpp Dir.cpp Dir.h)

if (WIN32)
set(PathCore_FILES ${PathCore_FILES} dir_winimpl.cpp dir_winimpl.h)
else()
set(PathCore_FILES ${PathCore_FILES} dir_posiximpl.cpp dir_posiximpl.h)
endif()

add_library(pathCore ${PathCore_FILES})