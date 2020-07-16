#include <iostream>
using namespace std;
#define MAX 1001

int T, n;
int num[MAX];

int main()
{
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> num[i];

		bool flag = false;
		for (int i=0; i<n; ++i) {
			int mid = 0;
			for (int j=i; j<n; ++j) {
				if (!mid && num[i] < num[j])
					mid = j;
				if (mid && num[mid] > num[j]) {
					flag = true;
					cout << "YES\n" << i+1 << " " << mid+1 << " " << j+1 << '\n';
					break;
				}
			}
			if (flag)
				break;
		}
		if (!flag)
			cout << "NO\n";
	}

	return 0;
}
