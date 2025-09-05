#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Robot;
class RoboLine;

class Robot{
    private:
    char ID;
    int Stamina;
    int location;
    bool Dead = false;
    
    public:
    static int RobotCounter;
    static int LineLength;
    Robot(char a,int S,int L):ID(a),Stamina(S),location(L){
    }
    int move(){
        int temp = location;
        int destination = rand()%2;
        if(destination == 1){
            if((temp+1) >= LineLength){
                return location;
            }
            else{
                location++;
                return location;
            }
        }
        if(destination == 0){
            if(temp - 1 <= 0){
                return location;
            }
            else{
                location --;
                return location;
            }
        }
        return -1;
    }
    int GetLocation(){
        return location;
    }
    int fight(){
        Stamina--;
        if(Stamina == 0){
            Dead = true;
            RobotCounter--;
            return 1;
        }
        return rand()%Stamina;
    }
    friend ostream& operator<<(ostream& os,Robot& obj){
        os <<" ["<<obj.ID << obj.Stamina<<"] ";
        return os;
    }
    void Death(){
        Dead = true;
        RobotCounter--;
    }
    bool isDead(){
        return Dead;
    }
};
int Robot::LineLength = 0;
int Robot::RobotCounter = 0;
class RoboLine{
    private:
    int line;
    int num_robots;
    vector<Robot*> Ring;
    vector<Robot*> Robots;
    public:
    RoboLine(int length,int num_robots):line(length),num_robots(num_robots){
        Robot::LineLength = length;
        Robot::RobotCounter = num_robots;
        Ring.resize(length , nullptr);
        Robots.resize(num_robots);

        int i = 0;
        int random;
        while(i < num_robots){
            random = rand()%line;
            while(Ring[random]){
                random = rand()%line;
            }    
        Robots[i] = new Robot('a' + i , rand()%10 + 1 , random);
        Ring[random] = Robots[i];
        i++;
        }
    }
    void Play(){
        for(int i = 0; i < num_robots ;i++){
            if(Robots[i]->isDead()){
                continue;
            }
            int PrePosition = Robots[i]->GetLocation();
            int Destination = Robots[i]->move();
            if(PrePosition == Destination){
                continue;
            }
            else if(Ring[Destination] == nullptr){
                Ring[PrePosition] = nullptr;
                Ring[Destination] = Robots[i];
            }
            else{
                if(Ring[Destination]->fight() > Robots[i]->fight()){
                    Robots[i]->Death();
                    Ring[PrePosition] = nullptr;
                }
                else{
                    Ring[Destination]->Death();
                    Ring[Destination] = Robots[i];
                    Ring[PrePosition] = nullptr;
                }
            }
        }
    }
    void ShowFight(){
        for(int i = 0 ; i < line; i++){
            if(Ring[i]){
                if(!(Ring[i]->isDead())){
                    cout << *Ring[i];
                }
            }
            else{
                cout << " _ ";
            }
        }
    }
    void DestroyRobots(){
        for(int i = 0 ; i < num_robots ; i++){
            delete Robots[i];
        }
    }
    
};
int main(){
    srand(time(0));
    string temp;
    RoboLine ob(20,5);
    while(Robot::RobotCounter > 1){
        ob.ShowFight();
        ob.Play();
        getline(cin,temp);
    }
    ob.ShowFight();
    ob.DestroyRobots();
    return 0;
}