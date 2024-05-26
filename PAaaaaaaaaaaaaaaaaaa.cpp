#include <iostream>
#include <fstream>
#include <conio.h>
#include <sstream>
#include <string>
#include <unistd.h>
using namespace std;

int jumlahSuratMasuk = 0;
int jumlahSuratKeluar = 0;
int max_masuk[100];
int max_keluar[100];

int main();
int menu_admin();

struct Suratmsk
{
    string tanggal_masuk;
    string tanggal_surat;
    string nomor_surat;
    string asal_surat;
    string perihal;
    string keterangan;
};

struct Suratklr
{
    string tanggal_keluar;
    string tanggal_surat;
    string nomor_surat;
    string tujuan_surat;
    string perihal;
    string keterangan;
};

Suratmsk suratMasuk[100];
Suratklr suratKeluar[100];

void surat_masuk(Suratmsk *suratMasuk, int &jumlahSuratMasuk)
{
    string ulang;
    int nomorUrutan = 1; // Variabel untuk nomor urutan
    cin.ignore();
    do
    {
        if (jumlahSuratMasuk < 100)
        {
            // system("cls");
            cout << "\nTanggal             : ";
            cin >> suratMasuk[jumlahSuratMasuk].tanggal_masuk;
            cin.ignore();
            cout << "Tanggal pelaksanaan : ";
            fflush(stdin); // Untuk membersihkan buffer sebelum menggunakan getline
            getline(cin, suratMasuk[jumlahSuratMasuk].tanggal_surat);
            cout << "Nomor surat         : ";
            fflush(stdin);
            getline(cin, suratMasuk[jumlahSuratMasuk].nomor_surat);
            cout << "Pengirim/asal surat : ";
            fflush(stdin);
            getline(cin, suratMasuk[jumlahSuratMasuk].asal_surat);
            cout << "Perihal             : ";
            fflush(stdin);
            getline(cin, suratMasuk[jumlahSuratMasuk].perihal);
            cout << "Lampiran            : ";
            fflush(stdin);
            getline(cin, suratMasuk[jumlahSuratMasuk].keterangan);

            // Menyimpan data ke dalam file
            ofstream file("data_surat_masuk.txt", ios::app); // Membuka file untuk menambahkan data baru di belakang
            if (file.is_open()) {
                file << suratMasuk[jumlahSuratMasuk].tanggal_masuk << endl;
                file << suratMasuk[jumlahSuratMasuk].tanggal_surat << endl;
                file << suratMasuk[jumlahSuratMasuk].nomor_surat << endl;
                file << suratMasuk[jumlahSuratMasuk].asal_surat << endl;
                file << suratMasuk[jumlahSuratMasuk].perihal << endl;
                file << suratMasuk[jumlahSuratMasuk].keterangan << endl;
                file.close();
                cout << "\nData surat masuk berhasil disimpan ke dalam file." << endl;
                cout << "Surat berhasil ditambahkan." << endl;
            } else {
                cout << "Gagal menyimpan data." << endl;
            }

            jumlahSuratMasuk++;
            // nomorUrutan++; // Increment nomor urutan
        }
        else
        {
            cout << "Batas maksimum surat masuk telah tercapai." << endl;
            break;
        }

        cout << endl;
        cout << "Ulangi (y/t) : ";
        cin >> ulang;
        cin.ignore(); // Membersihkan buffer setelah input karakter y/t

    } while (ulang == "y");
}

void insertion_sort_masuk(Suratmsk suratMasuk[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Suratmsk key = suratMasuk[i];
        int j = i - 1;

        // Membandingkan tanggal masuk dalam format YYYYMMDD untuk memastikan urutan tanggal yang benar
        while (j >= 0 && suratMasuk[j].tanggal_masuk < key.tanggal_masuk)
        {
            suratMasuk[j + 1] = suratMasuk[j];
            j = j - 1;
        }
        suratMasuk[j + 1] = key;
    }
}

