#include <iostream>
using namespace std;

int num[1001];

int __lower_bound(int start, int end, int elem)
{
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (num[mid] > elem)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int main()
{
	int n, t, len = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);

		int it = __lower_bound(0, len, t);
		if (it == len)
			len++;
		num[it] = t;
	}

	printf("%d\n", len);

	return 0;
}
