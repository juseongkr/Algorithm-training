#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int red, blue;

	scanf("%d %d", &red, &blue);
	
	printf("%d %d\n", min(red, blue), abs(red-blue)/2);

	return 0;
}
