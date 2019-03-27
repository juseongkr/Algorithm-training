#include <iostream>
using namespace std;

int main()
{
	int n, k, t, sum = 0, idx = 0;
	int fence[1500000] = {0, };

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> fence[i];
		if (i < k)
			sum += fence[i];
	}
	
	t = sum;
	for (int i=1; i<=n-k; ++i) {
		sum -= fence[i-1];
		sum += fence[i+k-1];

		if (sum < t) {
			t = sum;
			idx = i;
		}
	}
	
	cout << idx + 1 << '\n';

	return 0;
}
