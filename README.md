# Algorithms & Data Structures Project with VSCode/Docker, CMake and Googletest
I setup this repo to practice programming in C++. It also works as project setup example with [CMake](https://cmake.org/) and [Googletest](https://google.github.io/googletest/).

# Execute Instructions
The asumption is that you have [VSCode](https://code.visualstudio.com/) setup with [Docker](https://docs.docker.com/desktop/windows/) on Windows or Mac.
In the container terminal:
    cd build
    cmake -S ../ -B .
    cmake --build .
    ctest