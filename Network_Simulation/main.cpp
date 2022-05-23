#include "Header.h"
#include"Dijkstra.h"
#include "splay.h"
#include "splayC.h"


using namespace std;

#define sizeG 20

Graph<int> G1(20);
Routers<string>* R1 = new Routers<string>[5];
SplayRouters<string>* S1 = new SplayRouters<string>[5];

void Display() {

	cout << "\n\n";
	cout << "\t ********************************************************************************************************** \t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                  :     :     : :::::::  ::     ::::::::  ::::::::    :    :    :::::::                  *\t" << endl;
	Sleep(125);
	cout << "\t*                   :   : :   :  :::::::  ::     ::        ::    ::   : :  : :   :::::::                  *\t" << endl;
	Sleep(125);
	cout << "\t*                    : :   : :   :::::::  ::     ::        ::    ::  :   ::   :  :::::::                  *\t" << endl;
	Sleep(125);
	cout << "\t*                     :     :    :::::::  :::::: ::::::::  :::::::: :          : :::::::                  *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                        TO THE NETWROK EMULATOR                                          *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                  DATA STRUCTURES (CS-2001) PROJECT                                      *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                                BY:-                                                     *\t" << endl;
	Sleep(125);
	cout << "\t*                                     USMAN ALI BOKHARI - 20I-0794                                        *\t" << endl;
	Sleep(125);
	cout << "\t*                                     SHERWAN QADIR -     20I-0689                                        *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t*                                                                                                         *\t" << endl;
	Sleep(125);
	cout << "\t ********************************************************************************************************** \t" << endl;


	for (int i = 0; i < 30; i++) {
		cout << "\n";
		Sleep(125);
	}
}

void help() {

}

void Command_line(string input, Routers<string>* R) {


	bool s = false;
	char char1;
	string ins;

	while (s == false)
	{

		if (input.substr(0, 4) == "send" && input.substr(5, input.length()) == "message") { 
			int in;
			cout << "Do you want to use \n1. Lists\n2. Slay tree\n to send message." << endl;
			cin >> in;
			if (in == 1) {
				cout << "Enter MessageID: ";
				string id;
				cin >> id;
				string i;
				int x = stoi(id);
				cout << "Enter pirority: ";
				cin >> i;
				int pri = stoi(i);
				cout << "Enter Source Address: ";
				string SA;
				cin >> SA;
				cout << "Enter Dest Address: ";
				string DA;
				cin >> DA;
				cout << "Send Message: ";
				cin.ignore(10000, '\n');
				string MSG;
				getline(cin, MSG);
				Message M(x, pri, SA, DA, MSG, "");
				R->recieveMSG(&M, R);
				cout << "Trace: " << M.Trace << endl;
			}
			else {
				cout << "Enter MessageID: ";
				string id;
				cin >> id;
				string i;
				int x = stoi(id);
				cout << "Enter pirority: ";
				cin >> i;
				int pri = stoi(i);
				cout << "Enter Source Address: ";
				string SA;
				cin >> SA;
				cout << "Enter Dest Address: ";
				string DA;
				cin >> DA;
				cout << "Send Message: ";
				cin.ignore(10000, '\n');
				string MSG;
				getline(cin, MSG);
				Message M(x, pri, SA, DA, MSG, "");
				S1->recieveMSG(&M, S1);
				cout << "Trace: " << M.Trace << endl;
			}
		}
		
	}
}

