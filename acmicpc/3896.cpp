#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_VAL 1299710

int main()
{
	bool prime[MAX_VAL];
	vector<int> v;
	int t, n;

	fill(prime+2, prime+MAX_VAL, true);
	for (int i=2; i<=MAX_VAL; ++i) {
		if (prime[i])
			v.push_back(i);
		for (int j=i; j<=MAX_VAL; j+=i)
			prime[j] = false;
	}

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n == 1 || n == 2) {
			printf("0\n");
		} else {
			for (int i=1; i<v.size(); ++i) {
				if (v[i] == n) {
					printf("0\n");
					break;
				} else if (v[i] > n) {
					printf("%d\n", v[i] - v[i-1]);
					break;
				}
			}
		}
	}

	return 0;
}
