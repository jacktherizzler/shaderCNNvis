# Shader-based CNN Visualizer

A lightweight tool that visualizes the convolution operations of CNN layers in real-time using OpenGL fragment shaders. This project demonstrates how convolution operations can be efficiently performed on the GPU using custom shaders.

## Features

- OpenGL-powered visualizations of CNN feature maps
- Shader-based convolution simulation for GPU acceleration
- Interactive controls to switch between kernels and layers
- Minimal GUI built with GLFW and Dear ImGui
- Supports various 2D filters and edge detection operations

## Prerequisites

- OpenGL 3.3+
- GLFW
- GLEW
- CMake
- STB Image (included)

## Building from Source

```bash
git clone https://github.com/jacktherizzler/shader-cnn-visualizer
cd shader-cnn-visualizer
mkdir build && cd build
cmake ..
make
```

## Usage

Run the executable:
```bash
./cnn_visualizer
```

### Available Kernels

1. Edge Detection
   - Sobel X
   - Sobel Y
   - Laplacian

2. Blur Effects
   - Box Blur
   - Gaussian Blur

3. Image Enhancement
   - Sharpen

## Controls

- Use the kernel selector panel to switch between different convolution kernels
- View the results in real-time in the preview window
- Press ESC to exit the application

## Project Structure

```
.
├── CMakeLists.txt
├── include/
│   ├── shader.h
│   ├── renderer.h
│   └── gui.h
├── src/
│   ├── main.cpp
│   ├── shader.cpp
│   ├── renderer.cpp
│   └── gui.cpp
└── shaders/
    ├── vertex.glsl
    └── convolution.glsl
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.