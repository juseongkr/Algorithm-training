#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	long long n, s, cnt = 0;

	scanf("%lld %lld", &n, &s);

	while (s > 0) {
		s -= n;
		cnt++;
	}

	printf("%lld\n", cnt);

	return 0;
}
