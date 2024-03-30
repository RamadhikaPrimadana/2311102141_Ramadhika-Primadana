// LAPRAK 1 : UNGUIDED 3
// RAMADHIKA PRIMADANA
// 2311102141
// S1 IF-11-D

#include <iostream>
#include <map>

using namespace std;

// Struktur data untuk menyimpan informasi pemain sepak bola
struct PemainSepakBola {
    string nama_141;
    string klub_141;
};

int main() {
    // Deklarasi map dengan key int dan value berupa objek PemainSepakBola
    map<int, PemainSepakBola> club_141;

    // Menambahkan data pemain sepak bola ke dalam map
    club_141[1] = {"Cristiano Ronaldo", "Al-Nassr FC"};
    club_141[2] = {"Muhammad Salah", "Liverpool"};
    club_141[3] = {"Neymar Junior", "Al-Hilal FC"};
    club_141[4] = {"Kylian Mbappe", "Paris Saint-Germain FC"}; 
    club_141[5] = {"Mohamed Salah", "Liverpool FC"};

    cout << "TOP SKOR PEMAIN SEPAK BOLA DUNIA" << endl;

    // Perulangan for menggunakan range-based for loop
    for (int i = 1; i <= club_141.size(); ++i) {
        cout << "Nomor " << i << "  Atas Nama: " << club_141[i].nama_141 << ",  Bermain di: " << club_141[i].klub_141 << endl;
    }

    return 0;
}
