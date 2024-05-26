project "Example-Assembly"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"../Core/src",
		"../Core/src/Core",
		"../Core/vendor",
		"../Core/%{IncludeDir.glm}",
		"../Core/%{IncludeDir.Glad}",
	}

	links
	{
		"Core"
	}

	postbuildcommands {
        "{COPY} assets %{cfg.targetdir}/assets/"
    }

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"KMG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "KMG_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "KMG_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Distribution"
		defines "KMG_DISTRIBUTION"
		runtime "Release"
		optimize "on"
