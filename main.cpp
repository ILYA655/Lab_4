#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef struct Node{
	int Data;
	Node* next;
}Node;

Node* init(int num)
{
	Node* list = (Node*)malloc(sizeof(Node));
	list->Data = num;
	list->next = NULL;
	return list;
}

Node * add(Node* lst, int num)
{
	struct Node *temp, *p;
	temp = (Node*)malloc(sizeof(Node));
	p = lst->next;
	temp->Data = num;
	temp->next = p;
	return temp;
}

int** create(int n)
{
	int** A1, k = 1;
	A1 = (int**)malloc(n * sizeof(int*));
	srand(time(NULL));
	for(int i = 0; i < n; i++)
	{
		A1[i] = (int*)malloc(n * sizeof(int));
		A1[i][i] = 0;
		for (int j = k; j < n; j++)
		{
			if (rand() % 100 > 50)
			{
				A1[i][j] = 0;
			} else{
				A1[i][j] = 1;
			}
		}
		k++;
	}
	k = 1;
	for(int i = 0; i < n; i++)
	{
		for (int j = k; j < n; j++)
		{
			A1[j][i] = A1[i][j];
		}
		k++;
	}

	for (int i = 0; i < n; i++)
		cout << "V" << i + 1 << " ";

	for(int i = 0; i < n; i++)
	{
		cout << "\n";
		for (int j = 0; j < n; j++)
		{
			cout << A1[i][j] << "  ";
		}
	}
	return A1;
}

void DFS(bool* A2, int n, int i, int** A1)
{
	A2[i] = true;
	cout << i + 1 << " ";
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A1[i][j] == 1 && A2[j] == false)
			{
				DFS(A2, n, j, A1);
			}
		}
	}
}

int main()
{
	int n, **t;
	cout << "Enter array size: ";
	//scanf("%d", &n);
	cin >> n;
	bool* A2 = (bool*)malloc(n * sizeof(bool));
	t = create(n);
	cout << "\n";
	for (int i = 0; i < n; i++)
		A2[i] = false;
	cout << "DFS result: ";
	DFS(A2, n, 0, t);

	cout << "\n";
	system("pause");
	for (int i = 0; i < n; i++)
		free(t[i]);
	free(t);
	free(A2);
	return 0;
}
