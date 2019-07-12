#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 41

int main()
{
	int num[MAX];
	int n, s;

	cin >> n >> s;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int m = n/2;
	n = n-m;
	vector<int> A(1 << n);
	vector<int> B(1 << m);
	for (int i=0; i<(1 << n); ++i)
		for (int j=0; j<n; ++j)
			if (i & (1 << j))
				A[i] += num[j];

	for (int i=0; i<(1 << m); ++i)
		for (int j=0; j<m; ++j)
			if (i & (1 << j))
				B[i] += num[j+n];

	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());

	int l = 0, r = 0;
	long long ans = 0;
	while (l < (1 << n) && r < (1 << m)) {
		if (A[l] + B[r] == s) {
			long long a = 1;
			long long b = 1;
			l++;
			r++;
			while (l < (1 << n) && A[l-1] == A[l]) {
				a++;
				l++;
			}

			while (r < (1 << m) && B[r-1] == B[r]) {
				b++;
				r++;
			}
			ans += a * b;
		} else if (A[l] + B[r] < s) {
			l++;
		} else {
			r++;
		}
	}
	if (s == 0)
		ans--;

	cout << ans << '\n';

	return 0;
}
