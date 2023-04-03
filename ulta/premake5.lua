project "ulta"
    kind "StaticLib"
    language "C++"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "source/ultapch.h"
	pchsource "source/ultapch.cpp"

    files
	{
		"source/**.h",
		"source/**.cpp",
	}

    includedirs
	{
		"source"
    }

    links
    {
    }

    filter "configurations:Debug"
    {
        defines "ULTA_DEBUG"
        runtime "Debug"
        symbols "on"
    }

    filter "configurations:Release"
    {
        defines "ULTA_RELEASE"
        runtime "Release"
        optimize "on"
    }