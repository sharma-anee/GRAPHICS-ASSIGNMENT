#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define ROUND(a) ((int)(a + 0.5))
#define PII 3.14

void triangle(int, int, int, int, int, int);
void rotation(int, int, int, int, int, int, float);
void line_drawing(int, int, int, int);

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    initgraph(&gd, &gm, NULL);

    printf("The coordinates of the equilateral triangle are (250, 114), (200, 200) and (300, 200) and its centroid is (250, 172)\n");

    triangle(250, 114, 200, 200, 300, 200);
    delay(1000);

    printf("The angle of rotation is 45 degrees\n");

    rotation(250, 114, 200, 200, 300, 200, -45); //negative angle because the origin starts from top in the graphics window frame
    getch();
}


void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
   line_drawing(x1, y1, x2, y2);
   line_drawing(x2, y2, x3, y3);
   line_drawing(x3, y3, x1, y1);
}

void rotation(int x1, int y1, int x2, int y2, int x3, int y3, float theta)
{
    int l1, m1, l2, m2, l3, m3, xf = 250, yf = 172;

    cleardevice();

    theta = (theta * PII) / 180;

    l1 = xf + (x1 - xf)*cos(theta) - (y1 - yf)*sin(theta);
    m1 = yf + (x1 - xf)*sin(theta) + (y1 - yf)*cos(theta);
    l2 = xf + (x2 - xf)*cos(theta) - (y2 - yf)*sin(theta);
    m2 = yf + (x2 - xf)*sin(theta) + (y2 - yf)*cos(theta);
    l3 = xf + (x3 - xf)*cos(theta) - (y3 - yf)*sin(theta);
    m3 = yf + (x3 - xf)*sin(theta) + (y3 - yf)*cos(theta);
    triangle(l1, m1, l2, m2, l3, m3);
}


void line_drawing(int xa, int ya, int xb, int yb)
{
    int dx, dy, steps, i;
    float xNext, yNext, x = xa, y = ya;

    dx = xb - xa;
    dy = yb - ya;
    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xNext = dx / float(steps);
    yNext = dy / float(steps);
    putpixel(ROUND(x),ROUND(y), BLUE);
    for(i = 1; i <= steps; i++)
    {
        x = x + xNext;
        y = y + yNext;
        putpixel(ROUND(x), ROUND(y), BLUE);
    }
}

