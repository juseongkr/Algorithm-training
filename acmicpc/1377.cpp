#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	pair<int, int> num[500001];
	int n, ans = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &num[i].first);
		num[i].second = i;
	}

	sort(num, num+n);

	for (int i=0; i<n; ++i)
		ans = max(ans, num[i].second - i);

	printf("%d\n", ans + 1);

	return 0;
}
