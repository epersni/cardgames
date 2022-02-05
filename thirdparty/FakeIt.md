# FakeItUsageExample
This is an example which tests forked [FakeIt](https://github.com/libenike/FakeIt/tree/feature/add_cmake_support).

The purpose of the fork to add CMake support for FakeIt.
I fork FakeIt and change the corresponding CMakeLists.txt.
This project is a simple example which uses FakeIt.

Now to build this project, you must follow these steps:
1) Download FakeIt.

`git clone https://github.com/libenike/FakeIt.git`

2) Download the project.

`git clone https://github.com/libenike/FakeItUsageExample.git`

3) Cd to FakeIt and build it.

```
cd FakeIt
git checkout feature/add_cmake_support
cmake -S . -B build_ -DCMAKE_INSTALL_PREFIX=install
cmake --build build_
cmake --install build_
```


4) Cd to the project and build.

```
cd ../FakeItUsageExample/
cmake -S . -B build -DFakeIt_DIR=../FakeIt/install/lib/cmake/FakeIt/
cmake --build build/
```

As a result, this project has been built without errors.

Then use as:

```
cmake_minimum_required(VERSION 3.0)

project(FakeItUsageExample)

find_package(FakeIt REQUIRED)

add_executable(FakeItUsageExample
    FakeItUsageExample.cpp
)
target_link_libraries(FakeItUsageExample
    PRIVATE
        FakeIt::FakeIt
)
```

