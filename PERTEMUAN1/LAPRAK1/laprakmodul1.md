# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">RAMADHIKA PRIAMDANA - 2311102141</p>

## Dasar Teori

Tipe adalah format penyimpanan data. Fungsi tipe data adalah mempresentasikan suatu jenis dari suatu nilai yang terdapat pada program. Macam-macam tipe data yang terdapat pada C++ ada 3, yaitu:
1. Tipe Data Primitif
2. Tipe Data Abstrak
3. Tipe Data Koleksi

### 1. Tipe data Primitif
Tipe data primitif adalah tipe data yang  ditentukan sistem. Tipe data primitif ini disediakan oleh banyak bahasa pemrograman, perbedaannya terletak pada jumlah bit yang dialokasikan untuk setiap bit dalam tipe data primitif, tergantung pada bahasa pemrograman, compiler, dan sistem operasi. Contoh tipe data primitif adalah: 
1. Int, untuk Bilangan Bulat
2. Float, untuk Bilangan Desimal
3. Char, untuk Huruf.
4. Boolean, untuk True dan False.

### 2. Tipe Data Abstrak
Tipe data abstrak (Abstract Data Type - ADT) adalah konsep ilmu komputer yang memberikan spesifikasi matematis dari suatu tipe data dan operasi yang dapat dilakukan pada tipe data tersebut tanpa memberikan implementasi konkrit. ADT memisahkan  apa yang perlu dilakukan (spesifikasi) dan bagaimana hal itu perlu dilakukan (implementasi).

### 3. Tipe Data Koleksi
Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses data dalam jumlah besar dengan cara yang terstruktur. Tipe data koleksi yang umum digunakan dalam pemrograman :
1. Array, adalah struktur data statis yang menyimpan elemen dengan tipe data yang sama. Elemen-elemen ini dapat diakses  menggunakan indeks. Array memiliki ukuran tetap yang ditentukan selama deklarasi.
2. Vector, adalah Standard Template Library (STL) jika pada C/C++ berbentuk std::vector. Secara umum vektor mirip dengan array karena mampu menyimpan data sebagai elemen yang alokasi memorinya dilakukan secara otomatis dan terus menerus. Kemampuan Vector tidak hanya terbatas pada jumlah elemen dinamis saja, Vector pada C/C++ juga dilengkapi dengan fitur tambahan sepert element access, iterators, capacity, modifiers.
3. Map, adalah mirip dengan array, namun dengan index tipe data selain integer. Pada map, indeks diberi nama “key”. Pada std::map digunakan Self-Balancing Tree khususnya Red-Black Tree.

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
#include <iomanip>

using namespace std;

// Tipe Data Primitif by Rico Ade Pratama_2311102138
int main() {
    char op;
    float num1, num2;

    // It allows user to enter operator i.e. +, -, *, /

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    // It allows user to enter the operands
    cout << "Enter two operands: ";
    cin >> num1 >> num2;
    
    // Switch statement begins
    switch (op) {
        // If user enters +
        case '+':
        cout << "Result: " << num1 + num2;
        break;
        // If user enters -
        case '-':
        cout << "Result: " << num1 - num2;
        break;
        // If user enters *
        case '*':
        cout << "Result: " << num1 * num2;
        break;
        // If user enters /
        case '/':
        if (num2 != 0) {
            cout << "Result: " << fixed << setprecision(2) << num1 / num2;
            } else {
                cout << "Error! Division by zero is not allowed.";
                }
                break;
                // If the operator is other than +, -, * or /,
                // error message will display
                default:
                cout << "Error! Operator is not correct";
                } // switch statement ends
    return 0;
}
```
Kode di atas digunakan untuk melakukan operasi aritmatika dasar dari pilihan operasi penambahan (+), pengurangan (-), perkalian (*), dan pembagian (/). Program ini terdapat dua tipe data primitif, yakni char dan float. Tipe data char digunakan pada saat pemilihan switch case dan float, Serta akan aktif ketika pengguna sudah menginput dua angka. 

### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>
#include <string.h>
//Struct
struct Mahasiswa
{
    char name[50];
    char address[100];
    int age;
};
// // Tipe Data Abstrak by Rico Ade Pratama_2311102138
int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;

    // mengisi nilai ke struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs2.age = 23;
    
    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf ("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);\
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);

    return 0;
}

```
Kode di atas digunakan untuk mencetak data mahasiswa dengan menggunakan program struct. Struct merupakan contoh dari tipe data abstrak, Pada kode di atas terdapat sebuah struct 'Mahasiswa' dengan memiliki cabang 'name' (nama), 'address'(alamat), dan 'age' (umur). Ada 2 variabel mendeklarasikan dan menginisialisasi dengan data mahasiswa dengan struct 'mhs1' nama Dian dan 'mhs2' nama Bambang, dan fungsi 'printf' mencetak informasi mahasiswa.

