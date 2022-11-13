cmake_minimum_required(VERSION 3.21)

project(MySkseLibraryExample VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h include/*.h)

include(cmake/CommonLibNG.cmake)
find_package(CommonLibSSE CONFIG REQUIRED)
add_commonlibsse_plugin_ng(${PROJECT_NAME} SOURCES ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "!MySkseLibraryExample")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
include_directories(${PROJECT_NAME} include)
target_precompile_headers(${PROJECT_NAME} PUBLIC src/PCH.h)

configure_file(cmake/config.cmake.in "${PROJECT_NAME}-targets.cmake" @ONLY)

include(GNUInstallDirs)
install(DIRECTORY "${CMAKE_SOURCE_DIR}" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(TARGETS "${PROJECT_NAME}" EXPORT "${PROJECT_NAME}-targets" DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(EXPORT "${PROJECT_NAME}-targets" NAMESPACE "MySkseLibraryExample::" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-targets.cmake" DESTINATION "${CMAKE_INSTALL_LIBDIR}/../share/${PROJECT_NAME}")

add_custom_command(
	TARGET "${PROJECT_NAME}"
	POST_BUILD
	COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:${PROJECT_NAME}>" "${PROJECT_SOURCE_DIR}/SKSE/Plugins/$<TARGET_FILE_NAME:${PROJECT_NAME}>"
	COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_PDB_FILE:${PROJECT_NAME}>" "${PROJECT_SOURCE_DIR}/SKSE/Plugins/$<TARGET_PDB_FILE_NAME:${PROJECT_NAME}>"
	VERBATIM
)
