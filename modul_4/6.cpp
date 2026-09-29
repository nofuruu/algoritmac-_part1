#include <iostream>
using namespace std;

int main() {
    float total, bayar;

    cout << "Masukan Total Pembelian : ";
    cin >> total;

    // Jawaban: Tidak tepat jika memakai switch-case murni (tanpa if).
    // Alasan: switch-case hanya mencocokkan SATU nilai pasti (kesetaraan)
    // dengan label case yang harus konstanta integer/enum.
    // Sedangkan soal no.4 memakai kriteria RENTANG nilai:
    //  > 100000, 50000-100000, 10000-50000, < 10000
    // yang jumlah kemungkinannya tidak terbatas sehingga tidak bisa
    // ditulis sebagai case 1, case 2, ... secara murni.
    //
    // Cara memaksa: memakai switch(true) atau mengubah rentang menjadi
    // kategori integer dulu, tetapi itu sebenarnya meniru if-else
    // (case berisi ekspresi boolean) dan tidak murni switch-case.
    // Jadi solusi yang tepat untuk soal no.4 adalah if-else.

    cout << endl;
    cout << "Jawaban: Tidak dapat dipecahkan dengan switch-case murni." << endl;
    cout << "Alasan: switch-case untuk pencocokan nilai pasti, sedangkan" << endl;
    cout << "soal no.4 memakai rentang nilai sehingga tepat memakai if-else." << endl;
    cout << endl;

    // Demonstrasi logika yang benar tetap memakai if-else
    // (seperti program no.4), karena switch-case murni tidak mampu:
    if (total > 100000) {
        bayar = total - (total * 0.10);
        cout << "Mendapatkan diskon sebesar 10%" << endl;
        cout << "Total bayar : " << bayar << endl;
    } else if (total > 50000) {
        cout << "Mendapatkan bonus sebuah piring cantik" << endl;
    } else if (total > 10000) {
        cout << "Mendapatkan bonus sebuah gelas cantik" << endl;
    } else {
        cout << "Tidak mendapatkan bonus" << endl;
    }

    return 0;
}
