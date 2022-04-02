// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    bool static cmp(Item it1,Item it2){
        double d1 = (double)((1.000*it1.value)/it1.weight);
        double d2 = (double)((1.000*it2.value)/it2.weight);
        return d1 > d2;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        double cv = 0;
        // cout << arr[1].value << "\n";
        for(int i=0;i<n;i++){
            
            if(W>=arr[i].weight){
                W -= arr[i].weight;
                cv += arr[i].value;
            }
            else{
                double ratio = (1.00000*arr[i].value)/arr[i].weight;
                ratio *= W;
                cv += ratio;
                W=0;
            }
            
            if(W == 0)
                break;
        }
        
        return cv;
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends