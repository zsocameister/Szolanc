#include <iostream>
#include <string>
#include <vector>
/* MINDEN EGYÉB FONTOSABBNAK TŰNŐ SZART IDE PAKOLTAM
		word.substr(word.length() - 2, word.length() - 1);
		szo1[0](elso kari)    szo2[szo2.length() - 1](uccso kari)
		*/

using namespace std;
/*
Csekkoló funkció. Működése: előző szó uccsó karakter(ek) - aktuális szó első karakter(ek) egyezésének csekkolása
Ha duplamássalhangzóra végződött az előző szó akkor aszerint ellenőrzi aktuális szót, első két karinek kell stimmelnie
Ha üres a vektor(első szó beírása) akkor nem ellenőriz utolsó szó alapján(duh), csak ékezetet, kis/nagy betűt
Igaz értéket dob vissza ha valami gebaszt talált
5 bemeneti paramétere van: aktuális szó, előző szó, előző szó uccsó két karaktere egy string-ként, 
eddig beírt szavak vektora, 8db duplamássalhangzó egy vektor formájában
*/
bool check(string word, string lastWord, string last2, vector <string> szavak, vector <string> duplamassalh) {
	if (szavak.empty());
	else if (find(duplamassalh.begin(), duplamassalh.end(), last2) != duplamassalh.end()) {
		if (word.substr(0, 2) != last2) {
			cout << "Rossz karakterrekkel kezdted a beírt szót!\nElőző beírt szó: " << lastWord << "\n\n";
			return true;
		}
	}
	else{
		if (word[0] != lastWord[lastWord.length() - 1]) {
			cout << "Rossz karakterrel kezdted a beírt szót!\nElőző beírt szó: " << lastWord << "\n\n";
			return true;
		}
	}
	for (int i = 0; i < word.length(); i++) {
		if (isupper(word[i]) || not isprint(word[i])) {
			cout << "Nem megfelelő a beírt szó!(tartalmaz nagy vagy ékezetes betűket)\nElőző beírt szó: " << lastWord << "\n\n";
			return true;
		}
	}
	return false;
}
//Szabályok kiírása funkció
void szabalyok() {
	cout << "Szólánc játék. Szabályok:\n\
-Csak kisbetűket szabad beírni\n\
-Ékezeteket sajnos nem lehet használni :/\n\
-Ha egy szó második alkalommal kerül beírásra akkor biza game over van\n\
-Lehet próbálkozni, de nagyon elit ellenőrző rendszer van kiépítve, hogy ne lehessen megszegni a fenti \"szabályokat\"" << endl << endl;
	return;
}

int main() {
	setlocale(LC_ALL, "hun");
	string word, lastWord, last2;
	vector <string> duplamassalh = { "sz", "zs" , "ty", "cs", "dz", "gy", "ly", "ny"};
	vector <string> szavak;
	szabalyok();

	do {
		cout << "Írd be az első szót: ";
		cin >> word;
	} while (check(word, word, word, szavak, duplamassalh));

	// Fő ciklus, addig megy amíg a 'szavak' vectorban nincs kétszer ugyanaz a szó
	do { 
		szavak.push_back(word); //beírt szó mentése vektorba
		lastWord = word; //Előző körben használt szó elmentése összehasonlításhoz
		system("cls");

		last2 = lastWord.substr(lastWord.length() - 2, lastWord.length() - 1); //előző szó uccso két karija
		do {
			if (find(duplamassalh.begin(), duplamassalh.end(), last2) != duplamassalh.end()) {
				cout << "Írd be a következő szót(" << last2 << "): ";
			}
			else{
				cout << "Írd be a következő szót(" << lastWord.back() << "): ";
			}
				cin >> word;
			} while (check(word, lastWord, last2, szavak, duplamassalh));

		} while (find(szavak.begin(), szavak.end(), word) == szavak.end());
	system("cls");
	cout << "Ez a szó már volt(" << word << ")\nGAME OVER VAN DIKK\n\n";
	system("pause");
	return 0;
}