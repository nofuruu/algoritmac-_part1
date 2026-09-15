#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstring>

int main() {
    if (!glfwInit()) {
        std::cerr << "Gagal menginisialisasi GLFW\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(900, 550, "Input Identitas Mahasiswa", NULL, NULL);
    if (!window) {
        std::cerr << "Gagal membuat jendela utama\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    char tempNama[128] = "";
    char tempNim[64] = "";
    char tempProdi[128] = "";

    char finalNama[128] = "-";
    char finalNim[64] = "-";
    char finalProdi[128] = "-";

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowSize(ImVec2(550, 350), ImGuiCond_FirstUseEver);
        ImGui::Begin("Form Input Mahasiswa", NULL, ImGuiWindowFlags_NoCollapse);

        ImGui::TextColored(ImVec4(0.1f, 0.8f, 0.6f, 1.0f), "=== INPUT DATA MAHASISWA ===");
        ImGui::Separator();
        ImGui::Spacing();

        ImGui::InputText("Nama", tempNama, IM_ARRAYSIZE(tempNama));
        ImGui::InputText("NIM", tempNim, IM_ARRAYSIZE(tempNim));
        ImGui::InputText("Prodi", tempProdi, IM_ARRAYSIZE(tempProdi));

        ImGui::Spacing();
        
        // Tombol "Enter" (Submit) pada GUI
        if (ImGui::Button("Enter", ImVec2(120, 30))) {
            strcpy(finalNama, tempNama[0] != '\0' ? tempNama : "-");
            strcpy(finalNim, tempNim[0] != '\0' ? tempNim : "-");
            strcpy(finalProdi, tempProdi[0] != '\0' ? tempProdi : "-");
        }

        ImGui::Spacing();
        ImGui::Separator();
        ImGui::TextColored(ImVec4(0.9f, 0.7f, 0.1f, 1.0f), "=== HASIL TAMPILAN DATA ===");
        
        ImGui::Text("Nama  : %s", finalNama);
        ImGui::Text("NIM   : %s", finalNim);
        ImGui::Text("Prodi : %s", finalProdi);

        ImGui::Spacing();
        ImGui::Separator();

        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        
        glClearColor(0.08f, 0.08f, 0.09f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}