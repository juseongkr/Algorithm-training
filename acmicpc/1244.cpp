#include <iostream>
using namespace std;

int main()
{
	int arr[101];
	int n, s, t, k;

	cin >> n;
	for (int i=1; i<=n; ++i) {
		cin >> t;
		if (t == 0)
			arr[i] = -1;
		else
			arr[i] = 1;
	}

	cin >> s;
	for (int i=0; i<s; ++i) {
		cin >> t >> k;
		if (t == 1) {
			for (int j=k; j<=n; j+=k)
				arr[j] *= -1;
		} else {
			if ((k == 1 || k == n) || arr[k-1] != arr[k+1]) {
				arr[k] *= -1;
			} else {
				arr[k] *= -1;
				int l = k-1, r = k+1;
				while (0 < l && r <= n) {
					if (arr[l] == arr[r]) {
						arr[l] *= -1;
						arr[r] *= -1;
						r++;
						l--;
					} else {
						break;
					}
				}
			}
		}
	}

	for (int i=1; i<=n; ++i) {
		if (arr[i] == -1)
			cout << "0 ";
		else
			cout << "1 ";
		if (i % 20 == 0)
			cout << '\n';
	}

	return 0;
}
