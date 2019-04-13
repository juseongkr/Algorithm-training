#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	pair<int, int> li[100001];
	vector<pair<int, int>> vec;
	int num[100001];
	int n, len = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d %d", &li[i].first, &li[i].second);

	sort(li, li + n);

	for (int i=0; i<n; ++i) {
		int it = lower_bound(num, num + len, li[i].second) - num;
		if (it == len)
			len++;
		num[it] = li[i].second;
		vec.push_back({it, li[i].second});
	}

	printf("%d\n", n - len);
	for (int i=n-1; i>=0; i--) {
		if (vec[i].first == len-1) {
			vec[i].second = -1;
			len--;
		}
	}

	for (int i=0; i<n; ++i)
		if (vec[i].second > 0)
			printf("%d\n", li[i].first);

	return 0;
}
