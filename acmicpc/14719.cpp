#include <iostream>
using namespace std;
#define MAX 501

int n, m, ans;
int block[MAX], L[MAX], R[MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> block[i];

	L[0] = block[0];
	R[m-1] = block[m-1];
	for (int i=1; i<m; ++i) {
		L[i] = max(L[i-1], block[i]);
		R[m-i-1] = max(R[m-i], block[m-i-1]);
	}

	for (int i=1; i<m-1; ++i) {
		int cur = min(L[i], R[i]) - block[i];
		ans += max(cur, 0);
	}
	cout << ans << '\n';

	return 0;
}
