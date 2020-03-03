#include <iostream>
using namespace std;
#define MAX 251

int n;
int map[MAX][MAX], ans[MAX][MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];

	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (map[i][k] && map[k][j])
					ans[i][j]++;

	long long ret = 0;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (i != j)
				ret += ans[i][j] * (ans[i][j] - 1);

	cout << ret << '\n';

	return 0;
}
