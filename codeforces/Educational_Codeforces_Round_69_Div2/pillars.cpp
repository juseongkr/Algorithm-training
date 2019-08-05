#include <iostream>
using namespace std;
#define MAX 200002

int n, idx;
int a[MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		if (a[i] > a[idx])
			idx = i;
	}

	for (int i=0; i<idx; ++i) {
		if (a[i] > a[i+1]) {
			cout << "NO\n";
			return 0;
		}
	}

	for (int i=idx+1; i<n; ++i) {
		if (a[i-1] < a[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}
