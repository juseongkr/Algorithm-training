#include <iostream>
using namespace std;
#define MAX 101

int n, k, t;
int gate[MAX];

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> t;
		bool flag = false;
		for (int j=0; j<k; ++j) {
			if (gate[j] < t) {
				gate[j] = t;
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}
