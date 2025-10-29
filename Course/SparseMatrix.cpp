#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int , int>
#define ln '\n'

const int N = 1e5;
vector<int> ptr1 , ptr2, ptr3;
vector<int> ind1 , ind2 , ind3;
vector<int> val1 , val2 , val3;
int n;

void printMatrix(){
    for(int i = 0 ; i < n ; i ++){
        int start = ptr1[i];
        int end = ptr1[i + 1];
        cout << "MAtrix A => ROW : " << i << ln; 
        for(int j = start ; j < end ; j++){
            cout << "Column : " <<  ind1[j] << " Value : " << val1[j] << ln;
        }
        cout << ln;
    }
}
void sumMatrices(){
    vector<int> result_ptr(n + 1, 0);
    vector<int> result_ind;
    vector<int> result_val;
    int i = 0, j = 0;
    for(int row = 0; row < n; row++){
        int rowStartA = ptr1[row]; 
        int rowEndA = ptr1[row + 1]; 
        int rowStartB = ptr2[row]; 
        int rowEndB = ptr2[row + 1]; 
        int idxA = rowStartA, idxB = rowStartB;
        while(idxA < rowEndA || idxB < rowEndB){
            if(idxA < rowEndA && (idxB >= rowEndB || ind1[idxA] < ind2[idxB])){
                result_ind.push_back(ind1[idxA]);
                result_val.push_back(val1[idxA]);
                idxA++;
            }
            else if(idxB < rowEndB && (idxA >= rowEndA || ind2[idxB] < ind1[idxA])){
                result_ind.push_back(ind2[idxB]);
                result_val.push_back(val2[idxB]);
                idxB++;
            }
            else{
                result_ind.push_back(ind1[idxA]);
                result_val.push_back(val1[idxA] + val2[idxB]);
                idxA++;
                idxB++;
            }
        }
        result_ptr[row + 1] = result_ptr[row] + result_ind.size() - result_ptr[row];
    }
    cout << "Resultant Matrix in CSR format:" << endl;
    for(int i = 0; i <= n; i++){
        cout << "ptr[" << i << "] = " << result_ptr[i] << endl;
    }
    cout << "Indices (column positions):" << endl;
    for(int i = 0; i < result_ind.size(); i++){
        cout << result_ind[i] << " ";
    }
    cout << endl;
    cout << "Values:" << endl;
    for(int i = 0; i < result_val.size(); i++){
        cout << result_val[i] << " ";
    }
    cout << endl;
}

int main(){
    cout << "Enter Diamention of Matrices (n * n) :\n";
    cin >> n;
    ptr1.resize(n + 1);
    ptr2.resize(n + 1);
    ptr3.resize(n + 1);
    cout << "Enter index pointers Matrix A (space seprated):\n";
    for(int i = 0 ; i < n + 1 ; i++){
        cin >> ptr1[i];
    }
    int sizeA = 0;
    for(int i = 0 ; i < n ; i++){
        sizeA += ptr1[i + 1] - ptr1[i];
    }
    ind1.resize(sizeA);
    val1.resize(sizeA);
    cout << "Enter Indices Matrix A (space seprated):\n";
    for(int i = 0 ; i < sizeA ; i++){
        cin >> ind1[i];
    }
    cout << "Enter Values Matrix A(space seprated):\n";
    for(int i = 0 ; i < sizeA ; i++){
        cin >> val1[i];
    }
    printMatrix();

    //system("cls");



    cout << "Enter index pointers Matrix B (space seprated):\n";
    for(int i = 0 ; i < n + 1 ; i++){
        cin >> ptr2[i];
    }
    int sizeB = 0;
    for(int i = 0 ; i < n ; i++){
        sizeB += ptr2[i + 1] - ptr2[i];
    }
    ind2.resize(sizeB);
    val2.resize(sizeB);
    cout << "Enter Indices Matrix B(space seprated):\n";
    for(int i = 0 ; i < sizeB ; i++){
        cin >> ind2[i];
    }
    cout << "Enter Values Matrix B(space seprated):\n";
    for(int i = 0 ; i < sizeB ; i++){
        cin >> val2[i];
    }
    sumMatrices();
    return 0;
}
