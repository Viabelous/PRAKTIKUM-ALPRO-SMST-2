#include <iostream>				// Untuk input-output-endl
#include <conio.h>				// Untuk getch() dan getche()
using namespace std;			// Untuk menyederhanakan iostream agar tanpa std::



/* ----------- Deklarasi Var Global ----------- */
string namaTernak[100];			/* String nama ternak */
string dataTernak[100][2];		/* String detail ternak: JenisTernak, JenisKelamin */
char pilihanMenu;				/* Untuk jawab opsi menu */



/* ----------- Prototype ----------- */
void decor();						// untuk dekorasi bagian atas program
void decor(int jumlahGaris);		// untuk dekorasi lain yang berulangan
void tampilkanData();				// untuk menampilkan data keseluruhan
void tampilkanData(int index);		// untuk menampilkan data secara spesifik
void isiData();						// untuk menambah data baru
void cariData();					// untuk mencari index data pada array
void bumiHanguskan(int hapus);		// untuk menghapus data pada array
int search(string dicari);			// untuk pengguna mencari data
string isiDataNama();				// untuk mengisi nama data baru
string isiDataJenisTernak();		// untuk mengisi jenis ternak data baru
string isiDataJenisKelamin();		// untuk mengisi jenis kelamin ternak baru



/* ----------- Main ----------- */
int main(){
	/*Contoh Data
	namaTernak[0] = "Isabella"; dataTernak[0][0] = "Mama"; dataTernak[0][1] = "Perempuan";
	namaTernak[1] = "Norman"; dataTernak[1][0] = "Domba"; dataTernak[1][1] = "Jantan";
	namaTernak[2] = "Ray"; dataTernak[2][0] = "Sapi"; dataTernak[2][1] = "Jantan";
	namaTernak[3] = "Emma"; dataTernak[3][0] = "Ayam"; dataTernak[3][1] = "Betina";
	namaTernak[4] = "Don"; dataTernak[14][0] = "Manusia"; dataTernak[14][1] = "Jantan";
	namaTernak[5] = "Gilda"; dataTernak[99][0] = "Manusia"; dataTernak[99][1] = "Betina";
	*/

	
	do{									// Do-while agar program dapat terus berjalan
	system("CLS");						// Untuk menghapus isi layar CMD
	system("color 70");					// Untuk mengubah warna CMD
	decor();
	
	
	cout << "\n\n Pilihan Menu:" << endl;						// Menu Utama
	cout << " [1] Daftar Hewan Ternak" << endl;
	cout << " [2] Cari Data Ternak Dengan Nama" << endl;
	cout << " [3] Tambah Data Baru" << endl;
	cout << " [X] Keluar\n" << endl;
	pilihanMenu = getch();										// Getch() agar pengguna tidak perlu menekan tombol Enter
	
	
	switch(pilihanMenu){										// switch-case untuk respon pilihan pengguna
		
		case '1':
			tampilkanData();
			break;
			
		case '2':
			cariData();
			break;
			
		case '3':
			isiData();
			break;
			
			
		case 'x':												// Penutupan program
		case 'X':
			cout << "\n Terimakasih telah menggunakan program ini!" << endl;
			break;}
	
			
	}while(pilihanMenu != 'x' && pilihanMenu != 'X');
	
	return 0;}



/* ----------- Utensil ----------- */


// Untuk Menghapus
void bumiHanguskan(int hapus){
	for (int index = 0; index < 99; index++){					// Penggunaan For dan if agar index data berurutan saat dihapus
		if (index >= hapus){
			namaTernak[index] = namaTernak[index + 1];
			dataTernak[index][0] = dataTernak[index + 1][0];
			dataTernak[index][1] = dataTernak[index + 1][1];}}

	namaTernak[99] = "";
	dataTernak[99][0] = "";
	dataTernak[99][1] = "";}


// Untuk Mencari Index
int search(string dicari){
	int ditemukan = 0;
	
	
	for (int index = 0; index <= 100; index++){					// Penggunaan for dan if untuk membandingkan data satu persatu
		if (index == 100){continue;}
		else if (namaTernak[index] == dicari){break;}
		ditemukan++;}
		
		
	return ditemukan;}



/* ----------- Dekorasi Aplikasi ----------- */				// Ketiga procedure di bawah hanya untuk dekorasi
void decor (int jumlahGaris){
	for(int i = 0; i <= jumlahGaris; i++){
		cout << "-";
	}
}



void decor(){												// Penggunaan konsep overloading
	decor(41);
	
	cout << "\n" << endl;
	cout << "\t      P r o g r a m" << endl;
	cout << "\t    P e n d a t a a n" << endl;
	cout << "\t H e w a n  T e r n a k" << endl;
	cout << endl;

	decor(41);}



