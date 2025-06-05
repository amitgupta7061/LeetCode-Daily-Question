#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int oddStart = 1, evenStart = 2, oddGap = 1, evenGap = 2;
    bool timeToOdd = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(timeToOdd){
                cout<<oddStart<<" ";
                oddStart += 2;
            }else{
                cout<<evenStart<<" ";
                evenStart += 2;
            }
        }
        cout<<endl;
        if(timeToOdd){
            for(int k = 1; k <= oddGap; k++){
                oddStart += 2;
            }
            oddGap += 2;
            timeToOdd = false;
        } else{
            for(int k = 1; k <= evenGap; k++){
                evenStart += 2;
            }
            evenGap += 2;
            timeToOdd = true;
        }
    }
}