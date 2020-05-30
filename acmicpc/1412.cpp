#include <iostream>
using namespace std;
#define MAX 101

int n;
string map[MAX];
bool path[MAX][MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> map[i];

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (map[i][j] == 'Y' && map[j][i] == 'N')
				path[i][j] = 1;

	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				if (path[i][k] && path[k][j])
					path[i][j] = 1;

	for (int i=0; i<n; ++i) {
		if (path[i][i]) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}
