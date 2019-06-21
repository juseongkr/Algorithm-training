#include <iostream>
using namespace std;
#define MAX 11

int main()
{
	string num[MAX];
	int n, m;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		for (int j=m-1; j>=0; j--)
			cout << num[i][j];
		cout << '\n';
	}

	return 0;
}
