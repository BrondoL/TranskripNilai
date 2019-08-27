#include <iostream>
#include <cstring>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

struct siakad{
	char nama[100], fak[100], prog[100], jur[100], dos[100], huruf[100][2], mat[100][100], thn[100], smt[3], pass[100], kode[100][10];
	int npm, sks, ambl[100], kre[100], nil[100];
	double ip;
};

class metod{
public:
	siakad data;
	void NPM();
	void tahun();
	void semester();
	void password();
	void name();
	void fakultas();
	void prodi();
	void jurusan();
	void dosen();
	void code(int &);
	void matkul(int &);
	void Ambil(int &);
	void kredit(int &);
	void Nilai(int &);
	void IP(int &);
	void SKS(int &);
	void HM(int &);

};

	void metod::name(){
		cout << "Siapa Nama Anda                             : ";
		cin.getline(data.nama, sizeof(data.nama));
	}

	void metod::fakultas(){
		cout << "Dari Fakultas Mana Anda                     : ";
		cin.getline(data.fak, sizeof(data.fak));
	}

	void metod::prodi(){
		cout << "Dari Program Studi Mana Anda                : ";
		cin.getline(data.prog, sizeof(data.prog));
	}

	void metod::jurusan(){
		cout << "Dari Jurusan Mana Anda                      : ";
		cin.getline(data.jur, sizeof(data.jur));
	}

	void metod::dosen(){
		cout << "Siapa Dosen Pembimbing Anda                 : ";
		cin.getline(data.dos, sizeof(data.dos));
	}

	void metod::tahun(){
		cout << "TH Akademik  :   contoh: 2018/2019          : ";
		cin.getline(data.thn, sizeof(data.thn));
	}

	void metod::NPM(){
		cin >> data.npm;
	}

	void metod::semester(){
		cout << "Semester     :   (P = Semester Pendek)      : ";
		cin.getline(data.smt, sizeof(data.smt));
	}

	void metod::password(){
		cout << "Password KRS :   (Konsultasi Pada Dosen PA) : ";
		cin.getline(data.pass, sizeof(data.pass));
	}

	void metod::Ambil(int &b){
		cout << "Pengambilan ke Berapa                       : ";
		cin >> data.ambl[b];
	}

	void metod::Nilai(int &b){
		do{
			cout << "Berapa Nilai untuk Mata Kuliah ini          : ";
			cin >> data.nil[b];
			if(data.nil[b] < 0 || data.nil[b] > 100)
				cout << "Input Salah, Ulangi Lagi !";
		}while(data.nil[b] < 0 || data.nil[b] > 100);
	}

	void metod::kredit(int &b){
		cout << "Berapa SKS untuk Mata Kuliah ini            : ";
		cin >> data.kre[b];
	}

	void metod::code(int &b){
		cout << "Apa Kode dari Mata Kuliah Tersebut          : ";
		cin.getline(data.kode[b], sizeof(data.kode));

	}

	void metod::matkul(int &b){
		cout << "Apa Nama Mata Kuliah anda                   : ";
		cin.getline(data.mat[b], sizeof(data.mat));
	}

	void metod::IP(int &b){
		double nilai = 0;;
		for(int i=0; i<b; i++){
			if (strncmp (data.huruf[i],"A",2) == 0) {
	           nilai += 4 * data.kre[i];
	         }
	          else if (strncmp (data.huruf[i],"B+",2) == 0) {
	           nilai += 3.5 * data.kre[i];
	         }
	         else if (strncmp (data.huruf[i],"B",2) == 0) {
	           nilai += 3 * data.kre[i];
	         }
	          else if (strncmp (data.huruf[i],"C+",2) == 0) {
	           nilai += 2.5 * data.kre[i];
	         }
	         else if (strncmp (data.huruf[i],"C",2) == 0) {
	           nilai += 2 * data.kre[i];
	         }
	         else if (strncmp (data.huruf[i],"D",2) == 0) {
	           nilai += 1 * data.kre[i];
	         }
	         else if (strncmp (data.huruf[i],"E",2) == 0) {
	           nilai += 0 * data.kre[i];
	         }
	    }
	    data.ip = nilai/data.sks;
	}

	void metod::SKS(int &b){
		int jumlah = 0, i;
		for(i=0; i<b; i++){
			jumlah += data.kre[i];
		}
		data.sks = jumlah;
	}

	void metod::HM(int &b){
			if ((data.nil[b] >= 76) && (data.nil[b] <= 100))
			{
				strcpy(data.huruf[b], "A");
			}
			else if ((data.nil[b] >= 71) && (data.nil[b] < 76))
			{
				strcpy(data.huruf[b], "B+");
			}
			else if ((data.nil[b] >= 66) && (data.nil[b] < 71))
			{
				strcpy(data.huruf[b], "B");
			}
			else if ((data.nil[b] >= 61) && (data.nil[b] < 66))
			{
				strcpy(data.huruf[b], "C+");
			}
			else if ((data.nil[b] >= 56) && (data.nil[b] < 61))
			{
				strcpy(data.huruf[b], "C");
			}
			else if ((data.nil[b] >= 51) && (data.nil[b] < 56))
			{
				strcpy(data.huruf[b], "D");			}
			else if ((data.nil[b] >= 0) && (data.nil[b] < 51))
			{
				strcpy(data.huruf[b], "E");
			}else
				cout << "salah";
	}

