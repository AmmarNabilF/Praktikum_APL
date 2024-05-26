#include <iostream> // Library standar yang digunakan untuk input dan output
#include <iomanip>  // Library standar yang digunakan untuk manipulasi input dan output
#include <conio.h> // Library standar yang digunakan untuk fungsi getch()
#include <sstream> // Library standar yang digunakan untuk manipulasi string
#include <fstream> // Library standar yang digunakan untuk manipulasi file
#include <string> // Library standar yang digunakan untuk manipulasi string
#include <limits> // Library standar yang digunakan untuk manipulasi batas
#include <cctype> // Library standar yang digunakan untuk manipulasi karakter
#include <stdlib.h> // Library standar yang digunakan untuk fungsi system()

using namespace std; // Namespace standar yang digunakan untuk mempersingkat penulisan kode

string user = "petanitimun"; // Deklarasi variabel user dengan tipe data string dan nilai awal kosong
string pass = "kancil"; // Deklarasi variabel pass dengan tipe
string *userPtr = &user; // Deklarasi
string *passPtr = &pass; // Deklarasi

void clears() { // Fungsi clears() yang digunakan untuk membersihkan layar
    system("cls"); // Fungsi system("cls") yang digunakan untuk membersihkan layar
}

struct detail { // Struct detail yang digunakan untuk menyimpan data menu
    int kodeMenu; // Deklarasi variabel kodeMenu dengan tipe data integer
    string nama; // Deklarasi variabel nama dengan tipe data string
    double harga; // Deklarasi variabel harga dengan tipe data double
    int stok; // Deklarasi variabel stok dengan tipe data integer
};

struct data_menu {
    detail data;
};

struct data_pesanan {
    int kode;
    int jumlah;
};

data_menu menu[100];
data_pesanan pesanan[100];
string filemenu = "DATABASE MOMOOMILK.csv";
string fileriwayat = "DATABASE RIWAYAT PESANAN.csv";
int muatData(string filemenu, data_menu menu[]);
int jumlah_menu = muatData(filemenu, menu);
int jumlah_pesanan = 0;

bool login(string *userPtr, string *passPtr, int coba = 0) {
    if (coba == 3) {
        cout << "(!) Anda telah melewati batas percobaan, program berhenti.";
        return false;
    }

    string username, password;
    cout << "[  Login Admin  ]" << endl;
    cout << "Username : ";
    getline(cin, username);
    cout << "Password : ";
    getline(cin, password);

    if (username == *userPtr && password == *passPtr) {
        cout << "\nLogin berhasil!";
        cout << "\nHalo, Admin " << username << "!" << endl;
        cout << "\n";
        cout << "=================================" << endl;
        return true;
    } else {
        int percobaan = 2 - coba;
        cout << "\n(!) Login gagal, Username atau Password yang anda masukkan salah." << endl;
        if (coba != 2) {          
            cout << "(!) Sisa percobaan anda " << percobaan << " kali lagi.\n" << endl;
        }
        return login(userPtr, passPtr, coba + 1);
    }
}

bool ceknama(string nama) { // fungsi ceknama dengan parameter nama
    for (char c : nama) {
        if (!isalpha(c) && isspace(c) == 0) {
            return false;
        }
    }
    return true;
}

int buatKodeunik(data_menu menu[], int jumlah_menu) { // fungsi buatKodeunik dengan parameter menu dan jumlah_menu
    int kode;
    bool kodeUnik;
    do {
        kode = rand() % 99 + 1;
        kodeUnik = true;
        for (int i = 0; i < jumlah_menu; ++i) {
            if (menu[i].data.kodeMenu == kode) {
                kodeUnik = false;
                break;
            }
        }
    } while (!kodeUnik);
    return kode;
}

