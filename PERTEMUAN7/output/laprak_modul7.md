# <h1 align="center">LAPORAN PRAKTIKUM MODUL 7 : QUEUE</h1>
<p align="center">RAMADHIKA PRIMADANA - 2311102141</p>

# Dasar Teori

## A. PENGERTIAN QUEUE
Queue adalah struktur data yang memungkinkan penyimpanan dan pengambilan data dengan prinsip FIFO (First-In First-Out). Artinya, data yang pertama dimasukkan ke dalam queue akan menjadi data yang pertama pula untuk dikeluarkan. Konsep ini serupa dengan antrian pada kehidupan sehari-hari di mana orang yang datang lebih dulu akan dilayani terlebih dahulu. Dalam implementasinya, queue dapat dibangun menggunakan array atau linked list. Struktur data queue memiliki dua pointer utama, yaitu front dan rear. Front mengarah ke elemen pertama dalam queue, sementara rear mengarah ke elemen terakhir.

## B. PERBEDAAN QUEUE DENGAN STRUKTUR DATA YANG LAIN
Perbedaan mendasar antara queue dan struktur data lainnya seperti stack terletak pada aturan penambahan dan penghapusan elemen. Pada stack, penambahan dan penghapusan elemen dilakukan di satu ujung saja. Namun, pada queue, operasi tersebut dilakukan pada ujung yang berbeda karena perubahan data selalu mengacu pada head. Oleh karena itu, hanya terdapat satu jenis operasi untuk menambah atau menghapus elemen, yaitu Enqueue dan Dequeue. Saat Enqueue, elemen ditambahkan setelah elemen terakhir dalam queue. Sedangkan saat Dequeue, head digeser untuk menunjuk pada elemen selanjutnya dalam antrian.

## C. JENIS-JENIS PADA OPERASI QUEUE
Operasi pada Queue melibatkan serangkaian fungsi yang memberikan kita kemampuan untuk berinteraksi dengan struktur data ini. Mari kita jabarkan beberapa operasi dasar yang dapat kita lakukan pada Queue:

### 1. Berdasarkan Implementasinya

#### Linear/Simple Queue: Elemen-elemen data disusun dalam barisan linear dan penambahan serta penghapusan elemen hanya terjadi pada dua ujung barisan. Contoh Linear Queue:

##### Enqueue (Tambahkan Elemen):
- Elemen pertama: 1
- Elemen kedua: 2
- Elemen ketiga: 3
- Elemen keempat: 4
- Elemen kelima: 5
##### Dequeue (Hapus Elemen):
- Elemen pertama: 1 (dihapus)
- Elemen yang tersisa: 2, 3, 4, 5
##### Enqueue (Tambahkan Elemen):
- Elemen pertama: 2 (sebelumnya)
- Elemen kedua: 6
- Elemen ketiga: 7
- Elemen keempat: 8
- Elemen kelima: 9
##### Dequeue (Hapus Elemen):
- Elemen pertama: 2 (dihapus)
- Elemen yang tersisa: 3, 4, 5, 6, 7, 8, 9

#### Circular Queue: Mirip dengan jenis linear, tetapi ujung-ujung barisan terhubung satu sama lain, menciptakan struktur antrean yang berputar. Contoh Circular Queue:

##### Enqueue (Tambahkan Elemen):
- Elemen pertama: 1
- Elemen kedua: 2
- Elemen ketiga: 3
- Elemen keempat: 4
- Elemen kelima: 5
##### Dequeue (Hapus Elemen):
- Elemen pertama: 1 (dihapus)
- Elemen yang tersisa: 2, 3, 4, 5
##### Enqueue (Tambahkan Elemen):
- Elemen pertama: 2 (sebelumnya)
- Elemen kedua: 6
- Elemen ketiga: 7
- Elemen keempat: 8
- Elemen kelima: 9
##### Dequeue (Hapus Elemen):
- Elemen pertama: 2 (dihapus)
- Elemen yang tersisa: 3, 4, 5, 6, 7, 8, 9
##### Enqueue (Tambahkan Elemen):
- Elemen pertama: 3 (sebelumnya)
- Elemen kedua: 10
- Elemen ketiga: 11
- Elemen keempat: 12
- Elemen kelima: 13
##### Dequeue (Hapus Elemen):
- Elemen pertama: 3 (dihapus)
- Elemen yang tersisa: 4, 5, 6, 7, 8, 9, 10, 11, 12, 13

