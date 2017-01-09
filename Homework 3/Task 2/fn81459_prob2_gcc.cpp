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

bool makeCombinations(int num, int* arr, int& len) {
    if(len==0) {
        arr[0] = num;
        len++;
        return true;
    }
    for(int i=len-1;i>=0;i--) {
        if(arr[i]>1) {

        }
    }

    return false;
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

    for(int i=n;i>=0;i--)
    {

        arr[0] = i;

        makeSum(n, arr, 1, n-i);
    }


    return 0;
}
