#include <iostream>
using namespace std;
#define MAX 16

long long n, w, cnt;
long long val[MAX];

int main()
{
	cin >> n >> w;
	for (int i=0; i<n; ++i)
		cin >> val[i];

	for (int i=0; i<n-1; ++i) {
		if (val[i] < val[i+1]) {
			cnt = (w / val[i]) * val[i+1];
			w = (w % val[i]) + cnt;
		}
	}
	cout << w << '\n';

	return 0;
}
