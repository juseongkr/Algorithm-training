#include <iostream>
using namespace std;

int arr[21][21];
int rm[21][21];

int main()
{
	int n, ret = 0;

	scanf("%d", &n);

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			scanf("%d", &arr[i][j]);

	for (int k=0; k<n; ++k) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (i == j || j == k || k == i)
					continue;

				if (arr[i][j] == arr[i][k] + arr[k][j])
					rm[i][j] = 1;

				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}

	for (int i=0; i<n; ++i)
		for (int j=i; j<n; ++j)
			if (rm[i][j] != 1)
				ret += arr[i][j];

	printf("%d\n", ret);

	return 0;
}
