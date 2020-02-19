#include <iostream>
using namespace std;

int t, n, d;
int num[101];

int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> d;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		while (d--) {
			for (int i=1; i<n; ++i) {
				if (num[i]) {
					num[i-1]++;
					num[i]--;
					break;
				}
			}
		}
		cout << num[0] << '\n';
	}

	return 0;
}
