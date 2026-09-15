#include <iostream>
#include <string>
using namespace std;


int main() {
    string nama;
    int uts;
    int uas;
    int counterData = 0;

    int parameterNilai[3] = {60, 75, 85};
    string parameterPredikat[3] = {
        "Tidak Lulus",
        "Lulus Dengan Predikat Baik",
        "Lulus Dengan Predikat Sangat Baik"
    };

    cout << "Tugas Modul 3 : Nomor 3" << endl;
    cout << "================================" << endl;
    cout << "PROGRAM EVALUASI NILAI MAHASISWA" << endl;
    cout << "________________________________" << endl;

    cout << "Masukan Nama : ";
    cin >> ws;
    getline(cin, nama);

    cout << "Masukan Nilai UTS : ";
    cin >> uts;

    cout << "Masukan Nilai UAS : ";
    cin >> uas;

    counterData++;

    double nilaiAkhir = (uts * 0.4) + (uas * 0.6);

    int index = 0;
    if (nilaiAkhir >= parameterNilai[2]){
        index = 2;
    } else if (nilaiAkhir >= parameterNilai[1]){
        index = 1;
    } else {
        index = 0;
    }

    cout << "Nilai Hasil Nilai Evaluasi Mahasiswa" << endl;
    cout << "Nama Mahasiswa     : " << nama << endl;
    cout << "Nilai Uts          : " << uts << endl;
    cout << "Nilai Uas          : " << uas << endl;
    cout << "Nilai Akhir        : " << nilaiAkhir << endl;
    cout << "Status Peniliaian  : " << parameterPredikat[index] << endl;

    return 0;



}