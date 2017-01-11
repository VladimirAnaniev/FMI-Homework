#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    int* nums = new int[n];

    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    for(int left=0;left<2;left++) {
        for(int i=0;i<n;i++) {
            if(nums[i]%3==left) {
                cout<<nums[i]<<" ";
                nums[i] =0;
            }
        }
    }

    //Print all remaining
    for(int i=0;i<n;i++) {
        if(nums[i]!=0) cout<<nums[i]<<" ";
    }

    return 0;
}