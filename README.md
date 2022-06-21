# Woman Pong Source Code
This repository contains the source code of the 'Woman Pong' game. Currently only a linux distribution is supported for direct build of the game. If you are building for any other OS other than a linux derivative, then you will have to build it yourself manually.

## This project has the following dependancies:
* Latest version of SDL2
* Any compiler which supports the latest C++ standard aka C++20. Edit the cmake configuration file according to the compiler that you use. This project uses the GNU clang by default.
* cmake
* bash

If you want to directly build the project with little to no efforts as it is distributed in this repository, then you must fulfill the given dependencies first.

## How to build the project:
### For Linux:
1. Enter terminal and change directory to the parent folder of this project.
2. Execute the following command in terminal to build the project:
> bash build.sh
3. If the command is executed successfully, there would be 3 new folders created in the parent directory of the project:
    * bin : This folder contains the final executable of the project.
    * build : This folder contains the cmake build files of the project.
    * lib : This folder contains the dynamic library generated from the implementation files of the project.

## How to run the final executable:
### For Linux:
1. Change directory to the parent directory of the project.
2. Excute the command below to run the binary:
> bin/woman_pong

NOTE: If the contents of the `assets`, `bin`, and/or `lib` directory are moved from their places where they were originally generated, the game may not work properly. So maintain the build tree properly.

## License and copyright:
Information related to licensing and copyright can be found at the `LICENSE.md` file. Please read through it before doing any modification to the source code.
