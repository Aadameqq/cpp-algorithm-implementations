#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int sqrtN = 0;

const int ARRAY_SIZE=20;

int lookup[ARRAY_SIZE];

void buildSqrtDecompositionTable(vector<int> arr){
    int n = arr.size();

    sqrtN = sqrt(n);

    for(int i = 0;i<sqrtN+1;i++){
        lookup[i] = INT_MAX;
    }

    for(int i = 0;i*sqrtN<n; i++){
        int limit = (i+1)*sqrtN;
        for(int j = i*sqrtN; j< limit && j<n; j++){
            lookup[i] = min(arr[j], lookup[i]);
        }
    }
}

int query(vector<int> arr,int l, int r){

    int mn = INT_MAX;
    int i = l;
    while(i<r && i%sqrtN != 0 && l != 0){
        mn = min(mn,arr[i]);

        i++;
    }

    while(i+sqrtN-1 <= r){
        mn = min(mn,lookup[i/sqrtN]);
        i+=sqrtN;
    }

    while(i<=r){
        mn = min(mn,arr[i]);
        i++;
    }

    return mn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr = { 7, 2, 3, 0, 5, 10, 3, 12, 18, 9, 1 };

    buildSqrtDecompositionTable(arr);
    
    assert(query(arr,0,4) == 0);    
    assert(query(arr,4,7) == 3);    
    assert(query(arr,7,8) == 12);   
    assert(query(arr,2,7) == 0);   

 
    cout<<query(arr,0,4)<<endl;    
    cout<<query(arr,4,7)<<endl;    
    cout<<query(arr,7,8) <<endl;  
    cout<<query(arr,2,7) <<endl;  


    return 0;
}