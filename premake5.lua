-- premake5.lua
workspace "DOEngine"
   configurations { "Debug", "Release" }
   platforms { "Win32", "Win64", "Linux" }
   -- location "proj_%{_ACTION}"

project "DOEngine"
   kind "ConsoleApp"
   --kind "StaticLib"
   -- kind "DynamicLibrary"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   objdir "obj"
--- msbuild dir : C:\Windows\Microsoft.NET\Framework64\v4.0.30319
   files ({
	--	"**.h",
	--	"**.hpp",
		"src/**.cpp",
		"src/**.cc",
		"src/**.cxx",
		"include/**.h",
		"include/**.hpp",
		"include/**.hh",
		"include/**.hxx",
		
	})

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

	includedirs({
		"include",
		"thirdparty/SDL2-2.0.12-VC/include",
		"thirdparty/SDL2_image-VC/include",
		"thirdparty/SDL2_mixer-VC/include",
		"thirdparty/SDL2_ttf-VC/include"
	})
	
	libdirs {
		"thirdparty/SDL2-2.0.12-VC/lib/x86",
		"thirdparty/SDL2_image-VC/lib/x86",
		"thirdparty/SDL2_mixer-VC/lib/x86",
		"thirdparty/SDL2_ttf-VC/lib/x86"
	}

  filter  "platforms:Win64"
    defines{"WIN64"}
    system "windows"
    architecture "x64"

	includedirs({
		"include",
		"thirdparty/SDL2-2.0.12-VC/include",
		"thirdparty/SDL2_image-VC/include",
		"thirdparty/SDL2_mixer-VC/include",
		"thirdparty/SDL2_ttf-VC/include"
	})
	
		
	libdirs {
		"thirdparty/SDL2-2.0.12-VC/lib/x64",
		"thirdparty/SDL2_image-VC/lib/x64",
		"thirdparty/SDL2_mixer-VC/lib/x64",
		"thirdparty/SDL2_ttf-VC/lib/x64"
	}

	links {
      -- "Mingw32",
	  "SDL2Main",
      "SDL2",
      "wsock32",
	  "SDL2_ttf",
	  "SDL2_image",
	  "SDL2_mixer"
     }
 --filter  "platforms:Linux"
    -- defines{"LINUX"}
    -- system "linux"

	-- includedirs({
		-- "include"
	-- })
	-- links {
      -- "SDL2",
	  -- "SDL2_ttf",
	  -- "SDL2_image",
	  -- "SDL2_mixer"
     -- }
