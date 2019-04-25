#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define MAX_VAL 10001

int main()
{
	vector<int> v;
	bool prime[MAX_VAL];
	int hash[MAX_VAL];
	int t, n, idx, min_val;

	fill(prime+2, prime+MAX_VAL, true);
	fill(hash, hash+MAX_VAL, 0);
	for (int i=2; i<=MAX_VAL; ++i) {
		if (prime[i]) {
			v.push_back(i);
			hash[i] = 1;
		}
		for (int j=i; j<=MAX_VAL; j+=i)
			prime[j] = false;
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		min_val = INT_MAX;
		for (int i=0; i<v.size(); ++i) {
			if (hash[n-v[i]] && n-v[i] > 0) {
				if (min_val > abs(n-v[i] - v[i])) {
					idx = i;
					min_val = n-v[i] - v[i];
				}
			}
		}
		printf("%d %d\n", v[idx], n-v[idx]);
	}

	return 0;
}
