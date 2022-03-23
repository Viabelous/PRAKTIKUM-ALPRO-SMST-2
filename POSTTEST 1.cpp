// IBNU YAFI ARYA WARDANA --- 2109106039 --- A'21 INFORMATIKA //

#include <iostream>			//untuk input-output-dsj
#include <cstdlib>			//untuk cls
#include <stdlib.h>			//untuk pewarnaan (dekorasi)
using namespace std;		//agar tidak perlu menuliskan "std::"



// Deklarasi Variabel (digunakan: char, integer, dan boolean):
char pilihanMenu;				//var menu awal dan menu pengulangan
int hasilFaktorial;				//var hasil function faktorial
int banyakObjek;				//var banyak objek (n)
int objekDiperlukan;			//var banyak objek dicari (r)
int hasilAkhir;					//var hasil Permutasi atau Kombinasi
bool berjalan = true;			//var untuk melakukan perulangan program
bool prasyarat = false;			//var untuk mengatasi permasalahan pada procedure perhitungan
bool responPengulangan = true;	//var untuk mengatasi permasalahan pada MENU PENGULANGAN




//program:
void banner(){							//procedure untuk dekorasi program
	cout << "\n /##################################\\ " << endl;
	cout << "  Kalkulator Permutasi dan Kombinasi    " << endl;
	cout << " \\##################################/ \n" << endl;}						




int fakt(int angkaFaktorial){			//function untuk faktorial
hasilFaktorial = angkaFaktorial;
	
	if (angkaFaktorial > 0){			//percabagan if-else untuk mengatasi angkaFaktorial = 0
	
		for (angkaFaktorial; angkaFaktorial > 0; angkaFaktorial--){		//perulangan for menghitung faktorial metode rekursif
		
    		if (angkaFaktorial == 1){
				hasilFaktorial * 1;}
				
			else {hasilFaktorial *= (angkaFaktorial - 1);}
		}
	}
	
	else{hasilFaktorial = 1;}
	return hasilFaktorial;}




void perhitungan(int metodeTerpilih){			//procedure untuk perhitungan
prasyarat = false;
	
	do{											//perulangan do-while untuk mengatasi permasalahan perhitungan
		system("Color 0B");
		cout << " |||> Masukkan banyak objek yang ada (n): "; cin >> banyakObjek;
		cout << " |||> Masukkan banyak objek yang dibutuhkan (r): "; cin >> objekDiperlukan;
		
		
		if (banyakObjek < objekDiperlukan){		//perulangan if-else-if untuk mengatasi permasalahan "tidak terdefinisi"
			cout << " <Objek yang dibutuhkan tidak boleh melebihi objek yang ada!>\n";}
			
		else if (banyakObjek < 0 || objekDiperlukan < 0){
			cout << "         <Objek tidak boleh bernilai negatif!>\n";}
			
		else{prasyarat = true;}
		
		
		cout << " ============================================================\n\n";
	}while (prasyarat == false);
	
	
	switch (metodeTerpilih){					//percabangan switch-case untuk pilihan metode hitung yang berbeda
	
		case'1':								//perhitungan permutasi menggunakan operator aritmatik
			hasilAkhir = fakt(banyakObjek) / fakt(banyakObjek - objekDiperlukan);		
			cout << " Hasil Permutasi --> " << hasilAkhir << endl;
			break;
			
		case'2':								//perhitungan kombinasi menggunakan operator aritmatik
			hasilAkhir = fakt(banyakObjek) / (fakt(objekDiperlukan) * fakt(banyakObjek - objekDiperlukan));
			cout << " Hasil Kombinasi --> " << hasilAkhir << endl;
			break;
			
		default:
			break;}
			
	system("Color 06");
	cout << " Lanjutkan>>"; cin.ignore(1, '\n'); cin.get();}
			
			
			
			
int menu_perulangan(){
	responPengulangan = true;
	do{															//MENU PENGULANGAN (dengan do-while untuk menghindari kesalahan input)
		system("Color 0B");
		system("cls");
		banner();
		cout << "\n Apakah ingin mengulang?\n [1] ya\t\t[2] tidak\n"; 
		cout << " Pilihanmu: " ;cin >> pilihanMenu;
		
		switch (pilihanMenu){									//Percabangan switch-case untuk Menu Perulangan
			
			case '1':
				pilihanMenu = 'a';
				responPengulangan = false;
				berjalan = true;
				break;
				
			case '2':
				system("Color 06");
				cout << "\n Terimakasih telah menggunakan program ini!\n";
				cout << " Lanjutkan>>"; cin.ignore(1, '\n'); cin.get();
				responPengulangan = false;
				berjalan = false;
				break;
				
			default:
				system("Color 06");
				cout << " <Pilihan yang kamu pilih tidak ada>\n";
				cout << " ===================================\n";
				cout << " Lanjutkan>>"; cin.ignore(1, '\n'); cin.get();;
				break;}
	}while (responPengulangan == true);
	return berjalan;}
				



int main(){								//pemulai program
while(berjalan == true){				//perulangan while agar program dapat berulang
while(pilihanMenu != '1' && pilihanMenu != '2'){
	system("cls");
	pilihanMenu = 'a';
	
	system("Color 0B");
	
	banner();
	cout << "\n Selamat Datang! ketik angka menu:" << endl;		//MENU AWAL
	cout << " [1] Permutasi\n [2] Kombinasi" << endl;
	cout << " Pilihanmu: "; cin >> pilihanMenu;
	
	
	switch (pilihanMenu){			//Percabangan switch-case untuk menu
	
		case'1':
		case'2':
			perhitungan(pilihanMenu);
			break;
			
		default:
			system("Color 06");
			cout << "  <Menu yang kamu pilih tidak ada>\n";
			cout << " ==================================\n\n";
			cout << " Lanjutkan>>"; cin.ignore(1, '\n'); cin.get();
			break;}}
	

	berjalan = menu_perulangan();}
	return 0;}
