#include <iostream>
using namespace std;
#define MAX 1000001

int n, m;
int a[MAX], b[MAX], c[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	for (int i=0; i<m; ++i)
		cin >> b[i];

	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}

	while (i < n)
		c[k++] = a[i++];

	while (j < m)
		c[k++] = b[j++];

	for (int i=0; i<n+m; ++i)
		cout << c[i] << " ";
	
	return 0;
}
