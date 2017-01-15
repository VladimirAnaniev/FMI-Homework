/**
 *  
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Vladimir Ananiev
 * @idnumber 81459
 * @task 10
 * @compiler GCC
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

char table[5][5];

bool tableIsValid() {
    char found[25];
    int len=0;

    for(int i=0;i<5;i++) {
        for(int u=0;u<5;u++) {
            for(int j=0;j<len;j++) {
                if(found[j] == table[i][u]) return false;
            }

            found[len] = table[i][u];
            len++;
        }
    }

    return true;
}

bool isInTable(char c) {
    for(int i=0;i<5;i++) {
        for(int u=0;u<5;u++) {
            if(table[i][u] == c) return true;
        }
    }

    return false;
}

void modifyString(char* str, int len, char help) {
    for(int i=0;i<len;i++) {
        if(str[i]>='a'&&str[i]<='z') str[i]+='A'-'a';
        else if(!isInTable(str[i])) str[i] = help;
    }
}

void getRowAndCol(char c, int& row, int& col) {
    for(int i=0;i<5;i++) {
        for(int u=0;u<5;u++) {
            if(table[i][u] == c) {
                row=i;
                col=u;
            }
        }
    }
}

void swap(int& x, int& y) {
    int help=x;
    x=y;
    y=help;
}

int main() {
    char string[10000];

    for(int i=0;i<5;i++) {
        for(int u=0;u<5;u++) {
            cin>>table[i][u];
        }
    }

    if(tableIsValid()) {
        cin.ignore();
        cin.getline(string, 10000);

        char help = 'X';
        if(!isInTable('X')) help='Z';

        int len = (int) strlen(string);

        if(len%2==1) {
            string[len] = help;
            len++;
            string[len] = '\0';
        }

        modifyString(string, len, help);

        int r1,c1,r2,c2;
        for(int i=0;i<len;i+=2) {
            if(string[i]==string[i+1]) {
                string[i+1] = help;
            }

            getRowAndCol(string[i], r1, c1);
            getRowAndCol(string[i+1], r2, c2);

            if(r1==r2) {
                c1=(c1+1)%5;
                c2=(c2+1)%5;
            }
            else if(c1==c2) {
                r1=(r1+1)%5;
                r2=(r2+1)%5;
            }
            else {
                swap(c1,c2);
            }

            string[i] = table[r1][c1];
            string[i+1] = table[r2][c2];
        }

        cout<<string;
    }
    else {
        cout<<"Bad table!"<<endl;
    }




    return 0;
}
