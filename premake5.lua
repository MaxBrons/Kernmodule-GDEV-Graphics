-- Kernmodule-Graphics-Assembly
workspace "Kernmodule-Graphics-Assembly"
	architecture "x64"
	startproject "Kernmodule-Graphics-Assembly"

	configurations
	{
		"Debug",
		"Release",
        	"Distribution"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to Core/vendor
IncludeDir = {}
IncludeDir["GLFW"] = "vendor/glfw/include"
IncludeDir["Glad"] = "vendor/glad/include"
IncludeDir["glm"] = "vendor/glm"
IncludeDir["stb_image"] = "vendor/stb_image"

-- Projects
group "Dependencies"
	include "Core/vendor/premake5_glfw.lua"
	include "Core/vendor/premake5_glad.lua"
group ""

include "Core"
include "Example-Assembly"