void login(int &);
void loading();
void menu();
void display(int &, int &);
void print(int &, int &);

metod mahasiswa[100];

int main(){
	int z = 0;
	int x = 0;
	bool log;
	int pil, user = 0;
	login(user);
	// loading();
	log = true;

	do{
		menu();
		cin >> pil; cin.ignore();
		switch(pil){
			case 1:
					if(log == true){
						system("cls");
						cout << "================= FORMULIR PENGISIAN KRS =================" << endl << endl;
						mahasiswa[user].tahun();
						mahasiswa[user].semester();
						mahasiswa[user].password();
						mahasiswa[user].name();
						mahasiswa[user].fakultas();
						mahasiswa[user].prodi();
						mahasiswa[user].jurusan();
						mahasiswa[user].dosen();
						cout << "Ada Berapa Matkul di Semester Ini           : "; cin >> x;
						cout << endl;
						for(int i=0; i<x; i++){
							cin.ignore();
							cout << i+1 << " ";
							cout << "\t";mahasiswa[user].matkul(i);
							cout << "\t";mahasiswa[user].code(i);
							cout << "\t";mahasiswa[user].kredit(i);
							cout << "\t";mahasiswa[user].Nilai(i);
							cout << "\t";mahasiswa[user].Ambil(i);
							mahasiswa[user].HM(i);
							cout << endl;
						}
						mahasiswa[user].SKS(x);
						mahasiswa[user].IP(x);
						cin.ignore();
						cout << "\n\t==========================";
						cout << "\n\t   Input Data Berhasil";
						log = false;
						user++;
						cin.get();
					}else{
						system("cls");
						cout << "  Anda Harus Logout Terlebih Dahulu \n\t\tatau \n\t  Pilih Menu Edit KRS " << endl;
						cin.get();
					}
					break;
			case 2:
					if (log == false){
						system("cls");
						cout << "================= EDIT KRS =================" << endl << endl;
						mahasiswa[user-1].tahun();
						mahasiswa[user-1].semester();
						mahasiswa[user-1].password();
						mahasiswa[user-1].name();
						mahasiswa[user-1].fakultas();
						mahasiswa[user-1].prodi();
						mahasiswa[user-1].jurusan();
						mahasiswa[user-1].dosen();
						cout << "Ada Berapa Matkul di Semester Ini           : "; cin >> x;
						cout << endl;
						for(int i=0; i<x; i++){
							cin.ignore();
							cout << i+1 << " ";
							cout << "\t";mahasiswa[user-1].matkul(i);
							cout << "\t";mahasiswa[user-1].code(i);
							cout << "\t";mahasiswa[user-1].kredit(i);
							cout << "\t";mahasiswa[user-1].Nilai(i);
							cout << "\t";mahasiswa[user-1].Ambil(i);
							mahasiswa[user-1].HM(i);
							cout << endl;
						}
						mahasiswa[user-1].SKS(x);
						mahasiswa[user-1].IP(x);
						cin.ignore();
						cout << "\n\t==========================";
						cout << "\n\t   Input Data Berhasil";
						cin.get();
					}else{
						system("cls");
						cout << "Anda Belum Mengisi KRS Anda, Silahkan Pilih Menu 1 Dahulu !";
						cin.get();
					}
					break;
			case 3:
					system("cls");
					if(user==0){
						cout << "Belum Ada Data yang Diinputkan";
					}else{
						cout << "Data Yang Sudah Terinput : " << endl << endl;
						for(int i=0; i<user; i++){
							cout << i+1 << ". "<< mahasiswa[i].data.nama << endl;
						}
						cout << "\n\nSilahkan pilih lagi : "; cin >> z;
						display(z, x);
						cin.ignore();
					}
					cin.get();
					break;
			case 4:
					system("cls");
					if(user==0){
						cout << "Belum Ada Data yang Diinputkan";
					}else{
						cout << "Data Yang Sudah Terinput : " << endl << endl;
						for(int i=0; i<user; i++){
							cout << i+1 << ". "<< mahasiswa[i].data.nama << endl;
						}
						cout << "\n\nSilahkan pilih lagi : "; cin >> z;
						print(z, x);
						cin.ignore();
					}
					cin.get();
					break;
			case 5:
					system("cls");
					cout << "Anda Akan Logout dari Aplikasi... " << endl; cin.get();
					system("cls");
					login(user);
					//loading();
					log = true;
					break;
			case 6:
					break;
			default:
					system("cls");
					cout <<"\t\nPilihan tidak ada";
					cin.get();
					break;
		}
		system("cls");
	}while (pil != 6);
	cout << "Exit...";


	cin.get();
	return 0;
}

