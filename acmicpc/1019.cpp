#include <iostream>
using namespace std;

int ans[10];

void add(int n, int base)
{
	while (n) {
		ans[n%10] += base;
		n /= 10;
	}
}

int main()
{
	int n;

	cin >> n;
	int i = 1, base = 1;
	while (i <= n) {
		while (i <= n && i % 10 != 0) {
			add(i, base);
			i++;
		}

		if (i > n)
			break;

		while (i <= n && n % 10 != 9) {
			add(n, base);
			n--;
		}

		int cnt = n/10 - i/10 + 1;
		for (int i=0; i<10; ++i)
			ans[i] += cnt * base;

		i /= 10;
		n /= 10;
		base *= 10;
	}
	for (int i=0; i<10; ++i)
		cout << ans[i] << " ";

	return 0;
}
