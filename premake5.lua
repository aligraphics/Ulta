workspace "Ulta"
    architecture "x86_64"
    startproject "sandbox"
    
    configurations 
    { 
        "Debug", "Release"
    }

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "core"
    include "ulta"
group ""

group "misc"
    include "sandbox"
group ""