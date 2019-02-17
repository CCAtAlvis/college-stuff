#include<stdio.h>
#include<graphics.h>
#include<dos.h>

void colorLine (int x1, int y1, int x2, int y2)
{
    int i, j;
    float m, x, y;

    i = y2 - y1;
    j = x2 - x1;
    m = i/j;

    for (i=x1; i<=x2; i++)
    {
        j = m*i;
        putpixel(i, j, i*j);
    }
}

void main()
{
    int gd = DETECT, gm;
    int i, j, x1, x2, y1, y2;
    float m, x, y;
    // gd: Graphical Devices
    // DETECT: detects something
    // gm: Graphical Mode
    initgraph(&gd,&gm,"C:\\TC\\BGI");

    // put a pixel at given coords
    // putpixel(120,130,4);

    // for ( i=0; i<200; i++ )
         // putpixel(200 ,i, i);

    // draw an arc
    // arc(x, y, start-angle, end-angle, radius)
    // angle in degrees
    // arc(300, 300, 0, 360, 30);

    // angles are in clock wise direction
    // pieslice(100, 100, 45, 90, 40);

    // bar3d: draw a 3d bar
    // bar3d(left, top, right, bottom, depth, topflag);
    // bar3d(10, 120, 30, 10, 10, 1);

    // line: draw a line from a point to a point
    // line(x1, y1, x2, y2);
    // line(10, 10, 556, 354);

    // colorLine
    // colorLine(8,8, getmaxx(), getmaxy());

    /*i = getmaxy() - 0;
    j = getmaxx() - 0;
    m = (float)i/j;
    x1 = 0;
    x2 = getmaxx();

    printf("");
    for (x=0; x<=x2; x+=1)
    {
        y = m*x;
        putpixel(x, y, x+y);
        delay(10);
    } */

    // NAME
    // C
    line(10,10,10,50);
    line(10,10,50,10);
    line(10,50,50,50);

    // H
    line(60,10,60,50);
    line(60,30,100,30);
    line(100,10,100,50);

    // I
    line(110,10,150,10);
    line(130,10,130,50);
    line(110,50,150,50);

    // N
    line(160,10,160,50);
    line(160,10,200,50);
    line(200,10,200,50);

    // M
    line(210,10,210,50);
    line(210,10,230,40);
    line(230,40,250,10);
    line(250,10,250,50);

    // A
    line(260,10,260,50);
    line(260,10,300,10);
    line(260,30,300,30);
    line(300,10,300,50);

    // Y
    line(310,10,310,30);
    line(310,30,350,30);
    line(350,10,350,50);
    line(310,50,350,50);

    getch();
}
