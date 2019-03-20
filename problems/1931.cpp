#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first && a.second < b.second)
		return true;
	else
		return false;
}

int main()
{
	vector<pair<int, int>> time;
	int n, s, e, cnt = 0, pos = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		cin >> s >> e;
		time.push_back({e, s});
	}

	sort(time.begin(), time.end(), cmp);

	for (int i=0; i<n; ++i) {
		if (pos <= time[i].second) {
			pos = time[i].first;
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}
