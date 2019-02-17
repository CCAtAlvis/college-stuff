// mid point cirlce generation algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
	int gd=DETECT, gm;
	int r, x, y, xc, yc, pk, k;
	float xincr, yincr;

	printf("Enter x,y and r\n");
	scanf("%d%d%d", &xc, &yc, &r);

	clrscr();

	initgraph(&gd, &gm, "C:/TC/BGI");
	//line(10,10,100,100);

	x = 0;
	y = r;

	pk = 1-r;
	putpixel((xc + x), (yc + y), RED);
	putpixel((xc + y), (yc + x), RED);

	putpixel((xc - x), (yc - y), RED);
	putpixel((xc - y), (yc + x), RED);

	while (x<y)
	{
		x += 1;
		if (pk<0)
		{
			// x += 1;
			pk = pk + 2*x + 1;
		}
		else
		{
			// x += 1;
			y--;
			pk = pk + 2*x +1 - 2*y;
		}

		putpixel(xc + x, yc + y, RED);
		putpixel(xc + x, yc - y, RED);
		putpixel(xc - x, yc + y, RED);
		putpixel(xc - x, yc - y, RED);

		putpixel(xc + y, yc + x, RED);
		putpixel(xc + y, yc - x, RED);
		putpixel(xc - y, yc + x, RED);
		putpixel(xc - y, yc - x, RED);
	}

	getch();
	closegraph();
}
