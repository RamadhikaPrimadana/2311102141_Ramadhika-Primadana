# <h1 align="center">LAPORAN PRAKTIKUM MODUL 3 : SINGLE AND DOUBLE LINKED LIST</h1>
<p align="center">RAMADHIKA PRIMADANA - 2311102141</p>

# Dasar Teori

## SINGLE AND DOUBLE LINKED LIST

### LINKED LIST

Linked List adalah salah satu bentuk struktur data, berisi kumpulan data (node) yang tersusun secara sekuensial, saling sambung-menyambung, dinamis dan terbatas.
- Linked List sering disebut juga Senarai Berantai
- Linked List saling terhubung dengan bantuan variabel pointer
- Masing-masing data dalam Linked List disebut dengan node (simpul) yang menempati alokasi memori secara dinamis dan biasanya berupa struct yang terdiri dari beberapa field.

### SINGLE LINKED LIST

Single Linked List (SLL) adalah linked list unidirectional yang hanya memiliki satu arah. Single Linked List adalah sebuah LINKED LIST yang menggunakan sebuah variabel pointer saja untuk menyimpan banyak data dengan metode LINKED LIST, suatu daftar isi yang saling berhubungan. Single Linked List (SLL) adalah linked list unidirectional yang hanya memiliki satu arah. Pengguna hanya dapat melintasinya dalam satu arah, yaitu dari simpul kepala ke simpul ekor. SLL memiliki beberapa karakteristik, seperti memiliki memori tambahan untuk menyimpan link (tautan), memiliki simpul pertama yang disebut head atau simpul kepala, dan memiliki simpul akhir yang menunjuk ke simpul kepala. SLL dapat digunakan untuk membuat file system, adjacency list, dan hash table.

### DOUBLE LINKED LIST

Double Linked List (DLL) adalah linked list bidirectional yang memiliki dua arah. Pengguna bisa melintasinya secara dua arah. Double Linked List hampir sama dengan penggunaan Single Linked List. Hanya saja Double Linked List menerapkan dan memiliki tambahan sebuah pointer baru, yaitu prev (pointer previous), yang digunakan untuk menggeser mundur selain tetap mempertahankan pointer next. DLL ini memiliki simpul yang menunjuk ke simpul sebelumnya. Pointer ini memungkinkan Pengguna untuk melintas ke simpul sebelumnya dan ke simpul setelahnya. DLL lebih efisien dalam kasus dimana Pengguna membutuhkan akses ke simpul sebelumnya dan ke simpul setelahnya.

## Guided 

### 1. [Program Single Linked List]

```C++
// LAPRAK 3 : GUIDED 1
// RAMADHIKA PRIMADANA
// 23111021
// S1 IF-11-D
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        ;
    return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}

```

Kode di atas digunakan untuk mengimplementasikan program Single Linked List Non-Circular yang dapat digunakan untuk menangani operasi data yang berhubungan dengan linked list. Program ini menampilkan isi, menghitung jumlah, serta mengelola data dalam linked list secara efisien. Program ini juga memiliki bagian utama yang menggunakan fungsi untuk menambah, menghapus, mengubah, dan mengosongkan node dalam linked list. Program ini menggunakan struct Node untuk mengelola data dan tautan ke node berikutnya. Fungsi yang tersedia dalam program: `init()` Fungsi ini digunakan untuk menginisialisasi linked list. Dengan memanggil fungsi ini, kita mengatur head dan tail menjadi NULL. `isEmpty()` Fungsi ini digunakan untuk mengecek apakah linked list masih kosong atau tidak. `insertDepan(int nilai)` Fungsi ini digunakan untuk menambah data baru di depan linked list. `insertBelakang(int nilai)` Fungsi ini digunakan untuk menambah data baru di belakang linked list. `hitungList()` Fungsi ini digunakan untuk menghitung jumlah data yang ada dalam linked list. `insertTengah(int data, int posisi)` Fungsi ini digunakan untuk menambah data baru di posisi tertentu dalam linked list. `hapusDepan()` Fungsi ini digunakan untuk menghapus data terakhir dari linked list. `hapusBelakang()` Fungsi ini digunakan untuk menghapus data pertama dari linked list. `hapusTengah(int posisi)` Fungsi ini digunakan untuk menghapus data yang berada di posisi tertentu dalam linked list. `ubahDepan(int data)` Fungsi ini digunakan untuk mengubah data pertama dalam linked list menjadi data yang diberikan. `ubahTengah(int data, int posisi)` Fungsi ini digunakan untuk mengubah data yang berada di posisi tertentu dalam linked list menjadi data yang diberikan. `ubahBelakang(int data)` Fungsi ini digunakan untuk mengubah data terakhir dalam linked list menjadi data yang diberikan. `clearList()` Fungsi ini digunakan untuk menghapus semua data dalam linked list.`tampil()` Fungsi ini digunakan untuk menampilkan semua data dalam linked list. Hasil output akan berjalan sesuai codingan.

