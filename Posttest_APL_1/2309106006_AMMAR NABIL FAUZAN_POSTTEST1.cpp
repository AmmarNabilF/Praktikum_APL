//JUDUL: KONVERSI MATA UANG

//NAMA : AMMAR NABIL FAUZAN
//NIM  : 2309106006

#include <iostream>
#include <cstdlib>
using namespace std;

void user_login(){
	string nama = "ammar nabil fauzan";
	string nim = "2309106006";
	int salah = 0;
	
	for (int i = 0; i < 3; ++i){
		
		string username;
		cout << "Masukkan username anda: ";
		getline(cin, username); 
		string password;
		cout << "Masukkan password anda: ";
		getline(cin, password);
		
		if (username == nama && password == nim){
			cout << "Login berhasil" << endl;
			cout << " " << endl;
			break;		
			
		}else if (username == nama){
			cout << "password salah"<< endl;
		
		}else if (password == nim){
			cout << "username salah" << endl;
			
		}else{
			cout << "Username maupun Password tidak ada yang benar\n" << endl;
		}
		++salah;
		
		if (salah == 3){
			cout << "Anda gagal login. Saatnya saya mengusir anda dari program ini";
			exit(EXIT_FAILURE);
		}
	}

 }
 /* BAGIAN PERTAMA DARI MENU UTAMA */
 void tukar_uang_rupiah(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_dollar;
 	ke_dollar = uangkamu * 0.000064;
 	cout << "Berikut hasil pertukaran rupiah ke dollar: $" << ke_dollar << endl;
}
void tukar_uang_rupiah2(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_euro;
 	ke_euro = uangkamu * 0.000059;
 	cout << "Berikut hasil pertukaran rupiah ke euro: €" << ke_euro << endl;
}
void tukar_uang_rupiah3(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_yen;
 	ke_yen = uangkamu * 0.0096;
 	cout << "Berikut hasil pertukaran rupiah ke yen: ¥" << ke_yen << endl;
}
/* BAGIAN KEDUA DARI MENU UTAMA */

void tukar_uang_dollar(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_rupiah;
 	ke_rupiah = uangkamu * 15700;
 	cout << "Berikut hasil pertukaran dollar ke rupiah: Rp. " << ke_rupiah << endl;
}
 void tukar_uang_dollar2(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_euro;
 	ke_euro = uangkamu * 0.92;
 	cout << "Berikut hasil pertukaran dollar ke rupiah: €" << ke_euro << endl;
}
void tukar_uang_dollar3(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_yen;
 	ke_yen = uangkamu * 150.10;
 	cout << "Berikut hasil pertukaran dollar ke yen: ¥" << ke_yen << endl;
}
/* BAGIAN KETIGA DARI MENU UTAMA*/

void tukar_uang_euro(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_rupiah;
 	ke_rupiah = uangkamu * 17043.68;
 	cout << "Berikut hasil pertukaran euro ke rupiah: Rp." << ke_rupiah << endl;
}
void tukar_uang_euro2(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_dollar;
 	ke_dollar = uangkamu * 1.09;
 	cout << "Berikut hasil pertukaran euro ke dollar: $" << ke_dollar << endl;
}
void tukar_uang_euro3(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_yen;
 	ke_yen = uangkamu * 162.93;
 	cout << "Berikut hasil pertukaran euro ke yen: ¥" << ke_yen << endl;
}
/* BAGIAN KEEMPAT DARI MENU UTAMA*/

