# <h1 align="center">LAPORAN PRAKTIKUM MODUL 4 : LINKED LIST CIRCULAR DAN NON CIRCULAR</h1>
<p align="center">RAMADHIKA PRIMADANA - 2311102141</p>

# Dasar Teori

## Linked list 

Linked List adalah kumpulan elemen yang terhubung melalui pointer. Setiap elemen memiliki pointer yang menyimpan alamat memori, bisa berupa data atau pointer lain. Elemen pertama disebut head, dan jika kosong, head menunjuk ke NULL. Elemen terakhir disebut tail dengan pointer yang menunjuk ke NULL. Linked list memungkinkan penyimpanan data dengan alokasi memori dinamis, dan mudah dalam penambahan serta penghapusan elemen, namun ia memiliki kelemahan dalam akses acak yang lambat dan kebutuhan ruang ekstra untuk pointer. Linked list sering digunakan untuk data yang sering mengalami perubahan dan membutuhkan fleksibilitas dalam operasi penambahan atau penghapusan. Selain itu, linked list juga sering digunakan dalam implementasi struktur data lain seperti stack, queue, dan graph.

Terdapat beberapa jenis linked list, yaitu:
### Single Linked List
1. Single linked list Non Circular
Single linked list Non Circular adalah jenis struktur data linked list yang terdiri dari sejumlah node yang setiap node hanya memiliki satu pointer, yaitu pointer yang digunakan untuk menunjuk ke node selanjutnya dalam urutan linked list, kecuali untuk node terakhir yang disebut sebagai tail. Pada node tail atau node terakhir ini, pointer yang dimilikinya menunjuk ke NULL, menandakan akhir dari linked list tersebut.

2. Single Linked List Circular
Single Linked List Circular adalah suatu jenis linked list di mana setiap node memiliki sebuah field pointer yang menunjuk ke node berikutnya dalam urutan, tetapi dengan satu keistimewaan. Keistimewaan tersebut adalah pointer next dari node terakhir akan kembali menunjuk ke node pertama atau head, sehingga membentuk suatu lingkaran atau sirkuit. Dengan kata lain, dalam Single Linked List Circular, node tail atau node terakhir akan selalu menunjuk kembali ke node head atau node pertama, menghasilkan suatu struktur data yang berputar atau bersirkulasi.

### Double Linked List
1. Double Linked List Non Circular
Double Linked List Non Circular, saat berada pada node yang berfungsi sebagai head atau node pertama dalam linked list, nilai dari pointer prev pada node tersebut akan diatur menjadi NULL. Hal ini dikarenakan node head tidak memiliki node sebelumnya. Sedangkan untuk node yang berfungsi sebagai tail atau node terakhir dalam linked list, nilai dari pointer next pada node tersebut akan diatur untuk menunjuk ke NULL, menandakan akhir dari linked list tersebut.

2. Double Linked List Circular
Double Linked List Circular adalah jenis linked list di mana field pointer-nya terdiri dari dua buah pointer yang bergerak ke dua arah, yaitu prev dan next. Selain itu, pointer next pada Double Linked List Circular akan menunjuk kembali pada elemen tersebut sendiri, menciptakan sebuah pola sirkular. Dengan kata lain, baik pointer next maupun pointer prev pada Double Linked List Circular akan membentuk sebuah loop yang menghubungkan setiap elemen dalam struktur data ini secara berputar.

## Guided 

### 1. [Program Linked List Non Circular]

