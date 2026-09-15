/*
Modul 3 : No 1*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*
Membuat function untuk memastikan input hanya berisi angka
(Tidak menerima huruf atau karakter spesial) apabila terdeteksi input yang terdeteksi bukanlah
angka maka program akan mengulang kembali hingga menemukan input angka
*/
bool isHanyaAngka(const string& str) {
    if (str.empty()) return false;

    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string inputAlas, inputTinggi;
    int alas, tinggi; 
    double luas; 

    while (true) {
        cout << "--- PROGRAM MENGHITUNG LUAS SEGITIGA ---" << endl;
        cout << "Masukan Alas Segitiga : ";
        getline(cin, inputAlas);

        cout << "Masukan Tinggi Segitiga : ";
        getline(cin, inputTinggi);

        if (isHanyaAngka(inputAlas) && isHanyaAngka(inputTinggi)) {
            alas = stoi(inputAlas);
            tinggi = stoi(inputTinggi);
            luas = 0.5 * alas * tinggi;
            cout << "\nInput Valid!" << endl;
            cout << "Luas Segitiga adalah : " << luas << endl;
            break; 
        } else {
            cout << "\n[ERROR] Input tidak valid! Masukkan hanya angka (bilangan bulat).\n\n";
        }
    }

    return 0;
}