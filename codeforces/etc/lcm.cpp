#include <iostream>
using namespace std;

int main()
{
	long long b, a, i, cnt = 0;

	cin >> b;

	for (i=1; i*i<=b; ++i) {
		if (b % i == 0) {
			if (i * i == b)
				cnt++;
			else
				cnt+=2;
		}
	}

	cout << cnt << '\n';

	return 0;
}
