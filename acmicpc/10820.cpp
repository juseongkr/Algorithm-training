#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char str[102];
	while (fgets(str, sizeof(str), stdin) != NULL) {
		int a = 0, b = 0, c = 0, d = 0;
		str[strlen(str)-1] = '\0';

		for (int i=0; i<strlen(str); ++i) {
			if ('a' <= str[i] && str[i] <= 'z')
				a++;
			else if ('A' <= str[i] && str[i] <= 'Z')
				b++;
			else if ('0' <= str[i] && str[i] <= '9')
				c++;
			else if (str[i] == ' ')
				d++;
		}
		printf("%d %d %d %d\n", a, b, c, d);
	}

	return 0;
}