```C++
#include <iostream>
using namespace std;

// Deklarasi struct node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah kosong
bool isEmpty() {
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah depan
void insertDepan(int nilai) {
    // Buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah belakang
void insertBelakang(int nilai) {
    // Buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung jumlah list
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;

        // Transversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus depan
void hapusDepan() {
    Node *hapus;
    if (!isEmpty()) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong" << endl;
    }
}

// Hapus tengah
void hapusTengah(int posisi) {
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                sebelum = bantu;
            }
            if (nomor == posisi) {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah tengah
void ubahTengah(int data, int posisi) {
    Node *bantu;
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus semua list
void clearList() {
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan list
void tampil() {
    Node *bantu;
    bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
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
    hapusTengah(2);
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

Kode di atas digunakan untuk mengimplementasikan program data dalam bentuk single linked list non-circular. Program ini menggunakan struct Node untuk menyimpan data Nama dan NIM mahasiswa. Program ini menggunakan struct Node yang memiliki data dan pointer ke node selanjutnya. Setiap node juga memiliki pointer ke node awal dan node terakhir dari Linked List. Program ini juga menggunakan input-output dan looping untuk menampilkan menu pengguna dan mengelola pilihan pengguna. Pengguna dapat menambah, mengubah, dan menghapus data dari Linked List sesuai dengan pilihan yang dipilih. Program akan berjalan hingga pengguna memilih untuk keluar. Dalam Program ini berisi tentang untuk menyimpan, mengubah, dan menghapus data Nama dan NIM mahasiswa dalam Linked List.


### 2. [Program Linked List Circular]

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
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
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```

Kode di atas digunakan untuk mengimplementasikan program yang menggunakan single linked list circular. Dalam program ini, memiliki sebuah struktur(struct) yang dinamakan Node dengan berisi informasi data dalam bentuk string dan pointer yang menunjuk ke node berikutnya. Kemudian, mendeklarasikan struktur Node dengan informasi string data dan pointer next. Dan mendeklarasikan beberapa variabel seperti head, tail, baru, bantu, dan hapus yang semuanya bertipe pointer Node. selanjutnya, membuat beberapa fungsi untuk menambahkan data ke dalam list, baik di bagian depan, belakang, maupun di tengah list. Selain itu, ada juga fungsi untuk menghapus data dari list, menghitung jumlah data, menampilkan seluruh data, dan menghapus semua data dalam list. Kemudian program memanggil fungsi-fungsi tersebut di dalam fungsi main. Hasil tampilan output program di atas adalah:
-Ayam
-Bebek Ayam
-Bebek Ayam Cicak
-Bebek Ayam Cicak Domba
-Bebek Ayam Cicak
-Ayam Cicak
-Ayam Sapi Cicak
-Ayam Cicak

## Unguided 

### 1. [Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user.
![Soal Unguided1_Laprak4_ke-1](/pertemuan04/LAPRAK04/Soal%20Unguided1_Laprak4_ke-1.png)![Soal Unguided1_Laprak4_ke-2](/pertemuan04/LAPRAK04/Soal%20Unguided1_Laprak4_ke-2.png)![Soal Unguided1_Laprak4_ke-3](/pertemuan04/LAPRAK04/Soal%20Unguided1_Laprak4_ke-3.png)![Soal Unguided1_Laprak4_ke-4](/pertemuan04/LAPRAK04/Soal%20Unguided1_Laprak4_ke-4.png)![Soal Unguided1_Laprak4_ke-5](/pertemuan04/LAPRAK04/Soal%20Unguided1_Laprak4_ke-5.png)]

