#include <iostream>
using namespace std;
#define MAX 1000001

int n, a, b, c, ans;
bool ck[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> c;
		if (!ck[a] && !ck[b] && !ck[c])
			ans++;
		ck[a] = ck[b] = ck[c] = 1;
	}
	cout << ans << '\n';

	return 0;
}
