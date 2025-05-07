//PolyMorphism practice , override functions
#include <iostream>
using namespace std;

class Food{
    public:
    virtual void ShowInfo() = 0;
    virtual void ShowPrice() = 0;
    virtual void Time() = 0;
    virtual void CommitOrders() = 0;
    virtual ~Food(){}
};
class burger:public Food{
    private:
    bool tomato;
    bool pickle;
    int HotSauce;
    public:
    burger(bool tomato ,bool pickle ,int HotSauce): tomato(tomato), pickle(pickle) , HotSauce(HotSauce){};
    void ShowInfo() override{
        cout<<"Burger "<<( tomato ? "with " : "without " )<<"Tomatos and "
        <<( pickle ? "" : "without " )<<"pickles and "<<HotSauce<<" HotSauces."<<endl;
    };
    void ShowPrice() override{
        cout<<"price for Burger with "<<HotSauce<<" HotSauce is : "<<10+(HotSauce*0.2)<<"$"<<endl;
    };
    void Time() override{
        cout<<"Burger: 5-Minutes left..."<<endl;
    };
    void CommitOrders() override{
        cout<<"We're Making your Burger right now!"<<endl;
    };
};
class pizza:public Food{
    private:
    bool mushroom;
    int cheese;
    int size;
    public:
    string ch;
    pizza(bool mushroom , int cheese , int size): mushroom(mushroom), cheese(cheese), size(size){
        switch(cheese){
            case 1 :{ ch = "without Cheese";break;}
            case 2 :{ ch = "with less Cheese";break;}
            case 3 :{ ch = "with Cheese";break;}
            case 4 :{ ch = "with Extra Cheese";break;}
            default:{ cout<<"Invalid Input.Selecting default : (1)"; ch = "with Cheese";break;}
        };
    };
    
    void ShowInfo() override{
        cout<<"Pizza "<<( mushroom ? "with " : "without " )<<"Mushrooms and "
        <<ch<<" For "<<size<<"."<<endl;
    };
    void ShowPrice() override{
        cout<<"price of Pizza for "<<size<<" is : "<<(15*size)<<"$"<<endl;
    };
    void Time() override{
        cout<<"Pizza: 10-Minutes remaining ..."<<endl;
    };
    void CommitOrders() override{
        cout<<"your Pizza is on the way!"<<endl;
    };
};
class fries:public Food{
    private:
    bool special;
    bool size;
    public:
    fries(bool size , bool special):size(size),special(special){};
    void ShowInfo() override{
        cout<<( size ? "Big " : "Small " )<<( special ? "Special " : "Normal " )<<"Fries."<<endl;
    };
    void ShowPrice() override{
        cout<<"price of Fries : "<<((size) ? 4 : 2)+((special) ? 4 : 2)<<"$"<<endl;
    };
    void Time() override{
        cout<<"Fries : up in 3-minutes..."<<endl;
    };
    void CommitOrders() override{
        cout<<"Fries in the oil!"<<endl;
    };
};
class drink:public Food{
    private:
    int drinks;
    public:
    string dr;
    int price;
    drink(int drinks):drinks(drinks){
        switch(drinks){
            case 1 : {dr = "Water Enjoyer"; price = 2;break;}
            case 2 : {dr = "cold Cocacola!"; price = 5;break;}
            case 3 : {dr = "Fantastic fanta"; price = 5;break;}
            default: {cout<<"Invalid Input.Selecting default : (1)"; dr = "Water Enjoyer"; price = 2;break;}
        };
    };
    void ShowInfo() override{
        cout<<dr<<endl;
    };
    void ShowPrice() override{
        cout<<"your Drink Cost "<<price<<"$ dollars!"<<endl;
    };
    void Time() override{
        cout<<"your Drink is ready! you can take it in fridge."<<endl;
    };
    void CommitOrders() override{
        cout<<"all your drinks registered succesfully."<<endl;
    };
};
class FoodFactory{
    public:
    static Food* createFood(){
        int choice;
        cout<<"What's your Order?(1:Burger ,2:Pizza ,3:Fries ,4:Drinks)"<<endl;
        cin>>choice;
        switch(choice){
            case 1:{
                bool tomato;
                bool pickle;
                int hots;
                cout<<"Do you want Tomatos on your Burger?(0:No / 1:Yes)"<<endl;
                cin>>tomato;
                cout<<"Do you want Pickle on your Burger?(0:No / 1:Yes)"<<endl;
                cin>>pickle;
                cout<<"How Many Hot Sauces you want?"<<endl;
                cin>>hots;
                return new burger(tomato,pickle,hots);
            };
            case 2:{
                bool mushroom;
                int cheese; 
                int size;
                cout<<"Do you want Mushrooms on your Pizza?(0:No / 1:Yes)"<<endl;
                cin>>mushroom;
                cout<<"How much Cheese you want?\n1.No Cheese\n2.a little bit of Cheese\n3.Normal Amount of Cheese\n4.Extra Cheese"<<endl;
                cin>>cheese;
                cout<<"Pizza For 1,2 or 4?"<<endl;
                cin>>size;
                return new pizza(mushroom,cheese,size);
            };
            case 3:{
                bool special;
                bool size;
                cout<<"Do you want Special or Normal Fries?(0:Normal / 1:Special)"<<endl;
                cin>>special;
                cout<<"What Size you want? (0:Small / 1:Big)"<<endl;
                cin>>size;
                return new fries(size,special);
            };
            case 4:{
                int drinks;
                cout<<"What Drink you want?(1:Water ,2:CocaCola ,3:Fanta)"<<endl;
                cin>>drinks;
                return new drink(drinks);
            };
            default:{
                cout<<"Invalid Input.Selecting default : Burger with tomato and pickle with 1 sauce"<<endl;
                return new burger(1,1,1);
            };
        };  
    };
};
int main(){
    int n;
    cout<<"How many Items you want?"<<endl;
    cin>>n;
    while(n <= 0){
        cout<<"Invalid number of orders. try again:"<<endl;
        cin>>n;
    }
    Food* Foods[100];
    for(int i=0 ; i < n ; i++){
        Foods[i] = FoodFactory::createFood();
    }
    bool running = true;
    while(running){
        int menu;
        cout<<"~~~~~~Food Menu~~~~~~\n1.Show Orders Info\n2.Show Orders Price\n3.Time Remaining\n4.Commit Orders\n5.Exit Program\t\t" ;
        cin>>menu;
        switch(menu){
            case 1: {
                for(int i=0 ; i<n ;i++){Foods[i]->ShowInfo();}
            }break;
            case 2: {
                for(int i=0 ; i<n ;i++){Foods[i]->ShowPrice();}
            }break;
            case 3: {
                for(int i=0 ; i<n ;i++){Foods[i]->Time();}
            }break;
            case 4: {
                for(int i=0 ; i<n ;i++){Foods[i]->CommitOrders();}
            }break;
            case 5: {
                running = false;
                cout<<"Exiting Program! Bye Bye"<<endl;
            }break;
            default:{cout<<"Invalid Input.Try Again :"<<endl;
            }break;
        };
    }
    for (int i=0 ; i<n ;i++){
        delete Foods[i];
    }
    return 0;
}
//Shayan Erfanian