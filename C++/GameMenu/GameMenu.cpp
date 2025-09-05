//PolyMorphism practice , override a function
#include <iostream>
using namespace std;

class Character{
    public: 
    virtual void ShowState() = 0;
    virtual ~Character(){}
};
class Combatant{
    public:
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual ~Combatant(){}
};
class warrior:public Character, public Combatant{
    private:
    int strength;

    public:
    warrior(int strength):strength(strength){}
    void ShowState() override{
        cout<<"The Warrior Strength is: "<<strength<<endl;
    }
    void attack() override{
        cout<<"The Warroir is attacking with the most sharpen Sword!\n";
    }
    void defend() override{
        cout<<"The Warrior is defending himself.\n";
    }
};
class mage:public Character, public Combatant{
    private:
    int mana;

    public:
    mage(int mana):mana(mana){}
    void ShowState() override{
        cout<<"The Mage Mana is: "<<mana<<endl;
    }
    void attack() override{
        cout<<"The Mage is Casting deadliest Spells!\n";
    }
    void defend() override{
        cout<<"Mage is protecting himself with shield.\n";
    }
};
class archer:public Character, public Combatant{
    private:
    int accuracy;
    public:
    archer(int accuracy):accuracy(accuracy){}
    void ShowState() override{
        cout<<"The Archer Accuracy is: "<<accuracy<<endl;
    }
    void attack() override{
        cout<<"The Archer is aiming at the Enemies!\n";
    }
    void defend() override{
        cout<<"The Archer is in defensive pose.\n";
    }
};
class CharacterFactory{
    public: 
    static Character* CreateCharacter(){
        int choice;
        cout<<"choose your character:(1:Warrior, 2:Mage ,3:Archer)";
        cin>>choice;
        switch(choice){
            case 1:{
            int strength;
            cout<<"Enter Warrior Strength: ";
            cin>>strength;
            return new warrior(strength);}

            case 2:{
            int mana;
            cout<<"Enter Mage Mana: ";
            cin>>mana;
            return new mage(mana);}

            case 3:{
            int accuracy;
            cout<<"Enter Archer accuracy: ";
            cin>>accuracy;
            return new archer(accuracy);}

            default :{
            cout<<"Invalid input! Creating default Warrior with 80 strength";
            return new warrior(80);}
        }
    }
};
int main(){
    int n;
    cout<<"How many fighter you want?";
    cin>>n;

    if(n<=0){
        cout<<"Invalid Number Exiting..."<<endl;
        return 0;
    }

    Character* Characters[100];
    int counter;

    for(int i=0 ; i < n ; i++){
        Characters[i] = CharacterFactory::CreateCharacter();
        counter++;
    }
        bool loop = true;
        while(loop){
            cout<<"\n~~~~~Menu~~~~~"<<endl;
            cout<<"1. Show Agents Stats"<<endl;
            cout<<"2. Characters Start Attacking"<<endl;
            cout<<"3. Characters Defending"<<endl;
            cout<<"4. Exit!\n";
            
            int choice;
            cin>>choice;
            switch(choice){
                case 1 :
                    for(int i=0 ; i<counter; i++){
                        Characters[i]->ShowState();
                    }
                    break;
                case 2 :
                    for(int i=0 ; i<counter; i++){
                        Combatant* e = dynamic_cast<Combatant*>(Characters[i]);
                        e->attack();
                    }
                break;
                case 3 :
                    for(int i=0 ; i<counter; i++){
                        Combatant* e = dynamic_cast<Combatant*>(Characters[i]);
                        e->defend();
                    }
                break;
                case 4 :
                    loop = false;
                    cout<<"Exiting Program... , bye bye"<<endl;
                break;
                default:
                    cout << "Invalid option. Try again." << endl;
            }
        }
        for(int i=0 ; i<counter ; i++){
            delete Characters[i];
        }
    return 0;
}
//Shayan Erfanian