### 2. [Program Double Linked List]

```C++
// LAPRAK 3 : GUIDED 2
// RAMADHIKA PRIMADANA
// 2311102141
// S1 IF-11-D
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }
    void pop()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    DoublyLinkedList list;
    while (true)
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2:
        {
            list.pop();
            break;
        }
        case 3:
        {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData, newData);
            if (!updated)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4:
        {
            list.deleteAll();
            break;
        }
        case 5:
        {
            list.display();
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
```

Kode di atas digunakan untuk mengimplementasikan program Double Linked List yang mengelola data berupa angka. Program ini Hampir sama pada guided 1 atau hampir sama dengan Single Linked List. Program ini menggunakan class Node untuk mengelola data dan tautan ke node berikutnya, dan tautan ke node sebelumnya. Fungsi yang tersedia dalam program: `push(int data)` Fungsi ini digunakan untuk menambah data baru di akhir Double Linked List. `pop()` Fungsi ini digunakan untuk menghapus data terakhir dari Double Linked List. `update(int oldData, int newData)` Fungsi ini digunakan untuk mengubah data yang sesuai dengan oldData menjadi newData. `deleteAll()` Fungsi ini digunakan untuk menghapus semua data dari Double Linked List. `display()` Fungsi ini digunakan untuk menampilkan semua data yang ada dalam Double Linked List.
Program ini juga menampilkan menu pilihan untuk mengelola data, yaitu:
1. Add data
2. Delete data
3. Update data
4. Clear data
5. Display data
6. Exit
Hasil outputnya adalah pilihan pengguna. Pengguna dapat memilih opsi yang diinginkan dan program akan melakukan operasi yang sesuai dengan opsi yang dipilih.

## Unguided 

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut: a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda. ![Soal Unguided 1](/pertemuan03/Laprak03%20dan%20Output/Soal_Unguided01_Laprak3.png) b. Hapus data Akechi. c. Tambahkan data berikut diantara John dan Jane : Futaba 18. d. Tambahkan data berikut diawal : Igor 20. e. Ubah data Michael menjadi : Reyn 18. f. Tampilkan seluruh data]

