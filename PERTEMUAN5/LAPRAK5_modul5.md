# <h1 align="center">LAPORAN PRAKTIKUM MODUL 5 : HASH TABLE</h1>
<p align="center">RAMADHIKA PRIMADANA - 2311102141</p>

# Dasar Teori

## A. PENGERTIAN HASH TABLE
Hash Table atau Tabel Hash adalah sebuah data struktur yang digunakan untuk menyimpan dan mengelola data dengan cepat dan efisien. Hash table atau peta hash merupakan sebuah struktur data yang terdiri atas sebuah tabel dan fungsi yang bertujuan untuk memetakan nilai kunci (key) yang unik dan digunakan untuk mengakses, menyimpan data atau memanipulasinya. Fungsi hash memetakan elemen pada indeks dari hash table yang biasanya berukuran lebih besar dari jumlah data yang hendak disimpan. Hash table biasanya digunakan untuk menambahkan, menghapus, dan mencari data.

## B. PENGERTIAN HASHING DALAM HASH TABLE
Hashing adalah metode mengubah kunci atau string menjadi angka. Dalam dunia pemrograman, pengguna sering menggunakan teknik hashing ini untuk membuat struktur data yang disebut tabel hash.

## C. FUNGSI HASH TABLE
Hash table berfungsi untuk menyimpan dan mengelola data dengan cepat dan efisien. Ini sangat berguna untuk menyelesaikan masalah pencarian yang kompleks. Misalnya, jika kita memiliki sekumpulan data yang sangat besar, maka pencarian data secara linear atau binary search akan menjadi sangat lama. Namun, jika kita menggunakan hash table, maka pencarian data akan cepat dan efisien. Contohnya utamanya seperti pada bidang jaringan komputer yang mengembangkannya menjadi hybrid open hash table, yang kemudian dipakai untuk memproses jaringan komputer.

## D. KOMPONEN ELEMEN DALAM HASH TABLE
Hash table terdiri dari beberapa komponen elemen, antara lain :
1. Tabel: Tabel adalah sebuah array yang digunakan untuk menyimpan data.
2. Fungsi Hash: Fungsi hash digunakan untuk mengubah kunci menjadi indeks yang digunakan untuk menyimpan data pada tabel.
3. Kunci: Kunci adalah nilai yang digunakan untuk mengakses data pada hash table.
4. Nilai: Nilai adalah data yang disimpan pada hash table.

## E. PENANGANAN COLLISON(TABRAKAN) DALAM HASH TABLE
Hash table memiliki beberapa cara untuk mengatasi collision (tabrakan), yaitu dengan menggunakan closed hashing (open addressing) dan open hashing (Open Addressing). 
1. Open Hashing (Separate Chaining)
Open hashing atau separate chaining dilakukan dengan membuat tabel hash menjadi sebuah array of pointer yang masing-masing pointernya diikuti oleh sebuah linked list. Dalam pendekatan ini, setiap elemen array (bucket) mengandung sebuah linked list. Chain atau rantai pertama terletak pada array of pointer itu sendiri, sedangkan chain-chain berikutnya berhubungan dengan chain pertama secara memanjang. Kelemahan metode ini yaitu terjadi linked list yang panjang apabila data menumpuk pada satu atau sedikit indeks.
2. Closed Hashing (Open Addressing)
Closed Hashing dilakukan dengan menggunakan memori yang masih ada tanpa menggunakan memori di luar array yang dipakai. Dalam closed hashing, ketika terjadi tabrakan atau collision di suatu indeks dalam array, algoritma akan mencari alamat lain untuk menyimpan data yang bertabrakan tanpa meninggalkan array yang sudah ada. Terdapat tiga metode dalam closed hashing, antara lain :
- Linear Probing (Metode Pembagian) dilakukan dengan mencari posisi yang kosong dengan bergeser satu indeks dari indeks sebelumnya hingga ditemukan alamat yang belum terisi data.
- Quadratic Probing (Metode Midsquare/Nilai Tengah) dilakukan dengan mencari alamat baru untuk ditempati dengan proses perhitungan kuadratik yang lebih kompleks.
- Double Hashing (Metode Penjumlahan Digit) dilakukan dengan melakukan hashing ulang sehingga tercipta hash value yang baru

 Closed hashing menggunakan algoritma penyimpanan data yang berbeda sekali dengan open hashing, yang menggunakan algoritma yang lebih sederhana.

