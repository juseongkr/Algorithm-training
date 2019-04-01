#include <iostream>
using namespace std;

class Node {
public:
	char left;
	char right;
};

Node list[100];

void preorder(char r)
{
	if (r == '.')
		return;

	printf("%c", r);
	preorder(list[r].left);
	preorder(list[r].right);
}

void inorder(char r)
{
	if (r == '.')
		return;

	inorder(list[r].left);
	printf("%c", r);
	inorder(list[r].right);
}

void postorder(char r)
{
	if (r == '.')
		return;

	postorder(list[r].left);
	postorder(list[r].right);
	printf("%c", r);
}

int main()
{
	int n;
	char a, b, c;

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		cin >> a >> b >> c;
		list[a].left = b;
		list[a].right = c;
	}

	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	printf("\n");

	return 0;
}
