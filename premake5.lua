-- premake5.lua
workspace "DOEngine"
   configurations { "Debug", "Release" }
   platforms { "Win32", "Win64", "Linux" }

project "DOEngine"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   targetname("DOEngine")


   files { "src/**.h", "src/**.cpp", "src/**.c", "**.lua" }

   defines({"SQLITE_THREADSAFE=1"})

   postbuildcommands{"{COPY} assets %{cfg.buildtarget.directory}"}

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

  filter  "platforms:Win32" 
    defines{"WIN64"}
    system "windows"
    architecture "x32"

    includedirs{
      "../SDL2-2.0.9/i686-w64-mingw32/include/"
    }
 
    libdirs{
     "../SDL2-2.0.9/i686-w64-mingw32/lib/"
    }

    links {
      "Mingw32",
      "SDL2Main",
      "SDL2",
      "wsock32"
     }
  
  filter  "platforms:Win64" 
    defines{"WIN64"}
    system "windows"
    architecture "x64"

    includedirs{
      "../SDL2-2.0.9/x86_64-w64-mingw32/include/"
    }
 
    libdirs{
     "../SDL2-2.0.9/x86_64-w64-mingw32/lib/"
    }

    links {
      "Mingw32",
      "SDL2Main",
      "SDL2",
      "wsock32"
     }

  filter  "platforms:Linux" 
    defines{"LINUX"}
    system "linux"
    links {
      "SDL2"
     }

  -- project "SDL2Proj"
  --   kind "Makefile"
 
  --   buildcommands {
  --     --  '{MKDIR} %{wks.location}/thirdparty/SDL2/build',
  --      'cmake ../thirdparty/SDL2',
  --      'cmake --build .'
  --   }
 
  --   rebuildcommands {
  --     -- '{MKDIR} %{wks.location}/thirdparty/SDL2/build',
  --     'cmake ../thirdparty/SDL2',
  --     'cmake --build .'
  --   }
 
  --   cleancommands {
  --     '{RMDIR} build'
  --   }