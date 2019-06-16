#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<pair<int, int>> vec;
	int n, m, v;

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> v;
			if (v == 1)
				vec.push_back({i, j});
		}
	}
	
	int x = abs(vec[0].first - vec[1].first);
	int y = abs(vec[0].second - vec[1].second);
	cout << x + y << '\n';

	return 0;
}
