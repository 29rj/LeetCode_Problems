// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.


bool isAlright(bool graph[101][101],int node, int N, int col,int colored[]){
    
    for(int i=0;i<N;i++){
        if(node != i && graph[node][i] == 1 && colored[i] == col)
            return false;
    }
    
    return true;
}


bool helper(bool graph[101][101],int M,int N,int node,int colored[]) {
    
    if(node == N)
        return true;
    
    for(int i=1;i<=M;i++){
        
        if(isAlright(graph,node,N,i,colored)){
            
            colored[node] = i;
            
            if(helper(graph,M,N,node+1,colored))
                return true;
                
            colored[node] = 0;
            
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int M, int N)
{
   int colored[N];
    
   for(int i=0;i<N;i++){
       colored[i] = 0;
   }
    
   return helper(graph,M,N,0,colored);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends