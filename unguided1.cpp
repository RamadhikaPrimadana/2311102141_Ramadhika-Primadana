// Program Hash Table Menu Data Mahasiswa
#include <iostream>
#include <string> // Untuk memanipulasi string ke variable tujuan
#include <vector> // untuk menggunakan struktur data vektor
#include <iomanip> // Untuk mengatur format tabel bidang dalam output

using namespace std;

// Konstanta untuk ukuran tabel hash
const int TABLE_SIZE = 100;

// Kelas HashNode untuk menampung data mahasiswa
class HashNode
{
public:
    string Nama_141; // Menyimpan Nama
    string NIM_141; // Menyimpan NIM
    int Nilai_141; // Menyimpan Nilai

    // Konstruktor untuk inisialisasi data mahasiswa
    HashNode(string Nama_141, string NIM_141, int Nilai_141)
    {
        this->Nama_141 = Nama_141;
        this->NIM_141 = NIM_141;
        this->Nilai_141 = Nilai_141;
    }
};

// Kelas HashMap untuk mengelola data mahasiswa dalam tabel hash
class HashMap
{
private:
    vector<HashNode *> table_141[TABLE_SIZE]; // Tabel hash untuk menyimpan data

public:
    // Fungsi hash untuk menghitung nilai hash dari kunci (nama)
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c; // Menambahkan nilai ASCII dari setiap karakter
        }
        return hash_val % TABLE_SIZE; // Mengembalikan nilai hash yang terbatas pada ukuran tabel
    }

    // Fungsi untuk memasukkan data mahasiswa ke dalam tabel hash
    void insert(string Nama_141, string NIM_141, int Nilai_141)
    {
        int hash_val = hashFunc(Nama_141);                               // Mendapatkan nilai hash dari nama mahasiswa
        HashNode *node_141 = new HashNode(Nama_141, NIM_141, Nilai_141); // Membuat objek HashNode baru
        table_141[hash_val].push_back(node_141);                         // Menambahkan data mahasiswa ke dalam tabel
        cout << "----------------------------------------------------------\n";
        cout << "Data Mahasiswa dengan Nama " << Nama_141 << " berhasil ditambahkan." << endl;
        cout << "==========================================================\n";
    }

    // Fungsi untuk menghapus data mahasiswa dari tabel hash
    void remove(string Nama_141)
    {
        int hash_val = hashFunc(Nama_141); // Mendapatkan nilai hash dari nama mahasiswa
        for (auto it = table_141[hash_val].begin(); it != table_141[hash_val].end(); ++it)
        {
            if ((*it)->Nama_141 == Nama_141)
            {                                  // Memeriksa apakah nama mahasiswa sesuai
                delete *it;                    // Menghapus objek HashNode
                table_141[hash_val].erase(it); // Menghapus elemen dari vektor
                cout << "----------------------------------------------------------\n";
                cout << "Data Mahasiswa dengan nama " << Nama_141 << " berhasil dihapus." << endl;
                cout << "==========================================================\n";
                return;
            }
        }
        cout << "----------------------------------------------------------\n";
        cout << "Data Mahasiswa dengan nama " << Nama_141 << " tidak ditemukan." << endl;
        cout << "==========================================================\n";
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void searchByNIM(string NIM_141)
    {
        bool found_141 = false;
        for (int i_141 = 0; i_141 < TABLE_SIZE; ++i_141)
        {
            for (auto node_141 : table_141[i_141])
            {
                if (node_141->NIM_141 == NIM_141)
                {                         // Memeriksa apakah NIM sesuai
                    displayHeader();      // Menampilkan header tabel
                    displayRow(node_141); // Menampilkan baris data mahasiswa
                    found_141 = true;
                    return;
                }
            }
        }
        cout << "----------------------------------------------------------\n";
        cout << "Mahasiswa dengan NIM " << NIM_141 << " tidak ditemukan." << endl;
        cout << "==========================================================\n";
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
    void CariRentangNilai(int NilaiMin_141, int NilaiMax_141)
    {
        bool found_141 = false;
        displayHeader(); // Menampilkan header tabel
        for (int i_141 = 0; i_141 < TABLE_SIZE; ++i_141)
        {
            for (auto node_141 : table_141[i_141])
            {
                if (node_141->Nilai_141 >= NilaiMin_141 && node_141->Nilai_141 <= NilaiMax_141)
                {                         // Memeriksa rentang nilai
                    displayRow(node_141); // Menampilkan baris data mahasiswa
                    found_141 = true;
                }
            }
        }
        if (!found_141)
        {
            cout << "----------------------------------------------------------\n";
            cout << "Tidak ada data Mahasiswa dengan rentang nilai " << NilaiMin_141 << " sampai " << NilaiMax_141 << "." << endl;
            cout << "==========================================================\n";
        }
    }
    // Fungsi untuk menampilkan footer penutup tabel
    void displayFooter()
    {
        cout << "==========================================================\n";
    }

    // Fungsi untuk menampilkan header tabel
    void displayHeader()
    {
        cout << "==========================================================\n";
        cout << "|                       DATA MAHASISWA                   |\n";
        cout << "==========================================================\n";
        cout << "|          NAMA          |        NIM        |   NILAI   |\n";
        cout << "==========================================================\n";
    }

    // Fungsi untuk menampilkan baris data mahasiswa
    void
    displayRow(HashNode *node_141)
    {
        cout << "| " << left << setw(23) << node_141->Nama_141            // Menampilkan nama
             << "| " << left << setw(18) << node_141->NIM_141             // Menampilkan NIM
             << "| " << left << setw(9) << node_141->Nilai_141 << " |\n"; // Menampilkan nilai
    }

    // Fungsi untuk menampilkan semua data mahasiswa
    void tampilkanSemuaData()
    {
        bool found = false;
        displayHeader(); // Menampilkan header tabel
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            for (auto node : table_141[i])
            {
                displayRow(node); // Menampilkan baris data mahasiswa
                found = true;
            }
        }
        displayFooter(); // Menampilkan footer penutup tabel
        if (!found)
        {
            cout << "Tidak ada data yang tersimpan." << endl;
        }
    }
};