### 2. Berdasarkan Penggunaan

#### Priority Queue: Setiap elemen memiliki prioritas tertentu. Elemen dengan prioritas tertinggi akan diambil terlebih dahulu.Elemen dengan prioritas rendah akan dihapus setelah elemen dengan prioritas tinggi. Contoh Priority Queue:

##### Enqueue (Tambahkan Elemen):
- Elemen pertama: 1 (prioritas tinggi)
- Elemen kedua: 3 (prioritas sedang)
- Elemen ketiga: 2 (prioritas rendah)
- Elemen keempat: 4 (prioritas tinggi)
- Elemen kelima: 5 (prioritas rendah)
##### Dequeue (Hapus Elemen):
- Elemen pertama: 1 (dihapus prioritas tinggi)
- Elemen yang tersisa: 3, 2, 4, 5

#### Double-ended Queue (Dequeue): Elemen dapat ditambahkan atau dihapus dari kedua ujung antrean Contoh Double Ended Queue (Dequeue):

##### Enqueue (Tambahkan Elemen):
- Elemen pertama: 1
- Elemen kedua: 2
- Elemen ketiga: 3
- Elemen keempat: 4
- Elemen kelima: 5
##### Dequeue (Hapus Elemen):
- Elemen pertama: 1 (dihapus urutan paling depan)
- Elemen yang tersisa: 2, 3, 4, 5
##### Dequeue (Hapus Elemen):
- Elemen pertama: 5 (dihapus urutan paling ujung belakang)
- Elemen yang tersisa: 2, 3, 4.

## D. PROSEDUR OPERASI PADA QUEUE:
- enqueue() :menambahkan data kedalam queue.
- dequeue() :mengeluarkan data dari queue.
- peek() :mengambil data dari queue tanpa menghapusnya.
- isEmpty() :mengecek apakah queue kosong atau tidak.
- isFull() :mengecek apakah queue penuh atau tidak.
- size() :menghitung jumlah elemen dalam queue. 

## E. CONTOH ILLUSTRASI QUEUE
![CONTOH ILLUSTRASI QUEUE.png](/PERTEMUAN10/output/Contoh%20Ilustrasi%20Queue_141.png)


## Guided 

### 1. [Program Operasi Queue]

