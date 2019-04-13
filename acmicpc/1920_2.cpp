#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[100001];
	int n, m, t;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", &num[i]);

	sort(num, num + n);

	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		scanf("%d", &t);
		if (binary_search(num, num + n, t))
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