int lihat_surat_masuk(Suratmsk *suratMasuk, int &jumlahSuratMasuk)
{
    system("cls");
    ifstream file("data_surat_masuk.txt");

    if (file.is_open()) 
    {
        jumlahSuratMasuk = 0; // Reset jumlahSuratMasuk
        while (getline(file, suratMasuk[jumlahSuratMasuk].tanggal_masuk)) 
        {
            getline(file, suratMasuk[jumlahSuratMasuk].tanggal_surat);
            getline(file, suratMasuk[jumlahSuratMasuk].nomor_surat);
            getline(file, suratMasuk[jumlahSuratMasuk].asal_surat);
            getline(file, suratMasuk[jumlahSuratMasuk].perihal);
            getline(file, suratMasuk[jumlahSuratMasuk].keterangan);
            jumlahSuratMasuk++; // Update jumlahSuratMasuk
        }
        file.close();
        if (jumlahSuratMasuk > 0)
        {
            insertion_sort_masuk(suratMasuk, jumlahSuratMasuk);
            cout << "Daftar Surat Masuk\n" << endl;
            for (int i = 0; i < jumlahSuratMasuk; ++i)
            {
                cout << "Surat ke-" << i+1 << endl;
                cout << "Tanggal masuk surat  : " << suratMasuk[i].tanggal_masuk << endl;
                cout << "Tanggal pelaksanaan  : " << suratMasuk[i].tanggal_surat << endl;
                cout << "Nomor surat          : " << suratMasuk[i].nomor_surat << endl;
                cout << "Pengirim/asal surat  : " << suratMasuk[i].asal_surat << endl;
                cout << "Perihal              : " << suratMasuk[i].perihal << endl;
                cout << "Lampiran             : " << suratMasuk[i].keterangan << endl;
                cout << endl;
            }
        }
        else
        {
            cout << "Daftar Surat Masuk Kosong." << endl;
        }
    }
    else
    {
        cout << "Data surat masuk kosong." << endl;
    }

    // Menulis kembali data ke file setelah pembaruan
        ofstream files("data_surat_masuk.txt", ios::out | ios::trunc);
        if (files.is_open()) {
            for (int i = 0; i < jumlahSuratMasuk; ++i) {
                files << suratMasuk[i].tanggal_masuk << endl;
                files << suratMasuk[i].tanggal_surat << endl;
                files << suratMasuk[i].nomor_surat << endl;
                files << suratMasuk[i].asal_surat << endl;
                files << suratMasuk[i].perihal << endl;
                files << suratMasuk[i].keterangan << endl;
            }
            files.close();
        } else {
            cout << "Gagal menyimpan data." << endl;
        }
    return 1;
}

