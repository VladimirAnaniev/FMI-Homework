/**
 *  
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Vladimir Ananiev
 * @idnumber 81459
 * @task 2
 * @compiler GCC
 *
 */

#include <iostream>

using namespace std;

void printResult(int num, int* arr, int len) {
    cout<<num<<" = ";

    for(int i=0;i<len;i++) {
        cout<<arr[i];
        if(i<len-1) cout<<" + ";
    }
    cout<<endl;
}

int makeSum(int sum, int* prev, int len, int needed) {
    if(needed>0) {
        prev[len] = needed;
        needed=0;

        while(prev[len]>prev[len-1]) {
            prev[len]--;
            needed++;
        }

        len++;

        makeSum(sum,prev,len,needed);

        while(prev[len-1]>1) {
            prev[len-1]--;
            needed++;
            makeSum(sum,prev,len,needed);
        }

    }
    else {
        printResult(sum, prev, len);
    }
}



int main() {
    int n;
    int arr[32] = {0};
    cin>>n;

    for(int i=n;i>=1;i--)
    {

        arr[0] = i;

        makeSum(n, arr, 1, n-i);
    }


    return 0;
}
