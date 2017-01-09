#include <iostream>

using namespace std;

void recursiveFunction(int n) {
    if(n==1) {
        cout<<n;
    }
    else {
        recursiveFunction(n-1);
        cout<<n;
        recursiveFunction(n-1);
    }
}

int main() {
    int n;

    cin>>n;

    recursiveFunction(n);

    return 0;
}
