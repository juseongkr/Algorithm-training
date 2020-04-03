#include <iostream>
using namespace std;
#define MAX 200001

int n, num[MAX], ans[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	ans[0] = num[0];
	int mx = ans[0];
	for (int i=1; i<n; ++i) {
		ans[i] = mx + num[i];
		mx = max(mx, ans[i]);
	}

	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";

	return 0;
}
