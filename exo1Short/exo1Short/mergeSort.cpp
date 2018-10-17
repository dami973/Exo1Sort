#include "mergeSort.h"
#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int>left, vector<int>right);
vector<int> sort(vector<int> initList);
vector<int> rang(vector<int> sortList, vector<int> list);

mergeSort::mergeSort(vector<int> list)
{
	sortList = sort(list);
	rangList = rang(sortList, list);
}

void mergeSort::getSort() {
	int size = sortList.size();
	for (int i = 0; i < size; i++) {
		cout << sortList[i] << " ";
	}
	cout << "\n";
}

void mergeSort::getRang() {
	int size = rangList.size();
	for (int i = 0; i < size; i++) {
		cout << rangList[i] << " ";
	}
	cout << "\n";
}

vector<int> merge(vector<int>left, vector<int>right) {
	vector<int> result;

	while (!left.empty() || !right.empty()) {
		if (!left.empty() && ((!right.empty() && left[0] <= right[0]) || right.empty())) {
			result.push_back(left[0]);
			left.erase(left.begin());
		}
		else if (!right.empty() && ((!left.empty() && left[0] > right[0]) || left.empty())) {
			result.push_back(right[0]);
			right.erase(right.begin());
		}
	}

	return result;
}

vector<int> sort(vector<int> initList) {
	int size = initList.size();

	if (size <= 1) return initList; 

	vector<int> right, left;
	
	for (int i = 0; i < size; i++) {
		if (i < size / 2) {
			left.push_back(initList[i]);
		}
		else {
			right.push_back(initList[i]);
		}
	}

	left = sort(left);
	right = sort(right);

	return merge(left, right);
}

vector<int> rang(vector<int> sortList, vector<int> list) {
	int size = list.size();
	vector<int> rangList;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (sortList[i] == list[j]) {
				bool rangExist = false;
				int sizeR = rangList.size();
				for (int k = 0; k < sizeR; k++) {
					if (rangList[k] == j) {
						rangExist = true;
						break;
					}
				}
				if (!rangExist)rangList.push_back(j);
			}
		}
	}
	return rangList;
}