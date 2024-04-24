#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <algorithm> 
#include <limits>
using namespace std;

struct Barang {
    string nama;
    int harga;
    int stok;
};

// Array of struct Barang
Barang daftarBarang[100];
int jumlahBarang = 0;

// Fungsi untuk sorting huruf secara descending (Bubble Sort)
void sortingHurufDescending() {
    for (int i = 0; i < jumlahBarang - 1; ++i) {
        for (int j = 0; j < jumlahBarang - i - 1; ++j) {
            if (daftarBarang[j].nama < daftarBarang[j + 1].nama) {
                swap(daftarBarang[j], daftarBarang[j + 1]);
            }
        }
    }
}

// Fungsi untuk sorting angka secara ascending (Insertion Sort)
void sortingAngkaAscending() {
    for (int i = 1; i < jumlahBarang; ++i) {
        Barang key = daftarBarang[i];
        int j = i - 1;
        while (j >= 0 && daftarBarang[j].harga > key.harga) {
            daftarBarang[j + 1] = daftarBarang[j];
            j = j - 1;
        }
        daftarBarang[j + 1] = key;
    }
}

//  searching data pada kumpulan data yang terurut secara ascending 
int binarySearchAscending(int hargaCari) {
    int kiri = 0, kanan = jumlahBarang - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (daftarBarang[tengah].harga == hargaCari)
            return tengah;
        if (daftarBarang[tengah].harga < hargaCari)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return -1;
}

// searching data pada kumpulan data yang terurut secara descending 
int reverseBinarySearchDescending(int hargaCari) {
    int kiri = 0, kanan = jumlahBarang - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (daftarBarang[tengah].harga == hargaCari)
            return tengah;
        if (daftarBarang[tengah].harga < hargaCari)
            kanan = tengah - 1;
        else
            kiri = tengah + 1;
    }
    return -1;
}

void judul() {
    cout << "+----------------------------------------+" << endl;
    cout << "|   SELAMAT DATANG DI KOPERASI SEKOLAH   |" << endl;
    cout << "+----------------------------------------+" << endl;
}

// Deklarasi fungsi login
bool login(int attempts = 3) {
    string username = "Delima";
    string password = "2309106020";

    string inputUsername, inputPassword;
    cout << "Masukkan Username: ";
    cin >> inputUsername;
    cout << "Masukkan password: ";
    cin >> inputPassword;

    if (inputUsername == username && inputPassword == password) {
        cout << "Login berhasil. Selamat datang, " << username << "!" << endl;
        return true;
    } else {
        cout << "Login gagal. Silahkan coba lagi." << endl;
        if (attempts > 1)
            return login(attempts - 1); 
        else {
            cout << "Anda telah mencoba login sebanyak 3 kali. Akses ditolak." << endl;
            return false;
        }
    }
}

// Fungsi untuk menampilkan menu
void tampilMenu() {
    system("cls");
    cout << "+--------------------------------------+" << endl;
    cout << "|         MENU KOPERASI SEKOLAH        |" << endl;
    cout << "|======================================|" << endl;
    cout << "|     [1] TAMBAH BARANG                |" << endl;
    cout << "|     [2] TAMPILKAN BARANG             |" << endl;
    cout << "|     [3] HAPUS BARANG                 |" << endl;
    cout << "|     [4] UBAH BARANG                  |" << endl;
    cout << "|     [5] SORTING HURUF DESCENDING     |" << endl;
    cout << "|     [6] SORTING ANGKA ASCENDING      |" << endl;
    cout << "|     [7] SEARCH ASCENDING             |" << endl;
    cout << "|     [8] SEARCH DESCENDING            |" << endl;
    cout << "|     [9] KELUAR                       |" << endl;
    cout << "+--------------------------------------+" << endl;
}

// Fungsi untuk menampilkan daftar barang
void tampilkanBarang() {
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang yang tersedia saat ini." << endl;
    } else {
        cout << "Daftar Barang di Koperasi :" << endl;
        for (int i = 0; i < jumlahBarang; i++) {
            cout << "Barang ke-" << i + 1 << ":" << endl;
            cout << "Nama Barang : " << daftarBarang[i].nama << endl;
            cout << "Harga       : " << daftarBarang[i].harga << endl;
            cout << "Stok        : " << daftarBarang[i].stok << endl;
            cout << "---------------------------------------"<<endl;
        }
    }
    cout << "Tekan Enter untuk kembali ke menu utama..."; 
    getch();
}

