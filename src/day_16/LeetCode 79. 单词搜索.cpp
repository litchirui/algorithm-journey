class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y){
        if(board[x][y] != word[u]) return false;
        if(u == word.size() - 1) return true;

        // 搜之前先存一下当前位置是什么
        char t = board[x][y];
        board[x][y] = '.'; // 将搜过的位置标记一下
        for(int i = 0; i < 4; i ++){  
            int a = x + dx[i], b = y + dy[i];
            // 越界或被搜索过
            if(a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') 
                continue;
            if(dfs(board, word, u + 1, a, b)) return true;
        }
        board[x][y] = t;  //恢复现场
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // 遍历矩阵中的每个元素作为起点开始搜索
        for(int i = 0; i < board.size(); i ++)
            for(int j = 0; j < board[0].size(); j ++){
                if(dfs(board, word, 0, i, j)) return true;
            }
        return false;
    }
};

// 用st数组判重的写法，效率较慢
//新开bool数组判重的话要注意不要用vector, 另外dfs函数参数要传引用.
/**
对内置类型来说，通常传值更高效。
对用于自定义类型来所，传值要经历构造与析构过程，一般比较耗时。
*/
class Solution2 {
public:
    int n, m;
    vector<vector<bool>> st;

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        st = vector<vector<bool>>(n, vector<bool>(m));

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (dfs(board, word, i, j, 0)) return true; 

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int u)
    {

        if (board[x][y] != word[u]) return false; // 当前字符与目标字符不符，为false
        if (u == word.size() - 1) return true; 

        st[x][y] = true;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b]) 
                if (dfs(board, word, a, b, u + 1)) return true;
        }
        st[x][y] = false; // 恢复现场

        return false; // 四个方向都没有可以选择的，为false
    }
};


class Solutio1n {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y){
        if(board[x][y] != word[u]) return false;
        if(u == word.size() - 1) return true;

        // 搜之前先存一下当前位置是什么
        char t = board[x][y];
        board[x][y] = '.'; // 将搜过的位置标记一下
        for(int i = 0; i < 4; i ++){  
            int a = x + dx[i], b = y + dy[i];
            // 越界或被搜索过
            if(a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') 
                continue;
            if(dfs(board, word, u + 1, a, b)) return true;
        }
        board[x][y] = t;  //恢复现场
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // 遍历矩阵中的每个元素作为起点开始搜索
        for(int i = 0; i < board.size(); i ++)
            for(int j = 0; j < board[0].size(); j ++){
                if(dfs(board, word, 0, i, j)) return true;
            }
        return false;
    }
};

class Solution3 {
public:
    int n, m;
    bool st[7][7];

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();


        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (dfs(board, word, i, j, 0)) return true; 

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int u)
    {

        if (board[x][y] != word[u]) return false; // 当前字符与目标字符不符，为false
        if (u == word.size() - 1) return true; 

        st[x][y] = true;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b]) 
                if (dfs(board, word, a, b, u + 1)) return true;
        }
        st[x][y] = false; // 恢复现场

        return false; // 四个方向都没有可以选择的，为false
    }
};
