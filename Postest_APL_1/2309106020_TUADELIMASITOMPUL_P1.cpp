#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void konversiRupiah();
void konversiDollar();
void konversiYen();
void konversiEuro();

int main (){
    string username ="Delima";
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
            break;
        }
        else {
            cout << "Login gagal. Silahkan coba lagi.\n";
            percobaan++;
        }
    }
    while (percobaan <3);

    if (percobaan == 3) {
        cout << "Anda telah mencoba lagin sebanyak 3 kali. Akses ditolak.\n";
        return 1;

    }

    int pilih; 
    cout << "========================\n"
            " MENU KONVERSI MATA UANG \n"
            "========================\n"
            " 1. Rupiah\n"
            " 2. Dollar\n"
            " 3. Yen\n"
            " 4. Euro\n"
            "======================\n";
    cout << " Pilih mata Uang : ";
    cin >> pilih;

    system("cls");
    if (pilih == 1){
        konversiRupiah(); 
    }
    else if (pilih == 2){
        konversiDollar();
    }
    else if(pilih == 3){
        konversiYen();
    }
    else if(pilih == 4){
        konversiEuro();
    }


    return 0;
 }

void konversiRupiah() {
    char ulangi;
    do {
        int pilih;
        float rupiah;
        const float dollarRate = 0.000064;
        const float yenRate = 0.0096;
        const float euroRate = 0.000059;

        cout << "======================\n"
                " KONVERSI RUPIAH KE \n"
                "======================\n"
                " 1. Dollar\n"
                " 2. Yen\n"
                " 3. Euro\n"
                " 4. Kembali\n"
                " Pilih mata Uang : ";
        cin >> pilih;

        cout << " Masukkan Uang dalam Rupiah : Rp. ";
        cin >> rupiah;
        
        switch (pilih) {
            case 1:
                cout << "======================\n"
                        " RUPIAH KE DOLLAR \n"
                        "======================\n";
                cout << fixed << setprecision(2) << " Hasil konversi : $" << rupiah * dollarRate;
                break;
            case 2:
                cout << "======================\n"
                        " RUPIAH KE YEN \n"
                        "======================\n";
                cout << fixed << setprecision(2) << " Hasil konversi : ¥" << rupiah * yenRate;
                break;
            case 3:
                cout << "======================\n"
                        " RUPIAH KE EURO \n"
                        "======================\n";
                cout << fixed << setprecision(2) << " Hasil konversi : €" << rupiah * euroRate;
                break;
            case 4:
                
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }

        cout << "\nApakah kamu mau mengulang?\n";
        cout << "Jawab y/t: ";
        cin >> ulangi;
    } while (ulangi == 'y');
}

void konversiDollar() {
    char ulangi;
    do {
        int pilih;
        float dollar;
        const float rupiahRate = 15.700;
        const float yenRate = 150.10;
        const float euroRate = 0.92;

        cout << "======================\n"
                " KONVERSI DOLLAR KE \n"
                "======================\n"
                " 1. Rupiah\n"
                " 2. Yen\n"
                " 3. Euro\n"
                " Pilih mata Uang : ";
        cin >> pilih;

        cout << " Masukkan Uang dalam Dollar : $"; 
        cin >> dollar;

        switch (pilih) {
            case 1:
                cout << "======================\n"
                        " DOLLAR KE RUPIAH \n"
                        "======================\n";
                cout << fixed << setprecision(2) << " Hasil konversi : IDR" << dollar * rupiahRate;
                break;
            case 2:
                cout << "======================\n"
                        " DOLLAR KE YEN \n"
                        "======================\n";
                cout << fixed << setprecision(2) << " Hasil konversi : ¥" << dollar * yenRate;
                break;
            case 3:
                cout << "======================\n"
                        " DOLLAR KE EURO \n"
                        "======================\n";
                cout << fixed << setprecision(2) << " Hasil konversi : €" << dollar * euroRate;
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }

        cout << "\nApakah kamu mau mengulang?\n";
        cout << "Jawab y/t: ";
        cin >> ulangi;
    } while (ulangi == 'y');
}


void konversiYen() {
    char ulangi = 'y';
    do {
        int pilih;
        float yen;
        const float rupiah_rate = 104.66, dollar_rate = 0.0067, euro_rate = 0.0061;

        cout << "======================\n"
                " KONVERSI YEN KE \n"
                "======================\n"
                " 1. Rupiah\n"
                " 2. Dollar\n"
                " 3. Euro\n";
        cout << " Pilih mata uang: ";
        cin >> pilih;

        cout << "======================\n"
                " Masukkan uang dalam Yen : ¥ ";
        cin >> yen;

        cout << "\n\n======================\n";

        switch(pilih) {
            case 1:
                cout << fixed << setprecision(2) << " Hasil konversi : IDR" << yen * rupiah_rate;
                break;
            case 2:
                cout << fixed << setprecision(2) << " Hasil konversi : $" << yen * dollar_rate;
                break;
            case 3:
                cout << fixed << setprecision(2) << " Hasil konversi : €" << yen * euro_rate;
                break;
            default:
                cout << "Pilihan tidak valid.";
        }

        cout << "\n\n======================\n";
        cout << "Apakah Anda ingin mengulang?\n";
        cout << "Jawab y/t: ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');
}

void konversiEuro() {
    char ulangi = 'y';
    do {
        int pilih;
        float euro;
        const float rupiah_rate = 17.022, yen_rate = 162.67, dollar_rate = 1.08;

        cout << "======================\n"
                " KONVERSI EURO KE \n"
                "======================\n"
                " 1. Rupiah\n"
                " 2. Yen\n"
                " 3. Dollar\n";
        cout << " Pilih mata uang : ";
        cin >> pilih;

        cout << "======================\n"
                " Masukkan uang dalam Euro : € ";
        cin >> euro;

        cout << "\n\n======================\n";

        switch(pilih) {
            case 1:
                cout << fixed << setprecision(2) << " Hasil konversi : Rp. " << euro * rupiah_rate;
                break;
            case 2:
                cout << fixed << setprecision(2) << " Hasil konversi : ¥" << euro * yen_rate;
                break;
            case 3:
                cout << fixed << setprecision(2) << " Hasil konversi : $" << euro * dollar_rate;
                break;
            default:
                cout << "Pilihan tidak valid.";
        }

        cout << "\n\n======================\n";
        cout << "Apakah Anda ingin mengulang?\n";
        cout << "Jawab y/t: ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');
}
