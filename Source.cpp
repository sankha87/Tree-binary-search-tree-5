// Binary Search Tree in Data structure (Code Detail Explanation) Algorithm		https://www.youtube.com/watch?v=krBOwizyRe0&t=18s
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}*root;

void inorder_recursive(Node*);
void createBST(int);

void main()
{
	int n;
	printf("Enter the no of nodes : ");
	scanf("%d", &n);
	createBST(n);

	printf("\n\nInorder traversal : ");
	inorder_recursive(root);
	_getch();
}

void createBST(int n)
{
	int i, item;
	struct Node *p, *q;

	for (i = 0; i < n; i++)
	{
		p = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter the value of node %d : ", i + 1);
		scanf("%d", &item);
		p->data = item;
		p->left = NULL;
		p->right = NULL;

		if (i == 0)
			root = p;
		else
		{
			q = root;
			while (1)
			{
				if (p->data > q->data)
				{
					if (q->right == NULL)
					{
						q->right = p;
						break;
					}
					else
						q = q->right;
				}

				else
				{
					if (q->left == NULL)
					{
						q->left = p;
						break;
					}
					else
						q = q->left;
				}
			}
		}
	}
}

void inorder_recursive(struct Node *root)
{
	if (root == NULL)
		return;
	else
	{
		inorder_recursive(root->left);
		printf("%d ", root->data);
		inorder_recursive(root->right);
	}
}