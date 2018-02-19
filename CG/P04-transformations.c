// 2D transformations
// 1: Translation
// 2: Scaling
// 3: Shearing
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	int gd = DETECT, gm;
	int x1= 30, y1 = 30, x2 = 60, y2 = 80;
	int tx = 100, ty = 136;
    float sx = 2, sy = 2;
	clrscr();

	initgraph(&gd, &gm, "C:\\TC\\BGI");

    // translation
	// rectangle(x1,y1,x2,y2);
	// x1 += tx;
	// x2 += tx;
	// y1 += ty;
	// y2 += ty;
	// rectangle(x1,y1,x2,y2);

    // scaling: TODO properly
    // setcolor(BLUE);
    // rectangle(x1,y1, x2+((x2-x1)*sx), y2+((y2-y1)*sy));
    // setcolor(RED);
    // rectangle(x1/sx,y1/sy,x2*sx,y2*sy);


    // shearing
    x1 = x1 + shx*y1;
    x2 = x2 + shx*y2;
    line(x1,y1, x1,y2);
    line(x1,y1, x1,y2);
    line(x1,y1, x1,y2);
    line(x1,y1, x1,y2);

	getch();
	closegraph();
}
