#include <vector>

using namespace std;

class insertSort
{
public:
	insertSort(vector<int> List);
	void getSort();
	void getRang();

private:
	vector<int> sortListe;
	vector<int> rangListe;
};