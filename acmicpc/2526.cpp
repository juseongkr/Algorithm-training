#include <iostream>
using namespace std;
#define MAX 100

int d[MAX];

int main()
{
	int n, p;

	cin >> n >> p;
	int N = n;
	int ans = 0;
	for (int i=0; i<1000000; ++i) {
		int t = N * n;
		t %= p;
		if (d[t] == 2)
			ans++;
		d[t]++;
		n = t;
	}
	cout << ans << '\n';

	return 0;
}