int muatData(string filemenu, data_menu menu[]) { // fungsi muatData dengan parameter filemenu dan menu
    ifstream file(filemenu);
    if (!file.is_open()) {
        cout << "(!) Gagal membuka file." << endl;
        return 0;
    }

    string line;
    int jumlah_menu = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string kodeStr, nama, hargaStr, stokStr;
        getline(ss, kodeStr, ';');
        getline(ss, nama, ';');
        getline(ss, hargaStr, ';');
        getline(ss, stokStr, ';');

        menu[jumlah_menu].data.kodeMenu = stoi(kodeStr);
        menu[jumlah_menu].data.nama = nama;
        menu[jumlah_menu].data.harga = stod(hargaStr);
        menu[jumlah_menu].data.stok = stoi(stokStr);

        jumlah_menu++;
    }

    file.close();
    return jumlah_menu;
}

bool namaSudahada(data_menu menu[], int jumlah_menu, string nama) { // fungsi namaSudahada dengan parameter menu, jumlah_menu, dan nama
    for (int i = 0; i < jumlah_menu; ++i) {
        if (menu[i].data.nama == nama) {
            return true;
        }
    }
    return false;
}

void quickSort(data_menu menu[], int low, int high, bool ascending = true) {
    int i = low;
    int j = high;
    double pivot = menu[(low + high) / 2].data.harga;

    while (i <= j) {
        if (ascending) {
            while (menu[i].data.harga < pivot) {
                i++;
            }
            while (menu[j].data.harga > pivot) {
                j--;
            }
        } else {
            while (menu[i].data.harga > pivot) {
                i++;
            }
            while (menu[j].data.harga < pivot) {
                j--;
            }
        }

        if (i <= j) {
            swap(menu[i], menu[j]);
            i++;
            j--;
        }
    }

    if (low < j) {
        quickSort(menu, low, j, ascending);
    }
    if (i < high) {
        quickSort(menu, i, high, ascending);
    }
}

void sequentialSearch(data_menu menu[], int jumlah_menu) {
    cout << "Pencarian berdasarkan nama!" << endl;
    cout << "Nama menu yang dicari: ";
    string cari;
    getline(cin, cari);
    if (cari.empty()) {
        cout << "(!) Nama tidak boleh kosong" << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < jumlah_menu; i++) {
        if (menu[i].data.nama == cari) {
            found = true;
            cout << "Data menu ditemukan!" << endl;
            cout << "Kode : " << menu[i].data.kodeMenu << endl;
            cout << "Nama : " << menu[i].data.nama << endl;
            cout << "Harga: Rp. " << menu[i].data.harga << endl;
            cout << "Stok: " << menu[i].data.stok << endl;
            break;
        }
    }

    if (!found) {
        cout << "(!) Data menu dengan nama \"" << cari << "\" tidak ditemukan" << endl;
    }
}

void tambahMenu(string filemenu, data_menu menu[], int &jumlah_menu) {
    if (jumlah_menu >= 100) {
        cout << "Jumlah data mencapai batas maksimal (100)." << endl;
        return;
    }
    
    string nama;
    double harga;
    int stok;

    cout << "Tambah Data Menu\n";
    cout << "Nama: ";
    getline(cin, nama);
    while (nama.empty() || !ceknama(nama) || namaSudahada(menu, jumlah_menu, nama)) {
        if (nama.empty()) {
            cout << "(!) Nama tidak boleh kosong" << endl;
        } else if (namaSudahada(menu, jumlah_menu, nama)) {
            cout << "(!) Nama sudah ada" << endl;
        } else {
            cout << "(!) Nama tidak valid" << endl;
        }
        cout << "Nama: ";
        getline(cin, nama);
    }
    menu[jumlah_menu].data.nama = nama;
    
    cout << "Harga : Rp.  ";
    while (!(cin >> harga) || harga < 1 || harga == isalnum(harga)){
        cout << "(!) Harga tidak valid!" << endl;
        cout << "Harga : Rp.  ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //dengan menggunakan numeric_limits<streamsize>::max() kita bisa mengabaikan input yang tidak valid
    }
    menu[jumlah_menu].data.harga = harga;

    cout << "Stok: ";
    while (!(cin >> stok) || stok < 1 || stok == isalnum(stok)){
        cout << "(!) Stok tidak valid!" << endl;
        cout << "Stok: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //dengan menggunakan numeric_limits<streamsize>::max() kita bisa mengabaikan input yang tidak valid
    }
    menu[jumlah_menu].data.stok = stok;

    menu[jumlah_menu].data.kodeMenu = buatKodeunik(menu, jumlah_menu);

    ofstream file(filemenu, ios::app);
    if (!file.is_open()) {
        cout << "(!) Gagal membuka file." << endl;
        return;
    }
    file << menu[jumlah_menu].data.kodeMenu << ";"
         << menu[jumlah_menu].data.nama << ";"
         << menu[jumlah_menu].data.harga << ";"
         << menu[jumlah_menu].data.stok << "\n";
    file.close();

    cout << "Data dengan kode '" << menu[jumlah_menu].data.kodeMenu << "' berhasil ditambahkan!" << endl;
    jumlah_menu++;
}

