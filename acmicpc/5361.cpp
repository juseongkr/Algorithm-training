#include <iostream>
using namespace std;

int main()
{
	double dict[5] = {350.34, 230.9, 190.55, 125.3, 180.9};
	double n, sum;
	int t;

	cin >> t;
	while (t--) {
		sum = 0;
		for (int i=0; i<5; ++i) {
			cin >> n;
			sum += dict[i] * n;
		}
		printf("$%.2f\n", sum);

	}
	return 0;
}
