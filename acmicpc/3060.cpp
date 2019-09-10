#include <iostream>
#include <vector>
using namespace std;

long long num[6], nxt[6];

int main()
{
	int t, k;
	long long n;

	cin >> t;
	while (t--) {
		cin >> n;
		long long sum = 0;
		for (int i=0; i<6; ++i) {
			cin >> num[i];
			sum += num[i];
		}

		if (sum > n) {
			cout << "1\n";
			continue;
		}

		for (int i=2; ; ++i) {
			sum = 0;
			for (int j=0; j<6; ++j) {
				nxt[j] = (num[j] + num[(j+1)%6] + num[(j+3)%6] + num[(j+5)%6]);
				sum += nxt[j];
			}
			if (sum > n) {
				cout << i << '\n';
				break;
			}
			for (int i=0; i<6; ++i)
				num[i] = nxt[i];
		}
	}

	return 0;
}
