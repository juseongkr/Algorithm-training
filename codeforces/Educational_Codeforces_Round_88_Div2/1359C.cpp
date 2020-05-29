#include <iostream>
using namespace std;
const long long INF = 1e12+7;

int T;
long long h, c, t;

inline bool check(long long mid)
{
	return mid * h + (mid-1) * c >= (mid*2-1) * t;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> h >> c >> t;
		if (h == t) {
			cout << "1\n";
		} else if (h+c >= t*2) {
			cout << "2\n";
		} else {
			long long l = 1, r = INF;
			for (int i=0; i<50; ++i) {
				long long mid = (l+r)/2;
				if (check(mid))
					l = mid;
				else
					r = mid;
			}

			if ((l*h+(l-1)*c) * (2*r-1) <= 2*t*(2*l-1)*(2*r-1) - (r*h+(r-1)*c) * (2*l-1))
				cout << l*2-1 << '\n';
			else
				cout << r*2-1 << '\n';
		}
	}

	return 0;
}
