#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <sstream>
//#include  <bits/stdc++.h>
#include <Bits.h>
#include <fstream>

using namespace std;


int getInt(string x) {
	int ret = -1;
	if (x[0] == 'M') {
		int size = x.length();
		string conv = "";
		for (int i = 0; i < size; i++) {
			conv += x[i];
		}
		stringstream str;
		str << conv;
		str >> ret;
	}
	else if (x[0] == 'R') {
		int size = x.length();
		string conv = "";
		for (int i = 0; i < size; i++) {
			conv += x[i];
		}
		stringstream str;
		str << conv;
		str >> ret;
		ret += 15;
	}
	return ret;
}

string getStr(int x) {
	string ret = "";
	if (x<15) {
		string conv = "M";
		string p = "";
		p = to_string(x+1);
		conv += p;
		ret = conv;
	}
	else if (x >= 15) {
		string conv = "R";
		string p = "";
		p = to_string(x-14);
		conv += p;
		ret = conv;
	}
	return ret;
}

template<class T>
struct LNode {
	T data;
	LNode<T>* next;

	LNode() {
		next = NULL;
	}
	LNode(T ins) {
		data = ins;
		next = NULL;
	}
};

template<class T>
struct list {
	LNode<T>* head;

	list() {
		head = NULL;
	}

	void insert(LNode<T>* ins) {
		if (head == NULL) {
			head = ins;
		}
		else {
			LNode<T>* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = ins;
		}
	}

	int getindex(string check) {
		int i = 0;
		LNode<T>* temp = head;
		while (temp->data != check) {
			temp = temp->next;
			i++;
		}
		return i;
	}

	string GetName(int x) {
		int i = 0;
		LNode<T>* temp = head;
		while (i != x) {
			temp = temp->next;
			i++;
		}
		return temp->data;
	}
};



struct Message {
	int MsgId;
	int priority;
	string sourceAdd;
	string DestAdd;
	string Payload;//the msg itself
	string Trace;

	Message() {
		MsgId = -1;
		priority = -1;
		sourceAdd = "";
		DestAdd = "";
		Payload = "";
		Trace = "";
	}

	Message(int Mid, int pri, string sA, string dA, string Pl, string Tr) {
		MsgId = Mid;
		priority = pri;
		sourceAdd = sA;
		DestAdd = dA;
		Payload = Pl;
		Trace = Tr;
	}

