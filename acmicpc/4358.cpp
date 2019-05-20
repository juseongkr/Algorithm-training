#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, int> dict;
	int cnt = 0;
	string s;

	while (getline(cin, s)) {
		cnt++;
		dict[s]++;
	}

	for (auto it=dict.begin(); it!=dict.end(); it++)
		cout << fixed << setprecision(4) << it->first << " " << (double)it->second/cnt*100 << '\n';

	return 0;
}
