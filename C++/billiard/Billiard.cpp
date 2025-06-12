#include <iostream>
using namespace std;

class Table{
public:
    void newCords(){}
};
class RectAngleTable : public Table{
private:
    int width;
    int height;
    int xCordination;
    int yCordination;
public:
    RectAngleTable(int w,int h,int x,int y): width(w) , height(h) ,xCordination(x) , yCordination(y){}
    void newCords(){
        while(xCordination < 0 || xCordination > width){
            xCordination *= -1;
            if(xCordination < 0 ){
                xCordination += width;
            }
            if (xCordination > 0 && xCordination < width){
                break;
            }
            if(xCordination > width){
                xCordination -= width;
            }
        }
        while(yCordination < 0 || yCordination > height){
            yCordination *= -1;
            if(yCordination < 0 ){
                yCordination += height;
            }
            if (yCordination > 0 && yCordination < height){
                break;
            }
            if(yCordination > height){
                yCordination -= height;
            }
        }
     cout << "( "<<xCordination << " , " << yCordination<<" )";   
    }
};
class CircleTable : public Table{};
class TriAngleTable : public Table{};
class Ball{
private:
    int x;
    int y;
    int vx;
    int vy;
    int time;
public:
    Ball(){}
    Ball(int a,int b,int c,int d,int t) : x(a) , y(b) , vx(c) , vy(d) , time(t){}
    int xCord(){
        return x+(vx*time);
    }
    int yCord(){
        return y+(vy*time);
    }
};
int main(){
    Ball obj(0,3,17,5,3);    
    RectAngleTable r(10 , 10 , obj.xCord() , obj.yCord());
    r.newCords();
return 0;
}