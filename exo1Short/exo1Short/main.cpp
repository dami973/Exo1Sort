#include "insertSort.h"
#include "mergeSort.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int recupInt() {
	bool syntax = false;
	int i,size;
	string line;
	stringstream ss;
	while (!syntax) {
		cin >> line;
		size = line.size();
		for (int j = 0; j < size ;j++) {
			ss<<line[j];
			ss >> i;
			if (ss.fail()&& line[0]!=('-') ){
				cout << line[j]<<" Error, you have to put an integer \n";
				cin.ignore(256, '\n');
				cin.clear();
				ss.clear();
				syntax = false;
				break;
			}
			else syntax = true;
		}
	}
	ss<<line;
	ss >> i;
	return i;
}
/*
int recupInt() {
	string line;
	int i;
	stringstream ss;

	cin >> line;
	ss << line;
	ss >> i;

	while (ss.fail()) {
		cout <<line<< " Error, you have to put a int "<<endl;
		cin.ignore(256, '\n');
		cin.clear();
		ss.clear();

		cin >> line;
		ss<<line;
		cout<<ss.get();
		ss >> i;
		cout << i<<endl;
	}
	return i;
}*/

char recupChar() {
	string line;
	char i;
	stringstream ss;

	cin >> line;
	ss << line;
	ss >> i;
	while (ss.fail()) {
		cout << "Error, you have to put a single character /n";
		cin.clear();
		ss.clear();
		cin.ignore(256, '\n');
		cin >> line;
		ss << line;
		ss >> i;
	}
	return i;
}

int main() {
	vector<int> list;
	int value,size;
	char rep, rep2;
	bool syntax = false;

	cout << "How many value is there in your list ?\n";
	while (!syntax) {	
		size = recupInt();
		if (size <= 0) {
			syntax = false;
			cout << "Error, you have to put an integer >0 \n";
			cin.clear();
		}
		else syntax = true;
	}
	syntax = false;

	cout << "Enter your list one value by one :\n";
	for (int i = 0; i < size; i++) {
		value = recupInt();
		list.push_back(value);
	}

	while (!syntax) {
		cout << "merge or insertion sort? (m or i)\n";
		rep = recupChar();
		cin.clear();
		if (rep == 'm' || rep == 'M' || rep == 'i' || rep == 'I') syntax = true;
	}
	syntax = false;

	mergeSort mergeList(list);
	insertSort inserList(list);
	if (rep == 'm' || rep == 'M')mergeList.getSort();
	if (rep == 'i' || rep == 'I') inserList.getSort();
	

	while (!syntax) {
		cout << "Do you want the initial rank ? (y or n)\n";
		rep2 = recupChar();
		if (rep2 == 'y' || rep2 == 'Y'||rep2 == 'n' || rep2 == 'N')syntax = true;
	}
	syntax = false;
				
	if ((rep2 == 'y' || rep2 == 'Y')&& (rep == 'i' || rep == 'I'))inserList.getRang();
	if ((rep2 == 'y' || rep2 == 'Y') && (rep == 'm' || rep == 'M'))mergeList.getRang();
		
	
	return 0;
}

