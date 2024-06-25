/*
    Title:  Program to generate output to the PC screen
    Author: Your NAME, STUDENT ID, COURSE CODE, Lab Section
    Date:   Today's Date
    Description:    This program will ask for your NAME then output it centred
                    on row 12. This program will also allow for Deleting chars
                    (0x7F).
*/
#include "mbed.h"

int MAX=80;
void clear(void);                       // function to clear the screen
void position(int x, int y);            // function to position cursor
int main(void)
{
    unsigned char name[80];            // Name has MAX number of characters
    int i,x;
    for(;;)
  {
    clear();                            // clear the screen
    position(1,1);                      // position cursor at (1,1)
    i=0;                                // set index of name[] array to 0
    printf("Input ALL your name ? ");        // prompt for user name
    name[0]=getc(stdin);                // put a char in element 0
    putc(name[0],stdout);
    fflush(stdout);
    while(name[i]!=0x0d)                // while not <return> or <enter>
    {
        ++i;                            // move to next element of array
        name[i]=getc(stdin);            // put another char into name array
        putc(name[i],stdout);
        fflush(stdout);
        if(name[i]==0x7f)               // if <DEL> char 
        {
            putc(0x08,stdout);          // use <BS> to move back 1 char on screen
            --i;                        // move index back one for <DEL>
            --i;                        // move index back one for char
        }
    
    }
    name[i]='\0';                       // replace <return> with <null>

   x=(80-i)/2;                          // calculate centre for name
   position(12,x);                      // position cursor at (12,x)
   printf("%s",name);                   // print name on screen
  
   printf("\n\nHit any key to continue ... ");
   getchar();
   }
   
}
void clear(void)
{
       printf("\e[2J");                    // \e[2J clears the screen
       fflush(stdout);                     // flush output to screen
}
void position(int x, int y)
{
      printf("\e[%d;%dH",x,y);              // position cursor at (x,y)
      fflush(stdout);                       // flush output to screen
}
