#include <iostream>					// Dasar: cout, cin, endl
#include <conio.h>					// Untuk menggunakan getch() dan getche()
#include <windows.h>				// Untuk mewarnai console
using namespace std;				// meringkas penulisan std::



//Struct
struct dataPengunjung{								// Struct untuk menyimpan data pengunjung
	int 	nomorKamar						;
	string  nomorPengenal					;
	string 	nama, tipeKamar, catatan		;
	string  tanggalCheckin, tanggalCheckout	;
	bool 	wni								;
};



//Deklarasi Global
bool berjalan = true	; 			// Var untuk prasyarat perulangan program
int  jumlahKamar		;			// Var untuk menghitung jumlah kamar yang ada
int menujuData			;			// Var untuk pergi ke informasi data
char responMenu			;			// Var untuk jawaban pengguna terhadap menu



//Prototype
void   banner        ()										 		 		; // Dekorasi bagian atas program
void   bubbleSort    (dataPengunjung struk[])				 			 	; // Penyortir ruangan hotel
void   checkin       (dataPengunjung struk[])				 			 	; // Menu Checkin
void   checkout      (dataPengunjung struk[])				 			 	; // Menu Checkout
void   dataTampil    (dataPengunjung struk[])				 			 	; // Penampil keseluruhan data
void   dataTampil    (dataPengunjung struk[], int index)				 	; // Penampil informasi data
void   editHotel	 (dataPengunjung struk[])								; // Menu edit hotel
void   hapusData	 (dataPengunjung struk[], int index)					; // Penghapus data
void   kamarDefault  (dataPengunjung struk[])			 	 			 	; // Default kamar
char   konfCheckout	 (dataPengunjung struk[], int index)					; // Konfirmasi Checkout
char   menuMetode    (int rute)							 	 			 	; // Menu metode
void   namaDefault   (dataPengunjung struk[])			 	 			 	; // Default nama kosong
void   palette       (string namaWarna)								 		; // Pewarna
int    papanKetik    (dataPengunjung struk[])							 	; // Keyboard User
string pilihTipeKamar()														; // Daftar pilihan tipe kamar
void   pindahKamar   (dataPengunjung struk[], int kamarSatu, int kamarDua)	; // Pemindah kamar
void   properEditMenu(dataPengunjung struk[], int index)				 	; // Menu edit data
int    search        (dataPengunjung struk[], int nomor)				 	; // Pencari index dengan nomor ruangan
int    search        (dataPengunjung struk[], string tipeKamar)		 		; // Pencari index dengan tipe kamar
int    search        (string nama, dataPengunjung struk[])			 		; // Pencari index dengan nama
void   setColor      (WORD c)								 			 	; // Set Color




int main(){										// Fungsi main
	struct dataPengunjung kunjung[50]	;
	
	kamarDefault(kunjung)				;
	namaDefault	(kunjung)				;
	system		("color 70")			;		// Ubah warna keseluruhan data
	
	do{											// Penggunaan Do-while
	system("CLS")						;		// Hapus layar CMD
	banner()							;
	
	cout << " Menu Interaktif: \n" 	  	    << endl     //------ Menu Utama
		 << "\t [I / 1] Check-in"		    << endl
		 << "\t [O / 2] Check-out"			<< endl
		 << "\t [D / 3] Data Pengunjung"	<< endl
		 << "\t [E / 4] Edit Data" 			<< endl
		 << "\t [M / 5] Olah Kamar"			<< endl
		 << "\t [X / 6] Hentikan Program"	<< endl;
	responMenu = getch();						// Getch() agar pengguna tak perlu menekan tombol Enter
		 
	switch(responMenu){							// Penggunaan switch-case untuk respon pengguna
	 	case '1': case 'I': case 'i':			//------ Checkin
	 		checkin (kunjung);
	 		break			 ;

	 	case '2': case 'O': case 'o':           //------ Checkout
	 		checkout (kunjung);
	 		break			  ;

	 	case '3': case 'D': case 'd':			//------ Tampilankan Data
	 		dataTampil (kunjung);
			break				;

	 	case '4': case 'E': case 'e':			//------ Edit dan lihat data spesifik
	 		system("CLS")					 		 ;
	 		banner()						 		 ;
	 		menujuData = papanKetik (kunjung)		 ;
	 		if (menujuData == 99 || menujuData == 50){		// Penggunaan if-else untuk menghindari error
	 			break								 ;}
	 		else{properEditMenu(kunjung, menujuData) ;}
	 		break									 ;

	 	case '5': case 'M': case 'm':			//------ Edit hotel
		 	editHotel(kunjung);
	 		break;

	 	case '6': case 'X': case 'x':			//------ Keluar
	 		berjalan = false;
	 		break			;}
	 		
	}
	while(berjalan == true);
	
	system	("CLS")						;
	banner	()							;
	
	palette	("Merah")					;
	cout 	<< "\n Program Dihentikan."	;
	palette	("")						;
}
	
	

