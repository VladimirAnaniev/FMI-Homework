/**
 *
 * Solution to homework task
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2016/2017
 *
 * @author Vladimir Ananiev
 * @idnumber 81459
 * @task 9
 * @compiler GCC
 *
 */

#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    int prices[100000];
    int minutes[100000];
    int mb[100000];
    int sms[100000];

    for(int i=0;i<n;i++) {
        cin>>prices[i]>>minutes[i]>>mb[i]>>sms[i];
    }

    int minUsed, mbUsed, smsUsed;
    cin>>minUsed>>mbUsed>>smsUsed;

    int indexesArr[100000];
    int count=0;

    for(int i=0;i<n;i++) {
        if(minutes[i] >= minUsed && mb[i] >= mbUsed && sms[i] >= smsUsed) {
            indexesArr[count++] = i;
        }
    }

    for(int i=0;i<count;i++) { //Insertion sort
        int j=i;
        while(j>0 && prices[indexesArr[j-1]] > prices[indexesArr[j]]) {
            int help = indexesArr[j];
            indexesArr[j] = indexesArr[j-1];
            indexesArr[j-1] = help;
            j--;
        }
    }

    for(int i=0;i<count;i++) {
        cout<<prices[indexesArr[i]]<<" "<<minutes[indexesArr[i]]<<" "<<mb[indexesArr[i]]<<" "<<sms[indexesArr[i]]<<endl;
    }

    //Readability is for the weak!!

    if (!count) cout<<"No solution";

    return 0;
}