#include <iostream>
using namespace std;
#define MAX 51

int n, ans;
int b[MAX];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> b[i];

	while (1) {
		bool flag = true, check = true;
		for (int i=0; i<n; ++i) {
			if (b[i])
				flag = false;

			if (b[i] % 2) {
				ans++;
				b[i] -= 1;
				check = false;
			}
		}

		if (flag)
			break;

		if (check) {
			ans++;
			for (int i=0; i<n; ++i)
				b[i] /= 2;
		}
	}
	cout << ans << '\n';

	return 0;
}
