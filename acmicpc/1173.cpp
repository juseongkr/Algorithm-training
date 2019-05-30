#include <iostream>
using namespace std;

int main()
{
	int N, m, M, T, R, L;
	int t = 0, cnt = 0;

	cin >> N >> m >> M >> T >> R;
	if (m + T > M) {
		cout << "-1\n";
		return 0;
	}

	L = m;
	while (cnt < N) {
		t++;
		if (L + T <= M) {
			cnt++;
			L += T;
		} else {
			L -= R;
			if (L < m)
				L = m;
		}
	}

	cout << t << '\n';

	return 0;
}