```C++
// LAPRAK 4 : UNGUIDED 
// RAMADHIKA PRIMADANA
// 2311102131
// S1 IF-11-D

// Program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa
#include <iostream>
#include <iomanip> //untuk mengatur format output, seperti mengatur presisi desimal, lebar bidang, dan tata letak output

using namespace std;

// Deklarasi Struct Node
struct Node
{
    string Nama_141; // Menyimpan Nama
    string NIM_141; // Menyimpan NIM
    Node *next_141; // Ini adalah pointer ke struct Node untuk menyimpan referensi ke node berikutnya dalam linked list
};

Node *head_141; // Ini adalah pointer ke struct Node untuk menyimpan referensi ke node awal dari linked list
Node *tail_141; // Ini adalah pointer ke struct Node untuk menyimpan referensi ke node terakhir dari linked list

// Inisialisasi Node
void init_141()
{
    head_141 = NULL;
    tail_141 = NULL;
}

// Pengecekan apakah linked list kosong atau tidak
bool isEmpty_141()
{
    if (head_141 == NULL)
        return true;
    else
        return false;
}

// Tambah Node di depan linked list
void insertDepan_141(string Nama_141, string NIM_141) 
{
    // Buat Node baru_141
    Node *baru_141 = new Node; // Jika Linked List masih kosong, baru_141 akan menjadi node awal dan node terakhir dalam linked list
    baru_141->Nama_141 = Nama_141;
    baru_141->NIM_141 = NIM_141;
    baru_141->next_141 = NULL;
    if (isEmpty_141() == true)
    {
        head_141 = tail_141 = baru_141;
        tail_141->next_141 = NULL;
    }
    else
    {
        baru_141->next_141 = head_141;
        head_141 = baru_141;
    }
}

// Tambah Node di belakang linked list
void insertBelakang_141(string Nama_141, string NIM_141)
{
    // Buat Node baru_141
    Node *baru_141 = new Node;
    baru_141->Nama_141 = Nama_141;
    baru_141->NIM_141 = NIM_141;
    baru_141->next_141 = NULL;
    if (isEmpty_141() == true)
    {
        head_141 = tail_141 = baru_141;
        tail_141->next_141 = NULL;
    }
    else
    {
        tail_141->next_141 = baru_141;
        tail_141 = baru_141;
    }
}

// Menghitung jumlah Node dalam linked list
int hitungList_141()
{
    Node *hitung_141; // Untuk menghitung data
    hitung_141 = head_141;
    int jumlah_141 = 0; // Untuk mengetahui jumlah data
    while (hitung_141 != NULL)
    {
        jumlah_141++;
        hitung_141 = hitung_141->next_141;
    }
    return jumlah_141;
}

// Tambah Node di posisi_141 tertentu dalam linked list
void insertTengah_141(string Nama_141, string NIM_141, int posisiNama_141)
{
    if (posisiNama_141 < 1 || posisiNama_141 > hitungList_141()) // posisiNama_141 untuk mencari posisi nama
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisiNama_141 == 1)
    {
        cout << "Posisi bukan posisi_141 tengah" << endl;
    }
    else
    {
        Node *baru_141, *bantu_141; // Untuk membantu dalam menjalankan program
        baru_141 = new Node();
        baru_141->Nama_141 = Nama_141;
        baru_141->NIM_141 = NIM_141;

        // traversal
        bantu_141 = head_141;
        int nomor_141 = 1;
        while (nomor_141 < posisiNama_141 - 1) // nomor_141 untuk mengetahui nomor posisi
        {
            bantu_141 = bantu_141->next_141;
            nomor_141++;
        }

        baru_141->next_141 = bantu_141->next_141;
        bantu_141->next_141 = baru_141;
    }
}

// Hapus Node di depan linked list
void hapusDepan_141()
{
    Node *hapus_141; // Untuk menghapus data
    if (isEmpty_141() == false)
    {
        if (head_141->next_141 != NULL)
        {
            hapus_141 = head_141;
            head_141 = head_141->next_141;
            delete hapus_141;
        }
        else
        {
            head_141 = tail_141 = NULL;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Node di belakang linked list
void hapusBelakang_141()
{
    Node *hapus_141; 
    Node *bantu_141; 
    if (isEmpty_141() == false)
    {
        if (head_141 != tail_141)
        {
            hapus_141 = tail_141;
            bantu_141 = head_141;
            while (bantu_141->next_141 != tail_141)
            {
                bantu_141 = bantu_141->next_141;
            }
            tail_141 = bantu_141;
            tail_141->next_141 = NULL;
            delete hapus_141;
        }
        else
        {
            head_141 = tail_141 = NULL;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Node di posisi tertentu dalam linked list
void hapusTengah_141(int posisi_141)
{
    Node *bantu_141, *hapus_141, *sebelum_141;
    if (posisi_141 < 1 || posisi_141 > hitungList_141()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi_141 == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor_141 = 1;
        bantu_141 = head_141;
        while (nomor_141 <= posisi_141) {
            if (nomor_141 == posisi_141 - 1) {
                sebelum_141 = bantu_141;
            } 
            if (nomor_141 == posisi_141) {
                hapus_141 = bantu_141;
            }
            bantu_141 = bantu_141->next_141;
            nomor_141++;
        }
        sebelum_141->next_141 = bantu_141;
        delete hapus_141;
    }
}

/// Ubah Node di depan linked list
void ubahDepan_141(string Nama_141, string NIM_141)
{
    if (isEmpty_141() == false)
    {
        head_141->Nama_141 = Nama_141;
        head_141->NIM_141 = NIM_141;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Node di belakang linked list
void ubahBelakang_141(string Nama_141, string NIM_141)
{
    if (isEmpty_141() == 0)
    {
        tail_141->Nama_141 = Nama_141;
        tail_141->NIM_141 = NIM_141;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Node di posisi tertentu dalam linked list
void ubahTengah_141(string Nama_141, string NIM_141, int posisiNama_141)
{
    Node *bantu_141;
    if (isEmpty_141() == 0)
    {
        if (posisiNama_141 < 1 || posisiNama_141 > hitungList_141())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisiNama_141 == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu_141 = head_141;
            int nomor_141 = 1;
            while (nomor_141 < posisiNama_141)
            {
                bantu_141 = bantu_141->next_141;
                nomor_141++;
            }
            bantu_141->Nama_141 = Nama_141;
            bantu_141->NIM_141 = NIM_141;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Menghapus seluruh Node dalam linked list
void clearList_141() {
    Node *bantu_141, *hapus_141;
    bantu_141 = head_141;
    while (bantu_141 != NULL) {
        hapus_141 = bantu_141;
        bantu_141 = bantu_141->next_141;
        delete hapus_141;
    }
    head_141 = tail_141 = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Menampilkan seluruh data dalam linked list
void tampilList_141()
{
    Node *bantu_141;
    bantu_141 = head_141;
    if (isEmpty_141() == false)
    {
        cout << "============================================\n";
        cout << "|              DATA MAHASISWA              |\n";
        cout << "============================================\n";
        cout << "|        NAMA        |         NIM         |\n";
        cout << "============================================\n";
        while (bantu_141 != NULL)
        {
            cout << "| " << setw(19) << left << bantu_141->Nama_141;
            cout << "| " << setw(19) << left << bantu_141->NIM_141 << " |\n";
            bantu_141 = bantu_141->next_141;
        }
        cout << "============================================\n";
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init_141();
    int Pilih_141, posisiNama_141;
    string Nama_141, NIM_141;
    
    // Program akan terus berjalan hingga pengguna memilih untuk keluar (Pilih_141 = 0)
    do
    {
        // Menu utama
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1.  Tambah Depan\n";
        cout << "2.  Tambah Belakang\n";
        cout << "3.  Tambah Tengah\n";
        cout << "4.  Ubah Depan\n";
        cout << "5.  Ubah Belakang\n";
        cout << "6.  Ubah Tengah\n";
        cout << "7.  Hapus Depan\n";
        cout << "8.  Hapus Belakang\n";
        cout << "9.  Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. TAMPILKAN\n";
        cout << "0.  KELUAR\n";
        cout << "Pilih Operasi: ";
        cin >> Pilih_141;
        cout << endl;
        
        // Melakukan operasi berdasarkan pilihan pengguna
        switch (Pilih_141)
        {
            // Bentuk Macam-macam Pilihan Menu
            case 1:
                cout << "===================================================\n";
                cout << "<<<<<<<<<<<<<<<<<<< TAMBAH DEPAN >>>>>>>>>>>>>>>>>>\n";
                cout << "===================================================\n";
                cout << "Masukkan Nama : ";
                cin >> Nama_141;
                cout << "Masukkan NIM  : ";
                cin >> NIM_141;
                insertDepan_141(Nama_141, NIM_141);
                cout << "---------------------------------------------------\n";
                cout << "Data telah ditambahkan\n";
                cout << "===================================================\n";
                break;
            case 2:
                cout << "===================================================\n";
                cout << "<<<<<<<<<<<<<<<<<< TAMBAH BELAKANG >>>>>>>>>>>>>>>>\n";
                cout << "===================================================\n";
                cout << "Masukkan Nama : ";
                cin >> Nama_141;
                cout << "Masukkan NIM  : ";
                cin >> NIM_141;
                insertBelakang_141(Nama_141, NIM_141);
                cout << "---------------------------------------------------\n";
                cout << "Data telah ditambahkan\n";
                cout << "===================================================\n";
                break;
            case 3:
                cout << "===================================================\n";
                cout << "<<<<<<<<<<<<<<<<<< TAMBAH TENGAH >>>>>>>>>>>>>>>>>>\n";
                cout << "===================================================\n";
                cout << "Masukkan Nama   : ";
                cin >> Nama_141;
                cout << "Masukkan NIM    : ";
                cin >> NIM_141;
                cout << "Masukkan Posisi : ";
                cin >> posisiNama_141;
                insertTengah_141(Nama_141, NIM_141, posisiNama_141);
                cout << "---------------------------------------------------\n";
                cout << "Data telah ditambahkan pada posisi ke-" << posisiNama_141 << endl;
                cout << "===================================================\n";
                break;
            case 4:
                cout << "===================================================\n";
                cout << "<<<<<<<<<<<<<<<<<<<< UBAH DEPAN >>>>>>>>>>>>>>>>>>>\n";
                cout << "===================================================\n";
                cout << "Masukkan Nama : ";
                cin >> Nama_141;
                cout << "Masukkan NIM  : ";
                cin >> NIM_141;
                ubahDepan_141(Nama_141, NIM_141);
                cout << "---------------------------------------------------\n";
                cout << "Data telah diubah\n";
                cout << "===================================================\n";
                break;
            case 5:
                cout << "===================================================\n";
                cout << "<<<<<<<<<<<<<<<<<<< UBAH BELAKANG >>>>>>>>>>>>>>>>>\n";
                cout << "===================================================\n";
                cout << "Masukkan Nama : ";
                cin >> Nama_141;
                cout << "Masukkan NIM : ";
                cin >> NIM_141;
                ubahBelakang_141(Nama_141, NIM_141);
                cout << "---------------------------------------------------\n";
                cout << "Data telah diubah\n";
                cout << "===================================================\n";
                break;
            case 6:
                cout << "===================================================\n";
                cout << "<<<<<<<<<<<<<<<<<<< UBAH TENGAH >>>>>>>>>>>>>>>>>>>\n";
                cout << "===================================================\n";
                cout << "Masukkan Nama   : ";
                cin >> Nama_141;
                cout << "Masukkan NIM    : ";
                cin >> NIM_141;
                cout << "Masukkan Posisi : ";
                cin >> posisiNama_141;
                ubahTengah_141(Nama_141, NIM_141, posisiNama_141);
                cout << "---------------------------------------------------\n";
                cout << "Data telah diubah\n";
                cout << "===================================================\n";
                break;
            case 7:
                cout << "===================================================\n";
                cout << "<<<<<<<<<<<<<<<<<<< HAPUS DEPAN >>>>>>>>>>>>>>>>>>>\n";
                cout << "===================================================\n";
                hapusDepan_141();
                cout << "---------------------------------------------------\n";
                cout << "Data berhasil dihapus\n";
                cout << "===================================================\n";
                break;
            case 8:
                cout << "===================================================\n";
                cout << "<<<<<<<<<<<<<<<<<< HAPUS BELAKANG >>>>>>>>>>>>>>>>\n";
                cout << "===================================================\n";
                hapusBelakang_141();
                cout << "---------------------------------------------------\n";
                cout << "Data berhasil dihapus\n";
                cout << "===================================================\n";
                break;
            case 9:
                cout << "===================================================\n";
                cout << "<<<<<<<<<<<<<<<<<< TAMBAH TENGAH >>>>>>>>>>>>>>>>>>\n";
                cout << "===================================================\n";
                cout << "Masukkan posisi  : ";
                cin >> posisiNama_141;
                hapusTengah_141(posisiNama_141);
                cout << "---------------------------------------------------\n";
                cout << "Data berhasil dihapus\n";
                cout << "===================================================\n";
                break;
            case 10:
                clearList_141();
                break;
            case 11:
                tampilList_141();
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Maaf, pilihan tidak tersedia!\n";
        }
    } while (Pilih_141 != 0);

    return 0;
}




```
#### Output:
![ss_unguided1_laprak4.141_ke-1.png](/PERTEMUAN4/LAPRAK4/modul4.unguided1.1.141_png)
![ss_unguided1_laprak4.141_ke-2.png](/PERTEMUAN4/LAPRAK4/modul4.unguided1.2_141.png)
![ss_unguided1_laprak4.141_ke-3.png](/PERTEMUAN4/LAPRAK4/modul4.unguided1.3_141.png)
![ss_unguided1_laprak4.141_ke-4.png](/PERTEMUAN4/LAPRAK4/modul4.unguided1.4_141.png)
![ss_unguided1_laprak4.141_ke-5.png](/PERTEMUAN4/LAPRAK4/modul4.unguided1.5_141.png)


