#include <iostream>
using namespace std;

int main()
{
	int a, b, c;

	for (int i=1000; i<=9999; ++i) {
		a = b = c = 0;
		
		for (int j=i; j>0; j/=10)
			a += (j % 10);

		for (int j=i; j>0; j/=12)
			b += (j % 12);

		for (int j=i; j>0; j/=16)
			c += (j % 16);

		if (a == b && a == c)
			printf("%d\n", i);
	}
	
	return 0;
}
