#include <iostream>
using namespace std;

char cmd[10];
int m, bits, op;

int main()
{
	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		scanf("%s", cmd);
		
		switch (cmd[1]) {
		case 'd':
			scanf("%d", &op);
			bits |= (1 << op);
			break;
		case 'e':
			scanf("%d", &op);
			bits &= ~(1 << op);
			break;
		case 'h':
			scanf("%d", &op);
			if (bits & (1 << op))
				puts("1");
			else
				puts("0");
			break;
		case 'o':
			scanf("%d", &op);
			bits ^= (1 << op);
			break;
		case 'l':
			bits = (1 << 21) - 1;
			break;
		case 'm':
			bits = 0;
			break;
		}
	}

	return 0;
}
