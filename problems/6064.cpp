#include <iostream>
using namespace std;

int main()
{
	int m, n, x, y, num, i, j, k, cnt;
	cin >> num;

	for (int t=0; t<num; ++t) {
		i = 1;
		j = 1;
		k = 1;
		cnt = 1;
		cin >> m >> n >> x >> y;
		while (1) {
			if (i == x)
				k = m;
			else if (j == y)
				k = n;

			if ((i + k) % m == 0)
				i = m;
			else
				i = (i + k) % m;

			if ((j + k) % n == 0)
				j = n;
			else
				j = (j + k) % n;

			cnt += k;

			if (i == x && j == y)
				break;

			if (cnt > m * n) {
				cnt = -1;
				break;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}