```C++
// LAPRAK 3 : UNGUIDED 1
// RAMADHIKA PRIMADANA
// 2311102141
// S1 IF-11-D
#include <iostream>
using namespace std;

struct Node {
    string nama_141;
    int usia_141;
    Node* next_141;
};

Node* head_141 = nullptr;

void tampilkanList_141() {
    cout << "[ Nama ]" << "\t" << "[ Usia ]" << endl;
    Node* saatIni_141 = head_141;
    while (saatIni_141 != nullptr) {
        cout << saatIni_141->nama_141 << "\t\t" << saatIni_141->usia_141 << endl;
        saatIni_141 = saatIni_141->next_141;
    }
}

void insertDepan_141(string nama_141, int usia_141) {
    Node* baru_141 = new Node;
    baru_141->nama_141 = nama_141;
    baru_141->usia_141 = usia_141;
    baru_141->next_141 = head_141;
    head_141 = baru_141;
}

void insertBelakang_141(string nama_141, int usia_141) {
    Node* baru_141 = new Node;
    baru_141->nama_141 = nama_141;
    baru_141->usia_141 = usia_141;
    baru_141->next_141 = nullptr;
    if (head_141 == nullptr) {
        head_141 = baru_141;
    }
    else {
        Node* temp_141 = head_141;
        while (temp_141->next_141 != nullptr) {
            temp_141 = temp_141->next_141;
        }
        temp_141->next_141 = baru_141;
    }
}

void insertTengah_141(string nama_141, int usia_141, int posisi_141) {
    Node* baru_141 = new Node;
    baru_141->nama_141 = nama_141;
    baru_141->usia_141 = usia_141;
    Node* bantu_141 = head_141;
    for (int i_141 = 1; i_141 < posisi_141 - 1; i_141++) {
        if (bantu_141 != nullptr) {
            bantu_141 = bantu_141->next_141;
        }
    }
    if (bantu_141 != nullptr) {
        baru_141->next_141 = bantu_141->next_141;
        bantu_141->next_141 = baru_141;
    }
}

void hapusData_141(string nama_141) {
    Node* hapus_141 = head_141;
    Node* prev_141 = nullptr;
    while (hapus_141 != nullptr && hapus_141->nama_141 != nama_141) {
        prev_141 = hapus_141;
        hapus_141 = hapus_141->next_141;
    }
    if (hapus_141 == nullptr) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    if (prev_141 == nullptr) {
        head_141 = hapus_141->next_141;
    }
    else {
        prev_141->next_141 = hapus_141->next_141;
    }
    delete hapus_141;
}

void ubahData_141(string nama_141, string newnama_141, int newusia_141) {
    Node* temp_141 = head_141;
    while (temp_141 != nullptr && temp_141->nama_141 != nama_141) {
        temp_141 = temp_141->next_141;
    }
    if (temp_141 != nullptr) {
        temp_141->nama_141 = newnama_141;
        temp_141->usia_141 = newusia_141;
    }
}

void tampilkanData() {
    Node* temp_141 = head_141;
    while (temp_141 != nullptr) {
        cout << temp_141->nama_141 << " " << temp_141->usia_141 << endl;
        temp_141 = temp_141->next_141;
    }
}

int main() {
    insertBelakang_141("Rama", 19);
    insertBelakang_141("John", 19);
    insertBelakang_141("Jane", 20);
    insertBelakang_141("Michael", 18);
    insertBelakang_141("Yusuke", 19);
    insertBelakang_141("Akechi", 20);
    insertBelakang_141("Hoshino", 18);
    insertBelakang_141("Karin", 18);

    char pilihan_141;
    do {
        cout << "\nMenu:\n";
        cout << "a. Tampilkan data sesuai urutan tersedia (Data pertama adalah nama dan usia pengguna)\n";
        cout << "b. Hapus data Akechi\n";
        cout << "c. Tambahkan data berikut diantara John dan Jane : Futaba 18\n";
        cout << "d. Tambahkan data berikut diawal : igor 20\n";
        cout << "e. Ubah data Michael menjadi : Reyn 18\n";
        cout << "f. Tampilkan seluruh data\n";
        cout << "g. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan_141;

        switch (pilihan_141) {
            case 'a':
                cout << "\nData yang tersedia:\n";
                tampilkanList_141();
                break;
            case 'b':
                hapusData_141("Akechi");
                cout << "Data Akechi berhasil dihapus.\n";
                cout << "\nData yang tersedia setelah penghapusan:\n";
                tampilkanList_141();
                break;
            case 'c':
                insertTengah_141("Futaba", 18, 3); 
                cout << "Data Futaba berhasil ditambahkan.\n";
                cout << "\nData yang tersedia setelah penambahan:\n";
                tampilkanList_141();
                break;
            case 'd':
                insertDepan_141("Igor", 20);
                cout << "Data Igor berhasil ditambahkan di awal.\n";
                cout << "\nData yang tersedia setelah penambahan:\n";
                tampilkanList_141();
                break;
            case 'e':
                ubahData_141("Michael", "Reyn", 18);
                cout << "Data Michael berhasil diubah menjadi Reyn 18.\n";
                cout << "\nData yang tersedia setelah perubahan:\n";
                tampilkanList_141();
                break;
            case 'f':
                cout << "\nTampilan seluruh data sekarang:\n";
                tampilkanList_141();
                break;
            case 'g':
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                break;
        }
    } while (pilihan_141 != 'g');

    return 0;
}


```
#### Output:
![SS_Unguided01-1_Laprak3_2311102138_RicoAdePratama_S1IF11D](/pertemuan03/Laprak03%20dan%20Output/SS_Unguided01-1_Laprak3_2311102138_RicoAdePratama_S1IF11D.png)
![SS_Unguided01-2_Laprak3_2311102138_RicoAdePratama_S1IF11D](/pertemuan03/Laprak03%20dan%20Output/SS_Unguided01-2_Laprak3_2311102138_RicoAdePratama_S1IF11D.png)
![SS_Unguided01-3_Laprak3_2311102138_RicoAdePratama_S1IF11D](/pertemuan03/Laprak03%20dan%20Output/SS_Unguided01-3_Laprak3_2311102138_RicoAdePratama_S1IF11D.png)

