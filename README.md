# cub3d

A simple 3D raycasting engine built in C using the [MLX42](https://github.com/codam-coding-college/MLX42) library, inspired by Wolfenstein 3D.  
The program renders a first-person view of a maze using a 2D map and simulates depth through raycasting.

This project is part of the 42 School curriculum and demonstrates proficiency in graphics programming, mathematical concepts, event handling, and memory management.

## Prerequisites:

Before building the project, ensure you have the following installed:

- GNU Make
- GCC (C compiler)
- G++ (C++ compiler, required for MLX42)
- CMake
- X11 development libraries
- libbsd
- unzip
- OpenGL development libraries (libgl1-mesa-dev, libglx-dev)

- GNU Make
- GNU Compiler Collection:
  - `gcc` (C compiler)
  - `g++` (C++ compiler, required for MLX42)
- CMake
- X11 development libraries
- OpenGL development libraries
- GLFW and related X11 extensions
- `unzip` utility (for extracting assets)

Install all dependencies on Debian/Ubuntu-based systems:

```
sudo apt update && sudo apt install \
    make gcc cmake g++ unzip \
    libx11-dev libxext-dev libbsd-dev \
    libgl1-mesa-dev libglx-dev libxrandr-dev \
    libxinerama-dev libxcursor-dev libxi-dev \
    libglfw3-dev
```

## Installation

1.  Clone the repository:

```
git clone https://github.com/YellowFlash1040/cub3d.gitcd cub3d
```

2.  Build the project:

```
make
```

This will create an executable named `cub3d` in the project directory.

## Usage

Run the program with a map configuration file:

```
./cub3d maps/map.cub
```

### Controls

- **W / A / S / D**: Move the player
- **Left / Right Arrow**: Rotate the camera
- **ESC / Close window**: Quit the program

## Map Format

Maps must be provided in a `.cub` configuration file and follow specific rules:

- The map must be enclosed by walls (`1`)
- Valid characters:
  - `0` – empty space
  - `1` – wall
  - `N`, `S`, `E`, `W` – player starting position and orientation
- The file also includes:
  - Texture paths for each wall direction
  - Floor and ceiling colors

## Features

- Raycasting-based 3D rendering
- Textured walls
- Player movement and rotation
- Collision detection
- Minimap (if implemented)
- Basic lighting/shading effects (if implemented)

## Example

```
./cub3d maps/example.cub
```

## Notes

- The rendering uses a raycasting algorithm similar to early 3D games.
- Proper parsing and validation of the `.cub` file are required.
- Memory management and error handling are critical for stability.
