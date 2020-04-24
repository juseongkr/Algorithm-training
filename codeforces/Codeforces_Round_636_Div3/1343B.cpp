#include <iostream>
#include <vector>
using namespace std;

int T, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		if ((n / 2) % 2) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			int idx = 2, sum = 0;
			for (int i=0; i<n/2; ++i, idx+=2) {
				sum += idx;
				cout << idx << " ";
			}

			idx = 1;
			for (int i=0; i<n/2-1; ++i, idx+=2) {
				sum -= idx;
				cout << idx << " ";
			}

			cout << sum << '\n';
		}
	}
}
