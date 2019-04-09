#include <iostream>
using namespace std;

int d[10];

int find(int num)
{
	string s = to_string(num);
	for (int i=0; i<s.length(); ++i) {
		if (d[s[i]-'0'] != 0)
			return 0;
	}
	return s.length();
}

int main()
{
	int n, m, t, ret;

	scanf("%d %d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d", &t);
		d[t] = 1;
	}

	ret = abs(n - 100);
	for (int i=0; i<=500000*2; ++i) {
		int len = find(i);
		if (len != 0)
			ret = min(ret, abs(n-i) + len);
	}

	printf("%d\n", ret);
	
	return 0;
}
