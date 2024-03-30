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
