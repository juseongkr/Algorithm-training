#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAX 2001

int n, m;
int a[MAX], b[MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<n; ++i)
		cin >> b[i];

	sort(a, a+n);
	sort(b, b+n);

	int ans = 1e9+7;
	for (int i=0; i<n; ++i) {
		set<int> st;
		for (int j=0; j<n; ++j) {
			int d = (b[(i+j)%n] - a[j] + m) % m;
			st.insert(d);
		}
		if (st.size() == 1)
			ans = min(ans, *st.begin());
	}
	cout << ans << '\n';

	return 0;
}