	bool operator > (Message M) {
		if (this->priority > M.priority) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator >= (Message M) {
		if (this->priority >= M.priority) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator <= (Message M) {
		if (this->priority <= M.priority) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator < (Message M) {
		if (this->priority < M.priority) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator==(Message M) {
		if (this->priority == M.priority) {
			return true;
		}
		else {
			return false;
		}
	}

	friend ostream& operator<<(ostream& os, const Message& dt);
};

ostream& operator<<(ostream& os, const Message& dt) {
	os << dt.MsgId;
	return os;
}

template<class T>
struct Qnode {
	T routerName;
	Qnode<T>* next;
	Qnode() {
		next = NULL;
	}
};

template<class T>
struct Queue {
	Qnode<T>* head;
	int size;
	string name;
	Queue() {
		head = NULL;
		size = 0;
	}

	Qnode<T>* front() {
		return head;
	}
	void enqueu(T data) {
		if (head == NULL) {
			Qnode<T>* temp = new Qnode<T>;
			temp->routerName = data;
			head = temp;
		}
		else {
			Qnode<T>* temp = new Qnode<T>;
			temp->routerName = data;
			Qnode<T>* temp1 = head;
			while (temp1 != NULL) {
				temp1 = temp1->next;
			}
			temp1 = temp;
		}
		size++;
	}

	T dequeue() {
		Qnode<T>* temp = head;
		head = temp->next;
		T ret = temp->routerName;
		delete temp;
		size--;
		return ret;
	}
	bool exist(T S) {
		Qnode<T>* temp = head;
		while (temp != NULL) {
			if (temp->routerName == S) {
				return true;
			}
		}
		return false;
	}
	bool empty() {
		if (head == NULL)
			return true;
		else
			return false;
	}
};

template <class T>
class MaxHeap
{
public:
	T* data;				//storing elements in Heap...
	int count;			//To keep a track of no. of elements inserted...

	MaxHeap() {
		data = new T[200];
		count = 0;
	}

	MaxHeap(int size) {		//paramaterized constructor with respect to size specified...
		data = new T[size];
		count = 0;
	}

	void swap(int ind1, int ind2)			//Function to Swap...
	{
		T swap1;
		swap1 = data[ind1];
		data[ind1] = data[ind2];
		data[ind2] = swap1;
	}


	int parent(int i) {
		return(i - 1) / 2;			//using formula to get index of parent...
	}

	int left_child(int i) {
		return(2 * i + 1);			//using formula to get index of left_child...
	}

	int right_child(int i) {
		return(2 * i + 2);			//using formula to get index of right_child...
	}

	void prioritycheck(int node, int least) {
		if (least > node) {
			int p_index = parent(least);
			if (data[p_index] < data[least]) {
				swap(p_index, least);
				prioritycheck(node, p_index);
			}
		}
	}

	void insert(T value) {
		data[count] = value;			//value inserted...
		prioritycheck(0, count);
		count++;
	}


	void prioritycheck1(int node, int least) {

		int left = left_child(node);
		int right = right_child(node);
		int maximum;

		if (left <= least) {
			if (left == least) {
				maximum = left;
			}

			else {
				if (data[left] >= data[right]) {
					maximum = right;
				}

				else {
					maximum = left;
				}

				if (data[node] < data[maximum]) {
					swap(node, maximum);
					prioritycheck1(maximum, least);
				}
			}
		}
	}


	T delete_max() {
		count--;
		T ret = data[0];
		data[0] = data[count];			//max-value(root) deleted...
		prioritycheck1(0, count);
		return ret;
	}

	void display() {

		for (int i = 0; i < count; i++) {
			cout << data[i] << " ";
		}
	}


};

template <class T>
class MinHeap
{
public:
	T* data;				//storing elements in Heap...
	int count = 0;			//To keep a track of no. of elements inserted...


	MinHeap(int size) {		//paramaterized constructor with respect to size specified...
		data = new T[size];
		count = 0;
	}

	void swap(int ind1, int ind2)			//Function to Swap...
	{
		T swap1;
		swap1 = data[ind1];
		data[ind1] = data[ind2];
		data[ind2] = swap1;
	}


	int parent(int i) {
		return(i - 1) / 2;			//using formula to get index of parent...
	}

	int left_child(int i) {
		return(2 * i + 1);			//using formula to get index of left_child...
	}

	int right_child(int i) {
		return(2 * i + 2);			//using formula to get index of right_child...
	}

	void prioritycheck(int node, int least) {
		if (least > node) {
			int p_index = parent(least);
			if (data[p_index] > data[least]) {
				swap(p_index, least);
				prioritycheck(node, p_index);
			}
		}
	}

	void insert(T value) {
		data[count] = value;			//value inserted...
		prioritycheck(0, count);
		count++;
	}


	void prioritycheck1(int node, int least) {

		int left = left_child(node);
		int right = right_child(node);
		int minimum;

		if (left <= least) {
			if (left == least) {
				minimum = left;
			}

			else {
				if (data[left] <= data[right]) {
					minimum = right;
				}

				else {
					minimum = left;
				}

				if (data[node] < data[minimum]) {
					swap(node, minimum);
					prioritycheck1(minimum, least);
				}
			}
		}
	}


	void delete_max() {
		count--;
		data[0] = data[count];			//max-value(root) deleted...
		prioritycheck1(0, count);
	}

	void display() {

		for (int i = 0; i < count; i++) {
			cout << data[i] << " ";
		}
	}


};

template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node() {
		next = NULL;
	}
};

template<class T>
class AdjList {
public:
	Node<T>* head;
	AdjList() {
		head = NULL;
	}
	void insert(T x) {
		if (head == NULL) {
			head = new Node<T>;
			head->data = x;
		}
		else {
			Node<T>* temp = head;
			while (temp->next != NULL) {
				if (temp->data == x || temp->next->data==x || head->data==x)
					return;

				temp = temp->next;
			}
			temp->next = new Node<T>;
			temp->next->data = x;
			//cout << "Insert: " << x << endl;
		}
	}
	Node<T>* front() {
		return head;
	}
};

template<class T>
class Graph {
public:
	AdjList<T>* L;
	T** AdjArr;
	int NumVer;
	int*** arr;
	int size;
	Graph() {
		L=NULL;
	}
	Graph(int s) {
		size = s;
		//Create AdjList
		L = new AdjList<T>[s];

		//Create AdjArr
		AdjArr = new T*[s];
		for (int i = 0; i < s; i++)
			AdjArr[i] = new T[s];

		//Initialize
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++) {
				AdjArr[i][j] = 0;
			}
		}
		NumVer = s;

		arr = new int** [s];
		for (int i = 0; i < s; i++) {
			arr[i] = new int* [s];
		}
		for (int i = 0; i < s; i++) {
			for (int j = 0; j < s; j++)
				arr[i][j] = new int[s];
		}
		for (int p = 0; p < s; p++) {
			for (int i = 0; i < s; i++) {
				for (int j = 0; j < s; j++)
					arr[p][i][j] = -1;
			}
		}
	}

	void insert(int x, int y, char z) {
		L[x].insert(y);
		L[y].insert(x);
		stringstream str;
		str << z;
		int i;
		str >> i;
		//cout << "x: " << x << endl;
		//cout << "y: " << y << endl;
		//cout << "i: "<< i << endl;
		AdjArr[x][y] = i;
		AdjArr[y][x] = i;
	}

	void DispArr() {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				cout << AdjArr[i][j] << " ";
			}
			cout << endl;
		}
	}

	// BFS algorithm
	void BFS(int numVertices) {
		for (int i = 0; i < numVertices; i++) {
			cout << "For " << i + 1 << ": ";
			Node<T>* temp2 = L[i].head;
			while (temp2) {
				cout << temp2->data << " ";
				temp2 = temp2->next;
			}
			cout << endl;
		}
	}

	string* CSVFile(Graph *G) {
		string* csv = new string[21];

		fstream fin;

		fin.open("network.csv", ios::in);

		string line, word, temp;
		int i = 0;
		while (fin >> temp&&i<21) {
			csv[i] = temp;
			i++;
			getline(fin, line);
			/*while (getline(word, ', ')) {
				cout << word << " ";
			}*/
		}
		/*i = 0;
		while (i < 21) {
			cout << csv[i] << endl;
			i++;
		}*/

		

		return csv;
	}

};

