


# Simple 3D Renderer using SDL2

This is a simple 3D renderer built using SDL2 library in C++. It renders 3D points and vertices onto a 2D screen.


## Getting Started

1. Clone the repository:
   ```bash
   git clone Vlad421/SpinningCube
   ```
2. Navigate to the project directory:
   ```bash
   cd SpinningCube
   ```

### Prerequisites

To build and run this project, you need:

- C++ compiler supporting C++11 or later
- SDL2 library installed on your system

#### Installing SDL2

- **On Ubuntu:**
  ```bash
  sudo apt update
  sudo apt install libsdl2-dev
  ```

- **On macOS with Homebrew:**
  ```bash
  brew install sdl2
  ```

- **On Windows:**
  You can download the SDL2 development libraries from the [official website](https://www.libsdl.org/download-2.0.php) and follow the instructions for setup. After downloading, you can follow these steps:
  
  - Extract the downloaded archive.
  - Copy the contents of the `include` folder to your compiler's include directory.
  - Copy the `.lib` files from the `lib` folder to your compiler's library directory.
  - Copy the `.dll` files from the `lib` folder to your project directory or to a location in your system's PATH.

3. Build the project:
   - If using CMake:
     ```bash
     mkdir build && cd build
     cmake ..
     make
     ```
   - If using Makefile:
     ```bash
     make
     ```

## Usage

After building the project, you can run the executable to see the simple 3D rendering in action.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