Kode di atas digunakan untuk implementasi sederhana dari program Single Linked List yang mengelola data nama dan umur. Program ini menggunakan struct Node untuk mengelola data nama dan umur dan tautan ke node berikutnya. Berikut adalah deskripsi fungsi yang tersedia dalam program: `tampilkanList_138()` Fungsi ini digunakan untuk menampilkan semua data nama dan umur yang ada dalam linked list. `insertDepan_138(string nama_138, int usia_138)` Fungsi ini digunakan untuk menambah data nama dan umur baru di awal linked list. `insertBelakang_138(string nama_138, int usia_138)` Fungsi ini digunakan untuk menambah data nama dan umur baru di akhir linked list. `insertTengah_138(string nama_138, int usia_138, int posisi_138)` Fungsi ini digunakan untuk menambah data nama dan umur baru di posisi tertentu dalam linked list. `hapusData_138(string nama_138)` Fungsi ini digunakan untuk menghapus data nama dan umur yang sesuai diberikan. `ubahData_138(string nama_138, string newnama_138, int newusia_138)` Fungsi ini digunakan untuk mengubah data nama dan umur yang sesuai dengan nama yang diberikan. `tampilkanData()` Fungsi ini digunakan untuk menampilkan semua data nama dan umur yang ada dalam linked list. Program ini juga menampilkan menu pilihan untuk mengelola data nama dan umur, yaitu:
- a. Tampilkan data sesuai urutan tersedia (Data pertama adalah nama dan usia pengguna)
- b. Hapus data Akechi
- c. Tambahkan data berikut diantara John dan Jane : Futaba 18
- d. Tambahkan data berikut diawal : igor 20
- e. Ubah data Michael menjadi : Reyn 18
- f. Tampilkan seluruh data
- g. Keluar
Pengguna dapat memilih opsi yang diinginkan dan program akan melakukan operasi yang sesuai dengan opsi yang dipilih. Sebagai contoh memilih opsi urut dari a sampai g. Lebih jelasnya yang hasil programnya seperti gambar output diatas.

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahanoperasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.  Nama Produk Harga Originote 60.000, Somethinc 150.000, Skintific 100.000, Wardah 50.000, Hanasui 30.000. Case: 1. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific. 2. Hapus produk wardah. 3. Update produk Hanasui menjadi Cleora dengan harga 55.000. 4. Tampilkan menu seperti dibawah ini. Toko Skincare Purwokerto. 1. Tambah Data, 2. Hapus Data, 3. Update Data, 4. Tambah Data Urutan Tertentu, 5. Hapus Data Urutan Tertentu, 6. Hapus Seluruh Data, 7. Tampilkan Data, 8. Exit. Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :![Soal Unguided 2](/pertemuan03/Laprak03%20dan%20Output/Soal_Unguided02_Laprak3.png)]

