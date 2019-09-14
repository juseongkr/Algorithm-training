#include <iostream>
using namespace std;
#define MAX 100001
#define INF 1000000001*2

int num[MAX];

int main()
{
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int L, R;
	int mx = INF;
	int l = 0, r = n-1;
	while (l < r) {
		int sum = num[l] + num[r];
		if (mx > abs(sum)) {
			mx = abs(sum);
			L = l;
			R = r;
		}

		if (sum < 0)
			l++;
		else if (sum > 0)
			r--;
		else
			break;
	}
	cout << num[L] << " " << num[R] << '\n';

	return 0;
}
