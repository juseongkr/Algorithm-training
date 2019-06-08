#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<string, int> dict;
	string s;
	int n;

	cin >> n;
	for (int i=0; i<n*2-1; ++i) {
		cin >> s;
		dict[s]++;
	}

	for (auto it=dict.begin(); it!=dict.end(); it++)
		if (it->second % 2 != 0)
			cout << it->first;

	return 0;
}
