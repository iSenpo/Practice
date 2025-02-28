#include <stdio.h>


struct student{
    char name[20];
    float gpa;
};

int main(){
    
    struct student student1 = {"Sales", 3};
    struct student student2 = {"Salsa", 1.5};
    struct student student3 = {"Silos", 2.5};
    struct student student4 = {"Solis", 4};
    
    struct student students[]={student1 , student2 , student3 , student4};

    for(int i=0; i < sizeof(students)/sizeof(students[0]);i++){
        printf("%s \t",students[i].name);
        printf("%.2f\n",students[i].gpa);
    }
    return 0;}