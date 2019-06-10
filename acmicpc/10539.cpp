#include <iostream>
using namespace std;

int main()
{
	int n, t, sum = 0;
	
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		int ret = (i+1) * t - sum;
		cout << ret << " ";
		sum += ret;
	}

	return 0;
}
