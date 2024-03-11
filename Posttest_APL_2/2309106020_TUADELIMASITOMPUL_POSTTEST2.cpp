#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;

// Deklarasi awal fungsi login
int login();

// Deklarasi struct koperasi
struct koperasi {
    char barang[30];
    float harga;
    int stok;
};

// Deklarasi array bin
koperasi bin[30];

int login() {
    string username = "Delima";
    string password = "2309106020";

    int percobaan = 0;

    do {
        string inputUsername, inputPassword;
        cout << "Masukkan Username: ";
        cin >> inputUsername;
        cout << "Masukkan password: ";
        cin >> inputPassword;

        if (inputUsername == username && inputPassword == password) {
            cout << "Login berhasil. Selamat datang " << username << "!\n";
            return 0; 
        }
        else {
            cout << "Login gagal. Silahkan coba lagi.\n";
            percobaan++;
        }
    }
    while (percobaan < 3);

    if (percobaan == 3) {
        cout << "Anda telah mencoba login sebanyak 3 kali. Akses ditolak.\n";
        return 1;
    }
}



void menu() {
    int pilih, jumlah, i, indeks;
    while (true) {
        system("cls");
        cout<<"\t+--------------------------------------+"<<endl;
	    cout<<"\t|         MENU KOPERASI SEKOLAH        |"<<endl;
	    cout<<"\t|======================================|"<<endl;
	    cout<<"\t|     [1] TAMBAH BARANG                |"<<endl;
	    cout<<"\t|     [2] TAMPILKAN BARANG             |"<<endl;
	    cout<<"\t|     [3] HAPUS BARANG                 |"<<endl;
        cout<<"\t|     [4] UBAH BARANG                  |"<<endl;
        cout<<"\t|     [5] KELUAR                       |"<<endl;
	    cout<<"\t+--------------------------------------+\n"<<endl;
        cout <<"Pilih menu : ";
        cin >> pilih;

        if (pilih == 1) {
            cout<<"Masukkan jumlah barang yang ingin ditambahkan: ";
            cin >> jumlah;
            for (i = 0; i < jumlah; i++) {
                cout << "Barang ke-" << i+1 << ":\n";
                cout << "Nama Barang: ";
                cin >> bin[i].barang;
                cout << "Harga: ";
                cin >> bin[i].harga;
                cout << "Stok: ";
                cin >> bin[i].stok; 
            }
        }
        else if (pilih == 2) {
             if(jumlah == 0){
                cout<<"Tidak ada barang yang tersedia saat ini.\n";
            }else{
            cout << "\nDaftar Barang di Koperasi:\n";
            for (i = 0; i < jumlah; i++) {
                cout << "Barang ke-" << i+1 << ":\n";
                cout << "Nama Barang: " << bin[i].barang << endl;
                cout << "Harga: " << bin[i].harga << endl;
                cout << "Stok: " << bin[i].stok << endl;
               }
            cout <<"\n Tekan enter untuk melanjutkan..";
            getch();
            }
        } 
        else if (pilih == 3) {
            cout << "Masukkan indeks barang yang ingin dihapus: ";
            cin >> indeks;
            if (indeks < jumlah && indeks >= 0) {
                for (i = indeks; i < jumlah - 1; i++) {
                    bin[i].harga = bin[i + 1].harga;
                    bin[i].stok = bin[i + 1].stok;
                }
                jumlah--;
                cout << "Barang berhasil dihapus.\n";
            }
            else {
                cout << "Indeks barang tidak valid.\n";
            }
        }
        else if (pilih == 4) {
            cout << "Masukkan indeks barang yang ingin diubah: ";
            cin >> indeks;
            if (indeks < jumlah && indeks >= 0) {
                cout << "Nama Barang: ";
                cin >> bin[indeks].barang;
                cout << "Harga: ";
                cin >> bin[indeks].harga;
                cout << "Stok: ";
                cin >> bin[indeks].stok;
                cout << "Barang berhasil diubah.\n";
            }
            else {
                cout << "Indeks barang tidak valid.\n";
            }
        }
        else if (pilih == 5) {
            cout << "Terima kasih. Sampai jumpa!\n";
            break;
        }
            else {
            cout << "Pilihan tidak valid. Silahkan pilih lagi.\n";
        }
    }
}

int main() {
    if (login() == 1) {
        return 1; 
    }

    menu();

    return 0;
}


