// LAPRAK 1 : UNGUIDED 2
// Ramadhika Primadana
// 2311102141
// S1 IF-11-D

#include <iostream>
#include <string>

using namespace std;

// class PemainSepakBola
class PemainSepakBola {
public:
    // atribut
    string nama_141;
    int umur_141;
    int Goal_141;
    int assistGoal_141;
    string tim_141;

    // method
    void print() {
        cout << "Nama: " << nama_141 << endl;
        cout << "Umur: " << umur_141 << endl;
        cout << "Goal: " << Goal_141 << endl;
        cout << "Assist Goal: " << assistGoal_141 << endl;
        cout << "Tim: " << tim_141 << endl;
        cout << "----------------------" << endl;
    }
};

// struct PemainSepakBolaStruct
struct PemainSepakBolaStruct {
    // atribut
    string nama_141;
    int umur_141;
    int Goal_141;
    int assistGoal_141;
    string tim_141;
};

int main() {
    // Membuat objek dari class PemainSepakBola dan mengisi data
    PemainSepakBola pemain1;
    pemain1.nama_141 = "Muhammad Salah";
    pemain1.umur_141 = 36;
    pemain1.Goal_141 = 30;
    pemain1.assistGoal_141 = 15;
    pemain1.tim_141 = "Liverpool";

    // Menampilkan informasi pemain1
    pemain1.print();

    // Membuat objek dari struct PemainSepakBolaStruct dan mengisi data
    PemainSepakBolaStruct pemain2;
    pemain2.nama_141 = "Cristiano Ronaldo";
    pemain2.umur_141 = 39;
    pemain2.Goal_141 = 51;
    pemain2.assistGoal_141 = 10;
    pemain2.tim_141 = "Al-Nassr FC";

    // Menampilkan informasi pemain2
    cout << "Nama: " << pemain2.nama_141 << endl;
    cout << "Umur: " << pemain2.umur_141 << endl;
    cout << "Goal: " << pemain2.Goal_141 << endl;
    cout << "Assist Goal: " << pemain2.assistGoal_141 << endl;
    cout << "Tim: " << pemain2.tim_141 << endl;
    cout << "----------------------" << endl;

    return 0;
}
