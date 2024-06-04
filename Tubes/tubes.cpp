#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Definisi struktur untuk menu item
struct MenuItem {
    string nama;        // Tipe data string untuk nama item
    double harga;       // Tipe data double untuk harga item
    string deskripsi; // Tipe data string untuk deskripsi item
};

// Fungsi untuk menambahkan item ke dalam menu
void addMenuItem(unordered_map<int, MenuItem>& menu, int id, const string& name, double price, const string& description) {
    MenuItem item = {name, price, description}; // Membuat objek MenuItem
    menu[id] = item; // Menambahkan item ke hash table dengan kunci id
    cout << "Item berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua item di dalam menu
void displayMenu(const unordered_map<int, MenuItem>& menu) {
    if (menu.empty()) {
        cout << "Menu kosong!" << endl;
        return;
    }

    for (const auto& pair : menu) { // Iterasi melalui semua item di hash table
        cout << "ID: " << pair.first << endl;             // Menampilkan kunci (ID)
        cout << "Nama: " << pair.second.nama << endl;     // Menampilkan nama item
        cout << "Harga: " << pair.second.harga << endl;   // Menampilkan harga item
        cout << "deskripsi: " << pair.second.deskripsi << endl; // Menampilkan deskripsi item
        cout << "----------------------" << endl;
    }
}

// Fungsi untuk mengedit item dalam menu
void editMenuItem(unordered_map<int, MenuItem>& menu, int id) {
    if (menu.find(id) == menu.end()) {
        cout << "Item with ID " << id << " not found!" << endl;
        return;
    }

    cout << "Masukkan new name: ";
    cin.ignore();
    string name;
    getline(cin, name);

    cout << "Masukkan new price: ";
    double price;
    cin >> price;

    cout << "Masukkan new description: ";
    cin.ignore();
    string description;
    getline(cin, description);

    menu[id] = {name, price, description};
    cout << "Item updated successfully!" << endl;
}

// Fungsi untuk menghapus item dari menu
void deleteMenuItem(unordered_map<int, MenuItem>& menu, int id) {
    if (menu.erase(id)) {
        cout << "Item deleted successfully!" << endl;
    } else {
        cout << "Item with ID " << id << " not found!" << endl;
    }
}

// Fungsi untuk mencari item berdasarkan ID
void searchMenuItem(const unordered_map<int, MenuItem>& menu, int id) {
    auto it = menu.find(id);
    if (it != menu.end()) {
        cout << "ID: " << it->first << endl;
        cout << "Nama Menu: " << it->second.nama << endl;
        cout << "Harga Menu: " << it->second.harga << endl;
        cout << "Deskripsi Menu: " << it->second.deskripsi << endl;
    } else {
        cout << "Item with ID " << id << " tidak ditemukan!" << endl;
    }
}

int main() {
    unordered_map<int, MenuItem> menu; // Membuat hash table menu dengan kunci int dan nilai MenuItem
    int choice, id;
    string name, description;
    double price;

    while (true) {
        cout << "Sistem Manajemen Menu" << endl;
        cout << "1. Menambahkan Menu Item" << endl;
        cout << "2. Display Menu" << endl;
        cout << "3. Edit Menu Item" << endl;
        cout << "4. hapus Menu Item" << endl;
        cout << "5. mencari Menu Item" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan ID: ";
                cin >> id;
                cout << "Masukkan nama: ";
                cin.ignore();
                getline(cin, name);
                cout << "Masukkan harga: ";
                cin >> price;
                cout << "Masukkan description: ";
                cin.ignore();
                getline(cin, description);
                addMenuItem(menu, id, name, price, description);
                break;
            case 2:
                displayMenu(menu);
                break;
            case 3:
                cout << "Masukkan ID item yang akan diedit: ";
                cin >> id;
                editMenuItem(menu, id);
                break;
            case 4:
                cout << "Masukkan ID item yang akan dihapus: ";
                cin >> id;
                deleteMenuItem(menu, id);
                break;
            case 5:
                cout << "Masukkan ID item yang akan dicari: ";
                cin >> id;
                searchMenuItem(menu, id);
                break;
            case 6:
                cout << "Keluar..." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Definisi struktur untuk menu item
struct MenuItem {
    string nama;        // Tipe data string untuk nama item
    double harga;       // Tipe data double untuk harga item
    string deskripsi; // Tipe data string untuk deskripsi item
};

// Fungsi untuk menambahkan item ke dalam menu
void addMenuItem(unordered_map<int, MenuItem>& menu, int id, const string& name, double price, const string& description) {
    MenuItem item = {name, price, description}; // Membuat objek MenuItem
    menu[id] = item; // Menambahkan item ke hash table dengan kunci id
    cout << "Item berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua item di dalam menu
void displayMenu(const unordered_map<int, MenuItem>& menu) {
    if (menu.empty()) {
        cout << "Menu kosong!" << endl;
        return;
    }

    for (const auto& pair : menu) { // Iterasi melalui semua item di hash table
        cout << "ID: " << pair.first << endl;             // Menampilkan kunci (ID)
        cout << "Nama: " << pair.second.nama << endl;     // Menampilkan nama item
        cout << "Harga: " << pair.second.harga << endl;   // Menampilkan harga item
        cout << "deskripsi: " << pair.second.deskripsi << endl; // Menampilkan deskripsi item
        cout << "----------------------" << endl;
    }
}

// Fungsi untuk mengedit item dalam menu
void editMenuItem(unordered_map<int, MenuItem>& menu, int id) {
    if (menu.find(id) == menu.end()) {
        cout << "Item with ID " << id << " not found!" << endl;
        return;
    }

    cout << "Masukkan new name: ";
    cin.ignore();
    string name;
    getline(cin, name);

    cout << "Masukkan new price: ";
    double price;
    cin >> price;

    cout << "Masukkan new description: ";
    cin.ignore();
    string description;
    getline(cin, description);

    menu[id] = {name, price, description};
    cout << "Item updated successfully!" << endl;
}

// Fungsi untuk menghapus item dari menu
void deleteMenuItem(unordered_map<int, MenuItem>& menu, int id) {
    if (menu.erase(id)) {
        cout << "Item deleted successfully!" << endl;
    } else {
        cout << "Item with ID " << id << " not found!" << endl;
    }
}

// Fungsi untuk mencari item berdasarkan ID
void searchMenuItem(const unordered_map<int, MenuItem>& menu, int id) {
    auto it = menu.find(id);
    if (it != menu.end()) {
        cout << "ID: " << it->first << endl;
        cout << "Nama Menu: " << it->second.nama << endl;
        cout << "Harga Menu: " << it->second.harga << endl;
        cout << "Deskripsi Menu: " << it->second.deskripsi << endl;
    } else {
        cout << "Item with ID " << id << " tidak ditemukan!" << endl;
    }
}

int main() {
    unordered_map<int, MenuItem> menu; // Membuat hash table menu dengan kunci int dan nilai MenuItem
    int choice, id;
    string name, description;
    double price;

    while (true) {
        cout << "Sistem Manajemen Menu" << endl;
        cout << "1. Menambahkan Menu Item" << endl;
        cout << "2. Display Menu" << endl;
        cout << "3. Edit Menu Item" << endl;
        cout << "4. hapus Menu Item" << endl;
        cout << "5. mencari Menu Item" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan ID: ";
                cin >> id;
                cout << "Masukkan nama: ";
                cin.ignore();
                getline(cin, name);
                cout << "Masukkan harga: ";
                cin >> price;
                cout << "Masukkan description: ";
                cin.ignore();
                getline(cin, description);
                addMenuItem(menu, id, name, price, description);
                break;
            case 2:
                displayMenu(menu);
                break;
            case 3:
                cout << "Masukkan ID item yang akan diedit: ";
                cin >> id;
                editMenuItem(menu, id);
                break;
            case 4:
                cout << "Masukkan ID item yang akan dihapus: ";
                cin >> id;
                deleteMenuItem(menu, id);
                break;
            case 5:
                cout << "Masukkan ID item yang akan dicari: ";
                cin >> id;
                searchMenuItem(menu, id);
                break;
            case 6:
                cout << "Keluar..." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl;
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>                 // Header file untuk input dan output
#include <unordered_map>            // Header file untuk unordered_map
#include <string>                   // Header file untuk string
using namespace std;

// Definisi struktur untuk menu item
struct MenuItem {
    string nama;                    // Tipe data string untuk nama item
    double harga;                   // Tipe data double untuk harga item
    string deskripsi;               // Tipe data string untuk deskripsi item
};

// Fungsi untuk menambahkan item ke dalam menu
void addMenuItem(unordered_map<int, MenuItem>& menu, int id, const string& name, double price, const string& description) {
    MenuItem item = {name, price, description};  // Membuat objek MenuItem dengan nilai yang diberikan
    menu[id] = item;                             // Menambahkan item ke unordered_map dengan kunci id
    cout << "Item berhasil ditambahkan!" << endl; // Menampilkan pesan bahwa item berhasil ditambahkan
}

// Fungsi untuk menampilkan semua item di dalam menu
void displayMenu(const unordered_map<int, MenuItem>& menu) {
    if (menu.empty()) {                          // Memeriksa apakah menu kosong
        cout << "Menu kosong!" << endl;          // Menampilkan pesan jika menu kosong
        return;                                  // Keluar dari fungsi jika menu kosong
    }

    for (const auto& pair : menu) {              // Iterasi melalui semua item di unordered_map
        cout << "ID: " << pair.first << endl;             // Menampilkan kunci (ID)
        cout << "Nama: " << pair.second.nama << endl;     // Menampilkan nama item
        cout << "Harga: " << pair.second.harga << endl;   // Menampilkan harga item
        cout << "deskripsi: " << pair.second.deskripsi << endl; // Menampilkan deskripsi item
        cout << "----------------------" << endl;          // Memisahkan setiap item dengan garis
    }
}

// Fungsi untuk mengedit item dalam menu
void editMenuItem(unordered_map<int, MenuItem>& menu, int id) {
    if (menu.find(id) == menu.end()) {           // Memeriksa apakah item dengan ID yang diberikan ada di menu
        cout << "Item with ID " << id << " not found!" << endl; // Menampilkan pesan jika item tidak ditemukan
        return;                                  // Keluar dari fungsi jika item tidak ditemukan
    }

    cout << "Masukkan new name: ";               // Meminta input nama baru
    cin.ignore();                                // Mengabaikan karakter newline yang tersisa di buffer
    string name;                                 // Deklarasi variabel untuk nama baru
    getline(cin, name);                          // Mengambil input nama baru

    cout << "Masukkan new price: ";              // Meminta input harga baru
    double price;                                // Deklarasi variabel untuk harga baru
    cin >> price;                                // Mengambil input harga baru

    cout << "Masukkan new description: ";        // Meminta input deskripsi baru
    cin.ignore();                                // Mengabaikan karakter newline yang tersisa di buffer
    string description;                          // Deklarasi variabel untuk deskripsi baru
    getline(cin, description);                   // Mengambil input deskripsi baru

    menu[id] = {name, price, description};       // Memperbarui item dalam unordered_map dengan nilai baru
    cout << "Item updated successfully!" << endl; // Menampilkan pesan bahwa item berhasil diperbarui
}

// Fungsi untuk menghapus item dari menu
void deleteMenuItem(unordered_map<int, MenuItem>& menu, int id) {
    if (menu.erase(id)) {                        // Menghapus item dari unordered_map berdasarkan ID
        cout << "Item deleted successfully!" << endl; // Menampilkan pesan jika item berhasil dihapus
    } else {                                     // Jika item dengan ID yang diberikan tidak ditemukan
        cout << "Item with ID " << id << " not found!" << endl; // Menampilkan pesan bahwa item tidak ditemukan
    }
}

// Fungsi untuk mencari item berdasarkan ID
void searchMenuItem(const unordered_map<int, MenuItem>& menu, int id) {
    auto it = menu.find(id);                     // Mencari item dalam unordered_map berdasarkan ID
    if (it != menu.end()) {                      // Jika item ditemukan
        cout << "ID: " << it->first << endl;             // Menampilkan kunci (ID)
        cout << "Nama Menu: " << it->second.nama << endl; // Menampilkan nama item
        cout << "Harga Menu: " << it->second.harga << endl; // Menampilkan harga item
        cout << "Deskripsi Menu: " << it->second.deskripsi << endl; // Menampilkan deskripsi item
    } else {                                     // Jika item tidak ditemukan
        cout << "Item with ID " << id << " tidak ditemukan!" << endl; // Menampilkan pesan bahwa item tidak ditemukan
    }
}

int main() {
    unordered_map<int, MenuItem> menu;           // Membuat unordered_map untuk menyimpan menu dengan kunci int dan nilai MenuItem
    int choice, id;                              // Deklarasi variabel untuk pilihan dan ID
    string name, description;                    // Deklarasi variabel untuk nama dan deskripsi
    double price;                                // Deklarasi variabel untuk harga

    while (true) {                               // Loop utama untuk sistem manajemen menu
        cout << "Sistem Manajemen Menu" << endl; // Menampilkan judul sistem
        cout << "1. Menambahkan Menu Item" << endl; // Menampilkan opsi untuk menambahkan item
        cout << "2. Display Menu" << endl;       // Menampilkan opsi untuk menampilkan menu
        cout << "3. Edit Menu Item" << endl;     // Menampilkan opsi untuk mengedit item
        cout << "4. hapus Menu Item" << endl;    // Menampilkan opsi untuk menghapus item
        cout << "5. mencari Menu Item" << endl;  // Menampilkan opsi untuk mencari item
        cout << "6. Keluar" << endl;             // Menampilkan opsi untuk keluar dari program
        cout << "Masukkan pilihan Anda: ";       // Meminta input pilihan dari pengguna
        cin >> choice;                           // Mengambil input pilihan

        switch (choice) {                        // Switch case berdasarkan pilihan pengguna
            case 1:                              // Jika pilihan adalah 1 (Menambahkan item)
                cout << "Masukkan ID: ";         // Meminta input ID
                cin >> id;                       // Mengambil input ID
                cout << "Masukkan nama: ";       // Meminta input nama
                cin.ignore();                    // Mengabaikan karakter newline yang tersisa di buffer
                getline(cin, name);              // Mengambil input nama
                cout << "Masukkan harga: ";      // Meminta input harga
                cin >> price;                    // Mengambil input harga
                cout << "Masukkan description: "; // Meminta input deskripsi
                cin.ignore();                    // Mengabaikan karakter newline yang tersisa di buffer
                getline(cin, description);       // Mengambil input deskripsi
                addMenuItem(menu, id, name, price, description); // Menambahkan item ke menu
                break;
            case 2:                              // Jika pilihan adalah 2 (Menampilkan menu)
                displayMenu(menu);               // Menampilkan menu
                break;
            case 3:                              // Jika pilihan adalah 3 (Mengedit item)
                cout << "Masukkan ID item yang akan diedit: "; // Meminta input ID item yang akan diedit
                cin >> id;                       // Mengambil input ID
                editMenuItem(menu, id);          // Mengedit item dalam menu
                break;
            case 4:                              // Jika pilihan adalah 4 (Menghapus item)
                cout << "Masukkan ID item yang akan dihapus: "; // Meminta input ID item yang akan dihapus
                cin >> id;                       // Mengambil input ID
                deleteMenuItem(menu, id);        // Menghapus item dari menu
                break;
            case 5:                              // Jika pilihan adalah 5 (Mencari item)
                cout << "Masukkan ID item yang akan dicari: "; // Meminta input ID item yang akan dicari
                cin >> id;                       // Mengambil input ID
                searchMenuItem(menu, id);        // Mencari item dalam menu
                break;
            case 6:                              // Jika pilihan adalah 6 (Keluar dari program)
                cout << "Keluar..." << endl;     // Menampilkan pesan keluar
                return 0;                        // Mengakhiri program
            default:                             // Jika pilihan tidak valid
                cout << "Pilihan tidak valid! Silakan coba lagi." << endl; // Menampilkan pesan bahwa pilihan tidak valid
        }
        cout << endl;                            // Menampilkan baris kosong setelah setiap operasi
    }

    return 0;                                    // Mengembalikan nilai 0 untuk menunjukkan bahwa program berakhir dengan sukses
}
