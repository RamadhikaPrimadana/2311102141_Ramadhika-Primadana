// LAPRAK 6 : UNGUIDED 2
// Ramadhika Primadana
// 2311102141
// S1 IF-11-D

// Program Stack untuk melakukan pembalikan terhadap kalimat
#include <iostream>
#include <string> //library untuk menggunakan string
#include <stack>  //library untuk struktur data stack

using namespace std;

int main() {
    stack<char> CharStack_141;      // Inisialisasi stack untuk menyimpan karakter
    char LanjutkanInputKalimat_141; // Untuk melanjutkan input kalimat
    cout << "\n>>>> SELAMAT DATANG DI PROGRAM PEMBALIKAN KALIMAT BY Ramadhika Primadana 2311102141 <<<<" << endl; // Judul Program

    do {
        string Kalimat_141, KalimatDibalik_141;
        cout << "\n>> Masukkan kalimat minimal 3 kata : "; // User diminta untuk memasukan kalimat yang ingin dimasukkan, dengan minimal 3 kata
        getline(cin, Kalimat_141);  // Membaca input Kalimat_141 dari pengguna

        for (char c_141 : Kalimat_141) {
            CharStack_141.push(c_141); // Menambahkan setiap karakter ke dalam stack
        }

        while (!CharStack_141.empty()) { // Untuk memeriksa apakah stack tersebut kosong atau tidak
            if (CharStack_141.top() == ' ') {
                KalimatDibalik_141 += ' '; // Menambahkan spasi ke Kalimat_141 terbalik jika karakter teratas adalah spasi
            } else {
                KalimatDibalik_141 += CharStack_141.top(); // Menambahkan karakter teratas dari stack ke Kalimat_141 terbalik
            }
            CharStack_141.pop(); // Menghapus karakter teratas dari stack
        }

        cout << "== Hasil kalimat yang dibalikkan : " << KalimatDibalik_141 << endl; // Hasil kalimat yang dibalikan

        cout << "[2141] Apakah Anda ingin mencoba kalimat lain? (y/n) : "; // Menanyakan Kepada user apakah ingin mencoba kalimat lain atau tidak
        cin >> LanjutkanInputKalimat_141;
        cin.ignore(); // Untuk membersihkan Kalimat_141 buffer sebelumnya
    } while (LanjutkanInputKalimat_141 == 'y' || LanjutkanInputKalimat_141 == 'Y'); // Untuk melanjutkan input Kalimat_141 atau selesai

    return 0;
}
