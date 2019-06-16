#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long t;
	
	cin >> n;
	for (int i=0; i<n; ++i) {
		int cnt = 0;
		cin >> t;
		while (1) {
			if (t == 1) {
				cout << cnt << '\n';
				break;
			}
			if (t % 2 == 0) {
				t /= 2;
				cnt++;
			} else if (2*t % 3 == 0) {
				t = 2*t/3;
				cnt++;
			} else if (4*t % 5 == 0) {
				t = 4*t/5;
				cnt++;
			} else {
				cout << "-1\n";
				break;
			}
		}
	}

	return 0;
}
