#include <iostream>
using namespace std;
#define MAX 1001

int num[MAX];
int n, c, w, ans, mx;

int main()
{
	cin >> n >> c >> w;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		mx = max(mx, num[i]);
	}

	for (int i=mx; i>0; i--) {
		int sum = 0;
		for (int j=0; j<n; ++j) {
			if (num[j] < i)
				continue;

			int k = num[j] / i;
			int p = 0;
			if (num[j] % i == 0)
				p = (num[j] / i) - 1;
			else
				p = num[j] / i;

			int val = k * w * i - p * c;
			if (val > 0)
				sum += val;
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';

	return 0;
}
