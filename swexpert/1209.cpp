#include <iostream>
using namespace std;

int mat[101][101];

int main()
{
	int d;
	
	for (int t=1; t<=10; ++t) {
		cin >> d;

		int sum = 0, ans = 0;
		for (int i=0; i<100; ++i)
			for (int j=0; j<100; ++j)
				cin >> mat[i][j];

		for (int i=0; i<100; ++i) {
			for (int j=0; j<100; ++j) {
				sum += mat[i][j];
			}
			ans = max(ans, sum);
			sum = 0;
		}

		for (int i=0; i<100; ++i) {
			for (int j=0; j<100; ++j) {
				sum += mat[j][i];
			}
			ans = max(ans, sum);
			sum = 0;
		}

		for (int i=0; i<100; ++i) {
			sum += mat[i][i];
			ans = max(ans, sum);
		}

		sum = 0;
		for (int i=0; i<100; ++i) {
			sum += mat[i][99-i];
			ans = max(ans, sum);
		}
		cout << "#" << t << " " << ans << '\n';
	}

	return 0;
}
