workspace "bwc"
    configurations {
        "Debug",
        "Release",
        "DebugDLL",
        "ReleaseDLL"
    }

    platforms {
        "x86",
        "x86_64"
    }

    filter "configurations:Release*"
        defines {
            "NDEBUG"
        }

        flags {
            "LinkTimeOptimization"
        }

        symbols "Off"
        optimize "On"

    filter "configurations:Debug*"
        defines {
            "DEBUG"
        }

        symbols "On"
        optimize "Off"

    filter "platforms:x86"
        architecture "x86"

    filter "platforms:x86_64"
        architecture "x86_64"

    filter {}

    flags {
        "C99",
    }

    basedir "."
    location "build"
    targetdir "build/bin"
    objdir "build/obj"
    implibdir "build/lib"


project "bwc"
    kind "StaticLib"

    filter "configurations:DebugDLL or ReleaseDLL"
        kind "SharedLib"
        defines {
            "BWC_EXPORT_DLL"
        }

    filter {}

    language "C"

    includedirs {
        "include"
    }

    files {
        "src/bwc/bwc.c",
        "src/bwc/client.c",
        "src/bwc/command.c",
        "src/bwc/draw.c"
    }


project "dummy"
    kind "ConsoleApp"
    language "C"

    filter "configurations:*DLL"
        defines {
            "BWC_IMPORT_DLL"
        }

    filter {}

    includedirs {
        "include"
    }

    files {
        "src/example/dummy.c"
    }

    links {
        "bwc"
    }
