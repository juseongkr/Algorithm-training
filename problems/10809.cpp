#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	string str;
	char array[256];

	cin >> str;

	memset(array, -1, 256);
	for (int i=str.size()-1; i>=0; i--)
		array[str[i]] = i;

	for (char i='a'; i<='z'; i++)
		printf("%d ", array[i]);
	cout << '\n';

	return 0;
}
