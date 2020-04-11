#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000001

int n, k, p, idx[MAX];
vector<pair<int, int>> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> k;
		vec.push_back({k, i});
	}

	sort(vec.begin(), vec.end());

	for (int i=1; i<n; ++i) {
		if (vec[i-1].first != vec[i].first)
			p++;
		idx[vec[i].second] = p;
	}

	for (int i=0; i<n; ++i)
		cout << idx[i] << " ";
	cout << '\n';

	return 0;
}
