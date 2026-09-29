#!/bin/bash
# Run ringan GUI Kalkulator Modul 4 No.7 (Dear ImGui)
# Pakai: ./run_gui.sh [--build-only]
set -e
cd "$(dirname "$0")"

OUT="kalkulator_gui"

echo "[1/2] Build $OUT..."
g++ 7.cpp \
  ../modul_3/imgui/imgui.cpp \
  ../modul_3/imgui/imgui_draw.cpp \
  ../modul_3/imgui/imgui_tables.cpp \
  ../modul_3/imgui/imgui_widgets.cpp \
  ../modul_3/imgui/backends/imgui_impl_glfw.cpp \
  ../modul_3/imgui/backends/imgui_impl_opengl3.cpp \
  -I../modul_3/imgui -I../modul_3/imgui/backends \
  -lglfw -lGL -o "$OUT"
echo "Build OK: ./$OUT"

if [ "$1" = "--build-only" ]; then
  exit 0
fi

echo "[2/2] Run $OUT..."
./"$OUT"
