#include <iostream>
using namespace std;

int main()
{
	long long n, k, cnt, l = 0;

	while (cin >> n >> k) {
		cnt = n;
		while (cnt >= k) {
			l = cnt / k;
			cnt %= k;
			n += l;
			cnt += l;
		}
		cout << n << '\n';
	}

	return 0;
}