```C++
// LAPRAK 3 : UNGUIDED 2
// RAMADHIKA PRIMADANA
// 2311102141
// S1 IF-11-D
#include <iostream>
#include <iomanip> 
using namespace std;

// Deklarasi Struct Node
class Node {
public:
    string produk_141;
    int harga_141;
    Node* prev_141;
    Node* next_141;
};

// Deklarasi Class DoublyLinkedList
class DoublyLinkedList {
public:
    Node* head_141;
    Node* tail_141;

    // Constructor
    DoublyLinkedList() {
        head_141 = nullptr;
        tail_141 = nullptr;
    }

    // Prosedur untuk menambahkan data di depan
    void Push(int harga_141, string produk_141) {
        Node* newNode_141 = new Node;
        newNode_141->harga_141 = harga_141;
        newNode_141->produk_141 = produk_141;
        newNode_141->prev_141 = nullptr;
        newNode_141->next_141 = head_141;

        if (head_141 != nullptr) {
            head_141->prev_141 = newNode_141;
        }
        else {
            tail_141 = newNode_141;
        }

        head_141 = newNode_141;
    }

    // Prosedur untuk menambahkan data pada posisi tertentu
    void PushPosition(int posisi_141, int harga_141, string produk_141) {
        if (posisi_141 < 1) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        Node* newNode_141 = new Node;
        newNode_141->harga_141 = harga_141;
        newNode_141->produk_141 = produk_141;
        newNode_141->prev_141 = nullptr;
        newNode_141->next_141 = nullptr;

        if (posisi_141 == 1) {
            newNode_141->next_141 = head_141;
            if (head_141 != nullptr)
                head_141->prev_141 = newNode_141;
            else
                tail_141 = newNode_141;
            head_141 = newNode_141;
            return;
        }

        Node* saatIni_141 = head_141;
        for (int i = 1; i < posisi_141 - 1 && saatIni_141 != nullptr; ++i)
            saatIni_141 = saatIni_141->next_141;

        if (saatIni_141 == nullptr) {
            cout << "Posisi tidak valid!" << endl;
            delete newNode_141;
            return;
        }

        newNode_141->next_141 = saatIni_141->next_141;
        newNode_141->prev_141 = saatIni_141;
        if (saatIni_141->next_141 != nullptr)
            saatIni_141->next_141->prev_141 = newNode_141;
        else
            tail_141 = newNode_141;
        saatIni_141->next_141 = newNode_141;
    }

    // Prosedur untuk menghapus data di depan
    void Pop() {
        if (head_141 == nullptr) {
            cout << "Tidak ada data yang bisa dihapus!" << endl;
            return;
        }

        Node* temp_141 = head_141;
        head_141 = head_141->next_141;

        if (head_141 != nullptr) {
            head_141->prev_141 = nullptr;
        }
        else {
            tail_141 = nullptr;
        }

        delete temp_141;
    }

    // Prosedur untuk menghapus data pada posisi tertentu
    void PopPosition(int posisi_141) {
        if (head_141 == nullptr) {
            cout << "Tidak ada data yang bisa dihapus!" << endl;
            return;
        }

        Node* temp_141 = head_141;
        for (int i = 1; i < posisi_141 && temp_141 != nullptr; ++i) {
            temp_141 = temp_141->next_141;
        }

        if (temp_141 == nullptr) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        if (temp_141->prev_141 != nullptr) {
            temp_141->prev_141->next_141 = temp_141->next_141;
        } else {
            head_141 = temp_141->next_141;
        }

        if (temp_141->next_141 != nullptr) {
            temp_141->next_141->prev_141 = temp_141->prev_141;
        } else {
            tail_141 = temp_141->prev_141;
        }

        delete temp_141;
    }

    // Fungsi untuk mengupdate data
    bool Update(string oldProduk_141, string newProduk_141, int newharga_141) {
        Node* saatIni_141 = head_141;

        while (saatIni_141 != nullptr) {
            if (saatIni_141->produk_141 == oldProduk_141) {
                saatIni_141->produk_141 = newProduk_141;
                saatIni_141->harga_141 = newharga_141;
                return true;
            }
            saatIni_141 = saatIni_141->next_141;
        }

        return false;
    }

    // Prosedur untuk menghapus semua data
    void DeleteAll() {
        Node* saatIni_141 = head_141;

        while (saatIni_141 != nullptr) {
            Node* temp_141 = saatIni_141;
            saatIni_141 = saatIni_141->next_141;
            delete temp_141;
        }

        head_141 = nullptr;
        tail_141 = nullptr;
    }

    // Prosedur untuk menampilkan data
    void Display_141() {
        Node* saatIni_141 = head_141;

        cout << left << setw(20) << "[ Nama Produk ]" << setw(10) << "[ Harga ]" << endl;

        while (saatIni_141 != nullptr) {
            cout << setw(20) << saatIni_141->produk_141 << setw(10) << saatIni_141->harga_141 << endl;
            saatIni_141 = saatIni_141->next_141;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    cout << "\n== MENU TOKO SKINCARE PURWOKERTO BY RAMADHIKA PRIMADANA ==" << endl;

    // Inisialisasi data awal
    list.Push(30000, "Hanasui");
    list.Push(50000, "Wardah");
    list.Push(100000, "Skintific");
    list.Push(150000, "Somethinc");
    list.Push(60000, "Originote");
    list.Display_141(); 

    // Loop untuk menu interaktif
    while (true) {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "   1. Tambah Data" << endl;
        cout << "   2. Hapus Data" << endl;
        cout << "   3. Update Data" << endl;
        cout << "   4. Tambah Data pada Posisi Tertentu" << endl;
        cout << "   5. Hapus Data pada Posisi Tertentu" << endl;
        cout << "   6. Hapus Semua Data" << endl;
        cout << "   7. Tampilkan Data" << endl;
        cout << "   8. Exit" << endl;

        int pilihan_141;
        cout << "Pilih Nomor: ";
        cin >> pilihan_141;

        switch (pilihan_141) {
            case 1: {
                int harga_141;
                string produk_141;

                cout << "\nTAMBAH PRODUK SKINCARE" << endl;
                cout << "Nama produk: ";
                cin.ignore();
                getline(cin, produk_141);
                cout << "Harga produk: ";
                cin >> harga_141;
                list.Push(harga_141, produk_141);
                cout << "Produk berhasil ditambahkan!" << endl;
                list.Display_141(); 
                break;
            }

            case 2: {
                list.Pop();
                cout << "PRODUK PALING ATAS BERHASIL DIHAPUS!" << endl;
                list.Display_141(); 
                break;
            }

            case 3: {
                string oldProduk_141, newProduk_141;
                int newharga_141;

                cout << "\nUPDATE DATA PRODUK SKINCARE" << endl;
                cout << "Masukkan nama produk yang ingin diubah: ";
                cin.ignore();
                getline(cin, oldProduk_141);
                cout << "Masukkan nama produk baru: ";
                getline(cin, newProduk_141);
                cout << "Masukkan harga baru: ";
                cin >> newharga_141;

                bool update_141 = list.Update(oldProduk_141, newProduk_141, newharga_141);
                if (update_141) {
                    cout << "Data berhasil diperbarui!" << endl;
                } else {
                    cout << "Data tidak ditemukan!" << endl;
                }
                list.Display_141(); 
                break;
            }

            case 4: {
                int posisi_141, harga_141;
                string produk_141;

                cout << "\nTAMBAH PRODUK SKINCARE PADA POSISI TERTENTU" << endl;
                cout << "Masukkan posisi untuk produk baru: ";
                cin >> posisi_141;
                cout << "Nama produk: ";
                cin.ignore();
                getline(cin, produk_141);
                cout << "Harga produk: ";
                cin >> harga_141;
                list.PushPosition(posisi_141, harga_141, produk_141);
                cout << "Produk berhasil ditambahkan pada posisi ke-" << posisi_141 << "!" << endl;
                list.Display_141(); 
                break;
            }

            case 5: {
                int posisi_141;

                cout << "\nHAPUS PRODUK SKINCARE PADA POSISI TERTENTU" << endl;
                cout << "Masukkan posisi untuk menghapus data: ";
                cin >> posisi_141;
                list.PopPosition(posisi_141);
                cout << "Data berhasil dihapus pada posisi ke-" << posisi_141 << "!" << endl;
                list.Display_141(); 
                break;
            }

            case 6: {
                list.DeleteAll();
                cout << "SEMUA DATA BERHASIL DI HAPUS!" << endl;
                list.Display_141(); 
                break;
            }

            case 7: {
                cout << "\nTAMPILAN DATA PRODUK TOKO SKINCARE PURWOKERTO SEKARANG" << endl;
                list.Display_141(); 
                break;
            }

            case 8: {
                cout << "Terimakasih telah menggunakan program ini!" << endl;
                return 0;
            }

            default: {
                cout << "Pilihan anda tidak valid!" << endl;
                break;
            }
        }
    }

    return 0;
}




```
#### Output:
![SS_Unguided02-1_Laprak3_2311102138_RicoAdePratama_S1IF11D.png](/pertemuan03/Laprak03%20dan%20Output/SS_Unguided02-1_Laprak3_2311102138_RicoAdePratama_S1IF11D.png)
![SS_Unguided02-2_Laprak3_2311102138_RicoAdePratama_S1IF11D.png](/pertemuan03/Laprak03%20dan%20Output/SS_Unguided02-2_Laprak3_2311102138_RicoAdePratama_S1IF11D.png)
![SS_Unguided02-3_Laprak3_2311102138_RicoAdePratama_S1IF11D.png](/pertemuan03/Laprak03%20dan%20Output/SS_Unguided02-3_Laprak3_2311102138_RicoAdePratama_S1IF11D.png)