## F. OPERASI KERJA DALAM HASH TABLE
Berikut adalah operasi yang dapat dilakukan pada hash table:
1. Insert: Insert atau Tambah adalah operasi untuk menambahkan data pada hash table. Ini dapat dilakukan dengan menggunakan fungsi hash untuk menentukan indeks yang sesuai untuk menyimpan data.
2. Delete: Delete atau Hapus adalah operasi untuk menghapus data pada hash table. Ini dapat dilakukan dengan menggunakan indeks yang dihasilkan oleh fungsi hash untuk menentukan lokasi data yang akan dihapus.
3. Search: Search atau Pencarian adalah operasi untuk mencari data pada hash table. Ini dapat dilakukan dengan menggunakan indeks yang dihasilkan oleh fungsi hash untuk menentukan lokasi data yang dicari.
4. Update: Update atau Memperbarui adalah operasi untuk mengubah data pada hash table. Ini dapat dilakukan dengan menggunakan indeks yang dihasilkan oleh fungsi hash untuk menentukan lokasi data yang akan diupdate.

## G. KELEBIHAN  DAN KEKURANGAN HASH TABLE
#### 1. KELEBIHAN HASH TABLE
- Waktu akses yang lebih cepat, jika record yang dicari langsung berada pada angka hash lokasi penyimpanannya.
- Hashing yang relative lebih cepat.
- Cocok untuk merepresentasikan data dengan frekuensi insert, delete dan search yang tinggi.
- Hash table juga memiliki beberapa cara pencarian alamat lain tersebut, yaitu linear probing, quadratic probing, dan double hashing.
#### 2. KEKURANGAN HASH TABLE
Kekurangan dari hash table adalah adanya kemungkinan terjadi collision (tabrakan). Collision adalah saat dimana ada dua angka yang dimasukan dalam fungsi hash yang menhasilkan nilai hasil yang sama. Contoh: Hash(24) = 24 %5 = 4 dan Hash(19) = 19%5 = 4. Untuk mengatasi collision ini, dapat digunakan closed hashing (open addressing) dan open hashing (closed hashing digunakan untuk menyelesaikan collision dengan cara mencari alamat lain apabila alamat yang dituju sudah terisi)

## H. CONTOH ILLUSTRASI HASH TABLE
![CONTOH ILLUSTRASI HASH TABLE](/PERTEMUAN5/Gambar_Dasar_Teori.png)


## Guided 

### 1. [Program Hash Table Sederhana]

```C++
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```

Kode di atas digunakan untuk mengimplementasikan program Program di atas merupakan implementasi dari hash table sederhana. Pada program ini terdapat pasangan kunci-nilai (key-value) di mana setiap key dipetakan ke value tertentu menggunakan fungsi hash. Fungsi-fungsi yang tersedia dalam kelas HashTable antara lain:
- 'HashTable()': Konstruktor yang menginisialisasi tabel hash dengan ukuran maksimum 10.
- 'HashTable()': Destruktor yang digunakan untuk menghapus semua elemen dari tabel hash.
- 'insert(int key, int value)': Fungsi untuk menambahkan data ke dalam tabel hash.
- 'get(int key)': Fungsi untuk mengambil nilai dari tabel hash berdasarkan key yang diberikan.
- 'remove(int key)': Fungsi untuk menghapus data dari tabel hash berdasarkan key yang diberikan.
- 'traverse()': Fungsi untuk menampilkan semua data yang ada dalam tabel hash.
Dengan demikian, program tersebut menciptakan sebuah struktur data hash table sederhana yang memungkinkan operasi-operasi dasar seperti penyisipan, pencarian, dan penghapusan elemen. Dalam contoh penggunaan, kode ini menambahkan beberapa data ke dalam tabel hash, mengambil nilai dari key 1, menghapus data dari key 4, dan menampilkan semua data yang ada dalam tabel hash. Hasil Pada Output Program diatas seperti berikut:
- Get key 1: 10
- Get key 4: -1
- 3 : 30
- 2 : 20
- 1 : 10


### 2. [Program Hash Table dengan Node]

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

class HashNode {
public:
    string name;
    string phone_number;
    
    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Nomer Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    
    employee_map.remove("Mistah");
    
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    
    cout << "Hash Table : " << endl;
    employee_map.print();
    
