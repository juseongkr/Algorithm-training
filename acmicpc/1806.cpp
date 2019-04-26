#include <iostream>
#include <climits>
using namespace std;

#define MAX_VAL 100001

int main()
{
	int num[MAX_VAL];
	int n, s, left = 0, right = 0, cnt = 0, sum = 0, ret = INT_MAX;

	scanf("%d %d", &n, &s);
	for (int i=0; i<n; ++i)
		scanf("%d", &num[i]);

	while (1) {
		if (sum >= s) {
			ret = min(ret, right - left);
			sum -= num[left++];
			cnt++;
		} else if (right == n) {
			break;
		} else {
			sum += num[right++];
		}
	}

	if (cnt)
		printf("%d\n", ret);
	else
		printf("0\n");

	return 0;
}
