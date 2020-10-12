#include <iostream>
using namespace std;
#define MAX 31

int n, m;
int c[MAX][MAX];

int main()
{
	cin >> n >> m;

	c[0][0] = 1;
	for (int i=1; i<MAX; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j=1; j<i; ++j)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}

	cout << c[n-1][m-1] << '\n';

	return 0;
}
