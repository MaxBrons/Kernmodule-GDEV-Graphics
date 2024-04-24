#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <memory>

#ifdef KMG_DEBUG
	#ifdef KMG_PLATFORM_WINDOWS
		#define KMG_DEBUGBREAK() __debugbreak()
	#else
		#error "Platform doesn't support debugbreak."
	#endif
	
	#define KMG_CORE_VALIDATE(x, message) if(!(x)) KMG_LOG_ERROR(message)
	#define KMG_CORE_ASSERT(x, message) if(!(x)) { KMG_LOG_ERROR(message); KMG_DEBUGBREAK(); }
#else
	#define KMG_DEBUGBREAK()
#endif

#define KMG_BIND_EVENT(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace KMG
{
	template<typename T>
	using u_ptr = std::unique_ptr<T>;
	template<typename T, typename... Args>
	constexpr u_ptr<T> MakeUnique(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using s_ptr = std::shared_ptr<T>;
	template<typename T, typename... Args>
	constexpr s_ptr<T> MakeShared(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}