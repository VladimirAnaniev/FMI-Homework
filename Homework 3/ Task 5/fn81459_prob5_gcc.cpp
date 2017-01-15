/**
 *  
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Vladimir Ananiev
 * @idnumber 81459
 * @task 5
 * @compiler GCC
 *
 */

#include <iostream>
#include <cstring>

using namespace std;

int makeInt(char* num, int len, int base) {
    int result=0;

    int help=1;

    for(int i=len-1;i>=0;i--) {
        if(num[i]<='9') result+=(num[i]-'0')*help;
        else result+=(10+(num[i]-'A'))*help;

        help*=base;
    }

    return result;
}

int getNum(char* str, int end) {
    if(str[0]=='0')
    {
        if(str[1] == 'b') return makeInt(str+2, end-2, 2);
        else if(str[1]== 'x') return makeInt(str+2, end-2, 16);
        else return makeInt(str+1, end-1, 8);
    }
    else return makeInt(str, end, 10);
}

int main() {
    char exp[1000];

    cin.getline(exp,1000);
    int len = (int) strlen(exp);
    int sum=0;

    int lastNumStart = 0;
    for(int i=0;i<len;i++) {
        if(exp[i-1]==' '&&exp[i]=='+' && exp[i+1]==' ') {
            sum+= getNum(exp+lastNumStart, i-1-lastNumStart);

            lastNumStart = i+2;
        }
    }

    sum+= getNum(exp+lastNumStart, len-lastNumStart);

    cout<<sum;


    return 0;
}
