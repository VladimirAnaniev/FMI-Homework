/**
 *  
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Vladimir Ananiev
 * @idnumber 81459
 * @task 7
 * @compiler GCC
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int findVowel(char* word, int len) {
    for(int i=1;i<len;i++) {
        if(isVowel(word[i])) return i;
    }
    return -1;
}

bool isUppercase(char c) {
    return c>='A' && c<='Z';
}

void swapCases(char& c1, char& c2) {
    char diff = 'a'-'A';
    if(isUppercase(c1)) {
        c1+=diff;
        c2-=diff;
    }
    else {
        c1-=diff;
        c2+=diff;
    }
}

void weirdPrint(char* word, int len) {
    if(isVowel(word[0])) {
        for(int i=0;i<len;i++) {
            cout<<word[i];
        }
        if(isUppercase(word[0]) && isUppercase(word[len-1])) {
            cout<<"WAY";
        }
        else {
            cout<<"way";
        }
    }
    else {
        int index = findVowel(word, len);
        bool firstUpper = isUppercase(word[0]);
        bool indexUpper = isUppercase(word[index]);

        if(firstUpper!=indexUpper) {
            swapCases(word[0], word[index]);
        }

        for(int i=index;i<len;i++) {
            cout<<word[i];
        }
        for(int i=0;i<index;i++) {
            cout<<word[i];
        }

        if(firstUpper && indexUpper) {
            cout<<"AY";
        }
        else {
            cout<<"ay";
        }
    }
}

bool isALetter(char c) {
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

void task7Fun(char* str) {
    int len = (int) strlen(str);

    int chars = 0;
    char* startPointer = nullptr;

    for(int i=0;i<len;i++) {
        if(isALetter(str[i])) {
            if(chars==0) startPointer = str+i;
            chars++;
        }
        else {
            if(chars>0) weirdPrint(startPointer, chars);
            cout<<str[i];
            chars=0;
        }
    }

    if(chars>0) weirdPrint(startPointer, chars);
}

int main() {
    char string[10000];
    cin.getline(string,10000);

    task7Fun(string);

    return 0;
}
