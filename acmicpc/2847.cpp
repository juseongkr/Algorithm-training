#include <iostream>
using namespace std;
#define MAX 101

int main()
{
	int num[MAX];
	int n, ans = 0;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> num[i];

	int prev = num[n-1];
	for (int i=n-2; i>=0; i--) {
		while (prev <= num[i]) {
			num[i]--;
			ans++;
		}
		prev = num[i];
	}

	cout << ans << '\n';

	return 0;
}