void update_surat_masuk(Suratmsk *suratMasuk, int jumlahSuratMasuk)
{
    string ulang;
    do{
        // system("cls");
        int nomorUrut;
        bool found = false;

        insertion_sort_masuk(suratMasuk, jumlahSuratMasuk);
        lihat_surat_masuk(suratMasuk, jumlahSuratMasuk);

        // Meminta indeks surat yang ingin diupdate dari pengguna
        cout << "\nMasukkan indeks surat yang ingin diupdate : ";
        cin >> nomorUrut;
        cin.ignore();

        // Mencari indeks surat 
        for (int i = 0; i < jumlahSuratMasuk; ++i) {
            if (nomorUrut >= 1 && nomorUrut <= jumlahSuratMasuk)
            {
                // Menggeser indeks surat
                int index = nomorUrut - 1;

                // Variabel sementara untuk menyimpan data baru
                Suratmsk temp;

                // Meminta data baru dari pengguna
                cout << "Masukkan data baru untuk surat masuk pada surat ke- " << nomorUrut << "\n" << endl;
                cout << endl;
                
                cout << "Tanggal masuk surat : ";
                getline(cin, temp.tanggal_masuk);
                fflush(stdin);
                if (temp.tanggal_masuk.empty()) {
                    temp.tanggal_masuk = suratMasuk[i].tanggal_masuk; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Tanggal pelaksanaan : ";
                getline(cin, temp.tanggal_surat);
                fflush(stdin);
                if (temp.tanggal_surat.empty()) {
                    temp.tanggal_surat = suratMasuk[i].tanggal_surat; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Nomor surat         : ";
                getline(cin, temp.nomor_surat);
                fflush(stdin);
                if (temp.nomor_surat.empty()) {
                    temp.nomor_surat = suratMasuk[i].nomor_surat; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Pengirim/asal surat : ";
                getline(cin, temp.asal_surat);
                fflush(stdin);
                if (temp.asal_surat.empty()) {
                    temp.asal_surat = suratMasuk[i].asal_surat; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Perihal             : ";
                getline(cin, temp.perihal);
                fflush(stdin);
                if (temp.perihal.empty()) {
                    temp.perihal = suratMasuk[i].perihal; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Lampiran            : ";
                getline(cin, temp.keterangan);
                fflush(stdin);
                if (temp.keterangan.empty()) {
                    temp.keterangan = suratMasuk[i].keterangan; // Gunakan nilai yang lama jika input kosong
                }

                // Memperbarui data jika nomor surat ditemukan
                suratMasuk[index] = temp;
                found = true;
                cout << "\nData surat berhasil diupdate." << endl;
                break;
            }
        }

        // Jika nomor surat tidak ditemukan dalam array suratMasuk
        if (!found)
        {
            cout << "Indeks surat tidak ditemukan." << endl;
        }

        // Menulis kembali data ke file setelah pembaruan
        ofstream file("data_surat_masuk.txt", ios::out | ios::trunc);
        if (file.is_open()) {
            for (int i = 0; i < jumlahSuratMasuk; ++i) {
                file << suratMasuk[i].tanggal_masuk << endl;
                file << suratMasuk[i].tanggal_surat << endl;
                file << suratMasuk[i].nomor_surat << endl;
                file << suratMasuk[i].asal_surat << endl;
                file << suratMasuk[i].perihal << endl;
                file << suratMasuk[i].keterangan << endl;
            }
            file.close();
            cout << "Data berhasil disimpan ke dalam file." << endl;
        } else {
            cout << "Gagal menyimpan data." << endl;
        }
        cout << endl;
        cout << "Ulangi (y/t) : ";
        cin >> ulang;
        cin.ignore();

    } while (ulang == "y");
}


void delete_surat_masuk(Suratmsk *suratMasuk, int &jumlahSuratMasuk)
{
    string ulang;
    do{
        // system("cls");
        int nomorUrut;
        bool found = false;
        lihat_surat_masuk(suratMasuk, jumlahSuratMasuk);

    // Meminta indeks surat yang ingin dihapus pengguna
        cout << "\nMasukkan indeks surat yang ingin dihapus: ";
        cin >> nomorUrut;

        // Mencari indeks surat 
            if (nomorUrut >= 1 && nomorUrut <= jumlahSuratMasuk)
            {
                // Menggeser indeks surat
                int index = nomorUrut - 1;

                // Menggeser data ke atas untuk menggantikan data yang dihapus
                for (int i = index ; i < jumlahSuratMasuk - 1; ++i)
                {
                    suratMasuk[i] = suratMasuk[i + 1];
                }

                // Mengurangi jumlah surat masuk karena satu surat telah dihapus
                jumlahSuratMasuk--;

                found = true;
                cout << "Surat ke-" << nomorUrut << " berhasil dihapus." << endl;
            }
        

        // Jika nomor surat tidak ditemukan dalam array suratMasuk
        if (!found)
        {
            cout << "Indeks surat tidak ditemukan." << endl;
        }


        ofstream file("data_surat_masuk.txt", ios::out | ios::trunc);
        if (file.is_open()) {
            for (int i = 0; i < jumlahSuratMasuk; ++i) {
                file << suratMasuk[i].tanggal_masuk << endl;
                file << suratMasuk[i].tanggal_surat << endl;
                file << suratMasuk[i].nomor_surat << endl;
                file << suratMasuk[i].asal_surat << endl;
                file << suratMasuk[i].perihal << endl;
                file << suratMasuk[i].keterangan << endl;
            }
            file.close();
            cout << "Data berhasil disimpan ke dalam file." << endl;
        } else {
            cout << "Gagal menyimpan data." << endl;
        }

    cout << endl;
    cout << "Ulangi (y/t) : ";
    cin >> ulang;
    cin.ignore();

    } while (ulang == "y");
}

void binary_search_masuk(Suratmsk *suratMasuk, int jumlahSuratMasuk) {

    string tanggalDicari, ulang;
    lihat_surat_masuk(suratMasuk, jumlahSuratMasuk);
    cout << "\nMasukkan tanggal surat masuk yang ingin dicari (format: YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, tanggalDicari);

    int left = 0;
    int right = jumlahSuratMasuk - 1;
    bool ditemukan = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (suratMasuk[mid].tanggal_masuk == tanggalDicari) {
            ditemukan = true;
            cout << "\nSurat ditemukan\n"<< endl;
            cout << "Tanggal masuk  : " << suratMasuk[mid].tanggal_masuk << "\n";
            cout << "Tanggal surat  : " << suratMasuk[mid].tanggal_surat << "\n";
            cout << "Nomor surat    : " << suratMasuk[mid].nomor_surat << "\n";
            cout << "Asal surat     : " << suratMasuk[mid].asal_surat << "\n";
            cout << "Perihal        : " << suratMasuk[mid].perihal << "\n";
            cout << "Lampiran       : " << suratMasuk[mid].keterangan << "\n";
            break;
        } else if (suratMasuk[mid].tanggal_masuk < tanggalDicari) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!ditemukan) {
        cout << "\nSurat tidak ditemukan.\n";
    }
    
    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    getche();
}

void surat_keluar(Suratklr *suratKeluar, int &jumlahSuratKeluar)
{
    string ulang;
    int nomorUrutan = 1; // Variabel untuk nomor urutan
    cin.ignore();
    do
    {
        if (jumlahSuratKeluar < 100)
        {
            // system("cls");
            cout << "\nTanggal             : ";
            cin >> suratKeluar[jumlahSuratKeluar].tanggal_keluar;
            cin.ignore();
            cout << "Tanggal pelaksanaan : ";
            fflush(stdin); // Untuk membersihkan buffer sebelum menggunakan getline
            getline(cin, suratKeluar[jumlahSuratKeluar].tanggal_surat);
            cout << "Nomor surat         : ";
            fflush(stdin);
            getline(cin, suratKeluar[jumlahSuratKeluar].nomor_surat);
            cout << "Tujuan surat        : ";
            fflush(stdin);
            getline(cin, suratKeluar[jumlahSuratKeluar].tujuan_surat);
            cout << "Perihal             : ";
            fflush(stdin);
            getline(cin, suratKeluar[jumlahSuratKeluar].perihal);
            cout << "Lampiran            : ";
            fflush(stdin);
            getline(cin, suratKeluar[jumlahSuratKeluar].keterangan);

            // Menyimpan data ke dalam file
            ofstream file("data_surat_keluar.txt", ios::app); // Membuka file untuk menambahkan data baru di belakang
            if (file.is_open()) {
                file << suratKeluar[jumlahSuratKeluar].tanggal_keluar << endl;
                file << suratKeluar[jumlahSuratKeluar].tanggal_surat << endl;
                file << suratKeluar[jumlahSuratKeluar].nomor_surat << endl;
                file << suratKeluar[jumlahSuratKeluar].tujuan_surat << endl;
                file << suratKeluar[jumlahSuratKeluar].perihal << endl;
                file << suratKeluar[jumlahSuratKeluar].keterangan << endl;
                file.close();
                cout << "\nData surat keluar berhasil disimpan ke dalam file." << endl;
                cout << "Surat berhasil ditambahkan." << endl;
            } else {
                cout << "Gagal menyimpan data." << endl;
            }

            jumlahSuratMasuk++;
            // nomorUrutan++; // Increment nomor urutan
        }
        else
        {
            cout << "Batas maksimum surat keluar telah tercapai." << endl;
            break;
        }

        cout << endl;
        cout << "Ulangi (y/t) : ";
        cin >> ulang;
        cin.ignore(); // Membersihkan buffer setelah input karakter y/t

    } while (ulang == "y");
}

void insertion_sort_keluar(Suratklr suratKeluar[], int n)
{
    for (int i = 1; i < n; i++)
    {
        Suratklr key = suratKeluar[i];
        int j = i - 1;

        // Membandingkan tanggal keluar dalam format YYYYMMDD untuk memastikan urutan tanggal yang benar
        while (j >= 0 && suratKeluar[j].tanggal_keluar < key.tanggal_keluar)
        {
            suratKeluar[j + 1] = suratKeluar[j];
            j = j - 1;
        }
        suratKeluar[j + 1] = key;
    }
}

int lihat_surat_keluar(Suratklr *suratKeluar, int &jumlahSuratKeluar)
{
    system("cls");
    ifstream file("data_surat_keluar.txt");

    if (file.is_open()) 
    {
        jumlahSuratKeluar = 0; // Reset jumlahSuratKeluar
        while (getline(file, suratKeluar[jumlahSuratKeluar].tanggal_keluar)) 
        {
            getline(file, suratKeluar[jumlahSuratKeluar].tanggal_surat);
            getline(file, suratKeluar[jumlahSuratKeluar].nomor_surat);
            getline(file, suratKeluar[jumlahSuratKeluar].tujuan_surat);
            getline(file, suratKeluar[jumlahSuratKeluar].perihal);
            getline(file, suratKeluar[jumlahSuratKeluar].keterangan);
            jumlahSuratKeluar++; // Update jumlahSuratMasuk
        }
        file.close();
        if (jumlahSuratKeluar > 0)
        {
            insertion_sort_keluar(suratKeluar, jumlahSuratKeluar);
            cout << "Daftar Surat Keluar\n" << endl;
            for (int i = 0; i < jumlahSuratKeluar; ++i)
            {
                cout << "Surat ke-" << i+1 << endl;
                cout << "Tanggal keluar surat  : " << suratKeluar[i].tanggal_keluar << endl;
                cout << "Tanggal pelaksanaan   : " << suratKeluar[i].tanggal_surat << endl;
                cout << "Nomor surat           : " << suratKeluar[i].nomor_surat << endl;
                cout << "Tujuan surat          : " << suratKeluar[i].tujuan_surat << endl;
                cout << "Perihal               : " << suratKeluar[i].perihal << endl;
                cout << "Lampiran              : " << suratKeluar[i].keterangan << endl;
                cout << endl;
            }
        }
        else
        {
            cout << "Daftar Surat Keluar Kosong." << endl;
        }
    }
    else
    {
        cout << "Data surat keluar kosong." << endl;
    }
    return 1;
}

void update_surat_keluar(Suratklr *suratKeluar, int jumlahSuratKeluar)
{
    string ulang;
    do {
        // system("cls");
        int nomorUrut;
        bool found = false;

        insertion_sort_keluar(suratKeluar, jumlahSuratKeluar);   
        lihat_surat_masuk(suratMasuk, jumlahSuratMasuk);

        // Meminta indeks surat yang ingin diupdate dari pengguna
        cout << "\nMasukkan indeks surat yang ingin diupdate : ";
        cin >> nomorUrut;
        cin.ignore();

        // Mencari indeks surat 
        for (int i = 0; i < jumlahSuratKeluar; ++i) {
            if (nomorUrut >= 1 && nomorUrut <= jumlahSuratKeluar)
            {
                // Menggeser indeks surat
                int index = nomorUrut - 1;

                // Variabel sementara untuk menyimpan data baru
                Suratklr temp;

                // Meminta data baru dari pengguna
                cout << "Masukkan data baru untuk surat keluar pada surat ke- " << nomorUrut << "\n" << endl;
                cout << endl;
                
                cout << "Tanggal keluar surat : ";
                getline(cin, temp.tanggal_keluar);
                fflush(stdin);
                if (temp.tanggal_keluar.empty()) {
                    temp.tanggal_keluar = suratKeluar[i].tanggal_keluar; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Tanggal pelaksanaan : ";
                getline(cin, temp.tanggal_surat);
                fflush(stdin);
                if (temp.tanggal_surat.empty()) {
                    temp.tanggal_surat = suratKeluar[i].tanggal_surat; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Nomor surat         : ";
                getline(cin, temp.nomor_surat);
                fflush(stdin);
                if (temp.nomor_surat.empty()) {
                    temp.nomor_surat = suratKeluar[i].nomor_surat; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Tujuan surat        : ";
                getline(cin, temp.tujuan_surat);
                fflush(stdin);
                if (temp.tujuan_surat.empty()) {
                    temp.tujuan_surat = suratKeluar[i].tujuan_surat; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Perihal             : ";
                getline(cin, temp.perihal);
                fflush(stdin);
                if (temp.perihal.empty()) {
                    temp.perihal = suratKeluar[i].perihal; // Gunakan nilai yang lama jika input kosong
                }

                cout << "Lampiran            : ";
                getline(cin, temp.keterangan);
                fflush(stdin);
                if (temp.keterangan.empty()) {
                    temp.keterangan = suratKeluar[i].keterangan; // Gunakan nilai yang lama jika input kosong
                }

                // Memperbarui data jika nomor surat ditemukan
                suratKeluar[index] = temp;
                found = true;
                cout << "\nData surat berhasil diupdate." << endl;
                break;
            }
        }

        // Jika nomor surat tidak ditemukan dalam array suratKeluar
        if (!found)
        {
            cout << "Indeks surat tidak ditemukan." << endl;
        }

        // Menulis kembali data ke file setelah pembaruan
        ofstream file("data_surat_keluar.txt", ios::out | ios::trunc);
        if (file.is_open()) {
            for (int i = 0; i < jumlahSuratKeluar; ++i) {
                file << suratKeluar[i].tanggal_keluar << endl;
                file << suratKeluar[i].tanggal_surat << endl;
                file << suratKeluar[i].nomor_surat << endl;
                file << suratKeluar[i].tujuan_surat << endl;
                file << suratKeluar[i].perihal << endl;
                file << suratKeluar[i].keterangan << endl;
            }
            file.close();
            cout << "Data berhasil disimpan ke dalam file." << endl;
        } else {
            cout << "Gagal menyimpan data." << endl;
        }

    cout << endl;
    cout << "Ulangi (y/t) : ";
    cin >> ulang;
    cin.ignore();

    } while (ulang == "y");
}

void delete_surat_keluar(Suratklr *suratKeluar, int &jumlahSuratKeluar)
{
    string ulang;
    do {
        // system("cls");
        int nomorUrut;
        bool found = false;

        insertion_sort_keluar(suratKeluar, jumlahSuratKeluar);   
        lihat_surat_masuk(suratMasuk, jumlahSuratMasuk);

    // Meminta indeks surat yang ingin dihapus pengguna
        cout << "\nMasukkan indeks surat yang ingin dihapus: ";
        cin >> nomorUrut;

        // Mencari indeks surat 
        for (int i = 0; i < jumlahSuratKeluar; ++i) {
            if (nomorUrut >= 1 && nomorUrut <= jumlahSuratKeluar)
            {
                // Menggeser indeks surat
                int index = nomorUrut - 1;

                // Menggeser data ke atas untuk menggantikan data yang dihapus
                for (int i = index ; i < jumlahSuratKeluar - 1; ++i)
                {
                    suratKeluar[i] = suratKeluar[i + 1];
                }

                // Mengurangi jumlah surat keluar karena satu surat telah dihapus
                jumlahSuratKeluar--;

                found = true;
                cout << "Surat ke-" << nomorUrut << " berhasil dihapus." << endl;
            }
        }

        // Jika nomor surat tidak ditemukan dalam array suratMasuk
        if (!found)
        {
            cout << "Indeks surat tidak ditemukan." << endl;
        }

        ofstream file("data_surat_keluar.txt", ios::out | ios::trunc);
        if (file.is_open()) {
            for (int i = 0; i < jumlahSuratKeluar; ++i) {
                file << suratKeluar[i].tanggal_keluar << endl;
                file << suratKeluar[i].tanggal_surat << endl;
                file << suratKeluar[i].nomor_surat << endl;
                file << suratKeluar[i].tujuan_surat << endl;
                file << suratKeluar[i].perihal << endl;
                file << suratKeluar[i].keterangan << endl;
            }
            file.close();
            cout << "Data berhasil disimpan ke dalam file." << endl;
        } else {
            cout << "Gagal menyimpan data." << endl;
        }

    cout << endl;
    cout << "Ulangi (y/t) : ";
    cin >> ulang;
    cin.ignore();

    } while (ulang == "y");
}

void binary_search_keluar(Suratklr suratKeluar[], int jumlahSuratKeluar) {
    string tanggalDicari;
    lihat_surat_keluar(suratKeluar, jumlahSuratKeluar);
    cout << "\nMasukkan tanggal surat keluar yang ingin dicari (format: YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, tanggalDicari);
        
    int left = 0;
    int right = jumlahSuratKeluar - 1;
    bool ditemukan = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (suratKeluar[mid].tanggal_keluar == tanggalDicari) {
            ditemukan = true;
            cout << "\nSurat ditemukan\n" << endl;
            cout << "Tanggal keluar : " << suratKeluar[mid].tanggal_keluar << "\n";
            cout << "Tanggal surat  : " << suratKeluar[mid].tanggal_surat << "\n";
            cout << "Nomor surat    : " << suratKeluar[mid].nomor_surat << "\n";
            cout << "Tujuan surat   : " << suratKeluar[mid].tujuan_surat << "\n";
            cout << "Perihal        : " << suratKeluar[mid].perihal << "\n";
            cout << "Lampiran       : " << suratKeluar[mid].keterangan << "\n";
            break;
        } else if (suratKeluar[mid].tanggal_keluar < tanggalDicari) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!ditemukan) {
        cout << "\nSurat tidak ditemukan.\n";
    }

    cout << endl;
    cout << "Tekan ENTER untuk kembali...";
    cin.ignore();
    getche();
}

int crudmasuk()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "+--------------------------+" << endl;
        cout << "|        Menu Utama        |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "| 1. Tambah Surat Masuk    |" << endl;
        cout << "| 2. Lihat Surat Masuk     |" << endl;
        cout << "| 3. Update Surat Masuk    |" << endl;
        cout << "| 4. Hapus Surat Masuk     |" << endl;
        cout << "| 5. Keluar                |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "\nPilih : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            // insertion_sort_masuk(suratMasuk, jumlahSuratMasuk);
            lihat_surat_masuk(suratMasuk, jumlahSuratMasuk);
            surat_masuk(suratMasuk, jumlahSuratMasuk);
            break;
        case 2:
            // insertion_sort_masuk(suratMasuk, jumlahSuratMasuk);
            lihat_surat_masuk(suratMasuk, jumlahSuratMasuk);
            cout << endl;
            cout << "Tekan ENTER untuk kembali...";
            cin.ignore();
            getche();
            break;
        case 3:
            update_surat_masuk(suratMasuk, jumlahSuratMasuk);
            break;
        case 4:
            delete_surat_masuk(suratMasuk, jumlahSuratMasuk);
            break;
        case 5:
            menu_admin();
            break;
        default:
            cout << "\nPilihan tidak valid.\n" << endl;
            system("pause");
            break;
        }
    } while (pilihan != 5);
}

int crudkeluar()
{
    int pilihan;
    do
    {
        system("cls");
        cout << "+--------------------------+" << endl;
        cout << "|        Menu Utama        |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "| 1. Tambah Surat Keluar   |" << endl;
        cout << "| 2. Lihat Surat Keluar    |" << endl;
        cout << "| 3. Update Surat Keluar   |" << endl;
        cout << "| 4. Hapus Surat Keluar    |" << endl;
        cout << "| 5. Keluar                |" << endl;
        cout << "+--------------------------+" << endl;
        cout << "\nPilih : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            insertion_sort_keluar(suratKeluar, jumlahSuratKeluar);
            lihat_surat_keluar(suratKeluar, jumlahSuratKeluar);
            surat_keluar(suratKeluar, jumlahSuratKeluar);
            break;
        case 2:
            insertion_sort_keluar(suratKeluar, jumlahSuratKeluar);
            lihat_surat_keluar(suratKeluar, jumlahSuratKeluar);
            cout << endl;
            cout << "Tekan ENTER untuk kembali...";
            cin.ignore();
            cin.get();
            break;
        case 3:
            update_surat_keluar(suratKeluar, jumlahSuratKeluar);
            break;
        case 4:
            delete_surat_keluar(suratKeluar, jumlahSuratKeluar);
            break;
        case 5:
            menu_admin();
            break;
        default:
            cout << "\nPilihan tidak valid.\n" << endl;
            system("pause");
            break;
        }
    } while (pilihan != 5);
}

int menu_admin()
{
    int pilihan;
        system("cls");
        // cout << "+-----------------------------+" << endl;
        cout << "========== Menu Admin ==========\n" << endl;
        // cout << "+-----------------------------+" << endl;
        cout << "   1. Pengaturan Surat Masuk   " << endl;
        cout << "   2. Pengaturan Surat Keluar  " << endl;
        cout << "   3. Keluar                   " << endl;
        cout << "\n================================" << endl;
        cout << "\nPilih : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            crudmasuk();
            break;
        case 2:
            crudkeluar();
            break;
        case 3:
            main();
            break;
        default:
            cout << "\nPilihan tidak valid.\n" << endl;
            sleep(1);
            menu_admin(); // rekursif
            break;
        }
}

int menu_user()
{
    int pilihan;

    do
    {
        system("cls");
        cout << "========== Menu User ==========\n" << endl;
        cout << "    1. Lihat Surat Masuk      " << endl;
        cout << "    2. Lihat Surat Keluar     " << endl;
        cout << "    3. Searching Surat Masuk  " << endl;
        cout << "    4. Searcing Surat Keluar  " << endl;
        cout << "    5. Keluar                 " << endl;
        cout << "\n===============================" << endl;
        cout << "\nPilih : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            lihat_surat_masuk(suratMasuk, jumlahSuratMasuk);
            cout << endl;
            cout << "Tekan ENTER untuk kembali...";
            cin.ignore();
            getche();
            break;
        case 2:
            lihat_surat_keluar(suratKeluar, jumlahSuratKeluar);
            cout << endl;
            cout << "Tekan ENTER untuk kembali...";
            cin.ignore();
            getche();            
            break;
        case 3:
            binary_search_masuk(suratMasuk, jumlahSuratMasuk);
            break;
        case 4:
            binary_search_keluar(suratKeluar, jumlahSuratKeluar);
            break;
        case 5:
            main();
            break;
        default:
            cout << "\nPilihan tidak valid.\n" << endl;
            system("pause");
            break;
        }
    } while (pilihan != 5);
}

struct Pengguna {
    string username;
    string password;
};

void registerUser() {
    string username, password;

    cout << "Buat username anda      : ";
    cin.ignore();
    getline(cin, username);
    cout << "Buat password anda (NIM): ";
    fflush(stdin);
    cin >> password;

    if (password.length() != 10) {
        cout << "Harap input NIM dengan benar." << endl;
        return;
    }

    ofstream file("data_pengguna.txt", ios::app); // Membuka file untuk menambahkan data baru di belakang
    if (file.is_open()) {
        file << username << "," << password << endl;
        file.close();
        cout << "\nHello " << username << "! Selamat Anda berhasil Register. Silahkan Login ke akun Anda.\n" << endl;
    } else {
        cout << "Gagal memuat data." << endl;
    }
}

bool loginUser(string& username, string& password) {

    system("cls");
    string line, un, pw;

    string useradmin = "admin";
    string passadmin = "1234";

    cout << "Username       : ";
    cin >> username;
    cout << "Password (NIM) : ";
    cin >> password;

    ifstream file("data_pengguna.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, un, ',');
            getline(ss, pw, ',');
            if (un == username && pw == password) {
                file.close();
                return true;
            } 
        }
        file.close();

    if (useradmin == username && passadmin == password){
        return true;
        }
    }
    return false;
}

