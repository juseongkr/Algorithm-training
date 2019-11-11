#include <iostream>
using namespace std;
#define MAX 65

bool map[MAX][MAX];

int main()
{
	int n, t;

	cin >> n;
	map[0][0] = 1;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> t;
			if (map[i][j]) {
				if (i + t < n)
					map[i+t][j] = 1;
				if (j + t < n)
					map[i][j+t] = 1;
			}
		}
	}

	if (map[n-1][n-1])
		cout << "HaruHaru\n";
	else
		cout << "Hing\n";

	return 0;
}
