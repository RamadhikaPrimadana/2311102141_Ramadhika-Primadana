// LAPRAK 9 : UNGUIDED 1
// RAMADHIKA PRIMADANA
// 2311102141
// S1 IF-11-D

// Program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya
#include <iostream> // Library untuk operasi input dan output
#include <vector>   // Library untuk penggunaan kontainer vector
#include <string>   // Library untuk penggunaan tipe data string

using namespace std; // Menggunakan namespace std untuk mempermudah penulisan kode

int main() {
    int JumlahSimpul_2311102141; // Deklarasi variabel untuk menyimpan jumlah simpul

    // Menampilkan judul program
    cout << "\n>>>>>>> Program graph menghitung jarak dari sebuah kota By Ramadhika Primadana <<<<<<<" << endl;
    // Meminta pengguna memasukkan jumlah simpul
    cout << "\nSilakan masukan jumlah simpul : ";
    cin >> JumlahSimpul_2311102141; // Membaca input jumlah simpul dari pengguna

    // Mendeklarasikan vektor untuk menyimpan nama-nama simpul
    vector<string> NamaSimpul_2311102141(JumlahSimpul_2311102141);
    // Mendeklarasikan matriks untuk menyimpan bobot (jarak) antar simpul
    vector<vector<int>> bobot_2311102141(JumlahSimpul_2311102141, vector<int>(JumlahSimpul_2311102141));

    // Meminta pengguna memasukkan nama-nama simpul
    cout << "Silakan masukan nama simpul" << endl;
    for (int i_2311102141 = 0; i_2311102141 < JumlahSimpul_2311102141; ++i_2311102141) {
        // Meminta input nama simpul dari pengguna
        cout << "Simpul " << i_2311102141 + 1 << " : ";
        cin >> NamaSimpul_2311102141[i_2311102141]; // Membaca input nama simpul dan menyimpannya ke dalam vektor
    }

    // Meminta pengguna memasukkan bobot antar simpul
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i_2311102141 = 0; i_2311102141 < JumlahSimpul_2311102141; ++i_2311102141) {
        for (int j_2311102141 = 0; j_2311102141 < JumlahSimpul_2311102141; ++j_2311102141) {
            // Meminta input bobot (jarak) dari simpul i ke simpul j
            cout << NamaSimpul_2311102141[i_2311102141] << "--> " << NamaSimpul_2311102141[j_2311102141] << " = ";
            cin >> bobot_2311102141[i_2311102141][j_2311102141]; // Membaca input bobot dan menyimpannya ke dalam matriks
        }
    }

    cout << endl; // Menambahkan baris baru untuk tampilan yang lebih rapi

    // Menampilkan tabel jarak antar simpul
    cout << "     "; // Menambahkan spasi untuk perataan tabel
    for (const string& Nama_2311102141 : NamaSimpul_2311102141) {
        cout << Nama_2311102141 << "  "; // Menampilkan nama-nama simpul sebagai header kolom
    }
    cout << endl;

    for (int i_2311102141 = 0; i_2311102141 < JumlahSimpul_2311102141; ++i_2311102141) {
        cout << NamaSimpul_2311102141[i_2311102141] << "     "; // Menampilkan nama simpul sebagai header baris
        for (int j_2311102141 = 0; j_2311102141 < JumlahSimpul_2311102141; ++j_2311102141) {
            cout << bobot_2311102141[i_2311102141][j_2311102141] << "  "; // Menampilkan bobot (jarak) antar simpul
        }
        cout << endl;
    }

    return 0; // Mengembalikan nilai 0 untuk menandakan program berakhir dengan sukses
}
