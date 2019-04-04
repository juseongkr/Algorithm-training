#include <iostream>
using namespace std;

int main()
{
	int n, m, v, max_val = 1;
	int s[51][51];
	string str;

	scanf("%d %d", &n, &m);
	v = min(n, m);
	for (int i=0; i<n; ++i) {
		cin >> str;
		for (int j=0; j<m; ++j)
			s[i][j] = str[j] - '0';
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			for (int k=1; k<v; ++k) {
				if (n <= i + k || m <= j + k)
					continue;

				if (s[i][j] == s[i+k][j] && s[i][j] == s[i][j+k] && s[i][j] == s[i+k][j+k])
					max_val = max(max_val, (k + 1) * (k + 1));
			}
		}
	}
	printf("%d\n", max_val);

	return 0;
}
