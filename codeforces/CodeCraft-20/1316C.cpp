#include <iostream>
using namespace std;
#define MAX 1000001

int n, m, p;
int a[MAX], b[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> p;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<m; ++i)
		cin >> b[i];

	int l = 0;
	for (int i=0; i<n; ++i) {
		if (a[i] % p != 0) {
			l = i;
			break;
		}
	}

	int r = 0;
	for (int i=0; i<m; ++i) {
		if (b[i] % p != 0) {
			r = i;
			break;
		}
	}
	cout << l + r << '\n';

	return 0;
}
