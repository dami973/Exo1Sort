#include<iostream>
#include "insertSort.h"
#include "mergeSort.h"

vector<int> insert(vector<int> List);
vector<int> rang(vector<int> sortList, vector<int> list);

insertSort::insertSort(vector<int> List)
{
	sortListe = insert(List);
	rangListe = rang(sortListe, List);
}

void insertSort::getSort() {
	int size = this->sortListe.size();
	for (int i = 0; i < size; i++) {
		cout << this->sortListe[i] << " ";
	}
	cout << "\n";
}

void insertSort::getRang() {
	int size = this->rangListe.size();
	for (int i = 0; i < size; i++) {
		cout << this->rangListe[i] << " ";
	}
	cout << "\n";
}


vector<int> insert(vector<int> List) {
	int value;
	int size = List.size();
	int j,i;
	i = 1;
	while ( i < size) {
		j = i;
		while (j > 0 && List[j - 1] > List[j]) {
			value = List[j - 1];
			List[j - 1] = List[j];
			List[j]=value;
			j=j-1;
		}
		i=i+1;
	}
	return List;
}