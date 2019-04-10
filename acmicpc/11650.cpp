#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	vector<pair<int, int>> vec;
	int n, x, y;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d %d", &x, &y);
		vec.push_back({x, y});
	}

	sort(vec.begin(), vec.end(), cmp);

	for (int i=0; i<n; ++i)
		printf("%d %d\n", vec[i].first, vec[i].second);

	return 0;
}