```C++
// LAPRAK 7 : UNGUIDED 1
// Ramadhika Primadana
// 2311102141
// S1 IF-11-D

// Program penerapan konsep queue pada bagian guided dari array menjadi linked list
#include <iostream>
using namespace std;

const int maksimalQueue_141 = 5;  // Maksimal antrian adalah 5

// Node untuk menyimpan data_141 dan pointer ke node berikutnya
struct Node {
    string data_141;
    Node* next_141;
};

class Queue {
private:
    Node* front_141; // Node depan dari antrian
    Node* rear_141;  // Node belakang dari antrian

public: 
    Queue() { // Konstruktor untuk menginisialisasi antrian kosong
        front_141 = nullptr;
        rear_141 = nullptr;
    }

    // Fungsi untuk menambahkan data_141 ke antrian
    void enqueue_141(const string& data_141) {
        Node* newNode_141 = new Node;
        newNode_141->data_141 = data_141;
        newNode_141->next_141 = nullptr;
        
        // Jika antrian kosong
        if (isEmpty_141()) { // Jika antrian kosong maka front_141 dan rear_141 menunjuk ke newNode_141 yang baru dibuat 
            front_141 = rear_141 = newNode_141;
        } else { // Jika antrian tidak kosong maka rear_141 menunjuk ke newNode_141 yang baru dibuat
            rear_141->next_141 = newNode_141;
            rear_141 = newNode_141;
        }
        
        cout << ">> " << data_141 << " telah ditambahkan ke dalam antrian." << endl;
    }

    // Fungsi untuk menghapus data_141 dari antrian
    void dequeue_141() {
        if (isEmpty_141()) { // Jika antrian kosong maka tampilkan pesan "Antrian kosong" dan kembalikan nilai void
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* temp_141 = front_141; // Simpan node front_141 ke dalam variabel temp_141 untuk dihapus nantinya 
        front_141 = front_141->next_141; // Geser front_141 ke node selanjutnya 

        cout << ">> " << temp_141->data_141 << " telah dihapus dari antrian." << endl; // Tampilkan data_141 yang dihapus dari antrian 
        delete temp_141; // Hapus node yang disimpan di variabel temp_141

        // Jika setelah penghapusan antrian menjadi kosong
        if (front_141 == nullptr) {
            rear_141 = nullptr;
        }
    }

    // Fungsi untuk menampilkan seluruh antrian
    void displayQueue_141() {
        if (isEmpty_141()) { // Jika antrian kosong maka tampilkan pesan "Data antrian:" dan tampilkan pesan "(kosong)"
            cout << "\n[2141] Data Antrian :" << endl;
            for (int i_141 = 0; i_141 < maksimalQueue_141; i_141++) {
                cout << i_141 + 1 << ". (kosong)" << endl;
            }
        } else { // Jika antrian tidak kosong maka tampilkan data_141 antrian yang ada
            cout << "\n[2141] Data Antrian :" << endl;
            Node* current_141 = front_141;
            int i_141 = 1;
            while (current_141 != nullptr) { // Selama current_141 tidak menunjuk ke nullptr maka tampilkan data_141 antrian yang ada 
                cout << i_141 << ". " << current_141->data_141 << endl;
                current_141 = current_141->next_141;
                i_141++;
            }
            for (; i_141 <= maksimalQueue_141; i_141++) { // Tampilkan pesan "(kosong)" untuk antrian yang kosong 
                cout << i_141 << ". (kosong)" << endl;
            }
        }
    }

    // Fungsi untuk memeriksa apakah antrian kosong
    bool isEmpty_141() {
        return front_141 == nullptr;
    }

    // Fungsi untuk mengembalikan jumlah elemen dalam antrian
    int countQueue_141() {
        int count = 0;
        Node* current_141 = front_141;
        while (current_141 != nullptr) { // Selama current_141 tidak menunjuk ke nullptr maka hitung jumlah elemen dalam antrian
            count++;
            current_141 = current_141->next_141;
        }
        return count; // Kembalikan jumlah elemen dalam antrian
    }

    // Fungsi untuk menghapus semua elemen dalam antrian
    void clearQueue_141() {
        while (!isEmpty_141()) { // Selama antrian tidak kosong maka hapus elemen dalam antrian
            dequeue_141(); // Hapus elemen dalam antrian 
        } 
        cout << "Antrian telah dibersihkan." << endl;
    }
};

int main() {
    Queue queue; // Buat objek queue dari class Queue
    queue.enqueue_141("Ramadhika Primadana");
    queue.enqueue_141("ain");
    queue.displayQueue_141();
    cout << "[2141] Jumlah Antrian = " << queue.countQueue_141() << endl;
    queue.dequeue_141();
    queue.displayQueue_141();
    cout << "[2141] Jumlah Antrian = " << queue.countQueue_141() << endl;
    queue.dequeue_141();
    queue.displayQueue_141();
    cout << "[2141] Jumlah Antrian = " << queue.countQueue_141() << endl;

    return 0;
}


Kode di atas digunakan untuk mengimplementasikan program sederhana dari struktur data queue menggunakan array dalam bahasa C++. Program ini memungkinkan penambahan dan penghapusan elemen dari antrian serta operasi lainnya seperti melihat jumlah elemen dan menghapus semua elemen dalam antrian. Deskripsi singkat fungsi utama:
- isFull(): Memeriksa apakah antrian penuh atau tidak.
- isEmpty(): Memeriksa apakah antrian kosong atau tidak.
- enqueueAntrian(string data): Menambahkan elemen ke dalam antrian.
- dequeueAntrian(): Menghapus elemen dari antrian.
- countQueue(): Menghitung jumlah elemen dalam antrian.
- clearQueue(): Menghapus semua elemen dari antrian.
- viewQueue(): Menampilkan elemen-elemen dalam antrian.

  Fungsi-fungsi ini digunakan dalam fungsi main() untuk melakukan operasi-operasi pada antrian, seperti menambahkan elemen, menampilkan antrian, menghitung jumlah elemen, menghapus elemen, dan menghapus semua elemen dari antrian.

#### Hasil dari output program diatas seperti :
![ss_Unguided2_Laprak7_2311102141_RamadhikaPrimadana](/PERTEMUAN7/output/modul7.unguided1.1_141.png)


## Unguided 

### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]

```C++
// LAPRAK 7 : UNGUIDED 2
// Ramadhika Primadana
// 2311102141
// S1 IF-11-D

