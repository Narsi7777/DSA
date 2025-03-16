// https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1



class Solution {
  public:
    int rows[4]={-1,0,1,0};
    int columns[4]={0,1,0,-1};
    
    void dfs(vector<vector<char>>& mat,int i,int j,int n,int m){
        if(i<0||i>=n||j<0||j>=m){
            return;
        }  
        mat[i][j]='#';
        for(int k=0;k<4;k++){
            int newR=i+rows[k];
            int newC=j+columns[k];
            if(newR>=0&&newR<n&&newC>=0&&newC<m&&mat[newR][newC]=='O'){
                dfs(mat,newR,newC,n,m);
            }
        }
        
    }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O'){
                dfs(mat,0,i,n,m);    
            }
            
        }
        for(int i=0;i<n;i++){
            if(mat[i][m-1]=='O'){
                dfs(mat,i,m-1,n,m);    
            }
        }
        for(int i=0;i<m;i++){
            if(mat[n-1][i]=='O'){
                dfs(mat,n-1,i,n,m);    
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'){
                dfs(mat,i,0,n,m);    
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='#'){
                    mat[i][j]='O';
                }else if(mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

