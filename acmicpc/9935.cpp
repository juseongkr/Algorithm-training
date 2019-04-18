#include <iostream>
using namespace std;

int main()
{
	char ret[1000001];
	string str, bomb;
	int len, flag, idx = 0;

	cin >> str >> bomb;
	len = bomb.length();
	for (int i=0; i<str.length(); ++i) {
		ret[idx++] = str[i];
		flag = 0;
		for (int j=0; j<len; ++j) {
			int pos = idx - len + j;
			if (ret[pos] == bomb[j])
				flag++;
		}

		if (flag == len)
			idx -= len;
	}

	if (idx) {
		for (int i=0; i<idx; ++i)
			printf("%c", ret[i]);
		printf("\n");
	} else {
		printf("FRULA\n");
	}

	return 0;
}
