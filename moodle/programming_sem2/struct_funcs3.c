#include <stdio.h>

struct Circle
{
   int x, y;
   float r;
};


struct Circle changeRadius(struct Circle my_circle){
    my_circle.r += 1.0;
    return my_circle;
}


int main(){
    // считайте x, y, r
    int x, y;
    float r;
    scanf("%d%d%f", &x, &y, &r);
    // инициализируйте структуру my_circle
    struct Circle my_circle = {x, y, r};
    my_circle = changeRadius(my_circle);
    printf("%d %d %.1f", my_circle.x, my_circle.y, my_circle.r);

}
