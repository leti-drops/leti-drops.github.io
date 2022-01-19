#include <stdio.h>

// Опишите структуру
struct Circle
{
    int x, y;
    float r;
};

int main(){
    // считайте значения
    // инициализируйте  my_circle
    struct Circle my_circle;
    scanf("%d%d%f", &my_circle.x, &my_circle.y, &my_circle.r);
    printf("%d %d %.1f", my_circle.x, my_circle.y, my_circle.r);
}
