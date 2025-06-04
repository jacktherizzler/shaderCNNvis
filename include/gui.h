#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "renderer.h"
#include "imgui/imgui.h"

class GUI {
public:
    GUI();
    ~GUI();
    bool init(GLFWwindow* window);
    void render(Renderer& renderer);
    void cleanup();

private:
    struct Kernel {
        std::string name;
        std::vector<float> weights;
        int size;
    };
    
    std::vector<Kernel> kernels;
    int currentKernel;
    
    void setupKernels();
    void showKernelSelector();
    void showPreviewWindow(GLuint textureID);
    void showControlPanel();
};