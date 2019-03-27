#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long double num, l, r;
	long long  sum_r = 0, sum_l = 0;

	cin >> num;
	
	for (long long i=0; i<num; ++i) {
		cin >> l >> r;

		if (long(r) % 2 == 0)
			sum_r = r/2; 
		else
			sum_r = -1 * ceil(r/2);
	
		if (long(l-1) % 2 == 0)
			sum_l = (l-1)/2; 
		else
			sum_l = -1 * ceil((l-1)/2);
	
		cout << sum_r - sum_l << '\n';
	}

	return 0;
}

