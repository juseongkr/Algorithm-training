#include <iostream>
using namespace std;

int main()
{
	int num[100001];
	int n, t, idx = 0, sum = 0;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &t);
		if (t != 0)
			num[idx++] = t;
		else
			idx--;
	}

	for (int i=0; i<idx; ++i)
		sum += num[i];

	printf("%d\n", sum);

	return 0;
}
