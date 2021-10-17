#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stack> // стек
using namespace std;

typedef struct List{
	int Data;
	List* next;
}List;

List* init(int num)
{
	List* node = (List*)malloc(sizeof(List));
	node->Data = num;
	node->next = NULL;
	return node;
}

List* add(List* lst, int num)
{
	struct List *temp, *p;
	temp = (List*)malloc(sizeof(List));
	p = lst->next;
	temp->Data = num;
	temp->next = p;
	return temp;
}

void steck(int** A1, int n, int i)
{
	stack<int> Stack;
  	int nodes[n]; // вершины графа
  	for (int i = 0; i < n; i++)
		nodes[i] = 0; // исходно все вершины равны 0
	Stack.push(0); // помещаем в очередь первую вершину 
	while (!Stack.empty()) // пока стек не пуст
	{
		int node = Stack.top(); // извлекаем вершину
    	Stack.pop();
    	if (nodes[node] == 2) continue;
    	nodes[node] = 2; // отмечаем ее как посещенную
    	for (int j = n - 1; j >= 0; j--) // проверяем для нее все смежные вершины
    	//for (int j = 0; j < n; j++)
		{
      		if (A1[node][j] == 1 && nodes[j] != 2) // если вершина смежная и не обнаружена
      		{
	    	    Stack.push(j); // добавляем ее в cтек
    		    nodes[j] = 1; // отмечаем вершину как обнаруженную
      		}
    	}
    cout << node + 1 << " "; // выводим номер вершины
	}
	cout << "\n";
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
	cout << "\n";
	cin.get();
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
	//for (i = 0; i < n; i++)
	//{
		for (int j = 0; j < n; j++)
		{
			if (A1[i][j] == 1 && A2[j] == false)
			{
				DFS(A2, n, j, A1);
			}
		}
	//}
}

int main()
{
	int n, **t;
	cout << "Enter array size: ";
	cin >> n;
	bool* A2 = (bool*)malloc(n * sizeof(bool));
	t = create(n);
	cout << "\n";
	for (int i = 0; i < n; i++)
		A2[i] = false;
	cout << "DFS result: ";
	DFS(A2, n, 0, t);

	cout << "\n";
	cout << "Stack result: ";
	steck(t, n, 0);
	system("pause");
	for (int i = 0; i < n; i++)
		free(t[i]);
	free(t);
	free(A2);
	return 0;
}
