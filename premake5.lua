include "dependencies.lua"

workspace "Ulta"
    architecture "x86_64"
    startproject "editor"
    
    configurations 
    { 
        "Debug", "Release"
    }

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "dependencies"
    include "ulta/external/imgui"

group "core"
    include "ulta"
group ""

group "tools"
    include "editor"

group "misc"
    include "sandbox"
group ""