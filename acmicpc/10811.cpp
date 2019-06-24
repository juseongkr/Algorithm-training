#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 101

int main()
{
	int num[MAX];
	int n, m, a, b;

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		num[i] = i+1;

	for (int i=0; i<m; ++i) {
		cin >> a >> b;
		reverse(num+a-1, num+b);
	}

	for (int i=0; i<n; ++i)
		cout << num[i] << " ";

	return 0;
}
