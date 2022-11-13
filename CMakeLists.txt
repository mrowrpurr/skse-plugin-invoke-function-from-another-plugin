cmake_minimum_required(VERSION 3.21)

project(MySkseLibraryExample VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CommonLibSSE CONFIG REQUIRED)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h include/*.h)

add_commonlibsse_plugin(${PROJECT_NAME} SOURCES ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
include_directories(${PROJECT_NAME} include)
target_precompile_headers(${PROJECT_NAME} PUBLIC src/PCH.h)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "!MySkseLibraryExample")

add_custom_command(
	TARGET "${PROJECT_NAME}"
	POST_BUILD
	COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:${PROJECT_NAME}>" "${PROJECT_SOURCE_DIR}/SKSE/Plugins/${PROJECT_NAME}.dll"
	COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_PDB_FILE:${PROJECT_NAME}>" "${PROJECT_SOURCE_DIR}/SKSE/Plugins/${PROJECT_NAME}.pdb"
	VERBATIM
)
