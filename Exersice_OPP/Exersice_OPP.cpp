#include<iostream>
#include<vector>
using namespace std;

class penerbit;
class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) : nama(pNama) {
		cout << "Pengarang\"" << nama << "\"ada\n ";
	}
	~pengarang() {
		cout << "Pengarang\"" << nama << "\"tidak ada\n";
	}
	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
};
class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	penerbit(string pNama) : nama(pNama) {
		cout << "Penerbit\"" << nama << "\"ada\n ";
	}
	~penerbit() {
		cout << "Penerbit\"" << nama << "\"tidak ada\n ";
	}
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}
void penerbit::cetakPengarang() {
	cout << "\nDaftar penerbit pada pengarang\"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void pengarang::tambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
	pPenerbit->tambahPengarang(this);
}
void pengarang::cetakPenerbit() {
	cout << "\nDaftar pengarang pada penerbit\"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
int main() {
	pengarang* varPengarang1 = new pengarang("Gama Press");
	pengarang* varPengarang2 = new pengarang("Intan Pariwara");
	penerbit* varPenerbit1 = new penerbit("Joko");
	penerbit* varPenerbit2 = new penerbit("Lia");
	penerbit* varPenerbit3 = new penerbit("Giga");
	penerbit* varPenerbit4 = new penerbit("Asroni");

	varPengarang1->tambahPenerbit(varPenerbit1);
	varPengarang2->tambahPenerbit(varPenerbit1);
	varPengarang3->tambahPenerbit(varPenerbit1);
	varPengarang3->tambahPenerbit(varPenerbit2);
	

	varPengarang1->cetakPenerbit();
	varPengarang2->cetakPenerbit();
	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();
	varPenerbit3->cetakPengarang();
	varPenerbit4->cetakPengarang();

	delete varPenerbit1;
	delete varPenerbit2;
	delete varPengarang1;
	delete varPengarang2;
	delete varPengarang3;
	delete varPengarang4;

	return 0;
}


