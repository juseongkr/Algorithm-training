#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{	
	int num;
	int h, w, n;
	
	cin >> num;
	for (int i=0; i<num; ++i) {
		cin >> h >> w >> n;
		
		printf("%d%02d\n", (n-1) % h + 1, (n-1) / h + 1);
	}
	
	return 0;
}
