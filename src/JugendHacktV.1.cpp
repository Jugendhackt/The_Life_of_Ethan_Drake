#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>


using namespace std;

struct Situation{
	string id;
	string beschrieb;
	string frage;
	string next_id_ja;
	string next_id_nein;

};



int main() {
	cout << "Willkommen zu Life of Ethan" << endl;
	int w = 1;
	ifstream file;
	int y = 0;
	bool running = true;
	file.open("StroryEthan.txt");
	if(!file.is_open()){
		cout << "file could not be opened!";
		return 0;
	}

	vector<Situation> sit;

	string temp;
	while(getline(file,temp)){
		if(temp != "---"){
			break;
		}
		Situation item;
		getline(file,item.id);
		getline(file,item.beschrieb);
		getline(file,item.frage);
		getline(file,item.next_id_ja);
		getline(file,item.next_id_nein);
		sit.push_back (item);

	}
	//hier startet das richtige spiel
	string tempId = "1";
	while(running){

		for(int x=0; x< sit.size();x++){

		if(sit[x].id == tempId){
			string exitvalues = "9";
			if(exitvalues == sit[x].next_id_ja ){
				running = false;
			}
			if(exitvalues == sit[x].next_id_nein){
				running = false;
			}
			if(tempId == "5"){
				cout << endl << endl;
				sleep(w);
				cout << "Ende Kapitel I" << endl;
				sleep(w);
				cout << endl << endl;
			}
			if (tempId == "5.1.1.1"||tempId == "5.1.1.5"||tempId == "5.1.5.1"||tempId == "5.1.5.5"||tempId == "5.5.5.5"||tempId == "5.5.1.5"){
				cout << sit[x].beschrieb<< endl;
				sleep(w);
				cout << endl << endl;
				sleep(w);
				cout << endl << endl;
				sleep(w);
				cout << endl << endl;
				sleep(w);
				tempId =  "0"; //dort wo es weitergeht
				continue;
			}
			if(tempId =="5.5.5.1"){
				cout << "Chatverlauf:"<<endl;
				sleep(w);
				cout << "E: Ethan, F: Freund"<<endl;
				sleep(w);
				cout << "E: Ey ich verschwinde. Frau hat mit mir Schluss gemacht und fang jetzt ein neues Leben an."<<endl;
				sleep(w);
				cout << "F: Oh scheisse. Aber wir bleiben in Kontakt klar?"<<endl;
				sleep(w);
				cout << "E: Klar sicher. Noch letzte Worte?  "<<endl;
				sleep(w);
				cout << "F: das heisst also du siehst deine Tochter auch nicht? "<<endl;
				sleep(w);
				cout << "E: No shit Sherlock. Ehrlich du weisst wie meine Ex-Frau tickt." <<endl;
				sleep(w);
				cout << "F: Hmm…naja dann tschüss. Bis irgendwann dann mal."<<endl;
				sleep(w);
				cout << "Genervt verdrehst du deine Augen und fährst zum Bahnhof."<< endl;
				sleep(w);
				tempId =  "0";
				sleep(w);
				cout << endl << endl;

				sleep(w);
				cout << endl << endl;
				sleep(w);
				cout << endl << endl;
				sleep(w);
				continue;
			}
			if(tempId == "0"){
				cout << "*Egal wie schlecht es dir Geht"<<endl;
				sleep(w*2);
				cout << "irgendwann geht es wieder besser*" <<endl;
				sleep(w*2);
				cout << endl<<endl<<"ENDE"<< endl;
				return 0;
			}
			cout << "..." << endl;
			sleep(w);
			cout << "..." << endl;
			sleep(w);
			cout << "..." << endl;
			sleep(w);
			cout << sit[x].beschrieb << endl;
			sleep(w);
			cout << sit[x].frage << endl;
			sleep(w);
			cout << "für JA drücke J" << endl << "für NEIN drücke N" << endl;
			sleep(w);
			char temp;
			cin >> temp;
			if(temp == 'J' || temp == 'j'){
				tempId = sit[x].next_id_ja;
				sleep(w);
			}
			else if(temp == 'N' || temp == 'n'){
				tempId = sit[x].next_id_nein;
				sleep(w);
			}
			else{
				cout << "Du hast etwas falsches eingegeben" << endl;
				sleep(w);
				x=x - 1;
				y++;
				if(y > 4){
					cout << "Wat laberst du denn da?" << endl;
					sleep(w);
				}

			}

		}
	}

	}

	cout << "ende";


	return 0;
}
