//Overloading "+" Operator using template
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class ComplexNumber{
    private:
    T Re,Im;
    
    public:
    ComplexNumber(T a,T b): Re(a),Im(b) {}
    ComplexNumber():Re(0),Im(0) {}

    ComplexNumber<T> operator +(const ComplexNumber<T>& other) const{
        return ComplexNumber(Re + other.Re , Im + other.Im);
    }
    void print() const{
        cout<<"("<<Re<<" , "<<Im<<"i)";
    }
     friend ostream& operator<<(ostream& os,const ComplexNumber<T>& l) {
        os <<"("<<l.Re<<" , "<<l.Im<<"i)";
        return os;
    }
};

template <class V>
class Vector3D{
    private:
    V x,y,z;

    public:
    Vector3D(V a,V b,V c): x(a),y(b),z(c) {}
    Vector3D(): x(0),y(0),z(0) {}
    
    Vector3D<V> operator +(const Vector3D<V>& other) const{
        return Vector3D(x + other.x , y + other.y , z + other.z);
    }
    void print() const{
        cout<<"("<<x<<" , "<<y<<" , "<<z<<")";
    }
    friend ostream& operator<<(ostream& os,const Vector3D<V>& l){
        os << "("<<l.x<<" , "<<l.y<<" , "<<l.z<<")";
        return os;
    }
};
int main(){
    cout<<"\n~~~~~~ComplexNumber Test~~~~~~~\n";
    ComplexNumber<int> x(3 , 4);
    ComplexNumber<int> y(2 , -5);
    ComplexNumber<int> c = x + y;
    cout<<x<<" + "<<y<<" = "<<c<<endl;

    cout<<"\n~~~~~~Vector3D Test~~~~~~~\n";

    Vector3D<float> i(1.35 , -2.65 , 4.85);
    Vector3D<float> j(-3.35 , 4.55 , 9.15);
    Vector3D<float> k = i + j;
    cout << fixed << setprecision(2);
    cout<<i<<" + "<<j<<" = "<<k;

    return 0;
}
//Shayan Erfanian