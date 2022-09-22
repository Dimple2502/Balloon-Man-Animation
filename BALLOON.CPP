#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>

void clouds()
{
setcolor(WHITE);
setfillstyle(1,WHITE);
fillellipse(80,100,46,26);
fillellipse(110,80,46,26);
fillellipse(100,120,46,26);
fillellipse(150,100,46,26);

fillellipse(280,80,46,26);
fillellipse(310,60,46,26);
fillellipse(300,100,46,26);
fillellipse(350,80,46,26);

}

double angle = (30*3.14/180);
void fractal(int l,double a,int x,int y)
{
if(l!=0)
	{
	   double a1 = a+angle;
	   double a2 = a-angle;
	   int x1 = x + l*cos(a1);
	   int y1 = y - l*sin(a1);

	   setcolor(GREEN);
	   line(x,y,x1,y1);
	   fractal(l/2,a1,x1,y1);
	   x1 = x + l*cos(a2);
	   y1 = y - l*sin(a2);

	   line(x,y,x1,y1);
		   fractal(l/2,a2,x1,y1);
	   a1 = a1+angle;
	   a2 = a2-angle;
	   x1 = x + l*cos(a1);
	   y1 = y - l*sin(a1);

	   line(x,y,x1,y1);
	   fractal(l/2,a1,x1,y1);
	   x1 = x + l*cos(a2);
	   y1 = y - l*sin(a2);

	   line(x,y,x1,y1);
	   fractal(l/2,a2,x1,y1);
	}
}

int main()
{
int gd=DETECT,gm=DETECT,x=40,l=15,h=15,ht=0;
initgraph(&gd,&gm,"");
cleardevice();

clouds();



setfillstyle(5, GREEN);
	//grass
      
	fractal (20, 90*3.14/180, 80,470);
	fractal (20, 90*3.14/180, 180,450);
	fractal (20, 90*3.14/180, 280,470);
	fractal (20, 90*3.14/180, 380,450);
	fractal (20, 90*3.14/180, 480,470);
	fractal (20, 90*3.14/180, 580,450);
setcolor(BROWN);
//footpath
line(0,401,600,401);
//tree
	fractal (80, 90*3.14/180, 590,250);
	fractal (50, 90*3.14/180, 590,250);
	fractal (20, 90*3.14/180, 590,250);
	fractal (60, 90*3.14/180, 590,300);
//trunk
	setcolor(BROWN);
	int tp3[] = {580,401,600,401,600,250,580,250};
	setfillstyle(SOLID_FILL,BROWN);
	fillpoly(4,tp3);
//balloon
setcolor(RED);
for(int i=40; i>=1;i--)
{

	circle(530,290,i);
}
//Walking
while(x<460)
{

//stick
setcolor(YELLOW);
line(x+10,260,x,350);
//head
setcolor(LIGHTBLUE);
circle(x-20,315,15);
//body
line(x-20,330,x-20,375);
//legs
line(x-20,375,x-20-l,400);
line(x-20,375,x-20+l,400);
//hands
line(x-20,340,x,350);
line(x-20,340,x-20-h,360);

delay(1);
setcolor(BLACK);

//stick
line(x+10,260,x,350);
//head
circle(x-20,315,15);
//body
line(x-20,330,x-20,375);
//legs
line(x-20,375,x-20-l,400);
line(x-20,375,x-20+l,400);
//hands
line(x-20,340,x,350);
line(x-20,340,x-20-h,360);

x++;
l--;
if(l==-15)
l=15;
if(ht==1)
h++;
else h--;

if(h==15)
ht=0;
else if(h==-15)
ht=1;

}
setcolor(LIGHTBLUE);
//stick
line(x+10,360,x,350);
//head
circle(x-20,315,15);
//body
line(x-20,330,x-20,375);
//legs
line(x-20,375,x-20-l,400);
line(x-20,375,x-20+l,400);
//hands
line(x-20,340,x,350);
line(x-20,340,x-20-h,360);
	int i;
//stick rotate
for(i=0;i<20;i++)
{
setcolor(YELLOW);
line(x+10+i,260+i,x,350);
delay(1);
setcolor(0);
line(x+10+i,260+i,x,350);
}
setcolor(YELLOW);
line(x+10+i,260+i,x,350);

//balloon pops

int j;
for(j=0;j<40;j++)
{
  setcolor(BROWN);
  circle(530,290,40-j);
  delay(1);
  setcolor(0);
  circle(530,290,40-j);
  }
  setcolor(BROWN);
  circle(530,290,40-j);

getch();
}
