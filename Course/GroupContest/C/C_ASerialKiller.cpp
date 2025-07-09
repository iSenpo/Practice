#include <iostream>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int n;
    cin>>n;
    string dead,murderer;
    cin>>dead>>murderer;
    if(dead == s){
        cout<<s<<" "<<t;
    }
    else{
        cout<<t<<" "<<s;
    }
    for(int i = 0 ; i < n-1 ; i++){
        cin>>dead>>murderer;
        cout<<murderer<<" "<<dead;
    }
    return 0;
}