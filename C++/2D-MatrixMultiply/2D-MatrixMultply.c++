#include <iostream>
using namespace std;

int main(){
int A[6][6],B[6][6],C[6][6],r1,c1,r2,c2,i,j,k;

        cout<<"Enter Row of Matrix A :";
        cin>>r1;
        cout<<"Enter Column of Matrix A :";
        cin>>c1;
        cout<<"\nEnter Row of Matrix B :";
        cin>>r2;
        cout<<"Enter Column of Matrix B :";
        cin>>c2;

while(c1 != r2){
    cout<<"\nUnvalid bases.Try again!\n\n";
        cout<<"Enter Row of Matrix A :";
        cin>>r1;
        cout<<"Enter Column of Matrix A :";
        cin>>c1;
        cout<<"\nEnter Row of Matrix B :";
        cin>>r2;
        cout<<"Enter Column of Matrix B :";
        cin>>c2;
}
    for(int i=0 ; i<r1 ; i++){
        for(int j=0 ; j<c1 ; j++){
        cout<<"Enter a"<< i + 1 << j + 1 <<" : ";
        cin>>A[i][j];
        }
    }
    cout<<"Matrix A=\n";
    for(int i=0 ; i<r1 ; i++){
        for(int j=0 ; j<c1 ; j++){
        cout<<A[i][j]<<"\t";
        }cout<<"\n";
    }
    for(int i=0 ; i<r2 ; i++){
        for(int j=0 ; j<c2 ; j++){
        cout<<"Enter b"<< i + 1 << j + 1 <<" : ";
        cin>>B[i][j];
        }
    }
    cout<<"Matrix B=\n";
    for(int i=0 ; i<r2 ; i++){
        for(int j=0 ; j<c2 ; j++){
        cout<<B[i][j]<<"\t";
        }cout<<"\n";
    }
    for(int i=0; i<r1;i++){
        for(int j=0; j<c2 ; j++){
            C[i][j]=0;
        }
    }
    for(int i=0 ; i<r1;i++){
        for(int j=0; j<c2;j++){
            for(int k=0; k<c1;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    cout<<"\nMatrix C=\n";
    for(int i=0; i<r1;i++){
        for(int j=0; j<c2 ; j++){
            cout<<C[i][j]<<"\t";
        }
        cout<<"\n";
    }
return 0;}
//Shayan Erfanian - 40311126044