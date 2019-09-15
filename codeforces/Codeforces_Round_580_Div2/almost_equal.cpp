#include <iostream>
#include <vector>
using namespace std;
#define MAX 200002

long long num[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;
	if (n % 2 == 0) {
		cout << "NO\n";
		return 0;
	} else {
		cout << "YES\n";
		long long l = 1, r = 2*n;
		for (int i=0; i<n; ++i) {
			if (i % 2) {
				num[i] = l++;
				num[i+n] = l++;
			} else {
				num[i] = r--;
				num[i+n] = r--;
			}
		}
		for (int i=0; i<n*2; ++i)
			cout << num[i] << " ";
	}

	return 0;
}