### 3. [Tipe Data Koleksi]

```C++
#include <iostream>
#include <array>

using namespace std;

// Tipe Data Koleksi by Rico Ade Pratama_2311102138
int main() {
    
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    
    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;

return 0;
}
```
Kode di atas digunakan untuk mengetahui isi nilai dari penggunaan array. Array adalah tipe data koleksi, pada program ini akan mendeklarasikan dan menginisialisasi sebuah array integer bernama 'nilai' dengan terdapat 5 nilai array, yakni 23, 50, 34, 78, dan 90.Kemudian program ini akan mencetak nilai setiap elemen yang ada di dalam array menggunakan 'cout'.


## Unguided 


### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
// LAPRAK 1 : UNGUIDED 1
// RAMADHIKA PRIMADANA
// 2311102141
// S1 IF-11-D
#include <iostream>

using namespace std;

// Fungsi untuk menampilkan menu cafe
void TampilkanMenu() {
    cout << "===  NONGSKUY  ===" <<endl;
    cout << "1. Kopi          : Rp. 15,000" << endl;
    cout << "2. Teh           : Rp. 10,000" << endl;
    cout << "3. Sandwich      : Rp. 20,000" << endl;
    cout << "4. Nasi Goreng   : Rp. 25,000" << endl;
    cout << "5. Es Teh Manis  : Rp. 12,000" << endl;
    cout << "=================" << endl;
}

// Fungsi untuk menghitung total biaya pesanan
float HitungTotal(int pilihan, int jumlah) {
    float harga = 0;

    switch (pilihan) {
        case 1:
            harga = 15000;
            break;
        case 2:
            harga = 10000;
            break;
        case 3:
            harga = 20000;
            break;
        case 4:
            harga = 25000;
            break;
        case 5:
            harga = 12000;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
            return 0;
    }

    return harga * jumlah;
}

int main() {
    int pilihan;
    int jumlah;

    // Menampilkan menu cafe
    TampilkanMenu();

    // Meminta pengguna memilih menu
    cout << "Pilih menu (1-5): ";
    cin >> pilihan;

    // Meminta pengguna memasukkan jumlah pesanan
    cout << "Masukkan jumlah pesanan: ";
    cin >> jumlah;

    // Menghitung total biaya pesanan
    float total = HitungTotal(pilihan, jumlah);

    // Menampilkan total biaya pesanan
    cout << "Total biaya: Rp. " << total << endl;

    return 0;
}


```
#### Output:
![SS_Unguided1_RicoAdePratama_2311102138](/pertemuan01/LAPRAK01/SS_Unguided1_RicoAdePratama_2311102138.png)

Kode diatas digunakan untuk menjalankan Program KALKULATOR RICO ADE PRATAMA yang memungkinkan pengguna untuk melakukan operasi matematika dasar seperti penjumlahan, pengurangan, perkalian, pembagian, dan pemangkatan. Program memiliki menu pilihan yang ditampilkan kepada pengguna, dan setiap pilihan akan mengarahkan pengguna ke fungsi khusus yang melakukan perhitungan sesuai operasi yang dipilih. Program terus berjalan dalam loop hingga pengguna memilih opsi "0" untuk keluar dari program. Selain itu, program juga memiliki penanganan kasus khusus untuk pembagian dengan nol, memberikan pesan kesalahan jika hal tersebut terjadi.

Kesimpulan Tipe Data Primitif:
Kesimpulannya, program ini memanfaatkan tipe data primitif secara tepat sesuai dengan kebutuhan untuk menyederhanakan operasi kalkulasi matematika dasar. Penggunaan tipe data primitif membantu dalam mengelola data dengan efisien dan memudahkan implementasi program kalkulator sederhana ini.

### 2. [Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya]

```C++
// LAPRAK 1 : UNGUIDED 2
// RICO ADE PRATAMA
// 2311102138
// S1 IF-11-D

#include <iostream>
#include <string>

using namespace std;

// class PemainSepakBola
class PemainSepakBola {
public:
    // atribut
    string nama_138;
    int umur_138;
    int Goal_138;
    int assistGoal_138;
    string tim_138;