void decor(string hewan){
	if(hewan == "Ayam" || hewan == "Bebek"){
	cout << "\t   _____ " << endl;
	cout << "\t  /     \\ " << endl;
	cout << "\t |       | " << endl;
	cout << "\t |       | " << endl;
	cout << "\t  \\_____/ " << endl;}
		
	else if(hewan == "Sapi" || hewan == "Kambing" || hewan == "Unta"){
	cout << "\t  _________" << endl;
	cout << "\t [_________] " << endl;
	cout << "\t   ||||||| " << endl;
	cout << "\t  /       \\ " << endl;
	cout << "\t |O      O | " << endl;
	cout << "\t |  O      | " << endl;
	cout << "\t |      O  | " << endl;
	cout << "\t |_________| " << endl;}
	
	else if(hewan == "Domba"){
	cout << "\t  _________ " << endl;
	cout << "\t (         )" << endl;
	cout << "\t (        ))" << endl;
	cout << "\t (         )" << endl;
	cout << "\t ((        )" << endl;
	cout << "\t (_________)" << endl;}
	
	else{
	cout << "\t   ______||_ " << endl;
	cout << "\t  /_________\\ " << endl;
 	cout << "\t /___________\\ " << endl;
	cout << "\t ||||||||||||| " << endl;
	cout << "\t |           | " << endl;
 	cout << "\t |     _     | "<< endl;
	cout << "\t |____|_|____| " << endl;}
}



/* -------------- Tampilkan Data -------------- */
void tampilkanData(){
	
	int index = 0;
	
	do{
		system("CLS");
		decor();
	
		int halaman = index / 10 + 1;								// var untuk menentukan halaman penampilan	
		cout << "\n Halaman " << halaman << " dari 10" << endl; 
	
	
		for (int nomor = 0; nomor < 10; nomor-= -1){				// var untuk menampilkan halaman
			cout << " [" << nomor << "] " << namaTernak[index] << endl;
			index++;}
		decor(41);
	
	
		cout << "\n Tekan angka data yang ingin diperiksa atau pilih menu di bawah:" << endl;	// Menu interaksi data ditampilkan
			if (index > 10){cout << " [Z] Halaman Sebelumnya\t\t";}
			cout << " [X] Ke Menu\t\t";
			if (index < 100){cout << " [C] Halaman Selanjutnya";}
		pilihanMenu = getch();
		
		
		// Respon terhadap Pilihan
		int dataPilihan = pilihanMenu - 48;														// Respon menu interaksi data ditampilkan
			if 		(index == 10 && (pilihanMenu == 'Z' || pilihanMenu == 'z')){index = 0;}
			else if (pilihanMenu == 'Z' || pilihanMenu == 'z'){index -= 20;}
			else if (index == 100 && (pilihanMenu == 'C' || pilihanMenu == 'c')){index = 90;}
			else if (pilihanMenu == 'C' || pilihanMenu == 'c'){continue;}
			else if (dataPilihan < 0 || dataPilihan > 9){index -= 10;}
			else	{tampilkanData(dataPilihan); break;}
	
	}while(pilihanMenu != 'X' && pilihanMenu != 'x');
	
	pilihanMenu = '0';}



void tampilkanData(int index){								// Penggunaan overloading (2)
	string Response;										// var untuk respon penghapusan
	
	do{
	system("CLS");
	decor();
	cout << endl;
	
	
	if (index < 100){
		
	decor(30); cout << endl;
	decor(dataTernak[index][0]);
	decor(30); cout << endl;
	
	cout << " Nama Ternak\t: " << namaTernak[index] << endl;		// Untuk menampilkan Nama Ternak
	cout << " Jenis Ternak\t: " << dataTernak[index][0] << endl;	// Untuk menampilkan Jenis Ternak
	cout << " Jenis Kelamin\t: " << dataTernak[index][1] << endl;	// Untuk menampilkan Jenis Kelamin
	
	decor(30);
	
	cout << "\n\n Pilihan Menu:" << endl;
	cout << " [1] Ubah Nama\t\t [3] Ubah Jenis Kelamin Ternak" << endl;
	cout << " [2] Ubah Jenis Ternak\t [4] Hapus Data" << endl;
	cout << " [X] Keluar" << endl;
	pilihanMenu = getch();										// Getch() agar pengguna tidak perlu menekan tombol Enter
	
	cout << endl;
	switch(pilihanMenu){
		case '1':
			namaTernak[index] = isiDataNama();					// Untuk mengisi data nama ternak
			break;
			
		case '2':
			dataTernak[index][0] = isiDataJenisTernak();		// Untuk mengisi jenis data ternak
			break;
			
		case '3':
		 	dataTernak[index][1] = isiDataJenisKelamin();		// Untuk mengisi data jenis kelamin ternak
		 	break;
		 	
		case '4':
			cout << " Ketik HAPUS untuk mengkonfirmasi" << endl;
			cout << " >> "; cin >> Response;					// Untuk konfirmasi penghapusan
			if (Response == "HAPUS"){
				bumiHanguskan(index);
				pilihanMenu = 'x';
				break;}
			else{break;}
			
		case 'X':
		case 'x':
			break;}}
			
			
	else{														// Untuk penanganan error
		decor(30);
		cout << "\n\n Ternak dengan nama tersebut tidak ada.\n" << endl;
		decor(30);
		
		cout << "\n  [Tekan apa saja untuk kembali ke menu awal]" << endl;
		pilihanMenu = 'x';
		getch();}
	
	
	}while(pilihanMenu != 'X' && pilihanMenu != 'x');
	pilihanMenu = '0';}



