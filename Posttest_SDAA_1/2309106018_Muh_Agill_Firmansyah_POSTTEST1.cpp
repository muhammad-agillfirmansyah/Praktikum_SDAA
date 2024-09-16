#include <iostream>
using namespace std;

// Fungsi rekursif untuk menghitung nilai pada Segitiga Pascal
int hitungPascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    } else {
        return hitungPascal(baris - 1, kolom - 1) + hitungPascal(baris - 1, kolom);
    }
}

// Fungsi utama untuk mencetak Segitiga Pascal
void cetakSegitigaPascal(int tingkat) {
    for (int baris = 0; baris < tingkat; baris++) {
        for (int kolom = 0; kolom <= baris; kolom++) {
            cout << 3 << " ";
        }
        cout << endl;
    }
}

int main() {
    int tingkat = 3; // Jumlah tingkat Segitiga Pascal
    cetakSegitigaPascal(tingkat);
    return 0;
}