Kode di atas digunakan untuk membuat program menu, dari implementasi Double Linked List yang memiliki beberapa fungsi untuk menambah, mengurang, mengupdate, dan menampilkan data pada list yang berbasis linked list. Program ini menggunakan struktur data Node yang memiliki atribut produk dan harga. Kelas Double Linked List memiliki beberapa metode: `Push` Menambahkan data di depan list. `PushPosition` Menambahkan data pada posisi tertentu. `Pop` Menghapus data di depan list. `PopPosition` Menghapus data pada posisi tertentu. `Update` Mengupdate data. `DeleteAll` Menghapus semua data. `Display` Menampilkan data. Program ini juga menggunakan beberapa kondisi untuk mengatasi kasus kesalahan, seperti posisi yang tidak valid. Dalam program terdapat pilihan menu interaktif 1. Tambah Data, 2. Hapus Data, 3. Update Data, 4. Tambah Data Urutan tertentu, 5. Hapus Data Urutan tertentu, 6. Hapus Seluruh Data, 7. Tampilkan Data. 8. Exit . Pengguna dapat memilih nomor untuk melakukan salah satu dari tindakan tersebut. 
Seperti contoh pada output, pertama pilih no 4 masukkan produk ke posisi 3 (diantara somethinc dan skintific) tambah nama produk Azarine dan tambah harga 65000. Kedua pilih no 5 menghapuskan produk Wardah dengan masukkan posisi ke-5(sesuai nama produk Wardah). Ketiga pilih no 3 Update Data dengan ubah produk Hanasui menjadi Cleora dan masukkan harga 55000. Lalu trakhir pilih no 7 Tampilkan Hasil dan selesai. lebih jelasnya yang hasil programnya seperti gambar output diatas.

