#include <stdio.h>

// Опишите структуру
struct Person
{
    char name[100];
    char surname[100];
    int age;
};

int main(){
    // считайте значения
    // инициализируйте  some_person
    struct Person some_person;
    scanf("%s%s%d", some_person.name, some_person.surname, &some_person.age);
    printf("%s %s %d", some_person.name, some_person.surname, some_person.age);
}
