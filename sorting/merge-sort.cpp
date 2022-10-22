#include<bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int newArr[r+2];
    int i1 = l;
    int i2 = m+1;
        for(int i  = l;i<=r;i++){
            
            if(i1 > m && i2 > r){
                break;
            }
            else if(i2 > r){
                newArr[i] = arr[i1];
                i1++;
            }else if(i1 > m){
                newArr[i] = arr[i2];
                i2++;
            }
            else{
                if(arr[i1]>arr[i2]){
                newArr[i] = arr[i2];
                i2++;
                }else{
                    newArr[i] = arr[i1];
                    i1++;
                } 
            }
        
        }
        for(int i = l;i<=r;i++){
            arr[i] = newArr[i];
        }
}
void mergeSort(int arr[], int l, int r)
{
    if(l < r){
        int mid = l + (r - l) / 2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int arr[] = {1,7,5,4,22,8,9,6,92,1};

    mergeSort(arr,0,9);
    

    for(int el : arr){
        cout<<el<<" ";
    }
}