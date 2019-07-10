#include <iostream>
#include <vector>
using namespace std;
#define MAX 1000001

bool check[MAX];
vector<int> prime;

int main()
{
	int t, n;

	fill(check+2, check+MAX, true);
	for (int i=2; i<MAX; ++i) {
		if (check[i])
			prime.push_back(i);
		for (int j=i+i; j<MAX; j+=i)
			check[j] = false;
	}

	cin >> t;
	while (t--) {
		cin >> n;

		int ans = 0;
		for (int i=0; i<prime.size(); ++i) {
			int num = n - prime[i];
			if (2 <= num && prime[i] <= num) {
				if (check[num])
					ans++;
			} else {
				break;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
