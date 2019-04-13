#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long num[1000001];
	long long ret;
	int n, cnt = 1, max_cnt = 1;

	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%lld", &num[i]);

	sort(num, num+n);
	
	ret = num[0];
	for (int i=0; i<n-1; ++i) {
		if (num[i] == num[i+1])
			cnt++;
		else
			cnt = 1;
		if (max_cnt < cnt) {
			max_cnt = cnt;
			ret = num[i];
		}
	}

	printf("%lld", ret);

	return 0;
}
