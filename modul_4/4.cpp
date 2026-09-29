#include <iostream>
using namespace std;

int main() {
    float total, bayar;

    cout << "Masukan Total Pembelian : ";
    cin >> total;

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
