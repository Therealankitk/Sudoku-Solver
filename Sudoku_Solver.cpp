#include<iostream>
#include<map>
#include<vector>
using namespace std;

#define forin(i,a,b) for(int i=a;i<b;i++)
#define forout(i,a,b) for(int i=a;i>=b;i--)
#define vec vector<int>
#define pair pair<int,int>

void mainhero(vector<vec> &sudoku,int rw,int col,map<pair,map<int,int>> box,vector <map<int,int>> row,vector <map<int,int>> column){
    if(rw==9){
        forin(i,0,9){
            forin(j,0,9){
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    if(col==9){
        mainhero(sudoku,rw+1,0,box,row,column);
        return;
    }
    if(sudoku[rw][col]!=0){
        mainhero(sudoku,rw,col+1,box,row,column);
        return;
    }
    forin(i,1,10){
        if(!box[{rw/3,col/3}][i] && !row[rw][i] && !column[col][i]){
            box[{rw/3,col/3}][i] = 1;
            row[rw][i] = 1;
            column[col][i] = 1;
            sudoku[rw][col] = i;
            mainhero(sudoku,rw,col+1,box,row,column);
            box[{rw/3,col/3}][i] = 0;
            row[rw][i] = 0;
            column[col][i] = 0;
            sudoku[rw][col] = 0;
        }
    }
}
void Sudoku_Solver(vector<vec> &sudoku){
    map<pair,map<int,int>> box;
    vector <map<int,int>> row(9);
    vector <map<int,int>> column(9);

    forin(i,0,9){
        forin(j,0,9){
            if(sudoku[i][j]!=0){
                box[{i/3,j/3}][sudoku[i][j]] = 1;
                row[i][sudoku[i][j]] = 1;
                column[j][sudoku[i][j]] = 1;
            }
        }
    }

    mainhero(sudoku,0,0,box,row,column);
}

int main(){
    cout<<"!!SUDOKU SOLVER!!"<<endl<<endl;
    vector<vec> sudoku(9);
    cout<<"Input your sudoku:-"<<endl;
    forin(i,0,9){
        sudoku[i].resize(9);
        forin(j,0,9){
            cin>>sudoku[i][j];
        }
    }
    cout<<"Your Sudoku:- "<<endl;
    forin(i,0,9){
        forin(j,0,9){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    /*vector <vec> sudoku = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,4},
        {2,8,0,0,0,0,6,0,5},
        {3,0,0,2,0,0,1,0,9}
    };*/
    cout<<endl<<"Your Sudoku has been solved!!: "<<endl;
    Sudoku_Solver(sudoku);

    return 0;
}