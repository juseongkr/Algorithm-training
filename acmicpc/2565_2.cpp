#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	pair<int, int> li[101];
	int num[101];
	int n, len = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d %d", &li[i].first, &li[i].second);

	sort(li, li + n);

	for (int i=0; i<n; ++i) {
		auto it = lower_bound(num, num + len, li[i].second);
		if (it == num + len)
			len++;
		*it = li[i].second;
	}

	printf("%d\n", n - len);

	return 0;
}
