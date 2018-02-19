#include<stdio.h>
#include<graphics.h>
#include<math.h>

int round ( float x )
{
	int abs = (int)x;
	if ( x-abs < 0.5 )
		return abs;
	else
		return abs + 1;
}

void main()
{
	int gd = DETECT, gm;
	int x1, y1, x2, y2, dx, dy, steps, i;
	float xinc, yinc, x, y;

	x1 = 100;
	y1 = 100;
	x2 = 654;
	y2 = 350;

	initgraph(&gd, &gm, "C:\\TC\\BGI");

	// implementation of DDA
	dx = x2 - x1;
	dy = y2 - y1;

	if ( abs(dx) > abs(dy) )
		steps = abs(dx);
	else
		steps = abs(dy);

	// printf("\n%d %d %d", dx, dy, steps);

	xinc = (float)dx/steps;
	yinc = (float)dy/steps;

	// printf("\nxinc: %f   yinc: %f",xinc, yinc);

	x = x1;
	y = y1;

	for ( i=0; i<steps; ++i )
	{
		x = x+xinc;
		y = y+yinc;
		//printf("\nx: %d    y: %d   steps: %d    i: %d\n",x,y,steps,i);
		putpixel( round(x), round(y), 15);
	}

	// line(x1,y1,x2,y2);

	getch();
	// closegraph();
}
