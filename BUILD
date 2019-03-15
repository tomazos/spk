package(default_visibility = ["//visibility:public"])

cc_library(
    name = "spock",
    srcs = [
        "loader.cc",
    ],
    hdrs = [
        "loader.h",
        "spock.h",
        "spock_fwd.h",
    ],
    linkopts = [
        "-ldl",
        "-lglog",
        "-lSDL2",
    ],
)

cc_library(
    name = "spkx",
    srcs = [
        "canvas.cc",
        "game.cc",
        "helpers.cc",
        "memory.cc",
        "presenter.cc",
        "program.cc",
        "rendering.cc",
    ],
    hdrs = [
        "canvas.h",
        "game.h",
        "helpers.h",
        "memory.h",
        "presenter.h",
        "program.h",
        "rendering.h",
    ],
    linkopts = [
        "-lglog",
        "-lgflags",
    ],
    deps = [
        "//dvc:file",
        "//dvc:terminate",
        "//spk:spock",
    ],
)

cc_binary(
    name = "spkx_test",
    srcs = [
        "spkx_test.cc",
    ],
    deps = [
        ":spkx",
    ],
)
