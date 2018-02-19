// mid point ellipse generation algorithm
// thanks to Anand
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

void main()
{
    int xc, yc;
    float rx, ry, x, sx, sy, y, p;
    int gd=DETECT, gm;
    clrscr();

    printf("Enter the length of Major Axis and Minor Axis");
    scanf("%f %f",&rx, &ry);

    printf("\nEnter the co-ordinates of the center of the ellipse");
    scanf("%d %d",&xc,&yc);
    getch();
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    clrscr();

    x=0;
    y=ry;
    sx=xc;
    sy=yc;
    sy=sy+ry;

    putpixel(sx, sy, RED);
    sx=xc;
    sy=sy-ry-ry;
    putpixel(sx, sy, RED);

    p=(ry*ry)-(rx*rx*ry)+((1/4)*(rx*rx));

    while((2*(ry*ry)*x)<((2*rx*rx)*y))
    {
        if(p<0)
        {
            x=x+1;
            p=p+(2*(ry*ry)*(x))+(ry*ry);

        }
        else
        {
            x=x+1;
            y=y-1;
            p=p+(2*(ry*ry)*(x))+(ry*ry)-(2*(rx*rx)*y);
        }
        putpixel(xc+x,yc+y,RED);
        putpixel(xc+x,yc-y,RED);
        putpixel(xc-x,yc+y,RED);
        putpixel(xc-x,yc-y,RED);
    }

    p=((ry*ry)*(x+0.5)*(x+0.5))+((rx*rx)*(y-1)*(y-1))-((rx*rx)*(ry*ry));

    while(y>0)
    {
        if(p>0)
        {
            y=y-1;
            p=p-(2*rx*rx*y)+(rx*rx);
        }
        else
        {
            x=x+1;
            y=y-1;
            p=p+(2*ry*ry*x)-(2*rx*rx*y)+(rx*rx);
        }

        putpixel(xc+x,yc+y,RED);
        putpixel(xc+x,yc-y,RED);
        putpixel(xc-x,yc+y,RED);
        putpixel(xc-x,yc-y,RED);
    }

    getch();
    closegraph();
}
