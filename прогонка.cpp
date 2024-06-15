#include <math.h>
#include <iostream>
#include <conio.h>
using namespace std;
 
int i,n,k,n1=4, ml=4;  
double t,z,q,d;
double A[10][10];
double B[10]; 
double eps[10];
double X[10]; 
double et[10];
 
int main()
{
cout<<"Dimension of the sysytel is "<<ml<<"."<<endl;
cout<<"Input matrix A ("<< ml <<" string by "<< ml <<" numbers using Tab):"<<endl;
for (i=0;i<n1;i++)
    for (k=0;k<n1;k++)
        cin>>A[i][k];
 
cout<<"Matrix A:"<<endl;
for (i=0;i<n1;i++)
    {
    for (k=0;k<n1;k++)
        cout<<A[k][i]<<"\t";
    cout<<endl;
    }
    
cout<<"Input vector B ("<< ml <<" numbers):"<<endl;
for (i=0;i<ml;i++)
    cin>>B[i];
    
 
cout<<"Vector B:"<<endl;
for (i=0;i<n1;i++)
    cout<<B[i]<<"\t";
    cout<<endl;
n=n1-1;
eps[0]=-A[0][1]/A[0][0];
et[0]=B[0]/A[0][0];
 
for(i=1;i<n;i++)
    {
    z=A[i][i]+A[i][i-1]*eps[i-1];
    eps[i]=-A[i][i+1]/z;
    et[i]=(B[i]-A[i][i-1]*et[i-1])/z;
    }
 
X[n]=(B[n]-A[n][n-1]*et[n-1])/(A[n][n]+A[n][n-1]*eps[n-1]);
 
for(i=n-1;i>=0;i--)
    X[i]=eps[i]*X[i+1]+et[i];
 
cout<<"Matrix X:"<<endl;
for(i=0;i<n1;i++)
    cout<<"x["<<i<<"]="<<X[i]<<endl;
 
getch();
return 0;
}