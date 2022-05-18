class Solution {

public:

    void rotate(vector<vector<int>>& matrix) {

        

         int n,i,j,q;

n=matrix[i].size();

int p;

if(n%2==0)

  p=n/2;

  else

  p=(n+1)/2;

  if(n%2!=0)

   q=p-1;

   else

   q=p;

  for(i=0;i<p;i++)

  {

   for(j=0;j<q;j++)

   { 

   int temp=matrix[i][j];

   matrix[i][j]=matrix[n-j-1][i];

   matrix[n-j-1][i]=matrix[n-i-1][n-j-1];

   matrix[n-i-1][n-j-1]=matrix[j][n-i-1];

   matrix[j][n-i-1]=temp;

  }

  }

for(i=0;i<n;i++)

{

   for(j=0;j<n;j++)

      cout<<matrix[i][j]<<" ";

      cout<<endl;

}

        

    }

};