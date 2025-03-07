#include <iostream>
using namespace std;

string Coding(char A[] ,int len){

int x=0;

    if(len%2 == 0){
        x = len/2;
    }
    else{
        x =(len+1)/2;
    }    
string B;
    for(int a=0,b=x; a<x || b<len ; a++,b++){
        
        if(a<x){
           B += A[a];
        }
        if(b<len){
            B += A[b];
        }  
    } 
    cout<<B<<endl;
    return B;
}
void Uncoding(string A,int len){
    string C;
    for(int a=0; a<len  ; a+=2){
        
           C += A[a];
    }
    for(int b=1; b<len  ; b+=2){
        
           C += A[b];  
    }
    cout<<C<<endl;
    }
int main(){
int n=0;
cout<<"How many Words?\t";
cin>>n;

char A[n][100]={0};

for(int i=0 ; i<=n-1 ; i++){
    cin>>A[i];
}
for(int i=0 ; i<=n-1 ; i++){
    cout<<endl;
    int len=0;
    for(len=0 ; A[i][len] != '\0' ; len++);

   string M= Coding(A[i],len);
   Uncoding(M,len);
   
} 
return 0;}
//Shayan Erfanian & Amirmohammad Ehsani