#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int array[1001];
	int num;

	cin >> num;
	for (int i=0; i<num; ++i)
		cin >> array[i];

	sort(array, array + num);

	for (int i=0; i<num; ++i)
		cout << array[i] << '\n';

	return 0;
}
