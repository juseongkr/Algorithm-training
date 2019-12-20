#include <iostream>
using namespace std;
#define MAX 200001

int in[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, x, y;

	cin >> n;
	for (int i=0; i<n-1; ++i) {
		cin >> x >> y;
		in[x]++;
		in[y]++;
	}

	int ans = 1;
	for (int i=0; i<n; ++i)
		if (in[i] == 1)
			ans++;
	cout << ans / 2 << '\n';

	return 0;
}
