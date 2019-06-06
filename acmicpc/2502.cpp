#include <iostream>
using namespace std;

int fibo[31];

int main()
{
	int d, k;

	cin >> d >> k;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i=3; i<=d; ++i)
		fibo[i] = fibo[i-1] + fibo[i-2];

	int a = fibo[d-2];
	int b = fibo[d-1];

	int t = 1;
	while (1) {
		if ((k-a*t)%b == 0) {
			int n = (k-a*t)/b;
			cout << t << '\n' << n;
			break;
		}
		t++;
	}

	return 0;
}
