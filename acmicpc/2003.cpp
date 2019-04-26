#include <iostream>
using namespace std;

int main()
{
	int num[10001];
	int n, m, ret = 0, cnt = 0;
	int left = 0, right = 0;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		scanf("%d", &num[i]);

	while (1) {
		if (ret >= m)
			ret -= num[left++];
		else if (right == n)
			break;
		else
			ret += num[right++];
		if (ret == m)
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
