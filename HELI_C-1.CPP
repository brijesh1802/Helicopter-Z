#include<math.h>
#include<conio.h>
#include <iostream.h>
#include<time.h>
#include<graphics.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
int j=1;
int left=200,top=200,radx=30,rady=15;
int py1,py2,py3,py4,ran;
long score=0;
char ch;
int t,l;
int px;
void downheli();
void upheli();
void chk_pipe();
void heli_dam();
void bk_m(int level);
void main();
void play();
void drawMenu ( int selected , int defCol , int selCol ) ;
void start(int i);
int main_menu();
int level=1;


void d_score(long sc)
{


	 setfillstyle(SOLID_FILL,BLACK);
	 bar(0,getmaxy()-50,getmaxx(),getmaxy());

	 setcolor(15);
	 settextstyle(2,0,5);
	 outtextxy(400,getmaxy()-40," SCORE :");
	 char s[10];
	 sprintf(s,"%ld",sc);
	 setfillstyle(SOLID_FILL,0);
	 outtextxy(500,getmaxy()-40,s);

	 setcolor(BLACK);


}


void draw_heli()
{
setcolor(BLACK);
setfillstyle(LINE_FILL,CYAN);
fillellipse(left,top-rady,radx+10,rady-5); //top fan
setfillstyle(SOLID_FILL,CYAN);
fillellipse(left-63,top-9,10,4);     //small fan
fillellipse(left,top,radx,rady);
setfillstyle(SOLID_FILL,WHITE);
bar(left,top-3,left-65,top+3);
sector(left,top,90,270,radx,rady);
bar(left-65,top-3,left-62,top-8);
}


void ulta_heli()
{
setfillstyle(LINE_FILL,CYAN);
fillellipse(left,top+rady,radx+10,rady-5); //top fan
setfillstyle(SOLID_FILL,CYAN);
fillellipse(left-63,top+9,10,4);     //small fan
fillellipse(left,top,radx,rady);
setfillstyle(SOLID_FILL,WHITE);
bar(left,top-3,left-65,top+3);
sector(left,top,90,270,radx,rady);
bar(left-65,top+3,left-62,top+8);
delay(20);
setfillstyle(SOLID_FILL,BLACK);
fillellipse(left,top+rady,radx+10,rady-5); //top fan
fillellipse(left-63,top+9,10,4);     //small fan
fillellipse(left,top,radx,rady);
bar(left,top-3,left-65,top+3);
sector(left,top,90,270,radx,rady);
bar(left-65,top+3,left-62,top+8);
setcolor(BLACK);
}

void drawpipe(int px,int py)
{
setfillstyle(1,GREEN);
//up pipes
bar(px,py,px+60,py+200);
bar(px-15,py+200,px+75,py+220);

///down pipes

bar(px-40,py+400,px+20,getmaxy()-50);
bar(px-55,py+380,px+35,py+400);
chk_pipe();
d_score(++score);
}



void removepipe(int px,int py)
{

setfillstyle(1,BLACK);
//up pipes
bar(px,py,px+60,py+200);
bar(px-15,py+200,px+75,py+220);


//down pipes
bar(px-40,py+400,px+20,getmaxy()-50);
bar(px-55,py+380,px+35,py+400);


}

void bkg()
{
setcolor(BLACK);

randomize();


ran=random(80);

py1=random(-200);

A:
py2=random(-200);
if( abs(py1-py2)>100 )
goto A;

B:
py3=random(-200);
if(abs(py2-py3)>100)
goto B;


C:
py4=random(-200);
if(abs(py3-py4)>100)
goto C;

}


void bk_m(int level)
{
	switch (level)
 {
 case 1:drawpipe(px,py1);
	drawpipe(px+160,py2);
	drawpipe(px+320,py3);
	drawpipe(px+480,py4);
	delay(1);
	removepipe(px,py1);
	removepipe(px+160,py2);
	removepipe(px+320,py3);
	removepipe(px+480,py4);
	break;
 }
px=px-10;
 if(j==120 )
 {
 px=getmaxx();
 bkg();
 j=1;
 }
}

void chk_pipe()
{
   int yt=top-(rady-5),yb=top+rady+5;
   int clash=0;

  for(int x=left-66;x<=(left+radx+10);x++) //chk for up obstacle
  {
    if(getpixel(x,yt-1)==(GREEN) || getpixel(x,yb+1)==(GREEN ) ||getpixel(x,yt-1)==BROWN || getpixel(x,yb+1)==BROWN || (yt-1)<0 || (yb+1) >getmaxy() || getpixel(x,yt-1)==RED || getpixel(x,yb+1)==RED )
      {
       clash=1;
       //rem_heli();
       }
  }
    if(getpixel(x,yb)==(GREEN) || getpixel(x,yt)==(GREEN)|| getpixel(x,yb)==BROWN || getpixel(x,yt)==BROWN||getpixel(x,yb)==(RED) || getpixel(x,yt)==(RED))     //chk for front obstacle
   {
     clash=1;
     //rem_heli();
   }
   if(clash==1)
   {
   while(top<=getmaxy())
   {
   ulta_heli();
    top=top+10;
   }

      cleardevice();
      start(390);
      setfillstyle(SOLID_FILL,BLACK);
      bar(61,getmaxy()-394,539,getmaxy()-291);
      settextstyle(10,0,5);
      setcolor(WHITE);
      outtextxy(90,getmaxy()-390,"GAME OVER");
      settextstyle(3,0,4);
      setcolor(LIGHTRED) ;
      outtextxy(150,getmaxy()-206,"SCORE :");
      gotoxy(40,19);
      cout<<score;
	  score=0;
      getch();
      main();
   }


}


