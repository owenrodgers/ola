#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LA_IMPLEMENTATION
#include "ola.h"

#define HEIGHT 30
#define WIDTH 30

#define X_CENT WIDTH / 2
#define Y_CENT HEIGHT / 2


// cc -o ola_ball ola_ball.c

typedef struct
{
    char x [WIDTH][HEIGHT];
}frame;

typedef struct
{
    int x, y;
}point;


void clear();
void showframe(frame full);

frame fillframe(frame blank, int n);
frame addcircle(frame full, point c, int radius);

point adjcenter(point c, v2f velo);
v2f adj_velo(v2f velo, point c);

int main()
{
    int ticks = 0;
    char fillchar;
    frame mframe;
    point c;
    v2f velo;

    c.x = 4;
    c.y = 4;

    velo.c[0] = 1;
    velo.c[1] = 2;

    while(1)
    {

        mframe = fillframe(mframe, ticks);
        mframe = addcircle(mframe, c, 2);
        
        showframe(mframe);
        
        usleep(1E5);
        clear();

        ticks+=1;

        c.x += velo.c[0];
        c.y += velo.c[1];

        velo = adj_velo(velo, c);

    }
   
    return 0;
}

v2f adj_velo(v2f velo, point c)
{
 
    if(c.x > WIDTH || c.x < 0 )
    {
        if(c.y > HEIGHT || c.y < 0)
        {
            velo.c[1] = velo.c[1] * -1;
        }
       velo.c[0] = velo.c[0] * -1;
    }

    else if(c.y > HEIGHT || c.y < 0)
    {
        if(c.x > WIDTH || c.x < 0)
        {
            velo.c[0] = velo.c[0] * -1;
        }
        velo.c[1] = velo.c[1] * -1;

    }
  return velo;


}


void showframe(frame full)
{
    char c;
    for(int i = 0; i < WIDTH; i++)
    {
         for(int j = 0; j < HEIGHT; j++)
        {
            c = full.x[i][j];
            printf("%c", c);
        
        }
        printf("\n");
    }
}

frame fillframe(frame blank, int n)
{
    char fillchar;
    fillchar = ' ';

    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            blank.x[i][j] = fillchar;
        }
    }

    return blank;
}



frame addcircle(frame full, point c, int radius)
{
    for(int i = c.x - radius; i < c.x + radius * 2; i++)
    {
        for(int j = c.y - radius; j < c.y + radius * 2; j++)
        {
            if((i < WIDTH && i > 0) && (j < HEIGHT && j > 0))
            {
                full.x[i][j] = '%';
            }
        }
    }
    return full;
}


void clear()
{
    printf("\x1b[%dD", WIDTH);
    printf("\x1b[%dA", HEIGHT);
}






