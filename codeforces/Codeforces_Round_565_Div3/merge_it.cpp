#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long k;
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		int cnt = 0, one = 0, two = 0;
		for (int i=0; i<n; ++i) {
			cin >> k;
			if (k % 3 == 1)
				one++;
			else if (k % 3 == 2)
				two++;
			else
				cnt++;
		}
		if (one < two)
			swap(one, two);

		if (one == two) {
			cout << cnt + one << '\n';
		} else {
			cnt += two + (one-two)/3;
			cout << cnt << '\n';
		}
	}

	return 0;
}
