#include <stdio.h>
#include <limits.h>

#define MAX 15

void readInput(int *n, int latency[MAX][MAX]) {
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            scanf("%d", &latency[i][j]);
        }
   } 
}

int calculateLatency(int n, int latency[MAX][MAX], int path[]) {
    int laten=0;
    for(int i=0 ; i<n-1; i++)
    {
        laten+=latency[path[i]][path[i+1]];
    }
    laten+=latency[path[n-1]][path[0]];
    return laten;
}
void backtrack(int n,int *minLatency, int latency[MAX][MAX], int visited[], int path[], int level);

void generatePermutations(int n, int *minLatency, int latency[MAX][MAX]) {
//    *minLatency =0;
    int path[MAX], visited[MAX]={0};
        
    for(int i =0; i<n;i++)
    {
        path[0]=i;
        visited[i]=1;
        backtrack(n, minLatency, latency, visited, path, 1);
        visited[i]=0;
    }
    
}
void backtrack(int n,int *minLatency, int latency[MAX][MAX], int visited[], int path[], int level)
  {
      if (level==n)
      {
          int temp =calculateLatency(n, latency, path);
          if (temp < *minLatency)
          {
              *minLatency = temp;
          }
              return;
      }
    for (int i = 0; i<n; i++)
    {   
        if(!visited[i])
    {
        path[level]=i;
        visited[i]=1;
        backtrack(n, minLatency, latency, visited, path, level+1);
        visited[i]=0;
    }
    }
                                                                  }

int main() {
    int n;
    int latency[MAX][MAX];
    int minLatency = INT_MAX; 

    readInput(&n, latency);

    generatePermutations(n, &minLatency, latency);

    printf("%d\n", minLatency);

    return 0;
}
