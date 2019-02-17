// Poly Fill algorithms
// boundry fill and
// flood fill algorithms

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int cColor;

// x: x coord
// y: y coord
// fColor: fill color
// bColor: boundary color
void boundryFill (int x, int y, int fColor, int bColor)
{
	// get the color of current pixel
	cColor = getpixel(x, y);

	if (cColor != fColor && cColor != bColor )
	{
		delay(1);
		putpixel(x, y, fColor);
		// points above and below
		boundryFill(x, y+1, fColor, bColor);
		boundryFill(x, y-1, fColor, bColor);
		// points on side
		boundryFill(x+1, y, fColor, bColor);
		boundryFill(x-1, y, fColor, bColor);
	}
}

void floodFill (int x, int y, int fColor, int oColor)
{
	// get the color of current pixel
	cColor = getpixel(x, y);

	if (cColor == oColor )
	{
		delay(1);
		putpixel(x, y, fColor);
		// points above and below
		floodFill(x, y+1, fColor, oColor);
		floodFill(x, y-1, fColor, oColor);
		// points on side
		floodFill(x+1, y, fColor, oColor);
		floodFill(x-1, y, fColor, oColor);
	}
}

void main()
{
	int gd = DETECT, gm;
	clrscr();

	initgraph(&gd, &gm, "C:\\TC\\BGI");
	setcolor(WHITE);

	// boundary fill algo
	circle(100, 100, 40);
	boundryFill(100, 100, BLUE, WHITE);

	// flood fill algo
	setcolor(BLUE);
	line(300,300,400,300);
	setcolor(RED);
	line(300,300,350,200);
	setcolor(YELLOW);
	line(350,200,400,300);
	floodFill(350, 250, GREEN, BLACK);

	getch();
	closegraph();
}
