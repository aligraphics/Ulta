include "dependencies.lua"

workspace "Ulta"
    architecture { "x86_64" }
    configurations { "Debug", "Release" }
    flags { "MultiProcessorCompile" }

output_dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "core"
    include "ulta"
