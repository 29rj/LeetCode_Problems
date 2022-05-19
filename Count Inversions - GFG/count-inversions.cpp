// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long int arr[], int l, int m, int r)
    {
         // Your code here
         long long int ic=0;
         int k=0;
         int i=l;
      int j=m+1;
   long long int temp[r-l+1];
         while(i<=m && j<=r){
             if (arr[i]<=arr[j]){
                 temp[k]=arr[i];
                 i++;
                 k++;
             }else{
                 temp[k]=arr[j];
                 j++;
                 k++;
                 ic+= m-i+1;
             }
         }
         while(i<=m){
               temp[k]=arr[i];
                 i++;
                 k++;
         }
         while(j<=r){
             temp[k]=arr[j];
                 j++;
                 k++;
         }
         for(i=l;i<=r;i++){
             arr[i]=temp[i-l];
         }
         return ic;
    }

    long long int mergeSort(long long arr[], int l, int r)
    {
        long long ic=0;
        //code
        if(l>=r) return 0;
        
        int mid = (l+r)/2;
        ic+=mergeSort(arr,l,mid);
        ic+=mergeSort(arr,mid+1,r);
        ic+=merge(arr,l,mid,r);
       return ic; 
    }
// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    
    int l=0;
    int r=N-1;
    return mergeSort(arr, l,r);
}


};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends