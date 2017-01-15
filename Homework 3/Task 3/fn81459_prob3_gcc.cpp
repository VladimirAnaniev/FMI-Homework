/**
 *  
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Vladimir Ananiev
 * @idnumber 81459
 * @task 3
 * @compiler GCC
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

void weirdPrint(char* word, int len, int n) {
    n = n%len;

    //TODO: find out if test is true??
    //Ana-Maria 4
    //MariaAna- or ariaAna-M???

    for(int i=n;i<len;i++) {
        cout<<word[i];
    }
    for(int i=0;i<n;i++) {
        cout<<word[i];
    }
}

bool isALetter(char c) {
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

void task3Fun(char* str, int n) {
    int len = (int) strlen(str);

    int chars = 0;
    char* startPointer = nullptr;

    for(int i=0;i<len;i++) {
        if(isALetter(str[i]) || (str[i] == '-' && isALetter(str[i-1]) && isALetter(str[i+1]))) {
            if(chars==0) startPointer = str+i;
            chars++;
        }
        else {
            if(chars>0) weirdPrint(startPointer, chars, n);
            cout<<str[i];
            chars=0;
        }
    }

    if(chars>0) weirdPrint(startPointer, chars, n);
}

int main() {
    char string[10000];
    int n;

    cin.getline(string,10000);
    cin>>n;

    task3Fun(string, n);

    return 0;
}
