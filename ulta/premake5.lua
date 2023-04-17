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
		"source/**.cpp",
	}

    defines
    {
    }

    includedirs
	{
		"source",
        "external",
        "%{include_dir.glfw}",
    }

    libdirs
    {
        "%{library_dir.glfw}",
        "%{library_dir.imgui}"
    }

    links
    {
        "glfw3",
        "ImGui.lib",
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