### 2. [Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![Soal Unguided2_Laprak4.141](/PERTEMUAN4/LAPRAK4/Soal%201(1).PNG)]


#### Output:
![ss_unguided2_laprak4.141_ke-1.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.1_141.png) 
![ss_unguided2_laprak4.141_ke-2.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.2_141.png)   
![ss_unguided2_laprak4.141_ke-3.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.3_141.png)
![ss_unguided2_laprak4.141_ke-4.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.4_141.png)   
![ss_unguided2_laprak4.141_ke-5.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.5_141.png)   
![ss_unguided2_laprak4.141_ke-6.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.6_141.png)   
![ss_unguided2_laprak4.141_ke-7.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.7._141.png)
![ss_unguided2_laprak4.141_ke-8.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.8_141.png)   
![ss_unguided2_laprak4.141_ke-9.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.9_141.png)   
![ss_unguided2_laprak4.141_ke-10.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.10_141.png)  
![ss_unguided2_laprak4.141_ke-11.png](/PERTEMUAN4/LAPRAK4/modul4.ungided2.11_141.png) 


### 3. [Lakukan perintah berikut: 
![Soal Unguided3_Laprak4](/PERTEMUAN4/LAPRAK4/Soal%20Unguided3_Laprak4.png)]


#### Output:
![ss_unguided3_laprak4.141_ke-1.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.1_141.png)
![ss_unguided3_laprak4.141_ke-2.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.2_141.png)
![ss_unguided3_laprak4.141_ke-3.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.3_141.png)
![ss_unguided3_laprak4.141_ke-4.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.4_141.png)
![ss_unguided3_laprak4.141_ke-5.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.5_141.png)
![ss_unguided3_laprak4.141_ke-6.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.6_141.png)
![ss_unguided3_laprak4.141_ke-7.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.7_141.png)
![ss_unguided3_laprak4.141_ke-8.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.8_141.png)
![ss_unguided3_laprak4.141_ke-9.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.9_141.png)
![ss_unguided3_laprak4.141_ke-10.png](/PERTEMUAN4/LAPRAK4/modul4.ungided3.10_141.png)