void downheli()
{
//rem_heli();
cleardevice();
top=top+5;
draw_heli();
}

void upheli()
{
//rem_heli();
cleardevice();
top=top-35;
draw_heli();
}






int main_menu ()
{
int ch;
int selected = 1;
int TotalOptions = 3;

cleardevice();
setbkcolor ( BLACK );

drawMenu ( selected , WHITE , RED );
do
{
ch = getch();
if ( ch == 80 )
{
selected = selected >= TotalOptions ? 1 : selected + 1;
drawMenu ( selected , WHITE , RED );
}
else if ( ch == 72 )
{
selected = selected < 2 ? TotalOptions : selected - 1;
drawMenu ( selected , WHITE , RED );
}

}while ( ch != 13 );

return selected;
}


void drawMenu ( int selected , int defCol , int selCol )
{

int x = 220;
int y = 250;

int h = 30;
int i;
int TotalOptions = 3;
char menu_option[3][14]= {
			  " PLAY     ",
			  " ABOUT ",
			  " EXIT     "
			 };

cleardevice();
start(390);



setlinestyle(0,0,1);

for ( i = 1; i <= TotalOptions; i++ )
{
if ( i == selected )
{

setcolor (  selCol );
setfillstyle(INTERLEAVE_FILL,selCol);

}
else
{
setfillstyle(SOLID_FILL,0);
bar(x,y,x+15,y+40);
setcolor ( defCol );
setfillstyle(EMPTY_FILL,defCol);
}

fillellipse(x+7,y+25,7,7);
settextstyle(3,0,3);
outtextxy ( x + 20 , y + 10 , menu_option[i - 1] );
y = y + h + 15;

delay(20);


}
}


void start(int i)
{
setcolor(WHITE);
setlinestyle(0,0,1);
settextstyle(10,0,5);
outtextxy(80,getmaxy()-i,"HELI");
outtextxy(330,getmaxy()-i,"OPTER");
settextstyle(3,0,4);
outtextxy(280,getmaxy()-i+30,"Z");
setcolor(WHITE);
rectangle(230,getmaxy()-i,310,getmaxy()-i+80);
rectangle(237,getmaxy()-i+7,303,getmaxy()-i+73);
setfillstyle(SOLID_FILL,RED);
bar(60,getmaxy()-i-25,70,getmaxy()-i-45);
bar(540,getmaxy()-i-25,530,getmaxy()-i-45);


top=getmaxy()-i-55;
left=65;
draw_heli();
left=535;
draw_heli();


setcolor(RED);
rectangle(50,getmaxy()-i-25,550,getmaxy()-i+115);
setlinestyle(3,0,2);
rectangle(60,getmaxy()-i-5,540,getmaxy()-i+100);

  delay(20);

}


void play()
{
top=200;
left=200;
cleardevice();
px=getmaxx();
bkg();
A:

while(!kbhit())
{
bk_m(level);
downheli();

ch='/0';
++j;
}

if(kbhit())
{

ch=getch();
if(ch=='z')
{
bk_m(level);
upheli();
++j;
goto A;
}
}



}



void main()
{
char ch;
int gm,gd=DETECT;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
cleardevice();

for(int i=0;i<400;i=i+10)
{
  cleardevice();
  start(i);
}

left=200;

a:

int selected =main_menu();

switch(selected)
{
 case 1:  cleardevice();
	  play();


 case 2 : cleardevice();
	  start(390);
	  bar(0,getmaxy()-50,getmaxx(),getmaxy());
	  settextstyle(7,0,5);
	  outtextxy(220,getmaxy()-50,"ABOUT");
	  setcolor(WHITE);
	  settextstyle(7,0,3);
	  outtextxy(80,getmaxy()/2,"BRIJESH POOJARY");
	  outtextxy(300,getmaxy()/2+40,"&");
	  outtextxy(350,getmaxy()/2+70,"HARSHITH NAYAK");
	  settextstyle(2,0,5);
	  setcolor(RED);
	  outtextxy(360,390,"Press Any Key.....");
	  getch();
	  goto a;

 case 3 :
	 cleardevice();
	 gotoxy(25,15);
	 cout<<" HOPE YOU ENJOYED.... :-) ";
	 delay(1000);
	 closegraph();


}

getch();
cleardevice();
closegraph();
}
