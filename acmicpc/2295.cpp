#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001

int n, k, num[MAX], sum[MAX*MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	for (int i=0; i<n; ++i)
		for (int j=i; j<n; ++j)
			sum[k++] = num[i] + num[j];

	sort(sum, sum+k);

	for (int i=n-1; i>=0; i--) {
		for (int j=i; j>=0; j--) {
			if (binary_search(sum, sum+k, num[i] - num[j])) {
				cout << num[i] << '\n';
				return 0;
			}
		}
	}

	return 0;
}
