#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = 0;
  c.blue = MAX_COLOR;

  clear_screen(s);
  draw_line(75,75,25,30,s,c); //octant 1
  draw_line(41, 151, 78, 151, s, c); // slope of 0
  draw_line(300,300,67,29,s,c);//octant 2
  draw_line(89, 4, 179, 94, s, c); // slope of 1
  draw_line(375,125,300,250,s,c);//octant 7
  draw_line(70, 400, 270, 300, s, c); // octant 8
  draw_line(161, 40, 61, 140, s, c); // octant 3
  draw_line(173, 251, 73, 351, s, c); // slope of -1
  draw_line(194, 362, 75, 300, s, c); // octant 4
  draw_line(397, 100, 49, 60, s, c); // octant 5
  draw_line(131, 276, 31, 76, s, c); // octant 6
  draw_line(5,76,0,76,s,c);//horizontal
  draw_line(173,500,173,0,s,c);//vertical
  
  display(s);
  save_extension(s, "lines.png");
}
