class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        if(oldColor == color)
        {
            return image;
        }

        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>> q;

        q.push({sr, sc});
        image[sr][sc] = color;

        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                   image[nr][nc] == oldColor)
                {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};