void tampilkan() {
    if (jumlah_menu == 0) {
        cout << "Data kosong." << endl;
        return;
    } 
    else {
    cout << "Daftar Menu\n";
    cout << "=======================================================\n";
    cout << "| " << setw(4) << left << "Kode" << " | " << setw(20) << "Nama" << " | " << setw(14) << "Harga" << " | " << setw(4) << "Stok" << " |\n";
    cout << "=======================================================\n";

    for (int i = 0; i < jumlah_menu; i++) {
        int kode = menu[i].data.kodeMenu;
        string nama = menu[i].data.nama;
        double harga = menu[i].data.harga;
        int stok = menu[i].data.stok;
    cout << "| " << setw(4) << kode << " | " << setw(20) << nama << " | Rp. " << setw(10) << harga << " | " << setw(4) << stok << " |\n";
    }
    cout << "=======================================================\n";
    }
}

void tampilkanMenu() {
    while (true) {
        clears();
        tampilkan();
        cout << "\n[1] Sorting\n";
        cout << "[2] Searching\n";
        cout << "[0] Kembali\n";
        cout << "Pilih : ";
        string pilih;
        cin >> pilih;
        cin.clear();
        cin.ignore();

        if (pilih == "1") {
            while (true) {
                clears();
                cout << "Sorting berdasarkan harga!\n";
                cout << "[1] Termurah\n";
                cout << "[2] Termahal\n";
                cout << "[0] Kembali\n";
                cout << "Pilih : ";
                string sort;
                cin >> sort;
                cin.ignore();
                if (sort == "1") {
                    quickSort(menu, 0, jumlah_menu - 1, true);
                    cout << "Menu berhasil diurutkan dari yang termurah." << endl;
                } else if (sort == "2") {
                    quickSort(menu, 0, jumlah_menu - 1, false);
                    cout << "Menu berhasil diurutkan dari yang termahal." << endl;
                } else if (sort == "0") {
                    break;
                } else {
                    cout << "Pilihan tidak valid." << endl;
                    getch();
                }
            }
        }
        else if (pilih == "2") {
                clears();
                sequentialSearch(menu, jumlah_menu);
                cout << "Tekan [Enter] untuk kembali...";
                cin.ignore();
        }
        else if (pilih == "0") {
                clears();
                return;
        }
        else {
                cout << "Pilihan tidak valid. Coba lagi." << endl;
                getch();
        }
    }
}

