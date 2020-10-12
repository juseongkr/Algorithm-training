#include <iostream>
#include <cmath>
using namespace std;

int solve(int n)
{
	int cnt = 0, t = n;
	for (int i=2; i<n; ++i) {
		if (n % i)
			continue;

		while (t % i == 0) {
			cnt++;
			t /= i;
		}
	}

	return cnt ? cnt : 1;
}

int n;

int main()
{
	cin >> n;

	cout << ceil(log2(solve(n))) << '\n';

	return 0;
}
