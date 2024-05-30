class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>>& image, int i, int j, int startcolor,int color){
        if(i<0 || j<0 || i>=m || j>=n || image[i][j] != startcolor){
            return;
        }
        image[i][j] = color;

        dfs(image,i+1,j,startcolor,color);
        dfs(image,i-1,j,startcolor,color);
        dfs(image,i,j+1,startcolor,color);
        dfs(image,i,j-1,startcolor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();

        int startcolor = image[sr][sc];

        if(startcolor != color){
            dfs(image,sr,sc,startcolor,color);
        }
        return image;
    }
};