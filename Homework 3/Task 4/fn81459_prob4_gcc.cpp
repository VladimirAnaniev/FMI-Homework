/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Vladimir Ananiev
 * @idnumber 81459
 * @task 4
 * @compiler GCC
 *
 */

#include <iostream>

using namespace std;

void addCheckPositions(char** board, char piece, int x, int y) {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }


    if(piece == 'R' || piece == 'Q') {
        for(int row=x+1;row<8;row++) {
            if(board[row][y] == '\0' || board[row][y] == 'X') board[row][y] = 'X';
            else break;
        }
        for(int row=x-1;row>=0;row--) {
            if(board[row][y] == '\0' || board[row][y] == 'X') board[row][y] = 'X';
            else break;
        }
        for(int col=y+1;col<8;col++) {
            if(board[x][col] == '\0' || board[x][col] == 'X') board[x][col] = 'X';
            else break;
        }
        for(int col=y-1;col>=0;col--) {
            if(board[x][col] == '\0' || board[x][col] == 'X') board[x][col] = 'X';
            else break;
        }
    }

    if(piece == 'B' || piece == 'Q') {
        for(int i=1;i<8;i++) {
            if(board[x-i][y-i] == '\0' || board[x-i][y-i] == 'X') board[x-i][y-i] = 'X';
            else break;
        }
        for(int i=1;i<8;i++) {
            if(board[x+i][y-i] == '\0' || board[x+i][y-i] == 'X') board[x+i][y-i] = 'X';
            else break;
        }
        for(int i=1;i<8;i++) {
            if(board[x+i][y+i] == '\0' || board[x+i][y+i] == 'X') board[x+i][y+i] = 'X';
            else break;
        }
        for(int i=1;i<8;i++) {
            if(board[x-i][y+i] == '\0' || board[x-i][y+i] == 'X') board[x-i][y+i] = 'X';
            else break;
        }
    }

    if(piece== 'K') {
        if(board[x-1][y-1] == '\0') board[x-1][y-1] = 'X';
        if(board[x][y-1] == '\0') board[x-1][y-1] = 'X';
        if(board[x+1][y-1] == '\0') board[x-1][y-1] = 'X';
        if(board[x-1][y] == '\0') board[x-1][y-1] = 'X';
        if(board[x+1][y] == '\0') board[x-1][y-1] = 'X';
        if(board[x-1][y+1] == '\0') board[x-1][y-1] = 'X';
        if(board[x][y+1] == '\0') board[x-1][y-1] = 'X';
        if(board[x+1][y+1] == '\0') board[x-1][y-1] = 'X';
    }

    if(piece == 'N') {
        if(board[x-1][y-2] == '\0') board[x-1][y-1] = 'X';
        if(board[x+1][y-2] == '\0') board[x-1][y-1] = 'X';
        if(board[x-2][y-1] == '\0') board[x-1][y-1] = 'X';
        if(board[x+2][y+2] == '\0') board[x-1][y-1] = 'X';
        if(board[x+2][y-2] == '\0') board[x-1][y-1] = 'X';
        if(board[x-1][y+2] == '\0') board[x-1][y-1] = 'X';
        if(board[x-2][y+1] == '\0') board[x-1][y-1] = 'X';
        if(board[x+1][y+2] == '\0') board[x-1][y-1] = 'X';
    }
}

int getResult(char** board, int x, int y) {
    if(board[x][y] == 'X') {
        bool checkMate = true;
        for(int row=x-1;row<=x+1;row++) {
            for(int col=y-1;col<=y+1;col++) {
                if(row>=0 && row<8 && col>=0 && col<8 && col!=y && row!=x) {
                    if(board[row][col] != 'X') checkMate=false;
                }
            }
        }

        if(checkMate) return -2;
        else return -1;
    }
    else {
        bool staleMate = true;
        for(int row=x-1;row<=x+1;row++) {
            for(int col=y-1;col<=y+1;col++) {
                if(row>=0 && row<8 && col>=0 && col<8 && col!=y && row!=x) {
                    if(board[row][col] != 'X') staleMate=false;
                }
            }
        }

        if(staleMate) return 0;
        else return 1;
    }
}

int main() {
    int n;
    cin>>n;

    char* pieces = new char[n];
    int* xes = new int[n];
    int* ys = new int[n];

    char** board = new char*[8];
    for(int i=0;i<8;i++) {
        board[i] = new char[8];
        for (int j = 0; j < 8; j++) {
            board[i][j] = '\0';
        }
    }

    for(int i=0;i<n;i++) {
        char x;
        int y;
        cin>>pieces[i]>>x>>y;

        xes[i] = (int) x-'a';
        ys[i] = y-1;

        board[xes[i]][ys[i]] = pieces[i]; //Masterpiece
    }

    for(int i=0;i<n;i++) {
        addCheckPositions(board, pieces[i], xes[i], ys[i]);
    }

    char x;
    int y;

    cin>>x>>y;

    int result = getResult(board, (int)x-'a', y-1);

    if(result==0) cout<<"Stalemate!"<<endl;
    else if(result==1) cout<<"The show must go on!"<<endl;
    else if(result==-1) cout<<"Check!"<<endl;
    else if(result==-2) cout<<"Checkmate!"<<endl;


    return 0;
}