    // method
    void print() {
        cout << "Nama: " << nama_138 << endl;
        cout << "Umur: " << umur_138 << endl;
        cout << "Goal: " << Goal_138 << endl;
        cout << "Assist Goal: " << assistGoal_138 << endl;
        cout << "Tim: " << tim_138 << endl;
        cout << "----------------------" << endl;
    }
};

// struct PemainSepakBolaStruct
struct PemainSepakBolaStruct {
    // atribut
    string nama_138;
    int umur_138;
    int Goal_138;
    int assistGoal_138;
    string tim_138;
};

int main() {
    // Membuat objek dari class PemainSepakBola dan mengisi data
    PemainSepakBola pemain1;
    pemain1.nama_138 = "Lionel Messi";
    pemain1.umur_138 = 36;
    pemain1.Goal_138 = 30;
    pemain1.assistGoal_138 = 15;
    pemain1.tim_138 = "Inter Miami FC";

    // Menampilkan informasi pemain1
    pemain1.print();

    // Membuat objek dari struct PemainSepakBolaStruct dan mengisi data
    PemainSepakBolaStruct pemain2;
    pemain2.nama_138 = "Cristiano Ronaldo";
    pemain2.umur_138 = 39;
    pemain2.Goal_138 = 51;
    pemain2.assistGoal_138 = 10;
    pemain2.tim_138 = "Al-Nassr FC";

    // Menampilkan informasi pemain2
    cout << "Nama: " << pemain2.nama_138 << endl;
    cout << "Umur: " << pemain2.umur_138 << endl;
    cout << "Goal: " << pemain2.Goal_138 << endl;
    cout << "Assist Goal: " << pemain2.assistGoal_138 << endl;
    cout << "Tim: " << pemain2.tim_138 << endl;
    cout << "----------------------" << endl;

    return 0;
}


```
#### Output:
![SS_Unguided2_RicoAdePratama_2311102138](/pertemuan01/LAPRAK01/SS_Unguided2_RicoAdePratama_2311102138.png)

Kode di atas digunakan untuk mendefinisikan sebuah class 'PemainSepakBola' dan sebuah struct 'PemainSepakBolaStruct' untuk merepresentasikan informasi seorang pemain sepak bola. Class dan struct tersebut memiliki atribut-atribut seperti nama, umur, jumlah goal, jumlah assist goal, dan tim. Dalam program main(), objek pertama (pemain1) dibuat menggunakan class 'PemainSepakBola' dan diisi dengan data seperti nama Lionel Messi, umur 36 tahun, jumlah goal 30, jumlah assist goal 15, dan tim Inter Miami FC. Objek tersebut kemudian ditampilkan menggunakan metode print() yang ada di dalam class. Selanjutnya, objek kedua (pemain2) dibuat menggunakan struct 'PemainSepakBolaStruct' dan diisi dengan data seperti nama Cristiano Ronaldo, umur 39 tahun, jumlah goal 51, jumlah assist goal 10, dan tim Al-Nassr FC. Informasi objek kedua ditampilkan secara langsung dengan menggunakan cout.

Fungsi Class dalam 'PemainSepakBola':
1. Atribut: Menyimpan informasi pemain sepak bola seperti nama, umur, jumlah gol, jumlah assist goal, dan tim.
2. Method print(): Digunakan untuk menampilkan informasi pemain sepak bola ke layar.
3. Objek pemain1: Membuat objek dari class 'PemainSepakBola' bernama pemain1 dan mengisi data pemain tersebut.
4. Pemanggilan pemain1.print(): Menampilkan informasi pemain1 dengan menggunakan method print().

Fungsi Struct dalam 'PemainSepakBolaStruct':
1. Atribut: Sama seperti class, menyimpan informasi pemain sepak bola seperti nama, umur, jumlah gol, jumlah assist goal, dan tim.
2. Objek pemain2: Membuat objek dari struct 'PemainSepakBolaStruct' bernama pemain2 dan mengisi data pemain tersebut.
3. Pemanggilan langsung: Informasi pemain2 ditampilkan langsung tanpa menggunakan method khusus seperti pada class.

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.]

```C++
// LAPRAK 1 : UNGUIDED 3
// RICO ADE PRATAMA
// 2311102138
// S1 IF-11-D

#include <iostream>
#include <map>

using namespace std;

// Struktur data untuk menyimpan informasi pemain sepak bola
struct PemainSepakBola {
    string nama_138;
    string klub_138;
};

