#include <iostream>
using namespace std;

int solve(int n)
{
	int ret = 0;
	while (n > 0) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	string str;
	int n, ans, sum;

	while (cin >> str && str != "0") {
		sum = 0;
		for (int i=0; i<str.length(); ++i)
			sum += str[i] - '0';
		
		ans = solve(sum);
		while (ans > 9)
			ans = solve(ans);

		printf("%d\n", ans);
	}

	return 0;
}
