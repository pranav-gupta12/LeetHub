class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int m, int n, int index,int i, int j){
        // base case
        if(index>=word.length()) return true;
        // boundary case
        if(i<0 || i>=m || j<0 || j>=n  || board[i][j]!=word[index]) return false;
        char temp = board[i][j];
        board[i][j]= '{';
       bool op1=  search(board,word,m,n,index+1,i+1,j);
         bool op2=  search(board,word,m,n,index+1,i,j+1);
 bool op3=  search(board,word,m,n,index+1,i-1,j);
           bool op4=   search(board,word,m,n,index+1,i,j-1);
        board[i][j]= temp;
        return (op1 || op2 || op3 || op4);
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0])   if(search(board,word,m,n,0,i,j)) return true;
            }
        }
        return false;
    }
};