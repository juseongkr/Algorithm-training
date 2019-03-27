#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second && a.first < b.first)
		return true;
	else
		return false;
}

int main()
{
	vector<pair<int, int>> vec;
	int n, x, y;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end(), compare);

	for (auto i : vec)
		cout << i.first << " " << i.second << '\n';

	return 0;
}
