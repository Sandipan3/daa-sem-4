#include <stdio.h>
#include <stdlib.h>

int** graph;
int* visited;
int vertex;
int isDirected;

void initialize(int a , int b){
    vertex = a;
    isDirected = b;

    graph =(int**)malloc(vertex * sizeof(int*));
    for(int i = 0 ; i < vertex ; i++ ){
        graph[i] = (int*)calloc(vertex , sizeof(int));
    }
    visited = (int*)calloc(vertex , sizeof(int));
}

void addEdge(int src , int dest , int weight){
    graph[src][dest] = weight ;
    if(!isDirected)     graph[dest][src] = weight ;
}

void printGraph(){
    printf("Adj Matrix : \n");
    for(int i = 0 ; i < vertex ; i++){
        for(int j = 0 ; j < vertex ;j++ ){
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void bfs(int node){
    int* queue = (int*)malloc(vertex * sizeof(int));
    int rear = 0;  int front = 0;
    visited[node] = 1;
    queue[rear++] = node;
    while (front < rear)
    {
        int current  =  queue[front++];
        printf("%d\t",current);

        for (int i = 0; i < vertex; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main(){

     // Example graph:
    //       0
    //     /  \
    //    1    2
    //   / \  / \
    //  3  4 5   6

    initialize(7,0);

    addEdge(0 , 1 , 1);
    addEdge(0 , 2 , 1);
    addEdge(1 , 3 , 1);
    addEdge(1 , 4 , 1);
    addEdge(2 , 5 , 1);
    addEdge(2 , 6 , 1);

    printGraph();

    printf("DFS: \n");
    bfs(0);

    return 0;
}