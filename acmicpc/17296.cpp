#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double A;
	int n, step = 0;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> A;
		if (A > 0) {
			if (step)
				step += floor(A);
			else
				step += ceil(A);
		}
	}
	cout << step << '\n';

	return 0;
}
