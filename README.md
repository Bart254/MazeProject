# Raycasting Game

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)

## Description
This project is a raycasting game developed in C, implementing a graphics rendering engine using SDL2. Raycasting is a rendering technique used to create a 3D perspective in a 2D map, reminiscent of early video games like Wolfenstein 3D.

## Features
- Render walls with different colors
- Implement player movement and rotation
- Handle player collisions with walls
- Parse maps from files
- Draw the map on the window
- Add textures on walls, ground, and ceiling

### Features yet to be done
- Introduce enemies into the game
- Add weather effects like rain
- Implement additional features like shadows, special lighting, etc.

## Installation
1. Clone the repository:
    ```
    git clone https://github.com/Bart254/MazeProject.git
    ```
2. Navigate to the project directory:
    ```
    cd MazeProject 
    ```
3. Navigate to src files then compile the program using GCC:
    ```
    cd src
    gcc -o maze *.c -lSDL2 -lm -lSDL2_image
    ```

4. Alternatively, use the make file
    ```
    make
    ```

## Usage
1. Run the compiled program:
    ```
    ./maze
    ```
2. Follow the in-game instructions to control the player movement, rotation, and other actions:
    `w - moves forward`
    `s - moves back`
    `a - turns left`
    `d-  turns right`

## Contributing
Contributions are welcome! If you'd like to contribute to this project, feel free to open an issue or submit a pull request with your changes.