/*------------------------ DECORATION ------------------------*/

void banner(){
	palette("MerahPutih");
	cout << "                                   " 	<< endl
		 << "    _-***********************-_    " 	<< endl
		 << "   | |                       | |   " 	<< endl
		 << "   | |    [HOTEL BERNAMA]    | |   "	<< endl
		 << "   | |                       | |   " 	<< endl
		 << "   |_-***********************-_|   " 	<< endl
		 << "                                   " 	<< endl;
	palette("");
}



/*------------------------ UTENSILS ------------------------*/

// Set Warna
void setColor(WORD c){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);		// Pengubah warna console windows
}



// Beri Warna
void palette(string namaWarna){
	if 		(namaWarna == "Biru")  		{setColor(113);}
	else if (namaWarna == "Hijau") 		{setColor(114);}
	else if (namaWarna == "Merah") 		{setColor(116);}
	else if (namaWarna == "Kuning")		{setColor(118);}
	else if (namaWarna == "Abu-abu") 	{setColor(120);}
	else if (namaWarna == "MerahPutih") {setColor(508);}
	else 								{setColor(112);}
}



// Cari Nomor Kamar
int search(dataPengunjung struk[], int nomor){
	int indexDitemukan = 0;												// var untuk menampung index dicari
	
	for (int i = 0; i <= 50; i++){										// Penggunaan for untuk menuju semua data
		if 		(i == 50)					   {indexDitemukan = 50;}
		else if (struk[i].nomorKamar == nomor) {break;}
		else 								   {indexDitemukan++;}
	}
	
	return indexDitemukan;
}



// Cari Ketersediaan Kamar
int search(dataPengunjung struk[], string tipeKamar){					//--> Fungsi overloading
	int indexDitemukan = 0;												// var untuk menampung index dicari
	
	for (int i = 0; i <= 50; i++){
		if 		(i == 50)					   							 {indexDitemukan = 50;}
		else if (struk[i].nama == "" && struk[i].tipeKamar == tipeKamar) {break;}
		else 								  							 {indexDitemukan++;}
	}
	
	return indexDitemukan;
}



// Cari Nama
int search(string nama, dataPengunjung struk[]){
	int indexDitemukan = 0;											// var untuk menampung index dicari
	
	for (int i = 0; i <= 50; i++){
		if 		(i == 50) 				{indexDitemukan = 50;}
		else if (struk[i].nama == nama) {break;}
		else 							{indexDitemukan++;}
	}
	
	return indexDitemukan;
}



// Tipe Kamar
string pilihTipeKamar(){
	char   opsiTipeKamar	;										// var respon user
	string tipeKamar		;										// var pilihan user
	
	cout << "\n Tipe Kamar: " 			 << endl
		 << " [0] Standard Room"	 	 << endl
		 << " [1] Superior Room" 		 << endl
		 << " [2] Deluxe Room" 			 << endl
		 << " [3] Junior Suite Room"	 << endl
		 << " [4] Suite Room"			 << endl
		 << " [5] Single Room"			 << endl
		 << " [6] Twin Room"			 << endl
		 << " [7] Double Room"			 << endl
	     << " >> "						 		;
	opsiTipeKamar = getche()					;
	
	switch(opsiTipeKamar){
		case '0':
			tipeKamar = "Standard Room"			;
			break								;
		case '1':
			tipeKamar = "Superior Room"			;
			break								;
		case '2':
			tipeKamar = "Deluxe Room"			;
			break								;
		case '3':
			tipeKamar = "Junior Suite Room"		;
			break								;
		case '4':
			tipeKamar = "Suite Room"			;
			break								;
		case '5':
			tipeKamar = "Single Room"			;
			break								;
		case '6':
			tipeKamar = "Twin Room"				;
			break								;
		case '7':
			tipeKamar = "Double Room"			;
			break								;
		default:
			tipeKamar = "invalid"				;
			break								;
	}
	return tipeKamar							;
}