void ubahMenu(string filemenu, data_menu menu[], int jumlah_menu) {
    if (jumlah_menu == 0) {
        cout << "Data kosong." << endl;
        return;
    }
    tampilkan();
    int kode;
    cout << "Masukkan kode menu yang akan diubah: ";
    cin >> kode;
    int code = kode;

    bool found = false;
    for (int i = 0; i < jumlah_menu; ++i) {
        if (menu[i].data.kodeMenu == kode) {
            found = true;

            string nama;
            double harga;
            int stok;

            cout << "Nama baru: ";
            cin.ignore();
            getline(cin, nama);
            while (nama.empty() || !ceknama(nama)) {
                cout << "(!) Nama tidak valid, nama tidak boleh kosong" << endl;
                cout << "Nama baru: ";
                getline(cin, nama);
            }
            menu[i].data.nama = nama;

            cout << "Harga baru : Rp. ";
            while (!(cin >> harga) || harga < 1 || harga == isalnum(harga)) {
                cout << "(!) Harga tidak valid!" << endl;
                cout << "Harga baru : Rp. ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //dengan menggunakan numeric_limits<streamsize>::max() kita bisa mengabaikan input yang tidak valid
            }
            menu[i].data.harga = harga;

            cout << "Stok baru: ";
            while (!(cin >> stok) || stok < 1 || stok == isalnum(stok)) {
                cout << "(!) Stok tidak valid!" << endl;
                cout << "Stok baru: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //dengan menggunakan numeric_limits<streamsize>::max() kita bisa mengabaikan input yang tidak valid
            }
            menu[i].data.stok = stok;
            continue;
        }
    }

    if (found) {
        ofstream file(filemenu);
        if (!file.is_open()) {
            cout << "(!) Gagal membuka file." << endl;
            return;
        }

        for (int i = 0; i < jumlah_menu; ++i) {
            file << menu[i].data.kodeMenu << ";"
                 << menu[i].data.nama << ";"
                 << menu[i].data.harga << ";"
                 << menu[i].data.stok << "\n";
        }

        file.close();
        cout << "Data dengan kode '" << code << "' berhasil ditambahkan!" << endl;
    } else {
        cout << "(!) Kode menu tidak ditemukan." << endl;
    }
}

void hapusMenu(data_menu menu[], int &jumlah_menu) { // fungsi hapusMenu dengan parameter menu dan jumlah_menu
    if (jumlah_menu == 0) {
        cout << "Data kosong." << endl;
        return;
    }
    tampilkan();
    int kode;
    cout << "Masukkan kode menu yang akan dihapus: ";
    cin >> kode;

    bool found = false;
    for (int i = 0; i < jumlah_menu; ++i) {
        if (menu[i].data.kodeMenu == kode) {
            found = true;
            for (int j = i; j < jumlah_menu - 1; ++j) {
                menu[j] = menu[j + 1];
            }
            jumlah_menu--;
        }
    }

    if (found) {
        ofstream file(filemenu);
        if (!file.is_open()) {
            cout << "(!) Gagal membuka file." << endl;
            return;
        }

        for (int i = 0; i < jumlah_menu; ++i) {
            file << menu[i].data.kodeMenu << ";"
                 << menu[i].data.nama << ";"
                 << menu[i].data.harga << ";"
                 << menu[i].data.stok << "\n";
        }

        file.close();
        cout << "Data dengan kode '" << kode << "' berhasil dihapus!" << endl;
    } else {
        cout << "(!) Kode menu tidak ditemukan." << endl;
    }

}

bool riwayatPesanan() {
    ifstream file(fileriwayat);
    if (!file.is_open()) {
        cout << "(!) Gagal membuka file." << endl;
        return false;
    }
    file.ignore(3);
    string line;
    cout << "Riwayat Pesanan\n";
    cout << "==========================================================================\n";
    cout << "| " << setw(4) << left << "No" << " | " << setw(20) << "Nama" << " | " << setw(14) << "Harga" << " | " << setw(4) << "Jumlah" << " | " << setw(14) << "Total Harga" << " |\n";
    cout << "==========================================================================\n";
    int nomor = 1;
    while (getline(file, line)) {
        stringstream ss(line);
        string nomorStr, nama, jumlahStr, hargaStr, totalHargaStr;
        getline(ss, nomorStr, ';');
        getline(ss, nama, ';');
        getline(ss, jumlahStr, ';');
        getline(ss, hargaStr, ';');
        getline(ss, totalHargaStr, '\n');

        cout << "| " << setw(4) << nomorStr << " | " << setw(20) << nama << " | Rp. " << setw(10) << hargaStr << " | " << setw(4) << jumlahStr << "   | Rp. " << setw(10) << totalHargaStr << " |\n";
        nomor++;
    }
    cout << "==========================================================================\n";
    file.close();
    return true;

}

