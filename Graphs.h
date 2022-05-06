#pragma once
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "Matrix.h"
using namespace std;
void setGraph(Matrix* &m, int vertices)
{
    int k=0;
    m->n = (vertices * (vertices + 1))/2 ;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "Vertex A[" << i + 1 << "," << j + 1 << "] : ";
            cin >> m->A[k];
            k++;
        }
    }
}
void DisplayGraph(Matrix* m)
{
    double k = (-1 + sqrt(1 + (8 * m->n))) / 2;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i >= j)
                cout << m->A[((i + 1) * i) / 2 + j] << " ";
            else
                cout << m->A[(j+1)*j/2 + i] << " ";
        }
        cout << "\n";
    }
}
double GetGraph(Matrix* m, int i, int j)
{
    i--;
    j--;
    if (i >= j)
        return m->A[((i + 1) * i) / 2 + j];
    else
        return m->A[((j + 1) * j) / 2 + i];
}
void BFS(Matrix* m,int vertex) {
    Queue* Q = NULL;
    double vertices = (-1 + sqrt(1 + (8 * m->n))) / 2;
    int* visited = new int[int(vertices)] {0};
    cout << vertex << " " << flush;
    visited[vertex-1] = 1;
    enqueue(Q,vertex);
    while (!isEmpty(Q)) 
    {
        long double u = peek(Q);
        dequeue(Q);
        for (int v = 1; v <= vertices; v++) 
        {
            if (GetGraph(m,int(u),v) != 0 && visited[v-1] == 0) 
            {
                cout << v << " " << flush;
                visited[v-1] = 1;
                enqueue(Q,v);
            }
        }
    }
    cout << endl;
}
void DFS(Matrix* m,int vertex) 
{
    int* visited=new int[m->n] { 0 };
    Stack* stk = NULL;
    int u = int(vertex);
    push(stk,u);

    while (!isEmpty(stk)) {
        u = int(peek(stk));
        pop(stk);

        if (visited[u] != 1) {
            cout << u << " " << flush;
            visited[u] = 1;

            for (int v = m->n - 1; v >= 0; v--) {
                if (GetGraph(m,u,v) == 1 && visited[v] == 0) {
                    push(stk,v);
                }
            }
        }
    }
}