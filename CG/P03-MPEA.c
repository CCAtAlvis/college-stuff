// mid point ellipse generation algorithm
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
    int gd=DETECT, gm;
    int rx,ry,xc,yc;
    float x,y,p;

    printf("Enter the centre of the ellipse");
    scanf("%d %d",&xc, &yc);
    printf("Enter the radius of x and y respectively");
    scanf("%d %d",&rx, &ry);
    clrscr();

    initgraph(&gd,&gm,"C:\\TC\\BGI");

    x=0;
    y=ry;
    putpixel(xc+x, yc+y,RED);

    p=(ry*ry)-(rx*rx*ry)+(rx*rx/4);

    while((ry*ry*x)<(rx*rx*y))
    {
        if(p<0)
        {
            x += 1;
            p +=  2*ry*ry*x + ry*ry;
        }
        else
        {
            x += 1;
            y -= 1;
            p +=  2*ry*ry*x - 2*rx*rx*y + ry*ry;
        }

        putpixel(xc+x, yc+y, RED);
        putpixel(xc-x, yc+y, RED);
        putpixel(xc-x, yc-y, RED);
        putpixel(xc+x, yc-y, RED);
    }

    p = ry*ry*(x+(1/2))*(x+(1/2)) + rx*rx*(y-1)*(y-1) - rx*rx*ry*ry;

    while( y>0 )
    {
        if(p>0)
        {
            y -= 1;
            p = p - 2*rx*rx*y + rx*rx;
        }
        else
        {
            x += 1;
            y -= 1;
            p = p + 2*ry*ry*x - 2*rx*rx*y + rx*rx;
        }

        putpixel(xc+x, yc+y, RED);
        putpixel(xc-x, yc+y, RED);
        putpixel(xc-x, yc-y, RED);
        putpixel(xc+x, yc-y, RED);
    }


    getch();
    closegraph();
}
