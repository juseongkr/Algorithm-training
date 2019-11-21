#include <iostream>
using namespace std;
#define MAX 200001

int num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, v, k;

	cin >> n >> m >> v;
	v--;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<m; ++i) {
		cin >> k;
		if (k < v)
			cout << num[k] << '\n';
		else
			cout << num[v + (k-v) % (n-v)] << '\n';
	}

	return 0;
}
