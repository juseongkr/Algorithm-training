#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int num, t;
	string str;

	scanf("%d", &num);
	for (int i=0; i<num; ++i) {
		cin >> t >> str;
		for (int j=0; j<str.size(); ++j)
			for (int k=0; k<t; ++k)
				printf("%c", str[j]);
		printf("\n");
	}
	return 0;
}
