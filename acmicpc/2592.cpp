#include <iostream>
#include <algorithm>
using namespace std;

int num[1001];
int sum, ans, idx, t;

int main()
{

	for (int i=0; i<10; ++i) {
		cin >> t;
		num[t]++;
		sum += t;
	}

	for (int i=0; i<1001; ++i) {
		if (ans < num[i]) {
			ans = num[i];
			idx = i;
		}
	}

	cout << sum/10 << '\n' << idx << '\n';

	return 0;
}
