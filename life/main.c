        /* Conway's Game of Life implementation
         by Jędrzej Kryński
        
         TODO:
         - clean up neighbour check
         - implement pause, manual cycle when paused
        */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define field_w 96
#define field_h 32
int field[field_w][field_h]={0},i,x,y,rnd,gen=0,n[field_w][field_h]={0};
char c;
void generate(int field[field_w][field_h])
{
        srand(time(NULL));
        for(i=0;i<field_h;i++)
                for(y=0;y<field_w;y++)
                        {
                                rnd=rand();
                                if(rnd%8==0)field[y][i]=1;
                        }
}
void display(int field[field_w][field_h])
{
        printf("\033[H\033[2J");
        for(i=0;i<field_h;i++)
        {
                for(y=0;y<field_w;y++) field[y][i]==1 ? putchar('0') : putchar('.');
                printf("\n\r");
        }
        printf("Generation: %5d Press enter to cycle, c for continous mode, CTRL-C to quit\n", gen);
}
void cycle_field(int field[field_w][field_h])
{
        gen++;
        for(x=0;x<field_h;x++)
                for(y=0;y<field_w;y++)
                {
                        n[y][x]=0;
                        if(field[y-1][x-1]==1) n[y][x]+=1;
                        if(field[y+1][x+1]==1) n[y][x]+=1;
                        if(field[y+1][x-1]==1) n[y][x]+=1;
                        if(field[y-1][x+1]==1) n[y][x]+=1;
                        if(field[y][x-1]==1) n[y][x]+=1;
                        if(field[y][x+1]==1) n[y][x]+=1;
                        if(field[y-1][x]==1) n[y][x]+=1;
                        if(field[y+1][x]==1) n[y][x]+=1;
                }
        for(x=0;x<field_h;x++)
                for(y=0;y<field_w;y++)
                {
                        if(field[y][x]==1)
                        {
                                
                                if((n[y][x]==2)||(n[y][x]==3)) field[y][x]=1;
                                else field[y][x]=0;
                        }
                        if(field[y][x]==0&&n[y][x]==3) field[y][x]=1;
                }
}
int main()
{
        generate(field);
        /* field[54][2]=1,field[53][3]=1, field[53][4]=1, field[54][4]=1, field[55][4]=1; */ /* Small glider used for initial testing */
        while(1)
                {
                        printf("\033[H\033[2J");
                        display(field);
                        c=getchar();
                        if(c!=' ')
                                {
                                        while(c=='c')
                                        {
                                                cycle_field(field);
                                                display(field);
                                                usleep(20000);
                                        }
                                        cycle_field(field);
                                        display(field);
                                }
                }
        printf("\033[H\033[2J");
        display(field);
        exit(EXIT_SUCCESS);
}
