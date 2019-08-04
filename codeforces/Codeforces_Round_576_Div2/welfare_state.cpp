#include <iostream>
using namespace std;
#define MAX 200001

int n, q, t, x, y;
int a[MAX], pos[MAX], mx[MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];

	cin >> q;
	for (int i=0; i<q; ++i) {
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			a[x-1] = y;
			pos[x-1] = i;
		} else {
			cin >> mx[i];
		}
	}
	for (int i=q-1; i>=0; i--)
		mx[i] = max(mx[i], mx[i+1]);

	for (int i=0; i<n; ++i)
		cout << max(a[i], mx[pos[i]]) << " ";
	cout << '\n';

	return 0;
}
