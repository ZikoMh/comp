

#include <iostream>
#include <vector>
#include<fstream>

using namespace std;
inline const char* const BoolToString(bool b)
{
	return b ? "true" : "false";
}

class Transition{
public:
	int Eta_D;
	int Eta_A;
	char sym;
	Transition(int eD = 0, int eA = 0, char s = 'a') {
		Eta_A = eA;
		Eta_D = eD;
		sym = s;

	}
};
class Automate {
public:
	vector<char> alphabet;
	vector<int> etats;
	int etatI;
	vector<int> etatF;
	vector<Transition> trans;
	Automate(vector<char> a = {}, vector<int> et = {}, int eI = 0, vector<int> eF = {}, vector<Transition> t = {}) {
		alphabet = a;
		etats = et;
		etatI = eI;
		etatF = eF;
		trans = t;

	}
	void lecture() {
		int nbA, nbE, nbEf,nbT;
		cout << "entrer le nombre de l'aphabet: ";
		cin >> nbA;
		
		for (int i = 0; i < nbA; i++) {
			char n;
			cout << "entrer l'alphabet: ";
			cin >> n;
			alphabet.push_back(n);
		}
		cout << "entrer le nombre d'etats: ";
		cin >> nbE;
		
		for (int i = 0; i < nbE; i++) {
			int n;
			cout << "entrer l'etat: ";
			cin >> n;
			etats.push_back(n);
		}
		cout << "entrer l'etat initial";
		cin >> etatI;
		cout << "entrer le nombre d'etats finaux: ";
		cin >> nbEf;
		
		for (int i = 0; i < nbEf; i++) {
			int n;
			cout << "entrer l'etat final: ";
			cin >> n;
			etatF.push_back(n);
		}

		cout << "entrer le nombre de transition: ";
		cin >> nbT;

		for (int i = 0; i < nbT; i++) {
			
			int Eta_D;
			int Eta_A;
			char sym;
			cout << "       entrer l'etat de depart: ";
			cin >> Eta_D;
			cout << "       entrer l'etat d'arrive: ";
			cin >> Eta_A;
			cout << "       entrer le symbole: ";
			cin >> sym;
			Transition a(Eta_D, Eta_A, sym);
			trans.push_back(a);

		}

	}
	void afficher() {
		cout << "les alphabets: " << endl;
		for (int i = 0; i < alphabet.size(); i++) {
			cout << alphabet[i] << endl;
		}
		cout << "les etats: " << endl;
		for (int i = 0; i < etats.size(); i++) {
			cout << etats[i] << endl;
		}
		cout << "etat initial: " << etatI << endl;
		cout << "les etats finaux: " << endl;
		for (int i = 0; i < etatF.size(); i++) {
			cout << etatF[i] << endl;
		}
		cout << "les transitions: " << endl;
		for (int i = 0; i < trans.size(); i++) {
			cout << "etat de depart: "<<trans[i].Eta_D << endl;
			cout << "etat d'arrive: " << trans[i].Eta_A << endl;
			cout << "symbole:" << trans[i].sym << endl;
		}

		
	}
	int exixte_tran( int ed, char s) {
		for (Transition i : this->trans) {
			if (i.Eta_D == ed && i.sym == s) {
				return i.Eta_A;
			}
		}
		 return -1;
	}
	bool is_final(int e) {
		for (int i : this->etatF) {
			if (i == e) return true;
		}
		return false;
	}
	bool accepter(string mot) {
		int E = this->etatI, i = 0;
		while (mot[i] = !'0' && E != -1) {
			E = exixte_tran(E, mot[i]);
			i++;
		}
		if (E == -1) return false;
		if (is_final(E)) return true;
		else return false;
	}
};

int main()
{
	string filename;
	cout << "file name: ";
	int ligne = 50;
	
	getline(cin, filename);



	Automate A;
	A.lecture();
	A.afficher(); 
	bool r = A.accepter("abba"); 
	cout << "--------------------------" << endl;
	cout<< BoolToString(r);

}


