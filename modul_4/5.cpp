#include <iostream>
#include <string>
using namespace std;

int main() {
    string username, password;
    string userBenar = "admin";
    string passBenar = "12345";

    cout << "Masukan Username : ";
    cin >> username;
    cout << "Masukan Password : ";
    cin >> password;

    if (username == userBenar && password == passBenar) {
        cout << "Berhasil Login" << endl;
    } else if (username != userBenar && password != passBenar) {
        cout << "Username dan Password salah!" << endl;
    } else if (username != userBenar) {
        cout << "Username salah!" << endl;
    } else {
        cout << "Password salah!" << endl;
    }

    return 0;
}
