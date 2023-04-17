-- Engine Dependencies

include_dir = {}
include_dir["glfw"] = "%{wks.location}/ulta/external/glfw/include"


library_dir = {}
library_dir["glfw"] = "%{wks.location}/ulta/external/glfw/build/src/%{cfg.buildcfg}"
library_dir["imgui"] = "%{wks.location}/ulta/external/imgui/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/ImGui"