void tambahPesanan(data_pesanan pesanan[], int &jumlah_pesanan) {
    int kode;
    cout << "Masukkan kode menu: ";
    cin >> kode;
    bool found = false;
    for (int i = 0; i < jumlah_menu; ++i) {
        while (cin.fail() || kode < 1 || kode == isalnum(kode)) {
            cin.clear(); // Membersihkan kesalahan pada input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang tidak valid
            cout << "(!) Input tidak valid." << endl;
            cout << "Masukkan kode menu: ";
            cin >> kode;
        }
        if (menu[i].data.kodeMenu == kode) {
            found = true;
            int jumlah;
            cout << "Jumlah: ";
            cin >> jumlah;
            while (cin.fail() || jumlah < 1 || jumlah == isalnum(jumlah)) {
                cin.clear(); // Membersihkan kesalahan pada input stream
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang tidak valid
                cout << "(!) Input tidak valid." << endl;
                cout << "Jumlah: ";
                cin >> jumlah;
            }
            if (jumlah > menu[i].data.stok) {
                cout << "(!) Stok tidak mencukupi." << endl;
                return;
            }

            menu[i].data.stok -= jumlah;
            pesanan[jumlah_pesanan].kode = kode;
            pesanan[jumlah_pesanan].jumlah = jumlah;
            jumlah_pesanan++;

            ofstream file(filemenu);
            if (!file.is_open()) {
                cout << "(!) Gagal membuka file." << endl;
                return;
            }
            for (int i = 0; i < jumlah_menu; ++i) {
                file << menu[i].data.kodeMenu << ";"
                        << menu[i].data.nama << ";"
                        << menu[i].data.harga << ";"
                        << menu[i].data.stok << "\n";
            }
            file.close();
            
            cout << "Pesanan berhasil ditambahkan!" << endl;
        }
    }

    if (!found) {
       cout << "(!) Kode tidak ditemukan." << endl;
    }    
}

void hapusPesanan(data_pesanan pesanan[], int &jumlah_pesanan) {
    int kode;
    cout << "Masukkan kode menu: ";
    cin >> kode;

    bool found = false;
    for (int i = 0; i < jumlah_pesanan; ++i) {
        while (cin.fail() || kode < 1 || kode == isalnum(kode)) {
            cin.clear(); // Membersihkan kesalahan pada input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang tidak valid
            cout << "(!) Input tidak valid." << endl;
            cout << "Masukkan kode menu: ";
            cin >> kode;
        }
        if (pesanan[i].kode == kode) {
            found = true;
            for (int j = 0; j < jumlah_menu; ++j) {
                if (menu[j].data.kodeMenu == kode) {
                    menu[j].data.stok += pesanan[i].jumlah;
                    break;
                }
            }
            for (int j = i; j < jumlah_pesanan - 1; ++j) {
                pesanan[j] = pesanan[j + 1];
            }
            jumlah_pesanan--;

            ofstream file(filemenu);
            if (!file.is_open()) {
                cout << "(!) Gagal membuka file." << endl;
                return;
            }
            for (int i = 0; i < jumlah_menu; ++i) {
                file << menu[i].data.kodeMenu << ";"
                     << menu[i].data.nama << ";"
                     << menu[i].data.harga << ";"
                     << menu[i].data.stok << "\n";
            }
            file.close();

            cout << "Pesanan berhasil dihapus!" << endl;
        }
    }

    if (!found) {
        cout << "(!) Kode menu tidak ditemukan." << endl;
    }
}

