#include <iostream>
#include <cmath>
using namespace std;
#define MAX 10001

long long x[MAX], y[MAX];

int main()
{
	int n;

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];
	x[n] = x[0];
	y[n] = y[0];

	long long ans = 0;
	for (int i=0; i<n; ++i) {
		ans += x[i] * y[i+1];
		ans -= y[i] * x[i+1];
	}

	cout << abs(ans)/2;
	if (abs(ans) % 2 == 0)
		cout << ".0";
	else
		cout << ".5";

	return 0;
}
