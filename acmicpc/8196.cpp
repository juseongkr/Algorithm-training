#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000001
const int INF = 1e9+7;

int n;
int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	sort(num, num+n);

	int ans = num[0];
	for (int i=0; i<n; ++i)
		ans = max(ans, num[i+1] - ans);

	cout << ans << '\n';

	return 0;
}
