#include "mySharedPtr.h"
#include <iostream>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

int main() {
	mySharedPtr<int> p1(1);
	{
		mySharedPtr<int> p2 = p1;
		cout << p1.use_count() << endl;
	}
	cout << p1.use_count() << endl;
	cout << *p1 << endl;

	mySharedPtr<TreeNode> pt(TreeNode(78));
	cout << pt->val << endl;
	cout << pt.use_count() << endl;
    return 0;
}
