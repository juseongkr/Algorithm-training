#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[100001];
	int n, t, len = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		auto it = lower_bound(num, num + len, t);
		if (it == num + len)
			len++;
		*it = t;
	}

	printf("%d\n", n - len);

	return 0;
}
