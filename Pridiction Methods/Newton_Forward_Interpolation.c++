#include<iostream>
#include<conio.h>
using namespace std;

int fact(int f){
    int m=f;
    if(f==0){
        return 1;
    }
    else{
    m=m*(fact(f-1));
}
return m;
}
void forward_table(float x[],float y[],int n){
    cout<<"printing Forward Diffrence Table"<<endl;
    float d[n][n];
    for (int j = 0; j<n-1; j++)
    {
        for (int i = 0; i < n-j-1; i++)
        {
            if(j==0) d[i][j]=y[i+1]-y[i];
            else d[i][j]=d[i+1][j-1]-d[i][j-1];
        }
        
    }

    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n-j-1; i++)
        {
            cout<<d[i][j]<<"  ";
        }
        cout<<"\n";
    }   
}
float f_interpol(float a,float h,float p,float df[],float y[],int n){
    float u;
    u=(p-a)/h;
    cout<<"u = "<<u;
    float ut[n-1];
    float usum=u;
    ut[0]=usum;
    for(int i=1;i<n-1;i++){
        usum=usum*(u-i);
        ut[i]=usum;
        cout<<"\n"<<ut[i];
    }
    float fx=y[0]+(ut[0]*df[0]);
    cout<<"\n"<<"printing fx values"<<"\n"<<fx<<endl;
    for(int i=1;i<n-1;i++){
        fx += (ut[i]*df[i])/fact(i+1);
        cout<<fx<<endl;
        }
    return fx;
}
int main(){
    int n;
    cout<<"Enter no. of observations";
    cin>>n;
    float x[n],y[n]; 
    cout<<"Enter x and y values"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i];
    }
    //---------------forward_table(x,y,n);--------------
    cout<<"printing Forward Diffrence Table"<<endl;
    float d[n][n];
    for (int j = 0; j<n-1; j++)
    {
        for (int i = 0; i < n-j-1; i++)
        {
            if(j==0) d[i][j]=y[i+1]-y[i];
            else d[i][j]=d[i+1][j-1]-d[i][j-1];
        }
        
    }

    for (int j = 0; j < n-1; j++)
    {
        for (int i = 0; i < n-j-1; i++)
        {
            cout<<d[i][j]<<"  ";
        }
        cout<<"\n";
    }   
    //---------------float df[n-1];---------------------
    float df[n-1];
    for(int i=0;i <n-1;i++){
        df[i]=d[0][i];
    }
    float a=x[0];
    float h=x[1]-x[0];
    float p;
    cout<<"Enter the value want to pridict"<<endl;
    cin>>p;

    //--------------f_interpol(a,h,p,df,y,n);----------------
    //f_interpol(a,h,p,df,y,n);
    cout<<"\n Result ="<<f_interpol(a,h,p,df,y,n);

    
    return 0;
}