int main() {
    int pilihan;
    int loginAttempt = 3;
    string username, password;

    while (loginAttempt > 0) {
        system("cls");
        cout << "===== Pilihan Menu ===== \n" << endl;
        cout << "      1. Register  " << endl;
        cout << "      2. Login     " << endl;
        cout << "      3. Keluar    " << endl;
        cout << "\n========================" << endl;
        cout << endl;
        cout << "Pilih : ";
        cin >> pilihan;

        if (pilihan == 1) {
            system("cls");
            registerUser();
        } else if (pilihan == 2) {
                if (loginUser(username, password)) {
                    if (username == "admin" && password == "1234") {
                        cout << "\nLogin Berhasil! Menuju Menu Admin..." << endl;
                        sleep(1);
                        menu_admin();
                    } else {
                        cout << "\nLogin Berhasil! Menuju Menu User..." << endl;
                        sleep(1);
                        menu_user();
                    }
                    break;
                }
             else {
                loginAttempt--;
                cout << "\nInvalid Login. Anda memiliki " << loginAttempt << " kesempatan tersisa." << endl;
            } 
        } else if (pilihan == 3){
            cout << "\nbye bye ......\n" << endl;
            break;
        } else {
            cout << "\nPilihan tidak valid." << endl;
        }

        cout << "\nENTER untuk lanjut...";
        cin.ignore();
        getche();
    }

    if (loginAttempt == 0) {
        cout << "Anda telah 3x gagal. Harap coba kembali dalam beberapa saat..." << endl;
    }

    return 0;
}