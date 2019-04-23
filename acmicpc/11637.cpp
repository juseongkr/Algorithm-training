#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[11];
	int t, n;

	scanf("%d", &t);
	while (t--) {
		int sum = 0, max_val = 0, idx = 0;
		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			scanf("%d", &num[i]);
			sum += num[i];
			if (max_val < num[i]) {
				idx = i;
				max_val = num[i];
			}
		}

		sort(num, num+n);

		if (num[n-2] == num[n-1])
			printf("no winner\n");
		else if (max_val <= sum/2)
			printf("minority winner %d\n", idx+1);
		else
			printf("majority winner %d\n", idx+1);
	}

	return 0;
}
