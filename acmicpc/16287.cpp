#include <iostream>
using namespace std;
#define MAX 500001

int w, n;
int num[MAX], ans[800001];

int main()
{
	cin >> w >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			if (num[i] + num[j] < w && ans[w - num[i] - num[j]]) {
				cout << "YES\n";
				return 0;
			}
		}

		for (int j=0; j<i; j++)
			if (num[i] + num[j] < w)
				ans[num[i] + num[j]] = 1;
	}
	cout << "NO\n";

	return 0;
}
