// C++ program to print right view of
// Binary Tree

#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left, *right;
};
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
void printRightView(Node* root)
{
	if (!root)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		int n = q.size();
		for(int i = 1; i <= n; i++)
		{
			Node* temp = q.front();
			q.pop();
			if (i == n)
				cout<<temp->data<<" ";
			if (temp->left != NULL)
				q.push(temp->left);
			if (temp->right != NULL)
				q.push(temp->right);
		}
	}
}
int main()
{
 
    Node* root = newNode(101);
    root->left = newNode(21);
    root->right = newNode(13);
    root->left->left = newNode(71);
    root->left->right = newNode(8);
    root->right->right = newNode(115);
    root->right->left = newNode(120);
    root->right->right->left = newNode(114);
    printRightView(root);
}


