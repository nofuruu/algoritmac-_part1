#include <iostream>
#include <string>
using namespace std;

int main() {
    string namaFilm = "Avengers: Doomsday";
    int hargaTiket = 50000;
    int jumlahBeli = 3;
    int totalHarga;
    int uangBayar = 200000;
    int kembalian;

    totalHarga = hargaTiket * jumlahBeli;
    kembalian = uangBayar - totalHarga;

    cout << "=== STRUK PEMBELIAN TIKET BIOSKOP ===" << endl;
    cout << "Film        : " << namaFilm << endl;
    cout << "Harga Satuan: Rp " << hargaTiket << endl;
    cout << "Jumlah Beli : " << jumlahBeli << " tiket" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Total Bayar : Rp " << totalHarga << endl;
    cout << "Uang Tunai  : Rp " << uangBayar << endl;
    cout << "Kembalian   : Rp " << kembalian << endl;
    cout << "===================================" << endl;

    return 0;
}