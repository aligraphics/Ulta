project "editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. output_dir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. output_dir .. "/%{prj.name}")

    files
    {
        "source/*.cpp",
        "source/*.hpp"
    }

    includedirs
    {
        "%{wks.location}/ulta/source",
        "%{wks.location}/ulta/external"
    }

    links
    {
        "ulta"
    }

    filter "configurations:Debug"
        defines "ULTA_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ULTA_RELEASE"
        runtime "Release"
        optimize "on"