#include <iostream>
using namespace std;

int main()
{
	long long memo[1000001];
	long long num;

	cin >> num;

	memo[0] = 0;
	memo[1] = 0;
	memo[2] = 1;
	memo[3] = 1;
	
	for (int i=4; i<=num; ++i) {
		if (i % 3 == 0)
			memo[i] = min(memo[i/3] + 1, memo[i-1] + 1);
		else if (i % 2 == 0)
			memo[i] = min(memo[i/2] + 1, memo[i-1] + 1);
		else
			memo[i] = memo[i-1] + 1;
	}

	cout << memo[num] << '\n';

	return 0;
}
