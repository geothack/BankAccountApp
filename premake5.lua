
workspace "BankApp"
    configurations {"Debug","Release"}    

    startproject "Game"

project "App"
    kind "ConsoleApp"

    language "C++"
    cppdialect "C++latest"
    targetdir "bin/%{cfg.buildcfg}"

    architecture ("x64")

    includedirs 
    { 
        "Source",
        "glfw/include",
        "imgui-1.92.1",
        "glad/include",
        "stb",
    }

    libdirs 
    {
       "glfw/lib", 
       --"deps/assimp/lib", 
       
    }

    links 
    {
      "DearImgui",
       "glfw3.dll",
       "glfw3.lib",
       "Glad",
       "Stb"
    

    }

   files
    { 
      "Source/**.h", 
      "Source/**.cpp"
    }

    

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      buildoptions { "/MP" }
      kind "ConsoleApp"

      links 
      {
          --"assimp-vc143-mtd.lib",
          --"assimp-vc143-mtd.dll",
          --"freetyped.lib",
          --"box2dd.lib",
      }

      postbuildcommands { "{COPY} glfw/lib/glfw3.dll bin/Debug" }
      --postbuildcommands { "{COPY} Dependencies/Assimp/Library/assimp-vc143-mtd.dll bin/Debug" }
      --postbuildcommands { "{COPY} deps/openal/lib/OpenAL32.dll bin/Debug" }

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      buildoptions { "/MP" }
      kind "WindowedApp"

      links 
      {
          --"assimp-vc143-mt.lib",
          --"assimp-vc143-mt.dll",
          --"freetype.lib",
          --"rbox2d.lib",
      }

      --postbuildcommands { "{COPY} libs/sdl3/lib/x64/SDL3.dll bin/Release" }
      --postbuildcommands { "{COPY} libs/openal/libs/OpenAL32.dll bin/Release" }

project "DearImgui"
    kind "StaticLib"

    language "C++"
    cppdialect "C++latest"
    targetdir "bin/%{cfg.buildcfg}"

    architecture ("x64")

    includedirs 
    { 
        "glfw/include",
        "imgui-1.92.1",
    }

    libdirs 
    {
       "glfw/lib", 
    }

    links
    {
      "glfw3.lib",
      "glfw3.dll",
    }

   files
    { 
      "imgui-1.92.1/**.h", 
      "imgui-1.92.1/**.cpp",
      "imgui-1.92.1/**.txt"
    }

    
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      buildoptions { "/MP" }

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      buildoptions { "/MP" }


project "Glfw"
    kind "StaticLib"

    language "C++"
    cppdialect "C++latest"
    targetdir "bin/%{cfg.buildcfg}"

    architecture ("x64")

   files
    { 
      "glfw/**.h", 
      "glfw/**.cpp",
    }

    
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      buildoptions { "/MP" }

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      buildoptions { "/MP" }


project "Glad"
    kind "StaticLib"

    language "C++"
    cppdialect "C++latest"
    targetdir "bin/%{cfg.buildcfg}"

    architecture ("x64")

   files
    { 
      "glad/**.h", 
      "glad/**.c",
    }

    includedirs 
    { 
        "glad/include",
    }

    
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      buildoptions { "/MP" }

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      buildoptions { "/MP" }



project "Stb"
    kind "StaticLib"

    language "C++"
    cppdialect "C++latest"
    targetdir "bin/%{cfg.buildcfg}"

    architecture ("x64")

   files
    { 
      "stb/**.h", 
      "stb/**.c",
    }
    
   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      buildoptions { "/MP" }

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      buildoptions { "/MP" }

