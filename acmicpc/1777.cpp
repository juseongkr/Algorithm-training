#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 100001

int a[MAX], b[MAX];

int main()
{
	vector<int> v;
	int n;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> a[i];
		v.push_back(i);
	}

	for (int i=n; i>0; i--) {
		b[v[a[i]]] = i;
		v.erase(v.begin() + a[i]);
	}

	for (int i=n; i>0; i--)
		cout << b[i] << " ";

	return 0;
}
