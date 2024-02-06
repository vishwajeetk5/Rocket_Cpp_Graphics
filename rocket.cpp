#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void drawMoon() {
    setcolor(LIGHTGRAY);
    circle(600, 50, 120);
    setfillstyle(SOLID_FILL, LIGHTGRAY); 
    floodfill(600, 50, LIGHTGRAY); 

    setcolor(BLACK);
    circle(710,80,5);
    circle(610,20,7);
    circle(630,70,6);
    circle(590,70,4);
    circle(620,110,5);

    circle(540,70,5);
    circle(570,75,7);
    circle(630,20,6);
    circle(590,70,4);
    circle(610,90,5);
    
    circle(482,30,5);
    circle(710,160,7);
    circle(494,138,9);
    circle(522,110,5);
    circle(540,162,10);
    circle(564,90,8);
    circle(715,70,7);
    circle(602,122,9);
    circle(628,50,8);
}
void drawearth(){
    setcolor(BLUE);
    fillellipse((getmaxx() / 2)-300, getmaxy() + 500, 600, 600);
    setfillstyle(SOLID_FILL,BLUE); 
    floodfill(100,580,BLUE);
    setcolor(GREEN);
    fillellipse(200,580,80,30);
     setfillstyle(SOLID_FILL,GREEN); 
    floodfill(200,580,GREEN);

    fillellipse(50,560,90,40);
    setfillstyle(SOLID_FILL,GREEN); 
    floodfill(50,560,GREEN);
}

void drawRocket(int x, int y, int angle) {
    // Body of the rocket
    setcolor(YELLOW);
    rectangle(x + 10, y + 50, x + 40, y + 150);
    setcolor(WHITE);
    outtextxy(x + 11, y + 70, "ISRO");

    setcolor(LIGHTRED);
    rectangle(x + 15, y + 90, x + 35, y + 100);
    setfillstyle(SOLID_FILL, LIGHTRED);
    floodfill(x + 16, y + 91, LIGHTRED);

    setcolor(WHITE);
    rectangle(x + 15, y + 100, x + 35, y + 110);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x + 16, y + 101, WHITE);

    setcolor(GREEN);
    rectangle(x + 15, y + 110, x + 35, y + 120);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(x + 16, y + 111, GREEN);

    double radianAngle = angle * 3.14159265 / 180.0;
    int xOffset = static_cast<int>(20 * sin(radianAngle));
    int yOffset = static_cast<int>( 20* cos(radianAngle));

    // Top part of the rocket
    setcolor(DARKGRAY);
    // line(x + 10, y + 50, x + 25 , y + 20 );
    // line(x + 40, y + 50, x + 25 , y + 20 );
    // line(x + 10, y + 50, x + 40, y + 50);
    int rad = 100;
    arc(x+10+100,y+50,149,180,rad);
    arc(x+40-100,y+50,0,31,rad);
    for(int i=0;i<30;i++){
       arc(x+10+100,y+50,149+i,180,rad-i);
    arc(x+40-100,y+50,0,31-i,rad-i); 
    }

    // Flame
    setcolor(RED);
    for (int i = 1; i < 30; i++) {
        
        rectangle(x + 15 - i, y + 150 + i, x + 35 + i, y + 180 + i);
        setfillstyle(SOLID_FILL, RED);
        floodfill(x + 16, y + 160 + i, RED);
    }
}

void displaymsg(){
    int x= getmaxx()/2;
    int y= getmaxy()/2;
    int r=100;
    setcolor(WHITE);
    outtextxy(x-45,y-30," I Reached my   ");
    outtextxy(x-30,y-10,"destination");
    outtextxy(x-45,y+10,"and you too!!");
    line(550,80,x+r*cos(45),y-r*sin(45));
    line(550,80,x+85,y-52);
    
    for(int i=15;i>0;i--){
         arc(x,y,60,30,r-i);
         delay(10);
    }

}

int main() {
    initwindow(800, 600, "CHANDRAYAAN 3 MISSION SIMULATION");
    // int gd = DETECT, gm;
    // initgraph(&gd, &gm, NULL);

    int x = getmaxx() / 2 - 30;
    int y = getmaxy() - 200;
    int angle = 0;
   
       drawMoon();
        drawearth();
        drawRocket(x, y, angle);
        delay(100);
    while (y >= -70) {
        delay(100);
        cleardevice();
        drawMoon();
        drawearth();
        drawRocket(x, y, angle);
        
        angle += 2;

        // Update the position of the rocket in a curved path
        x += 5; // Adjust the horizontal movement for the curve
        y -= 15; // Adjust the vertical movement for the curve
    }
    displaymsg();
    delay(20000);
    closegraph();
    return 0;
}
