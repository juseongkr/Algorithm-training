#include <iostream>
using namespace std;
#define MAX 51

string map[MAX];
int x[MAX], y[MAX];
int n, m, a, b;

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (map[i][j] == 'X')
				y[i] = x[j] = 1;

	for (int i=0; i<n; ++i)
		if (y[i] == 0)
			a++;

	for (int i=0; i<m; ++i)
		if (x[i] == 0)
			b++;

	cout << max(a, b) << '\n';

	return 0;
}
