#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1001

int num[MAX];

int main()
{
	string t, s[MAX];
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	for (int i=0; i<n; ++i) {
		cin >> t;
		for (int j=0; j<n; ++j) {
			if (s[j] == t) {
				num[i] = j;
				break;
			}
		}
	}

	int ans = 0;
	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			if (num[i] > num[j]) {
				ans++;
				break;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}
