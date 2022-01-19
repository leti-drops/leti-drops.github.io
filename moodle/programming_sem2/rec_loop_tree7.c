#include <stdio.h>
#include <stdlib.h>

unsigned int shapearea(int x, int y, int w, int h, unsigned char* field);

unsigned int maxarea(int x, int y,
			int w, int h, unsigned char* field)
{
	unsigned int marea = 0;
	if(field[y*w + x] == 1){
		marea = shapearea(x, y, w, h, field);
	}
	field[y*w + x] = 2;

	if(x > 0 && field[y*w + (x-1)] != 2){ // left
		unsigned int narea = maxarea(x - 1, y, w, h, field);
		if(narea > marea)
			marea = narea;
	}
	if(x < w - 1 && field[y*w + (x+1)] != 2){ // right
		unsigned int narea = maxarea(x + 1, y, w, h, field);
		if(narea > marea)
			marea = narea;
	}
	if(y > 0 && field[(y-1)*w + x] != 2){ // up
		unsigned int narea = maxarea(x, y - 1, w, h, field);
		if(narea > marea)
			marea = narea;
	}
	if(y < h - 1 && field[(y+1)*w + x] != 2){ // down
		unsigned int narea = maxarea(x, y + 1, w, h, field);
		if(narea > marea)
			marea = narea;
	}
	return marea;
}

unsigned int shapearea(int x, int y,
		     int w, int h, unsigned char* field)
{
	if(field[y*w + x] == 1)
	{ // filled in
		unsigned int area = 1;
		field[y*w + x] = 2;
		if(x > 0) // left
			area += shapearea(x - 1, y, w, h, field);
		if(x < w-1) // right
			area += shapearea(x + 1, y, w, h, field);
		if(y > 0) // up
			area += shapearea(x, y - 1, w, h, field);
		if(y < h-1) // down
			area += shapearea(x, y + 1, w, h, field);
		return area;
	}
	return 0;
}

int main()
{
	int h, w;
	scanf("%d %d", &h, &w);
	unsigned char* field = malloc(w*h);
	for(int i = 0; i < w*h; ++i)
		scanf("%hhu", field + i);

	printf("%u\n", maxarea(0, 0, w, h, field));
}
