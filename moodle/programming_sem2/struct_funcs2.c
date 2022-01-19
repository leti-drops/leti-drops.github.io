#include <stdio.h>
#include <string.h>

struct Person
{
    char name[100];
    char surname[100];
    int age;
};

struct Person createPerson(char* name, char* surname, int age){
    struct Person p;
    strcpy(p.name, name);
    strcpy(p.surname, surname);
    p.age = age;
    return p;
}


int main(){
    // считайте name, surname, age
    char name[100]; char surname[100];
    int age;
    scanf("%100s%100s%d", name, surname, &age);
    struct Person some_person = createPerson(name, surname, age); 
    printf("%s %s %d", some_person.name, some_person.surname, some_person.age);
}
