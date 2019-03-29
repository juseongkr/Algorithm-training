#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	int num[3];

	for (int i=0; i<3; ++i)
		scanf("%d", &num[i]);

	sort(num, num+3);
	
	cin >> str;
	for (int i=0; i<str.length(); ++i)
		printf("%d ", num[str[i] - 'A']);
	printf("\n");

	return 0;
}
