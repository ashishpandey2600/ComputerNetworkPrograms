#include<iostream>
using namespace std;
#define for(a,b) for(int i=a;i<b;i++) 
void bitstuffing(int bits[],int newn,int cz,int n)
{
    
    int f=0; bool know=1; int z=0;
    //f is for counting no. of ones
    // know is to know about waether zero is being stuffed or not
    // z variable for iteration
    int flag[8]={0,1,1,1,1,1,1,0};
    int frame[newn];
    //1. inserting flag values
    for(0,8)
    frame[i]=flag[i];
    int l=0;
    for(8,n+cz+7) // 2 loop for Entering the value
    {  
        if (bits[i]==1)
       {
           if (bits[i-1]!=0 )//for counting 1 , condition for previous element must not be zero
           { 
              f++;
           }
       }
       if (f==5) //for if f=5 time to count one zero and reset f to 0;
       {
            if (bits[i+1]==0){//this will check weth
              f=0;
            }
            else{
             frame[i]=0;
             know=0;
            }
       }
       if (know==1)
       {
          frame[i]=bits[l];
       }
       know=1;
       
       l++;  
    }

   // 3 loop for flag end
    for(cz+7+n,newn)
    { frame[i]=flag[z];
      z++;
        
    }
  
    for(0,newn)
    {
       cout<<frame[i]<<" ";
    }
    

}
int main()
{
     int n;
     int cz=0;
     int f=0;
     bool know=0;
     cout<<"Enter the frame size : ";
     cin>>n;
    int bits[n];
    for(0,n)
    {
       cin>>bits[i];
       if (bits[i]==1)
       {
           if (bits[i-1]!=0 )//for counting 1 , condition for previous element must not be zero
           { 
              f++;
           }
       }
       if (f==5) //for if f=5 time to count one zero and reset f to 0;
       {
            if (bits[i+1]==0){//this will check weth
              f=0;
            }
            else
              cz++;
       }  
    }
    cout<<cz <<" no. of zeros required !!"<<endl;
    int newn=n+cz+15;// n= previous array size(datasize) cz= number of zeros to be stuffed; 16 for flag at end and starting
     bitstuffing(bits,newn,cz,n);
    return 0;
}