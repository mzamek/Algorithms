# Algorithms & Data Structures Project with VSCode/Docker, CMake and Googletest
I setup this repo to practice programming in modern C++. It is currently WIP. Some of the features this repo will include are:
- Data Structures
- Dynamic Programming Problems
- NP-Complete Problems
- C++ Features
    - Templates/Variadic Templates
    - Smart Pointers
    - C++17
- Basic Dockerfile
- Unit tests
- Repo also works as project setup example with [CMake](https://cmake.org/) and [Googletest](https://google.github.io/googletest/).

You can open project in docker and execute unit tests.

# Execute Instructions
The asumption is that you have [VSCode](https://code.visualstudio.com/) setup with [Docker](https://docs.docker.com/desktop/windows/) on Windows or Mac. There is nothing else needed.
In the container terminal:
```shell
    cd build
    cmake -S ../ -B .
    cmake --build .
    ctest
```