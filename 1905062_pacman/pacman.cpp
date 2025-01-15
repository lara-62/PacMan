# include "../iGraphics.h"
#include<istream>
#include<windows.h>
#include<mmsystem.h>
#define screen_width 1300
#define screen_height 750
#include<string.h>
#include<stdlib.h>


void pacman_move();//for moving pacman
void blinky_move();//for moving blinky and pinky
void score_count();
void time_countfunction();
int chase_scatter_mode;
int time_fright;
int pause,resume;
int menu_page=1,game_page,new_game,resume_page,instruction_page,settings,highscore,credits,level;
char name[100];
char name_array[12][100];
char highscore_array[12][100];
int len=0,indx,kop,opp,mor,mor2,mor3;
struct co_ordinate
{
    int x,y;
};
bool T;
int mode1,mode2,mode3,mode4,mode;
struct co_ordinate up_b,down_b,left_b,right_b,up_p,down_p,left_p,right_p,b,p,i,c,target_b,target_p,target_i,target_c;
struct position_of_enemy
{
  struct co_ordinate recent;
  struct co_ordinate initial;

}blinky,pinky,inky,clyde;
//int blx=9,bly=7;//blinky's initial position co_ordinate
//int recx=9;
//int recy=7;
int show,stop,m,live,j;
int i_up,i_left,i_right,i_down,lara;
int time_count;
int time_count_forshow;
int time_min;
int score;
char str_score[100];
char time_countarray[100]={'0'};
char min_countarray[100]={'0'};
char pellets_countarray[100]={'0'};
char ghost_eaten_array[100]={'0'};
char power_pelletsarray[100]={'0'};
int pellets,ghost,power;
int wall_width=32;//no need
int mazex=360;//no need
int mazey=670;//no need
int food_size=5;//no need
int pac_no,pac;
int bx,by,px,py,ix,iy,cx,cy;
char pacman_pic[4][3][100]={{"pacman 1.bmp","pacman 3.bmp","pacman 2.bmp"},{"pacman down 1.bmp","pacman down 2.bmp","pacman down 3.bmp"},{"pacman right 1.bmp","pacman right 2.bmp","pacman right 3.bmp"},{"pacman up 1.bmp","pacman up 2.bmp","pacman up 3.bmp"}};
int down;
int left;
int right;
int up;
int color[]={0,0xffffff,0xffffff,0xffffff};//no need
int special_foodx1=2,special_foodx2=14;//no need
int special_foody1=1,special_foody2=17;// no need
int pos_x,pos_y;
int pacman_positiony;
int pacman_positionx;
int pacman_initialpositiony;
int pacman_initialpositionx;
char enemy_pic_blinky[4][3][100]={{"blinky up 1.bmp","f.bmp","eye up.bmp"},{"blinky right 1.bmp","f.bmp","eye right.bmp"},{"blinky down 1.bmp","f.bmp","eye down.bmp"},{"blinky left 1.bmp","f.bmp","eye left.bmp"}};
char enemy_pic_pinky[4][3][100]={ {"pinky left.bmp","f.bmp","eye left.bmp"},{"pinky up.bmp","f.bmp","eye up.bmp"},{"pinky right.bmp","f.bmp","eye right.bmp"},{"pinky down.bmp","f.bmp","eye down.bmp"}};
char enemy_pic_inky[4][3][100]={{"inky up.bmp","f.bmp","eye up.bmp"},{"inky right.bmp","f.bmp","eye right.bmp"},{"inky down.bmp","f.bmp","eye down.bmp"},{"inky left.bmp","f.bmp","eye left.bmp"} };
char enemy_pic_clyde[4][3][100]={{"clyde up.bmp","f.bmp","eye up.bmp"},{"clyde right.bmp","f.bmp","eye right.bmp"},{"clyde down.bmp","f.bmp","eye down.bmp"},{"clyde left.bmp","f.bmp","eye left.bmp"} };
int blinky_mode,pinky_mode,inky_mode,clyde_mode;
enum
{   u,
    r,
    d,
    l

}b_position,p_position,i_position,c_position;
int maze_for_enemymovement[21][19]
={
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
		1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};



//draw_maze