int main() {
    // Deklarasi map dengan key int dan value berupa objek PemainSepakBola
    map<int, PemainSepakBola> club_138;

    // Menambahkan data pemain sepak bola ke dalam map
    club_138[1] = {"Cristiano Ronaldo", "Al-Nassr FC"};
    club_138[2] = {"Lionel Messi", "Inter Miami FC"};
    club_138[3] = {"Neymar Junior", "Al-Hilal FC"};
    club_138[4] = {"Kylian Mbappe", "Paris Saint-Germain FC"}; 
    club_138[5] = {"Mohamed Salah", "Liverpool FC"};

    cout << "TOP SKOR PEMAIN SEPAK BOLA DUNIA" << endl;

    // Perulangan for menggunakan range-based for loop
    for (int i = 1; i <= club_138.size(); ++i) {
        cout << "Nomor " << i << "  Atas Nama: " << club_138[i].nama_138 << ",  Bermain di: " << club_138[i].klub_138 << endl;
    }

    return 0;
}


```
#### Output:
![SS_Unguided3_RicoAdePratama_2311102138](/pertemuan01/LAPRAK01/SS_Unguided3_RicoAdePratama_2311102138.png)

Kode di atas digunakan untuk implementasi sederhana untuk menampilkan informasi 'TOP SKOR PEMAIN SEPAK BOLA DUNIA'. Program menggunakan struktur data map untuk menyimpan informasi pemain sepak bola, di mana nomor pemain menjadi kunci (key), dan objek PemainSepakBola menjadi nilai (value). Setelah data pemain sepak bola ditambahkan ke dalam map, program melakukan perulangan menggunakan range-based for loop untuk mencetak informasi setiap pemain, termasuk nomor, nama, dan klubnya.

Perbedaan antara Array dan Map adalah bagaimana elemen disimpan dan diakses. Contoh perbedaan utama: 
1. Penyimpanan Data: 
 Array: Menyimpan elemen berurutan di lokasi berurutan. Elemen diakses menggunakan indeks numerik.
 Map : Menyimpan pasangan nilai key. Setiap elemen dapat diakses melalui key unik.
2. Indeks atau Key: 
 Array: Akses elemen menggunakan indeks numerik (biasanya dimulai dari 0).
 Map : Gunakan key (dari tipe data apa pun) untuk mengakses nilai terkait.
3. Ukuran: 
 Array: Ukuran tetap saat deklarasi dan tidak dapat diubah saat runtime.
 Map : bersifat dinamis dan dapat bertambah atau menyusut saat program sedang berjalan.
4. Kecepatan Pencarian: 
 Array: Pencarian menggunakan indeks bisa lebih cepat karena posisi elemen dapat dihitung secara langsung.
 Map : Pencarian  menggunakan key dan kecepatan pencarian bergantung pada implementasi struktur data.
5. Fitur dengan key unik: 
 Array: Semua indeks harus unik, tetapi nilai elemen dapat diulang.
 Map : Setiap key harus unik dan setiap key memiliki nilai yang ditetapkan padanya.

Dalam kasus program di atas, map digunakan untuk menyimpan data pemain sepak bola menggunakan nomor sebagai key atau kuncinya, memungkinkan akses langsung ke informasi pemain berdasarkan nomor tertentu. Hal ini membuat map lebih fleksibel dalam situasi di mana key tidak perlu berurutan atau dibatasi pada nomor atau nilai numerik tertentu.

## Kesimpulan
Kesimpulannya, Pemahaman tipe data C++ sangat penting dalam pengembangan perangkat lunak dan membantu programmer dalam mengelola data dengan cara yang sesuai. Penggunaan tipe data primitif, seperti int, float, dan char, memberikan efisiensi dalam penggunaan memori dan operasi matematika dasar. Serta Penggunaan class dan struct dalam C++ tergantung pada kebutuhan dan desain program. Class lebih canggih dengan dukungan enkapsulasi, pewarisan, dan hak akses, sementara struct lebih sederhana dan cocok untuk menyimpan data terstruktur tanpa banyak fungsionalitas tambahan. Selain itu, struktur data seperti array dan map memungkinkan penyimpanan dan akses data yang terorganisir.

## Referensi
[1] Asisten Praktikum. Modul 1 : Tipe Data 1. UNIVERSITAS TELKOM PURWOKERTO, 2024
[2] Putri Muslina. Dasar-Dasar Pemprograman Komputer. UNIVERSITAS ADZKIA PADANG, 2023.
[3] A Zein, & ES Eriana. ALGORITMA DAN STRUKTUR DATA Universitas Pamulang Tangerang Selatan – Banten, 2022.