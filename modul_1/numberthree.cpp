#include <iostream>
using namespace std;

int main() {
    int target_sks = 146;
    int total_sks;

    cout << "Masukkan total SKS yang sudah lulus: ";
    cin >> total_sks;

    if (total_sks >= target_sks) {
        cout << "Status: Selamat! SKS Anda sudah mencapai " << total_sks << ". Anda siap wisuda." << endl;
    } else {
        int kekurangan = target_sks - total_sks;
        cout << "Status: Belum memenuhi syarat." << endl;
        cout << "Anda masih kurang " << kekurangan << " SKS dan harus mengulang kuliah tahun depan." << endl;
    }

    return 0;
}