// Program dari nomor 1, membuat konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa
#include <iostream>
#include <string>

using namespace std;

const int maksimalQueue_141 = 5;  // Maksimal antrian adalah 5

// Node untuk menyimpan data dan pointer ke node berikutnya
struct Node {
    string Nama_141;
    string NIM_141;
    Node* next_141;
};

class Queue {
private:
    Node* front_141; // Node depan dari antrian
    Node* rear_141;  // Node belakang dari antrian

public: 
    Queue() { // Konstruktor untuk menginisialisasi antrian kosong
        front_141 = nullptr;
        rear_141 = nullptr;
    }

    // Fungsi untuk menambahkan data ke antrian
    void enqueue_141(const string& Nama_141, const string& NIM_141) {
        Node* newNode_141 = new Node;
        newNode_141->Nama_141 = Nama_141;
        newNode_141->NIM_141 = NIM_141;
        newNode_141->next_141 = nullptr;
        
        // Jika antrian kosong
        if (isEmpty_141()) { // Jika antrian kosong maka front_141 dan rear_141 menunjuk ke newNode_141 yang baru dibuat 
            front_141 = rear_141 = newNode_141;
        } else { // Jika antrian tidak kosong maka rear_141 menunjuk ke newNode_141 yang baru dibuat
            rear_141->next_141 = newNode_141;
            rear_141 = newNode_141;
        }
        
        cout << ">> Mahasiswa dengan Nama: " << newNode_141->Nama_141 << ", dan NIM: " << newNode_141->NIM_141 << " telah ditambahkan ke dalam antrian." << endl;
    }