/* -------------- Pencarian Data -------------- */
void cariData(){												// Untuk mencari index data
	system("CLS");
	decor();
	
	string dicari;
	int indexDitemukan;
	
	cout << "\n Masukkan Nama Ternak: "; fflush(stdin);			// fflush(stdin) untuk membersihkan konsol
	getline(cin,dicari);										// getline untuk menginput data lebih dari 1 kata
	indexDitemukan = search(dicari);
	
	tampilkanData(indexDitemukan);}
	
	

/* -------------- Isi Data -------------- */
void isiData(){
	int lahanKosong;											// Var untuk mencari elemen array yang kosong
	int ketersediaan;											// Var untuk mencari apakah nama sudah ada di dalam array
	string nama;												// Var untuk inputan nama ternak baru
	string jenisTernak;											// Var untuk jenis ternak untuk ternak baru
	string jenisKelamin;										// Var untuk jenis kelamin untuk ternak baru
	
	system("CLS");
	decor();
	
	lahanKosong = search("");								// Untuk mencari data "" (kosong) pada array
	if(lahanKosong == 100){
	cout << "\n Ruang Penyimpanan Data Penuh.";
	cout << "\n  [Tekan apa saja untuk kembali ke menu awal]" << endl;
	getch();}
	
	
	else{
	cout << endl;
	nama = isiDataNama();									// Formulir Pengisian data baru					
	jenisTernak = isiDataJenisTernak();
	jenisKelamin = isiDataJenisKelamin();
	
	
	ketersediaan = search(nama);							// Untuk menghindari adanya duplikasi pada array
	if(ketersediaan < 100){lahanKosong = ketersediaan;}
	
	
	namaTernak[lahanKosong] = nama;							// Pengisian data baru pada array
	dataTernak[lahanKosong][0] = jenisTernak;
	dataTernak[lahanKosong][1] = jenisKelamin;
		
	tampilkanData(lahanKosong);}}



string isiDataNama(){
	string Nama;													// Var nama ternak baru
	cout << "\n Masukkan Nama Ternak Baru: " ; fflush(stdin);
	getline(cin,Nama);
	cout << endl;
	return Nama;}



string isiDataJenisKelamin(){
	char JenisKelamin;												// Var data jenis kelamin ternak baru
	cout << "\n Jenis Kelamin: [1] Jantan" << endl;
	cout << "                [2] Betina" << endl;
	cout << "                [3] Hemafrodit" << endl;
	cout << " Pilih: "; JenisKelamin = getche();					// getche(), sama seperti getch() namun inputan user terlihat
	
	
	switch(JenisKelamin){
		case'1':							// program akan memasukkan data "Jantan" pada jenis kelamin ternak
			return "Jantan";
			break;
			
		case'2':							// program akan memasukkan data "Betina" pada jenis kelamin ternak
			return "Betina";
			break;
			
		case'3':							// program akan memasukkan data "Hemafrodit" pada jenis kelamin ternak
			return "Hemafrodit";
			break;
			
		default:							// program akan mengosongkan data jenis kelamin ternak
			return "";
			break;}}
			


string isiDataJenisTernak(){
	char JenisTernak;										// Var untuk jenis ternak dari ternak baru
	string JenisTernakKustom;								// Var untuk jenis ternak kustom
	
	cout << "\n Jenis Ternak: [1] Ayam" << endl;
	cout << "               [2] Bebek" << endl;
	cout << "               [3] Sapi" << endl;
	cout << "               [4] Kambing" << endl;
	cout << "               [5] Unta" << endl;
	cout << "               [6] Domba" << endl;
	cout << "               [K] Kustom" << endl;
	cout << " Pilih: "; JenisTernak = getche();
	cout << endl;
	
	
	switch(JenisTernak){
		case'1':							// program akan memasukkan data "ayam" pada jenis ternak
			return "Ayam";
			break;
			
		case'2':							// program akan memasukkan data "bebek" pada jenis ternak
			return "Bebek";
			break;
			
		case'3':							// program akan memasukkan data "sapi" pada jenis ternak
			return "Sapi";
			break;
			
		case'4':							// program akan memasukkan data "kambing" pada jenis ternak
			return "Kambing";
			break;
			
		case'5':							// program akan memasukkan data "unta" pada jenis ternak
			return "Unta";
			break;
			
		case'6':							// program akan memasukkan data "domba" pada jenis ternak
			return "Domba";
			break;
			
		case'K':							// program akan meminta pengguna memasukkan jenis ternak lain
		case'k':
			cout << "\n Masukkan Jenis Hewan: "; fflush(stdin);
			getline(cin,JenisTernakKustom);
			return JenisTernakKustom;
			break;
			
		default:							// program akan mengosongkan jenis ternak
			return "";
			break;}}
