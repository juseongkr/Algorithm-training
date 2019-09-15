#include <iostream>
using namespace std;
#define MAX 101

int a[MAX], b[MAX], d[401];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		d[a[i]]++;
	}

	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> b[i];
		d[b[i]]++;
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (d[a[i]+b[j]] == 0) {
				cout << a[i] << " " << b[j] << '\n';
				return 0;
			}
		}
	}

	return 0;
}