Kode di atas digunakan untuk implementasi Linked List Non-Circular untuk membuat program menu, dengan menyimpan Nama dan NIM mahasiswa. Program ini menggunakan struct Node yang memiliki data Nama dan NIM, serta pointer ke node selanjutnya dalam linked list dengan sangat kompleks. Program ini memiliki beberapa fungsi untuk menyimpan, mengubah, dan menghapus data dalam linked list. Berikut fungsi yang tersedia adalah:

init_138(): Fungsi untuk memulihkan linked list ke keadaan awal, dengan mengatur pointer ke node awal dan node terakhir ke NULL.
isEmpty_138(): Fungsi untuk mengecek apakah linked list kosong atau tidak.
insertDepan_138(): Fungsi untuk menambah data di depan linked list.
insertBelakang_138(): Fungsi untuk menambah data di belakang linked list.
hitungList_138(): Fungsi untuk menghitung jumlah node dalam linked list.
insertTengah_138(): Fungsi untuk menambah data di posisi tertentu dalam linked list.
hapusDepan_138(): Fungsi untuk menghapus data di depan linked list.
hapusBelakang_138(): Fungsi untuk menghapus data di belakang linked list.
hapusTengah_138(): Fungsi untuk menghapus data di posisi tertentu dalam linked list.
ubahDepan_138(): Fungsi untuk mengubah data di depan linked list.
ubahBelakang_138(): Fungsi untuk mengubah data di belakang linked list.
ubahTengah_138(): Fungsi untuk mengubah data di posisi tertentu dalam linked list.
clearList_138(): Fungsi untuk menghapus semua data dalam linked list.
tampilList_138(): Fungsi untuk menampilkan data dalam linked list.

