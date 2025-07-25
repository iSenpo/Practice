//spam-filter 247 sgu
//https://codeforces.com/problemsets/acmsguru/problem/99999/274

#include <iostream>
using namespace std;

bool isLetter(char c){
    if('a' <= c && 'z' >= c)
        return true;
    
    if('A' <= c && 'Z' >= c)
        return true;
    
    return false;
}
bool isSymbol(char c){

    if(isLetter(c))
        return true;
    
    if('0' <= c && '9' >= c)
        return true;
    
    if(c == '-' || c == '_')
        return true;
    
    return false;
}
bool isWord(string s){
    if(s.size() == 0)
        return false;

    for(int i = 0; i<s.size(); i++){
        if(!isSymbol(s[i]))
            return false;   
    }
    return true;
}
bool isDomain(string s){
    if(!(s.size() == 2 || s.size() == 3))
        return false;
    for(int i = 0 ; i<s.size() ; i++){
        if(!isLetter(s[i]))
            return false;
    }
   return true;
}
bool isPrefix(string s){
    if(s.size() == 0)
        return false;

    int p = -1;
    string t="";
    for(int i = 0; i<s.size() ; i++){
        if(s[i] == '.'){
            if(!isWord(t))
                return false;
            t = "";
            i++;
        }
        t += s[i];
    }
    if(!isWord(t))
        return false;

    return true;
}
bool isSuffix(string s){
    if(s.size() == 0)
        return false;
    int p = -1;
    for(int i = s.size()-1 ; i >= 0 ; i--){
        if(s[i] == '.'){
            p = i;
            break;
        }
    }
    if(p == -1)
        return false;
    
    string pref = "";
    for(int i = 0; i <p ; i++){
        pref += s[i];
    }
    if(!isPrefix(pref))
        return false;

    string domin = "";
    for(int i = p+1 ; i <s.size(); i++){
        domin += s[i];
    }
    if(!isDomain(domin))
        return false;

    return true;
}
bool isEmail(string s){
    int p = -1;
    for(int i = 0 ; i< s.size() ; i++){
        if(s[i] == '@'){
            p = i;
            break;
        }
    }
    if(p == -1)
        return false;
    
    string pref="";
    for(int i = 0; i<p ; i++){
        pref += s[i];
    }
    if(!isPrefix(pref))
        return false;
    
    string suff= "";
    for(int i = p+1 ; i <s.size(); i++){
        suff += s[i];
    }   
    if(!isSuffix(suff))
        return false;

    return true;
}
int main(){
    int n;
    cin>>n;
    string s;
    //wont work with cin cz they use spaces in middle of word
    getline(cin,s);
    for(int i = 0; i<n ; i++){
        getline(cin,s);

        if(isEmail(s))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    
    return 0;
}