#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int main()
{
	set<string> s;
	char str[1001];

	scanf("%s", str);
	for (int i=1; i<=strlen(str); i++) {
		for (int j=0; j<strlen(str)-i+1; j++) {
			string t(str+j, str+i+j);
			s.insert(t);
		}
	}

	printf("%lu\n", s.size());

	return 0;
}
