/*#include <iostream>
#include <stack> // стек
using namespace std;
int main()
{
  stack<int> Stack;
  int mas[7][7] = { 
    { 0, 1, 1, 0, 0, 0, 1 }, // матрица смежности
    { 1, 0, 1, 1, 0, 0, 0 },
    { 1, 1, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 0 } 
  };
  int nodes[7]; // вершины графа
  for (int i = 0; i < 7; i++) // исходно все вершины равны 0
    nodes[i] = 0;
  Stack.push(0); // помещаем в очередь первую вершину
  while (!Stack.empty())
  { // пока стек не пуст
    int node = Stack.top(); // извлекаем вершину
    Stack.pop();
    if (nodes[node] == 2) continue;
    nodes[node] = 2; // отмечаем ее как посещенную
    for (int j = 6; j >= 0; j--)
    { // проверяем для нее все смежные вершины
      if (mas[node][j] == 1 && nodes[j] != 2)
      { // если вершина смежная и не обнаружена
        Stack.push(j); // добавляем ее в cтек
        nodes[j] = 1; // отмечаем вершину как обнаруженную
      }
    }
    cout << node + 1 << endl; // выводим номер вершины
  }
  cin.get();
  return 0;
}*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
//using namespace std;

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
		printf("V%d ", i + 1);

	for(int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", A1[i][j]);
		}
	}
	return A1;
}

void DFS(bool* A2, int n, int i, int** A1)
{
	A2[i] = true;
	printf("%d ", i + 1);
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
	printf("Vvedite razmer array: ");
	scanf("%d", &n);
	bool* A2 = (bool*)malloc(n * sizeof(bool));
	t = create(n);
	printf("\n");
	for (int i = 0; i < n; i++)
		A2[i] = false;
	printf("Rezultat obhoda: ");
	DFS(A2, n, 0, t);

	printf("\n");
	system("pause");
	for (int i = 0; i < n; i++)
		free(t[i]);
	free(t);
	free(A2);
	return 0;
}
