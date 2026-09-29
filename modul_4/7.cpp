// =====================================================================
// Modul 4 No.7 - Kalkulator GUI (Dear ImGui)
// ---------------------------------------------------------------------
// PENJELASAN (jawaban teori):
// Pada program kalkulator console (No.3) yang memakai "cin >> a >> b",
// jika input bukan angka (huruf/simbol), maka:
//  1. operator>> GAGAL mencocokkan tipe (expect float, dapat char),
//  2. stream masuk ke failbit, variabel 'a'/'b' TIDAK terisi nilai baru
//     (tetap 0 / nilai sampah), karakter salah TERTINGGAL di buffer,
//  3. semua cin berikutnya langsung gagal tanpa menunggu ketikan baru,
//     sehingga pilihan menu terbaca ngawur (biasanya 0) dan program
//     mencetak hasil salah / "menu tidak tersedia".
// Solusi console: cek cin.fail(), lalu cin.clear() + cin.ignore().
// Solusi GUI di bawah: validasi string SEBELUM dihitung, input salah
// ditolak secara visual tanpa merusak stream.
//
// KENAPA Dear ImGui (ringan & worth it, tanpa setting ribet):
//  - Sudah di-vendor di repo (modul_3/imgui), tinggal -I, tanpa install Qt/wx.
//  - Immediate-mode: cukup InputText + Button + Text, tanpa designer/ signal-slot.
//  - Cukup link glfw + opengl yang sudah tersedia.
// CARA COMPILE dari folder modul_4:
//  g++ 7.cpp ../modul_3/imgui/imgui.cpp ../modul_3/imgui/imgui_draw.cpp \
//    ../modul_3/imgui/imgui_tables.cpp ../modul_3/imgui/imgui_widgets.cpp \
//    ../modul_3/imgui/backends/imgui_impl_glfw.cpp \
//    ../modul_3/imgui/backends/imgui_impl_opengl3.cpp \
//    -I../modul_3/imgui -I../modul_3/imgui/backends -lglfw -lGL -o kalkulator_gui
// =====================================================================
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* description) {
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Validasi string angka: boleh spasi depan/belakang, satu minus di depan,
// satu titik desimal. Menolak huruf & simbol lain.
static bool tryParseAngka(const char* s, float& out) {
    if (s == nullptr || s[0] == '\0') return false;
    // lewati spasi depan
    while (isspace((unsigned char)*s)) s++;
    if (*s == '\0') return false;

    char* end = nullptr;
    out = strtof(s, &end);
    if (end == s) return false; // tidak ada konversi sama sekali
    while (isspace((unsigned char)*end)) end++;
    return *end == '\0'; // harus habis termakan, sisa huruf = invalid
}

int main(int, char**) {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(520, 480, "Kalkulator Modul 4 - Dear ImGui", nullptr, nullptr);
    if (window == nullptr) return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // --- State kalkulator ---
    static char bufA[64] = "";
    static char bufB[64] = "";
    static int operasi = 1; // 1=tambah, 2=kurang, 3=kali
    static char pesan[128] = "Masukkan dua bilangan lalu tekan Hitung.";
    static ImVec4 warnaPesan = ImVec4(0.7f, 0.7f, 0.7f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(480, 430), ImGuiCond_FirstUseEver);
        ImGui::Begin("Kalkulator (Pengganti No.3)", nullptr, ImGuiWindowFlags_NoCollapse);

        ImGui::Text("Bilangan Pertama:");
        ImGui::InputTextWithHint("##a", "cth: 12.5", bufA, sizeof(bufA), ImGuiInputTextFlags_CharsDecimal);

        ImGui::Text("Bilangan Kedua:");
        ImGui::InputTextWithHint("##b", "cth: 3", bufB, sizeof(bufB), ImGuiInputTextFlags_CharsDecimal);

        ImGui::Spacing(); ImGui::Separator(); ImGui::Spacing();

        ImGui::Text("Pilih Operasi:");
        ImGui::RadioButton("1. Penjumlahan (+)", &operasi, 1);
        ImGui::RadioButton("2. Pengurangan (-)", &operasi, 2);
        ImGui::RadioButton("3. Perkalian (*)", &operasi, 3);

        ImGui::Spacing();
        if (ImGui::Button("Hitung", ImVec2(120, 0))) {
            float a = 0, b = 0;
            bool okA = tryParseAngka(bufA, a);
            bool okB = tryParseAngka(bufB, b);
            if (!okA && !okB) {
                snprintf(pesan, sizeof(pesan), "Error: kedua input bukan angka valid!");
                warnaPesan = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);
            } else if (!okA) {
                snprintf(pesan, sizeof(pesan), "Error: bilangan pertama bukan angka!");
                warnaPesan = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);
            } else if (!okB) {
                snprintf(pesan, sizeof(pesan), "Error: bilangan kedua bukan angka!");
                warnaPesan = ImVec4(1.0f, 0.3f, 0.3f, 1.0f);
            } else {
                float hasil = 0;
                const char* op = "+";
                if (operasi == 1) { hasil = a + b; op = "+"; }
                else if (operasi == 2) { hasil = a - b; op = "-"; }
                else { hasil = a * b; op = "*"; }
                snprintf(pesan, sizeof(pesan), "Hasil: %g %s %g = %g", a, op, b, hasil);
                warnaPesan = ImVec4(0.2f, 1.0f, 0.2f, 1.0f);
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Bersihkan", ImVec2(120, 0))) {
            bufA[0] = '\0'; bufB[0] = '\0';
            snprintf(pesan, sizeof(pesan), "Masukkan dua bilangan lalu tekan Hitung.");
            warnaPesan = ImVec4(0.7f, 0.7f, 0.7f, 1.0f);
        }

        ImGui::Spacing(); ImGui::Separator(); ImGui::Spacing();
        ImGui::TextColored(warnaPesan, "%s", pesan);

        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Kenapa input huruf merusak versi console?")) {
            ImGui::TextWrapped("cin >> float mengharapkan digit. Huruf/simbol membuat "
                "operator>> gagal, failbit aktif, variabel tidak terisi, sisa karakter "
                "menumpuk di buffer sehingga menu ikut gagal terbaca. GUI ini aman "
                "karena validasi string dulu (tryParseAngka) sebelum dihitung.");
        }

        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.15f, 0.15f, 0.15f, 1.00f);
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
