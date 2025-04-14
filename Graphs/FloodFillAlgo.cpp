
//https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int rows[]={-1,0,1,0};
        int columns[]={0,1,0,-1};
        queue<pair<int,int>> pq;
        pq.push({sr,sc});
        int givenColour=image[sr][sc];
        image[sr][sc]=newColor;
        visited[sr][sc]=true;
        
        while(!pq.empty()){
            int r=pq.front().first;
            int c=pq.front().second;
            pq.pop();
            for(int i=0;i<4;i++){
                int newR=rows[i]+r;
                int newC=columns[i]+c;
                if(newR>=0&&newR<n&&newC>=0&&newC<m&&visited[newR][newC]==false&&image[newR][newC]==givenColour){
                     pq.push({newR,newC}); 
                   visited[newR][newC]=true;
                    image[newR][newC]=newColor;
                }
                
            }
            
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
