#include <iostream>
using namespace std;
#define MAX 1001

int num[MAX];

int main()
{
	int n, m, u, v;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> u >> v;
		num[u-1]++;
		num[v-1]++;
	}
	for (int i=0; i<n; ++i)
		cout << num[i] << '\n';

	return 0;
}
