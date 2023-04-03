project "ulta"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. output_dir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. output_dir .. "/%{prj.name}")

    pchheader "source/ultapch.hpp"
	pchsource "source/ultapch.cpp"

    files
	{
		"source/**.hpp",
		"source/**.cpp"
	}

    includedirs
	{
		"source"
    }

    filter "configurations:Debug"
        defines "ULTA_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ULTA_RELEASE"
        runtime "Release"
        optimize "on"