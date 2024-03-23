#include <iostream>
#include <cstdlib>
using namespace std;

struct buku{
    string judul;
    string penulis;
    int tahun_terbit;
};

struct maks_data{
	struct buku data_buku[10];
};
maks_data data;
int jumlah_buku = 0;

int percobaan_login(int salah){
    string nama = "ammar nabil fauzan";
    string nim = "2309106006";
    
    string username;
    cout << "Masukkan username anda: ";
    getline(cin, username); 
    string password;
    cout << "Masukkan password anda: ";
    getline(cin, password);

    if (username == nama && password == nim){
        cout << "Login berhasil" << endl;
        cout << " " << endl;
        return 1;        
        
    }else if (username == nama){
        cout << "password salah"<< endl;
    }
	else if (password == nim){
        cout << "username salah" << endl;   
    }
	else{
        cout << "Username maupun Password tidak ada yang benar\n" << endl;
    }
    
    salah--;
    
    if (salah > 0){
    cout << "Anda memiliki " << salah << " kesempatan lagi" << endl;
    cout << " " << endl;
    percobaan_login(salah);
	}
    else{
        cout << "Anda gagal login. Saatnya saya mengusir anda dari program ini";
        exit(EXIT_FAILURE);
    }

return 0;
 }
 

void tambah_buku(){
	cout << "\nMasukkan jumlah buku yang ingin ditambah [Max buku = 10]: ";
    cin >> jumlah_buku;
    
    if (jumlah_buku > 10){
    	cout << "\nMaaf. Anda telah melebihi batas maksimal dari jumlah buku yang ingin ditambah\n" << endl;
    	return;
	}
	else{
    for (int i = 0; i < jumlah_buku; ++i){
        cout << "Buku ke-" << i + 1 << endl;
        cin.ignore();
        cout << "Judul: ";
        getline(cin, data.data_buku[i].judul);
        cout << "Penulis: ";
        getline(cin, data.data_buku[i].penulis);
        cout << "Tahun terbit: ";
        cin >> data.data_buku[i].tahun_terbit;
        cout << " " << endl;
    	}
	}
}

void tampilkan_data_buku(){
	if (jumlah_buku == 0) {
		cout << "Belum ada data untuk ditampilkan" << endl;
		cout << " " << endl;
		return;
	}
	for (int i = 0; i < jumlah_buku; ++i){
        cout << "Judul: " << data.data_buku[i].judul << endl;
        cout << "Penulis: " << data.data_buku[i].penulis << endl;
        cout << "Tahun terbit: " << data.data_buku[i].tahun_terbit << endl;
        cout << " " << endl;
    }
}

void memperbarui_data_buku(){
	if (jumlah_buku == 0) {
		cout << "Belum ada data untuk diperbarui" << endl;
		cout << " " << endl;
		return;
	}    
    cout << "Perbarui Data";
    cout << " " << endl;
    int pilih;
    cout << "Silahkan pilih sesuai nomor urut: ";
    cin >> pilih;
    
    if (pilih >= 0 && pilih < jumlah_buku){
    	cout << "\nBerikut data buku yang anda pilih\n: " << endl;
    	cout << "Judul: " << data.data_buku[pilih].judul << endl;
    	cout << "Penulis: " << data.data_buku[pilih].penulis << endl;
    	cout << "Tahun terbit: " << data.data_buku[pilih].tahun_terbit << endl;
    	
    	cout << "\nMasukkan data baru untuk buku ke-" << pilih + 1 << endl;
    	cin.ignore();
    	cout << "Perbaikan judul: ";
    	getline(cin, data.data_buku[pilih].judul);
    	cout << "Perbaikan penulis: ";
    	getline(cin, data.data_buku[pilih].penulis);
    	cout << "Perbaikan tahun terbit: ";
    	cin >> data.data_buku[pilih].tahun_terbit;
    	cout << "Data buku berhasil diperbarui ! ! !" << endl;
    	cout << " " << endl;
	}
	else {
		cout << "Angka yang dimasukkan tidak benar (X)\n" << endl;
		cout << " " << endl;
	}
    
}
void hapus_data_buku(){
	if (jumlah_buku == 0) {
		cout << "Belum ada data untuk dihapus" << endl;
		cout << " " << endl;
		return;
	}
	
	tampilkan_data_buku();
    
	cout << "Hapus Data";
    cout << " " << endl;
    int pilih;
    cout << "\nSilahkan pilih sesuai nomor urut: ";
    cin >> pilih;
    
    if (pilih >= 0 && pilih < jumlah_buku){
    	for (int i = pilih; i < jumlah_buku - 1; ++i){
    		data.data_buku[i] = data.data_buku[i + 1];
		}
		jumlah_buku--;
		
		cout << "Data buku ke-" << pilih+1 << " " << "Telah dihapus" << endl;
		cout << " " << endl;
		
	}
	else {
		cout << "Angka yang anda masukkan tidak valid (X)" << endl;
		cout << " " << endl;
	}
}
void menu_buku_bacaan(){
    
	while (true){
		cout << "\nMAIN MENU\n"
	    "0) Keluar program\n"
	    "1) Tambah buku\n"
	    "2) Menampilkan list buku\n"
	    "3) Mengupdate data buku\n"
	    "4) Menghapus data buku\n";
	    
	    int pilih;
	    cout << "Silahkan pilih opsi diatas: ";
	    cin >> pilih;
	    cout << " " << endl;
	    if (cin.fail()) {
	    	cout << "Tolong masukkan inputan sesuai angka yang ditampilkan " << endl;
	    	cin.clear();
	    	cin.ignore();
		}
		else{
		    if (pilih == 0){
		        exit(0);
		    }
		    else if (pilih == 1){
		        tambah_buku();
		    }
		    else if (pilih == 2){
		        tampilkan_data_buku();
		    }
		    else if (pilih == 3){
		        memperbarui_data_buku();
		    }
		    else if (pilih == 4){
		        hapus_data_buku();
		    }
		    else{
		        cout << "\nTidak ada opsi pilihan tersebut " << endl;
		        
		    }
		}
	}
} 

int main(){
	int kesempatan = 3;
	percobaan_login(kesempatan);
    menu_buku_bacaan();
    return 0;
}