int main()
{
    HashMap hmap_141; // Membuat objek HashMap
    int Pilihan_141;
    string Nama_141, NIM_141;
    int nilai, NilaiMin_141, NilaiMax_141;

    // Menu utama program
    do
    {
        cout << "\n==========================================================\n";
        cout << ">>>>>>> MENU PROGRAM MAHASISWA BY Ramadhika Primadana <<<<<<<\n";
        cout << "==========================================================\n";
        cout << "1. TAMBAH DATA MAHASISWA\n";
        cout << "2. MENGHAPUS DATA MAHASISWA\n";
        cout << "3. MENCARI DATA BERDASARKAN NIM MAHASISWA\n";
        cout << "4. MENCARI DATA BERDASARKAN RENTANG NILAI MAHASISWA\n";
        cout << "5. TAMPILKAN SEMUA DATA\n";
        cout << "6. KELUAR\n";
        cout << "==========================================================\n";
        cout << "Masukkan pilihan: ";
        cin >> Pilihan_141; // Meminta input dari pengguna
        cout << endl;
        switch (Pilihan_141)
        {
        case 1: // Untuk pilihan menu menambah data mahasiswa
            cout << "==========================================================\n";
            cout << "<<<<<<<<<<<<<<<<<< TAMBAH DATA MAHASISWA >>>>>>>>>>>>>>>>>\n";
            cout << "==========================================================\n";
            cout << "Masukkan Nama : ";
            cin >> ws;
            getline(cin, Nama_141); // Meminta input nama mahasiswa
            cout << "Masukkan NIM  : ";
            cin >> NIM_141; // Meminta input NIM mahasiswa
            cout << "Masukkan Nilai: ";
            cin >> nilai;                              // Meminta input nilai mahasiswa
            hmap_141.insert(Nama_141, NIM_141, nilai); // Memanggil fungsi untuk memasukkan data mahasiswa
            break;
        case 2: // Untuk pilihan menu menghapus data mahasiswa
            cout << "==========================================================\n";
            cout << "<<<<<<<<<<<<<<<<< MENGHAPUS DATA MAHASISWA >>>>>>>>>>>>>>>\n";
            cout << "==========================================================\n";
            cout << "Masukkan Nama Mahasiswa untuk dihapus : ";
            cin >> ws;
            getline(cin, Nama_141);    // Meminta input nama mahasiswa yang akan dihapus
            hmap_141.remove(Nama_141); // Memanggil fungsi untuk menghapus data mahasiswa
            break;
        case 3: // Untuk pilihan menu Mencari data berdasarkan NIM mahasiswa
            cout << "==========================================================\n";
            cout << "<<<<<<<<<< MENCARI DATA BERDASARKAN NIM MAHASISWA >>>>>>>>\n";
            cout << "==========================================================\n";
            cout << "Masukkan NIM Mahasiswa untuk dicari : ";
            cin >> NIM_141;                // Meminta input NIM mahasiswa yang akan dicari
            hmap_141.searchByNIM(NIM_141); // Memanggil fungsi untuk mencari data berdasarkan NIM
            break;
        case 4: // Untuk pilihan menu Mencari data berdasarkan Rentang nilai mahasiswa
            cout << "==========================================================\n";
            cout << "<<<< MENCARI DATA BERDASARKAN RENTANG NILAI MAHASISWA >>>>\n";
            cout << "==========================================================\n";
            cout << "Masukkan Nilai Minimum  : ";
            cin >> NilaiMin_141; // Meminta input nilai minimum
            cout << "Masukkan Nilai Maksimum : ";
            cin >> NilaiMax_141;                                   // Meminta input nilai maksimum
            hmap_141.CariRentangNilai(NilaiMin_141, NilaiMax_141); // Memanggil fungsi untuk mencari data berdasarkan rentang nilai
            break;
        case 5: // Untuk pilihan menu Menampilkan semua data
            hmap_141.tampilkanSemuaData(); // Memanggil fungsi untuk menampilkan semua data
            break;
        case 6: // Untuk pilihan Keluar menu
            cout << "Terima kasih telah menggunakan program ini." << endl; // Pesan penutup
            break;
        default:
            cout << "Pilihan tidak valid. Silakan pilih sesuai nomor pada menu." << endl; // Pesan kesalahan
        }
    } while (Pilihan_141 != 6); // Melanjutkan program sampai pengguna memilih untuk keluar

    return 0; // Mengakhiri program
}
