#include <iostream>
#include <vector>
using namespace std;

#define MAX_VAL 1000001

int main()
{
	vector<int> v;
	bool prime[MAX_VAL];
	int hash[MAX_VAL];
	bool flag;
	int n;

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

	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;

		flag = true;
		for (int i=0; i<v.size(); ++i) {
			if (hash[n-v[i]] && n-v[i] > 0) {
				printf("%d = %d + %d\n", n, v[i], n-v[i]);
				flag = false;
				break;
			}
		}

		if (flag)
			printf("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}
