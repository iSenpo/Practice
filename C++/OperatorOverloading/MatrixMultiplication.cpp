//Matrix Multipliction with operator overloading ( * ) using dynamic memory and using try/throw/catch
#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

class Matrix{
    private:
    vector<vector<int>> data;
    int row,col;
    public:
    Matrix(int r,int c): row(r),col(c){
        data.resize(r , vector<int>(c,0));
    }
    void input(){
        cout<<"Enter Matrix Elements : ( " <<row << " x "<<col<<" )\n";
        for(int i =0 ; i<row ; i++){
            for(int j = 0 ; j<col ;j++){
                cin>>data[i][j];
            }
        }
    }
    Matrix operator*(const Matrix& B) const{
        if(col != B.row){
            throw invalid_argument("Invalid Input! Can't Multiply !!");
        }
        Matrix result(row,B.col);
        for(int i=0 ; i<row ;i++){
            for(int j=0; j<B.col ;j++){
                for(int k=0; k<col ;k++){
                    result.data[i][j] += data[i][k]*B.data[k][j];
                }
            }
        }
        return result;
    }
    friend ostream& operator<<(ostream& os ,const Matrix& a){
    
        os << fixed << setprecision(2);
         for(int i =0 ; i<a.row ; i++){
            os << "|";
            for(int j = 0 ; j<a.col ;j++){
                os<<setw(4)<<a.data[i][j];
            }
            os<<"|\n";
        }
        return os;
    }

};
int main(){
    int row1,col1,row2,col2;
    cout<<"Enter row & cols of Matrix A :\n";
    cin>>row1>>col1;
    Matrix A(row1,col1);
    A.input();

    cout<<"Enter row & cols of Matrix B :\n";
    cin>>row2>>col2;
    Matrix B(row2,col2);
    B.input();

   try {
    Matrix C = A * B;
    cout << C;
} catch (exception& e) {
    cout << "Error: " << e.what();
}

    return 0;
}
//Shayan Erfanian