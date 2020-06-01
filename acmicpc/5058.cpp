#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 20001
typedef pair<int, int> pi;

int T, m, w, h;
int arr[MAX];
vector<pi> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> m;
		vec.clear();
		for (int i=0; i<m; ++i) {
			cin >> w >> h;
			vec.push_back({w, h});
		}

		sort(vec.begin(), vec.end(), [](pi a, pi b) {
			if (a.first != b.first)
				return a.first > b.first;
			return a.second < b.second;
		});

		int len = 0;
		fill(arr, arr+MAX, 0);
		for (int i=0; i<m; ++i) {
			int idx = upper_bound(arr, arr+len, vec[i].second) - arr;
			if (idx == len)
				len++;
			arr[idx] = vec[i].second;
		}
		cout << len << '\n';
	}

	return 0;
}
