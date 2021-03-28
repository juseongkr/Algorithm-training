#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 301

int p, m, l, idx, lv[MAX];
vector<pair<string, int>> vec[MAX];
string n;

int main()
{
	cin >> p >> m;
	for (int i=0; i<p; ++i) {
		cin >> l >> n;
		for (int j=0; j<MAX; ++j) {
			if (lv[j] == 0) {
				lv[j] = l;
				vec[j].push_back({n, l});
				idx++;
				break;
			} else if (abs(lv[j] - l) <= 10 && vec[j].size() < m) {
				vec[j].push_back({n, l});
				break;
			}
		}
	}

	for (int i=0; i<idx; ++i) {
		if (vec[i].size() == m)
			cout << "Started!\n";
		else
			cout << "Waiting!\n";

		sort(vec[i].begin(), vec[i].end());
		for (int j=0; j<vec[i].size(); ++j) {
			cout << vec[i][j].second << " " << vec[i][j].first << '\n';
		}
	}

	return 0;
}
