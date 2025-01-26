#include <iostream>
#include <string>
using namespace std;

class Contact {
 	private:
 		string nama;
 		string tempat_tinggal;
 		string alamat;
 		string kekuatan;
 	
 	public:
 		Contact () : nama(""), tempat_tinggal(""), alamat(""), kekuatan(""){
		}
		 
		void setContact(const string& n, const string& t, const string& a, const string& k){
			nama = n;
			tempat_tinggal = t;
			alamat = a;
			kekuatan = k;
		}
        
        string getNama() const {return nama;}
		void displayContact() const{
			cout << "Nama: "<< nama << endl;
			cout << "Tempat Tinggal: "<< tempat_tinggal <<endl;
			cout << "Alamat: "<< alamat << endl;
			cout << "Kekuatan: "<< kekuatan << endl;
		}
		
		void editContact(const string& nama_baru, const string& tempat_tinggal_baru, const string& alamat_baru, const string& kekuatan_baru){
			nama = nama_baru;
			tempat_tinggal = tempat_tinggal_baru;
			alamat = alamat_baru;
			kekuatan = kekuatan_baru;
		}
};

class PhoneBook {
	private:
		Contact contacts[8];
		int ukuran;
		int indeks_selanjutnya;
	public:
		PhoneBook() : ukuran(0), indeks_selanjutnya(0) {
		}
		
		void addContact(const string& nama, const string& tempat_tinggal, const string& alamat, const string& kekuatan) {
			contacts[indeks_selanjutnya].setContact(nama, tempat_tinggal, alamat, kekuatan);
			indeks_selanjutnya = (indeks_selanjutnya + 1) % 8;
			if (ukuran < 8) ukuran++;
			cout << "Kontak sudah tersimpan.\n";
		}
		
		void searchContacts() const {
			if (ukuran == 0){
				cout << "Tidak ada kontak yang tersedia.\n";
				return;
			}
			
			cout << "List Kontak:\n";
			for (int i=0; i < ukuran; i++){
				cout << i + 1 << ". " << contacts[i].getNama() << endl;
			}
			
			cout << "Masukkan nomor kontak untuk melihat lebih rinci: ";
			int pilih;
			cin >> pilih;
			
			if (pilih > 0 && pilih <= ukuran){
				contacts[pilih - 1].displayContact();
			}
			else{
				cout << "Pilihan tidak sesuai.\n";
			}
		}
		
	void editContact(){
		if (ukuran == 0){
			cout << "Tidak ada kontak yang bisa diedit.\n";
			return;
		}
		
		cout << "List Kontak:\n";
		for (int i = 0; i < ukuran; i++){
			cout << i + 1 << ". " << contacts[i].getNama() <<endl;
		}
		
		cout << "Masukkan nomor kontak untuk melihat lebih rinci: ";
			int pilih;
			cin >> pilih;
		
		if (pilih > 0 && pilih <= ukuran){
			string nama_baru, tempat_tinggal_baru, alamat_baru, kekuatan_baru;
			cout << "Masukkan nama baru: ";
			cin.ignore();
		    getline(cin, nama_baru);
		    cout << "Masukkan tempat tinggal baru: ";
		    getline(cin, tempat_tinggal_baru);
		    cout << "Masukkan alamat baru: ";
		    getline(cin, alamat_baru);
		    cout << "Masukkan kekuatan baru: ";
		    getline(cin, kekuatan_baru);
		    
		    contacts[pilih-1].editContact(nama_baru, tempat_tinggal_baru, alamat_baru, kekuatan_baru);
		    cout << "Kontak telah diperbarui.\n";
		}
		else{
			cout << "Pilihan tidak sesuai.\n";
		}
	}
	
	void deleteContact(){
		if (ukuran == 0){
			cout << "Tidak ada kontak yang bisa dihapus.\n";
			return;
		}
		
		cout << "List Kontak:\n";
		for (int i = 0; i < ukuran; i++){
			cout << i+1 << ". "<< contacts[i].getNama() << endl;
		}
		
		cout << "Masukkan nomor kontak yang ingin dihapus: ";
		int pilih;
		cin >> pilih;
		
		if (pilih >0 && pilih <= ukuran){
			for (int i = pilih - 1; i < ukuran - 1; i++){
				contacts[i] = contacts[i+1];
			}
			ukuran--;
			indeks_selanjutnya = ukuran%8;
			cout << "Kontak berhasil dihapus.\n";
		} else{
			cout << "Pilihan tidak sesuai.\n";
		}
   	}
};

int main(){
	PhoneBook phoneBook;
	string nama, tempat_tinggal, alamat, kekuatan;
	int pilih;
	
	do{
		cout << "-------------- Buku Kontak Pak Bell ----------------";
		cout << "\n|                    Opsi:                         |\n";
		cout << "|             1. Tambahkan Kontak                  |\n";
		cout << "|             2. Cari Kontak                       |\n";
		cout << "|             3. Edit Kontak                       |\n";
		cout << "|             4. Hapus Kontak                      |\n";
		cout << "|             5. Keluar                            |\n";
		cout << "----------------------------------------------------\n";
		cout << " \n";
		cout << "Pilih opsi:";
		cin >> pilih;
		
		switch (pilih) {
			case 1:
				cout << "Masukkan nama: ";
				cin.ignore();
				getline(cin, nama);
		    	cout << "Masukkan tempat tinggal: ";
		    	getline(cin, tempat_tinggal);
		    	cout << "Masukkan alamat: ";
		    	getline(cin, alamat);
		    	cout << "Masukkan kekuatan (Pyro, Hydro, Cyro, Anemo, Dendro, Geo, Hydro, Electro, Havoc, Spectro): ";
		    	getline(cin, kekuatan);
		    	phoneBook.addContact(nama, tempat_tinggal, alamat, kekuatan);
		    	break;
		    case 2:
		    	phoneBook.searchContacts();
		    	break;
		    case 3:
		    	phoneBook.editContact();
		    	break;
		    case 4:
		    	phoneBook.deleteContact();
		    case 5:
		    	cout << "Keluar dari program...\n";
		    	break;
		    default:
		    	cout << "Pilihan tidak sesuai. Coba lagi.\n";
		}
	}
	
	while (pilih !=5);
	return 0;
}
