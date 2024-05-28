class Solution {
public:
    int m,n;

    void dfs(int i,int j,vector<vector<int>>& image,int startcolor,int newcolor){
        if(i<0 || j<0 || i>=m || j>=n || image[i][j] != startcolor){
            return;
        }

        image[i][j] = newcolor;

        dfs(i+1,j,image,startcolor,newcolor);
        dfs(i-1,j,image,startcolor,newcolor);
        dfs(i,j+1,image,startcolor,newcolor);
        dfs(i,j-1,image,startcolor,newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        m = image.size();
        n = image[0].size();

        int startcolor = image[sr][sc];
        if(startcolor != newcolor){
            dfs(sr,sc,image,startcolor,newcolor);
        }
        return image;
    }
};