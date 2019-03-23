#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	string str;
	int num[100001], len, sum = 0;
	bool flag = false;

	cin >> str;
	len = str.length();
	for (int i=0; i<len; ++i) {
		num[i] = str[i] - '0';
		sum += num[i];
	}

	sort(num, num + len, cmp);

	for (int i=0; i<len; ++i)
		if (num[i] == 0)
			flag = true;

	if (!flag || sum % 3 != 0)
		printf("-1");
	else
		for (int i=0; i<len; ++i)
			printf("%d", num[i]);
	printf("\n");

	return 0;
}
