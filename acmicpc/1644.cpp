#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, left = 0, right = 0, cnt = 0, ans = 0;
	vector<int> num;
	vector<bool> prime;

	scanf("%d", &n);
	prime.resize(n+1, true);
	for (int i=2; i<=n; ++i) {
		if (prime[i])
			num.push_back(i);
		for (int j=i; j<=n; j+=i)
			prime[j] = false;
	}

	while (1) {
		if (ans >= n)
			ans -= num[left++];
		else if (right == num.size())
			break;
		else
			ans += num[right++];
		if (ans == n)
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
