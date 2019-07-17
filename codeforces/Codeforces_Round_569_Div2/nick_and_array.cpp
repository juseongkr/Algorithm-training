#include <iostream>
using namespace std;
#define MAX 100001

int main()
{
	int n;
	int num[MAX];

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> num[i];
		if (num[i] >= 0)
			num[i] = -num[i]-1;
	}

	if (n % 2 != 0) {
		int min_val = 100000;
		int idx = 0;
		for (int i=0; i<n; ++i) {
			if (num[i] < min_val) {
				idx = i;
				min_val = num[i];
			}
		}
		num[idx] = -num[idx]-1;
	}

	for (int i=0; i<n; ++i)
		cout << num[i] << " ";

	return 0;
}
