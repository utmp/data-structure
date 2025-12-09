#include <stdio.h>
#include <stdlib.h>
int main(){
    struct Student{
        int id;
        char name[50];
    };
    struct Student s1 = {23,"Ahmet"};
    struct Student s2 = {65,"John"};
    printf("Id: %d\t name:  %s\n",s1.id,s1.name);
    printf("Id: %d\t name:  %s\n",s2.id,s2.name);


    struct Animal{
        char type[50];
        char breed[50];
    };
    struct Animal dog = {"kopek","kangal"};
    struct Animal cat = {"kedi","tekir"};
    printf("Type: %s\t breed:  %s\n",dog.type,dog.breed);
    printf("Type: %s\t breed:  %s",cat.type,cat.breed);
}