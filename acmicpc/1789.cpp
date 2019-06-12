#include <iostream>
using namespace std;

int i, ans;
long long n, sum;

int main()
{
	cin >> n;
	while (1) {
		sum += ++i;
		ans++;
		if (sum > n)
			break;
	}

	cout << ans-1 << '\n';

	return 0;
}
