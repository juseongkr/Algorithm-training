#include <iostream>
using namespace std;
#define MAX 101

int T, n;
int mat[MAX][MAX], c[MAX], r[MAX];

int main()
{
	cin >> T;
	for (int t=1; t<=T; ++t) {
		cin >> n;
		int trace = 0, row = 0, col = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				cin >> mat[i][j];
				if (i == j)
					trace += mat[i][j];
			}
		}

		for (int i=0; i<n; ++i) {
			fill(r, r+MAX, 0);
			for (int j=0; j<n; ++j) {
				if (++r[mat[i][j]] > 1) {
					row++;
					break;
				}
			}
		}

		for (int i=0; i<n; ++i) {
			fill(c, c+MAX, 0);
			for (int j=0; j<n; ++j) {
				if (++c[mat[j][i]] > 1) {
					col++;
					break;
				}
			}
		}

		cout << "Case #" << t << ": " << trace << " " << row << " " << col << '\n';
	}

	return 0;
}