## Kesimpulan
Kesimpulannya, pada modul 3 ini Linked List terdapat dua jenis, yaitu Single Linked List dan Double Linked List. Dengan mempertimbangkan kelebihan dan kekurangan masing-masing, pemilihan antara Single Linked List dan Double Linked List sangat tergantung pada kebutuhan dan karakteristik dari aplikasi yang sedang dibangun.

Single Linked List cocok digunakan ketika:
- Akses data dilakukan secara linear, seperti iterasi dari awal hingga akhir.
- Membutuhkan penggunaan memori yang lebih efisien.
- Operasi yang umumnya dilakukan adalah penambahan atau penghapusan node dari akhir atau awal list.

Double Linked List lebih cocok digunakan ketika:
- Akses data seringkali memerlukan navigasi maju dan mundur, seperti saat penghapusan atau penambahan pada posisi tertentu.
- Kebutuhan akan fleksibilitas dalam traversal data. 
- Efisiensi operasi seperti penghapusan, penambahan, atau pembaruan data lebih penting daripada penggunaan memori.

Dalam prakteknya, terkadang kombinasi dari kedua jenis linked list ini juga digunakan untuk memenuhi kebutuhan spesifik. Misalnya, dapat menggunakan Single Linked List untuk keperluan umum, sementara menggunakan Double Linked List untuk operasi-operasi yang memerlukan navigasi maju dan mundur. Pemilihan jenis linked list haruslah didasarkan pada analisis mendalam terhadap karakteristik aplikasi dan kebutuhan fungsionalnya, serta mempertimbangkan faktor-faktor seperti performa, efisiensi memori, dan kompleksitas implementasi.

