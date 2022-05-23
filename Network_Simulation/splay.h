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
#include "Header.h"
#include "splayC.h"
using namespace std;

struct tablerow {

	string destination;
	string nextdevice;

	tablerow() {

	}

	tablerow(string s1, string s2) {
		destination = s1;
		nextdevice = s2;
	}

	bool operator<(tablerow rhs) {
		return stoi(destination.substr(1, destination.length())) < stoi(rhs.destination.substr(1, rhs.destination.length()));
	}
	bool operator>(tablerow rhs) {
		return stoi(destination.substr(1, destination.length())) > stoi(rhs.destination.substr(1, rhs.destination.length()));
	}
	bool operator==(tablerow rhs) {
		return destination == rhs.destination && nextdevice == rhs.nextdevice;
	}
	bool operator!=(tablerow rhs) {
		return destination == rhs.destination || nextdevice == rhs.nextdevice;
	}
	bool operator<=(tablerow rhs) {
		return stoi(destination.substr(1, destination.length())) <= stoi(rhs.destination.substr(1, rhs.destination.length()));
	}
	bool operator>=(tablerow rhs) {
		return stoi(destination.substr(1, destination.length())) >= stoi(rhs.destination.substr(1, rhs.destination.length()));
	}
	friend ostream& operator<<(ostream& os, const tablerow& dt);
};

ostream& operator<<(ostream& os, const tablerow& dt) {
	os << dt.destination << "   " << dt.nextdevice;
	return os;
}


template<class T>
struct SplayRouters {
	T dest;
	int destI;
	string name;
	MaxHeap<Message> PriorityQueue;
	SplayTree<tablerow> RoutingTable;
	//list<string> RountingTable[2]; //0 is dest, 1 is outgoing
	Queue<Message>* outgoingQ;

	SplayRouters() {
		;
	}

	SplayRouters(int s, T* arr, int x, T str, T Name) {
		name = Name;
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
		//cout << "--------->" << name << endl;
		for (int i = 0; i < 15; i++) {
			//cout << stoi(name.substr(1, name.length())) + 14 << endl;
			
			RoutingTable.insertNode(*(new tablerow(getStr(i), getStr(arr[stoi(name.substr(1, name.length())) + 14][i][0]))));
		}
		//cout << "lol ->>>" << endl;
		//RoutingTable.Inorder(RoutingTable.root);
	}

	void sendMSG(Message* M, SplayRouters* rts) {
		tablerow* srch = new tablerow(M->DestAdd, "");
		RoutingTable.splay(RoutingTable.root, *srch);
		//cout <<  "1" << RoutingTable.root->value.nextdevice << std::endl;
		if (RoutingTable.root->value.nextdevice == M->DestAdd) {
			Sleep(1000);
			cout << "Message Received" << endl;
		}
		else if (RoutingTable.root->value.destination == M->DestAdd) {
			Sleep(1000);
			//cout << "tgia is sparta >>" << RoutingTable.root->value.nextdevice << endl;
			int index = stoi(RoutingTable.root->value.nextdevice.substr(1, RoutingTable.root->value.nextdevice.length())) - 1;
			//cout << index << endl;
			rts[index].recieveMSG(M, rts);
		}
		else {
			cout << "Link Broken :(" << std::endl;
		}
	}

	void recieveMSG(Message* M, SplayRouters* rts) {
		
		PriorityQueue.insert(*M);
		M->Trace += name + " ";
		cout << name  << std::endl;
		sendMSG(M, rts);
		
	}

};
