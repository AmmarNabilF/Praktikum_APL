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
int buku_terhapus = 0;


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

void BubbleSort(buku arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].judul < arr[j + 1].judul) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void SelectionSort(buku arr[], int n){
	for(int i = 0; i < n - 1; i++){
		int minIndex = i;
		for (int j = i + 1; j < n; j++){
			if (arr[j].tahun_terbit < arr[minIndex].tahun_terbit){
				minIndex = j;
			}
		}
		int temp = arr[minIndex].tahun_terbit;
		arr[minIndex].tahun_terbit = arr[i].tahun_terbit;
		arr[i].tahun_terbit = temp;
	}
}

void InsertionSort(buku arr[], int n){
	string key_penulis;
	string key_judul;
	int key_tahun_terbit;
	int j;
	for(int i = 1; i < n; i++){
		key_penulis = arr[i].penulis;
		key_judul = arr[i].judul;
		key_tahun_terbit = arr[i].tahun_terbit;
		j = i - 1;
		
		while (j >= 0 && arr[j].penulis > key_penulis){
			arr[j + 1].penulis = arr[j].penulis;
			arr[j + 1].judul = arr[j].judul;
			arr[j + 1].tahun_terbit = arr[j].tahun_terbit;
			j = j - 1;
		}
		arr[j + 1].penulis = key_penulis;
		arr[j + 1].judul = key_judul;
		arr[j + 1].tahun_terbit = key_tahun_terbit;
	}
}

int SequentialSearch(buku arr[], int n, string cari){
	for (int i = 0; i < n; i++){
		if (arr[i].judul == cari){
			return i;
		}
	}
	return -1;
}



int BinarySearch(buku arr[], int n, int cari){
	int kiri, kanan;
	kiri = 0;
	kanan = jumlah_buku - 1;
	
	while (kiri <= kanan) {
		int tengah = kiri + (kanan - kiri) / 2;
		
		if (arr[tengah].tahun_terbit == cari){
			return tengah;
		}
		if (arr[tengah].tahun_terbit > cari){
			kanan = tengah - 1;
		}
		else{
			kiri = tengah + 1;
		}
	}
	return -1;
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

int jumlah_data(int *jumlah){
	*jumlah = jumlah_buku;
} 

int jumlah_buku_dihapus(int &terhapus){
	return terhapus = buku_terhapus;
}

void tampilkan_data_buku(){
	if (jumlah_buku == 0) {
		cout << "Belum ada data untuk ditampilkan" << endl;
		cout << " " << endl;
		return;
	}
	cout << "\nPilih sorting dan search\n"
		"1) Judul Buku\n"
		"2) Penulis\n"
		"3) Tahun Terbit\n";
		
	int pilih;
	cout << " " << endl;
	cout << "Pilih sorting berdasarkan apa: ";
	cin >> pilih;
	
	if (pilih == 1){
		BubbleSort(data.data_buku, jumlah_buku);
		for (int i = 0; i < jumlah_buku; ++i){
        	cout << i << ")Judul: " << data.data_buku[i].judul << endl;
        	cout << "Penulis: " << data.data_buku[i].penulis << endl;
        	cout << "Tahun terbit: " << data.data_buku[i].tahun_terbit << endl;
        	cout << " " << endl;
    	}
    	string pilihan;
    	cout << "Ingin mencari judul buku ?(y/n): ";
		cin >> pilihan;
		if (pilihan == "y"){
			string cari_judul;
			cout << "Masukkan judul yang ingin dicari: ";
			cin.clear();
			cin.ignore();
			getline(cin, cari_judul);
			
			int hasil = SequentialSearch(data.data_buku, jumlah_buku, cari_judul);
			
			if (hasil != 1){
				cout << "Data ditemukan pada indeks ke-" << hasil << endl;
				cout << "Judul: " << data.data_buku[hasil].judul << endl;
				cout << "Penulis: " << data.data_buku[hasil].penulis << endl;
				cout << "Tahun Terbit: " << data.data_buku[hasil].tahun_terbit << endl;
			}
			else{
				cout << "Buku dengan judul " << cari_judul << " tidak ada" << endl;
			}
		}
		else{
			return;
		}
	}
	if (pilih == 2){
		InsertionSort(data.data_buku, jumlah_buku);
		for (int i = 0; i < jumlah_buku; ++i){
        	cout << i << ")Judul: " << data.data_buku[i].judul << endl;
        	cout << "Penulis: " << data.data_buku[i].penulis << endl;
        	cout << "Tahun terbit: " << data.data_buku[i].tahun_terbit << endl;
        	cout << " " << endl;
    	}
    	string pilihan;
    	cout << "Ingin mencari penulis buku ?(y/n): ";
		cin >> pilihan;
		if (pilihan == "y"){
			string cari_penulis;
			cout << "Masukkan nama penulis yang ingin dicari: ";
			cin.clear();
			cin.ignore();
			getline(cin, cari_penulis);
			
			int hasil = SequentialSearch(data.data_buku, jumlah_buku, cari_penulis);
			
			if (hasil != 1){
				cout << "Data ditemukan pada indeks ke-" << hasil << endl;
				cout << "Judul: " << data.data_buku[hasil].judul << endl;
				cout << "Penulis: " << data.data_buku[hasil].penulis << endl;
				cout << "Tahun Terbit: " << data.data_buku[hasil].tahun_terbit << endl;
			}
			else{
				cout << "Buku dengan dengan nama penulis " << cari_penulis << " tidak ada" << endl;
			}
		}
		else{
			return;
		}
	}
	
	if (pilih == 3){
		SelectionSort(data.data_buku, jumlah_buku);
		for (int i = 0; i < jumlah_buku; ++i){
        	cout << i << ")Judul: " << data.data_buku[i].judul << endl;
        	cout << "Penulis: " << data.data_buku[i].penulis << endl;
        	cout << "Tahun terbit: " << data.data_buku[i].tahun_terbit << endl;
        	cout << " " << endl;
    	}
    	string pilihan;
    	cout << "Ingin mencari tahun terbit buku ?(y/n): ";
    	cin >> pilihan;
		if (pilihan == "y"){
			int cari_tahunterbit;
			cout << "Masukkan tahun terbit buku yang ingin dicari: ";
			cin.clear();
			cin.ignore();
			cin >> cari_tahunterbit;
		
			int hasil = BinarySearch(data.data_buku, jumlah_buku, cari_tahunterbit);
		
			if (hasil != 1){
				cout << "Data ditemukan pada indeks ke-" << hasil << endl;
				cout << "Judul: " << data.data_buku[hasil].judul << endl;
				cout << "Penulis: " << data.data_buku[hasil].penulis << endl;
				cout << "Tahun Terbit: " << data.data_buku[hasil].tahun_terbit << endl;
			}
			else{
				cout << "Buku dengan tahun terbit " << cari_tahunterbit << " tidak ada" << endl;
			}
	
		}		
		else{
			return;
		}
		
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
		buku_terhapus++;
		
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
	    
	    int banyaknya_buku;
		jumlah_data(&banyaknya_buku);
		cout << " " << endl;
		cout << "Banyaknya buku saat ini: " << banyaknya_buku << endl;
		
		int hapus;
		jumlah_buku_dihapus(hapus);
		cout << "Banyaknya buku yang telah dihapus: " << hapus << endl;
	    cout << " " << endl;
	    
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