Program ini menggunakan input-output dan looping untuk menampilkan menu pengguna dengan mengelola pilihan atau inputan dari pengguna. Pengguna dapat menambah, mengubah, dan menghapus data dalam linked list sesuai dengan pilihan yang dipilih. Program akan berjalan hingga pengguna memilih untuk keluar (Pilih_138 = 0). Program ini dapat digunakan untuk menyimpan, mengubah, dan menghapus data Nama dan NIM mahasiswa dalam linked list. 

## Kesimpulan
Kesimpulannya, pada modul 4 ini Linked List terdapat banyak jenis, yaitu Single Linked List Circular dan Non-Circular, serta Double Linked List Circular dan Non-Circular. Linked list adalah kumpulan elemen yang saling terhubung melalui pointer

- Single Linked List Circular: Tidak ada simpul null, traversal tidak memiliki batas akhir, namun memerlukan penanganan khusus agar tidak terjebak dalam pengulangan tak terbatas.
- Single Linked List Non-Circular: Sederhana dalam implementasi, efisien dalam penggunaan memori, namun traversal terbatas ke depan saja.
- Double Linked List Circular: Memungkinkan traversal dari mana saja dalam lingkaran, dan operasi penghapusan/penambahan di ujung list lebih efisien, namun juga memerlukan penanganan khusus dan penggunaan memori yang lebih besar.
- Double Linked List Non-Circular: Lebih fleksibel dengan traversal maju dan mundur, namun memerlukan lebih banyak ruang memori dan implementasi yang lebih rumit.

Dalam pemilihan jenis linked list, pertimbangkan kebutuhan spesifik antara efisiensi ruang dan waktu operasi. Circular linked list Cocok untuk navigasi data maju dan mundur terus menerus, serta lebih fleksibel dalam hal navigasi. Non-circular linked list Lebih sederhana dan efisien dalam hal memori.

## Referensi
[1] Dr. Joseph Teguh Santoso., Struktur Data dan ALgoritma. Semarang: Yayasan Prima Agus Teknik, 2021.
[2] Rafsanjani, Malik Akbar Hashemi. "Implementasi Algoritma Pengurutan General Purpose dan Berbasis Komparasi untuk Data Berkategori dalam Waktu Linier Tanpa Paralelisasi" (2021).
