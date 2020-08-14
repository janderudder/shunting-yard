-- premake5.lua
workspace "C++17-Project-Workspace"
   configurations { "release", "debug" }

project "shunting-yard"

   kind        "ConsoleApp"
   objdir      "%{cfg.buildcfg}/obj"
   language    "C++"
   cppdialect  "C++17"
   location    "../"
   targetdir   "../bin/"
   targetname  "shunting-yard"

   files {
      "../src/**.cpp"
   }
   includedirs    { "../include" }

   enablewarnings { "all", "extra", "shadow", "unused" }

   filter "configurations:debug"
      defines  { "DEBUG" }
      symbols  "On"
      optimize "Debug"

   filter "configurations:release"
      symbols  "Off"
      defines  { "NDEBUG" }
      optimize "On"
