# funkin_cpp

[Friday Night Funkin'](https://github.com/FunkinCrew/Funkin) fan-game recreation made in C++
with various libraries such as [GLFW](https://www.glfw.org/) and [OpenAL-Soft](https://openal-soft.org/).

## Purpose

To create a version of FNF that can be more heavily optimized and tweaked to run -- basically however you want.

Hopefully with good modding support *eventually*, but getting anything to work is the primary focus at first lol.

## Building

In the future there will probably be a more comprehensive guide, but for now just know this project
uses [CMake](https://cmake.org/) as its buildsystem, and targets C++ 17.

Currently things are being tested on Windows primarily -- however support for other systems will come
eventually (at least for major desktop platforms like macOS & X11/Wayland on Linux).

If you want to try building yourself just run:
  1. `cmake -B build`
  2. `cmake --build build`

You can add more options to these commands, like `-G Ninja` in the first to specify using the [Ninja buildsystem](https://ninja-build.org/)
(which may be required for some things like proper `compile_commands.json` support if you have another buildsystem as your default).