    // Fungsi untuk menghapus data dari antrian
    void dequeue_141() {
        if (isEmpty_141()) { // Jika antrian kosong maka tampilkan pesan "Antrian kosong" dan kembalikan nilai void
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* temp_141 = front_141; // Simpan node front_141 ke dalam variabel temp_141 untuk dihapus nantinya 
        front_141 = front_141->next_141; // Geser front_141 ke node selanjutnya 

        cout << ">> Mahasiswa dengan Nama: " << temp_141->Nama_141 << ", dan NIM: " << temp_141->NIM_141 << " telah dihapus dari antrian." << endl; // Tampilkan data mahasiswa yang dihapus dari antrian 
        delete temp_141; // Hapus node yang disimpan di variabel temp_141

        // Jika setelah penghapusan antrian menjadi kosong
        if (front_141 == nullptr) {
            rear_141 = nullptr;
        }
    }

    // Fungsi untuk menampilkan seluruh antrian
    void displayQueue_141() {
        if (isEmpty_141()) { // Jika antrian kosong maka tampilkan pesan "Data antrian:" dan tampilkan pesan "(kosong)"
            cout << "\n[2141] Data Antrian :" << endl;
            for (int i_141 = 0; i_141 < maksimalQueue_141; i_141++) {
                cout << i_141 + 1 << ". (kosong)" << endl;
            }
        } else { // Jika antrian tidak kosong maka tampilkan data antrian yang ada
            cout << "\n[2141] Data Antrian :" << endl;
            Node* current_141 = front_141;
            int i_141 = 1;
            while (current_141 != nullptr) { // Selama current_141 tidak menunjuk ke nullptr maka tampilkan data antrian yang ada 
                cout << i_141 << ". " << "Nama: " << current_141->Nama_141 << ", NIM: " << current_141->NIM_141 << endl;
                current_141 = current_141->next_141;
                i_141++;
            }
            for (; i_141 <= maksimalQueue_141; i_141++) { // Tampilkan pesan "(kosong)" untuk antrian yang kosong 
                cout << i_141 << ". (kosong)" << endl;
            }
        }
    }

    // Fungsi untuk memeriksa apakah antrian kosong
    bool isEmpty_141() {
        return front_141 == nullptr;
    }

    // Fungsi untuk mengembalikan jumlah elemen dalam antrian
    int countQueue_141() {
        int count_141 = 0;
        Node* current_141 = front_141;
        while (current_141 != nullptr) { 
            count_141++;
            current_141 = current_141->next_141;
        }
        return count_141; // Kembalikan jumlah elemen dalam antrian
    }

    // Fungsi untuk menghapus semua elemen dalam antrian
    void clearQueue_141() {
        while (!isEmpty_141()) { // Selama antrian tidak kosong maka hapus elemen dalam antrian
            dequeue_141(); // Hapus elemen dalam antrian 
        } 
        cout << "Antrian telah dibersihkan." << endl;
    }
};

int main() {
    Queue queue; // Buat objek queue dari class Queue
    queue.enqueue_141("Ramadhika Primadana", "2311102141");
    queue.enqueue_141("Chaerunnisa", "2311100010");
    queue.displayQueue_141();
    cout << "[2141] Jumlah Antrian = " << queue.countQueue_141() << endl;
    queue.dequeue_141();
    queue.displayQueue_141();
    cout << "[2141] Jumlah Antrian = " << queue.countQueue_141() << endl;
    queue.dequeue_141();
    queue.displayQueue_141();
    cout << "[2141] Jumlah Antrian = " << queue.countQueue_141() << endl;

    return 0;
}


```
#### Output:
![ss_Unguided2_Laprak7_2311102141_Ramadhika Primadana](/PERTEMUAN7/output/modul7.unguided1.1_141.png)


Kode di atas digunakan untuk implementasi struktur data Queue atau antrian dengan menggunakan linked list di C++. Antrian diimplementasikan sebagai kelas yang disebut 'Queue', yang memiliki penunjuk depan dan penunjuk belakang untuk melacak elemen depan dan belakang antrian. Antrian dapat menyimpan string sebagai elemennya.
Kelas Queue memiliki beberapa metode untuk memanipulasi antrian:
- 'enqueue_138(const string& data_138)': menambahkan elemen ke bagian belakang antrian.
- 'dequeue_138()': menghapus elemen dari depan antrian.
- 'displayQueue_138()': menampilkan semua elemen dalam antrian.
- 'isEmpty_138()': memeriksa apakah antrian kosong.
- 'countQueue_138()': mengembalikan jumlah elemen dalam antrian.
- 'clearQueue_138()': menghapus semua elemen dari antrian.

  Fungsi ini 'main' mendemonstrasikan cara menggunakan 'Queue' kelas dengan membuat objek antrian, menambah dan menghapus elemen dari antrian, dan menampilkan antrian di berbagai tahapan. Program ini juga menggunakan metode 'isEmpty_138()', 'countQueue_138()', dan 'clearQueue_138()' untuk menunjukkan status antrian saat ini.

  Program ini dalam penggunaannya menggunakan output dari code otomatis. Lebih jelasnya yang hasil programnya seperti gambar output diatas.


### 2. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]

```C++
// LAPRAK 7 : UNGUIDED 2
// Ramadhika Primadana
// 2311102141
// S1 IF-11-D

// Program dari nomor 1, membuat konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa
#include <iostream>
#include <string>

using namespace std;

const int maksimalQueue_141 = 5;  // Maksimal antrian adalah 5

// Node untuk menyimpan data dan pointer ke node berikutnya
struct Node {
    string Nama_141;
    string NIM_141;
    Node* next_141;
};

class Queue {
private:
    Node* front_141; // Node depan dari antrian
    Node* rear_141;  // Node belakang dari antrian

public: 
    Queue() { // Konstruktor untuk menginisialisasi antrian kosong
        front_141 = nullptr;
        rear_141 = nullptr;
    }

    // Fungsi untuk menambahkan data ke antrian
    void enqueue_141(const string& Nama_141, const string& NIM_141) {
        Node* newNode_141 = new Node;
        newNode_141->Nama_141 = Nama_141;
        newNode_141->NIM_141 = NIM_141;
        newNode_141->next_141 = nullptr;
        
        // Jika antrian kosong
        if (isEmpty_141()) { // Jika antrian kosong maka front_141 dan rear_141 menunjuk ke newNode_141 yang baru dibuat 
            front_141 = rear_141 = newNode_141;
        } else { // Jika antrian tidak kosong maka rear_141 menunjuk ke newNode_141 yang baru dibuat
            rear_141->next_141 = newNode_141;
            rear_141 = newNode_141;
        }
        
        cout << ">> Mahasiswa dengan Nama: " << newNode_141->Nama_141 << ", dan NIM: " << newNode_141->NIM_141 << " telah ditambahkan ke dalam antrian." << endl;
    }

