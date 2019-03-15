#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<string> array[51];
	string word, same;
	int num;

	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> word;
		array[word.size()].push_back(word);
	}
	
	for (int i=0; i<51; ++i)
		sort(array[i].begin(), array[i].end());

	for (int i=0; i<51; ++i) {
		for (auto elem : array[i]) {
			if (elem != same)
				cout << elem << '\n';
			same = elem;
		}
	}

	return 0;
}
