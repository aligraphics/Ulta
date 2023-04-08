project "ulta"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. output_dir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. output_dir .. "/%{prj.name}")

    pchheader "ultapch.hpp"
	pchsource "source/ultapch.cpp"

    files
	{
		"source/**.hpp",
		"source/**.cpp"
	}

    defines
    {
        "GLFW_INCLUDE_NONE"
    }

    includedirs
	{
		"source",
        "%{include_dir.GLFW}"
    }

    links
    {
        "GLFW"
    }

    filter "system:windows"
        systemversion "latest"
        defines
        {
            "ULTA_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "ULTA_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ULTA_RELEASE"
        runtime "Release"
        optimize "on"