int maze_art[21][19]
={
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
		1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

int maze_artcopy[21][19]
={
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
		1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
		1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
		1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};
void score_count()
{   if(game_page)
{
   itoa(score,str_score,10);
}
}



 void time_counting()
 {
    if(game_page){
     time_count++;
     time_count_forshow++;
     if(time_count%60==0)
     {
         time_count=0;

     }
     if(time_count_forshow%60==0)
     {
          time_count_forshow=0;
          time_min++;
     }
     if(time_count==2)
     {
         maze_for_enemymovement[8][9]=1;
     }
      itoa(time_count_forshow,time_countarray,10);
       itoa(time_min,min_countarray,10);
    }
 }


void maze()
{

int mx=mazex,my=mazey;
for(int i=0;i<21;i++)
{
    for(int j=0;j<19;j++)
    {
        if(maze_art[i][j]==1)
        {   iSetColor(111,111,111);
            iFilledRectangle(mx+j*(wall_width),my-i*(wall_width),wall_width,wall_width);
        }
    }
}
}


//draw food
void food()
{
    int mx=mazex+food_size+5,my=mazey+food_size+5;
    for(int i=0;i<21;i++)
{

    for(int j=0;j<19;j++)
    {
        if(maze_art[i][j]==0)

        {
            if((i==7||i==11)&&(j==0||j==1||j==2||j==16||j==17||j==18))
            {

            }
            else
            {
                if((i==special_foodx1||i==special_foodx2)&&(j==special_foody1||j==special_foody2))
                {
                 iSetColor(27,256,7);
                 iFilledCircle(mx+j*wall_width+10,my-i*wall_width+10,food_size);
                }
                else
                {iSetColor(242,188,0);
             iFilledRectangle(mx+j*wall_width,my-i*wall_width,food_size,food_size);
                }
            }

        }
    }
}
}
//draw enemy


//draw blinky



 void blinky_move()
 {  if(game_page){
    //scatter mood
if(!blinky_mode){
    if(time_count<5||time_count>=20&&time_count<25||time_count>=40&&time_count<45){
    if(maze_for_enemymovement[b.y-1][b.x]==0&&by!=b.y-1)//up
    { //maze_for_enemymovement[recy-1][recx]=-1;
      blinky.recent.y=blinky.recent.y+wall_width;
      bx=b.x;
      by=b.y;
      b.y=b.y-1;
      /*if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
      b_position=u;
    }
     else if(maze_for_enemymovement[b.y][b.x+1]==0&&bx!=b.x+1)
    {//maze_for_enemymovement[recy][recx+1]=-1;
      blinky.recent.x=blinky.recent.x+wall_width;
      bx=b.x;
      by=b.y;
     b.x=b.x+1;
     if(b.x==18)
     {
         b.x=0;
         blinky.recent.x=blinky.recent.x-wall_width*18;
     }
    /* if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
     b_position=r;
    }
    else if(maze_for_enemymovement[b.y+1][b.x]==0&&by!=b.y+1)
    {
     //maze_for_enemymovement[recy+1][recx]=-1;
     bx=b.x;
     by=b.y;
      blinky.recent.y=blinky.recent.y-wall_width;
      b.y=b.y+1;
      /*if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
      b_position=d;
    }
     else if(maze_for_enemymovement[b.y][b.x-1]==0&&bx!=b.x-1)
    {//maze_for_enemymovement[recy][recx-1]=-1;
        bx=b.x;
        by=b.y;
      blinky.recent.x=blinky.recent.x-wall_width;
        b.x=b.x-1;
      if(b.x==0)
      {
          b.x=18;
          blinky.recent.x=blinky.recent.x+wall_width*18;

      }
      /*if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
      b_position=l;

    }
   }
    if (time_count>=5&&time_count<20||time_count>=25&&time_count<40||time_count>=45)
    {   int maxd=1000;
        int flag;
        int distance;

        up_b.x=b.x;
        up_b.y=b.y-1;
        left_b.x=b.x-1;
        left_b.y=b.y;
        down_b.x=b.x;
        down_b.y=b.y+1;
        right_b.x=b.x+1;
        right_b.y=b.y;
        if(maze_for_enemymovement[up_b.y][up_b.x]!=1&&by!=up_b.y)
        {   distance=(target_b.x-up_b.x)*(target_b.x-up_b.x)+(target_b.y-up_b.y)*(target_b.y-up_b.y);
            if(distance<maxd)
            {   flag=1;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[left_b.y][left_b.x]!=1&&bx!=left_b.x)
        {   distance=(target_b.x-left_b.x)*(target_b.x-left_b.x)+(target_b.y-left_b.y)*(target_b.y-left_b.y);
            if(distance<maxd)
            {   flag=2;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[down_b.y][down_b.x]!=1&&by!=down_b.y)
        {   distance=(target_b.x-down_b.x)*(target_b.x-down_b.x)+(target_b.y-down_b.y)*(target_b.y-down_b.y);
            if(distance<maxd)
            {   flag=3;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[right_b.y][right_b.x]!=1&&bx!=right_b.x)
        {   distance=(target_b.x-right_b.x)*(target_b.x-right_b.x)+(target_b.y-right_b.y)*(target_b.y-right_b.y);
            if(distance<maxd)
            {   flag=4;
                maxd=distance;
            }
        }
        switch(flag)
        {   case 1:blinky.recent.y=blinky.recent.y+wall_width;
                    by=b.y;
                    bx=b.x;
                    b.y=b.y-1;
                   /* if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }
           */         b_position=u;
                    break;
            case 2:blinky.recent.x=blinky.recent.x-wall_width;
                    bx=b.x;
                    by=b.y;
                    b.x=b.x-1;
                /* if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
                    if(b.x==0)

      {
          b.x=18;
          blinky.recent.x=blinky.recent.x+wall_width*18;

      }

                   b_position=l;
                    break;
            case 3:blinky.recent.y=blinky.recent.y-wall_width;
                    by=b.y;
                    bx=b.x;
                   b.y=b.y+1;
                   /*if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
                   b_position=d;
                   break;
            case 4:blinky.recent.x=blinky.recent.x+wall_width;
                    bx=b.x;
                    by=b.y;

         b.x=b.x+1;
        /* if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
                    if(b.x==18)
     {
         b.x=0;
         blinky.recent.x=blinky.recent.x-wall_width*18;
     }

                    b_position=r;
                    break;
        }
    }


}
if(!pinky_mode)

{
    if(time_count<5||time_count>=20&&time_count<25||time_count>=40&&time_count<45)
    {
         if(maze_for_enemymovement[p.y-1][p.x]==0&&py!=p.y-1)
    { //maze_for_enemymovement[recy-1][recx]=-1;
      pinky.recent.y=pinky.recent.y+wall_width;
      px=p.x;
      py=p.y;
      p.y=p.y-1;
      p_position=u;
    }
             else if(maze_for_enemymovement[p.y][p.x-1]==0&&px!=p.x-1)
    {//maze_for_enemymovement[recy][recx-1]=-1;
        px=p.x;
        py=p.y;
      pinky.recent.x=pinky.recent.x-wall_width;
      p.x=p.x-1;
     if(p.x==0)
      {
          p.x=18;
          pinky.recent.x=pinky.recent.x+wall_width*18;

      }
      p_position=l;
    }

     else if(maze_for_enemymovement[p.y][p.x+1]==0&&px!=p.x+1)
    {//maze_for_enemymovement[recy][recx+1]=-1;
      pinky.recent.x=pinky.recent.x+wall_width;
      px=p.x;
      py=p.y;
     p.x=p.x+1;
     if(p.x==18)
      {
          p.x=0;
          pinky.recent.x=pinky.recent.x-wall_width*18;

      }
     p_position=r;
    }
    else if(maze_for_enemymovement[p.y+1][p.x]==0&&py!=p.y+1)
    {
     //maze_for_enemymovement[recy+1][recx]=-1;
     px=p.x;
     py=p.y;
      pinky.recent.y=pinky.recent.y-wall_width;
      p.y=p.y+1;
      p_position=d;
    }

   }
    if (time_count>=5&&time_count<20||time_count>=25&&time_count<40||time_count>=45)
    {   int maxd=1000;
        int flag;
        int distance;
        up_p.x=p.x;
        up_p.y=p.y-1;
        left_p.x=p.x-1;
        left_p.y=p.y;
        down_p.x=p.x;
        down_p.y=p.y+1;
        right_p.x=p.x+1;
        right_p.y=p.y;
        if(maze_for_enemymovement[up_p.y][up_p.x]!=1&&py!=up_p.y)
        {   distance=(target_p.x-up_p.x)*(target_p.x-up_p.x)+(target_p.y-up_p.y)*(target_p.y-up_p.y);
            if(distance<maxd)
            {   flag=1;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[left_p.y][left_p.x]!=1&&px!=left_p.x)
        {   distance=(target_p.x-left_p.x)*(target_p.x-left_p.x)+(target_p.y-left_p.y)*(target_p.y-left_p.y);
            if(distance<maxd)
            {   flag=2;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[down_p.y][down_p.x]!=1&&py!=down_p.y)
        {   distance=(target_p.x-down_b.x)*(target_p.x-down_b.x)+(target_p.y-down_b.y)*(target_p.y-down_b.y);
            if(distance<maxd)
            {   flag=3;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[right_p.y][right_p.x]!=1&&px!=right_p.x)
        {   distance=(target_p.x-right_p.x)*(target_p.x-right_p.x)+(target_p.y-right_p.y)*(target_p.y-right_p.y);
            if(distance<maxd)
            {   flag=4;
                maxd=distance;
            }
        }
        switch(flag)
        {   case 1:pinky.recent.y=pinky.recent.y+wall_width;
                    py=p.y;
                    px=p.x;
                    p.y=p.y-1;
                    p_position=u;
                    break;
            case 2:pinky.recent.x=pinky.recent.x-wall_width;
                    px=p.x;
                    py=p.y;
                    p.x=p.x-1;
                    if(p.x==0)
      {
          p.x=18;
          pinky.recent.x=pinky.recent.x+wall_width*18;

      }
                   p_position=l;
                    break;
            case 3:pinky.recent.y=pinky.recent.y-wall_width;
                    py=p.y;
                    px=p.x;
                   p.y=p.y+1;
                   p_position=d;
                   break;
            case 4:pinky.recent.x=pinky.recent.x+wall_width;
                    px=p.x;
                    py=p.y;
                    p.x=p.x+1;
                    if(p.x==18)
      {
          p.x=0;
          pinky.recent.x=pinky.recent.x-wall_width*18;

      }
                    p_position=r;
                    break;
        }

 }

}
 }


 }

 void inky_move()
 {  if(game_page){
     if(!inky_mode)
     {
     if(time_count<=7||time_count>14&&time_count<=21||time_count>=40&&time_count<47){
    //jeta running chilo otar track rakhte hobe
    if(i_up){  lara=0;
        if(maze_for_enemymovement[i.y-1][i.x]==0&&iy!=i.y-1)
        {  lara=1;
            iy=i.y;
            ix=i.x;
          i.y=i.y-1;
          inky.recent.y=inky.recent.y+wall_width;

        }
       /* else
        {
            i_right=1;
            i_up=0;
            i_left=0;
            i_down=0;
        }*/
        }
        if(i_right){
                lara=0;
        if(maze_for_enemymovement[i.y][i.x+1]==0&&ix!=i.x+1)
        {  lara=1;
        ix=i.x;
        iy=i.y;
          i.x=i.x+1;
          inky.recent.x=inky.recent.x+wall_width;

        }
        /*else
        {

            i_right=0;
            i_up=0;
            i_left=0;
            i_down=1;
        }*/
        }
        if(i_down){lara=0;
        if(maze_for_enemymovement[i.y+1][i.x]==0&&iy!=i.y+1)
        {  lara=1;
        iy=i.y;
        ix=i.x;
          i.y=i.y+1;
          inky.recent.y=inky.recent.y-wall_width;

        }
        /*else
        {

            i_right=0;
            i_up=0;
            i_left=1;
            i_down=0;
        }*/
        }
         if(i_left){lara=0;
        if(maze_for_enemymovement[i.y][i.x-1]==0&&ix!=i.x-1)
        {  lara=1;
        ix=i.x;
        iy=i.y;
          i.x=i.x-1;
          inky.recent.x=inky.recent.x-wall_width;

        }
        /*else
        {

            i_right=0;
            i_up=1;
            i_left=0;
            i_down=0;
        }*/
        }






        if(lara==0){
        if(maze_for_enemymovement[i.y-1][i.x]==0&&iy!=i.y-1)
        {   iy=i.y;
        ix=i.x;
          i.y=i.y-1;
          inky.recent.y=inky.recent.y+wall_width;

            i_right=0;
            i_up=1;
            i_left=0;
            i_down=0;


        }



        else if(maze_for_enemymovement[i.y][i.x+1]==0&&ix!=i.x+1)
        {   ix=i.x;
            iy=i.y;
          i.x=i.x+1;
          inky.recent.x=inky.recent.x+wall_width;



            i_right=1;
            i_up=0;
            i_left=0;
            i_down=0;

        }

        else if(maze_for_enemymovement[i.y+1][i.x]==0&&iy!=i.y+1)
        {   iy=i.y;
        ix=i.x;
          i.y=i.y+1;
          inky.recent.y=inky.recent.y-wall_width;

            i_down=1;
            i_right=0;
            i_up=0;
            i_left=0;

        }
        else if(maze_for_enemymovement[i.y][i.x-1]==0&&ix!=i.x-1)
        {   ix=i.x;
        iy=i.y;
          i.x=i.x-1;
          inky.recent.x=inky.recent.x-wall_width;



            i_right=0;
            i_up=0;
            i_left=1;
            i_down=0;
        }
        }
 }


else if(time_count>7&&time_count<=14||time_count>21&&time_count<25)
{

     if(i_up){  lara=0;
        if(maze_for_enemymovement[i.y-1][i.x]==0&&iy!=i.y-1)
        {  lara=1;
            iy=i.y;
            ix=i.x;
          i.y=i.y-1;
          inky.recent.y=inky.recent.y+wall_width;

        }
       /* else
        {
            i_right=1;
            i_up=0;
            i_left=0;
            i_down=0;
        }*/
        }
        if(i_right){
                lara=0;
        if(maze_for_enemymovement[i.y][i.x+1]==0&&ix!=i.x+1)
        {  lara=1;
        ix=i.x;
        iy=i.y;
          i.x=i.x+1;
          inky.recent.x=inky.recent.x+wall_width;

        }
        /*else
        {

            i_right=0;
            i_up=0;
            i_left=0;
            i_down=1;
        }*/
        }
        if(i_down){lara=0;
        if(maze_for_enemymovement[i.y+1][i.x]==0&&iy!=i.y+1)
        {  lara=1;
        iy=i.y;
        ix=i.x;
          i.y=i.y+1;
          inky.recent.y=inky.recent.y-wall_width;

        }
        /*else
        {

            i_right=0;
            i_up=0;
            i_left=1;
            i_down=0;
        }*/
        }
         if(i_left){lara=0;
        if(maze_for_enemymovement[i.y][i.x-1]==0&&ix!=i.x-1)
        {  lara=1;
        ix=i.x;
        iy=i.y;
          i.x=i.x-1;
          inky.recent.x=inky.recent.x-wall_width;

        }
        /*else
        {

            i_right=0;
            i_up=1;
            i_left=0;
            i_down=0;
        }*/
        }






        if(lara==0){
                         if(maze_for_enemymovement[i.y+1][i.x]==0&&iy!=i.y+1)
        {   iy=i.y;
        ix=i.x;
          i.y=i.y+1;
          inky.recent.y=inky.recent.y-wall_width;

            i_down=1;
            i_right=0;
            i_up=0;
            i_left=0;

        }
        else if(maze_for_enemymovement[i.y][i.x-1]==0&&ix!=i.x-1)
        {   ix=i.x;
        iy=i.y;
          i.x=i.x-1;
          inky.recent.x=inky.recent.x-wall_width;



            i_right=0;
            i_up=0;
            i_left=1;
            i_down=0;
        }
        else if(maze_for_enemymovement[i.y-1][i.x]==0&&iy!=i.y-1)
        {   iy=i.y;
        ix=i.x;
          i.y=i.y-1;
          inky.recent.y=inky.recent.y+wall_width;

            i_right=0;
            i_up=1;
            i_left=0;
            i_down=0;


        }



        else if(maze_for_enemymovement[i.y][i.x+1]==0&&ix!=i.x+1)
        {   ix=i.x;
            iy=i.y;
          i.x=i.x+1;
          inky.recent.x=inky.recent.x+wall_width;



            i_right=1;
            i_up=0;
            i_left=0;
            i_down=0;

        }


        }

}














else if(time_count>=25&&time_count<40||time_count>=47)

{       int maxd=1000;
        int flag;
        int distance;

        if(maze_for_enemymovement[i.y-1][i.x]!=1&&iy!=i.y-1)//up
        {   distance=(target_i.x-i.x)*(target_i.x-i.x)+(target_i.y-i.y+1)*(target_i.y-i.y+1);
            if(distance<maxd)
            {   flag=1;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[i.y][i.x-1]!=1&&ix!=i.x-1)//left
        {   distance=(target_i.x-i.x+1)*(target_i.x-i.x+1)+(target_i.y-i.y)*(target_i.y-i.y);
            if(distance<maxd)
            {   flag=2;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[i.y+1][i.x]!=1&&iy!=i.y+1)//down
        {   distance=(target_i.x-i.x)*(target_i.x-i.x)+(target_i.y-i.y-1)*(target_i.y-i.y-1);
            if(distance<maxd)
            {   flag=3;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[i.y][i.x+1]!=1&&ix!=i.x+1)//right
        {   distance=(target_i.x-i.x-1)*(target_i.x-i.x-1)+(target_i.y-i.y)*(target_i.y-i.y);
            if(distance<maxd)
            {   flag=4;
                maxd=distance;
            }
        }
        switch(flag)
        {   case 1:inky.recent.y=inky.recent.y+wall_width;
                    iy=i.y;
                    ix=i.x;
                   i.y=i.y-1;
                  i_position=u;
                    break;
            case 2:inky.recent.x=inky.recent.x-wall_width;
                   ix=i.x;
                    iy=i.y;
                    i.x=i.x-1;
                    if(i.x==0)
      {
         i.x=18;
          inky.recent.x=inky.recent.x+wall_width*18;

      }
                   i_position=l;
                    break;
            case 3:inky.recent.y=inky.recent.y-wall_width;
                    iy=i.y;
                    ix=i.x;
                   i.y=i.y+1;
                   i_position=d;
                   break;
            case 4:inky.recent.x=inky.recent.x+wall_width;
                    ix=i.x;
                    iy=i.y;
                    i.x=i.x+1;
                    if(i.x==18)
      {
          i.x=0;
          inky.recent.x=inky.recent.x-wall_width*18;

      }
                   i_position=r;
                    break;
        }

 }
     }
     if(!clyde_mode)
{
if(c.x==10&&c.y==9)
{  cx=c.x;
cy=c.y;
    c.x=c.x-1;
    c.y=c.y;
    clyde.recent.x=clyde.recent.x-wall_width;

}
else if(c.x==9&&c.y==9)
{
    c.x=c.x;
    cx=c.x;
    cy=c.y;
    c.y=c.y-1;
    clyde.recent.y=clyde.recent.y+wall_width;
}
else if(c.x==9&&c.y==8)
{
    c.x=c.x;
    cx=c.x;
    cy=c.y;
    c.y=c.y-1;
    clyde.recent.y=clyde.recent.y+wall_width;
}
else
{
        if(time_count<7){
        int maxd=1000;
        int flag;
        int distance;

        if(maze_for_enemymovement[c.y-1][c.x]!=1&&cy!=c.y-1)//up
        {   distance=(target_c.x-c.x)*(target_c.x-c.x)+(target_c.y-c.y+1)*(target_c.y-c.y+1);
            if(distance<maxd)
            {   flag=1;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[c.y][c.x-1]!=1&&cx!=c.x-1)//left
        {   distance=(target_c.x-c.x+1)*(target_c.x-c.x+1)+(target_c.y-c.y)*(target_c.y-c.y);
            if(distance<maxd)
            {   flag=2;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[c.y+1][c.x]!=1&&cy!=c.y+1)//down
        {   distance=(target_c.x-c.x)*(target_c.x-c.x)+(target_c.y-c.y-1)*(target_c.y-c.y-1);
            if(distance<maxd)
            {   flag=3;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[c.y][c.x+1]!=1&&cx!=c.x+1)//right
        {   distance=(target_c.x-c.x-1)*(target_c.x-c.x-1)+(target_c.y-c.y)*(target_c.y-c.y);
            if(distance<maxd)
            {   flag=4;
                maxd=distance;
            }
        }
        switch(flag)
        {   case 1:clyde.recent.y=clyde.recent.y+wall_width;
                    cy=c.y;
                    cx=c.x;
                   c.y=c.y-1;
                  c_position=u;
                    break;
            case 2:clyde.recent.x=clyde.recent.x-wall_width;
                   cx=c.x;
                    cy=c.y;
                   c.x=c.x-1;
                    if(c.x==0)
      {
         c.x=18;
          clyde.recent.x=clyde.recent.x+wall_width*18;

      }
                  c_position=l;
                    break;
            case 3:clyde.recent.y=clyde.recent.y-wall_width;
                    cy=c.y;
                    cx=c.x;
                   c.y=c.y+1;
                   c_position=d;
                   break;
            case 4:clyde.recent.x=clyde.recent.x+wall_width;
                cx=c.x;
                    cy=c.y;
                   c.x=c.x+1;
                    if(c.x==18)
      {
         c.x=0;
        clyde.recent.x=clyde.recent.x-wall_width*18;

      }
                 c_position=r;
                    break;
        }



        }
        if(time_count>=7){
        int maxd=1000;
        int flag;
        int distance;

        if(maze_for_enemymovement[c.y-1][c.x]!=1&&cy!=c.y-1)//up
        {   distance=(target_c.x-c.x)*(target_c.x-c.x)+(target_c.y-c.y+1)*(target_c.y-c.y+1);
            if(distance<maxd)
            {   flag=1;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[c.y][c.x-1]!=1&&cx!=c.x-1)//left
        {   distance=(target_c.x-c.x+1)*(target_c.x-c.x+1)+(target_c.y-c.y)*(target_c.y-c.y);
            if(distance<maxd)
            {   flag=2;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[c.y+1][c.x]!=1&&cy!=c.y+1)//down
        {   distance=(target_c.x-c.x)*(target_c.x-c.x)+(target_c.y-c.y-1)*(target_c.y-c.y-1);
            if(distance<maxd)
            {   flag=3;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[c.y][c.x+1]!=1&&cx!=c.x+1)//right
        {   distance=(target_c.x-c.x-1)*(target_c.x-c.x-1)+(target_c.y-c.y)*(target_c.y-c.y);
            if(distance<maxd)
            {   flag=4;
                maxd=distance;
            }
        }
        switch(flag)
        {   case 1:clyde.recent.y=clyde.recent.y+wall_width;
                    cy=c.y;
                    cx=c.x;
                   c.y=c.y-1;
                  c_position=u;
                    break;
            case 2:clyde.recent.x=clyde.recent.x-wall_width;
                   cx=c.x;
                    cy=c.y;
                   c.x=c.x-1;
                    if(c.x==0)
      {
         c.x=18;
          clyde.recent.x=clyde.recent.x+wall_width*18;

      }
                  c_position=l;
                    break;
            case 3:clyde.recent.y=clyde.recent.y-wall_width;
                    cy=c.y;
                    cx=c.x;
                   c.y=c.y+1;
                   c_position=d;
                   break;
            case 4:clyde.recent.x=clyde.recent.x+wall_width;
                cx=c.x;
                    cy=c.y;
                   c.x=c.x+1;
                    if(c.x==18)
      {
         c.x=0;
        clyde.recent.x=clyde.recent.x-wall_width*18;

      }
                 c_position=r;
                    break;
        }



        }

}
 }


 }



 }

























void pacman_die()
{   if(game_page){
    if(chase_scatter_mode==0){

    if((pos_x==b.x&&(pos_y==b.y-1||pos_y==b.y||pos_y==b.y+1))||(pos_y==b.y &&(pos_x==b.x-1||pos_x==b.x||pos_x==b.x+1)))
    {           if(blinky_mode==0)
                {show=1;
                m++;
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
                iPauseTimer(3);


                if(m==10)
                {
                    stop=1;
                    m=0;
                   PlaySound("pacman_death.wav",NULL,SND_SYNC);
                    live++;

                }
                }
    }
    else if((pos_x==p.x&&(pos_y==p.y-1||pos_y==p.y||pos_y==p.y+1))||(pos_y==p.y &&(pos_x==p.x-1||pos_x==p.x||pos_x==p.x+1)))
    {
        if(pinky_mode==0)
        {show=1;
                m++;
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
                iPauseTimer(3);

                if(m==10)
                {
                    stop=1;
                    m=0;
                    live++;
                    PlaySound("pacman_death.wav",NULL,SND_SYNC);

                }
        }
    }
    else if((pos_x==i.x&&(pos_y==i.y-1||pos_y==i.y||pos_y==i.y+1))||(pos_y==i.y &&(pos_x==i.x-1||pos_x==i.x||pos_x==i.x+1)))
    {
                if(inky_mode==0)
                {show=1;
                m++;
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
                iPauseTimer(3);

                if(m==10)
                {
                    stop=1;
                    m=0;
                    live++;
                    PlaySound("pacman_death.wav",NULL,SND_SYNC);
                }
                }

    }
    else if((pos_x==c.x&&(pos_y==c.y-1||pos_y==c.y||pos_y==c.y+1))||(pos_y==c.y &&(pos_x==c.x-1||pos_x==c.x||pos_x==c.x+1)))
    {
                if(clyde_mode==0)
                {show=1;
                m++;
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
                iPauseTimer(3);

                if(m==10)
                {
                    stop=1;
                    m=0;
                    live++;
                   PlaySound("pacman_death.wav",NULL,SND_SYNC);
                }
                }

    }
}
/* if((pos_x==b.x&&pos_y==b.y)||(pos_x==i.x&&pos_y==i.y)||(pos_x==p.x&&pos_y==p.y))
            {
               show=1;
                m++;
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
                iPauseTimer(3);
                iPauseTimer(4);
                if(m==10)
                {
                    stop=1;
                    m=0;
                }

            }
            if(((pacman_positionx-blinky.recent.x<=20&&pacman_positionx-blinky.recent.x>=-20) &&(pacman_positiony-blinky.recent.y<=20&& pacman_positiony-blinky.recent.y>=-20))||
                ((pacman_positionx-inky.recent.x<=20&&pacman_positionx-inky.recent.x>=-20) &&(pacman_positiony-inky.recent.y<=20&&pacman_positiony-inky.recent.y>=-20))||
                    ((pacman_positionx-pinky.recent.x<=20&&pacman_positionx-pinky.recent.x>=-20) &&(pacman_positiony-pinky.recent.y<=20&&pacman_positiony-pinky.recent.y>=-20))||
                    ((pacman_positionx-clyde.recent.x<=20&&pacman_positionx-clyde.recent.x>=-20) &&(pacman_positiony-clyde.recent.y<=20&&pacman_positiony-clyde.recent.y>=-20)))
                    {
                        show=1;
                m++;
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
                iPauseTimer(3);
                iPauseTimer(4);
                if(m==10)
                {
                    stop=1;
                    m=0;
                }

                    }


}*/
}

}
void again()
{   if(game_page)
{
    if(stop)
{
   pos_x=8;pos_y=13;
   pacman_positionx=pacman_initialpositionx;
   pacman_positiony=pacman_initialpositiony;
   target_c.x=5;
    target_c.y=18;
    b_position=u;
    p_position=u;
    i_position=u;
    c_position=u;
    b.x=9;
    b.y=7;
    p.x=8;
    p.y=9;
    i.x=9;
    i.y=9;
    c.y=9;
    c.x=10;
    bx=0,by=0,px=0,py=0;ix=0;iy=0,cx=0,cy=0;
    pinky.recent.x=pinky.initial.x;
    pinky.recent.y=pinky.initial.y;
    blinky.recent.x=blinky.initial.x;
    blinky.recent.y=blinky.initial.y;
     inky.recent.x=inky.initial.x;
    inky.recent.y=inky.initial.y;
     clyde.recent.x=clyde.initial.x;
    clyde.recent.y=clyde.initial.y;
    printf("%d\n",clyde.initial.x);
    printf("%d\n",clyde.initial.y);
     maze_for_enemymovement[8][9]=0;
     i_up=1;i_left=0;i_right=0;i_down=0;lara=0;
     time_count=0;
   iResumeTimer(0);
   iResumeTimer(1);
   iResumeTimer(2);
   iResumeTimer(3);
   iResumeTimer(4);
    show=0;
    stop=0;
    blinky_mode=0;
     inky_mode=0;
      pinky_mode=0;
       clyde_mode=0;}


}

}







//eat_food
void eat_food()
{ if(game_page)
{
if(maze_art[pos_y][pos_x]!=3)
{
if((pos_y==special_foodx1&&pos_x==special_foody1)||(pos_y==special_foodx2&&pos_x==special_foody1)||(pos_y==special_foodx1&&pos_x==special_foody2)|| (pos_y==special_foodx2&&pos_x==special_foody2))
{
     score=score+150;
        power++;
        itoa(power,power_pelletsarray,10);
     score_count();
}
else
{
    score=score+10;
    pellets++;
    itoa(pellets,pellets_countarray,10);
    score_count();
}
}
maze_art[pos_y][pos_x]=3;

}

}
void frightend_mode()
{   if(game_page)
    {
    time_fright++;
    if(maze_art[pos_y][pos_x]!=3){
    if((pos_y==special_foodx1&&pos_x==special_foody1)||(pos_y==special_foodx2&&pos_x==special_foody1)||(pos_y==special_foodx1&&pos_x==special_foody2)|| (pos_y==special_foodx2&&pos_x==special_foody2))
    {
        chase_scatter_mode=1;
        iPauseTimer(6);
        iPauseTimer(7);
        mode1=1;
        mode2=1;
        mode3=1;
        mode4=1;
    }
}


if(time_fright==60)
{

  if(!blinky_mode)

  {mode1=0;}
  if(!pinky_mode)
  {
      mode2=0;
  }
    if(!inky_mode)
        {
             mode3=0;
        }
 if(!clyde_mode)
 {
 mode4=0;
 }
 chase_scatter_mode=0;
  time_fright=0;
  iResumeTimer(6);
  iResumeTimer(7);

}



}
}
void eating_mode()
{
    if(game_page){
    if(chase_scatter_mode)
    {

    if((pos_x==b.x&&(pos_y==b.y-1||pos_y==b.y||pos_y==b.y+1))||(pos_y==b.y &&(pos_x==b.x-1||pos_x==b.x||pos_x==b.x+1)))
    {

      blinky_mode=1;
      mode1=2;
       T=true;
      if(T)
      {
       //PlaySound("pacman_eatghost.wav",NULL,SND_SYNC);
        T=false;
      }

     /* iPauseTimer(7);
      iResumeTimer(8);*/

    }

    if((pos_x==p.x&&(pos_y==p.y-1||pos_y==p.y||pos_y==p.y+1))||(pos_y==p.y &&(pos_x==p.x-1||pos_x==p.x||pos_x==p.x+1)))
    {
      pinky_mode=1;
      mode2=2;
      T=true;
      if(T)
      {
       //PlaySound("pacman_eatghost.wav",NULL,SND_SYNC);
        T=false;
      }

    }
    if((pos_x==i.x&&(pos_y==i.y-1||pos_y==i.y||pos_y==i.y+1))||(pos_y==i.y &&(pos_x==i.x-1||pos_x==i.x||pos_x==i.x+1)))
    {
     inky_mode=1;
    mode3=2;
      T=true;
      if(T)
      {
       //PlaySound("pacman_eatghost.wav",NULL,SND_SYNC);
        T=false;
      }
    }
    if((pos_x==c.x&&(pos_y==c.y-1||pos_y==c.y||pos_y==c.y+1))||(pos_y==c.y &&(pos_x==c.x-1||pos_x==c.x||pos_x==c.x+1)))
    {
      clyde_mode=1;
      mode4=2;
        T=true;
      if(T)
      {
       //PlaySound("pacman_eatghost.wav",NULL,SND_SYNC);
        T=false;
      }

    }
}
if(blinky_mode){
        if(b.x==target_b.x&&b.y==target_b.y)
        {   ghost++;
      itoa(ghost,ghost_eaten_array,10);
            blinky_mode=0;
            mode1=0;
/*iResumeTimer(7);
            iResumeTimer(8);*/

    }
      int maxd=1000;
        int flag;
        int distance;

        up_b.x=b.x;
        up_b.y=b.y-1;
        left_b.x=b.x-1;
        left_b.y=b.y;
        down_b.x=b.x;
        down_b.y=b.y+1;
        right_b.x=b.x+1;
        right_b.y=b.y;
        if(maze_for_enemymovement[up_b.y][up_b.x]!=1&&by!=up_b.y)
        {   distance=(target_b.x-up_b.x)*(target_b.x-up_b.x)+(target_b.y-up_b.y)*(target_b.y-up_b.y);
            if(distance<maxd)
            {   flag=1;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[left_b.y][left_b.x]!=1&&bx!=left_b.x)
        {   distance=(target_b.x-left_b.x)*(target_b.x-left_b.x)+(target_b.y-left_b.y)*(target_b.y-left_b.y);
            if(distance<maxd)
            {   flag=2;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[down_b.y][down_b.x]!=1&&by!=down_b.y)
        {   distance=(target_b.x-down_b.x)*(target_b.x-down_b.x)+(target_b.y-down_b.y)*(target_b.y-down_b.y);
            if(distance<maxd)
            {   flag=3;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[right_b.y][right_b.x]!=1&&bx!=right_b.x)
        {   distance=(target_b.x-right_b.x)*(target_b.x-right_b.x)+(target_b.y-right_b.y)*(target_b.y-right_b.y);
            if(distance<maxd)
            {   flag=4;
                maxd=distance;
            }
        }
        switch(flag)
        {   case 1:blinky.recent.y=blinky.recent.y+wall_width;
                    by=b.y;
                    bx=b.x;
                    b.y=b.y-1;
                   /* if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }
           */         b_position=u;
                    break;
            case 2:blinky.recent.x=blinky.recent.x-wall_width;
                    bx=b.x;
                    by=b.y;
                    b.x=b.x-1;
                /* if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
                    if(b.x==0)

      {
          b.x=18;
          blinky.recent.x=blinky.recent.x+wall_width*18;

      }

                   b_position=l;
                    break;
            case 3:blinky.recent.y=blinky.recent.y-wall_width;
                    by=b.y;
                    bx=b.x;
                   b.y=b.y+1;
                   /*if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
                   b_position=d;
                   break;
            case 4:blinky.recent.x=blinky.recent.x+wall_width;
                    bx=b.x;
                    by=b.y;

         b.x=b.x+1;
        /* if((b.x==8||b.x==9||b.x==10)&&(b.y==9))
         {
             bx=0;
             by=0;
         }*/
                    if(b.x==18)
     {
         b.x=0;
         blinky.recent.x=blinky.recent.x-wall_width*18;
     }

                    b_position=r;
                    break;
        }


    }

   if(clyde_mode)
    {   if(c.x==target_c.x&&c.y==target_c.y)
            {   ghost++;
      itoa(ghost,ghost_eaten_array,10);
                mode4=0;
                clyde_mode=0;
            }
        int maxd=1000;
        int flag;
        int distance;

        if(maze_for_enemymovement[c.y-1][c.x]!=1&&cy!=c.y-1)//up
        {   distance=(target_c.x-c.x)*(target_c.x-c.x)+(target_c.y-c.y+1)*(target_c.y-c.y+1);
            if(distance<maxd)
            {   flag=1;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[c.y][c.x-1]!=1&&cx!=c.x-1)//left
        {   distance=(target_c.x-c.x+1)*(target_c.x-c.x+1)+(target_c.y-c.y)*(target_c.y-c.y);
            if(distance<maxd)
            {   flag=2;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[c.y+1][c.x]!=1&&cy!=c.y+1)//down
        {   distance=(target_c.x-c.x)*(target_c.x-c.x)+(target_c.y-c.y-1)*(target_c.y-c.y-1);
            if(distance<maxd)
            {   flag=3;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[c.y][c.x+1]!=1&&cx!=c.x+1)//right
        {   distance=(target_c.x-c.x-1)*(target_c.x-c.x-1)+(target_c.y-c.y)*(target_c.y-c.y);
            if(distance<maxd)
            {   flag=4;
                maxd=distance;
            }
        }
        switch(flag)
        {   case 1:clyde.recent.y=clyde.recent.y+wall_width;
                    cy=c.y;
                    cx=c.x;
                   c.y=c.y-1;
                  c_position=u;
                    break;
            case 2:clyde.recent.x=clyde.recent.x-wall_width;
                   cx=c.x;
                    cy=c.y;
                   c.x=c.x-1;
                    if(c.x==0)
      {
         c.x=18;
          clyde.recent.x=clyde.recent.x+wall_width*18;

      }
                  c_position=l;
                    break;
            case 3:clyde.recent.y=clyde.recent.y-wall_width;
                    cy=c.y;
                    cx=c.x;
                   c.y=c.y+1;
                   c_position=d;
                   break;
            case 4:clyde.recent.x=clyde.recent.x+wall_width;
                cx=c.x;
                    cy=c.y;
                   c.x=c.x+1;
                    if(c.x==18)
      {
         c.x=0;
        clyde.recent.x=clyde.recent.x-wall_width*18;

      }
                 c_position=r;
                    break;
        }



        }
        if(inky_mode)

    {       if(i.x==target_i.x&&i.y==target_i.y)
    {
        ghost++;
      itoa(ghost,ghost_eaten_array,10);
        mode3=0;
        inky_mode=0;
    }
        int maxd=1000;
        int flag;
        int distance;

        if(maze_for_enemymovement[i.y-1][i.x]!=1&&iy!=i.y-1)//up
        {   distance=(target_i.x-i.x)*(target_i.x-i.x)+(target_i.y-i.y+1)*(target_i.y-i.y+1);
            if(distance<maxd)
            {   flag=1;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[i.y][i.x-1]!=1&&ix!=i.x-1)//left
        {   distance=(target_i.x-i.x+1)*(target_i.x-i.x+1)+(target_i.y-i.y)*(target_i.y-i.y);
            if(distance<maxd)
            {   flag=2;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[i.y+1][i.x]!=1&&iy!=i.y+1)//down
        {   distance=(target_i.x-i.x)*(target_i.x-i.x)+(target_i.y-i.y-1)*(target_i.y-i.y-1);
            if(distance<maxd)
            {   flag=3;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[i.y][i.x+1]!=1&&ix!=i.x+1)//right
        {   distance=(target_i.x-i.x-1)*(target_i.x-i.x-1)+(target_i.y-i.y)*(target_i.y-i.y);
            if(distance<maxd)
            {   flag=4;
                maxd=distance;
            }
        }
        switch(flag)
        {   case 1:inky.recent.y=inky.recent.y+wall_width;
                    iy=i.y;
                    ix=i.x;
                   i.y=i.y-1;
                  i_position=u;
                    break;
            case 2:inky.recent.x=inky.recent.x-wall_width;
                   ix=i.x;
                    iy=i.y;
                    i.x=i.x-1;
                    if(i.x==0)
      {
         i.x=18;
          inky.recent.x=inky.recent.x+wall_width*18;

      }
                   i_position=l;
                    break;
            case 3:inky.recent.y=inky.recent.y-wall_width;
                    iy=i.y;
                    ix=i.x;
                   i.y=i.y+1;
                   i_position=d;
                   break;
            case 4:inky.recent.x=inky.recent.x+wall_width;
                    ix=i.x;
                    iy=i.y;
                    i.x=i.x+1;
                    if(i.x==18)
      {
          i.x=0;
          inky.recent.x=inky.recent.x-wall_width*18;

      }
                   i_position=r;
                    break;
        }

    }
    if(pinky_mode)
    {
        if(p.x==target_p.x&&p.y==target_p.y)
        {   ghost++;
      itoa(ghost,ghost_eaten_array,10);
            mode2=0;
            pinky_mode=0;
        }

    int maxd=1000;
        int flag;
        int distance;
        up_p.x=p.x;
        up_p.y=p.y-1;
        left_p.x=p.x-1;
        left_p.y=p.y;
        down_p.x=p.x;
        down_p.y=p.y+1;
        right_p.x=p.x+1;
        right_p.y=p.y;
        if(maze_for_enemymovement[up_p.y][up_p.x]!=1&&py!=up_p.y)
        {   distance=(target_p.x-up_p.x)*(target_p.x-up_p.x)+(target_p.y-up_p.y)*(target_p.y-up_p.y);
            if(distance<maxd)
            {   flag=1;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[left_p.y][left_p.x]!=1&&px!=left_p.x)
        {   distance=(target_p.x-left_p.x)*(target_p.x-left_p.x)+(target_p.y-left_p.y)*(target_p.y-left_p.y);
            if(distance<maxd)
            {   flag=2;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[down_p.y][down_p.x]!=1&&py!=down_p.y)
        {   distance=(target_p.x-down_b.x)*(target_p.x-down_b.x)+(target_p.y-down_b.y)*(target_p.y-down_b.y);
            if(distance<maxd)
            {   flag=3;
                maxd=distance;
            }
        }
        if(maze_for_enemymovement[right_p.y][right_p.x]!=1&&px!=right_p.x)
        {   distance=(target_p.x-right_p.x)*(target_p.x-right_p.x)+(target_p.y-right_p.y)*(target_p.y-right_p.y);
            if(distance<maxd)
            {   flag=4;
                maxd=distance;
            }
        }
        switch(flag)
        {   case 1:pinky.recent.y=pinky.recent.y+wall_width;
                    py=p.y;
                    px=p.x;
                    p.y=p.y-1;
                    p_position=u;
                    break;
            case 2:pinky.recent.x=pinky.recent.x-wall_width;
                    px=p.x;
                    py=p.y;
                    p.x=p.x-1;
                    if(p.x==0)
      {
          p.x=18;
          pinky.recent.x=pinky.recent.x+wall_width*18;

      }
                   p_position=l;
                    break;
            case 3:pinky.recent.y=pinky.recent.y-wall_width;
                    py=p.y;
                    px=p.x;
                   p.y=p.y+1;
                   p_position=d;
                   break;
            case 4:pinky.recent.x=pinky.recent.x+wall_width;
                    px=p.x;
                    py=p.y;
                    p.x=p.x+1;
                    if(p.x==18)
      {
          p.x=0;
          pinky.recent.x=pinky.recent.x-wall_width*18;

      }
                    p_position=r;
                    break;
        }

 }










    }




        }
//pacman_type_change


//PACMAN_MOVE








void pacman_move()
{   if(game_page){
    if(left||right||down||up)
{


    pac++;
    if(pac>2)
    {
        pac=0;
    }
}

    if(right)
    {
        if(maze_art[pos_y][pos_x+1]!=1)
        {
            eat_food();
            pacman_positionx=pacman_positionx+wall_width;
            if (chase_scatter_mode)
            {
                if(!blinky_mode)
                {
                    target_b.x=pos_x+5;
                    target_b.y=pos_y;
                }
                else
                {
                    target_b.x=9;
                    target_b.y=7;
                }
                if(!pinky_mode)
                {
                    target_p.x=pos_x-5;
                    target_p.y=pos_y;
                }
                else
                {
                    target_p.x=9;
                    target_p.y=7;
                }
                if(!inky_mode)
                {
                    target_i.x=pos_x;
                    target_i.y=pos_y-5;
                }
                else
                {
                    target_i.x=9;
                    target_i.y=7;
                }
            }
            if(!chase_scatter_mode)
            {
                target_p.x=pos_x+5;
                target_p.y=pos_y;
                target_i.y=pos_y+5;
                target_i.x=pos_x;
                if(blinky_mode)
                {
                    target_b.x=9;
                    target_b.y=7;
                }
                else
                {
                    target_b.x=pos_x;
                    target_b.y=pos_y;


                }
            }


            if(time_count>=7)
            {
                if(chase_scatter_mode)
                {
                    if(!clyde_mode)
                    {
                        target_c.y=pos_y+10;
                        target_c.x=pos_x;
                    }
                    else
                    {
                        target_c.x=9;
                        target_c.y=7;
                    }

                }
                else
                {
                    if(clyde_mode)
                    {
                        target_c.y=7;
                        target_c.x=9;
                    }
                    else
                    {
                        target_c.y=pos_y-10;
                        target_c.x=pos_x;
                    }
                }
            }
            pos_x=pos_x+1;
        }
        else
        {
            right=0;
            pac=2;

        }
        if(pos_x==18&&pos_y==9)
        {
            if(clyde_mode)
            {
                target_c.y=7;
                target_c.x=9;
            }
            eat_food();
            pos_x=0;
            target_p.x=pos_x+ 5;
            target_p.y=pos_y;
            target_i.y=pos_y+5;
            target_i.x=pos_x;
            target_b.x=pos_x;
            target_b.y=pos_y;
            if(time_count>=7)
            {
                if(clyde_mode)
                {
                    target_c.y=7;
                    target_c.x=9;
                }
                else
                {
                    target_c.y=pos_y-10;
                    target_c.x=pos_x;
                }
            }

            pacman_positionx=pacman_positionx-18*wall_width;
        }
        if(clyde_mode)
        {
            target_c.y=7;
            target_c.x=9;
        }
        if(pinky_mode)
        {
            target_p.y=7;
            target_p.x=9;
        }
        if(inky_mode)
        {
            target_i.y=7;
            target_i.x=9;
        }



    }
    if(up)
    {


        if(maze_art[pos_y-1][pos_x]!=1)
        {
            eat_food();
            pacman_positiony= pacman_positiony+wall_width;
            if(!chase_scatter_mode)
            {
                target_p.y=pos_y-5;
                target_p.x=pos_x;
                target_i.y=pos_y;
                target_i.x=pos_x+5;
                if(blinky_mode)
                {
                    target_b.x=9;
                    target_b.y=7;
                }
                else
                {
                    target_b.x=pos_x;
                    target_b.y=pos_y;
                }
            }
            else
            {
                if(!blinky_mode)
                {
                    target_b.x=pos_x;
                    target_b.y=pos_y+5;
                }
                else
                {
                    target_b.x=9;
                    target_b.y=7;
                }
                if(!pinky_mode)
                {
                    target_p.y=pos_y+5;
                    target_p.x=pos_x;
                }
                else
                {
                    target_p.x=9;
                    target_p.y=7;
                }
                if(!inky_mode)
                {
                    target_i.y=pos_y;
                    target_i.x=pos_x-5;
                }
                else
                {
                    target_i.x=9;
                    target_i.y=7;
                }



            }
            if(time_count>=7)
            {
                if(chase_scatter_mode)
                {
                    if(!clyde_mode)
                    {
                        target_c.y=pos_y;
                        target_c.x=pos_x+10;
                    }
                    else
                    {
                        target_c.x=9;
                        target_c.y=7;
                    }

                }
                else
                {
                    if(clyde_mode)
                    {
                        target_c.y=7;
                        target_c.x=9;
                    }
                    else
                    {
                        target_c.y=pos_y;
                        target_c.x=pos_x-10;
                    }

                }

            }
            pos_y=pos_y-1;
        }
        else
        {
            up=0;
            pac=2;

        }
        if(clyde_mode)
        {
            target_c.y=7;
            target_c.x=9;
        }

        if(pinky_mode)
        {
            target_p.y=7;
            target_p.x=9;
        }
        if(inky_mode)
        {
            target_i.y=7;
            target_i.x=9;
        }



    }
    if(down)
    {
        if(maze_art[pos_y+1][pos_x]!=1)
        {
            eat_food();

            pacman_positiony=pacman_positiony-wall_width;
            if(chase_scatter_mode)
            {
                if(!blinky_mode)
                {
                    target_b.y=pos_y+10;
                    target_b.x=pos_x;
                }
                else
                {
                    target_b.y=7;
                    target_b.x=9;
                }

                if(!pinky_mode)
                {
                    target_p.y=pos_y-5;
                    target_p.x=pos_x;
                }
                else
                {
                    target_p.x=9;
                    target_p.y=7;
                }

                if(!inky_mode)
                {
                    target_i.y=pos_y;
                    target_i.x=pos_x+5;
                }
                else
                {
                    target_i.x=9;
                    target_i.y=7;
                }

            }
            else
            {
                target_p.y=pos_y+5;
                target_p.x=pos_x;
                target_i.y=pos_y;
                target_i.x=pos_x-5;
                if(blinky_mode)
                {
                    target_b.x=9;
                    target_b.y=7;
                }
                else
                {
                    target_b.x=pos_x;
                    target_b.y=pos_y;
                }

            }
            if(time_count>=7)
            {
                if(chase_scatter_mode)
                {
                    if(clyde_mode)
                    {
                        target_c.x=9;
                        target_c.y=7;
                    }
                    else
                    {
                        target_c.y=pos_y;
                        target_c.x=pos_x-15;
                    }

                }
                else

                {
                    if(clyde_mode)
                    {
                        target_c.x=9;
                        target_c.y=7;
                    }

                    else
                    {
                        target_c.y=pos_y;
                        target_c.x=pos_x+10;
                    }
                }
            }
            pos_y=pos_y+1;
        }
        else
        {

            pac=1;
        }
        if(clyde_mode)
        {
            target_c.x=9;
            target_c.y=7;
        }
        if(pinky_mode)
        {
            target_p.y=7;
            target_p.x=9;
        }
        if(inky_mode)
        {
            target_i.y=7;
            target_i.x=9;
        }






    }


    if(left)
    {
        if(maze_art[pos_y][pos_x-1]!=1)
        {
            eat_food();
            pacman_positionx=pacman_positionx-wall_width;
            if(chase_scatter_mode)
            {
                if(!blinky_mode)
                {
                    target_b.x=pos_x-10;
                    target_b.y=pos_y;
                }
                else
                {
                    target_b.x=9;
                    target_b.y=7;
                }
                if(!pinky_mode)
                {
                    target_p.x=pos_x+5;
                    target_p.y=pos_y;
                }
                else
                {
                    target_p.x=9;
                    target_p.y=7;
                }
                if(!inky_mode)
                {
                    target_i.y=pos_y+5;
                    target_i.x=pos_x;
                }
                else
                {

                    target_i.x=9;
                    target_i.y=7;
                }
            }
            else
            {
                if(blinky_mode)
                {
                    target_b.x=9;
                    target_b.y=7;
                }
                else
                {
                    target_b.x=pos_x;
                    target_b.y=pos_y;
                }

                target_p.x=pos_x-5;
                target_p.y=pos_y;
                target_i.y=pos_y-5;
                target_i.x=pos_x;
            }
            if(time_count>=7)
            {
                if(chase_scatter_mode)
                {
                    if(clyde_mode)
                    {

                        target_c.y=pos_y-15;
                        target_c.x=pos_x;
                    }
                    else
                    {
                        target_c.y=7;
                        target_c.x=9;
                    }
                }
                else
                {
                    target_c.y=pos_y+10;
                    target_c.x=pos_x;
                }
            }
            pos_x=pos_x-1;
        }
        else
        {

            pac=2;

        }
        if(pos_x==0&&pos_y==9)
        {
            eat_food();
            target_p.x=pos_x-5;
            target_p.y=pos_y;
            target_i.y=pos_y-5;
            target_i.x=pos_x;
            target_b.x=pos_x;
            target_b.y=pos_y;
            pos_x=18;
            if(time_count>=7)
            {
                target_c.y=pos_y+10;
                target_c.x=pos_x;
            }
            pacman_positionx=pacman_positionx+18*wall_width;
        }
        if(clyde_mode)
        {
            target_c.x=9;
            target_c.y=7;
        }
        if(pinky_mode)
        {
            target_p.y=7;
            target_p.x=9;
        }
        if(inky_mode)
        {
            target_i.y=7;
            target_i.x=9;
        }
    }

}
}
void iDraw()
{
	//place your drawing codes here

	iClear();
	if(game_page)
    {
	if(live<3){
	iSetColor(255,255,255);
	maze();
	iSetColor(242,188,0);
	food();
    iShowBMP2(pacman_positionx,pacman_positiony,pacman_pic[pac_no][pac],color[pac_no]);
    iShowBMP(pinky.recent.x,pinky.recent.y,enemy_pic_pinky[p_position][mode2]);
     iShowBMP(inky.recent.x,inky.recent.y,enemy_pic_inky[i_position][mode3]);
     iShowBMP(blinky.recent.x,blinky.recent.y,enemy_pic_blinky[b_position][mode1]);
     iShowBMP(clyde.recent.x,clyde.recent.y,enemy_pic_clyde[c_position][mode4]);
     iText(1032,617,"YOUR SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
     iText(1200,617,str_score,GLUT_BITMAP_TIMES_ROMAN_24);
     iText(1032,650,"TIME:",GLUT_BITMAP_TIMES_ROMAN_24);
     iText(1232,650,time_countarray,GLUT_BITMAP_TIMES_ROMAN_24);
      iText(1220,650,":",GLUT_BITMAP_TIMES_ROMAN_24);
     iText(1200,650,min_countarray,GLUT_BITMAP_TIMES_ROMAN_24);
     if(show)
     {      iSetColor(255,255,255);
         iText(610,325,"LOST A LIFE!!",GLUT_BITMAP_TIMES_ROMAN_24);
     }
        iText(100,650,"EXISTING LIVES",GLUT_BITMAP_TIMES_ROMAN_24);
     for(j=live;j<3;j++)
     {
       iShowBMP(100+j*40,600,"pacman 3.bmp");
     }
     iSetColor(242,188,0);
     if(pause)
     {
       iShowBMP2(100,100,"PAUSE.bmp",0);
     }

     else
     {
      iShowBMP2(100,100,"PAUSE2.bmp",0);
     }
    if(resume)
    {
        iShowBMP2(1000,100,"RESUME2.bmp",0);
    }
    else
    {
     iShowBMP2(1000,100,"RESUME.bmp",0);
    }

	}
	else
    {   //iShowBMP(0,0,"game_over_menu.bmp");
        iShowBMP(0,0,"game over.bmp");
        iSetColor(242,188,0);
        iText(750,520,str_score,GLUT_BITMAP_TIMES_ROMAN_24);
         iText(820,465,time_countarray,GLUT_BITMAP_TIMES_ROMAN_24);
      iText(770,465,"min",GLUT_BITMAP_TIMES_ROMAN_24);
     iText(750,465,min_countarray,GLUT_BITMAP_TIMES_ROMAN_24);
     iText(850,465,"sec",GLUT_BITMAP_TIMES_ROMAN_24);
     iText(750,400,pellets_countarray,GLUT_BITMAP_TIMES_ROMAN_24);
     iText(750,270,ghost_eaten_array,GLUT_BITMAP_TIMES_ROMAN_24);
     iText(750,335,power_pelletsarray,GLUT_BITMAP_TIMES_ROMAN_24);
     //iText(250,100,name,GLUT_BITMAP_TIMES_ROMAN_24);
     iRectangle(245,65,400,100);
     if(mode)
     {
         iText(250,80,name_array[level],GLUT_BITMAP_TIMES_ROMAN_24);
     }

    }   if(T){
      PlaySound("pacman_beginning.wav",NULL,SND_SYNC);
      T=false;
    }
    }
  if(menu_page)
    {   T=true;
        iShowBMP(0,0,"menu.bmp");
    //PlaySound("pacman_intermission.wav",NULL,SND_LOOP);

    }
    if(instruction_page)
    {   PlaySound("pacman_beginning.wav",NULL,SND_SYNC);
       iShowBMP(0,0,"instruction_page.bmp") ;
        iSetColor(242,188,0);
        iText(1000,100,"GO TO MAIN PAGE",GLUT_BITMAP_TIMES_ROMAN_24);
    }

}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx,  my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my)  is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{   printf("mx=%d  my=%d\n",mx,my);
	if(menu_page)
    {
    if(mx>=540&&mx<=720&&my>=440&&my<=490)
    {
        game_page=1;
        menu_page=0;
       resume_page=1;
       instruction_page=0;


    }
    if(mx>=528&&my>=378&&mx<=738&&my<=417)
    {
        game_page=1;
        menu_page=0;
        new_game=1;
        instruction_page=0;
    }
    if(mx>=500&&my>=180&&mx<=765&&my<=225)
       {
           instruction_page=1;
            game_page=0;
        menu_page=0;
        new_game=0;

       }
       if( my>=60&&mx>=588 &&mx<=671  &&my<=95)
       {
           exit(1);
       }

    }
    if(game_page)
    {


		if(pause==0)
    {
     if(mx>=100&&mx<=205&&my>=100&&my<=177)
     {
         iPauseTimer(0);
         iPauseTimer(1);
         iPauseTimer(2);
         iPauseTimer(3);
         iPauseTimer(3);
         iPauseTimer(4);
         iPauseTimer(5);
         iPauseTimer(6);
         iPauseTimer(7);
         iPauseTimer(8);


         pause=1;
         resume=0;


     }


	}
	if(resume==0)
    {
        if(mx>=1000&&mx<=1290&&my>=100&&my<=150)
       {

        iResumeTimer(0);
        iResumeTimer(1);
        iResumeTimer(2);
        iResumeTimer(3);
        iResumeTimer(4);
        iResumeTimer(5);
        iResumeTimer(6);
        iResumeTimer(7);
        iResumeTimer(8);



        resume=1;
        pause=0;
        }
    }

	/*if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}*/
    }
    if(live==3)
    {


		//place your codes here
		if(mx>=245&&mx<=540&&my>=65&&my<=150)
		{
			mode = 1;
		}

        if(mx>=904&&my>=83&&mx<=1169&&my<=118)
        {
            menu_page=1;
            game_page=0;

        }
    }

    }
    if(instruction_page)
    {
        if(mx>=1000&&mx<=1220&&my<=120&&my>=100)
        {
            menu_page=1;
            instruction_page=0;
        }
    }

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{  FILE *fp;
	if(key == 'q')
	{   if(live<3)
        {

        fp=fopen("reload.text","w");
        //fprintf(fp,"%c%c%c%c",'u','u','u','u');
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d",target_c.x,target_c.y,b.x,b.y,p.x,p.y,i.x,i.y,c.y,c.x);
        fprintf(fp," %d %d %d %d %d %d %d %d \n",pinky.recent.x,pinky.recent.y,blinky.recent.x,blinky.recent.y,inky.recent.x,inky.recent.y,clyde.recent.x,clyde.recent.y);
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d \n",chase_scatter_mode,time_fright,pause,resume,mode1,mode2,mode3,mode4,show,stop,m,live);
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d \n",j,i_up,i_left,i_right,i_down,lara,time_count,time_count_forshow,time_min,score);
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",pellets,ghost,power,pac_no,pac,bx,by,px,py,ix,iy,cx,cy,down,left,right,up);
        fprintf(fp," %d %d %d %d %d\n",pos_x,pos_y,pacman_positionx,pacman_positiony,level);
        for(int i=0;i<21;i++)
        {
            for(int k=0;k<19;k++)
            {
                fprintf(fp,"%d ",maze_art[i][k]);
            }
           fputc('\n',fp);
        }
        fputs(str_score,fp);
        fprintf(fp,"%c",'\n');
        fputs(time_countarray,fp);
        fprintf(fp,"%c",'\n');
        fputs(pellets_countarray,fp);
        fprintf(fp,"%c",'\n');
        fputs(ghost_eaten_array,fp);
         fprintf(fp,"%c",'\n');
          fputs(power_pelletsarray,fp);
        fclose(fp);
        }
		exit(0);
	}
    if(live==3)
    {

	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(name_array[level],name);
			name_array[level][len]='\0';
			//printf("%s\n", str2);
			for(int i=0;i<len;i++)
            {
                name[i]=0;
            }

			len = 0;
			}
		else
		{
			name[len] = key;
			len++;
		}






		fp=fopen("highscore.text","w");


        strcpy(highscore_array[level],str_score);

               for(opp=0;opp<level;opp++)
               {   // printf("%d\n",i);
                   for(kop=0;kop<level-opp;kop++)
                   {
                        char swap_string[100]={'0'};
                        char wap_string[100]={'0'};
                       if(atoi(highscore_array[kop])<atoi(highscore_array[kop+1]))
                       {
                          strcpy(swap_string,highscore_array[kop]);
                          strcpy(highscore_array[kop],highscore_array[kop+1]);

                          strcpy(highscore_array[kop+1],swap_string);

                          strcpy(wap_string,name_array[kop]);
                          strcpy(name_array[kop],name_array[kop+1]);

                          strcpy(name_array[kop+1],wap_string);


                       }

                   }
                  // printf("\n%s %s\n",name_array[opp],highscore_array[opp]);
               }
               for(int i=0;i<=level;i++)
               {
                   strcat(highscore_array[i],"\n");
                   strcat(name_array[i],"\n");
               }
               for(mor2=0;mor2<level&&mor2<5;mor2++)
               {    //printf("%s %s\n",name_array[mor2],highscore_array[mor2]);
                  fputs(highscore_array[mor2],fp);




               }
                fclose(fp);
                FILE *cp;
                cp=fopen("name.text","w");
               for(mor3=0;mor3<level&&mor3<5;mor3++)
               {    //printf("%s %s\n",name_array[mor2],highscore_array[mor2]);

                  fputs(name_array[mor3],cp);


               }
               fclose(cp);


	}

}
}
/*
function iSpecialKeyboard() is called whenver user hits special keys like- function keys, home, end, pg up, pg down, arraows etc. you have to use appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT  */

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	else{
	if(key==GLUT_KEY_DOWN)
    {

    down=1;
    pac_no=1;
    left=0;
    right=0;
    up=0;
    }
    if(key==GLUT_KEY_LEFT)
    {
    pac_no=0;
    left=1;
    down=0;
    right=0;
    up=0;

    }
    if(key==GLUT_KEY_RIGHT)
    {
    pac_no=2;
    left=0;
    down=0;
    right=1;
    up=0;

    }
    if(key==GLUT_KEY_UP)
    {
    pac_no=3;
    left=0;
    down=0;
    right=0;
    up=1;

    }}
	//place your codes for other keys here
}
void game_over()
{   if(game_page)
{
    if(live==3)
    {
        iPauseTimer(0);
        iPauseTimer(1);
        iPauseTimer(2);
        iPauseTimer(3);
        iPauseTimer(4);
        iPauseTimer(5);
        iPauseTimer(6);
        iPauseTimer(7);
       // scanf("%s",name);
         FILE *fp;

            //   for(int i=0;i<level;i++)


        fp=fopen("helloworld.text","w");
        //fprintf(fp,"%c%c%c%c",'u','u','u','u');
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d",5,18,9,7,8,9,9,9,9,10);
        fprintf(fp," %d %d %d %d %d %d %d %d",pinky.initial.x,pinky.initial.y,blinky.initial.x,blinky.initial.y,inky.initial.x,inky.initial.y,clyde.initial.x,clyde.initial.y);
         fprintf(fp," %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0);
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d\n",0,1,0,0,0,0,0,0,0,0);
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0);
        fprintf(fp," %d %d %d %d %d\n",8,13,pacman_initialpositionx,pacman_initialpositiony,level+1);
        for(int i=0;i<21;i++)
        {
            for(int k=0;k<19;k++)
            {
                fprintf(fp,"%d ",maze_artcopy[i][k]);
            }
           fputc('\n',fp);
        }


        fclose(fp);
    }


}
}
void game()
{
    if(game_page)
    {  if(new_game)
       {FILE* fp;
    fp=fopen("helloworld.text","r");
    //fscanf(fp,"%c %c %c %c",&b_position,&p_position, &i_position, &c_position);
    fscanf(fp,"%d",&target_c.x);

    fscanf(fp,"%d",&target_c.y);

    fscanf(fp,"%d",&b.x);
    fscanf(fp,"%d",&b.y);
    fscanf(fp,"%d",&p.x);
    fscanf(fp,"%d",&p.y);
    fscanf(fp,"%d",&i.x);
    fscanf(fp,"%d",&i.y);
    fscanf(fp,"%d",&c.y);
    fscanf(fp,"%d",&c.x);
    fscanf(fp,"%d",&pinky.recent.x);
    fscanf(fp,"%d",&pinky.recent.y);
    fscanf(fp,"%d",&blinky.recent.x);
    fscanf(fp,"%d",&blinky.recent.y);
    fscanf(fp,"%d",&inky.recent.x);
    fscanf(fp,"%d",&inky.recent.y);
    fscanf(fp,"%d",&clyde.recent.x);
    fscanf(fp,"%d",&clyde.recent.y);
    fscanf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d",&chase_scatter_mode,&time_fright,&pause,&resume,&mode1,&mode2,&mode3,&mode4,&show,&stop,&m,&live,&j);
    fscanf(fp,"%d %d %d %d %d %d %d %d %d",&i_up,&i_left,&i_right,&i_down,&lara,&time_count,&time_count_forshow,&time_min,&score);
    fscanf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&pellets,&ghost,&power,&pac_no,&pac,&bx,&by,&px,&py,&ix,&iy,&cx,&cy,&down,&left,&right,&up);
    fscanf(fp,"%d %d %d %d %d",&pos_x,&pos_y,&pacman_positionx,&pacman_positiony,&level);
   // printf("%d %d %d %d %d",&pos_x,&pos_y,&pacman_positionx,&pacman_positiony,&level);
    for(int i=0;i<21;i++)
        {
            for(int k=0;k<19;k++)
            {
                fscanf(fp,"%d ",&maze_art[i][k]);
            }

        }

        iResumeTimer(0);
        iResumeTimer(1);
        iResumeTimer(2);
        iResumeTimer(3);
        iResumeTimer(4);
        iResumeTimer(5);
        iResumeTimer(6);
        iResumeTimer(7);
        iResumeTimer(8);
        iResumeTimer(9);
   fclose(fp);
    maze_for_enemymovement[8][9]=0;
    //level++;
    fp=fopen("highscore.text","r");
    mor=0;
    if(level>=5)
    {
        level=5;
    }
    while(mor<level)
    {
        fgets(highscore_array[mor],10,fp);


        mor++;
    }
    fclose(fp);
    mor=0;
    fp=fopen("name.text","r");
    while(mor<level)
    {
        fgets(name_array[mor],10,fp);

        mor++;
    }

    fclose(fp);
    opp=0;
    kop=0;

  new_game=0;
       }
      if(resume_page)
       {
        FILE* fp;
    fp=fopen("reload.text","r");
    //fscanf(fp,"%c %c %c %c",&b_position,&p_position, &i_position, &c_position);
    fscanf(fp,"%d",&target_c.x);

    fscanf(fp,"%d",&target_c.y);

    fscanf(fp,"%d",&b.x);
    fscanf(fp,"%d",&b.y);
    fscanf(fp,"%d",&p.x);
    fscanf(fp,"%d",&p.y);
    fscanf(fp,"%d",&i.x);
    fscanf(fp,"%d",&i.y);
    fscanf(fp,"%d",&c.y);
    fscanf(fp,"%d",&c.x);
    fscanf(fp,"%d",&pinky.recent.x);
    fscanf(fp,"%d",&pinky.recent.y);
    fscanf(fp,"%d",&blinky.recent.x);
    fscanf(fp,"%d",&blinky.recent.y);
    fscanf(fp,"%d",&inky.recent.x);
    fscanf(fp,"%d",&inky.recent.y);
    fscanf(fp,"%d",&clyde.recent.x);
    fscanf(fp,"%d",&clyde.recent.y);
    fscanf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d",&chase_scatter_mode,&time_fright,&pause,&resume,&mode1,&mode2,&mode3,&mode4,&show,&stop,&m,&live,&j);
    fscanf(fp,"%d %d %d %d %d %d %d %d %d",&i_up,&i_left,&i_right,&i_down,&lara,&time_count,&time_count_forshow,&time_min,&score);
    fscanf(fp,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&pellets,&ghost,&power,&pac_no,&pac,&bx,&by,&px,&py,&ix,&iy,&cx,&cy,&down,&left,&right,&up);
    fscanf(fp,"%d %d %d %d %d",&pos_x,&pos_y,&pacman_positionx,&pacman_positiony,&level);
    //printf("%d %d %d %d %d",&pos_x,&pos_y,&pacman_positionx,&pacman_positiony,&level);
    for(int i=0;i<21;i++)
        {
            for(int k=0;k<19;k++)
            {
                fscanf(fp,"%d ",&maze_art[i][k]);
            }

        }

    fgets(str_score,10,fp);
    fgets(time_countarray,10,fp);
     fgets(pellets_countarray,10,fp);

        fgets(ghost_eaten_array,10,fp);

          fgets(power_pelletsarray,10,fp);
    printf("\n%s\n",str_score);

   fclose(fp);
  /* fp=fopen("highscore.text","r");
    mor=0;
    while(mor<=level)
    {
        fgets(highscore_array[mor],10,fp);
        fgets(name_array[mor],10,fp);
        mor++;
    }

    opp=0;
    kop=0;
*/

   resume_page=0;
       }
    }


}

int main()
{
    //place your own initialization codes here.




    b_position=u;
    p_position=u;
    i_position=u;
    c_position=u;
 pinky.initial.x=mazex+wall_width*8;
     pinky.initial.y=mazey-wall_width*9;
    blinky.initial.x=mazex+wall_width*9;
    blinky.initial.y=mazey-wall_width*7;
     inky.initial.x=mazex+wall_width*9;
    inky.initial.y=mazey-wall_width*9;
     clyde.initial.x=mazex+wall_width*10;
    clyde.initial.y=mazey-wall_width*9;
 pacman_initialpositiony=mazey-wall_width*13;
 pacman_initialpositionx=mazex+wall_width*8;
    iSetTimer(130,pacman_move);//1
	iSetTimer(150,blinky_move);//2
	iSetTimer(150,inky_move);//3
	iSetTimer(1000,time_counting);//4
    iSetTimer(150,frightend_mode);//5
    iSetTimer(150,eating_mode);//6
    iSetTimer(150,pacman_die);//7
    iSetTimer(150,again);//8
    iSetTimer(20,game_over);
    iSetTimer(20,game);




	iInitialize(screen_width,screen_height,"my first project");
    return 0;
}