    return 0;
}
```

Kode di atas digunakan untuk mengimplementasikan program sederhana hash map untuk menyimpan nama dan nomor telepon. Program menggunakan tiga Include: iostream, string, dan vector, dengan konstanta TABLE_SIZE bernilai 11. Fungsi-fungsi yang tersedia dalam kelas HashMap antara lain:
- 'hashFunc(string key)': Fungsi untuk menghasilkan indeks dari key yang diberikan.
- 'insert(string name, string phone_number)': Fungsi untuk menambahkan data ke dalam tabel hash.
- 'remove(string name)': Fungsi untuk menghapus data dari tabel hash berdasarkan key yang diberikan.
- 'searchByName(string name)': Fungsi untuk mengambil nilai dari tabel hash berdasarkan key yang diberikan.
- 'print()': Fungsi untuk menampilkan semua data yang ada dalam tabel hash.
Dalam main, program membuat objek employee_map dan melakukan operasi pada data, kemudian mencetak isi hash map. Contoh penggunaannya, kode ini menambahkan beberapa data ke dalam tabel hash, mengambil nilai dari key "Mistah" dan "Pastah", menghapus data dari key "Mistah", dan menampilkan semua data yang ada dalam tabel hash. Hasil Pada Output Program diatas seperti berikut:
- Nomer Hp Mistah : 1234
- Nomer Hp Pastah : 5678
- Nomer Hp Mistah setelah dihapus : 
- Hash Table : 
- 0: 
- 1: 
- 2: 
- 3: 
- 4: [Pastah, 5678]
- 5: 
- 6: [Ghana, 91011]
- 7: 
- 8: 
- 9: 
- 10:

## Unguided 

### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : 
- a. Setiap mahasiswa memiliki NIM dan nilai. 
- b. Program memiliki tampilan pilihan menu berisi poin C. 
- c. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).]

```C++
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



```
#### Output:
MENAMBAH DATA MAHASISWA
![SS_Unguided1_Laprak5_ke-1.png](/PERTEMUAN5/modul5.ungided1.1_141.png)
![SS_Unguided1_Laprak5_ke-2.png](/PERTEMUAN5/modul5.ungided1.2_141.png)
![SS_Unguided1_Laprak5_ke-3.png](/PERTEMUAN5/modul5.ungided1.3_141.png)
![SS_Unguided1_Laprak5_ke-4.png](/PERTEMUAN5/modul5.ungided1.4_141.png)
![SS_Unguided1_Laprak5_ke-5.png](/PERTEMUAN5/modul5.ungided1.5_141.png)


Kode di atas digunakan untuk implementasi dari struktur data hash table yang digunakan untuk menyimpan data mahasiswa, yang terdiri dari nama, NIM, dan nilai. Tabel yang digunakan memiliki ukuran 100. Fungsi-fungsi yang tersedia dalam kelas HashMap antara lain:
- `hashFunc(string key)`: Fungsi untuk menghasilkan indeks dari key (nama) mahasiswa.
- `insert(string Nama, string NIM, int Nilai)`: Fungsi untuk menambahkan data mahasiswa ke dalam tabel hash.
- `remove(string Nama)`: Fungsi untuk menghapus data mahasiswa dari tabel hash berdasarkan nama.
- `searchByNIM(string NIM)`: Fungsi untuk mencari data mahasiswa berdasarkan NIM.
- `CariRentangNilai(int NilaiMin, int NilaiMax)`: Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai.
- `tampilkanSemuaData()`: Fungsi untuk menampilkan semua data mahasiswa yang ada dalam tabel hash.
Contoh penggunaannya Didalam Program tersebut terdapat menampilkan Menu menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai yang diinput oleh pengguna. Program ini juga terdapat menampilkan semua data mahasiswa yang ada dalam tabel hash. Lebih jelasnya yang hasil programnya seperti gambar output diatas.


## Kesimpulan
Kesimpulannya, pada modul 5 ini Hash Table atau Tabel Hash adalah sebuah struktur data yang digunakan untuk menyimpan pasangan key-value, di mana key digunakan sebagai indeks atau alamat untuk mengakses nilai terkait (value). Hash table terdiri dari sebuah array di mana setiap elemen dalam array tersebut disebut sebagai bucket. Untuk memetakan suatu key pada sebuah value, diperlukan sebuah teknik hashing. Tabel Hash Table atau Tabel Hash ini adalah struktur data yang sangat baik untuk operasi penyisipan, pencarian, dan penghapusan dengan kompleksitas waktu rata-rata yang cepat. Namun, perlu dipertimbangkan pula manajemen collision atau tabrakan data hash dan skalabilitas struktur data ini tergantung pada aplikasi spesifik yang digunakan.

## Referensi
[1] Dr. Joseph Teguh Santoso. Struktur Data dan ALgoritma. Semarang: Yayasan Prima Agus Teknik. 2021.
[2] Muhammad Nugraha. Dasar Pemrograman Dengan C++ Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta. 2021.
[3] Mulyana A. E-Books Cara Mudah Mempelajari Algoritma dan Struktur Data. 2023.