// Sorting Kamar
void bubbleSort(dataPengunjung struk[]){				// Bubble Sort
	for(int i = 0; i < 48; i++){
		for(int j = 0; j < 48; j++){
			if(struk[j].nomorKamar > struk[j+1].nomorKamar &&
			(struk[j].nomorKamar != 0 && struk[j+1].nomorKamar != 0)){
				swap(struk[j], struk[j+1]);}			// Swap untuk menukar isi indeks array
		}
	}
}



// Delete aka Check Out Data
void hapusData(dataPengunjung struk[], int index){
	struk[index].nama            = ""			;
	struk[index].nomorPengenal   = ""			;
	struk[index].tanggalCheckin  = ""			;
	struk[index].tanggalCheckout = ""			;
	struk[index].catatan 		 = ""			;
}




// Peringkas Menu Yang Ditulis Berulang
char menuMetode(int rute){
	system("CLS")		;
	banner()			;
	
	if (rute == 1){		// Olah Data
		cout << "\n Pilihan Metode Cari: " 	<< endl
			 << " [1] Dengan nomor kamar"   << endl
			 << " [2] Dengan nama"			<< endl;
		rute = getch()							   ;}
		
	if (rute == 2){		// Olah Hotel
		cout << "\n Pilihan Pengolahan: "	<< endl
			 << " [1] Tambahkan Kamar baru" << endl
			 << " [2] Olah Kamar lama"		<< endl;
		rute = getch()							   ;}
		
	return rute									   ;
}



// Untuk Papan Ketikan
int papanKetik(dataPengunjung struk[]){
	int ketik;							// var untuk menampung inputan user
	
	palette ("Abu-abu")										;
   cout << " Ketik '0' untuk kembali ke menu awal " << endl ;
	palette ("")											;		
	
   cout << "\t  [|| "										;
	
	palette ("Biru")										;
   cin  >> ketik											;
	palette ("")											;
	
	cout << "\t  ````````" << endl							;
	
	if   (ketik == 0) {return 99;}	//--> Kembali ke Menu
	else 			  {
		ketik = search(struk, ketik)						;
		
		if (ketik == 50){			//--> Data tidak ada
		palette("Merah")									;
	    cout << "   Kamar Tersebut Tidak Ada." 		<< endl ;
		palette("Kuning")									;
	    cout << "      [Tekan apa saja.]" 	 		<< endl ;
		palette("")											;
		getch()												;
		return 50											;}
		
		else{return ketik									;}}
}



// Untuk Pindah Kamar
void pindahKamar(dataPengunjung struk[], int kamarSatu, int kamarDua){
	palette("Hijau")										  	 ;
   cout << "\t\t Berhasil Dipindahkan."  << endl			  	 ;
	palette("Kuning")										  	 ;
   cout << "\t\t   [Tekan apa saja.]"  	 << endl			  	 ;
    getch()													  	 ;
	    
	swap(struk[kamarSatu], struk[kamarDua])					  	 ;
	swap(struk[kamarSatu].nomorKamar, struk[kamarDua].nomorKamar);
	swap(struk[kamarSatu].tipeKamar,  struk[kamarDua].tipeKamar) ;
	properEditMenu(struk, kamarDua)							  	 ;}



/*------------------------ CHECKIN ------------------------*/
void checkin(dataPengunjung struk[]){
	char   kewarganegaraan				 ;			// var untuk pilihan kewarganegaraan
	string nomorPengenal				 ;			// var untuk nomor pengenal
	string nama, tipeKamar, catatan		 ;			// var nama, var tipe kamar dipilih, var catatan tambahan
	
	system("CLS")							;
	banner()								;
	
	cout << "\n Nama: "; fflush(stdin)		;		// Penggunaan fflush dan getline untuk mengambil inputan dengan spasi
	getline(cin,nama)						;
	
	
	cout << " Nomor Pengenal: "				;
	cin  >> nomorPengenal					; 
	
	tipeKamar = pilihTipeKamar()					;
	
	
	int slot = search(struk, tipeKamar)				;		// var untuk menampung indeks kamar yang tersedia
	if (slot == 50){
		palette("Merah")							;
		cout << "\t\t Kamar Tidak Tersedia." << endl;
		palette("Kuning")							;
		cout << "\t\t   [Tekan apa saja.]" 	 << endl;
		palette("")									;
		getch()										;}
	
	else{
		cout << "\n Nomor Kamar: "					;
		palette("Biru")								;
		cout << struk[slot].nomorKamar << "\n\n"	;
		palette("")									;
	
		cout << " Opsi Kewarganegaraan:" << endl
			 << " [0] WNA" 				 << endl
			 << " [1] WNI" 				 << endl
		     << " >> "					 			;
		kewarganegaraan = getche()					;				// getche(), sama dengan getch() namun inputan ditampilkan
		struk[slot].wni = (kewarganegaraan == '1')? true : false;	// Penggunaan ternary untuk meringkas percabangan
	
		cout << "\n Catatan: ";	fflush(stdin)		;
		getline(cin,catatan)						;
	

	struk[slot].nama 		  = nama				;
	struk[slot].nomorPengenal = nomorPengenal		;	
	struk[slot].catatan 	  = catatan				;
	
	
	cout << "\n Tanggal Check-in:  "; fflush(stdin)	;
	getline(cin,struk[slot].tanggalCheckin)			;
	
	cout << " Tanggal Check-out: "	; fflush(stdin)	;
	getline(cin,struk[slot].tanggalCheckout)		;
	
	
	palette("Biru")									;
	cout << "\n\t\t Berhasil ditambahkan." << endl	;
	palette("Kuning")								;
	cout << "\t\t   [Tekan apa saja.]" 	   << endl	;
	getch()											;}
}



