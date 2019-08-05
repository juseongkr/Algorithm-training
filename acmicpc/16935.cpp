#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int n, m, r, o;
int a[MAX][MAX], ans[MAX][MAX];

void func1()
{
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			ans[i][j] = a[n-1-i][j];
}

void func2()
{
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			ans[i][j] = a[i][m-1-j];
}

void func3()
{
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			ans[i][j] = a[n-1-j][i];
}

void func4()
{
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			ans[i][j] = a[j][m-1-i];
}

void func5()
{
	for (int i=0; i<n/2; ++i) {
		for (int j=0; j<m/2; ++j) {
			ans[i][j] = a[i+n/2][j];
			ans[i][j+m/2] = a[i][j];
			ans[i+n/2][j] = a[i+n/2][j+m/2];
			ans[i+n/2][j+m/2] = a[i][j+m/2];
		}
	}
}

void func6()
{
	for (int i=0; i<n/2; ++i) {
		for (int j=0; j<m/2; ++j) {
			ans[i][j] = a[i][j+m/2];
			ans[i][j+m/2] = a[i+n/2][j+m/2];
			ans[i+n/2][j] = a[i][j];
			ans[i+n/2][j+m/2] = a[i+n/2][j];
		}
	}
}

int main()
{

	cin >> n >> m >> r;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> a[i][j];

	while (r--) {
		cin >> o;
		switch (o) {
		case 1:
			func1();
			break;
		case 2:
			func2();
			break;
		case 3:
			func3();
			swap(n, m);
			break;
		case 4:
			func4();
			swap(n, m);
			break;
		case 5:
			func5();
			break;
		case 6:
			func6();
			break;
		}

		for (int i=0; i<MAX; ++i)
			for (int j=0; j<MAX; ++j)
				a[i][j] = ans[i][j];

	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			cout << ans[i][j] << " ";
		cout << '\n';
	}

	return 0;
}
