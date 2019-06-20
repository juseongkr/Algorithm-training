#include <iostream>
#include <climits>
using namespace std;
#define MAX 500001

int a[MAX], b[MAX];

int main()
{
	int n, h, x, y;
	int min = INT_MAX;

	cin >> n >> h;
	for (int i=0; i<n/2; ++i) {
		cin >> x >> y;
		b[x]++;
		a[y]++;
	}

	for (int i=h; i>=1; i--) {
		a[i] += a[i+1];
		b[i] += b[i+1];
	}

	int cnt = 1;
	for (int i=1; i<=h; ++i) {
		int t = a[i] + b[h-i+1];
		if (t < min) {
			min = t;
			cnt = 1;
		} else if (t == min) {
			cnt++;
		}
	}

	cout << min << " " << cnt << '\n';

	return 0;
}
