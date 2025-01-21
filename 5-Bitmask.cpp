//dp[i][mask] -> mask stores state information of N objects

//In the below code, (int)15 i.e. your mask represents the integers 1,2,3,4 states
//Initializing mask : (1<<n) -1
#include <bits/stdc++.h>
using namespace std;

void add(int& subset, int x){
    subset = subset | (1<< (x-1));
}

//ith bit is represents by (i+1)th number
void remove(int& subset, int x){
    subset = subset & ~(1<< (x-1));
}

void display(int subset){
    for(int bit_no=0; bit_no<=9; bit_no++){
        if(subset & (1<<bit_no)){
            cout<<bit_no+1<<" ";
        }
    }
}

int main(){
    int Set=15;
    
    remove(Set,5);
    add(Set,2);
    display(Set);
    return 0;
}