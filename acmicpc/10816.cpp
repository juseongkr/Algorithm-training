#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[500001];
	int n, m, t;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &num[i]);

	sort(num, num+n);

	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		scanf("%d", &t);
		int left = lower_bound(num, num + n, t) - num;
		int right = upper_bound(num, num + n, t) - num;
		printf("%d ", right - left);
	}

	return 0;
}
