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
