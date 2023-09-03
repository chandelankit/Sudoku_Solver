#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>&sudoku,int val,int i,int j){
    int r=i;
    int c=j;
    for(int k=0;k<sudoku.size();k++){
        if(sudoku[r][k]==val) return false;
    
        if(sudoku[k][c]==val) return false;

        if(sudoku[3*(r/3)+k/3] [3*(c/3)+k%3]==val) return false;
    }
    return true;
    
}
bool solve(vector<vector<int>>& sudoku){
    int n=sudoku[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sudoku[i][j]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(sudoku,val,i,j)){ sudoku[i][j]=val;
                    bool ansPossible=solve(sudoku);
                    if(ansPossible) return true;
                    //backtrack
                    else sudoku[i][j]=0;}
                }
              return false;
            }
        }
    }

    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}

int main(){
   int rows=9;
    int cols=9;
     vector<vector<int>> sudoku(rows, vector<int>(cols));
     for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> sudoku[i][j];
        }
    }
    solveSudoku(sudoku);
    cout<<endl<<"The solution of the given sudoku is :"<<endl<<endl;
    for(int i=0;i<sudoku.size();i++){
        for(int j=0;j<sudoku.size();j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}