void tampilkanPesanan(data_pesanan pesanan[], int jumlah_pesanan, double totalHarga = 0) { // fungsi tampilkanPesanan dengan parameter pesanan, jumlah_pesanan, dan totalHarga
    cout << "Pesanan Anda\n";
    cout << "=========================================================\n";
    cout << "| " << setw(4) << left << "Kode" << " | " << setw(20) << "Nama" << " | " << setw(14) << "Harga" << " | " << setw(4) << "Jumlah" << " |\n";
    cout << "=========================================================\n";
    for (int i = 0; i < jumlah_pesanan; i++) {
        int kode = pesanan[i].kode;
        int jumlah = pesanan[i].jumlah;
        for (int j = 0; j < jumlah_menu; j++) {
            if (menu[j].data.kodeMenu == kode) {
                cout << "| " << setw(4) << kode << " | " << setw(20) << menu[j].data.nama << " | Rp. " << setw(10) << menu[j].data.harga << " | " << setw(4) << jumlah << "   |\n";
                totalHarga += menu[j].data.harga * jumlah;
                break;
            }
        }
    }
    cout << "=========================================================\n";
    cout << "Total harga : Rp. " << totalHarga << endl;
}

void pesanMenu(data_pesanan pesanan[], int &jumlah_pesanan) {
    string pilih;
    cout << "\n[1] Tambah pesanan\n";
    cout << "[2] Hapus pesanan\n";
    cout << "[3] Konfirmasi pesanan\n";
    cout << "[0] Kembali\n";
    cout << "Pilih : ";
    cin >> pilih;
    cin.ignore();

    if (pilih == "1") {
        while (true) {
            clears();
            tampilkan();
            tambahPesanan(pesanan, jumlah_pesanan);
            string lanjut;
            cout << "Tekan [Enter] untuk kembali... (Atau key apa saja untuk menambah lagi)";
            cin.clear();
            cin.ignore();
            getline(cin, lanjut);
            if (!lanjut.empty()) {
                clears();
            } else {
                clears();
                break;
            }
        }
        pesanMenu(pesanan, jumlah_pesanan);
    } 
    else if (pilih == "2") {
        clears();
        if (jumlah_pesanan == 0) {
            cout << "Pesanan kosong." << endl;
            cout << "Tekan [Enter] untuk kembali...";
            cin.ignore();
            return;
        }
        while (true) {
            clears();
            tampilkanPesanan(pesanan, jumlah_pesanan);
            hapusPesanan(pesanan, jumlah_pesanan);
            string lanjut;
            cout << "Tekan [Enter] untuk kembali... (Atau key apa saja untuk menghapus lagi)";
            cin.clear();
            cin.ignore();
            getline(cin, lanjut);
            if (!lanjut.empty()) {
                clears();
            } else {
                clears();
                break;
            }
        }
        pesanMenu(pesanan, jumlah_pesanan);
    } 
    else if (pilih == "3") {
        clears();
        if (jumlah_pesanan == 0) {
            cout << "Pesanan kosong." << endl;
            cout << "Tekan [Enter] untuk kembali...";
            cin.ignore();
            return;
        }
        tampilkanPesanan(pesanan, jumlah_pesanan);
        cout << "\nApakah Anda ingin menyimpan pesanan?\n";
        cout << "[1] Simpan pesanan\n";
        cout << "[selain 1] Batal simpan pesanan\n";
        cout << "Pilihan : ";
        string pilihan;
        cin >> pilihan;
        if (pilihan == "1") {
            cout << "Pesanan disimpan.\n";
            cout << "Tekan [Enter] untuk melanjutkan...";
            cin.ignore();
        } else {
            for (int i = 0; i < jumlah_pesanan; i++) {
                int kode = pesanan[i].kode;
                int jumlah = pesanan[i].jumlah;
                for (int j = 0; j < jumlah_menu; j++) {
                    if (menu[j].data.kodeMenu == kode) {
                        menu[j].data.stok += jumlah;
                        break;
                    }
                }
            }
            jumlah_pesanan = 0;
            cout << "Pesanan dibatalkan.\n";
            cout << "Tekan [Enter] untuk kembali...";
            cin.ignore();
            getch();
        }
    } 
    else if (pilih == "0") {
        clears();
        return;
    } 
    else {
        cout << "Pilihan tidak valid. Coba lagi." << endl;
        pesanMenu(pesanan, jumlah_pesanan);
    }
}

