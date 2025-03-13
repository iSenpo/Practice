#include <iostream>
using namespace std;

char findSecondUpper(const char name[]) {
    int counter = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            counter++;
            if (counter == 2) return name[i];  
        }
    }
    return 'z' + 1;  
}
void swapWords(char a[], char b[]) {
    char temp[50];
    int i = 0;
    while (a[i] != '\0') {
        temp[i] = a[i];
        i++;
    }
    temp[i] = '\0';

    i = 0;
    while (b[i] != '\0') {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';

    i = 0;
    while (temp[i] != '\0') {
        b[i] = temp[i];
        i++;
    }
    b[i] = '\0';
}
void PrintRozane(char one[], int n1){
   cout<<one<<" 4031112600"<<n1<<endl;
}
void PrintShabane(char two[], int n2){
   for(int i=0 ; two[i+3] != '\0';i++){cout<<two[i];}cout<<" 4031212600"<<n2<<endl;
}
int main() {
    char B[100][50] = {}; string A; 
    int N = 0, C = 0; int i=0; int j =0; int n1=1; int n2=1;
    
    cout << "Enter Names: ";
    getline(cin, A);

    for (int i = 0; i < A.length(); i++) {
        if (A[i] != ',') {
            B[N][C] = A[i];
            C++;
        } else {
            B[N][C] = '\0';
            N++;
            C = 0;
            i++;  
        }
    }
    B[N][C] = '\0';
    N++;  
    for (int i = 0; i < N - 1; i++) {
      for (int j = i + 1; j < N; j++) {
          if (findSecondUpper(B[i]) > findSecondUpper(B[j])) { 
             swapWords(B[i], B[j]);}

          if (findSecondUpper(B[i]) == findSecondUpper(B[j])){
             if(B[i][0] > B[j][0]){swapWords(B[i], B[j]);}
          }   
      }
  }
    for(int i = 0; i < N; i++){
        while(B[i][j] != '\0'){j++;} 
      if(B[i][j-1] != ')'){
         PrintRozane(B[i],n1); n1++;
      }
      j=0;
   }
   for(int i = 0; i < N; i++){
        while(B[i][j] != '\0'){j++;} 
      if(B[i][j-1] == ')'){
        PrintShabane(B[i],n2); n2++;
      }
      j=0;
   }
    return 0;
}
//Shayan Erfanian