// Fungsi untuk menambahkan barang dengan parameter address-of
void tambahBarang(Barang* barangBaru) {
    if (jumlahBarang >= 100) {
        cout << "Koperasi sudah penuh, tidak dapat menambah barang lagi." << endl;
    } else {
        cout << "Masukkan Nama Barang  : ";
        cin >> barangBaru->nama;
        cout << "Masukkan Harga Barang : ";
        cin >> barangBaru->harga;
        cout << "Masukkan Stok Barang  : ";
        cin >> barangBaru->stok;
        jumlahBarang++;
        sortingHurufDescending(); 
        cout << "Barang berhasil ditambahkan!" << endl;
    }
    cout << "Tekan Enter untuk kembali ke menu utama..."; 
    getch();
}

// Fungsi untuk menghapus barang
void hapusBarang() {
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang yang tersedia untuk dihapus." << endl;
    } else {
        int indeks;
        cout << "Masukkan indeks barang yang ingin dihapus: ";
        cin >> indeks;
        if (indeks >= 1 && indeks <= jumlahBarang) {
            for (int i = indeks - 1; i < jumlahBarang - 1; i++) {
                daftarBarang[i] = daftarBarang[i + 1];
            }
            jumlahBarang--;
            cout << "Barang berhasil dihapus!" << endl;
        } else {
            cout << "Indeks barang tidak valid." << endl;
        }
    }
    cout << "Tekan Enter untuk kembali ke menu utama..."; 
    getch();
}

// Fungsi untuk mengubah barang
void ubahBarang() {
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang yang tersedia untuk diubah." << endl;
    } else {
        int indeks;
        cout << "Masukkan indeks barang yang ingin diubah: ";
        cin >> indeks;
        if (indeks >= 1 && indeks <= jumlahBarang) {
            cout << "Masukkan Nama Barang: ";
            cin >> daftarBarang[indeks - 1].nama;
            cout << "Masukkan Harga Barang: ";
            cin >> daftarBarang[indeks - 1].harga;
            cout << "Masukkan Stok Barang: ";
            cin >> daftarBarang[indeks - 1].stok;
            sortingHurufDescending();
            cout << "Barang berhasil diubah!" << endl;
        } else {
            cout << "Indeks barang tidak valid." << endl;
        }
    }
    cout << "Tekan Enter untuk kembali ke menu utama..."; 
    getch();
}

int main() {
    judul();
    if (!login()) {
        cout << "Aplikasi ditutup." << endl;
        return 1;
    }

    int hasilAsc, hasilDesc;

    while (true) {
        tampilMenu();
        int pilih;
        cout << "Pilih menu : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                tambahBarang(&daftarBarang[jumlahBarang]);
                break;
            case 2:
                tampilkanBarang();
                break;
            case 3:
                hapusBarang();
                break;
            case 4:
                ubahBarang();
                break;
            case 5:
                sortingHurufDescending();
                cout << "Sorting huruf secara descending selesai." << endl;
                break;
            case 6:
                sortingAngkaAscending();
                cout << "Sorting angka secara ascending selesai." << endl;
                break;
            case 7:
                // Panggil fungsi searching pada data terurut secara ascending
                int hargaCariAsc;
                cout << "Masukkan harga yang ingin dicari: ";
                cin >> hargaCariAsc;
                hasilAsc = binarySearchAscending(hargaCariAsc);
                if (hasilAsc != -1)
                    cout << "Barang dengan harga " << hargaCariAsc << " ditemukan pada indeks " << hasilAsc << endl;
                else
                    cout << "Barang dengan harga " << hargaCariAsc << " tidak ditemukan." << endl;
                break;
            case 8:
                // Panggil fungsi searching pada data terurut secara descending
                int hargaCariDesc;
                cout << "Masukkan harga yang ingin dicari: ";
                cin >> hargaCariDesc;
                hasilDesc = reverseBinarySearchDescending(hargaCariDesc); 
                if (hasilDesc != -1)
                    cout << "Barang dengan harga " << hargaCariDesc << " ditemukan pada indeks " << hasilDesc << endl;
                else
                    cout << "Barang dengan harga " << hargaCariDesc << " tidak ditemukan." << endl;
                break;
            case 9:
                cout << "Terima kasih. Sampai jumpa!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silahkan pilih lagi." << endl;
                cin.clear(); 
                cin.ignore(); 
                break;
        }
    }
    return 0;
}
