#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string dna[1001], ret;
	int dict[27];
	int n, m, pos, max_val, cnt = 0;

	scanf("%d %d", &n, &m);
	for (int i=0; i<n; ++i)
		cin >> dna[i];

	for (int i=0; i<m; ++i) {
		memset(dict, 0, sizeof(dict));
		max_val = 0;
		for (int j=0; j<n; ++j)
			dict[dna[j][i] - 'A'] += 1;

		for (int k=0; k<27; ++k) {
			if (max_val < dict[k]) {
				max_val = dict[k];
				pos = k;
			}
		}
		printf("%c", pos + 'A');
		ret += (pos + 'A');
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (ret[j] != dna[i][j])
				cnt++;
	printf("\n%d\n", cnt);

	return 0;
}