void tukar_uang_yen(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_rupiah;
 	ke_rupiah = uangkamu * 104.61;
 	cout << "Berikut hasil pertukaran yen ke rupiah: Rp." << ke_rupiah << endl;
}
void tukar_uang_yen2(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_dollar;
 	ke_dollar = uangkamu * 0.0067 ;
 	cout << "Berikut hasil pertukaran euro ke yen: $" << ke_dollar << endl;
}
void tukar_uang_yen3(){
 	int uangkamu;
 	cout << "Masukkan nominal mata uang: ";
 	cin >> uangkamu;
 	float ke_euro;
 	ke_euro = uangkamu * 0.0061 ;
 	cout << "Berikut hasil pertukaran yen ke euro: €" << ke_euro << endl;
}
void menu_konversi_rupiah(){
	while (true){
	cout << " " << endl;
	cout << "MENU KONVERSI RUPIAH\n"
	"0) MENU UTAMA\n"
	"1) RUPIAH KE DOLLAR\n"
	"2) RUPIAH KE EURO\n"
	"3) RUPIAH KE YEN\n";
	
	int pilih;
	cout << "Silahkan pilih angka diatas lalu tekan enter: ";
	cin >> pilih;
	if (pilih == 0){
		break;
	}else if (pilih == 1){
		tukar_uang_rupiah();
		
	}else if (pilih == 2){
		tukar_uang_rupiah2();
		
	}else if (pilih == 3){
		tukar_uang_rupiah3();
		
	}else{
		cout << "tidak ada opsi dengan angka tersebut" << endl;
		
	}
	}
}

void menu_konversi_dollar(){
	while (true){
	cout << " " << endl;
	cout << "MENU KONVERSI DOLLAR\n"
	"0) MENU UTAMA\n"
	"1) DOLLAR KE RUPIAH\n"
	"2) DOLLAR KE EURO\n"
	"3) DOLLAR KE YEN\n";
	int pilih;
	cout << "Silahkan pilih angka diatas lalu tekan enter: ";
	cin >> pilih;
	if (pilih == 0){
		break;
	}
	else if (pilih == 1){
		tukar_uang_dollar();
		
	}else if (pilih == 2){
		tukar_uang_dollar2();
		
	}else if (pilih == 3){
		tukar_uang_dollar3();
		
	}else{
		cout << "tidak ada opsi dengan angka tersebut" << endl;
		
	}
	}
}

void menu_konversi_euro(){
	while (true){
	cout << " " << endl;
	cout << "MENU KONVERSI EURO\n"
	"0) MENU UTAMA\n"
	"1) EURO KE RUPIAH\n"
	"2) EURO KE DOLLAR\n"
	"3) EURO KE YEN\n";
	int pilih;
	cout << "Silahkan pilih angka diatas lalu tekan enter: ";
	cin >> pilih;
	if (pilih == 0){
		break;
	}
	else if (pilih == 1){
		tukar_uang_euro();

	}else if (pilih == 2){
		tukar_uang_euro2();
		
	}else if (pilih == 3){
		tukar_uang_euro3();
		
	}else{
		cout << "tidak ada opsi dengan angka tersebut" << endl;
		
	}
	}
}

void menu_konversi_yen(){
	while (true){
	cout << " " << endl;
	cout << "MENU KONVERSI YEN\n"
	"0) MENU UTAMA\n"
	"1) YEN KE RUPIAH\n"
	"2) YEN KE DOLLAR\n"
	"3) YEN KE EURO\n";
	int pilih;
	cout << "Silahkan pilih angka diatas lalu tekan enter: ";
	cin >> pilih;
	
	if (pilih == 0){
		break;
	}
	else if (pilih == 1){
		tukar_uang_yen();
		
	}else if (pilih == 2){
		tukar_uang_yen2();
		
	}else if (pilih == 3){
		tukar_uang_yen3();
		
	}else{
		cout << "tidak ada opsi dengan angka tersebut" << endl;
		
	}
	}
}

void main_menu(){
	while (true){
	cout << " " << endl;
	cout << "MENU UTAMA\n"
	"0) KELUAR PROGRAM/BERHENTI\n"
	"1) KONVERSI NILAI RUPIAH\n"
	"2) KONVERSI NILAI DOLLAR\n"
	"3) KONVERSI NILAI EURO\n"
	"4) KONVERSI NILAI YEN\n";
	int pilih;
	cout << "Silahkan pilih angka diatas lalu enter: ";
	cin >> pilih;
	
	if (pilih == 0){
		cout << "BYE - BYE" << endl;
		break;
	}else if (pilih == 1){
		menu_konversi_rupiah();
	
	}else if (pilih == 2){
		menu_konversi_dollar();
		
	}else if (pilih == 3){
		menu_konversi_euro();
		
	}else if (pilih == 4){
		menu_konversi_yen();
	
	}else{
		cout << "tidak ada opsi dengan angka tersebut" << endl;
	}
	}
}
int main(){
	user_login();
	main_menu();
	return 0;
	}