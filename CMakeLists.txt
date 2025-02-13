cmake_minimum_required(VERSION 3.13)
project(PAA_zkouska)

find_package(VTK COMPONENTS
		vtkCommonCore
		vtkCommonDataModel
		vtkFiltersCore
		vtkIOLegacy QUIET)

set(CMAKE_CXX_STANDARD 17)

set(WARNINGS "-Wall -Weffc++ -pedantic -Wextra -Wcast-align -Wcast-qual -Wchar-subscripts -Wcomment -Wconversion -Wdisabled-optimization -Wfloat-equal -Wformat -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimport -Winit-self -Winline -Winvalid-pch -Wunsafe-loop-optimizations -Wlong-long -Wmissing-braces -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wparentheses -Wpointer-arith -Wredundant-decls -Wreturn-type -Wsequence-point -Wsign-compare -Wstack-protector -Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch -Wswitch-default -Wswitch-enum -Wtrigraphs -Wuninitialized -Wunknown-pragmas -Wunreachable-code -Wunused -Wunused-function -Wunused-label -Wunused-parameter -Wunused-value -Wunused-variable -Wvariadic-macros -Wvolatile-register-var -Wwrite-strings -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wrestrict -Wnull-dereference -Wold-style-cast -Wuseless-cast -Wdouble-promotion")

include_directories(include)

set(HEADER_FILES
	stl_reader/stl_reader.h
	include/main.hpp
	include/global.hpp
	include/Lattice.hpp
	include/Column.hpp
	include/Tile.hpp
	include/Direction.hpp
	include/Layer.hpp
	include/vec.hpp
)

set(SOURCE_FILES
	src/main.cpp
	src/Lattice.cpp
	src/Column.cpp
	src/Tile.cpp
	src/Direction.cpp
	src/Layer.cpp
	src/vec.cpp
)

add_executable(PAA ${HEADER_FILES} ${SOURCE_FILES})

add_custom_command(
    TARGET PAA POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/resources
            $<TARGET_FILE_DIR:PAA>
)

if (VTK_VERSION VERSION_LESS "8.90.0")
	include(${VTK_USE_FILE})
	target_link_libraries(PAA PRIVATE ${VTK_LIBRARIES})
else ()
	target_link_libraries(PAA PRIVATE ${VTK_LIBRARIES})
	vtk_module_autoinit(
			TARGETS PAA
			MODULES ${VTK_LIBRARIES}
	)
endif ()