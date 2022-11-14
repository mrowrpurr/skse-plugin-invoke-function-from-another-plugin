#pragma once

#ifdef BUILD_DLL
#define API_INTERFACE __declspec(dllexport)
#else
#define API_INTERFACE __declspec(dllimport)
#endif

#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <functional>
#include <initializer_list>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <set>
#include <span>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <variant>
#include <vector>

#pragma warning(push)
#include <spdlog/sinks/basic_file_sink.h>

#ifdef NDEBUG
#	include <spdlog/sinks/basic_file_sink.h>
#else
#	include <spdlog/sinks/msvc_sink.h>
#endif
#pragma warning(pop)

namespace logger = SKSE::log;
namespace WinAPI = SKSE::WinAPI;

using namespace std::literals;

namespace stl {
	using namespace SKSE::stl;
}

#define DLLEXPORT __declspec(dllexport)
