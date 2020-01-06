#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	long long n, m, tmp;
	long long sum = 0, total = 0, max_val = 0;
	vector<long long> a;

	scanf("%lld %lld", &n, &m);

	for (int i=0; i<n; ++i) {
		scanf("%lld", &tmp);
		a.push_back(tmp);
		total += tmp;
	}

	sort(a.begin(), a.end());

	for (int i=0; i<n; ++i) {
		if (a[i] > max_val)
			max_val++;
	}

	n += (a[n-1] - max_val);

	sum = total - n;
	
	cout << sum << '\n';

	return 0;
}
