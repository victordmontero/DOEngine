-- premake5.lua
workspace "DOEngine"
   configurations { "Debug", "Release" }
   platforms { "Win32", "Win64", "Linux" }
   -- location "proj_%{_ACTION}"

project "DOEngine"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   objdir "obj/%{cfg.buildcfg}"
   -- targetname("DOEngine")
   location("proj%{_ACTION}")

   includedirs{
	"src",
	"thirdparty/SDL/include",
	"thirdparty/SDL/build/include/",
	"thirdparty/SDL2_ttf/include/"
	}

   files {
      "src/**.h*",
      "src/**.c*",
      "*.lua"
	}

   defines({"SQLITE_THREADSAFE=1"})

   --postbuildcommands{"{COPY} assets %{cfg.buildtarget.directory}"}

   libdirs {
		"thirdparty/SDL/build"
	}

   links {
      "SDL2"
   }

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"

  filter  "platforms:Win32" 
    defines{"WIN32"}
    system "windows"
    architecture "x32"
 
     libdirs{
         "thirdparty/SDL2_ttf/lib/x86"
     }

project "SDL2Lib"
   kind "Makefile"
   objdir()
   
   cleancommands {
	   "{RMDIR} thirdparty/SDL/build/"
   }
   
   filter "configurations:Debug"
		targetdir "thirdparty/SDL/build/Debug"
		targetname "SDL2d.dll"
   
   buildcommands {
      "cmake thirdparty/SDL/ -B thirdparty/SDL/build/",
	   "cmake --build thirdparty/SDL/build/"
   }
   
   rebuildcommands {
	   "{RMDIR} thirdparty/SDL/build/",
	   "cmake thirdparty/SDL/ -B thirdparty/SDL/build/",
	   "cmake --build thirdparty/SDL/build/"
   }
   
   filter "configurations:Release"
		targetdir "thirdparty/SDL/build/Release"
		targetname "SDL2.dll"
   
   buildcommands {
	   "cmake -DCMAKE_BUILD_TYPE=Release thirdparty/SDL/ -B thirdparty/SDL/build/",
	   "cmake --build thirdparty/SDL/build/ --config Release"
   }
   
   rebuildcommands {
	   "{RMDIR} thirdparty/SDL/build/",
	   "cmake -DCMAKE_BUILD_TYPE=Release thirdparty/SDL/ -B thirdparty/SDL/build/",
	   "cmake --build thirdparty/SDL/build/ --config Release"
   }
