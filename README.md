# Intro

This is a lightly modified version of the [Cycles](https://www.cycles-renderer.org/) renderer. This is required by the [Cycles for Max plugin](https://github.com/jlwitthuhn/cyclesformax-opensource).

# Prerequisites

Building requires a number of third party libraries that can be found in the [Cycles for Max Dependencies](https://github.com/jlwitthuhn/cyclesformax-dependencies) repo. Use that repo to build a version of the dependencies suitable for the version of 3ds Max that you would like to target. With these dependencies build, modify `src/cmake/cyclesformax.cmake` so `MY_LIB_ROOT` points to your top-level dependency directory (containing `140r`, `141r`, etc).

You will also need some nVidia SDKs to build a plugin that can target CUDA and OptiX. These are:
* [OptiX SDK 7.1.0](https://developer.nvidia.com/designworks/optix/downloads/legacy)
* [CUDA Toolkit 11.4](https://developer.nvidia.com/cuda-11-4-0-download-archive)

If you want to support Kepler cards (GTX 600/700 series) you will need to install an older CUDA Toolkit and modify the `CYCLES_CUDA_BINARIES_ARCH` cmake variable:
* [CUDA Toolkit 10.2](https://developer.nvidia.com/cuda-10.2-download-archive)

# Versions

Each version of 3ds Max is only supported by a single version of Visual Studio

Visual Studio 2015: 3ds Max 2017-2019
Visual Studio 2017: 3ds Max 2020-2022
Visual Studio 2019: 3ds Max 2023
