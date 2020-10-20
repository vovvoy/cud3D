cmake_minimum_required(VERSION 3.12)
project(cub3d C)

set(CMAKE_C_FLAGS "-Lmlx -lmlx -framework OpenGL -framework AppKit")

link_directories(/usr/local/lib)
include_directories(/usr/local/include)


add_executable(cub3d main.c main.c)