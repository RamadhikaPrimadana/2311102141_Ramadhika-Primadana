// LAPRAK 8 : UNGUIDED 1
// RAMADHIKA PRIMADANA
// 2311102141
// S1 IF-11-D

// Program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search
#include <iostream>
#include <conio.h>  // Jika menggunakan Windows. Untuk sistem operasi lain, perlu mencari pengganti dari _getche()

using namespace std;

// Fungsi untuk melakukan pencarian binary pada array karakter
int binarySearch_141(char Array_141[], int Size_141, char Target_141) {
    int Kiri_141 = 0;
    int Kanan_141 = Size_141 - 1;

    // Melakukan binary search selama Kiri_141 tidak melebihi Kanan_141
    while (Kiri_141 <= Kanan_141) {
        int Tengah_141 = Kiri_141 + (Kanan_141 - Kiri_141) / 2;

        // Jika huruf Target_141 berada di tengah array
        if (Array_141[Tengah_141] == Target_141)
            return Tengah_141;

        // Jika huruf Target_141 berada di sebelah kiri tengah array
        if (Array_141[Tengah_141] > Target_141)
            Kanan_141 = Tengah_141 - 1;

        // Jika huruf Target_141 berada di sebelah kanan tengah array
        else
            Kiri_141 = Tengah_141 + 1;
    }

    // Jika huruf Target_141 tidak ditemukan
    return -1;
}

// Fungsi untuk melakukan selection sort pada array karakter
void selectionSort_141(char Array_141[], int Size_141) {
    for (int i_141 = 0; i_141 < Size_141 - 1; ++i_141) {
        int IndeksTengah_141 = i_141;
        for (int j_141 = i_141 + 1; j_141 < Size_141; ++j_141) {
            // Menemukan elemen terkecil dalam array yang belum diurutkan
            if (Array_141[j_141] < Array_141[IndeksTengah_141]) {
                IndeksTengah_141 = j_141;
            }
        }
        // Menukar elemen terkecil yang ditemukan dengan elemen pertama yang belum diurutkan
        swap(Array_141[i_141], Array_141[IndeksTengah_141]);
    }
}

int main() {
    string sentence_141; // Variabel untuk menyimpan kalimat yang dimasukkan oleh pengguna
    char Target_141; // Variabel untuk menyimpan karakter yang akan dicari

    cout << "\n======= SELAMAT DATANG DI PROGRAM BINARY SEARCH BY RAMADHIKA PRIMADANA =======" << endl; // Judul Program
    cout << "\n>> Masukkan kalimat : ";
    getline(cin, sentence_141); // Mengambil input kalimat dari pengguna

    // Membuat array untuk menyimpan karakter
    int PanjangSentence_141 = sentence_141.size(); // Menghitung panjang kalimat
    char KarakterArray_141 [100]; // Array untuk menyimpan karakter-karakter dari kalimat (mengabaikan spasi)
    int Size_141 = 0; // Variabel untuk melacak jumlah karakter non-spasi

    // Mengisi KarakterArray_141  dengan karakter-karakter dari kalimat
    for (int i_141 = 0; i_141 < PanjangSentence_141; ++i_141) {
        if (sentence_141[i_141] != ' ') {  // Mengabaikan spasi
            KarakterArray_141 [Size_141] = sentence_141[i_141]; // Menyimpan karakter ke KarakterArray_141 
            ++Size_141; // Menambah ukuran dari array yang telah diisi
        }
    }

    cout << ">> Masukkan huruf yang ingin dicari : ";
    cin >> Target_141;

    // Mengurutkan array karakter menggunakan selection sort
    selectionSort_141(KarakterArray_141 , Size_141);

    // Menampilkan daftar huruf yang sudah diurutkan sesuai abjad
    cout << "== Daftar huruf yang sudah diurutkan sesuai abjad : ";
    for (int i_141 = 0; i_141 < Size_141; ++i_141) {
        cout << KarakterArray_141 [i_141] << " ";
    }

    // Mencari huruf dalam array yang telah diurutkan
    int Index_141 = binarySearch_141(KarakterArray_141 , Size_141, Target_141);

    cout << endl;

    // Menampilkan hasil pencarian dan daftar huruf yang sudah diurutkan
    if (Index_141 != -1) {
        cout << "[2138] Huruf '" << Target_141 << "' ditemukan pada urutan ke-" << Index_141 << " dalam urutan abjad." << endl;
    } else {
        cout << "[2138] Huruf '" << Target_141 << "' tidak ditemukan dalam kalimat." << endl;
    }

    _getche();  // Menunggu pengguna menekan tombol sebelum program berakhir (hanya untuk Windows)
    return 0; // Mengembalikan nilai 0 menandakan bahwa program berakhir dengan sukses
}
