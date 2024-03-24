#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <limits>

using namespace std;

void judul() {
    cout << "+----------------------------------------+" << endl;
    cout << "|   SELAMAT DATANG DI KOPERASI SEKOLAH   |" << endl;
    cout << "+----------------------------------------+" << endl;
}

// Deklarasi struct koperasi
struct Barang {
    string nama;
    int harga;
    int stok;
};

// Array of struct Barang
Barang daftarBarang[100];
int jumlahBarang = 0;

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
            return login(attempts - 1); // Panggil rekursi dengan mengurangi jumlah percobaan
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
    cout << "|     [5] KELUAR                       |" << endl;
    cout << "+--------------------------------------+" << endl;
}

// Fungsi untuk menampilkan daftar barang
void tampilkanBarang() {
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang yang tersedia saat ini." << endl;
    } else {
        cout << "Daftar Barang di Koperasi:" << endl;
        for (int i = 0; i < jumlahBarang; i++) {
            cout << "Barang ke-" << i + 1 << ":" << endl;
            cout << "Nama Barang: " << daftarBarang[i].nama << endl;
            cout << "Harga: " << daftarBarang[i].harga << endl;
            cout << "Stok: " << daftarBarang[i].stok << endl;
            cout << endl;
        }
    }
    cout << "Tekan Enter untuk kembali ke menu utama..."; 
    getch();
}

// Fungsi untuk menambahkan barang
void tambahBarang() {
    if (jumlahBarang >= 100) {
        cout << "Koperasi sudah penuh, tidak dapat menambah barang lagi." << endl;
    } else {
        cout << "Masukkan Nama Barang: ";
        cin >> daftarBarang[jumlahBarang].nama;
        cout << "Masukkan Harga Barang: ";
        cin >> daftarBarang[jumlahBarang].harga;
        cout << "Masukkan Stok Barang: ";
        cin >> daftarBarang[jumlahBarang].stok;
        jumlahBarang++;
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

    while (true) {
        tampilMenu();
        int pilih;
        cout << "Pilih menu : ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                tambahBarang();
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
                cout << "Terima kasih. Sampai jumpa!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silahkan pilih lagi." << endl;
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard input buffer
                break;
                getch();
        }
    }
    return 0;
}
