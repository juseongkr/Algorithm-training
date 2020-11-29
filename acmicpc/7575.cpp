#include <iostream>
using namespace std;
#define MAX 1001

int n, k;
int s[MAX], b[MAX], len[101], num[101][MAX*2], fail[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> k >> len[0];
	for (int i=0; i<len[0]; ++i)
		cin >> s[i];

	for (int i=1; i<n; ++i) {
		cin >> len[i];
		for (int j=0; j<len[i]; ++j) {
			cin >> num[i][j];
			num[i][len[i]*2-j] = num[i][j];
		}
		len[i] = 2*len[i]+1;
	}

	for (int it=0; it<=len[0]-k; ++it) {
		for (int j=0; j<k; ++j)
			b[j] = s[j+it];

		for (int i=1, j=0; i<k; ++i) {
			while (j && b[i] != b[j])
				j = fail[j-1];

			if (b[i] == b[j])
				fail[i] = ++j;
		}

		bool flag = true;
		for (int t=1; t<n; ++t) {
			if (!flag)
				break;

			flag = false;
			for (int i=0, j=0; i<len[t]; ++i) {
				while (j && num[t][i] != b[j])
					j = fail[j-1];

				if (num[t][i] == b[j]) {
					if (j == k-1) {
						flag = true;
						break;
					} else {
						j++;
					}
				}
			}

		}

		if (flag) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";

	return 0;
}
