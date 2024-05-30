// LAPRAK 8 : UNGUIDED 3
// Ramadhika Primadana
// 2311102141
// S1 IF-11-D

// Program Algoritma Sequential Search
#include <iostream>

using namespace std;

int main(){
    int n_141 = 10; // Jumlah elemen dalam array, yang berarti 10
    int Data_141[n_141] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Array data yang akan dicari
    int Target_141 = 4; // Target yang akan dicari dalam array
    int Count_141 = 0; // Variabel untuk menghitung banyaknya kemunculan target dalam array

    // Melakukan pencarian sequential untuk menghitung banyaknya angka 4 dalam array
    for (int i_141 = 0; i_141 < n_141; i_141++) {
        if (Data_141[i_141] == Target_141) {
            Count_141++; // Jika angka target ditemukan, tambahkan 1 ke variabel Count_141
        }
    }

    // Menampilkan hasil pencarian
    cout << "\n======= SELAMAT DATANG DI PROGRAM SEQUENTIAL SEARCH BY Ramadhika Primadana =======" << endl; // Judul Program
    cout << "\n>> Data : {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl; // Menampilkan data yang akan dicari
    cout << "[2141] Angka " << Target_141 << " ditemukan sebanyak " << Count_141 << " kali." << endl; // Menampilkan hasil pencarian

    return 0; // Mengembalikan nilai 0 menandakan bahwa program berakhir dengan sukses
}
