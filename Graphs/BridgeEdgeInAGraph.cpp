//https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void constructAdj(int V, vector<vector<int>> &edges, int c, int d,vector<vector<int>>& adjMat){
        for(int i=0;i<edges.size();i++){
            if((edges[i][0]==c&&edges[i][1]==d)||edges[i][0]==d&&edges[i][1]==c){
                continue;
            }else{
                adjMat[edges[i][0]].push_back(edges[i][1]);
                adjMat[edges[i][1]].push_back(edges[i][0]);
            }
        }        
    }
    void dfs(vector<vector<int>>& adjMat,int c,vector<int>& visited){
        visited[c]=1;
        for(int i:adjMat[c]){
            if(visited[i]!=1){
                dfs(adjMat,i,visited);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adjMat(V);
        constructAdj(V,edges,c,d,adjMat);
        vector<int> visited(V,0);
        dfs(adjMat,c,visited);
        if(visited[d]==0){
            return true;
        }else{
            return false;
        }
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
