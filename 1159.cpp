#include <iostream>
#include <string.h>
#define fill(a, x)	memset(a, x, sizeof(a))
using namespace std;

int main()
{
	int dict[27];
	int num, flag = 0;
	string str;
	fill(dict, 0);

	cin >> num;

	for (int i=0; i<num; ++i) {
		cin >> str;
		dict[str[0] - 97]++;
	}
	
	for (int i=0; i<27; ++i) {
		if (dict[i] >= 5) {
			printf("%c", i + 97);
			flag = 1;
		}
	}

	if (!flag)
		cout << "PREDAJA\n";

	return 0;
}
