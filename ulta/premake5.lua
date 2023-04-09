project "ulta"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. output_dir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. output_dir .. "/%{prj.name}")

    files
	{
		"source/**.hpp",
		"source/**.cpp"
	}

    defines
    {
    }

    includedirs
	{
		"source",
        "%{include_dir.glfw}"
    }

    links
    {
        "glfw3"
    }

    filter "system:windows"
        systemversion "latest"
        pchheader "ultapch.hpp"
        pchsource "source/ultapch.cpp"
        defines
        {
            "ULTA_PLATFORM_WINDOWS"
        }

    filter "system:macosx"
        systemversion "latest"
        pchheader "source/ultapch.hpp"
        pchsource "source/ultapch.cpp"
        defines
        {
            "ULTA_PLATFORM_MACOS"
        }

    filter "configurations:Debug"
        defines "ULTA_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ULTA_RELEASE"
        runtime "Release"
        optimize "on"