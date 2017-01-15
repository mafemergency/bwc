workspace "bwc"
	configurations {
		"Debug",
		"Release",
	}

	platforms {
		"x86",
		"x86_64"
	}

	filter "configurations:Release"
		defines {
			"NDEBUG"
		}

		flags {
			"LinkTimeOptimization"
		}

		symbols "Off"
		optimize "Full"

	filter "configurations:Debug"
		defines {
			"DEBUG"
		}

		symbols "On"
		optimize "Off"

	filter {}

	basedir "."
	location "build"
	targetdir "build/bin"
	objdir "build/obj"


project "bwc"
	kind "ConsoleApp"
	language "C"

	includedirs {
		"include"
	}

	files {
		"src/bwc/client.c"
	}
