#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	deque<pair<int, int>> que;
	vector<int> num;
	int n, l, t;

	scanf("%d %d", &n, &l);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		num.push_back(t);
	}

	for (int i=0; i<n; ++i) {
		int len = i - l;
		if (!que.empty() && que.front().second <= len)
			que.pop_front();

		while (!que.empty() && que.back().first > num[i])
			que.pop_back();

		que.push_back({num[i], i});
		printf("%d ", que.front().first);
	}

	return 0;
}
