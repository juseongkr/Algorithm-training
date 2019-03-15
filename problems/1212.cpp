#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int len;
	char first[10][4] = {"0", "1", "10", "11", "100", "101", "110", "111"};
	char binary[10][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
	char num[333335];
	
	cin >> num;
	len = strlen(num);
	
	cout << first[num[0] - 48];
	for (int i=1; i<len; ++i)
		cout << binary[num[i] - 48]; 
	cout << '\n';

	return 0;
}
