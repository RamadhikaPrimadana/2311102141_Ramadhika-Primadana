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