void menu(){
	cout << "\t\t" << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << endl;
	cout << "\t\t" << (char)186 << " \tHOME-MHS "<< "\t  " << (char)186 << endl;
	cout << "\t\t" << (char)186 << "\t\t          " << (char)186 << endl;
	cout << "\t\t" << (char)186 << " 1. Isi KRS Baru \t  "<< (char)186 << endl;
	cout << "\t\t" << (char)186 << " 2. Edit KRS  \t\t  "<< (char)186 << endl;
	cout << "\t\t" << (char)186 << " 3. Lihat Transkrip      "<< (char)186 << endl;
	cout << "\t\t" << (char)186 << " 4. Print Transkrip      "<< (char)186 << endl;
	cout << "\t\t" << (char)186 << " 5. Logout \t\t  "<< (char)186 << endl;
	cout << "\t\t" << (char)186 << " 6. Exit \t\t  "<< (char)186 << endl;
	cout << "\t\t" << (char)186 << "\t\t          " << (char)186 << endl;
	cout << "\t\t" << (char)186 << " Pilihan : \t\t  " << (char)186 << endl;
	cout << "\t\t" << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << endl;
	cout << "\t\t"<<(char)62<<(char)62<<" ";
}

void login(int &user){
  	int i = 0;
	string passwd;
	cout << "====================================";
	cout << "\n\n           LOGIN APLIKASI        "<<endl;
	cout << "\n===================================="<<endl<<endl;
   	do {
    	cout << "Username   : "; mahasiswa[user].NPM(); cin.ignore();
		cout << "\nPassword   : "; getline(cin, passwd);

 		if (passwd == "admin") {
         	cout << "\n--------------------\n";
          	cout << "Anda Berhasil Login" << endl;
         	cout << "--------------------\n\n";
         	break;
      	}else {
          	cout << "\n------------------------\n";
         	cout << "Maaf mahasiswa & PASSWORD Salah!" << endl;
         	cout << "-------------------------\n\n";
        	i = i + 1;
     	}
 	  }while (i < 3);
 	 if(i == 3){
 	 	system("cls");
   		cout << "Anda Telah 3x Memasukan mahasiswa & PASSWORD Yang Salah\n";
   		cout << "Mohon Maaf Akun Anda Kami Blokir, Terima Kasih..";
   		exit(0);

   	 }
   	cin.get();
   	system("cls");
}

void loading(){
	system("cls");
	system("color 0a");
 	cout<<"\n\n\n\t\t    LOADING...\n\n";
 	char a=177, b=219;
 	cout<<"\t\t";
 	for (int i=0;i<=15;i++){
 	cout<<a;
	}
 	cout<<"\r";
 	cout<<"\t\t";
 	for (int i=0;i<=15;i++){
 		cout<<b;
  		Sleep(300);
 	}
 	system("cls");
 	system("color 07");
}

