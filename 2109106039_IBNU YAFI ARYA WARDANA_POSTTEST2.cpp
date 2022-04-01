// IBNU YAFI ARYA WARDANA --- 2109106039 --- A'21 INFORMATIKA //

#include <iostream>			//untuk input-output-endl
#include <conio.h>			//untuk memperindah tampilan user interface
#include <stdlib.h>
using namespace std;		//agar tidak perlu menuliskan "std::"


// Deklarasi variabel; variabel digunakan: integer, char, array, pointer, dan boolean.
int matriksPertama[3][3];				// variabel matriks 1 atau a
int matriksKedua[3][3];					// variabel matriks 2 atau b
int matriksHasil[3][3];					// variabel matriks 3 atau c
int *pointer;							// variabel pointer
int barisDiperbaiki;					// variabel pemilihan baris matriks
int kolomDiperbaiki;					// variabel pemilihan kolom matriks
char pilihanMenu;						// variabel memilih menu
bool berjalan = true;					// variabel untuk segala macam perulangan yang ada
bool responPengulangan = true;			// var untuk mengatasi salah inputan pada MENU PENGULANGAN



void isi_matriks(char namaMatriks, int array [3][3]){				//procedure mengisi matriks
	pointer = &array[0][0];											//pointer untuk mengarahkan letak pengisian nilai
	for (int i = 1; i < 4; i++){									//nested for untuk pengisian berulang
		
		for (int j = 1; j < 4; j++){
			cout << " isi matriks " << namaMatriks << i << j << ": "; cin >> *pointer;
			
			if (j == 3){
				cout << endl;}
			
			pointer++;}}}											//increment pada var pointer untuk menuju alamat berikutnya



void tampilkan_matriks(int array[3][3]){							//procedure menampilkan matriks
	pointer = &array[0][0];
	cout << endl;
	
	for (int i = 0; i < 3; i++){
		
		for (int j = 0; j < 3; j++){
			
			if (j == 0){
				cout << " |\t";}
				
			cout << *pointer << "\t";
			
			if (j == 2){
				cout << "|" << endl;}
				
			pointer++;}}}

			

void perbaikan_matriks(int matriks[3][3]){							//procedure meralat matriks
	system("cls");														//clrscr untuk menghapus isi layar (clearscreen)
	tampilkan_matriks(matriks);
	
	//Pemilihan nilai yang hendak diubah
	cout << " Perbaiki baris ke: "; cin >> barisDiperbaiki;
	cout << " Perbaiki kolom ke: "; cin >> kolomDiperbaiki;
	pointer = &matriks[barisDiperbaiki - 1][kolomDiperbaiki - 1];
	
	cout << " Perbaiki matriks" << barisDiperbaiki << kolomDiperbaiki;
	cout << " dengan: "; cin >> *pointer;
	
	tampilkan_matriks(matriks);}



void cek_matriks(int matriks[3][3]){								//procedure konfirmasi benar tidaknya matriks
	do{																//perulangan do-while untuk mengatasi salah inputan
	system("cls");
	tampilkan_matriks(matriks);
	
	cout << "\n Apakah matriks tersebut sudah benar? (y / n)" << endl;
	cout << " >> "; cin >> pilihanMenu;
		switch (pilihanMenu){										//Percabangan switch-case untuk yes/no
	
		case'y':
			berjalan = false;
			break;
			
		case'n':
			perbaikan_matriks(matriks);
			break;
			
		default:
			cout << "  <Menu yang kamu pilih tidak ada>\n";
			cout << " ==================================\n\n";
			cout << " -Lanjutkan-"; getch();						//getch untuk menunda kemunculan output berikutnya
			break;}}
	while(berjalan == true);
	berjalan = true;}
	


void kalikan_matriks(int matriksA[3][3],int matriksB[3][3], int matriksC[3][3]){
	pointer = &matriksC[0][0];
	for (int i = 0; i < 3; i++){
		
		for (int j = 0; j < 3; j++){
			
			for (int k = 0; k < 3; k++){
			*pointer += matriksA[i][k] * matriksB[k][j];}
			
		pointer++;}}}



int menu_perulangan(){												//Function untuk pengulangan
	responPengulangan = true;
	do{
		system("cls");
		cout << "\n\n\n\n\n Apakah ingin mengulang?\n [1] ya\t\t[2] tidak\n\n"; 
		cout << "\n Pilihanmu: " ;cin >> pilihanMenu;
		
		switch (pilihanMenu){
			
			case '1':
				responPengulangan = false;
				berjalan = true;
				break;
				
			case '2':
				system("cls");
				cout << "\n\n\n Terimakasih telah menggunakan program ini!\n";
				cout << " Lanjutkan>>"; cin.ignore(1, '\n'); cin.get();
				responPengulangan = false;
				berjalan = false;
				break;
				
			default:
				cout << " <Pilihan yang kamu pilih tidak ada>\n";
				cout << " ===================================\n";
				cout << " Lanjutkan>>"; getch();
				break;}
	}while (responPengulangan == true);
	return berjalan;}



int main(){
	do{																//Perulangan do-while untuk mengulangan program keseluruhan
	system("cls");
	cout << "\n Selamat datang di program perkalian matriks!" << endl;
	
	//Pengisian Matriks Pertama
	cout << "\n\n\n Silakan isi matriks pertama(a): " << endl;
	isi_matriks('a',matriksPertama);
	cek_matriks(matriksPertama);
	
	system("cls");
	
	//Pengisian Matriks Kedua
	cout << "\n\n\n Silakan isi matriks kedua(b): " << endl;
	isi_matriks('b',matriksKedua);
	cek_matriks(matriksKedua);
	
	//Perhitungan Perkalian
	kalikan_matriks(matriksPertama, matriksKedua, matriksHasil);
	system("cls");
	
		// Menampilkan Hasil Akhir
		cout << "\n\t Matriks Pertama" << endl;
		tampilkan_matriks(matriksPertama);
		cout << "\n\t\t x\n" << endl;
		cout << "\n\t Matriks Kedua" << endl;
		tampilkan_matriks(matriksKedua);
		cout << "\n\t\t =\n" << endl;
		tampilkan_matriks(matriksHasil);
		
		cout << "\n ===================================\n";
		cout << " Lanjutkan>>"; cin.ignore(1, '\n'); cin.get();;
		
	
	berjalan = menu_perulangan();
	
	}while(berjalan == true);
	return 0;
}
