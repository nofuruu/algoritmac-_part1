#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <GLFW/glfw3.h> // Library untuk membuat jendela

// Fungsi wajib untuk menangkap error GLFW
static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char**) {
    // 1. Setup Jendela GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(500, 450, "Program Hitung Gaji - Dear ImGui", nullptr, nullptr);
    if (window == nullptr) return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Aktifkan V-Sync

    // 2. Setup Context Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark(); // Gunakan tema gelap (seperti DearPyGui)
    
    // Inisialisasi Backend ImGui
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // --- VARIABEL LOGIKA KITA ---
    // Di ImGui, kita cukup mendefinisikan variabel C++ biasa!
    int gaji_harian = 150000;
    bool kehadiran[7] = {false, false, false, false, false, false, false};
    const char* hari[7] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};

    // 3. Main Loop (Berjalan selama jendela belum ditutup)
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Mulai menggambar frame UI baru
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // --- MULAI DESAIN ANTARMUKA ---
        ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(460, 380), ImGuiCond_FirstUseEver);
        ImGui::Begin("Kalkulator Gaji", nullptr, ImGuiWindowFlags_NoCollapse);

        // Input Gaji (Otomatis mengubah variabel gaji_harian)
        ImGui::Text("Masukkan Gaji per Hari (Rp):");
        ImGui::InputInt("##gaji", &gaji_harian); 
        ImGui::Spacing(); ImGui::Separator(); ImGui::Spacing();

        ImGui::Text("Ceklis Hari Kehadiran:");
        
        // Membuat Tabel
        if (ImGui::BeginTable("TabelHari", 2, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
            ImGui::TableSetupColumn("Hari Kerja");
            ImGui::TableSetupColumn("Status Hadir", ImGuiTableColumnFlags_WidthFixed, 100.0f);
            ImGui::TableHeadersRow();

            for (int i = 0; i < 7; i++) {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("%s", hari[i]);
                
                ImGui::TableNextColumn();
                ImGui::PushID(i); // Agar setiap checkbox punya ID unik
                // Checkbox ini langsung mengubah nilai array 'kehadiran[i]'
                ImGui::Checkbox("##hadir", &kehadiran[i]); 
                ImGui::PopID();
            }
            ImGui::EndTable();
        }

        ImGui::Spacing(); ImGui::Separator(); ImGui::Spacing();

        // --- KALKULASI HASIL LANGSUNG ---
        int hari_masuk = 0;
        for(int i = 0; i < 7; i++) {
            if(kehadiran[i]) hari_masuk++;
        }
        int total_gaji = hari_masuk * gaji_harian;
        
        // Menampilkan Hasil (Menggunakan warna teks hijau)
        ImGui::TextColored(ImVec4(0.2f, 1.0f, 0.2f, 1.0f), "Total Hari Masuk : %d hari", hari_masuk);
        ImGui::TextColored(ImVec4(0.2f, 1.0f, 0.2f, 1.0f), "Total Gaji       : Rp %d", total_gaji);

        ImGui::End();
        // --- SELESAI DESAIN ANTARMUKA ---

        // Proses Render ke Layar
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.15f, 0.15f, 0.15f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // 4. Bersihkan memori saat program ditutup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}