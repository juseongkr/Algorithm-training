#include <iostream>
using namespace std;

int main()
{
	string str;
	int n;
	
	scanf("%d", &n);

	for (int i=0; i<n; ++i) {
		cin >> str;

		printf("String #%d\n", i+1);
		for (int j=0; j<str.length(); ++j)
			printf("%c", (str[j] - 'A' + 1) % 26 + 'A');
		printf("\n\n");
	}

	return 0;
}
