#include <iostream>
using namespace std;
#define MAX 100001

int s[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int n, m, a, b;

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		s[a]++;
		s[b]++;
	}

	for (int i=1; i<=n; ++i)
		cout << s[i] << '\n';

	return 0;
}