void tulis_riwayatPesanan( int nomor, string nama, int jumlah, double harga, double totalHarga) {
    ofstream file(fileriwayat, ios::app);
    if (file.is_open()) {
        file << nomor << ";"
             << nama << ";"
             << jumlah << ";"
             << harga << ";"
             << totalHarga << "\n";
        file.close();
    } 
}

void bayar(data_pesanan pesanan[], double totalHarga = 0) {
    if (jumlah_pesanan == 0) {
        cout << "(!) Pesanan kosong." << endl;
        cout << "Tekan [Enter] untuk kembali...";
        cin.ignore();
        clears();
        return;
    }

    tampilkanPesanan(pesanan, jumlah_pesanan, totalHarga); // Memanggil fungsi tampilkanPesanan dengan parameter pesanan, jumlah_pesanan, dan totalHarga
    cout << "\n";
    cout << "Pilih Pembayaran :" << endl;
    cout << "[1] Tunai" << endl;
    cout << "[2] QRIS " << endl;
    cout << "Pilih metode pembayaran : ";
    string pilihan;
    cin >> pilihan;

    if (pilihan == "1") {
        cout << "\nTerima kasih telah berbelanja di MOMOO MILK\n";
        for (int i = 0; i < jumlah_pesanan; i++) {
                pesanan[i].kode = 0;
                pesanan[i].jumlah = 0;
        }
        jumlah_pesanan = 0;
    } 
    else if (pilihan == "2") {
        cout << "Silahkan scan QRIS untuk melakukan pembayaran\n";
        cout << "Tekan [Enter] untuk melanjutkan pembayaran...";
        cin.ignore();
        cin.get(); 
        cout << "\nTerima kasih telah berbelanja di MOMOO MILK\n";
        int nomor = 0;
        nomor += 1;
        for (int i = 0; i < jumlah_pesanan; i++) {
        int kode = pesanan[i].kode;
        int jumlah = pesanan[i].jumlah;
            for (int j = 0; j < jumlah_menu; j++) {
                if (menu[j].data.kodeMenu == kode) {
                    string nama = menu[j].data.nama;
                    double harga = menu[j].data.harga;
                    double totalHarga = harga * jumlah;
                    tulis_riwayatPesanan(nomor, nama, jumlah, harga, totalHarga);
                    break;
                }
            }
        } 
        for (int i = 0; i < jumlah_pesanan; i++) {
                pesanan[i].kode = 0;
                pesanan[i].jumlah = 0;
        }
        jumlah_pesanan = 0;
    } 
    else {
        cout << "(!) Pilihan tidak valid!" << endl;
        cout << "Pembayaran gagal." << endl;
        cout << "\nTekan [Enter] untuk kembali...";
        getch();
        return;
    }
    cout << "Pembayaran berhasil." << endl;
}