template<class T>
struct Routers {
	int numQ;
	T dest;
	int destI;
	string name;
	MaxHeap<Message> PriorityQueue;
	list<string> RountingTable[2]; //0 is dest, 1 is outgoing
	Queue<Message>* outgoingQ;

	Routers() {
		;
	}

	Routers(int s,T* arr, int x,T str,T Name) {
		name = Name;
		numQ = s;
		destI = x;
		dest = str;
		outgoingQ = new Queue<Message>[s];
		for (int i = 0; i < s; i++) {
			outgoingQ[i].name = arr[i];
		}
	}

	void create(int s, T* arr, T Name) {
		name = Name;
		outgoingQ = new Queue<Message>[s];
		for (int i = 0; i < s; i++) {
			outgoingQ[i].name = arr[i];
		}
	}

	void generateRT(int*** arr) {
		for (int i = 0; i < 20; i++) {
			//cout<<"GenRt "
			RountingTable[1].insert(new LNode<string>(getStr(arr[int(name[1])-48 +14][i][0])));
			//cout << "Outgoing: " << getStr(arr[getInt(name)][i][0]) << endl;
			RountingTable[0].insert(new LNode<string>(getStr(i)));
			//cout << "dest: " << getStr(i) << endl;
		}

	}

	void recieveMSG(Message* M, Routers<string>* R) {
		PriorityQueue.insert(*M);
		int i = 0;
		i=RountingTable[0].getindex(M->DestAdd);
		string destination = RountingTable[1].GetName(i);
		for (int j = 0; j < numQ; j++) {
			if (outgoingQ[i].name == destination)
				outgoingQ[i].enqueu(*M);
		}
		M->Trace += name;
		sendMsg(M,R);
	}

	void sendMsg(Message* M,Routers<string>* R) {
		PriorityQueue.delete_max();
		cout << name << endl;
		int i = 0;
		string send = "";
		i = RountingTable[0].getindex(M->DestAdd);
		string destination = RountingTable[1].GetName(i);
		for (int j = 0; j < numQ; j++) {
			if (outgoingQ[i].name == destination)
				send=outgoingQ[i].dequeue().DestAdd;
		}
		if (destination==M->DestAdd) {
			cout << "Message delivered!" << endl;
			return;
		}
		if (destination!="") {
			cout << "Sending message to " << destination <<"..." << endl;
			Sleep(1000);
			cout << "Message forwarded." << endl;
			int pls = int(destination[1])-48;
			R[pls-1].recieveMSG(M,R);
		}
		else {
			cout << "Message could not be sent" << endl;
		}
		
	}
};