-- premake5.lua
workspace "DOEngine"
   configurations { "Debug", "Release" }
   platforms { "Win32", "Linux" }

project "DOEngine"
   kind "WindowedApp"
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
	"src/**.h",
	"src/**.cpp",
	"src/**.c",
	"*.lua"
	}

	-- removefiles {"src/old_state/**"}

   ---defines({"SQLITE_THREADSAFE=1"})

   --postbuildcommands{"{COPY} assets %{cfg.buildtarget.directory}"}

  filter "configurations:Debug"
    defines { "DEBUG" }
    symbols "On"
	
	libdirs {
		"thirdparty/SDL/build/Debug"
	}
	
	links {
      -- "Mingw32",
      "SDL2Maind",
      "SDL2d",
      "wsock32",
	  "SDL2_ttf"
     }

  filter "configurations:Release"
    defines { "NDEBUG" }
    optimize "On"
	
	libdirs {
		"thirdparty/SDL/build/Release"
	}
	
	links {
      -- "Mingw32",
      "SDL2Main",
      "SDL2",
      "wsock32",
	  "SDL2_ttf"
     }

  filter  "platforms:Win32" 
    defines{"WIN32"}
    system "windows"
    architecture "x32"
 
     libdirs{
      -- "thirdparty/SDL2-2.0.10/lib/x86/",
	  -- "thirdparty/SDL/build/Debug",
	  "thirdparty/SDL2_ttf/lib/x86"
     }

  filter  "platforms:Linux" 
    defines{"LINUX"}
    system "linux"
    links {
      "SDL2"
     }

project "SDL2Lib"
   kind "Makefile"
   objdir()
   
   cleancommands {
	"{ECHO} Cleaning SDL2",
	"{RMDIR} thirdparty/SDL/build/"
   }
   
   filter "configurations:Debug"
		targetdir "thirdparty/SDL/build/Debug"
		targetname "SDL2d.dll"
   
   buildcommands {
	"{ECHO} Building SDL2",
	"cmake thirdparty/SDL/ -A Win32 -B thirdparty/SDL/build/",
	"cmake --build thirdparty/SDL/build/"
   }
   
   rebuildcommands {
	"{ECHO} Re Building SDL2",
	"{RMDIR} thirdparty/SDL/build/",
	"cmake thirdparty/SDL/ -A Win32 -B thirdparty/SDL/build/",
	"cmake --build thirdparty/SDL/build/"
   }
   
   filter "configurations:Release"
		targetdir "thirdparty/SDL/build/Release"
		targetname "SDL2.dll"
   
   buildcommands {
	"{ECHO} Building SDL2",
	"cmake -DCMAKE_BUILD_TYPE=Release thirdparty/SDL/ -A Win32 -B thirdparty/SDL/build/",
	"cmake --build thirdparty/SDL/build/ --config Release"
   }
   
   rebuildcommands {
	"{ECHO} Re Building SDL2",
	"{RMDIR} thirdparty/SDL/build/",
	"cmake -DCMAKE_BUILD_TYPE=Release thirdparty/SDL/ -A Win32 -B thirdparty/SDL/build/",
	"cmake --build thirdparty/SDL/build/ --config Release"
   }
   
		