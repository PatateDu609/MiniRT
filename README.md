# MiniRT
A small RayTracer based on MiniLibx

# Context

This project has been implemented for the 42 School as an introduction to 3D programmation.
However, it has been adapted to be used as reference by students in the last year of the
University of Paris' bachelor. It does not follow the 42 Norm anymore and it doesn't use my libft.

# Requirements

This has been tested using:

- GNU Make 4.3
- GCC 11.3

# Usage

Makefile commands
```shell
make # build the program and rebuilds if any .c has been updated

# Clean everything and start the build from scratch
make re # if any header file has been modified (the Makefile do not support header file dependencies)

make clean # to clean object files
make fclean # to clean object files AND the executable
```

MiniRT command:
```shell
./miniRT scene.rt # render scene as bmp file
./miniRT scene.rt -save # render scene as bmp file
./miniRT scene.rt -png # render scene as png file
```
