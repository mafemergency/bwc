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
        optimize "On"

    filter "configurations:Debug"
        defines {
            "DEBUG"
        }

        symbols "On"
        optimize "Off"

    filter {}

    flags {
        "C99",
    }

    basedir "."
    location "build"
    targetdir "build/bin"
    objdir "build/obj"


project "bwc"
    kind "StaticLib"
    language "C"

    includedirs {
        "include"
    }

    files {
        "src/bwc/bwc.c",
        "src/bwc/client.c",
        "src/bwc/command.c"
    }


project "dummy"
    kind "ConsoleApp"
    language "C"

    includedirs {
        "include"
    }

    files {
        "src/example/dummy.c"
    }

    links {
        "bwc"
    }
