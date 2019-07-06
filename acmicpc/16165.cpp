#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 101

int main()
{
	string group[MAX];
	vector<string> member[MAX];
	string s, team, name, query;
	int n, m, count, type;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> group[i] >> count;
		for (int j=0; j<count; ++j) {
			cin >> name;
			member[i].push_back(name);
		}
	}

	for (int k=0; k<m; ++k) {
		cin >> query >> type;
		if (type) {
			for (int i=0; i<n; ++i) {
				bool flag = false;
				for (int j=0; j<member[i].size(); ++j) {
					if (member[i][j] == query) {
						cout << group[i] << '\n';
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
		} else {
			for (int i=0; i<n; ++i) {
				if (group[i] == query) {
					sort(member[i].begin(), member[i].end());
					for (int j=0; j<member[i].size(); ++j)
						cout << member[i][j] << '\n';
					break;
				}
			}
		}
	}

	return 0;
}