void createR(int numRouters, Routers<string>* R,int** arr,int***D) {
	//cout << "I start" << endl;
	int z = 0;
		for (int i = 15; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (arr[i][j] != 0) {
					z++;
				}
			}
		}
		string* names = new string[z];
		z = 0;

		for (int i = 15; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (arr[i][j] != 0) {
					names[z] = getStr(j);
					//cout <<"Name: " << getStr(j) << endl;
					z++;
				}
			}
		}
		/*cout << endl;
		cout << endl;
		cout << endl;*/
		for (int i = 0; i < numRouters; i++) {
			//cout << "Name: " << getStr(i + 15) << endl;
			R[i].create(z, names, getStr(i + 15));
		}

		for (int i = 0; i < 5; i++) {
			R[i].generateRT(D);
		}
}
void createR(int numRouters, SplayRouters<string>* R,int** arr,int***D) {
	//cout << "I start" << endl;
	int z = 0;
		for (int i = 15; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (arr[i][j] != 0) {
					z++;
				}
			}
		}
		string* names = new string[z];
		z = 0;

		for (int i = 15; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (arr[i][j] != 0) {
					names[z] = getStr(j);
					//cout <<"Name: " << getStr(j) << endl;
					z++;
				}
			}
		}
		/*cout << endl;
		cout << endl;
		cout << endl;*/
		for (int i = 0; i < numRouters; i++) {
			//cout << "Name: " << getStr(i + 15) << endl;
			R[i].create(z, names, getStr(i + 15));
		}

		for (int i = 0; i < 5; i++) {
			R[i].generateRT(D);
		}
}

void createG(Graph<int>* G) {
	string* csv = G->CSVFile(G);
	int rid = 3;
	for (int i = 1; i < 21; i++) {
		if (i > 9) {
			rid = 4;
		}
		if (i > 15)
			rid = 3;
		csv[i] = csv[i].substr(rid, csv[i].length());
	}

	/*for (int i = 1; i < 21; i++) {
		cout << csv[i] << endl;
	}*/
	int p = 0;

	for (int i = 1; i < 21; i++) {
		for (int j = 0; j < csv[i].length(); j++) {
			if (csv[i][j] == '?')
				p++;
			if (csv[i][j] != ',' && csv[i][j] != '?') {
				G->insert(i - 1, p, csv[i][j]);
				p++;
			}
		}
		p = 0;
	}
}

int*** RunDstra(Graph<int> G) {

	int*** arr = new int** [sizeG];
	for (int i = 0; i < sizeG; i++) {
		arr[i] = new int* [sizeG];
	}
	for (int i = 0; i < sizeG; i++) {
		for (int j = 0; j < sizeG; j++)
			arr[i][j] = new int[sizeG];
	}

	//dijkstra(G.AdjArr, 0);
	for (int p = 0; p < sizeG; p++) {
		for (int i = 0; i < sizeG; i++) {
			for (int j = 0; j < sizeG; j++)
				arr[p][i][j] = -1;
		}
	}
	//createG(&G);
	//G.BFS(20);
	//G.DispArr();
	for (int i = 0; i < 21; i++) {
		dijkstra(G.AdjArr, i, arr, sizeG);
	}

	/*cout << endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++)
			if(arr[15][i][j]!=-1)
			cout << arr[15][i][j] << " ";
		cout << endl;
	}*/

	return arr;
}




int main() {
	
	//dijkstra
	createG(&G1);
	//G.BFS(20);
	//G.DispArr();
	G1.arr = RunDstra(G1);

	//G.DispArr();
	Message M(1,5,"M1", "M6", "Hello sir","");
	Message L(2,10,"M2",  "R2", "Hello sir1","");
	Message P(3,7,"M3", "R2", "Hello sir2","");
	Message O(4,4,"M4", "R2", "Hello sir3","");

	MaxHeap<Message>* Q=new MaxHeap<Message>;

	Q->insert(M);
	Q->insert(L);
	Q->insert(P);
	Q->insert(O);
	//Q.display();
	createR(5, R1, G1.AdjArr, G1.arr);
	createR(5, S1, G1.AdjArr, G1.arr);
	
	Display();
	//R->setPq(Q);
	string command;
	cout << "NETWROK>>";
	getline(cin,command);
	Command_line(command,R1);
	//R->sendMsg(R);



	//implement routers and msgs.
}