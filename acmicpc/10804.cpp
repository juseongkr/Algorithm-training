#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num[20];
	int a, b;

	for (int i=0; i<20; ++i)
		num[i] = i+1;

	for (int i=0; i<10; ++i) {
		cin >> a >> b;
		reverse(num+a-1, num+b);
	}

	for (int i=0; i<20; ++i)
		cout << num[i] << " ";

	return 0;
}