void display(int &user, int &b){
	string tmp = " ";
	cout << "\n\tKementerian Riset, Teknologi dan Pendidikan Tinggi Republik Indonesia" << endl;
	cout << setw(50) << "UNIVERSITAS LAMPUNG" << endl;
	cout << "  "; for(int i=0; i<76; i++) cout << (char)205; cout << endl;
	cout << setw(50) << "TRANSKRIP AKADEMIK" << endl << endl;
	cout << "NAMA \t\t: " << left << setw(15) << mahasiswa[user-1].data.nama << "\t\tFakultas \t: " << mahasiswa[user-1].data.fak << endl;
	cout << "NIM/NPM \t: " << left << setw(15) << mahasiswa[user-1].data.npm << "\t\tJurusan \t: " << mahasiswa[user-1].data.jur << endl;
	cout << "Pemb. Akad \t: " << left << setw(15) << mahasiswa[user-1].data.dos << "\t\tProg. Studi \t: " << mahasiswa[user-1].data.prog << endl;
	cout << "Semester \t: " << left << setw(15) << mahasiswa[user-1].data.smt << "\t\tTH Ajaran \t: " << mahasiswa[user-1].data.thn << endl;

	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << "No.   Kode\t   Mata Kuliah\t\t\tKredit \tPenngamb. ke \t HM" << endl;
	cout << "\n--------------------------------------------------------------------------------" << endl;
	for(int i=0; i<b; i++){
		cout << i+1 << "     " << left << setw(8) << mahasiswa[user-1].data.kode[i] << "\t   " << left << setw(20) << mahasiswa[user-1].data.mat[i] << "\t\t   " << left << setw(3) << mahasiswa[user-1].data.kre[i] << "\t      " << left << setw(3) << mahasiswa[user-1].data.ambl[i] << "\t  " << left << setw(3) << mahasiswa[user-1].data.huruf[i] << endl;
	}
	cout << "\n--------------------------------------------------------------------------------" << endl;
	cout << right << setw(51) << "Total Kredit : " << mahasiswa[user-1].data.sks << "\t Index Prestasi : " << mahasiswa[user-1].data.ip << endl;
	cout << "\n--------------------------------------------------------------------------------" << endl;
}

void print(int &user, int &b){
	ofstream myfile;

	myfile.open("Transkrip.txt");
   	if(!myfile.fail())
   	{
	    string tmp = " ";
		myfile << "\n\tKementerian Riset, Teknologi dan Pendidikan Tinggi Republik Indonesia" << endl;
		myfile << setw(50) << "UNIVERSITAS LAMPUNG" << endl;
		myfile << "  "; for(int i=0; i<75; i++) myfile << (char)205; myfile << endl;
		myfile << setw(50) << "TRANSKRIP AKADEMIK" << endl << endl;
		myfile << "NAMA \t\t: " << left << setw(15) << mahasiswa[user-1].data.nama << "\t\tFakultas \t: " << mahasiswa[user-1].data.fak << endl;
		myfile << "NIM/NPM \t: " << left << setw(15) << mahasiswa[user-1].data.npm << "\t\tJurusan \t: " << mahasiswa[user-1].data.jur << endl;
		myfile << "Pemb. Akad \t: " << left << setw(15) << mahasiswa[user-1].data.dos << "\t\tProg. Studi \t: " << mahasiswa[user-1].data.prog << endl;
		myfile << "Semester \t: " << left << setw(15) << mahasiswa[user-1].data.smt << "\t\tTH Ajaran \t: " << mahasiswa[user-1].data.thn << endl;

		myfile << "\n--------------------------------------------------------------------------------" << endl;
		myfile << "No.   Kode\t   Mata Kuliah\t\t\tKredit \tPenngamb. ke \t HM" << endl;
		myfile << "\n--------------------------------------------------------------------------------" << endl;
		for(int i=0; i<b; i++){
			myfile << i+1 << "     " << left << setw(8) << mahasiswa[user-1].data.kode[i] << "\t   " << left << setw(20) << mahasiswa[user-1].data.mat[i] << "\t\t   " << left << setw(3) << mahasiswa[user-1].data.kre[i] << "\t      " << left << setw(3) << mahasiswa[user-1].data.ambl[i] << "\t  " << left << setw(3) << mahasiswa[user-1].data.huruf[i] << endl;
		}
		myfile << "\n--------------------------------------------------------------------------------" << endl;
		myfile << setw(51) << "Total Kredit : " << mahasiswa[user-1].data.sks << "\t Index Prestasi : " << mahasiswa[user-1].data.ip << endl;
		myfile << "\n--------------------------------------------------------------------------------" << endl;
	    myfile.close();
	    system("cls");
	    cout<<"Print File Berhasil ! :)"<<endl;
    }else{
        cout<<"File tidak ditemukan"<<endl;
    }
}
