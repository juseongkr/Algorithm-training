#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 51

int ans[10];

int main()
{
	vector<pair<int, int>> vec;
	string map[MAX];
	int r, c;

	cin >> r >> c;
	for (int i=0; i<r; ++i) {
		cin >> map[i];
		for (int j=c-1; j>=0; j--) {
			if ('1' <= map[i][j] && map[i][j] <= '9') {
				vec.push_back({j, map[i][j]-'0'});
				break;
			}
		}
	}

	sort(vec.rbegin(), vec.rend());

	int cnt = 1;
	int prev = vec[0].first;
	ans[vec[0].second] = 1;
	for (int i=1; i<vec.size(); ++i) {
		if (vec[i].first == prev) {
			ans[vec[i].second] = cnt;
		} else {
			ans[vec[i].second] = ++cnt;
			prev = vec[i].first;
		}
	}

	for (int i=1; i<10; ++i)
		cout << ans[i] << '\n';

	return 0;
}
