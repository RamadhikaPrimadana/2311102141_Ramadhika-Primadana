// LAPRAK 1 : UNGUIDED 1
// RAMADHIKA PRIMADANA
// 2311102141
// S1 IF-11-D
#include <iostream>

using namespace std;

// Fungsi untuk menampilkan menu cafe
void TampilkanMenu() {
    cout << "===  NONGSKUY  ===" <<endl;
    cout << "1. Kopi          : Rp. 15,000" << endl;
    cout << "2. Teh           : Rp. 10,000" << endl;
    cout << "3. Sandwich      : Rp. 20,000" << endl;
    cout << "4. Nasi Goreng   : Rp. 25,000" << endl;
    cout << "5. Es Teh Manis  : Rp. 12,000" << endl;
    cout << "=================" << endl;
}

// Fungsi untuk menghitung total biaya pesanan
float HitungTotal(int pilihan, int jumlah) {
    float harga = 0;

    switch (pilihan) {
        case 1:
            harga = 15000;
            break;
        case 2:
            harga = 10000;
            break;
        case 3:
            harga = 20000;
            break;
        case 4:
            harga = 25000;
            break;
        case 5:
            harga = 12000;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    return harga * jumlah;
}

int main() {
    int pilihan;
    int jumlah;

    // Menampilkan menu cafe
    TampilkanMenu();

    // Meminta pengguna memilih menu
    cout << "Pilih menu (1-5): ";
    cin >> pilihan;

    // Meminta pengguna memasukkan jumlah pesanan
    cout << "Masukkan jumlah pesanan: ";
    cin >> jumlah;

    // Menghitung total biaya pesanan
    float total = HitungTotal(pilihan, jumlah);

    // Menampilkan total biaya pesanan
    cout << "Total biaya: Rp. " << total << endl;

    return 0;
}
