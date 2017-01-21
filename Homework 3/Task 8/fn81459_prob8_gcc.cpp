/**
 *  
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Vladimir Ananiev
 * @idnumber 81459
 * @task 8
 * @compiler GCC
 *
 */

#include <iostream>

using namespace std;

int getModulo(int num) {
    if(num>=0) return num%3;

    return 3 + (num % 3);
}

int main() {
    int n;
    cin>>n;

    int* nums = new int[n];

    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    for(int left=0;left<3;left++) {
        for(int i=0;i<n;i++) {
            if(getModulo(nums[i])==left) {
                cout<<nums[i]<<" ";
                nums[i] =0;
            }
        }
    }

    //Print all remaining
    //for(int i=0;i<n;i++) {
        //if(nums[i]!=0) cout<<nums[i]<<" ";
    //}

    return 0;
}
