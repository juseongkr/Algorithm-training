#include <iostream>
#include <vector>
using namespace std;
#define MAX 27

int n, m;
string x, y;
bool map[MAX][MAX];

int main()
{
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> x >> y;
		map[x[0]-'a'][y[0]-'a'] = 1;
	}

	for (int k=0; k<MAX; ++k)
		for (int i=0; i<MAX; ++i)
			for (int j=0; j<MAX; ++j)
				if (map[i][k] && map[k][j])
					map[i][j] = 1;

	while (m--) {
		bool ans = true;
		cin >> x >> y;
		if (x.length() != y.length()) {
			cout << "no\n";
			continue;
		}

		if (x != y) {
			for (int i=0; i<x.length(); ++i) {
				int a = x[i]-'a';
				int b = y[i]-'a';
				if (a != b && !map[a][b]) {
					ans = false;
					break;
				}
			}
		}

		if (ans)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
