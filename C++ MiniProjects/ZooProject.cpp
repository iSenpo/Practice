#include <iostream>
#include <fstream>
using namespace std;

struct animal{

    string name="";
    int cage_number=0;
    int year_of_entry=0;
    bool is_rare=false;
    bool is_fed=false;

    bool is_name(string name){

        if(name.size()<2){

            cout<<"Invalid name"<<endl;
            return false;

        }

        return  true;
    }

};

int main(){

    string input;

    int zoocages;

    int counter=-1;

    cin>>input; 
    cin>>zoocages;
    animal animals[zoocages];


    while(true){

        cin>>input;

    
        if(input=="ADD"){

            counter++;

            if(counter>zoocages){
                break;

            }

            string s;
            int cagenumber;
            bool checkcage=false;
            bool checkname=false;
            int year;
            bool rare;

            cin>>s;

            if(!(animals[counter].is_name(s))){

                checkname=true;

            }

            cin>>cagenumber;

            for(int i=0;i<=counter;i++){
                if(animals[i].cage_number==cagenumber){

                    cout<<"Another animal is kept in this cage"<<endl;
                    checkcage=true;

                    break;
                }
            }

            if(cagenumber<0 || cagenumber>zoocages){
                
                cout<<"This cage does not exist"<<endl;
                checkcage=true;

            }

            cin>>year;
            cin>>rare;

            if(checkcage || checkname){

                counter--;
                continue;

            }
    
            animals[counter].name=s;
            animals[counter].cage_number=cagenumber;
            animals[counter].year_of_entry=year;
            animals[counter].is_rare=rare;
            cout<<"The animal named " << s << " was added successfully"<<endl;
        
        }

        if(input=="SEARCH"){

            string t;
            bool check=false;
            cin>>t;

            if(t=="name"){

                string s;
                cin>>s;

                for(int i=0;i<=counter;i++){

                    if(s==animals[i].name){

                        cout<<animals[i].name<<" "<<animals[i].cage_number<<" "<<animals[i].year_of_entry<<" "<<animals[i].is_rare<<endl;
                        check=true;

                    }
                }
            }

            if(t=="cage_number"){

                int a;
                cin>>a;

                for(int i=0;i<=counter;i++){
                    if(a==animals[i].cage_number){

                        cout<<animals[i].name<<" "<<animals[i].cage_number<<" "<<animals[i].year_of_entry<<" "<<animals[i].is_rare<<endl;
                        check=true;

                    }
                }  
            }

            if(!check){

                cout<<"No animal was found"<<endl;

            }
        }

        if(input=="LIST"){

            if(counter==-1){

                cout<<"No animal was found"<<endl;

            }

            for(int i=0;i<=counter;i++){

                cout<<animals[i].name<<" "<<animals[i].cage_number<<" "<<animals[i].year_of_entry<<" "<<animals[i].is_rare<<endl;

            }
        }

        if(input=="DELETE"){

            int a;
            string oldname;
            int b=-1;
            cin>>a;

            for(int i=0;i<=counter;i++){

                if(animals[i].cage_number==a){

                    b=i;
                    oldname=animals[b].name;
                    break;
                    
                }
            }

            if(b==-1){

                cout<<"No animal was found"<<endl;

            }

            else{

                for(int i=b;i<=counter;i++){

                    animals[i]=animals[i+1];

                }

                counter--;
                cout<<"The animal named "<< oldname <<" was deleted successfully"<<endl;
                
            }
        }

        if(input=="EDIT"){

            int a;
            int b=-1;
            string s;
            string oldname;
            string name;
            bool check=false;
            cin>>a;
            cin>>s;

            for(int i=0;i<=counter;i++){

                if(animals[i].cage_number==a){

                    b=i;
                    break;
                    
                }
            }

            if(b!=-1){

            oldname=animals[b].name;

            }

            if(b==-1){

                cout<<"No animal was found"<<endl;
                check=true;

            }
            
            if(s=="year_of_entry" && b!=-1){

                int a;
                cin>>a;
                animals[b].year_of_entry=a;
                
            }

            if(s=="name" && b!=-1){

                cin>>name;

                if(!(animals[b].is_name(name)) && b!=-1){

                    check=true;
                }

                else{

                    animals[b].name=name;

                }

            }
            
            if(s=="is_fed" && b!=-1){

                animals[b].is_fed=(!animals[b].is_fed);

            }

            if(s=="is_rare" && b!=-1){

                animals[b].is_rare=(!animals[b].is_rare);

            }
            
            if(!check){

                cout<<"The animal named " << oldname << " was edited successfully"<<endl;

            }
        }

        if(input=="SORT"){
            
            animal temp;

            for(int i=0;i<=counter-1;i++){
                for(int j=0;j<=counter-i-1;j++){

                    if(animals[j].name==animals[j+1].name){
                        if(animals[j].cage_number>animals[j+1].cage_number){

                            temp=animals[j];
                            animals[j]=animals[j+1];
                            animals[j+1]=temp;

                        }
                    }

                    if(animals[j].name>animals[j+1].name){

                        temp=animals[j];
                        animals[j]=animals[j+1];
                        animals[j+1]=temp;

                    }
                }
            }
        }

        if(input=="FEED"){

            int a;
            int b=0;
            animal temp;
            cin>>a;

            for(int i=0;i<=counter;i++){
                if(!animals[i].is_fed){

                    b++;

                }
            }

            animal hungry[b];
            int c=0;

            for(int i=0;i<=counter;i++){

                if(!animals[i].is_fed){
                    
                    hungry[c]=animals[i];
                    c++;

                }
            }

            for(int i=0;i<b-1;i++){
                for(int j=0;j<b-i-1;j++){

                    if( (!hungry[j].is_rare) && hungry[j+1].is_rare){

                        temp=hungry[j];
                        hungry[j]=hungry[j+1];
                        hungry[j+1]=temp;

                    }

                    if(hungry[j].is_rare == hungry[j+1].is_rare){

                        if(hungry[j].year_of_entry>hungry[j+1].year_of_entry){

                        temp=hungry[j];
                        hungry[j]=hungry[j+1];
                        hungry[j+1]=temp;

                        }
                    }
                }
            }

            for(int i=0;i<min(a,b);i++){
               for(int j=0;j<=counter;j++){

                    if(hungry[i].cage_number == animals[j].cage_number){

                        animals[j].is_fed=true;
                        break;

                    }
                }

                cout<<"The animal named "<< hungry[i].name << " was fed"<<endl;

            }
        }
           
        if(input=="SAVE"){

            string s;
            cin>>s;

            fstream file(s, ios::in | ios::out | ios::app);

            if(!file.is_open()){

                cerr<<"The file does not exist"<<endl;

            }

            else{

                for(int i=0;i<=counter;i++){

                    file<<animals[i].name<<" "<<animals[i].cage_number<<" "
                    <<animals[i].year_of_entry<<" "<<animals[i].is_rare<<" "<<animals[i].is_fed<<endl;

                }

                cout<<"Animals were saved successfully"<<endl;

            }

            file.close();

        }

        if(input=="LOAD"){

            string s;
            cin>>s;
            ifstream file(s);

            if(!file.is_open()){

                cerr<<"The file does not exist"<<endl;

            }

            else{

                while(getline(file , s)){

                    int i=0;
                    int j=0;
                    string n1="";
                    string n2="";
                    counter++;

                    
                    while(i<s.size()){

                        if(s[i]==' '){

                            j++;
                            i++;
                            continue;

                        }

                        if(j==0){

                            animals[counter].name=animals[counter].name+s[i];

                        }

                        while(j==1 && s[i]!=' '){

                            n1=n1+s[i];
                            i++;

                        }

                        if(j==1){

                            if(n1.size()==1){

                                animals[counter].cage_number=n1[0]-'0';

                            }

                            if(n1.size()==2){

                                animals[counter].cage_number= animals[counter].cage_number + (n1[0]-'0')*10;
                                animals[counter].cage_number= animals[counter].cage_number + n1[1]-'0';

                            }

                            if(n1.size()==3){

                                animals[counter].cage_number= animals[counter].cage_number + (n1[0]-'0')*100;
                                animals[counter].cage_number= animals[counter].cage_number + (n1[1]-'0')*10;
                                animals[counter].cage_number= animals[counter].cage_number + n1[2]-'0';
                                
                            }

                            continue;

                        }

                        while(j==2 && s[i]!=' '){

                            n2=n2+s[i];
                            i++;

                        }

                        if(j==2){

                            animals[counter].year_of_entry=animals[counter].year_of_entry + (n2[0]-'0')*1000;
                            animals[counter].year_of_entry=animals[counter].year_of_entry + (n2[1]-'0')*100;
                            animals[counter].year_of_entry=animals[counter].year_of_entry + (n2[2]-'0')*10;
                            animals[counter].year_of_entry=animals[counter].year_of_entry + (n2[3]-'0')*1;
                            
                            continue;

                        }

                        if(j==3){

                            if(s[i]=='1'){

                                animals[counter].is_rare=true;

                            }
                            else{

                                animals[counter].is_rare=false;

                            }
                        }

                        if(j==4){

                            if(s[i]=='1'){

                                animals[counter].is_fed=true;

                            }
                            else{

                                animals[counter].is_fed=false;

                            }
                        }

                        i++;

                    }
                }

                cout<<"Animals were loaded successfully"<<endl;

            }

            file.close();

        }

        if(input=="EXIT"){

            return 0;

        }
    }
}

