workspace "Ulta"
    architecture "x86_64"
    
    configurations 
    { 
        "Debug", "Release"
    }

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "core"
    include "ulta"
group ""