    // Fungsi untuk menghapus data dari antrian
    void dequeue_141() {
        if (isEmpty_141()) { // Jika antrian kosong maka tampilkan pesan "Antrian kosong" dan kembalikan nilai void
            cout << "Antrian kosong." << endl;
            return;
        }

        Node* temp_141 = front_141; // Simpan node front_141 ke dalam variabel temp_141 untuk dihapus nantinya 
        front_141 = front_141->next_141; // Geser front_141 ke node selanjutnya 

        cout << ">> Mahasiswa dengan Nama: " << temp_141->Nama_141 << ", dan NIM: " << temp_141->NIM_141 << " telah dihapus dari antrian." << endl; // Tampilkan data mahasiswa yang dihapus dari antrian 
        delete temp_141; // Hapus node yang disimpan di variabel temp_141

        // Jika setelah penghapusan antrian menjadi kosong
        if (front_141 == nullptr) {
            rear_141 = nullptr;
        }
    }

    // Fungsi untuk menampilkan seluruh antrian
    void displayQueue_141() {
        if (isEmpty_141()) { // Jika antrian kosong maka tampilkan pesan "Data antrian:" dan tampilkan pesan "(kosong)"
            cout << "\n[2141] Data Antrian :" << endl;
            for (int i_141 = 0; i_141 < maksimalQueue_141; i_141++) {
                cout << i_141 + 1 << ". (kosong)" << endl;
            }
        } else { // Jika antrian tidak kosong maka tampilkan data antrian yang ada
            cout << "\n[2141] Data Antrian :" << endl;
            Node* current_141 = front_141;
            int i_141 = 1;
            while (current_141 != nullptr) { // Selama current_141 tidak menunjuk ke nullptr maka tampilkan data antrian yang ada 
                cout << i_141 << ". " << "Nama: " << current_141->Nama_141 << ", NIM: " << current_141->NIM_141 << endl;
                current_141 = current_141->next_141;
                i_141++;
            }
            for (; i_141 <= maksimalQueue_141; i_141++) { // Tampilkan pesan "(kosong)" untuk antrian yang kosong 
                cout << i_141 << ". (kosong)" << endl;
            }
        }
    }

    // Fungsi untuk memeriksa apakah antrian kosong
    bool isEmpty_141() {
        return front_141 == nullptr;
    }

    // Fungsi untuk mengembalikan jumlah elemen dalam antrian
    int countQueue_141() {
        int count_141 = 0;
        Node* current_141 = front_141;
        while (current_141 != nullptr) { 
            count_141++;
            current_141 = current_141->next_141;
        }
        return count_141; // Kembalikan jumlah elemen dalam antrian
    }

