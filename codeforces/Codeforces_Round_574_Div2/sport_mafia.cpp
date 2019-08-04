#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1000000001

int n, k, t;

int main()
{
	cin >> n >> k;
	for (int i=0; i<MAX; ++i) {
		t += i;
		if (t == n + k - i) {
			cout << n - i << '\n';
			return 0;
		}
	}
	return 0;
}
