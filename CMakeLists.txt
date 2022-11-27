cmake_minimum_required(VERSION 3.21)

project(SKSE.Plugin.Examples VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(DEPLOY_MOD "Copy mod .dll and resource into %SKYRIM_MODS_DEPLOY_ROOT%\\${PROJECT_NAME}" OFF)

# Override <DEPLOY_ROOT> to set the path of a mod to deploy files to.
# The SKSE plugin files will be writen to <DEPLOY_ROOT>/<PROJECT_NAME>/SKSE/Plugins
# You can use the environment variable SKYRIM_MODS_DEPLOY_ROOT to set a default <DEPLOY_ROOT>
# set(DEPLOY_ROOT "C:/some/path/to/mod/path")

find_package(CommonLibSSE CONFIG REQUIRED)

add_subdirectory(PluginWithFunction)
add_subdirectory(PluginThatCallsOtherPluginsFunction)
