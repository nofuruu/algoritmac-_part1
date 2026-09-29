#include <iostream>
using namespace std;

int main() {
  int a;
  int b;
  int c;

  cout << "Masukan Bilangan Pertama  : ";
  cin >> a;
  cout << "Masukan Bilangan Kedua  : ";
  cin >> b;
  cout << "Masukan Bilangan Ketiga  : ";
  cin >> c;

  if (a > b) {
    if (a > c) {
      cout << "Input Bilangan pertama adalah : " << a
           << "\nLebih besar daripada input kedua dan ketiga" << endl;
    } else {
      cout << "Input Bilangan ketiga adalah : " << c
           << "\nLebih besar daripada input pertama dan kedua" << endl;
    }
  } else {
    if (b > c) {
      cout << "Input Bilangan kedua adalah : " << b
           << "\nLebih besar daripada input pertama dan ketiga" << endl;
    } else {
      cout << "Input Bilangan ketiga adalah : " << c
           << "\nLebih besar daripada input pertama dan kedua" << endl;
    }
  }

  return 0;
}