// LAPRAK 8 : UNGUIDED 2
// RAMADHIKA PRIMADANA
// 2311102141
// S1 IF-11-D

// Program menghitung banyaknya huruf vocal dalam sebuah kalimat menggunakan Sequential Search
#include <iostream>
#include <cctype> // Untuk fungsi tolower

using namespace std;

// Fungsi untuk memeriksa apakah sebuah karakter adalah vocal
bool isVowel_141(char Karakter_141) {
    // Konversi karakter menjadi huruf kecil agar pemeriksaan tidak case-sensitive
    Karakter_141 = tolower(Karakter_141);
    // Periksa apakah karakter adalah salah satu dari 'a', 'e', 'i', 'o', 'u'
    return (Karakter_141 == 'a' || Karakter_141 == 'e' || Karakter_141 == 'i' || Karakter_141 == 'o' || Karakter_141 == 'u');
}

// Fungsi untuk menghitung banyaknya huruf vocal dalam sebuah kalimat
int countVowels_141(const string &Kalimat_141) {
    int Count_141 = 0; // Variabel untuk menghitung jumlah vocal
    // Loop melalui setiap karakter dalam string Kalimat_141
    for (char Karakter_141 : Kalimat_141) {
        // Periksa apakah karakter adalah vocal menggunakan fungsi isVowel_141
        if (isVowel_141(Karakter_141)) {
            Count_141++; // Tambahkan ke Count_141 jika karakter adalah vocal
        }
    }
    return Count_141; // Kembalikan jumlah vocal
}

int main() {
    string Kalimat_141; // Variabel untuk menyimpan kalimat yang dimasukkan oleh pengguna

    cout << "\n======= SELAMAT DATANG DI PROGRAM MENCARI KALIMAT VOCAL BY RAMADHIKA PRIMADANA =======" << endl; // Nama Program
    cout << "\n>> Masukkan sebuah kalimat : ";
    getline(cin, Kalimat_141); // Membaca input kalimat dari pengguna

    // Menghitung jumlah huruf vocal dalam kalimat menggunakan fungsi countVowels_141
    int vowelCount_141 = countVowels_141(Kalimat_141);

    // Menampilkan hasil perhitungan jumlah huruf vocal
    cout << "[2138] Banyaknya huruf vocal dalam kalimat adalah : " << vowelCount_141 << endl;

    return 0; // Mengembalikan nilai 0 menandakan bahwa program berakhir dengan sukses
}