## Referensi
[1] DS Malik. C++ programming academia.edu. 2023. https://d1wqtxts1xzle7.cloudfront.net/44550466/malik98092_0538798092_01.01_toc-libre.pdf?1460150743=&response-content-disposition=inline%3B+filename%3DLicensed_to_iChapters_User.pdf&Expires=1711417840&Signature=QUWLkxNCREaUZERtTrNMyVuArAiqfL8gW59W~ig-gMmJ1R2emo2yfmdrdD5Pi7aVTVYCFWPxLAk2r83lsQNM-oALR8mOiDroa1fXQQZoUN5Hy4F~TVXpM1sjheUpOcFfH6A46ps3ldcZPWNPoDZtSXk7dxhUf5~0jmJe1X5yFtSyvfhLDQEQybrF~KOpLZew5gbro5aMP2J2NzRjCAbU-FKWDTs4jiQehla8qeQ0h7bsMPVOIX-EMTouUAu1PAzaa2OD41WS3M38pNFDC9YuN2evzzLSHzJzvJsJTgy9vfDgIraZE8T7j6xnfa8nQMOpDBlfjdUL4hTBOi9enkuwgg__&Key-Pair-Id=APKAJLOHF5GGSLRBV4ZA

[2] Agung Kurniman Putra. Single Linked List. Umitra Bandar Lampung. 2019. https://web.archive.org/web/20220428114131/https://files.osf.io/v1/resources/u6qf7/providers/osfstorage/5cc20527e68786001813664e?format=pdf&action=download&direct&version=1

[3] Anugrah Ananda Nauli Siregar. PENGERTIAN LINKED OBJECT. Umitra Bandar Lampung. 2019. https://www.academia.edu/99621929/Pengertian_Linked_Object