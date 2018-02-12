#include <stdio.h>
#include <stdlib.h>
#include "ml6.h"
#include "display.h"
#include "draw.h"
int octant_num(int x0, int y0, int x1, int y1){
  double s = ((double)y1-y0)/(x1-x0);
  if(x0==x1 || s>=1){
    return 2;
  }
  if(s>=0){
    return 1;
  }
  if(s>=-1){
    return 8;
  }
  return 7;
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if(x0>x1){
    int X= x0;
    int Y =y0;
    x0=x1;
    x1=X;
    y0=y1;
    y1=Y;
  }
  else if(x0==x1 && y0>y1){
    int Y =y0;
    y0=y1;
    y1=Y;
  }
  //switches the values if neccesary
  //bc we always draw the line left to right
  int x= x0;
  int y =y0;
  int A = y1-y0;
  int B= -(x1-x0);
  int d;  
  int octant = octant_num(x0,y0,x1,y1);

  if(octant == 1){
    d = 2 * A + B;
    while(x <= x1){
      plot(s,c,x,y);
      if(d > 0){
	y++;
	d += 2 * B;
      }
      x++;
      d += 2 * A;
    }
  }
  if(octant == 8){
    d = 2 * A - B;
    while(x <= x1){
      plot(s,c,x,y);
      if(d < 0){
	y--;
	d += 2 * B;
      }
      x++;
      d += 2 * A;
    }
  }
  if (octant == 2){
    d = A + 2 * B;
    while(y <= y1){
      plot(s,c,x,y);
      if(d < 0){
	x++;
	d += 2 * A;
      }
      y++;
      d += 2 * B;
    }
  }
  if (octant == 7){
    d = A - 2 * B;
    while(y >= y1){
      plot(s,c,x,y);
      if(d > 0){
	x++;
	d += 2 * A;
      }
      y--;
      d += 2 * B;
    }
  }  

}
