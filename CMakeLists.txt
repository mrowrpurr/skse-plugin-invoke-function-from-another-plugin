cmake_minimum_required(VERSION 3.21)

project(MySkseLibraryExample VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_DLL "Build main .dll (will dllexport rather than dllimport)" OFF)

file(GLOB_RECURSE API_INTERFACE_FILES include/*.h)
file(GLOB_RECURSE IMPLEMENTATION_FILES src/*.cpp src/*.h include_implementation/*.h)

if(BUILD_DLL)
	add_definitions(-DBUILD_DLL)
	set(SOURCE_FILES ${API_INTERFACE_FILES} ${IMPLEMENTATION_FILES})
	set(INCLUDE_FOLDERS include include_implementation)
else()
	set(SOURCE_FILES ${API_INTERFACE_FILES} src/PCH.h) # client seems to want the PCH
	set(INCLUDE_FOLDERS include)
endif()

message(STATUS "Here are the source files ${SOURCE_FILES}")

include(cmake/CommonLibNG.cmake)
find_package(CommonLibSSE CONFIG REQUIRED)
add_commonlibsse_plugin_ng(${PROJECT_NAME} SOURCES ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "!MySkseLibraryExample")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
include_directories(${PROJECT_NAME} ${INCLUDE_FOLDERS})
target_precompile_headers(${PROJECT_NAME} PUBLIC src/PCH.h)

include(GNUInstallDirs)

# Tutorial: https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20Export%20Configuration.html
install(DIRECTORY "${CMAKE_SOURCE_DIR}" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(TARGETS "${PROJECT_NAME}" EXPORT "${PROJECT_NAME}-targets" DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(EXPORT "${PROJECT_NAME}-targets" FILE "${PROJECT_NAME}-targets.cmake" NAMESPACE "MySkseLibraryExample::" DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
	"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
	NO_SET_AND_CHECK_MACRO
	NO_CHECK_REQUIRED_COMPONENTS_MACRO
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
export(EXPORT "${PROJECT_NAME}-targets" FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-targets.cmake")

if(BUILD_DLL)
	add_custom_command(
		TARGET "${PROJECT_NAME}"
		POST_BUILD
		COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:${PROJECT_NAME}>" "${PROJECT_SOURCE_DIR}/SKSE/Plugins/$<TARGET_FILE_NAME:${PROJECT_NAME}>"
		COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_PDB_FILE:${PROJECT_NAME}>" "${PROJECT_SOURCE_DIR}/SKSE/Plugins/$<TARGET_PDB_FILE_NAME:${PROJECT_NAME}>"
		VERBATIM
	)
endif()