/*------------------------ CHECKOUT ------------------------*/

void checkout(dataPengunjung struk[]){
	char rute = menuMetode(1)	   ;		// var jalur menu metode, var 
	int nomor				 	   ;		// var indeks
	string nama				 	   ;		// var nama
	
	switch (rute){
		case '1': // dengan nomor kamar
			cout << " Masukkan nomor kamar: "					;
			palette		  ("Biru")								;
			cin  >> nomor					 					;
			palette("")											;
			nomor = search(struk, nomor)	 					;
			
			if (nomor == 50){
				palette	  ("Merah")								;
				cout << " Kamar tersebut tidak ada." << endl	;
				palette("Kuning")								;
				cout << "     [Tekan apa saja.]"     << endl	;
				getch()											;}
				
			else{
			konfCheckout(struk, nomor)							;}
			break												;
			
		case '2': // dengan nama
			cout << " Masukkan nama: "; 						;
			palette		  ("Biru")								;
			fflush(stdin)										;
			getline		  (cin,nama)							;
			palette("")											;
			nomor = search(nama, struk)							;
			
			if (nomor == 50){
				palette	  ("Merah")								;
				cout << "\n Nama tidak ditemukan." 	 << endl	;
				palette("Kuning")								;
				cout << "  [Tekan apa saja.]"     	 << endl	;
				getch()											;}
				
			else{
				konfCheckout(struk, nomor)						;}
			break												;}
}



char konfCheckout(dataPengunjung struk[], int index){
	char opsi;							// var untuk menampung jawaban user
	
	cout << " Lanjutkan Check-out? (y/n)" << endl	;
	opsi = getch()									;
	opsi = (opsi == 'y' || opsi == 'Y') ? 'y' : 'n'	;
				
	if (opsi == 'y'){hapusData(struk, index)		;
	system ("CLS")									;
	banner ()										;
	palette("Hijau")								;
   cout << "\t Checkout Berhasil."  	<< endl		;
	palette("Kuning")								;
   cout << "\t [Tekan apa saja.]" 	 	<< endl		;
	palette("")										;
	getch()											;}
	return opsi;
}

