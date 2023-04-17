# TempestEngine

## A W.I.P Game engine/Graphics engine
[![Ubuntu | CMake](https://github.com/Vitoludde/TempestEngine/actions/workflows/ubuntu-cmake.yml/badge.svg)](https://github.com/Vitoludde/TempestEngine/actions/workflows/ubuntu-cmake.yml)

[![Windows | CMake](https://github.com/Vitoludde/TempestEngine/actions/workflows/windows-cmake.yml/badge.svg)](https://github.com/Vitoludde/TempestEngine/actions/workflows/windows-cmake.yml)

This is project is a long sighted project. The main goal at this stage of the project is to integrate a custom built math engine and enable support for GLSL with some kind of casting interaction between the two, this is to lay a foundation for custom built games using this project as an engine.

## How to compile

### Windows

1. Download this repository via Zip or using the command: <br> ```git clone https://github.com/Vitoludde/TempestEngine.git```

2. Once the repository is locally downloaded: Navigate to the build folder and run following command:<br>
    ```cmake ..```

3. Depending on what compiler you have chosen or what cmake has automatically chosen your folder may look different what is followed here under Windows, if you have GCC please follow the last part of the linux tutorial.

4. If you have Visual Studio set as your compiler then CMake will generate a file called TempestEngine.sln, run this and then build the solution. An executable will be generated in PATH-TO-PROJECT/build/Debug

### Linux

1. Download this repository via Zip or using the command:<br> ```git clone https://github.com/Vitoludde/TempestEngine.git```

2. Once the repository is locally downloaded: Navigate to the build folder and run following command:<br>
    ```cmake ..```

3. Since Linux doesn't have Visual Studio CMake will now generate a makefile, please run folling command:<br>
    ```make```

4. This makefile will generate an executable in the build folder named TempestEngine
