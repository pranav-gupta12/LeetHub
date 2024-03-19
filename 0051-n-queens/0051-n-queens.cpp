class Solution {
public:
    // bool IsSafe(int row, int col,vector<vector<string>> &board, int n ){
    //     // for row
    //     for(int i= col;i>=0;i--){
    //         if(board[row][i]!=".") return false;
    //     }
    //     // upper diagonal
    //     int i = row, j = col;
    //     while(i>=0 && j>=0 ){
    //         if(board[i--][j--]!= ".") return false;
    //     }
    //     while(row<n && col>=0 ){
    //         if(board[row++][col--]!= ".") return false;
    //     }
    //     return true;
    // }
//      void add(vector<vector<string>>& ans, vector<vector<string>>& board, int n) {
//         vector<string> temp;
//         for (int i = 0; i < n; i++) {
//             string row;
//             for (int j = 0; j < n; j++) {
//                 row += board[i][j];
//             }
//             temp.push_back(row);
//         }
//         ans.push_back(temp);
//     }
    
//     void solve(int col,vector<vector<string>> &ans, vector<vector<string>> &board, int n,  unordered_map<int,bool> &rowMap,
//         unordered_map<int,bool> &upperDiagonal,
//         unordered_map<int,bool> &lowerDiagonal){
//         if(col>=n){
//           add(ans,board,n);
//             return ;
//         }
//         for(int row=0;row<n;row++){
//             if(rowMap[row]==0 && upperDiagonal[(n-1 + col - row)]==0 && lowerDiagonal[row+col]==0){
//                 rowMap[row]= 1;
//                 upperDiagonal[n-1 + col - row]=1;
//                 lowerDiagonal[row+col]= 1;
                
//                 board[row][col] = 'Q';
//                  solve(col+1,ans,board,n,rowMap,upperDiagonal,lowerDiagonal);
//                  board[row][col] = '.';
//                  rowMap[row]= 0;
//                 upperDiagonal[n-1 + col - row]=0;
//                 lowerDiagonal[row+col]= 0;
//             }
//         }
//     }
       void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {

  vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};