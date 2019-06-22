#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000001

int main()
{
	int lego[MAX];
	int x, n;

	while (scanf("%d", &x) != EOF) {
		x *= 10000000;
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d", &lego[i]);

		sort(lego, lego+n);

		int l = 0, r = n-1;
		while (l <= r) {
			int sum = lego[l] + lego[r];
			if (sum == x)
				break;
			if (sum > x)
				r--;
			else
				l++;
		}
		if (l >= r)
			printf("danger\n");
		else
			printf("yes %d %d\n", lego[l], lego[r]);
	}

	return 0;
}
