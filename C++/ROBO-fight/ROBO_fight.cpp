#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Robot;
class Roboline;
class Robot{
    private:
        char ID;
        int stamina;
        int location;
    public:
        static int RobotCounter;
        static int Length;
        int kills = 0;
        bool isDead = false;
        Robot(){}
        Robot(char _ID ,int _stamina ,int _location):ID(_ID),stamina(_stamina),location(_location){
            RobotCounter++;
        }
        friend ostream& operator<<(ostream& os ,const Robot& r){
            os <<" ["<< r.ID << r.stamina <<"] ";
            return os;
        }
        int move(){
            int dir = rand()%2;
            if(dir == 1){
                if(location + 1 == Length)
                    return location;
                location++;
                return location;
            }
            if(dir == 0){
                if(location == 0)
                    return location;
                location--;
                return location;
            }
            return -1;
        }
        int GetLoc(){
            return location;
        }
        int fight(){
            stamina--;
            if(stamina == 0){
                this->Die();
                return -1;
            }
            int luck = rand()%stamina;
            return luck;
        }
        void Die(){
            if(isDead)
                return;
            RobotCounter--;
            isDead = true;
        }
};
int Robot::RobotCounter = 0;
int Robot::Length = 0;

class RoboLine{
    private:
        int line;
        int num_bot;
        vector<Robot*> field;
        vector<Robot*> Robots;
    public:
        RoboLine(int _line ,int n):line(_line),num_bot(n){
            Robot::Length = line;
            field.resize(line , nullptr);
            Robots.resize(num_bot);
            //
            for(int i = 0 ; i < num_bot ; i++){
                int rnd = rand() % line;
                while(field[rnd]){
                    rnd = rand() % line;
                }
                Robots[i] = new Robot('a' + i , rand()%9 + 1 , rnd);
                field[rnd] = Robots[i];
            }
        }
        void play(){
            show();
            for(int i = 0 ; i < num_bot ; i++){
                if(Robots[i]->isDead){
                    continue;
                }
                int PrePosition = Robots[i]->GetLoc();
                int Destination = Robots[i]->move();
                if(PrePosition == Destination)
                    continue;
                else{
                    if(!field[Destination]){
                        field[Destination] = Robots[i];
                        field[PrePosition] = nullptr;
                    }
                    else if(field[Destination]){
                        int FightP = field[PrePosition]->fight();
                        int FightD = field[Destination]->fight();
                        if(FightD > FightP){
                            field[PrePosition]->Die();
                            field[PrePosition] = nullptr;
                        }
                        else{
                            field[Destination]->Die();
                            field[Destination] = Robots[i];
                            field[PrePosition] = nullptr;
                        }
                        field[Destination]->kills++;
                    }
                }
            }
        }
        void show(){
            for(int i = 0 ; i < line ; i++){
                if(field[i]){
                    cout << *field[i];
                }
                else{
                    cout << " ---- ";
                }
            }
        }
        void FightRecord(){
            cout<<"\n ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
            for(int i = 0 ; i < num_bot ; i++){
                cout << *Robots[i] << ": " << Robots[i]->kills << '\n'; 
            }

        }
        ~RoboLine(){
            for(int i = 0 ; i < num_bot ; i++){
                delete Robots[i];
            }
        }
};
int main(){
    srand(time(NULL));
    RoboLine start(15 , 5);
    while(Robot::RobotCounter > 1){
        start.play();
        string skip;
        getline(cin , skip);
    }
    start.show();
    start.FightRecord();
    return 0;
}