#pragma once
#include <string>

namespace KMG
{
	class Log
	{
	public:
		virtual ~Log() = default;

		static void Trace(const std::string& text);
		static void Info(const std::string& text);
		static void Warn(const std::string& text);
		static void Error(const std::string& text);

	private:
		Log() = default;
	};

#ifdef KMG_DEBUG
	#define KMG_LOG_TRACE(x) ::KMG::Log::Trace(x)
	#define KMG_LOG_INFO(x)  ::KMG::Log::Info(x)
	#define KMG_LOG_WARN(x)  ::KMG::Log::Warn(x)
	#define KMG_LOG_ERROR(x) ::KMG::Log::Error(x)
#else
	#define KMG_LOG_TRACE(x)
	#define KMG_LOG_INFO(x)
	#define KMG_LOG_WARN(x)
	#define KMG_LOG_ERROR(x)
#endif
}

