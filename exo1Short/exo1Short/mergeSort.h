#include <vector>

using namespace std;

class mergeSort
{
public:
	mergeSort(vector<int> list);
	void getSort();
	void getRang();

private:
	vector<int> sortList;
	vector<int> rangList;
};

