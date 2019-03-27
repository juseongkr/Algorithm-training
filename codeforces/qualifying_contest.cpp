#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{	
	vector<pair<int, string>> q[100001];
	string name;
	int n, m, r, s;

	cin >> n >> m;

	for (int i=0; i<n; ++i) {
		cin >> name >> r >> s;
		q[r].push_back({s, name});
	}

	for (int i=1; i<=m; ++i) {
		sort(q[i].begin(), q[i].end());

		if (q[i].size() >= 3 && q[i][q[i].size()-3].first == q[i][q[i].size()-2].first)
			cout << "?\n";
		else
			cout << q[i][q[i].size()-1].second << " " << q[i][q[i].size()-2].second << '\n';
	}

	return 0;
}
