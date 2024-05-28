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