    // Fungsi untuk menghapus semua elemen dalam antrian
    void clearQueue_141() {
        while (!isEmpty_141()) { // Selama antrian tidak kosong maka hapus elemen dalam antrian
            dequeue_141(); // Hapus elemen dalam antrian 
        } 
        cout << "Antrian telah dibersihkan." << endl;
    }
};

int main() {
    Queue queue; // Buat objek queue dari class Queue
    queue.enqueue_141("Ramadhika Primadana", "2311102141");
    queue.enqueue_141("Chaerunnisa", "2311100010");
    queue.displayQueue_141();
    cout << "[2141] Jumlah Antrian = " << queue.countQueue_141() << endl;
    queue.dequeue_141();
    queue.displayQueue_141();
    cout << "[2141] Jumlah Antrian = " << queue.countQueue_141() << endl;
    queue.dequeue_141();
    queue.displayQueue_141();
    cout << "[2141] Jumlah Antrian = " << queue.countQueue_141() << endl;

    return 0;
}

```
#### Output:
![ss_Unguided2_Laprak7_2311102141_Ramadhika Primadana](/PERTEMUAN7/output/modul7.unguided2.1_141.png)

Kode di atas digunakan untuk implementasi dari struktur data Queue atau antrian pada C++. Dengan dirancang khusus untuk menyimpan data siswa dengan atribut nama dan nomor induk siswa (NIM). Antrian memiliki kapasitas maksimal 5 siswa. Program ini menggunakan implementasi daftar tertaut dari antrian, dengan penunjuk depan dan belakang untuk melacak elemen depan dan belakang antrian.
Kelas 'Queue' memiliki beberapa metode untuk memanipulasi antrian:
- 'enqueue_138': menambahkan siswa baru ke belakang antrian dengan nama dan ID siswa yang diberikan.
- 'dequeue_138': mengeluarkan siswa depan dari antrian dan mencetak nama dan ID siswanya.
- 'displayQueue_138': mencetak status antrian saat ini, menampilkan nama dan ID siswa setiap siswa dalam antrian.
- 'isEmpty_138': memeriksa apakah antrian kosong dan mengembalikan nilai boolean yang menunjukkan hasilnya.
- 'countQueue_138': mengembalikan jumlah siswa yang sedang dalam antrian.
- 'clearQueue_138': mengeluarkan semua siswa dari antrian dan mencetak pesan yang menunjukkan bahwa antrian telah dihapus.

  Fungsi ini 'main' mendemonstrasikan cara menggunakan 'Queue' kelas dengan membuat objek antrian, menambahkan beberapa siswa ke antrian, menampilkan antrian, dan mengeluarkan siswa dari antrian. Program ini juga menggunakan metode 'isEmpty_138', 'countQueue_138', dan 'clearQueue_138' untuk menunjukkan status antrian saat ini.

  Program ini dalam penggunaannya menggunakan output dari code otomatis. Lebih jelasnya yang hasil programnya seperti gambar output diatas.


## Kesimpulan
Kesimpulannya, pada modul 7 ini Queue atau antrian merupakan struktur data LIFO (Last In First Out) dimana suatu struktur data yang terbentuk dari barisan hingga yang terurut dari satuan data. Queue mirip dengan konsep antrian pada kehidupan sehari-hari, dimana konsumen yang datang lebih dulu akan dilayani terlebih dahulu. Implementasinya dapat menggunakan array atau linked list, dengan dua pointer utama, yaitu front dan rear. Berbeda dengan struktur data lain seperti stack, penambahan dan penghapusan elemen dalam queue terjadi pada ujung yang berbeda, yaitu front untuk Dequeue dan rear untuk Enqueue.

Keunggulan atau Kelebihan Queue yaitu Implementasi yang sederhana, dan sangat efisiensi dalam hal Waktu. Queue jika menggunakan linked list lebih fleksibel dan efisien untuk penambahan dan penghapusan elemen di tengah antrian. Ada banyak jenis-jenis operasi. Queue menggunakan Prinsip FIFO yaitu yang memastikan bahwa data diproses sesuai urutan penerimaannya, membuat antrian berguna dalam aplikasi di mana data perlu diproses dalam urutan tertentu.

Kekurangan Queue antara lain seperti Ukuran terbatas atau overhead memori, ketika menambahkan dan menghapus elemen di tengah antrian tidak efisien karena membutuhkan pergeseran elemen lain. Batasan kapasitas pada implementasi dengan array dan Performa yang buruk pada implementasi dengan array jika terdapat operasi dequeue yang sering dilakukan. Queue memiliki sifat LIFO yang tidak dapat diubah, Artinya elemen yang pertama kali masuk akan menjadi elemen yang pertama kali dikeluarkan, Ini membuat queue kurang fleksibel untuk digunakan dalam beberapa situasi yang memerlukan akses acak atau pengubahan urutan data. Tidak dapat digunakan untuk semua kasus, dan Tidak mendukung operasi pencarian.

## Referensi
 [1] Dr. Joseph Teguh Santoso. Struktur Data dan ALgoritma. Semarang: Yayasan Prima Agus Teknik. 2021.

 [2] Muhammad Nugraha. Dasar Pemrograman Dengan C++ Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta. 2021.

 [3] Mulyana A. E-Books Cara Mudah Mempelajari Algoritma dan Struktur Data. 2023.

 [4] Rafsanjani, Malik Akbar Hashemi. "Implementasi Algoritma Pengurutan General Purpose dan Berbasis Komparasi untuk Data Berkategori dalam Waktu Linier Tanpa Paralelisasi", 2021.