void menuUser() {
    clears();
    jumlah_menu = muatData(filemenu, menu);
    string pilihan;
    cout << "\033[1;36m" 
         << "=====================================\n"
         << "|      Menu Guest - MOMOO MILK      |\n"
         << "=====================================\n"
         << "| 1. Pesan                          |\n"
         << "| 2. Cari Menu                      |\n"
         << "| 3. Bayar                          |\n"
         << "| 0. Keluar                         |\n"
         << "=====================================\033[0m\n"
         << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == "1") {
        clears();
        pesanMenu(pesanan, jumlah_pesanan);
        menuUser();
    }
    else if (pilihan == "2") {
        clears();
        tampilkanMenu();
        menuUser();
    }
    else if (pilihan == "3") {
        clears();
        bayar(pesanan);
        menuUser();
    }
    else if (pilihan == "0") {
        cout << "Terima Kasih & Sampai Jumpa!" << endl;
    }
    else {
        cout << "(!) Pilihan tidak valid!" << endl;
        getch();
        menuUser();
    }
}


void menuAdmin() {
    jumlah_menu = muatData(filemenu, menu);
    string pilihan;
    cout << "\n";
    cout << "   Menu Admin - MOMOO MILK\n"
            << "[1] Tambah data menu\n"
            << "[2] Tampilkan data menu\n"
            << "[3] Perbarui data menu\n"
            << "[4] Hapus data menu\n"
            << "[5] Riwayat pesanan\n"
            << "[0] Keluar\n"
            << "Pilih menu : ";
    cin >> pilihan;
    cin.ignore();

    if (pilihan == "1") {
        while (true) {
            clears();
            tambahMenu(filemenu, menu, jumlah_menu);
            string lanjut;
            cout << "Tekan [Enter] untuk kembali... (Atau key apa saja untuk menambah lagi)";
            cin.clear();
            cin.ignore();
            getline(cin, lanjut);
            if (!lanjut.empty()) {
                clears();
            } else {
                clears();
                break;
            }
        }
        menuAdmin();
    }
    else if (pilihan == "2") {
        clears();
        tampilkanMenu();
        menuAdmin();
    }
    else if (pilihan == "3") {
        while (true) {
            clears();
            ubahMenu(filemenu, menu, jumlah_menu);
            string lanjut;
            cout << "Tekan [Enter] untuk kembali... (Atau key apa saja untuk mengubah lagi)";
            cin.clear();
            cin.ignore();
            getline(cin, lanjut);
            if (!lanjut.empty()) {
                clears();
            } else {
                clears();
                break;
            }
        }
        menuAdmin();
    }
    else if (pilihan == "4") {
        while (true) {
            clears();
            hapusMenu(menu, jumlah_menu);
            string lanjut;
            cout << "Tekan [Enter] untuk kembali... (Atau key apa saja untuk menghapus lagi)";
            cin.clear();
            cin.ignore();
            getline(cin, lanjut);
            if (!lanjut.empty()) {
                clears();
            } else {
                clears();
                break;
            }
        }
        menuAdmin();
    }
    else if (pilihan == "5") {
        clears();
        riwayatPesanan();
        cout << "Tekan [Enter] untuk kembali...";
        cin.ignore();
        clears();
        menuAdmin();
    }
    else if (pilihan == "0") {
        cout << "Terima Kasih & Sampai Jumpa!" << endl;
    }
    else {
        cout << "(!) Pilihan tidak valid!" << endl;
        menuAdmin(); 
    }
}

int main() {
    srand(time(0));
    while (true) {
        clears();
        string pilihan;
        cout << "===================" << endl;
        cout << "|    MOMOO MILK   |" << endl;
        cout << "===================" << endl;
        cout << "\n";
        cout << "Silakan masuk sebagai:" << endl;
        cout << "[1] Admin" << endl;
        cout << "[2] Guest" << endl;
        cout << "[0] Keluar" << endl;
        cout << "Pilihan Anda : ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == "1") {
            clears();
            if (login(userPtr, passPtr)) {
                menuAdmin();
            }
        }
        else if (pilihan == "2") {
            clears();
            menuUser();
        
        }
        else if (pilihan == "0") {
            cout << "\nTerima Kasih & Sampai Jumpa!" << endl;
            break;
        }
        else {
            cout << "(!) Pilihan tidak valid!" << endl;
        }
    }
}