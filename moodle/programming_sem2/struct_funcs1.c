#include <stdio.h>

struct Circle
{
    int x, y;
    float r;
};

struct Circle createCircle(int x, int y, float r){
    struct Circle c = {x, y, r};
    return c;
}


int main(){
    // считайте x, y, r
    int x, y; float r;
    scanf("%d%d%f", &x, &y, &r);
    struct Circle my_circle = createCircle(x, y, r);

    printf("%d %d %.1f", my_circle.x, my_circle.y, my_circle.r);

}
