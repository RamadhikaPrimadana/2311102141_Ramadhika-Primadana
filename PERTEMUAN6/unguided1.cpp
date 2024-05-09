// LAPRAK 6 : UNGUIDED 1
// Ramadhika Primadana
// 2311102141
// S1 IF-11-D

// Program Stack untuk menentukan apakah kalimat tersebut Palindrom/tidak
#include <iostream>
#include <string> //library untuk menggunakan string
#include <stack> //library untuk menggunakan stack

using namespace std;

// Fungsi untuk membersihkan Kata_141 dari spasi dan karakter non-alphanumeric
string BersihkanKata_141 (string Kata_141) {
    string KataBersih_141;
    for (char & c_141 : Kata_141) {
        if (isalpha(c_141)) { // Memeriksa apakah karakter adalah huruf
            KataBersih_141 += tolower(c_141); // Mengubah huruf menjadi huruf kecil atau bersih
        }
    }
    return KataBersih_141;
}

// Fungsi untuk memeriksa apakah sebuah string adalah palindrom
bool Palindrom_141 (string Kata_141) {
    stack<char> TumpukkanKata_141;
    int Length_141 = Kata_141.length();

    // Memasukkan setengah karakter pertama ke dalam tumpukan
    for (int i_141 = 0; i_141 < Length_141 / 2; i_141++) {
        TumpukkanKata_141.push(Kata_141[i_141]);
    }

    // Menentukan titik awal untuk membandingkan karakter kedua setengah
    int Mulai_141 = Length_141 / 2;
    if (Length_141 % 2 != 0) {
        Mulai_141++;
    }

    // Membandingkan karakter kedua setengah dengan karakter dalam tumpukan
    for (int i_141 = Mulai_141; i_141 < Length_141; i_141++) {
        if (TumpukkanKata_141.empty() || Kata_141[i_141] != TumpukkanKata_141.top()) {
            return false;
        }
        TumpukkanKata_141.pop();
    }

    return true;
}

int main() {
    char LanjutkanInputKata_141;
    cout << "\n>>>> SELAMAT DATANG DI PROGRAM PALINDROM BY Ramadhika Primadana 2311102141 <<<<" << endl; // Judul Program

    do {
        // Memasukkan Kata_141 atau kalimat yang ingin dimasukkan
        string Kata_141;
        cout << "\n>> Masukkan kalimat : "; // User diminta untuk memasukan kata atau kalimat yang ingin dimasukkan
        getline(cin, Kata_141);

        // Membersihkan Kata_141 dari spasi, karakter non-alphanumeric, dan mengubah huruf menjadi huruf kecil
        string KataBersih_141 = BersihkanKata_141 (Kata_141);

        // Memeriksa apakah Kata_141 adalah palindrom setelah dibersihkan
        if (Palindrom_141 (KataBersih_141)) {
            cout << "== Kalimat tersebut adalah : Palindrom" << endl; // Hasil yang berarti kata atau kalimat tersebut Palindrom
        } else {
            cout << "== Kalimat tersebut adalah : Bukan Palindrom" << endl; // Hasil yang berarti kata atau kalimat tersebut Bukan Palindrom
        }

        cout << "[2141] Apakah Anda ingin mencoba kalimat lain? (y/n) : "; // Menanyakan Kepada user apakah ingin mencoba kalimat lain atau tidak
        cin >> LanjutkanInputKata_141;
        cin.ignore(); // Untuk membersihkan buffer Kata_141 sebelumnya
    } while (LanjutkanInputKata_141 == 'y' || LanjutkanInputKata_141 == 'Y'); // Untuk melanjutkan input kata atau selesai

    return 0;
}
