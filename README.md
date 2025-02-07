# Woman Pong
Pong game that behaves like women. Currently only a linux distribution is supported for direct builds. If you are building for any other OS other than a linux derivative, then you will have to build it manually.

## Dependencies:
* SDL2
* Any compiler that supports at least C++20. Edit CMakeLists.txt as you need to. The default compiler is clang.
* cmake
* bash

If you want to directly build the project with little to no efforts as it is distributed in this repository, then you must fulfill the given dependencies first.

## Manual Build:
### Linux:
1. Enter terminal and change directory to the parent folder.
2. Execute the following to build:
> bash build.sh
3. If the command executed successfully, there would be 3 new folders created in the parent directory:
    * bin : Contains the final executable.
    * build : Contains the build files.
    * lib : Contains dynamic libraries.

## Execution:
### Linux:
1. Change directory to the parent folder.
2. Excute the following to run:
> bin/woman_pong

NOTE: If the contents of the `assets`, `bin`, and/or `lib` directory are moved from their places where they were originally generated, the game may not work properly. So maintain the directory tree properly.

## License and Copyright:
Read `LICENSE.md` before doing any modification.
