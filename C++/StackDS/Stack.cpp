#include <iostream>
using namespace std;

const int Default_Size = 10;
class Stack{
private:
    int* elements;
    int count;
    int size;
public:
    Stack(int _size = Default_Size):size(_size){
        elements = new int[size];
        count = 0;
    }
    //Stack v = u;
    //Stack v(u);
    Stack(const Stack& s){
        size = s.size;
        count = s.count;
        elements = new int[size];
        for(int i = 0 ; i < count ; i++){
            elements[i] = s.elements[i];
        }
    }
    //v = u;
    //v = v;
    Stack& operator = (const Stack& s){
        if(this == &s){
            return *this;
        }
        size = s.size;
        count = s.count;
        elements = new int[size];
        for(int i = 0 ; i < count ; i++){
            elements[i] = s.elements[i];
        }
        return *this;
    }
    void push(int x){
        if(count >= size){
            throw "WTF!";
        }
        elements[count] = x;
        count++;
    }
    void pop(){
        if(count == 0){
            throw "WTF!!";
        }
        else{
            count--;
        }
    }
    int top() const{
        if(count <= 0){
            throw "WTF!!!";
        }
        else{
            return elements[count-1];
        }
    }
    int element_count() const{
        return count;
    }
    ~Stack(){
        delete[] elements;
    }
};
int main(){
    Stack s(100);
    s.push(3);
    s.push(5);
    cout << s.element_count() << " " << s.top() << '\n';
    {
        Stack v = s;
        cout << v.element_count() << " " << v.top() << '\n';
    }
    {
        Stack w(s);
        cout << w.element_count() << " " << w.top() << '\n';
    }
    {
        Stack u;
        u = s;
        cout << u.element_count() << " " << u.top() << '\n';
        u = u;
        cout << u.element_count() << " " << u.top() << '\n';
    }


}