#include <iostream>
using namespace std;


int main() {
    int a;
    int b;
    cout << "Masukan nomor yang tidak lebih kecil dari nomer 5 : ";
    cin >> a;
    cout << "Masuka  nomor yang tidak lebih kecil dari nomer 8 : ";
    cin >> b; 
    int incorrect = (a<5) && (b<8);

    if (incorrect) { 
        cout << "Syarat Tidak Terpenuhi" << endl;
    } else {
        cout << "Syarat Terpenuhi" << endl;
        
    }
}