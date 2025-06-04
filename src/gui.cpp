#define GL_SILENCE_DEPRECATION
#include "gui.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <OpenGL/gl3.h>

GUI::GUI() : currentKernel(0) {
    setupKernels();
}

GUI::~GUI() {
    cleanup();
}

bool GUI::init(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    if (!ImGui_ImplGlfw_InitForOpenGL(window, true) ||
        !ImGui_ImplOpenGL3_Init("#version 330")) {
        return false;
    }

    return true;
}

void GUI::render(Renderer& renderer) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    showKernelSelector();
    showPreviewWindow(renderer.getOutputTexture());
    showControlPanel();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GUI::cleanup() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void GUI::setupKernels() {
    // Edge detection kernels
    kernels.push_back({"Sobel X", {
        -1, 0, 1,
        -2, 0, 2,
        -1, 0, 1
    }, 3});

    kernels.push_back({"Sobel Y", {
        -1, -2, -1,
         0,  0,  0,
         1,  2,  1
    }, 3});

    kernels.push_back({"Laplacian", {
         0,  1,  0,
         1, -4,  1,
         0,  1,  0
    }, 3});

    // Blur kernels
    kernels.push_back({"Box Blur", {
        1/9.0f, 1/9.0f, 1/9.0f,
        1/9.0f, 1/9.0f, 1/9.0f,
        1/9.0f, 1/9.0f, 1/9.0f
    }, 3});

    kernels.push_back({"Gaussian Blur", {
        1/16.0f, 2/16.0f, 1/16.0f,
        2/16.0f, 4/16.0f, 2/16.0f,
        1/16.0f, 2/16.0f, 1/16.0f
    }, 3});

    // Sharpen kernel
    kernels.push_back({"Sharpen", {
         0, -1,  0,
        -1,  5, -1,
         0, -1,  0
    }, 3});
}

void GUI::showKernelSelector() {
    ImGui::Begin("Kernel Selection");

    for (size_t i = 0; i < kernels.size(); i++) {
        if (ImGui::RadioButton(kernels[i].name.c_str(), currentKernel == i)) {
            currentKernel = i;
        }
    }

    ImGui::End();
}

void GUI::showPreviewWindow(GLuint textureID) {
    ImGui::Begin("Preview");
    
    ImVec2 windowSize = ImGui::GetContentRegionAvail();
    ImGui::ImageWithBg((ImTextureID)textureID, windowSize, ImVec2(0, 0), ImVec2(1, 1), ImVec4(1, 1, 1, 1));

    ImGui::End();
}

void GUI::showControlPanel() {
    ImGui::Begin("Controls");

    if (ImGui::Button("Reset")) {
        // Reset to original image
    }

    ImGui::End();
}