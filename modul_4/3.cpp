#include <iostream>
using namespace std;

int main() {
    float a, b, hasil;
    int pilih;

    cout << "Masukan Bilangan Pertama : ";
    cin >> a;
    cout << "Masukan Bilangan Kedua : ";
    cin >> b;

    cout << "\n--- Menu Kalkulator ---" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "Pilih menu [1/2/3] : ";
    cin >> pilih;

    if (pilih == 1) {
        hasil = a + b;
        cout << "Hasil penjumlahan " << a << " + " << b << " = " << hasil << endl;
    } else if (pilih == 2) {
        hasil = a - b;
        cout << "Hasil pengurangan " << a << " - " << b << " = " << hasil << endl;
    } else if (pilih == 3) {
        hasil = a * b;
        cout << "Hasil perkalian " << a << " * " << b << " = " << hasil << endl;
    } else {
        cout << "Pilihan menu tidak tersedia!" << endl;
    }

    return 0;
}
