#include <iostream>
using namespace std;

struct Task{
        string task;
        bool completed = false;
        void createNewTask(){
            cout<<"Task title: ";
            cin.ignore();
            getline(cin,task);
        }
        void deleteTask(){
            task = "";
            completed = false;
        } 
};
void reOrderTasks(int n,Task a[],int count){
    for(int i = n; i<count ;i++){
      a[i-1].task = a[i].task;
      a[i-1].completed = a[i].completed;
    }
}
int main(){
        Task list[100];
        int counter = 0;
        bool loop = true;
        while(loop){
            cout<<"~ ~ ~ TODO List ~ ~ ~\n"
                <<"1.Add new Task\n"
                <<"2.Show my Tasks\n"
                <<"3.Mark as Completed\n"
                <<"4.Delete Task\n"
                <<"5.Exit\n\n"
                <<"Your Selection: ";
            int choice;
            cin >> choice;
            switch(choice){
                case(1):{
                    list[counter].createNewTask();
                    counter++;
                    break;}
                case(2):{
                    for(int i = 0; i < counter ; i++){
                         if(list[i].completed){
                            cout << i+1<<".["<<list[i].task<<"] Done.\n";
                            continue;
                        }
                        cout << i+1 << "." << list[i].task << "\n";
                    }
                    cout<<"~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
                    break;}
                case(3):{
                    cout << "Which task have u completed ? ";
                    int n;
                    cin >> n;
                    list[n-1].completed = true;
                    break;}
                case(4):{
                    cout<<"Which task you want to Delete?!  ";
                    int n;
                    cin >> n;
                    list[n-1].deleteTask();
                    reOrderTasks(n,list,counter);
                    counter--;
                    break;}
                case(5):{
                    cout << "Exiting program, BYE BYE";
                    loop = false;
                    break;}
                default:{
                    cout<<"Invalid Option!! try again:\n";
                    break;}
            }
        }    
 return 0;
}