/*------------------------ TAMPILKAN DATA ------------------------*/
void dataTampil(dataPengunjung struk[]){
	
	int lantai[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  ; // Array banyaknya kamar pada tiap lantai
	int index									     ; // var index
	
	for (int l = 0; l < 10; l++) {
		system("CLS")			;
		banner()				;
		
		
		if 		(l == 3) 						   		{continue						     ;} // Vanish lantai 4
		else if ((l+1) * 100 > struk[index].nomorKamar) {break	 						     ;}
		else											{cout << "\t\tLANTAI " << l+1 << endl;}
		
		for (int i = 0; i < 20; i++) {
			if (struk[index].nomorKamar == 0)			     {break;}	// Mengatasi penulisan kamar kosong
			if (struk[index].nomorKamar > (l+1) * 100 + 100) {break;}	// Pemisahan kamar per lantai
			
			cout << " [" << struk[index].nomorKamar << "] ";
			
			if (struk[index].nama == "") {palette("Hijau"); cout << "Kosong\n"	   		<< endl;}
			else 				 		 {palette("Merah"); cout << "Tidak Kosong\n" 	<< endl;}
			
			index++					;
			lantai[l]++				;	
			palette("")				;}	
			
			if (l != 0)							   	   {cout << " [Z] << \t"		;}
														cout << " [X] Papan Ketik"	;
			if ((l+1) * 100 < struk[index].nomorKamar) {cout << " \t\t>> [C]"		;}
			
			responMenu = getch();
		
			switch(responMenu){
			
				case'z': case'Z':	// Halaman Sebelumnya
					if(l > 0){
						if(l == 4){ // Vanish lantai 4
							index -= (lantai[4] + lantai[2])  ;
							lantai[4] = 0					  ;
							lantai[2] = 0					  ;
							l = 1							  ;}
						
						else	  {
							index -= (lantai[l] + lantai[l-1]);
							lantai[l] = 0					  ;
							lantai[l-1] = 0					  ;
							l -= 2							  ;}
						}
						
					else{
						index -= lantai[l]					;
						lantai[l] = 0						;
						l -= 1								;
						}
						
					break									;
				
				
				case'x': case'X':	// Memunculkan papan ketik
					cout << "\n\n" << endl					;
					menujuData = papanKetik(struk)			;
					
					if      (menujuData == 50){
						index -= lantai[l]	  				;
						lantai[l] = 0						;
						l -= 1					  			;}
					
					else if (menujuData == 99) {
						l = 10					  			;}
					
					else					  {
						l = 10								;
						properEditMenu(struk, menujuData)	;}
					
					break;
					
					
				case'c': case 'C':	// Halaman Selanjutnya
					if ((l+1) * 100 < struk[index].nomorKamar)	{
						break								;}
				
				default:
					index -= lantai[l]					;
					lantai[l] = 0						;
					l -= 1								;
					break;}
}
}

void dataTampil(dataPengunjung struk[], int index){
	system("CLS");
	banner()	 ;
	
	cout << "	.Informasi Kamar " << struk[index].nomorKamar << "."  << endl
		 << " Tipe Kamar: \t\t"	   << struk[index].tipeKamar  << "\n" << endl
		 << " Nama: \t\t\t" 	   << struk[index].nama 			  << endl
		 << " Kewarganegaraan: \t"											 ;
	string kewarganegaraan = (struk[index].wni == true) ? "WNI" : "WNA"		 ;
	
	if(struk[index].nama == ""){cout << "" 							  << endl;}
	else 					   {cout << kewarganegaraan				  << endl;}
	
	cout << " Nomor Pengenal: \t"    << struk[index].nomorPengenal 	  << endl
		 << "\n Tanggal Check-in:\t" << struk[index].tanggalCheckin	  << endl
		 << " Tanggal Check-out:\t"  << struk[index].tanggalCheckout  << endl
		 << "\n Catatan:\n "		 << struk[index].catatan		  << endl;
}



/*------------------------ MENU EDIT ------------------------*/
void properEditMenu(dataPengunjung struk[], int index){
	char opsi		;				// var untuk pilihan menu user
	int kamarLain	;				// var untuk menampung kamar pindahan
	
	if(struk[index].nama == ""){
	system ("CLS")									;
	banner ()										;
	
	palette("Merah")								;
   cout << "\t Data tidak ada."  		<< endl		;
	palette("Kuning")								;
   cout << "\t[Tekan apa saja.]" 	 	<< endl		;
	palette("")										;
	getch()											;}
	
	else{
	do{
	dataTampil(struk, index)				     ;
	cout << "\n Ubah: " 				  << endl
		 << " [1] Check-out" 			  << endl
		 << " [2] Pindah Kamar" 		  << endl
		 << " [3] Kembali ke menu awal\n" << endl;
	opsi = getch()						     ;

	switch(opsi){
		case '1':
			opsi = konfCheckout(struk, index)				;
			if (opsi == 'y'){opsi = '3'						;}
			break											;
		
		case '2':
			cout << " Pindahkan ke kamar nomor: "			;
			cin  >> kamarLain								;
			kamarLain = search(struk, kamarLain)			;
			if (kamarLain == 50){
				palette("Merah")							;
			   cout << "\t\t Kamar Tidak Tersedia."  << endl;
				palette("Kuning")							;
			   cout << "\t\t   [Tekan apa saja.]" 	 << endl;
				palette("")									;
				getch()										;}
			
			else if (struk[kamarLain].nama != ""){
				palette("Merah")							  ;
			   cout << "\t\t Kamar Sedang Ditempati" << endl  ;
				palette("")									  ;
			   cout << " Tukar Kamar? (y/n)" 		 << endl  ;
			   opsi = getch()								  ;
			   opsi = (opsi == 'y' || opsi == 'Y') ? '3' : 'n';
			   if (opsi == '3'){
				pindahKamar(struk, index, kamarLain)		  ;
			   }}
				
			else{
				pindahKamar(struk, index, kamarLain)		;
				opsi = '3'									;}
				
			break											;
		
		case '3':	
		default:
			break;}
	}
	while(opsi != '3');}
}



/*------------------------ OLAH HOTEL ------------------------*/
void editHotel(dataPengunjung struk[]){
	int    slot, nomorKamarBaru, index;			// var index kosong, nomor kamar dituju, index
	char   opsi, konfHapus			  ;			// var pilihan menu user, konfirmasi hapus user
	string tipeKamar				  ;			// var tipe kamar
	bool   konfirmasi				  ;			// var konfirmasi user
	
	opsi = menuMetode(2);
	switch(opsi){
		case '1':
			system("CLS")								;
			banner()									;
			
			cout << " Ketik nomor kamar baru: "			;
			cin  >> nomorKamarBaru			   			;
			slot = search(struk, nomorKamarBaru)    	;
			if (slot == 50){
				slot = search(struk, 0)					;
				tipeKamar = pilihTipeKamar()   			;
				
				struk[slot].nomorKamar = nomorKamarBaru	;
				struk[slot].tipeKamar  = tipeKamar		;
				
				palette("Hijau")								  ;
			   cout << "\t\t Kamar Berhasil ditambahkan."  << endl;
				palette("Kuning")								  ;
			   cout << "\t\t   [Tekan apa saja.]" 		   << endl;
				palette("")										  ;
				getch()											  ;}
				
			else{
				palette("Merah")								  ;
			   cout << "\t\t Kamar Sudah ada."  		   << endl;
				palette("Kuning")								  ;
			   cout << "\t\t [Tekan apa saja.]" 	 	   << endl;
				palette("")										  ;
				getch()											  ;}
			break;
		
		case '2':
			system("CLS")								;
			banner()									;
			
			index = papanKetik(struk)					;
			
			if (struk[index].nama == ""){
				do{
				dataTampil(struk, index)					;
				cout << " Olah Kamar:	" 			<< endl
					 << " [1] Ubah Jenis Kamar"		<< endl
					 << " [2] Hapus Kamar"			<< endl 
					 << " [3] Kembali"				<< endl;
				opsi = getch()								;
				switch(opsi){
					case '1':
						tipeKamar = pilihTipeKamar();
						struk[index].tipeKamar  = tipeKamar	;
						break;
						
					case '2':
						cout << " Hapus Kamar? (y/n)" << endl	;
						konfHapus = getch()						;
						konfirmasi = (konfHapus == 'y' || konfHapus == 'Y')? true:false;
						
						if (konfirmasi == true){	
						struk[index].nomorKamar = 0				;
						struk[index].tipeKamar  = ""			;
						for (int i = index; i < 48; i++){
							swap(struk[i], struk[i+1]);}		;
						opsi 					= '3'			;}
						else {break;}
						break;}
						
				}while(opsi != '3');
			}
				 
				 
			else{
				palette("Merah")								  ;
			   cout << "\t\t Kamar Sedang Ditempati."  	   << endl;
				palette("Kuning")								  ;
			   cout << "\t\t    [Tekan apa saja.]" 	 	   << endl;
				palette("")										  ;
				getch()											  ;}
			break;
				
	}			
	bubbleSort(struk);

}



/*------------------------ DEFAULT ------------------------*/

// Nama default yang diberikan
void namaDefault(dataPengunjung struk[]){
	for (int i = 0; i < 50; i++) {struk[i].nama = "";}
}



// Kamar Default yang diberikan
void kamarDefault(dataPengunjung struk[]){
	int kamar = 100	;
	int index = 0	;
	
	for (int i = 1; i < 6; i++){
		
		if (kamar == 400){kamar = 405;}
		
		else{
			for (int j = 1; j < 6; j++){
				kamar += 1					   			;
				struk[index].nomorKamar = kamar			;
				struk[index].tipeKamar = "Standard Room";
				index++						   			;
				jumlahKamar++				  			;}}
		
		kamar += 95										;}
		
		struk[index].nomorKamar = kamar + 1				;
		index++						   	   				;
		
		struk[index].nomorKamar = 701					;
		index++											;
		
	for (int i = index; i < 50; i++){struk[index].nomorKamar = 0;}
}

