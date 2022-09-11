/*----------------------------------------------------------------
Project Title            :        Mastermind
Group No                 :        Group 18
1st Member Name          :        CH'NG JING YING
1st Matric               :        19001168
2nd Member Name          :        ONG WEI LING
2nd Matric               :        19001359
Semester                 :        January

-Command to compile the project:
 gcc Group18_mastermind.c gfx.c -o a.o -lX11 -lm 
 ------------------------------------------------------------------*/

#include "gfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>


/* ######################################## DECLARE FUNCTION ######################################## */
void playGame(); //main page
void gameLevel(); //second page
void statistic(int *count1, int *count2, int *count3, int *win_lvl1, int *time_lvl1, int *win_lvl2, int *time_lvl2, int *win_lvl3, int *time_lvl3, int *plose_lvl3);

/*------- Level 1 -----*/
void info_one(); //third page
void level1grid(); //forth page
void level_one_one(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1);
void level_one_two(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1);
void level_one_three(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1);
void random_lvl_one(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1);
void win_lvl_one(int *ptime1, int w1);
void Lose_chances(int Lose);
void Lose_lvl_one(int *ptime1, int *w1);
void info_playing_level_one();
int hint_level_one_one(int h); //new
int hint_level_one_two(int h); //new
int hint_level_one_three(int h); //new
void lvl1(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1, int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2, int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3);
void play_lvl1(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1, int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2, int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3);

/*--------- Level 2 -----------*/
void info_two();
void info_playing_level_two(); //new
void levelgrid2();
void level_two_one(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2);
void level_two_two(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2);
void level_two_three(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2);
void random_lvl_two(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2);
void win_lvl_two(int *ptime2, int w2);
void Lose_chances_lvl_two(int Lose);
void Lose_lvl_two(int *ptime2, int *w2);
int hint_level_two_one(int h); //new
int hint_level_two_two(int h); //new
int hint_level_two_three(int h); //new
void lvl2(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2, int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3);
void play_lvl2(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2, int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3);

/*------- Level 3 --------*/
void info_three(); //new
void info_playing_level_three();
void levelgrid3();
void level_three_one(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3);
void level_three_two(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3);
void level_three_three(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3);
void random_lvl_three(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3);
void win_lvl_three(int *ptime3, int w3);
void Lose_chances_lvl_three(int Lose);
void Lose_lvl_three(int *ptime3, int *w3);
int hint_level_three_one(int h); //new
int hint_level_three_two(int h); //new
int hint_level_three_three(int h); //new
void lvl3(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3);
void play_lvl3(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3);


/* ######################################## Main program ######################################## */
int main(void)
{
	char c; char a; 
	int count1 = 0, count2 = 0, count3 = 0;
	int win_lvl1=0, win_lvl2=0, win_lvl3=0, w_lvl1=0, i_lvl1=0, time_lvl1=0, w_lvl2=0, i_lvl2=0, time_lvl2=0, w_lvl3=0, i_lvl3=0, time_lvl3=0, lose_lvl3=0;
	int *pwin_lvl1; int *pwin_lvl2; int *pwin_lvl3; int *pw_lvl1; int *pi_lvl1; int *ptime_lvl1; int *pw_lvl2; int *pi_lvl2; int *ptime_lvl2; int *pw_lvl3; int *pi_lvl3; int *ptime_lvl3; int *pcount3; int *pcount2; int *pcount1; int *plose_lvl3;
	
	pwin_lvl1 = &win_lvl1; pwin_lvl2 = &win_lvl2; pwin_lvl3 = &win_lvl3; pw_lvl1 = &w_lvl1; pi_lvl1=&i_lvl1; ptime_lvl1=&time_lvl1; pw_lvl2 = &w_lvl2; pi_lvl2=&i_lvl2; ptime_lvl2=&time_lvl2;
	pw_lvl3 = &w_lvl3; pi_lvl3=&i_lvl3; ptime_lvl3=&time_lvl3; pcount3=&count3; pcount2=&count2;  pcount1=&count1; plose_lvl3=&lose_lvl3;
	
	srand(time(NULL));
    gfx_open(1000,770,"Colour and Shape Matching Game");
    gfx_clear_color(0,0,0); //black screen

    while(1) { // Wait for the user to press a character.
		gfx_clear();
		gfx_color(255,255,255); 
		gfx_text("WELCOME TO COLOUR & SHAPE MATCHING GAME",370,260);
		gfx_text("PRODUCED BY ONG WEI LING & CH'NG JING YING",360,290); //bug 1: click only shown
		playGame();
		a = gfx_wait();
		if(gfx_xpos()>=335 && gfx_xpos()<=635 && gfx_ypos()>=303 && gfx_ypos()<=383 || a == 'p' || a =='P') // play game
		{

			gfx_clear();
			gameLevel();
			
			a = gfx_wait();
			/* ------- Level 1 ----------*/
			if(gfx_xpos()>=335 && gfx_xpos()<=635 && gfx_ypos()>=303 && gfx_ypos()<=383 || a=='1' ) //press level 1 enter info page
			{
				lvl1(pcount1,pwin_lvl1,pw_lvl1,pi_lvl1,ptime_lvl1,pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2,pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
				printf("In main w_lvl1 = %d and i_lvl1 = %d and count1 = %d and win_lvl1 = %d\n",w_lvl1,i_lvl1,count1,win_lvl1);
			}
			
			/*--------- Level 2 ------*/
			else if(gfx_xpos()>=335 && gfx_xpos()<=635 && gfx_ypos()>=390 && gfx_ypos()<=470 || a=='2') // level 2
			{
				lvl2(pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2,pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
				printf("In main w_lvl2 = %d and i_lvl2 = %d and count2 = %d and win_lvl2 = %d\n",w_lvl2,i_lvl2,count2,win_lvl2);
			}
			
			/*----------- Level 3 -------*/
			else if(gfx_xpos()>=335 && gfx_xpos()<=635 && gfx_ypos()>=477 && gfx_ypos()<=557 || a == '3') //level 3
			{
				lvl3(pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
				printf("In main w_lvl3 = %d and i_lvl3 = %d and count3 = %d and win_lvl3 = %d\n",w_lvl3, i_lvl3, count3,win_lvl3);
			}

		}
		else if (gfx_xpos()>=335 && gfx_xpos()<=635 && gfx_ypos()>=390 && gfx_ypos()<=470 || a=='s' || a=='S') // statistic button
		{
			gfx_clear();
			statistic(pcount1,pcount2,pcount3,pwin_lvl1,ptime_lvl1,pwin_lvl2,ptime_lvl2,pwin_lvl3,ptime_lvl3,plose_lvl3); 
			a = gfx_wait();
		}
		else if (gfx_xpos()>=335 && gfx_xpos()<=635 && gfx_ypos()>=477 && gfx_ypos()<=557 || a=='q' || a=='Q') //exit
		{
			break;
		}
	} //greatest while close


}

/* --------- Main Close ----------- */

void lvl1(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1, int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2, int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3)
{
				char a;
				*pcount1 = *pcount1 + 1; //count of level 1
				gfx_clear(); //clear screen
				info_one();
				a = gfx_wait();	
				gfx_clear();	
				level1grid();
				info_playing_level_one();
				random_lvl_one(pcount1,pwin_lvl1,pw_lvl1,pi_lvl1,ptime_lvl1);	
				printf("In lvl 1 *pw_lvl1 = %d and *pi_lvl1 = %d and *pcount1=%d\n",*pw_lvl1, *pi_lvl1,*pcount1);
				play_lvl1(pcount1,pwin_lvl1,pw_lvl1,pi_lvl1,ptime_lvl1,pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2,pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
}



void play_lvl1(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1, int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2, int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3)
{
	char a;
	printf("Hello level 1\n");
	printf("In play *pw_lvl1 = %d and *pi_lvl1 = %d and *pcount1 = %d\n",*pw_lvl1, *pi_lvl1, *pcount1);
	if (*pw_lvl1>2)
	{
		while(*pw_lvl1=3)
		{	
			Lose_lvl_one(ptime_lvl1, pi_lvl1);
			a = gfx_wait();
			if (a=='m' || (gfx_xpos() > 570 && gfx_xpos() < 660) && (gfx_ypos() > 150 && gfx_ypos() < 200))
			{
				break;
			}
			else if (a=='n' || (gfx_xpos() > 300 && gfx_xpos() < 390) && (gfx_ypos() > 150 && gfx_ypos() < 200)) //play again level 3
			{
				lvl1(pcount1,pwin_lvl1,pw_lvl1,pi_lvl1,ptime_lvl1,pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2,pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
			}
			}
			
	}
	else if (*pi_lvl1>=3)
	{
		printf("*pi_lvl1 = %d\n", *pi_lvl1);
		*pwin_lvl1 = *pwin_lvl1 + 1;
		int win = (*pi_lvl1)-*pw_lvl1;
		win_lvl_one(ptime_lvl1, win);
		/* Back to main menu*/
		a = gfx_wait();
		if (a=='n' || (gfx_xpos() > 300 && gfx_xpos() < 390) && (gfx_ypos() > 150 && gfx_ypos() < 200)) //next level to level 2
		{
			lvl2(pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2,pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
		}
	}
				
}

void lvl2(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2, int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3)
{
				char a;
				*pcount2 = *pcount2 + 1; //count of level 1
				gfx_clear(); //clear screen
				info_two();
				a = gfx_wait();	
				gfx_clear();	
				levelgrid2();
				info_playing_level_two();
				random_lvl_two(pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2);	
				printf("In lvl 2 *pw_lvl2 = %d and *pi_lvl2 = %d and *pcount2=%d\n",*pw_lvl2, *pi_lvl2,*pcount2);
				play_lvl2(pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2,pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
}

void play_lvl2(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2, int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3)
{
	char a;
	printf("Hello level 2\n");
	printf("In play *pw_lvl2 = %d and *pi_lvl2 = %d and *pcount2 = %d\n",*pw_lvl2, *pi_lvl2, *pcount2);
	if (*pw_lvl2>2)
	{
		while(*pw_lvl2=3)
		{	
			Lose_lvl_two(ptime_lvl2, pi_lvl2);
			a = gfx_wait();
			if (a=='m' || (gfx_xpos() > 570 && gfx_xpos() < 660) && (gfx_ypos() > 150 && gfx_ypos() < 200))
			{
				break;
			}
			else if (a=='n' || (gfx_xpos() > 300 && gfx_xpos() < 390) && (gfx_ypos() > 150 && gfx_ypos() < 200)) //play again level 3
			{
				lvl2(pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2,pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
			}
		}
			
	}
	else if (*pi_lvl2>=6)
	{
		printf("*pi_lvl2 = %d\n", *pi_lvl2-3);
		*pwin_lvl2 = *pwin_lvl2 + 1;
		int win = (*pi_lvl2-3)-*pw_lvl2;
		win_lvl_two(ptime_lvl2, win);
		/* Back to main menu*/
		a = gfx_wait();
		if (a=='n' || (gfx_xpos() > 300 && gfx_xpos() < 390) && (gfx_ypos() > 150 && gfx_ypos() < 200)) //next level to level 3
		{
			lvl3(pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
		}
	}
				
}


void lvl3(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3)
{
				char a;
				*pcount3 = *pcount3 + 1; //count of level 3
				gfx_clear(); //clear screen
				info_three();
				a = gfx_wait();	
				gfx_clear();	
				levelgrid3();
				info_playing_level_three();
				random_lvl_three(pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3);	
				printf("In lvl 3 *pw_lvl3 = %d and *pi_lvl3 = %d and *pcount3=%d\n",*pw_lvl3, *pi_lvl3,*pcount3);
				play_lvl3(pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);


}

void play_lvl3(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3, int *plose_lvl3)
{
	char a;
	printf("Hello\n");
	//*pcount3++; //count of level 3
	printf("In play *pw_lvl3 = %d and *pi_lvl3 = %d and *pcount3 = %d\n",*pw_lvl3, *pi_lvl3, *pcount3);
	if (*pw_lvl3>2)
	{
		while(*pw_lvl3>=3)
		{	
			*plose_lvl3 = *plose_lvl3 + 1;
			Lose_lvl_three(ptime_lvl3, pi_lvl3);
			a = gfx_wait();
			if (a=='m' || (gfx_xpos() > 570 && gfx_xpos() < 660) && (gfx_ypos() > 150 && gfx_ypos() < 200))
			{
				break;
			}
			else if (a=='n' || (gfx_xpos() > 300 && gfx_xpos() < 390) && (gfx_ypos() > 150 && gfx_ypos() < 200)) //play again level 3
			{
				lvl3(pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3,plose_lvl3);
			}
			}
			
	}
	else if (*pi_lvl3>=6)
	{
		printf("*pi_lvl3 = %d\n", *pi_lvl3-3);
		*pwin_lvl3 = *pwin_lvl3 + 1;
		int win = (*pi_lvl3-3)-*pw_lvl3;
		win_lvl_three(ptime_lvl3, win);
		/* Back to main menu*/
		a = gfx_wait();
	}
				
}


void playGame() //first page
{
			//gfx_rectangle (int x, int y, int width, int height) play
			gfx_color(0,0,0);
			gfx_rectangle(335,303,300,80);
			gfx_color(65,105,225);
			gfx_fillrectangle(335,303,300,80);
			gfx_color(255,255,255);
			gfx_text("PLAY GAME",455, 352);
					//gfx_rectangle (int x, int y, int width, int height) statistic
					gfx_color(0,0,0);
					gfx_rectangle(335,390,300,80);
					gfx_color(147,112,219);
					gfx_fillrectangle(335,390,300,80);
					gfx_color(255,255,255);
					gfx_text("STATISTIC",455, 441);
			//gfx_rectangle (int x, int y, int width, int height) exit
			gfx_color(0,0,0);
			gfx_rectangle(335,477,300,80);
			gfx_color(255,0,0);
			gfx_fillrectangle(335,477,300,80);
			gfx_color(255,255,255);
			gfx_text("EXIT",465, 529);
			
			//mascot//
			gfx_color(255,255,255);
			gfx_fillcircle(950,720,60);
			gfx_fillcircle(950,680,40);
			gfx_color(255,0,0);
			gfx_fillcircle(950,705,8);
			gfx_color(34,139,34);
			gfx_fillcircle(950,720,8);
			gfx_color(255,0,0);
			gfx_fillcircle(950,735,8);
			gfx_color(0,0,0);
			gfx_fillcircle(943,673,6);
			gfx_fillcircle(955,673,6);
			gfx_color(225,215,0);
			gfx_line(900,650,910,660);
			gfx_line(900,690,910,680);
			gfx_color(255,255,255);
			gfx_text("PRESS 'PLAY GAME' OR 'P' TO START",590,655);
			gfx_text("PRESS 'STATISTIC' OR 'S' TO VIEW YOUR GAME STATISTIC",590,670);
			gfx_text("PRESS 'EXIT' OR 'Q' IF YOU WANT TO QUIT THE GAME",590,685);
			gfx_text("ONLY SMALL ALPHABET CAN BE ENTERED",590,700);
}


void gameLevel() //second page
{
	gfx_color(255,255,255);
	gfx_text("PLEASE CHOOSE GAME LEVEL",335,283);

			//gfx_rectangle (int x, int y, int width, int height) easy
			gfx_color(0,0,0);
			gfx_rectangle(335,303,300,80);
			gfx_color(144,112,219);
			gfx_fillrectangle(335,303,300,80);
			gfx_color(255,255,255);
			gfx_text(">>> LEVEL 1 <<<",445, 332);
			gfx_text(">>> 2 BY 3 GRIDS <<<",430,357);
					//gfx_rectangle (int x, int y, int width, int height) medium
					gfx_color(0,0,0);
					gfx_rectangle(335,390,300,80);
					gfx_color(255,105,180);
					gfx_fillrectangle(335,390,300,80);
					gfx_color(255,255,255);
					gfx_text(">>> LEVEL 2 <<<",445, 420);
					gfx_text(">>> 3 BY 4 GRIDS <<<",430,445);
			//gfx_rectangle (int x, int y, int width, int height) hard
			gfx_color(0,0,0);
			gfx_rectangle(335,477,300,80);
			gfx_color(255,160,122);
			gfx_fillrectangle(335,477,300,80);
			gfx_color(255,255,255);
			gfx_text(">>> LEVEL 3 <<<",445, 509);
			gfx_text(">>> COLOUR AND SHAPE MATCHING <<<",395,534);

			gfx_color(0,0,0);
			gfx_rectangle(93,661,180,80);
			gfx_color(252,0,0);
			gfx_fillrectangle(93,661,180,80);
			gfx_color(255,255,255);
			gfx_text("       MAIN MENU ",117, 710);
			
			//mascot//
			gfx_color(255,255,255);
			gfx_fillcircle(950,720,60);
			gfx_fillcircle(950,680,40);
			gfx_color(255,0,0);
			gfx_fillcircle(950,705,8);
			gfx_color(34,139,34);
			gfx_fillcircle(950,720,8);
			gfx_color(255,0,0);
			gfx_fillcircle(950,735,8);
			gfx_color(0,0,0);
			gfx_fillcircle(943,673,6);
			gfx_fillcircle(955,673,6);
			gfx_color(225,215,0);
			gfx_line(900,650,910,660);
			gfx_line(900,690,910,680);
			gfx_color(255,255,255);
			gfx_text("PRESS 'LEVEL 1' OR '1' IF YOU WISH TO PLAY LEVEL 1",590,655);
			gfx_text("PRESS 'LEVEL 2' OR '2' IF YOU WISH TO PLAY LEVEL 2",590,670);
			gfx_text("PRESS 'LEVEL 3' OR '3' IF YOU WISH TO PLAY LEVEL 3",590,685);
	
}

void statistic(int *count1, int *count2, int *count3, int *win_lvl1, int *time_lvl1, int *win_lvl2, int *time_lvl2, int *win_lvl3, int *time_lvl3, int *lose_lvl3)
{
			char win_lvl_1[100]; char Lose_lvl_1[100];char win_lvl_2[100]; char Lose_lvl_2[100];char win_lvl_3[100]; char Lose_lvl_3[100];
			char count_1[100]; char count_2[100]; char count_3[100];
			
			/* Main Menu Button*/
			gfx_color(0,0,0);
			gfx_rectangle(93,661,180,80);
			gfx_color(252,0,0);
			gfx_fillrectangle(93,661,180,80);
			gfx_color(255,255,255);
			gfx_text(" MAIN MENU ",117, 710);
			
			printf("-------- Statistic --------\n");

			/* Overall Statitic - No. of games played, - no. of games won, - no. of game lost, -time on game*/
			int i;
			gfx_color(255,255,255);
			gfx_rectangle(50,50,400,250);
			gfx_text("OVERALL STATISTIC",200,86);
			for(i=50;i<445;i++)
			{
				gfx_text("-",i,110);
			}
			/* Overall Statistic Value */
			
			/* Total Count */
			gfx_color(255,255,255);
			printf("Total count = %d\n", *count1+*count2+*count3);
			sprintf(count_1,"TOTAL COUNT = %d", *count1+*count2+*count3);
			gfx_text(count_1,70,150);
			
			/* Win */
			gfx_color(255,255,255);
			printf("No. of games win (total) = %d\n", *win_lvl1+*win_lvl2+*win_lvl3);
			int win1 = *win_lvl1+*win_lvl2+*win_lvl3;
			sprintf(win_lvl_1,"TOTAL NO. OF GAMES WIN = %d", win1);
			gfx_text(win_lvl_1, 70, 185);
			/* Lose */
			printf("No. of games Lose (total) = %d\n", ((*count1+*count2+*count3)-(*win_lvl1+*win_lvl2+*win_lvl3)));
			sprintf(Lose_lvl_1,"TOTAL NO. OF GAMES LOSE = %d", ((*count1+*count2+*count3)-(*win_lvl1+*win_lvl2+*win_lvl3)));
			gfx_text(Lose_lvl_1,70,220);
			
			/* Level 1 Statistic*/
			/* Level 1 Box */
			gfx_color(255,255,255);
			gfx_rectangle(550,50,400,250);
			gfx_text("LEVEL 1",735,86);
			for(i=550;i<945;i++)
			{
				gfx_text("-",i,110);
			}
			/* Level 1 Value */
			
			/* Count of Level 1 played*/
			gfx_color(255,255,255);
			printf("Total count of level 1 played = %d\n", *count1);
			sprintf(count_1,"TOTAL COUNT OF LEVEL 1 PLAYED = %d", *count1);
			gfx_text(count_1,570,150);
			
			/* Win */
			gfx_color(255,255,255);
			printf("No. of games win (Level 1) = %d\n", *win_lvl1);
			sprintf(win_lvl_1,"NO. OF GAMES WIN IN LEVEL 1 = %d", *win_lvl1);
			gfx_text(win_lvl_1, 570, 185);
			/* Lose */
			printf("No. of games Lose = %d\n", (*count1-*win_lvl1));
			sprintf(Lose_lvl_1,"NO. OF GAMES LOSE IN LEVEL 1 = %d", (*count1-*win_lvl1));
			gfx_text(Lose_lvl_1,570,220);
			
			/* Level 2 Statistic*/
			/* Level 2 Box */
			gfx_color(255,255,255);
			gfx_rectangle(50,380,400,250);
			gfx_text("LEVEL 2",215,416);
			for(i=50;i<445;i++)
			{
				gfx_text("-",i,440);
			}
			
			/* Level 2 Value */
			/* Count of Level 2 played */
			gfx_color(255,255,255);
			printf("Total count of level 2 played = %d\n", *count2);
			sprintf(count_2,"TOTAL COUNT OF LEVEL 2 PLAYED = %d", *count2);
			gfx_text(count_2,70,480);
			
			/* Win */
			gfx_color(255,255,255);
			printf("No. of games win (Level 2) = %d\n", *win_lvl2);
			sprintf(win_lvl_2,"NO. OF GAMES WIN IN LEVEL 2 = %d", *win_lvl2);
			gfx_text(win_lvl_2, 70, 515);
			/* Lose */
			printf("No. of games Lose (Level 2)= %d\n", (*count2-*win_lvl2));
			sprintf(Lose_lvl_2,"NO. OF GAMES LOSE IN LEVEL 2 = %d", (*count2-*win_lvl2));
			gfx_text(Lose_lvl_2, 70, 550);
			
			/* Level 3 Statistic*/
			/* Level 3 Box */
			gfx_color(255,255,255);
			gfx_rectangle(550,380,400,250); 
			gfx_text("LEVEL 3",735,416);
			for(i=550;i<945;i++)
			{
				gfx_text("-",i,440);
			}
			
			/* Level 3 Value */
			/* Count of Level 3 played */
			gfx_color(255,255,255);
			printf("Total count of level 3 played = %d\n", *count3);
			sprintf(count_3,"TOTAL COUNT OF LEVEL 3 PLAYED = %d", *count3);
			gfx_text(count_3,570,480);
			
			/* Win */
			gfx_color(255,255,255);
			printf("No. of games win (Level 3) = %d\n", *win_lvl3);
			sprintf(win_lvl_3,"NO. OF GAMES WIN IN LEVEL 3 = %d", *win_lvl3);
			gfx_text(win_lvl_3, 570, 515);
			/* Lose */
			printf("No. of games Lose (Level 3)= %d\n", *lose_lvl3);
			sprintf(Lose_lvl_3,"NO. OF GAMES LOSE IN LEVEL 3 = %d", *lose_lvl3);
			gfx_text(Lose_lvl_3, 570, 550);
			
			/* Back To Main Page */
			/*a = gfx_wait();
			if (gfx_xpos()>=93 && gfx_xpos()<=273 && gfx_ypos()>=661 && gfx_ypos()<=741)
			{
				gfx_clear();
				main_page();
			}*/
			

}

/*------------------- Level 1 -----------------------*/
void info_one() //third page
{
			//gfx_clear();//clear screen
			gfx_text("----- SCORING RULES -----",425,233);
			gfx_text("YOU HAVE TO FIND OUT THE 3 PAIRS",405,258);
			gfx_text("TO WIN THE GAME IN LEVEL 1.",422,278);
			gfx_text("-------- CHANCES --------",425,323);
			gfx_text("YOU ONLY HAVE 3 CHANCES.",430,348);
			gfx_text("ONCE YOU USE UP THE 3 CHANCES,",415,368);
			gfx_text("        YOU LOSE!!!      ",425,388);
			gfx_text("---------- HINT ---------",425,433);
			gfx_text("PRESS THE HINT BUTTON OR '4' TO GET TIPS",390,458);
			gfx_text("YOU ONLY HAVE 1 HINT IN LEVEL 1",410,478);
			gfx_text("------- WARNING!! -------",425,520);
			gfx_text("ONCE YOU CLICK, YOU CAN'T UNDO",410,553);
			gfx_text("-------------------------------------------",370,583);
			gfx_text("| LEFT CLICK OR PRESS 'ENTER' TO CONTINUE |",370,603);
			gfx_text("-------------------------------------------",370,616);
			
			//mascot//
			gfx_color(255,255,255);
			gfx_fillcircle(950,720,60);
			gfx_fillcircle(950,680,40);
			gfx_color(255,0,0);
			gfx_fillcircle(950,705,8);
			gfx_color(34,139,34);
			gfx_fillcircle(950,720,8);
			gfx_color(255,0,0);
			gfx_fillcircle(950,735,8);
			gfx_color(0,0,0);
			gfx_fillcircle(943,673,6);
			gfx_fillcircle(955,673,6);
			gfx_color(225,215,0);
			gfx_line(900,650,910,660);
			gfx_line(900,720,910,710);
			gfx_color(255,255,255);
			gfx_text("IF YOU WIN, YOU CAN STRAIGHT AWAY PRESS 'N'",630,655);
			gfx_text("OR HIT THE BUTTON TO PROCEED TO NEXT LEVEL.",630,670);
			gfx_text("ELSE HIT THE BUTTON OR PRESS 'M' IF YOU WISH",630,685);
			gfx_text("TO GO BACK TO MAIN PAGE.",630,700);
			gfx_text("GOOD LUCK!!!",630,715);
}

void level1grid() //forth page
{
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,236,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,336,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,436,160,68);
    
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,236,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,336,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,436,160,68);
    
    gfx_color(0,0,0);
    gfx_text("A",310,296);
    gfx_text("C",310,396);
    gfx_text("E",310,496);
    gfx_text("B",510,296);
    gfx_text("D",510,396);
    gfx_text("F",510,496);

}

void level_one_one(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1)
{
	char a;
	int i=0,w=0,h=0;
	int time1;
	
	time_t start, end; 
	
	start = time(NULL); 
	
	while (i<3 && w<3)
	{
		a = gfx_wait();
		if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 236 && gfx_ypos() < 304) || a =='a')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(300,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))|| a =='d')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(500,336,160,68);
				i++;
			}
                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a=='b'||a=='c'||a=='e'||a=='f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,236,160,68);
				gfx_color(0,0,0);
				gfx_text("A",310,296);
				w++;
				Lose_chances(w);
			}
		}
		
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 336 && gfx_ypos() < 404)|| a=='d')
        {
			gfx_color(175,238,238); //pale turquiose
			gfx_fillrectangle(500,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))|| a=='a')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(300,236,160,68);
				i++;
			}
                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a=='b'||a=='c'||a=='e'||a=='f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,336,160,68);
				gfx_color(0,0,0);
				gfx_text("D",510,396);
				w++;
				Lose_chances(w);
			}
		}
		
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 336 && gfx_ypos() < 404)|| a=='c')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(300,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='f')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(500,436,160,68);
				i++;
			}
                    
			else if (((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404))|| a=='b'||a=='a'||a=='e'||a=='d')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,336,160,68);
				gfx_color(0,0,0);
				gfx_text("C",310,396);
				w++;
				Lose_chances(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='f')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(500,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))|| a=='c')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(300,336,160,68);
				i++;
			}
                    
			else if (((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404))|| a=='b'||a=='a'||a=='e'||a=='d')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,436,160,68);
				gfx_color(0,0,0);
				gfx_text("F",510,496);
				w++;
				Lose_chances(w);
			}
		}

		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 436 && gfx_ypos() < 504)|| a=='e')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(300,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))|| a=='b')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(500,236,160,68);
				i++;
			}
                    
			else if (((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404))||((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404))|| a=='c'||a=='a'||a=='f'||a=='d')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,436,160,68);
				gfx_color(0,0,0);
				gfx_text("E",310,496);
				w++;
				Lose_chances(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 236 && gfx_ypos() < 304)|| a=='b')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(500,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='e')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(300,436,160,68);
				i++;
			}
                    
			else if (((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404))||((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404))|| a=='c'||a=='a'||a=='f'||a=='d')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,236,160,68);
				gfx_color(0,0,0);
				gfx_text("B",510,296);
				w++;
				Lose_chances(w);
			}
		}
		else if ((gfx_xpos() > 805 && gfx_xpos() < 895) && (gfx_ypos() > 588 && gfx_ypos() < 633) || a == '4')
		{
			h++;
			hint_level_one_one(h);
		}
	}
	
	end = time(NULL); 
	
	time1 = difftime(end, start);
	
	printf("Time1 is %d\n", time1);
	*ptime_lvl1 = time1;
	
	*pi_lvl1=i; *pw_lvl1=w;
	//printf("*pi_lvl1=%d; *pw_lvl1=%d\n", *pi_lvl1, *pw_lvl1);
	
	/*Life and total played*/

	printf("i = %d\n", i);
	printf("w = %d\n", w);
}


void level_one_two(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1)
{
	char a;
	int i=0,w=0,h=0;
	int time1;
	
	time_t start, end; 
	
	start = time(NULL); 
	
	while (i<3 && w<3)
	{
		a = gfx_wait();
		if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 336 && gfx_ypos() < 404) || a =='c')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(300,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504)) || a == 'e')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(300,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a == 'a'|| a == 'b'|| a == 'd'|| a == 'f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,336,160,68);
				gfx_color(0,0,0);
				gfx_text("C",310,396);
				w++;
				Lose_chances(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 436 && gfx_ypos() < 504)|| a == 'e')
        {
			gfx_color(175,238,238); //pale turquiose
			gfx_fillrectangle(300,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))|| a =='c')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(300,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a == 'a'|| a == 'b'|| a == 'd'|| a == 'f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,436,160,68);
				gfx_color(0,0,0);
				gfx_text("E",310,496);
				w++;
				Lose_chances(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 236 && gfx_ypos() < 304)|| a=='b')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(500,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))|| a=='d')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(500,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a == 'a'|| a == 'c'|| a == 'e'|| a == 'f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,236,160,68);
				gfx_color(0,0,0);
				gfx_text("B",510,296);
				w++;
				Lose_chances(w);
			}
		}
		
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 336 && gfx_ypos() < 404)|| a=='d')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(500,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))|| a=='b')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(500,236,160,68);
				i++;
			}         
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a == 'a'|| a == 'c'|| a == 'e'|| a == 'f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,336,160,68);
				gfx_color(0,0,0);
				gfx_text("D",510,396);
				w++;
				Lose_chances(w);
			}
		}
		
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 236 && gfx_ypos() < 304)|| a == 'a')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(300,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))|| a=='f')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(500,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404))|| a == 'b'|| a == 'c'|| a == 'e'|| a == 'd')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,236,160,68);
				gfx_color(0,0,0);
				gfx_text("A",310,296);
				w++;
				Lose_chances(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='f')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(500,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(300,236,160,68);
				i++;
			}
                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404))|| a == 'b'|| a == 'c'|| a == 'e'|| a == 'd')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,436,160,68);
				gfx_color(0,0,0);
				gfx_text("F",510,496);
				w++;
				Lose_chances(w);
			}
		}
		
		else if ((gfx_xpos() > 805 && gfx_xpos() < 895) && (gfx_ypos() > 588 && gfx_ypos() < 633) || a == '4')
		{
			h++;
			hint_level_one_two(h);
		}
	}
	
	/*Time spend*/
	
	end = time(NULL); 
	
	time1 = difftime(end, start);
	
	printf("Time1 is %d\n", time1);
	*ptime_lvl1 = time1;
	
	*pi_lvl1=i; *pw_lvl1=w;
	//printf("*pi_lvl1=%d; *pw_lvl1=%d\n", *pi_lvl1, *pw_lvl1);
	
	/*Life and total played*/

	printf("i = %d\n", i);
	printf("w = %d\n", w);
}

void level_one_three(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1)
{
	char a;
	int i=0,w=0,h=0;
	int time1;
	
	time_t start, end; 
	
	start = time(NULL); 
	
	while (i<3 && w<3)
	{
		a = gfx_wait();
		if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='b')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(500,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='e')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(300,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a=='a'|| a=='c'|| a=='d'|| a=='f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,236,160,68);
				gfx_color(0,0,0);
				gfx_text("B",510,296);
				w++;
				Lose_chances(w);
			}
		}

		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='e')
        {
			gfx_color(175,238,238); //pale turquiose
			gfx_fillrectangle(300,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='b')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(500,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a=='a'|| a=='c'|| a=='d'|| a=='f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,436,160,68);
				gfx_color(0,0,0);
				gfx_text("E",310,496);
				w++;
				Lose_chances(w);
			}
		}
		
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='c')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(300,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='d')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(500,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a=='a'|| a=='b'|| a=='e'|| a=='f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,336,160,68);
				gfx_color(0,0,0);
				gfx_text("C",310,396);
				w++;
				Lose_chances(w);
			}
		}
		
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='d')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(500,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='c')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(300,336,160,68);
				i++;
			}         
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))|| a=='a'|| a=='b'|| a=='e'|| a=='f')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,336,160,68);
				gfx_color(0,0,0);
				gfx_text("D",510,396);
				w++;
				Lose_chances(w);
			}
		}
		
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='a')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(300,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='f')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(500,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404))|| a=='c'|| a=='b'|| a=='e'|| a=='d')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,236,160,68);
				gfx_color(0,0,0);
				gfx_text("A",310,296);
				w++;
				Lose_chances(w);
			}
		}
		
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='f')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(500,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(300,236,160,68);
				i++;
			}
                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404))|| a=='c'|| a=='b'|| a=='e'|| a=='d')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,436,160,68);
				gfx_color(0,0,0);
				gfx_text("F",510,496);
				w++;
				Lose_chances(w);
			}
		}
		
		else if ((gfx_xpos() > 805 && gfx_xpos() < 895) && (gfx_ypos() > 588 && gfx_ypos() < 633) || a == '4')
		{
			h++;
			hint_level_one_three(h);
		}
	}
	
	end = time(NULL); 
	
	time1 = difftime(end, start);
	
	printf("Time1 is %d\n", time1);
	*ptime_lvl1 = time1;
	
	*pi_lvl1=i; *pw_lvl1=w;
	//printf("*pi_lvl1=%d; *pw_lvl1=%d\n", *pi_lvl1, *pw_lvl1);
	
	/*Life and total played*/

	printf("i = %d\n", i);
	printf("w = %d\n", w);

}

void random_lvl_one(int *pcount1, int *pwin_lvl1, int *pw_lvl1, int *pi_lvl1, int *ptime_lvl1)
{
	int lower = 1, upper = 3, count = 1; 

	// Use current time as 
	// seed for random generator 
	srand(time(0)); 

	int i, num; 
	for (i = 0; i < count; i++) { 
		int num = (rand() % (upper - lower + 1)) + lower; 
		printf("(Random) Level 1: Case %d\n ", num); 
		
		if (num==1)
		{
			level_one_one(pcount1,pwin_lvl1,pw_lvl1,pi_lvl1,ptime_lvl1);
			
		}
		else if (num==2)
		{
			level_one_two(pcount1,pwin_lvl1,pw_lvl1,pi_lvl1,ptime_lvl1);
		}
		else if (num==3)
		{
			level_one_three(pcount1,pwin_lvl1,pw_lvl1,pi_lvl1,ptime_lvl1);
		}
	} 
	
}



void info_playing_level_one()
{
	/* White Rectangle Outer Line Box */
    	gfx_color(255,255,255);
    	gfx_rectangle(750,150,200,500);
    	
    	/* Game Level */
    	gfx_text("LEVEL 1",830,190);
    	gfx_text("********************************",755,230);
    	
    	/* Introduce color */
    	gfx_color(175,238,238);
    	gfx_fillrectangle(760,260,80,34);
    	gfx_text("Pale Turquoise",860, 280);
    	gfx_color(255,182,193);
    	gfx_fillrectangle(760,340,80,34);
    	gfx_text("Light Pink",860, 360);
    	gfx_color(255,218,185);
    	gfx_fillrectangle(760,420,80,34);
    	gfx_text("Peach Puff",860, 440);
    	
    	/* Life Symbol */
    	gfx_color(255,255,255);
    	gfx_text("**********  CHANCES  ***********",755,500);
    	gfx_color(178,34,34);
    	gfx_fillcircle(780,550,40);
    	gfx_fillcircle(850,550,40);
    	gfx_fillcircle(920,550,40);   
    	
    	/* Hint Button */
    	gfx_color(255,255,255);
    	gfx_rectangle(805,588,90,45);
    	gfx_text("HINT",840,615);	
}

void win_lvl_one(int *ptime1, int w1) //pass time value
{
	int a;
	int time1;
	char pt1[100];
	char pw1[100];
	char c;
	char button='r';
	//int *ptime1;
	
	/* White Rectangle Outer Line Box */
	gfx_color(255,255,255);
	gfx_rectangle(280,20,400,200);
	
	/* You Won */
	gfx_color(255,255,255);
	gfx_text("CONGRATULATIONS ! ! !", 430,45);
	gfx_text("YOU WON", 455,65);
	/* Next Level Box */
	gfx_color(255,153,153);
	gfx_rectangle(300,150,90,50);
	gfx_color(255,255,255);
	gfx_text("NEXT LEVEL",315,180);
	/* Return to main page Box*/
	gfx_color(204,204,255);
	gfx_rectangle(570,150,90,50);
	gfx_color(255,255,255);
	gfx_text("BACK TO",585,170);
	gfx_text("MAIN PAGE",585,190);
	
	/*Time used*/
	printf("The time used is %d seconds\n", *ptime1);
	sprintf(pt1,"TIME SPEND IN THIS ROUND   : %d seconds",*ptime1);
	gfx_color(255,255,255);
    gfx_text(pt1,300,100);
    
    /*Life remained*/
	printf("Life remained = %d\n", w1);
	sprintf(pw1,"CHANCES REMAINED           : %d",w1);
	gfx_color(255,255,255);
    gfx_text(pw1,300,130);
	
}



void Lose_chances(int Lose)
{
	if (Lose==1)
	{
		gfx_color(255,255,255);
		gfx_fillcircle(920,550,40);
	}
	else if (Lose==2)
	{
		gfx_color(255,255,255);
		gfx_fillcircle(920,550,40);
		gfx_fillcircle(850,550,40);
	}
	else if (Lose==3)
	{
		gfx_color(255,255,255);
		gfx_fillcircle(920,550,40);
		gfx_fillcircle(850,550,40);
		gfx_fillcircle(780,550,40);
		printf("\nLose==3");
	}
}

void Lose_lvl_one(int *ptime1, int *w1) //pass time value
{
	int a;
	int time1;
	char pt1[100];
	char pw1[100];
	//int *ptime1;
	
	//usleep(2500000);
	
	gfx_clear();
	
	/* White Rectangle Outer Line Box */
	gfx_color(255,255,255);
	gfx_rectangle(280,20,400,200);
	
	/* You Won */
	gfx_color(255,255,255);
	gfx_text("SORRY", 465,45);
	gfx_text("YOU LOSE", 455,65);
	/* Next Level Box */
	gfx_color(255,153,153);
	gfx_rectangle(300,150,90,50);
	gfx_color(255,255,255);
	gfx_text("TRY AGAIN",315,180);
	/* Return to main page Box*/
	gfx_color(204,204,255);
	gfx_rectangle(570,150,90,50);
	gfx_color(255,255,255);
	gfx_text("BACK TO",585,170);
	gfx_text("MAIN PAGE",585,190);
	
	/*Time used*/
	printf("The time used is %d seconds\n", *ptime1);
	sprintf(pt1,"TIME SPEND IN THIS ROUND   : %d seconds",*ptime1);
	gfx_color(255,255,255);
    gfx_text(pt1,300,90);
    
    /*Guess made correct*/
	printf("Life remained = %d\n", *w1);
	sprintf(pw1,"GUESS MADE CORRECT         : %d",*w1);
	gfx_color(255,255,255);
    gfx_text(pw1,300,115);
    
    /*Life remain*/
    gfx_text("CHANCES REMAINED           : 0", 300,140);
    
	
}

int hint_level_one_one(int h)
{
	gfx_color(255,255,255);
	gfx_text("Hint:", 300,536);
	if (h=1)
	{
		gfx_color(255,255,255);
		gfx_text("A and D are pale turquoise", 300,551);
	}
}

int hint_level_one_two(int h)
{
	gfx_color(255,255,255);
	gfx_text("Hint:", 300,536);
	if (h=1)
	{
		gfx_color(255,255,255);
		gfx_text("A and F are peach puff", 300,551);
	}
}

int hint_level_one_three(int h)
{
	gfx_color(255,255,255);
	gfx_text("Hint:", 300,536);
	if (h=1)
	{
		gfx_color(255,255,255);
		gfx_text("C and D are light pink", 300,551);
	}
}

/**** Level 2 ****/

void info_two() //third page
{
			//gfx_clear();//clear screen
			gfx_text("----- SCORING RULES -----",425,233);
			gfx_text("YOU HAVE TO FIND OUT THE 6 PAIRS",405,258);
			gfx_text("TO WIN THE GAME IN LEVEL 2.",422,278);
			gfx_text("-------- CHANCES --------",425,323);
			gfx_text("YOU ONLY HAVE 3 CHANCES.",430,348);
			gfx_text("ONCE YOU USE UP THE 3 CHANCES,",415,368);
			gfx_text("        YOU LOSE!!!      ",425,388);
			gfx_text("---------- HINT ---------",425,433);
			gfx_text("PRESS THE HINT BUTTON OR '4' TO GET TIPS",390,458);
			gfx_text("YOU ONLY HAVE 3 HINT IN LEVEL 2",410,478);
			gfx_text("------- WARNING!! -------",425,520);
			gfx_text("ONCE YOU CLICK, YOU CAN'T UNDO",410,553);
			gfx_text("-------------------------------------------",370,583);
			gfx_text("| LEFT CLICK OR PRESS 'ENTER' TO CONTINUE |",370,603);
			gfx_text("-------------------------------------------",370,616);
			
			//mascot//
			gfx_color(255,255,255);
			gfx_fillcircle(950,720,60);
			gfx_fillcircle(950,680,40);
			gfx_color(255,0,0);
			gfx_fillcircle(950,705,8);
			gfx_color(34,139,34);
			gfx_fillcircle(950,720,8);
			gfx_color(255,0,0);
			gfx_fillcircle(950,735,8);
			gfx_color(0,0,0);
			gfx_fillcircle(943,673,6);
			gfx_fillcircle(955,673,6);
			gfx_color(225,215,0);
			gfx_line(900,650,910,660);
			gfx_line(900,720,910,710);
			gfx_color(255,255,255);
			gfx_text("IF YOU WIN, YOU CAN STRAIGHT AWAY PRESS 'N'",630,655);
			gfx_text("OR HIT THE BUTTON TO PROCEED TO NEXT LEVEL.",630,670);
			gfx_text("ELSE HIT THE BUTTON OR PRESS 'M' IF YOU WISH",630,685);
			gfx_text("TO GO BACK TO MAIN PAGE.",630,700);
			gfx_text("GOOD LUCK!!!",630,715);
}

void info_playing_level_two()
{
	/* White Rectangle Outer Line Box */
    	gfx_color(255,255,255);
    	gfx_rectangle(750,150,200,500);
    	
    	/* Game Level */
    	gfx_text("LEVEL 2",830,190);
    	gfx_text("********************************",755,230);
    	
    	/* Introduce color */
    	gfx_color(175,238,238); //pale turquoise colour
    	gfx_fillrectangle(760,260,80,17); 
    	gfx_text("Pale Turquoise",860, 270);
    	gfx_color(255,182,193); //light pink
    	gfx_fillrectangle(760,292,80,17);
    	gfx_text("Light Pink",860, 302);
    	gfx_color(255,218,185); //peach puff
    	gfx_fillrectangle(760,324,80,17);
    	gfx_text("Peach Puff",860, 334);
    	gfx_color(240,230,140); //Khaki
    	gfx_fillrectangle(760,356,80,17);
    	gfx_text("Khaki",860, 366);
    	gfx_color(152,251,152); //pale green
    	gfx_fillrectangle(760,388,80,17);
    	gfx_text("Pale Green",860, 398);
    	gfx_color(221,160,221); //plum
    	gfx_fillrectangle(760,420,80,17);
    	gfx_text("Plum",860, 432);
    	
    	/* Life Symbol */
    	gfx_color(255,255,255);
    	gfx_text("**********  CHANCES  ***********",755,500);
    	gfx_color(178,34,34);
    	gfx_fillcircle(780,550,40);
    	gfx_fillcircle(850,550,40);
    	gfx_fillcircle(920,550,40);   
    	
    	/* Hint Button */
    	gfx_color(255,255,255);
    	gfx_rectangle(805,588,90,45);
    	gfx_text("HINT",840,615);
}

void levelgrid2()
{
	gfx_clear();
	
	gfx_color(255,255,255); 
    gfx_fillrectangle(100,236,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(100,336,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(100,436,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(100,536,160,68);
	
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,236,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,336,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,436,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,536,160,68);
    
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,236,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,336,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,436,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,536,160,68);

	gfx_color(0,0,0);
	gfx_text("A",110,296);
	gfx_text("D",110,396);
	gfx_text("G",110,496);
	gfx_text("J",110,596);
	
	gfx_text("B",310,296);
	gfx_text("E",310,396);
	gfx_text("H",310,496);
	gfx_text("K",310,596);
	
	gfx_text("C",510,296);
	gfx_text("F",510,396);
	gfx_text("I",510,496);
	gfx_text("L",510,596);
}

void level_two_one(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2)
{
	
	char a;
	int i=0,w=0,h=0;
	
	int time2;
	
	time_t start, end; 
	
	start = time(NULL); 
	
	while (i<6 && w<3)
	{
		a = gfx_wait();
		if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='a')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(100,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='e')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(300,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='d'||a=='f'||a=='g'||a=='h'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,236,160,68);
				gfx_color(0,0,0);
				gfx_text("A",110,296);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='e')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(300,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(100,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='d'||a=='f'||a=='g'||a=='h'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,336,160,68);
				gfx_color(0,0,0);
				gfx_text("E",310,396);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='g')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(100,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='h')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(300,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='d'||a=='f'||a=='a'||a=='e'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,436,160,68);
				gfx_color(0,0,0);
				gfx_text("G",110,496);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='h')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(300,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='g')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(100,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='d'||a=='f'||a=='a'||a=='e'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,436,160,68);
				gfx_color(0,0,0);
				gfx_text("H",310,496);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='d')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(100,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='i')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(500,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='g'||a=='f'||a=='a'||a=='e'||a=='h'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,336,160,68);
				gfx_color(0,0,0);
				gfx_text("D",110,396);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='i')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(500,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='d')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(100,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='g'||a=='f'||a=='a'||a=='e'||a=='h'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,436,160,68);
				gfx_color(0,0,0);
				gfx_text("I",510,496);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='b')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(300,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='k')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(300,536,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='c'||a=='g'||a=='f'||a=='a'||a=='e'||a=='h'||a=='j'||a=='d'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,236,160,68);
				gfx_color(0,0,0);
				gfx_text("B",310,296);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='k')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(300,536,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='b')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(300,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='c'||a=='g'||a=='f'||a=='a'||a=='e'||a=='h'||a=='j'||a=='d'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,536,160,68);
				gfx_color(0,0,0);
				gfx_text("K",310,596);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='c')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(500,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='j')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(100,536,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='k'||a=='g'||a=='f'||a=='a'||a=='e'||a=='h'||a=='b'||a=='d'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,236,160,68);
				gfx_color(0,0,0);
				gfx_text("C",510,296);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='j')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(100,536,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='c')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(500,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='k'||a=='g'||a=='f'||a=='a'||a=='e'||a=='h'||a=='b'||a=='d'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,536,160,68);
				gfx_color(0,0,0);
				gfx_text("J",110,596);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='f')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(500,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='l')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(500,536,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='k'||a=='g'||a=='j'||a=='a'||a=='e'||a=='h'||a=='b'||a=='d'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,336,160,68);
				gfx_color(0,0,0);
				gfx_text("F",510,396);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='l')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(500,536,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='f')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(500,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='k'||a=='g'||a=='j'||a=='a'||a=='e'||a=='h'||a=='b'||a=='d'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,536,160,68);
				gfx_color(0,0,0);
				gfx_text("L",510,596);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		else if ((gfx_xpos() > 805 && gfx_xpos() < 895) && (gfx_ypos() > 588 && gfx_ypos() < 633) || a =='4')
		{
			h++;
			h = hint_level_two_one(h);
		}
	}
	
	end = time(NULL); 
	
	time2 = difftime(end, start);
	
	printf("Time2 is %d\n", time2);
	*ptime_lvl2 = time2;
	
	*pi_lvl2=i; *pw_lvl2=w;
	printf("*pi_lvl2=%d; *pw_lvl2=%d\n", *pi_lvl2, *pw_lvl2);
	
	/*Life and total played*/

	printf("i (Level 2) = %d\n", i);
	printf("w (Level 2) = %d\n", w);
}

void level_two_two(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2)
{
	char a;
	int i=0,w=0,h=0;
	int time2;
	
	time_t start, end; 
	
	start = time(NULL); 
	
	while (i<6 && w<3)
	{
		a = gfx_wait();
		if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='a')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(100,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='d')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(100,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,236,160,68);
				gfx_color(0,0,0);
				gfx_text("A",110,296);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='d')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(100,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(100,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,336,160,68);
				gfx_color(0,0,0);
				gfx_text("D",110,396);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='e')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(300,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='h')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(300,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='a'||a=='f'||a=='g'||a=='d'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,336,160,68);
				gfx_color(0,0,0);
				gfx_text("E",310,396);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='h')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(300,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='e')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(300,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='a'||a=='f'||a=='g'||a=='d'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,436,160,68);
				gfx_color(0,0,0);
				gfx_text("H",310,496);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='i')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(500,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='l')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(500,536,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='b'||a=='c'||a=='a'||a=='f'||a=='g'||a=='d'||a=='h'||a=='j'||a=='k'||a=='e')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,436,160,68);
				gfx_color(0,0,0);
				gfx_text("I",510,496);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='l')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(500,536,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='i')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(500,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='b'||a=='c'||a=='a'||a=='f'||a=='g'||a=='d'||a=='h'||a=='j'||a=='k'||a=='e')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,536,160,68);
				gfx_color(0,0,0);
				gfx_text("L",510,596);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='g')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(100,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='f')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(500,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='a'||a=='l'||a=='i'||a=='d'||a=='h'||a=='j'||a=='k'||a=='e')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,436,160,68);
				gfx_color(0,0,0);
				gfx_text("G",110,496);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='f')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(500,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='g')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(100,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='a'||a=='l'||a=='i'||a=='d'||a=='h'||a=='j'||a=='k'||a=='e')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,336,160,68);
				gfx_color(0,0,0);
				gfx_text("F",510,396);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='j')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(100,536,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='b')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(300,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='f'||a=='c'||a=='a'||a=='l'||a=='i'||a=='d'||a=='h'||a=='g'||a=='k'||a=='e')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,536,160,68);
				gfx_color(0,0,0);
				gfx_text("J",110,596);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='b')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(300,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='j')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(100,536,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='f'||a=='c'||a=='a'||a=='l'||a=='i'||a=='d'||a=='h'||a=='g'||a=='k'||a=='e')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,236,160,68);
				gfx_color(0,0,0);
				gfx_text("B",310,296);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='k')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(300,536,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='c')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(500,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='f'||a=='b'||a=='a'||a=='l'||a=='i'||a=='d'||a=='h'||a=='g'||a=='j'||a=='e')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,536,160,68);
				gfx_color(0,0,0);
				gfx_text("K",310,596);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='c')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(500,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='k')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(300,536,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='f'||a=='b'||a=='a'||a=='l'||a=='i'||a=='d'||a=='h'||a=='g'||a=='j'||a=='e')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,236,160,68);
				gfx_color(0,0,0);
				gfx_text("C",510,296);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		else if ((gfx_xpos() > 805 && gfx_xpos() < 895) && (gfx_ypos() > 588 && gfx_ypos() < 633) || a == '4')
		{
			h++;
			h = hint_level_two_two(h);
		}
	}
	
	end = time(NULL); 
	
	time2 = difftime(end, start);
	
	printf("Time2 is %d\n", time2);
	*ptime_lvl2 = time2;
	
	*pi_lvl2=i; *pw_lvl2=w;
	
	/*Life and total played*/

	printf("i (Level 2) = %d\n", i);
	printf("w (Level 2) = %d\n", w);
}

void level_two_three(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2)
{
	char a;
	int i=0, w=0, h=0;
	int time2;
	
	time_t start, end; 
	
	start = time(NULL); 
	
	while (i<6 && w<3)
	{
		a = gfx_wait();
		if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='c')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(500,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='j')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(100,536,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='a'||a=='b'||a=='d'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,236,160,68);
				gfx_color(0,0,0);
				gfx_text("C",510,296);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='j')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(100,536,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='c')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(500,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='a'||a=='b'||a=='d'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,536,160,68);
				gfx_color(0,0,0);
				gfx_text("J",110,596);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='a')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(100,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='l')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(500,536,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='b'||a=='d'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='k'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,236,160,68);
				gfx_color(0,0,0);
				gfx_text("A",110,296);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='l')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(500,536,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(100,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='b'||a=='d'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='k'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,536,160,68);
				gfx_color(0,0,0);
				gfx_text("L",510,596);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='b')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(300,236,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='k')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(300,536,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='a'||a=='d'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='l'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,236,160,68);
				gfx_color(0,0,0);
				gfx_text("B",310,296);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='k')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(300,536,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='b')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(300,236,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='a'||a=='d'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='l'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,536,160,68);
				gfx_color(0,0,0);
				gfx_text("K",310,596);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='d')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(100,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='g')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(100,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='a'||a=='b'||a=='e'||a=='f'||a=='k'||a=='h'||a=='i'||a=='l'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,336,160,68);
				gfx_color(0,0,0);
				gfx_text("D",110,396);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='g')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(100,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='d')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(100,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='a'||a=='b'||a=='e'||a=='f'||a=='k'||a=='h'||a=='i'||a=='l'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,436,160,68);
				gfx_color(0,0,0);
				gfx_text("G",110,496);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='e')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(300,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='i')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(500,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='a'||a=='b'||a=='d'||a=='f'||a=='k'||a=='h'||a=='g'||a=='l'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,336,160,68);
				gfx_color(0,0,0);
				gfx_text("E",310,396);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='i')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(500,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='e')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(300,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='a'||a=='b'||a=='d'||a=='f'||a=='k'||a=='h'||a=='g'||a=='l'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,436,160,68);
				gfx_color(0,0,0);
				gfx_text("I",510,496);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='h')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(300,436,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='f')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(500,336,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='a'||a=='b'||a=='d'||a=='i'||a=='k'||a=='e'||a=='g'||a=='l'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,436,160,68);
				gfx_color(0,0,0);
				gfx_text("H",310,496);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='f')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(500,336,160,68);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='h')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(300,436,160,68);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='j'||a=='a'||a=='b'||a=='d'||a=='i'||a=='k'||a=='e'||a=='g'||a=='l'||a=='c')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,336,160,68);
				gfx_color(0,0,0);
				gfx_text("F",510,396);
				w++;
				Lose_chances_lvl_two(w);
			}
		}
		else if ((gfx_xpos() > 805 && gfx_xpos() < 895) && (gfx_ypos() > 588 && gfx_ypos() < 633) || a =='4')
		{
			h++;
			h = hint_level_two_three(h);
		}
	}
	end = time(NULL); 
	
	time2 = difftime(end, start);
	
	printf("Time2 is %d\n", time2);
	*ptime_lvl2 = time2;
	
	*pi_lvl2=i; *pw_lvl2=w;
	
	/*Life and total played*/

	printf("i (Level 2) = %d\n", i);
	printf("w (Level 2) = %d\n", w);
}

void random_lvl_two(int *pcount2, int *pwin_lvl2, int *pw_lvl2, int *pi_lvl2, int *ptime_lvl2)
{
	int lower = 1, upper = 3, count = 1; 

	// Use current time as 
	// seed for random generator 
	srand(time(0)); 

	int i, num; 
	for (i = 0; i < count; i++) { 
		int num = (rand() % (upper - lower + 1)) + lower; 
		printf("(Random) Level 2: Case %d\n ", num); 
		
		if (num==1)
		{
			level_two_one(pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2);
		}
		else if (num==2)
		{
			level_two_two(pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2);
		}
		else if (num==3)
		{
			level_two_three(pcount2,pwin_lvl2,pw_lvl2,pi_lvl2,ptime_lvl2);
		}
	} 
}

void win_lvl_two(int *ptime2, int w2) //pass time value
{
	int a;
	int time2;
	char pt2[100];
	char pw2[100];
	char c;
	char button='r';
	//int *ptime1;
	
	/* White Rectangle Outer Line Box */
	gfx_color(255,255,255);
	gfx_rectangle(280,20,400,200);
	
	/* You Won */
	gfx_color(255,255,255);
	gfx_text("CONGRATULATIONS ! ! !", 430,45);
	gfx_text("YOU WON", 455,65);
	/* Next Level Box */
	gfx_color(255,153,153);
	gfx_rectangle(300,150,90,50);
	gfx_color(255,255,255);
	gfx_text("NEXT LEVEL",315,180);
	/* Return to main page Box*/
	gfx_color(204,204,255);
	gfx_rectangle(570,150,90,50);
	gfx_color(255,255,255);
	gfx_text("BACK TO",585,170);
	gfx_text("MAIN PAGE",585,190);
	
	/*Time used*/
	printf("The time used is %d seconds\n", *ptime2);
	sprintf(pt2,"TIME SPEND IN THIS ROUND   : %d seconds",*ptime2);
	gfx_color(255,255,255);
    gfx_text(pt2,300,100);
    
    /*Life remained*/
	printf("Life remained = %d\n", w2);
	sprintf(pw2,"CHANCES REMAINED           : %d", w2);
	gfx_color(255,255,255);
    gfx_text(pw2,300,130);
	
}

void Lose_chances_lvl_two(int Lose)
{
	if (Lose==1)
	{
		gfx_color(255,255,255);
		gfx_fillcircle(920,550,40);
	}
	else if (Lose==2)
	{
		gfx_color(255,255,255);
		gfx_fillcircle(920,550,40);
		gfx_fillcircle(850,550,40);
	}
	else if (Lose==3)
	{
		gfx_color(255,255,255);
		gfx_fillcircle(920,550,40);
		gfx_fillcircle(850,550,40);
		gfx_fillcircle(780,550,40);
		printf("\nLose==3");
	}
}


void Lose_lvl_two(int *ptime2, int *w2) //pass time value
{
	int a;
	int time2;
	char pt2[100];
	char pw2[100];
	//int *ptime1;
	
	//usleep(2500000);
	
	gfx_clear();
	
	/* White Rectangle Outer Line Box */
	gfx_color(255,255,255);
	gfx_rectangle(280,20,400,200);
	
	/* You Won */
	gfx_color(255,255,255);
	gfx_text("SORRY", 465,45);
	gfx_text("YOU LOSE", 455,65);
	/* Next Level Box */
	gfx_color(255,153,153);
	gfx_rectangle(300,150,90,50);
	gfx_color(255,255,255);
	gfx_text("TRY AGAIN",315,180);
	/* Return to main page Box*/
	gfx_color(204,204,255);
	gfx_rectangle(570,150,90,50);
	gfx_color(255,255,255);
	gfx_text("BACK TO",585,170);
	gfx_text("MAIN PAGE",585,190);
	
	/*Time used*/
	printf("The time used is %d seconds\n", *ptime2);
	sprintf(pt2,"TIME SPEND IN THIS ROUND   : %d seconds",*ptime2);
	gfx_color(255,255,255);
    gfx_text(pt2,300,90);
    
    /*Guess made correct*/
	printf("Life remained = %d\n", *ptime2);
	sprintf(pw2,"GUESS MADE CORRECT         : %d",*w2);
	gfx_color(255,255,255);
    gfx_text(pw2,300,115);
    
    /*Life remain*/
    gfx_text("CHANCES REMAINED           : 0", 300,140);
    
	
}

int hint_level_two_one(int h)
{
	gfx_color(255,255,255);
	gfx_text("Hint:", 100,636);
	if (h==1)
	{
		gfx_color(255,255,255);
		gfx_text("A and E are pale turquoise", 100,651);
		return (1);
	}
	else if (h==2)
	{	
		gfx_color(255,255,255);
		gfx_text("G and H are light pink", 100,666);
		return (2);
	}
	else if (h==3)
	{	
		gfx_color(255,255,255);
		gfx_text("D and I are peach puff", 100,681);
		return (3);
	}
}

int hint_level_two_two(int h)
{
	gfx_color(255,255,255);
	gfx_text("Hint:", 100,636);
	if (h==1)
	{
		gfx_color(255,255,255);
		gfx_text("G and F are khaki", 100,651);
		return (1);
	}
	else if (h==2)
	{	
		gfx_color(255,255,255);
		gfx_text("B and J are pale green", 100,666);
		return (2);
	}
	else if (h==3)
	{	
		gfx_color(255,255,255);
		gfx_text("C and K are plum", 100,681);
		return (3);
	}
}

int hint_level_two_three(int h)
{
	gfx_color(255,255,255);
	gfx_text("Hint:", 100,636);
	if (h==1)
	{
		gfx_color(255,255,255);
		gfx_text("C and J are pale turquoise", 100,651);
		return(1);
	}
	else if (h==2)
	{	
		gfx_color(255,255,255);
		gfx_text("A and L are light pink", 100,666);
		return(2);
	}
	else if (h==3)
	{	
		gfx_color(255,255,255);
		gfx_text("B and K are peach puff", 100,681);
		return (3);
	}
}

/*--------------- Level 3 -------------------*/
void info_three() //third page
{
			//gfx_clear();//clear screen
			gfx_text("----- SCORING RULES -----",425,233);
			gfx_text("YOU HAVE TO FIND OUT THE 6 PAIRS",405,258);
			gfx_text("TO WIN THE GAME IN LEVEL 3.",422,278);
			gfx_text("-------- CHANCES --------",425,323);
			gfx_text("YOU ONLY HAVE 3 CHANCES.",430,348);
			gfx_text("ONCE YOU USE UP THE 3 CHANCES,",415,368);
			gfx_text("        YOU LOSE!!!      ",425,388);
			gfx_text("---------- HINT ---------",425,433);
			gfx_text("PRESS THE HINT BUTTON OR '4' TO GET TIPS",390,458);
			gfx_text("YOU ONLY HAVE 2 HINT IN LEVEL 3",410,478);
			gfx_text("------- WARNING!! -------",425,520);
			gfx_text("ONCE YOU CLICK, YOU CAN'T UNDO",410,553);
			gfx_text("-------------------------------------------",370,583);
			gfx_text("| LEFT CLICK OR PRESS 'ENTER' TO CONTINUE |",370,603);
			gfx_text("-------------------------------------------",370,616);
			
			//mascot//
			gfx_color(255,255,255);
			gfx_fillcircle(950,720,60);
			gfx_fillcircle(950,680,40);
			gfx_color(255,0,0);
			gfx_fillcircle(950,705,8);
			gfx_color(34,139,34);
			gfx_fillcircle(950,720,8);
			gfx_color(255,0,0);
			gfx_fillcircle(950,735,8);
			gfx_color(0,0,0);
			gfx_fillcircle(943,673,6);
			gfx_fillcircle(955,673,6);
			gfx_color(225,215,0);
			gfx_line(900,650,910,660);
			gfx_line(900,720,910,710);
			gfx_color(255,255,255);
			gfx_text("IF YOU WIN, YOU CAN STRAIGHT AWAY PRESS 'N'",630,655);
			gfx_text("OR HIT THE BUTTON TO PROCEED TO NEXT LEVEL.",630,670);
			gfx_text("ELSE HIT THE BUTTON OR PRESS 'M' IF YOU WISH",630,685);
			gfx_text("TO GO BACK TO MAIN PAGE.",630,700);
			gfx_text("GOOD LUCK!!!",630,715);
}

void info_playing_level_three()
{
	/* White Rectangle Outer Line Box */
    	gfx_color(255,255,255);
    	gfx_rectangle(750,150,200,500);
    	
    	/* Game Level */
    	gfx_text("LEVEL 3",830,190);
    	gfx_text("********************************",755,230);
    	
    	/* Introduce color */
    	gfx_color(175,238,238); //pale turquoise colour
    	gfx_fillrectangle(760,260,80,17); 
    	gfx_text("Pale Turquoise",860, 270);
    	gfx_color(255,182,193); //light pink
    	gfx_fillrectangle(760,292,80,17);
    	gfx_text("Light Pink",860, 302);
    	gfx_color(255,218,185); //peach puff
    	gfx_fillrectangle(760,324,80,17);
    	gfx_text("Peach Puff",860, 334);
    	gfx_color(240,230,140); //Khaki
    	gfx_fillrectangle(760,356,80,17);
    	gfx_text("Khaki",860, 366);
    	gfx_color(152,251,152); //pale green
    	gfx_fillrectangle(760,388,80,17);
    	gfx_text("Pale Green",860, 398);
    	gfx_color(221,160,221); //plum
    	gfx_fillrectangle(760,420,80,17);
    	gfx_text("Plum",860, 432);
    	
    	/* Life Symbol */
    	gfx_color(255,255,255);
    	gfx_text("**********  CHANCES  ***********",755,500);
    	gfx_color(178,34,34);
    	gfx_fillcircle(780,550,40);
    	gfx_fillcircle(850,550,40);
    	gfx_fillcircle(920,550,40);   
    	
    	/* Hint Button */
    	gfx_color(255,255,255);
    	gfx_rectangle(805,588,90,45);
    	gfx_text("HINT",840,615);
}

void levelgrid3()
{
	gfx_clear();
	
	gfx_color(255,255,255); 
    gfx_fillrectangle(100,236,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(100,336,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(100,436,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(100,536,160,68);
	
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,236,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,336,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,436,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(300,536,160,68);
    
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,236,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,336,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,436,160,68);
    gfx_color(255,255,255); 
    gfx_fillrectangle(500,536,160,68);

	gfx_color(0,0,0);
	gfx_text("A",110,296);
	gfx_text("D",110,396);
	gfx_text("G",110,496);
	gfx_text("J",110,596);
	
	gfx_text("B",310,296);
	gfx_text("E",310,396);
	gfx_text("H",310,496);
	gfx_text("K",310,596);
	
	gfx_text("C",510,296);
	gfx_text("F",510,396);
	gfx_text("I",510,496);
	gfx_text("L",510,596);
}

void level_three_one(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3)
{
	char a;
	int i=0,w=0,h=0;
	int time3;
	
	time_t start, end; 
	
	start = time(NULL); 
	
	while (i<6 && w<3)
	{
		a = gfx_wait();
		if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='a')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(100,236,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(180, 270, 60);
			gfx_color(175,238,238);
			gfx_fillcircle(200, 270, 60);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='e')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(300,336,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380, 370, 60);
				gfx_color(175,238,238);
				gfx_fillcircle(400, 370, 60);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='d'||a=='f'||a=='g'||a=='h'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,236,160,68);
				gfx_color(0,0,0);
				gfx_text("A",110,296);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='e')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(300,336,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380, 370, 60);
			gfx_color(175,238,238);
			gfx_fillcircle(400, 370, 60);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(100,236,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(180, 270, 60);
				gfx_color(175,238,238);
				gfx_fillcircle(200, 270, 60);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='d'||a=='f'||a=='g'||a=='h'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,336,160,68);
				gfx_color(0,0,0);
				gfx_text("E",310,396);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='g')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(100,436,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(180,453,30);
			gfx_fillcircle(160,466,30);
			gfx_fillcircle(180,466,30);
			gfx_fillcircle(200,466,30);
			gfx_fillcircle(167,485,30);
			gfx_fillcircle(193,485,30);
			gfx_color(255,182,193);
			gfx_fillcircle(180,470,15); 
			
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='h')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(300,436,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380,453,30);
				gfx_fillcircle(360,466,30);
				gfx_fillcircle(380,466,30);
				gfx_fillcircle(400,466,30);
				gfx_fillcircle(367,485,30);
				gfx_fillcircle(393,485,30);
				gfx_color(255,182,193);
				gfx_fillcircle(380,470,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='d'||a=='f'||a=='a'||a=='e'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,436,160,68);
				gfx_color(0,0,0);
				gfx_text("G",110,496);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='h')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(300,436,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380,453,30);
			gfx_fillcircle(360,466,30);
			gfx_fillcircle(380,466,30);
			gfx_fillcircle(400,466,30);
			gfx_fillcircle(367,485,30);
			gfx_fillcircle(393,485,30);
			gfx_color(255,182,193);
			gfx_fillcircle(380,470,15); 
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='g')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(100,436,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(180,453,30);
				gfx_fillcircle(160,466,30);
				gfx_fillcircle(180,466,30);
				gfx_fillcircle(200,466,30);
				gfx_fillcircle(167,485,30);
				gfx_fillcircle(193,485,30);
				gfx_color(255,182,193);
				gfx_fillcircle(180,470,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='b'||a=='c'||a=='d'||a=='f'||a=='a'||a=='e'||a=='i'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,436,160,68);
				gfx_color(0,0,0);
				gfx_text("H",310,496);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='b')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(300,236,160,68);
			gfx_color(255,255,255);
			gfx_fillrectangle(360,241,60,40);
			gfx_fillrectangle(335,261,20,20);
			gfx_fillcircle(360,293,20);
			gfx_fillcircle(410,293,20);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='k')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(300,536,160,68);
				gfx_color(255,255,255);
				gfx_fillrectangle(360,541,60,40);
				gfx_fillrectangle(335,561,20,20);
				gfx_fillcircle(360,593,20);
				gfx_fillcircle(410,593,20);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='h'||a=='c'||a=='d'||a=='f'||a=='a'||a=='e'||a=='i'||a=='j'||a=='g'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,236,160,68);
				gfx_color(0,0,0);
				gfx_text("B",310,296);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='k')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(300,536,160,68);
			gfx_color(255,255,255);
			gfx_fillrectangle(360,541,60,40);
			gfx_fillrectangle(335,561,20,20);
			gfx_fillcircle(360,593,20);
			gfx_fillcircle(410,593,20);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='b')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(300,236,160,68);
				gfx_color(255,255,255);
				gfx_fillrectangle(360,241,60,40);
				gfx_fillrectangle(335,261,20,20);
				gfx_fillcircle(360,293,20);
				gfx_fillcircle(410,293,20);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='h'||a=='c'||a=='d'||a=='f'||a=='a'||a=='e'||a=='i'||a=='j'||a=='g'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,536,160,68);
				gfx_color(0,0,0);
				gfx_text("K",310,596);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='d')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(100,336,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(180,370,60);
			gfx_color(240,230,140);
			gfx_fillrectangle(180,370,80,30);
			gfx_fillcircle(190,360,10);
			gfx_color(255,255,255);
			gfx_fillcircle(190,380,10);
			gfx_fillcircle(203,393,10);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='j')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(100,536,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(180,570,60);
				gfx_color(240,230,140);
				gfx_fillrectangle(180,570,80,30);
				gfx_fillcircle(190,560,10);
				gfx_color(255,255,255);
				gfx_fillcircle(190,580,10);
				gfx_fillcircle(203,593,10);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='h'||a=='c'||a=='k'||a=='f'||a=='a'||a=='e'||a=='i'||a=='b'||a=='g'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,336,160,68);
				gfx_color(0,0,0);
				gfx_text("D",110,396);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='j')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(100,536,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(180,570,60);
			gfx_color(240,230,140);
			gfx_fillrectangle(180,570,80,30);
			gfx_fillcircle(190,560,10);
			gfx_color(255,255,255);
			gfx_fillcircle(190,580,10);
			gfx_fillcircle(203,593,10);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='d')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(100,336,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(180,370,60);
				gfx_color(240,230,140);
				gfx_fillrectangle(180,370,80,30);
				gfx_fillcircle(190,360,10);
				gfx_color(255,255,255);
				gfx_fillcircle(190,380,10);
				gfx_fillcircle(203,393,10);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='h'||a=='c'||a=='k'||a=='f'||a=='a'||a=='e'||a=='i'||a=='b'||a=='g'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,536,160,68);
				gfx_color(0,0,0);
				gfx_text("J",110,596);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='c')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(500,236,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580,270,60);
			gfx_color(152,251,152);
			gfx_fillrectangle(580,270,80,30);
			gfx_fillcircle(590,260,10);
			gfx_color(255,255,255);
			gfx_fillcircle(590,280,10);
			gfx_fillcircle(603,293,10);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='l')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(500,536,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580,570,60);
				gfx_color(152,251,152);
				gfx_fillrectangle(580,570,80,30);
				gfx_fillcircle(590,560,10);
				gfx_color(255,255,255);
				gfx_fillcircle(590,580,10);
				gfx_fillcircle(603,593,10);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='h'||a=='d'||a=='k'||a=='f'||a=='a'||a=='e'||a=='i'||a=='b'||a=='g'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,236,160,68);
				gfx_color(0,0,0);
				gfx_text("C",510,296);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='l')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(500,536,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580,570,60);
			gfx_color(152,251,152);
			gfx_fillrectangle(580,570,80,30);
			gfx_fillcircle(590,560,10);
			gfx_color(255,255,255);
			gfx_fillcircle(590,580,10);
			gfx_fillcircle(603,593,10);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='c')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(500,236,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580,270,60);
				gfx_color(152,251,152);
				gfx_fillrectangle(580,270,80,30);
				gfx_fillcircle(590,260,10);
				gfx_color(255,255,255);
				gfx_fillcircle(590,280,10);
				gfx_fillcircle(603,293,10);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='h'||a=='d'||a=='k'||a=='f'||a=='a'||a=='e'||a=='i'||a=='b'||a=='g'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,536,160,68);
				gfx_color(0,0,0);
				gfx_text("L",510,596);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='f')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(500,336,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580,353,30);
			gfx_fillcircle(560,366,30);
			gfx_fillcircle(580,366,30);
			gfx_fillcircle(600,366,30);
			gfx_fillcircle(567,385,30);
			gfx_fillcircle(593,385,30);
			gfx_color(221,160,221);
			gfx_fillcircle(580,370,15); 
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='i')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(500,436,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580,453,30);
				gfx_fillcircle(560,466,30);
				gfx_fillcircle(580,466,30);
				gfx_fillcircle(600,466,30);
				gfx_fillcircle(567,485,30);
				gfx_fillcircle(593,485,30);
				gfx_color(221,160,221);
				gfx_fillcircle(580,470,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='h'||a=='d'||a=='k'||a=='c'||a=='a'||a=='e'||a=='l'||a=='b'||a=='g'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,336,160,68);
				gfx_color(0,0,0);
				gfx_text("F",510,396);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 436 && gfx_ypos() < 604)||a=='i')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(500,436,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580,453,30);
			gfx_fillcircle(560,466,30);
			gfx_fillcircle(580,466,30);
			gfx_fillcircle(600,466,30);
			gfx_fillcircle(567,485,30);
			gfx_fillcircle(593,485,30);
			gfx_color(221,160,221);
			gfx_fillcircle(580,470,15); 
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='f')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(500,336,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580,353,30);
				gfx_fillcircle(560,366,30);
				gfx_fillcircle(580,366,30);
				gfx_fillcircle(600,366,30);
				gfx_fillcircle(567,385,30);
				gfx_fillcircle(593,385,30);
				gfx_color(221,160,221);
				gfx_fillcircle(580,370,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='h'||a=='d'||a=='k'||a=='c'||a=='a'||a=='e'||a=='l'||a=='b'||a=='g'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,436,160,68);
				gfx_color(0,0,0);
				gfx_text("I",510,496);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		else if ((gfx_xpos() > 805 && gfx_xpos() < 895) && (gfx_ypos() > 588 && gfx_ypos() < 633) || a == '4')
		{
			h++;
			h = hint_level_three_one(h);
		}
	}
	
	end = time(NULL); 
	
	time3 = difftime(end, start);
	
	printf("Time3 is %d\n", time3);
	*ptime_lvl3 = time3;
	
	*pi_lvl3=i; *pw_lvl3=w;
	printf("In level three *pi_lvl3=%d; *pw_lvl3=%d\n", *pi_lvl3, *pw_lvl3);
	
	/*Life and total played*/

	printf("i (Level 3) = %d\n", i);
	printf("w (Level 3) = %d\n", w);
	
	//play_lvl3(pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3);
}

void level_three_two(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3)
{
	char a;
	int i=0,w=0,h=0;
	int time3;
	
	time_t start, end; 
	
	start = time(NULL); 
	
	while (i<6 && w<3)
	{
		a = gfx_wait();
		if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='j')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(100,536,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(180, 570, 60);
			gfx_color(175,238,238);
			gfx_fillcircle(200, 570, 60);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='c')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(500,236,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580, 270, 60);
				gfx_color(175,238,238);
				gfx_fillcircle(600, 270, 60);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='a'||a=='b'||a=='d'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,536,160,68);
				gfx_color(0,0,0);
				gfx_text("J",110,596);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='c')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(500,236,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580, 270, 60);
			gfx_color(175,238,238);
			gfx_fillcircle(600, 270, 60);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='j')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(100,536,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(180, 570, 60);
				gfx_color(175,238,238);
				gfx_fillcircle(200, 570, 60);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='a'||a=='b'||a=='d'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,236,160,68);
				gfx_color(0,0,0);
				gfx_text("C",510,296);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='d')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(100,336,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(180,353,30);
			gfx_fillcircle(160,366,30);
			gfx_fillcircle(180,366,30);
			gfx_fillcircle(200,366,30);
			gfx_fillcircle(167,385,30);
			gfx_fillcircle(193,385,30);
			gfx_color(255,182,193);
			gfx_fillcircle(180,370,15); 
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='l')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(500,536,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580,553,30);
				gfx_fillcircle(560,566,30);
				gfx_fillcircle(580,566,30);
				gfx_fillcircle(600,566,30);
				gfx_fillcircle(567,585,30);
				gfx_fillcircle(593,585,30);
				gfx_color(255,182,193);
				gfx_fillcircle(580,570,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a'||a=='b'||a=='c'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='k'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,336,160,68);
				gfx_color(0,0,0);
				gfx_text("D",110,396);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='l')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(500,536,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580,553,30);
			gfx_fillcircle(560,566,30);
			gfx_fillcircle(580,566,30);
			gfx_fillcircle(600,566,30);
			gfx_fillcircle(567,585,30);
			gfx_fillcircle(593,585,30);
			gfx_color(255,182,193);
			gfx_fillcircle(580,570,15);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='d')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(100,336,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(180,353,30);
				gfx_fillcircle(160,366,30);
				gfx_fillcircle(180,366,30);
				gfx_fillcircle(200,366,30);
				gfx_fillcircle(167,385,30);
				gfx_fillcircle(193,385,30);
				gfx_color(255,182,193);
				gfx_fillcircle(180,370,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a'||a=='b'||a=='c'||a=='e'||a=='f'||a=='g'||a=='h'||a=='i'||a=='k'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,536,160,68);
				gfx_color(0,0,0);
				gfx_text("L",510,596);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='a')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(100,236,160,68);
			gfx_color(255,255,255);
			gfx_fillrectangle(160,241,60,40);
			gfx_fillrectangle(135,261,20,20);
			gfx_fillcircle(160,293,20);
			gfx_fillcircle(210,293,20);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='f')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(500,336,160,68);
				gfx_color(255,255,255);
				gfx_fillrectangle(560,341,60,40);
				gfx_fillrectangle(535,361,20,20);
				gfx_fillcircle(560,393,20);
				gfx_fillcircle(610,393,20);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='d'||a=='b'||a=='c'||a=='e'||a=='l'||a=='g'||a=='h'||a=='i'||a=='k'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,236,160,68);
				gfx_color(0,0,0);
				gfx_text("A",110,296);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='f')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(500,336,160,68);
			gfx_color(255,255,255);
			gfx_fillrectangle(560,341,60,40);
			gfx_fillrectangle(535,361,20,20);
			gfx_fillcircle(560,393,20);
			gfx_fillcircle(610,393,20);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(100,236,160,68);
				gfx_color(255,255,255);
				gfx_fillrectangle(160,241,60,40);
				gfx_fillrectangle(135,261,20,20);
				gfx_fillcircle(160,293,20);
				gfx_fillcircle(210,293,20);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='d'||a=='b'||a=='c'||a=='e'||a=='l'||a=='g'||a=='h'||a=='i'||a=='k'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,336,160,68);
				gfx_color(0,0,0);
				gfx_text("F",510,396);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='g')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(100,436,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(180,470,60);
			gfx_color(240,230,140);
			gfx_fillrectangle(180,470,80,30);
			gfx_fillcircle(190,460,10);
			gfx_color(255,255,255);
			gfx_fillcircle(190,480,10);
			gfx_fillcircle(203,493,10);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='e')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(300,336,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380,370,60);
				gfx_color(240,230,140);
				gfx_fillrectangle(380,370,80,30);
				gfx_fillcircle(390,360,10);
				gfx_color(255,255,255);
				gfx_fillcircle(390,380,10);
				gfx_fillcircle(403,393,10);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='d'||a=='b'||a=='c'||a=='a'||a=='l'||a=='f'||a=='h'||a=='i'||a=='k'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,436,160,68);
				gfx_color(0,0,0);
				gfx_text("G",110,496);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='e')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(300,336,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380,370,60);
			gfx_color(240,230,140);
			gfx_fillrectangle(380,370,80,30);
			gfx_fillcircle(390,360,10);
			gfx_color(255,255,255);
			gfx_fillcircle(390,380,10);
			gfx_fillcircle(403,393,10);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='g')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(100,436,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(180,470,60);
				gfx_color(240,230,140);
				gfx_fillrectangle(180,470,80,30);
				gfx_fillcircle(190,460,10);
				gfx_color(255,255,255);
				gfx_fillcircle(190,480,10);
				gfx_fillcircle(203,493,10);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='d'||a=='b'||a=='c'||a=='a'||a=='l'||a=='f'||a=='h'||a=='i'||a=='k'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,336,160,68);
				gfx_color(0,0,0);
				gfx_text("E",310,396);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='b')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(300,236,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380,270,60);
			gfx_color(152,251,152);
			gfx_fillrectangle(380,270,80,30);
			gfx_fillcircle(390,260,10);
			gfx_color(255,255,255);
			gfx_fillcircle(390,280,10);
			gfx_fillcircle(403,293,10);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='h')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(300,436,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380,470,60);
				gfx_color(152,251,152);
				gfx_fillrectangle(380,470,80,30);
				gfx_fillcircle(390,460,10);
				gfx_color(255,255,255);
				gfx_fillcircle(390,480,10);
				gfx_fillcircle(403,493,10);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='d'||a=='e'||a=='c'||a=='a'||a=='l'||a=='f'||a=='g'||a=='i'||a=='k'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,236,160,68);
				gfx_color(0,0,0);
				gfx_text("B",310,296);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='h')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(300,436,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380,470,60);
			gfx_color(152,251,152);
			gfx_fillrectangle(380,470,80,30);
			gfx_fillcircle(390,460,10);
			gfx_color(255,255,255);
			gfx_fillcircle(390,480,10);
			gfx_fillcircle(403,493,10);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='b')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(300,236,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380,270,60);
				gfx_color(152,251,152);
				gfx_fillrectangle(380,270,80,30);
				gfx_fillcircle(390,260,10);
				gfx_color(255,255,255);
				gfx_fillcircle(390,280,10);
				gfx_fillcircle(403,293,10);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='d'||a=='e'||a=='c'||a=='a'||a=='l'||a=='f'||a=='g'||a=='i'||a=='k'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,436,160,68);
				gfx_color(0,0,0);
				gfx_text("H",310,496);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='k')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(300,536,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380,553,30);
			gfx_fillcircle(360,566,30);
			gfx_fillcircle(380,566,30);
			gfx_fillcircle(400,566,30);
			gfx_fillcircle(367,585,30);
			gfx_fillcircle(393,585,30);
			gfx_color(221,160,221);
			gfx_fillcircle(380,570,15); 
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='i')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(500,436,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580,453,30);
				gfx_fillcircle(560,466,30);
				gfx_fillcircle(580,466,30);
				gfx_fillcircle(600,466,30);
				gfx_fillcircle(567,485,30);
				gfx_fillcircle(593,485,30);
				gfx_color(221,160,221);
				gfx_fillcircle(580,470,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='d'||a=='e'||a=='c'||a=='a'||a=='l'||a=='f'||a=='g'||a=='h'||a=='b'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,536,160,68);
				gfx_color(0,0,0);
				gfx_text("K",310,596);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='i')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(500,436,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580,453,30);
			gfx_fillcircle(560,466,30);
			gfx_fillcircle(580,466,30);
			gfx_fillcircle(600,466,30);
			gfx_fillcircle(567,485,30);
			gfx_fillcircle(593,485,30);
			gfx_color(221,160,221);
			gfx_fillcircle(580,470,15); 
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='k')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(300,536,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380,553,30);
				gfx_fillcircle(360,566,30);
				gfx_fillcircle(380,566,30);
				gfx_fillcircle(400,566,30);
				gfx_fillcircle(367,585,30);
				gfx_fillcircle(393,585,30);
				gfx_color(221,160,221);
				gfx_fillcircle(380,570,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='d'||a=='e'||a=='c'||a=='a'||a=='l'||a=='f'||a=='g'||a=='h'||a=='b'||a=='j')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,436,160,68);
				gfx_color(0,0,0);
				gfx_text("I",510,496);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		else if ((gfx_xpos() > 805 && gfx_xpos() < 895) && (gfx_ypos() > 588 && gfx_ypos() < 633)|| a == '4')
		{
			h++;
			h = hint_level_three_two(h);
		}
	}
	end = time(NULL); 
	
	time3 = difftime(end, start);
	
	printf("Time3 is %d\n", time3);
	*ptime_lvl3 = time3;
	
	*pi_lvl3=i; *pw_lvl3=w;
	printf("*pi_lvl3=%d; *pw_lvl3=%d\n", *pi_lvl3, *pw_lvl3);
	
	/*Life and total played*/

	printf("i (Level 3) = %d\n", i);
	printf("w (Level 3) = %d\n", w);	
}

void level_three_three(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3)
{
	char a;
	int i=0,w=0,h=0;
	int time3;
	
	time_t start, end; 
	
	start = time(NULL); 
	
	while (i<6 && w<3)
	{
		a = gfx_wait();
		if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='e')
        {
			gfx_color(175,238,238); //pale turquoise
			gfx_fillrectangle(300,336,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380, 370, 60);
			gfx_color(175,238,238);
			gfx_fillcircle(400, 370, 60);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='i')
			{
				gfx_color(175,238,238); //pale turquiose
				gfx_fillrectangle(500,436,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580, 470, 60);
				gfx_color(175,238,238);
				gfx_fillcircle(600, 470, 60);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='a'||a=='b'||a=='c'||a=='d'||a=='f'||a=='g'||a=='h'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,336,160,68);
				gfx_color(0,0,0);
				gfx_text("E",310,396);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='i')
        {
			gfx_color(175,238,238); //pale turquiose
			gfx_fillrectangle(500,436,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580, 470, 60);
			gfx_color(175,238,238);
			gfx_fillcircle(600, 470, 60);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='e')
			{
				gfx_color(175,238,238); //pale turquoise
				gfx_fillrectangle(300,336,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380, 370, 60);
				gfx_color(175,238,238);
				gfx_fillcircle(400, 370, 60);
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='a'||a=='b'||a=='c'||a=='d'||a=='f'||a=='g'||a=='h'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,436,160,68);
				gfx_color(0,0,0);
				gfx_text("I",510,496);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='a')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(100,236,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(180,253,30);
			gfx_fillcircle(160,266,30);
			gfx_fillcircle(180,266,30);
			gfx_fillcircle(200,266,30);
			gfx_fillcircle(167,285,30);
			gfx_fillcircle(193,285,30);
			gfx_color(255,182,193);
			gfx_fillcircle(180,270,15); 
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='h')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(300,436,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380,453,30);
				gfx_fillcircle(360,466,30);
				gfx_fillcircle(380,466,30);
				gfx_fillcircle(400,466,30);
				gfx_fillcircle(367,485,30);
				gfx_fillcircle(393,485,30);
				gfx_color(255,182,193);
				gfx_fillcircle(380,470,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='b'||a=='c'||a=='d'||a=='f'||a=='g'||a=='e'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,236,160,68);
				gfx_color(0,0,0);
				gfx_text("A",110,296);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='h')
        {
			gfx_color(255,182,193); //light pink
			gfx_fillrectangle(300,436,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380,453,30);
			gfx_fillcircle(360,466,30);
			gfx_fillcircle(380,466,30);
			gfx_fillcircle(400,466,30);
			gfx_fillcircle(367,485,30);
			gfx_fillcircle(393,485,30);
			gfx_color(255,182,193);
			gfx_fillcircle(380,470,15); 
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='a')
			{
				gfx_color(255,182,193); //light pink
				gfx_fillrectangle(100,236,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(180,253,30);
				gfx_fillcircle(160,266,30);
				gfx_fillcircle(180,266,30);
				gfx_fillcircle(200,266,30);
				gfx_fillcircle(167,285,30);
				gfx_fillcircle(193,285,30);
				gfx_color(255,182,193);
				gfx_fillcircle(180,270,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='b'||a=='c'||a=='d'||a=='f'||a=='g'||a=='e'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,436,160,68);
				gfx_color(0,0,0);
				gfx_text("H",310,496);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='d')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(100,336,160,68);
			gfx_color(255,255,255);
			gfx_fillrectangle(160,341,60,40);
			gfx_fillrectangle(135,361,20,20);
			gfx_fillcircle(160,393,20);
			gfx_fillcircle(210,393,20);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='g')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(100,436,160,68);
				gfx_color(255,255,255);
				gfx_fillrectangle(160,441,60,40);
				gfx_fillrectangle(135,461,20,20);
				gfx_fillcircle(160,493,20);
				gfx_fillcircle(210,493,20);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='b'||a=='c'||a=='a'||a=='f'||a=='h'||a=='e'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,336,160,68);
				gfx_color(0,0,0);
				gfx_text("D",110,396);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 436 && gfx_ypos() < 504)||a=='g')
        {
			gfx_color(255,218,185); //peach puff
			gfx_fillrectangle(100,436,160,68);
			gfx_color(255,255,255);
			gfx_fillrectangle(160,441,60,40);
			gfx_fillrectangle(135,461,20,20);
			gfx_fillcircle(160,493,20);
			gfx_fillcircle(210,493,20);
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='d')
			{
				gfx_color(255,218,185); //peach puff
				gfx_fillrectangle(100,336,160,68);
				gfx_color(255,255,255);
				gfx_fillrectangle(160,341,60,40);
				gfx_fillrectangle(135,361,20,20);
				gfx_fillcircle(160,393,20);
				gfx_fillcircle(210,393,20);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='b'||a=='c'||a=='a'||a=='f'||a=='h'||a=='e'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,436,160,68);
				gfx_color(0,0,0);
				gfx_text("G",110,496);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='b')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(300,236,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380,270,60);
			gfx_color(240,230,140);
			gfx_fillrectangle(380,270,80,30);
			gfx_fillcircle(390,260,10);
			gfx_color(255,255,255);
			gfx_fillcircle(390,280,10);
			gfx_fillcircle(403,293,10);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='c')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(500,236,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580,270,60);
				gfx_color(240,230,140);
				gfx_fillrectangle(580,270,80,30);
				gfx_fillcircle(590,260,10);
				gfx_color(255,255,255);
				gfx_fillcircle(590,280,10);
				gfx_fillcircle(603,293,10);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='g'||a=='d'||a=='a'||a=='f'||a=='h'||a=='e'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,236,160,68);
				gfx_color(0,0,0);
				gfx_text("B",310,296);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 236 && gfx_ypos() < 304)||a=='c')
        {
			gfx_color(240,230,140); //khaki
			gfx_fillrectangle(500,236,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580,270,60);
			gfx_color(240,230,140);
			gfx_fillrectangle(580,270,80,30);
			gfx_fillcircle(590,260,10);
			gfx_color(255,255,255);
			gfx_fillcircle(590,280,10);
			gfx_fillcircle(603,293,10);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 236) && (gfx_ypos() < 304))||a=='b')
			{
				gfx_color(240,230,140); //khaki
				gfx_fillrectangle(300,236,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380,270,60);
				gfx_color(240,230,140);
				gfx_fillrectangle(380,270,80,30);
				gfx_fillcircle(390,260,10);
				gfx_color(255,255,255);
				gfx_fillcircle(390,280,10);
				gfx_fillcircle(403,293,10);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='g'||a=='d'||a=='a'||a=='f'||a=='h'||a=='e'||a=='j'||a=='k'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,236,160,68);
				gfx_color(0,0,0);
				gfx_text("C",510,296);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 300 && gfx_xpos() < 460) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='k')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(300,536,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(380,570,60);
			gfx_color(152,251,152);
			gfx_fillrectangle(380,570,80,30);
			gfx_fillcircle(390,560,10);
			gfx_color(255,255,255);
			gfx_fillcircle(390,580,10);
			gfx_fillcircle(403,593,10);
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 336) && (gfx_ypos() < 404))||a=='f')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(500,336,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580,370,60);
				gfx_color(152,251,152);
				gfx_fillrectangle(580,370,80,30);
				gfx_fillcircle(590,360,10);
				gfx_color(255,255,255);
				gfx_fillcircle(590,380,10);
				gfx_fillcircle(603,393,10);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='g'||a=='d'||a=='a'||a=='b'||a=='h'||a=='e'||a=='j'||a=='c'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(300,536,160,68);
				gfx_color(0,0,0);
				gfx_text("K",310,596);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 336 && gfx_ypos() < 404)||a=='f')
        {
			gfx_color(152,251,152); //pale green
			gfx_fillrectangle(500,336,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580,370,60);
			gfx_color(152,251,152);
			gfx_fillrectangle(580,370,80,30);
			gfx_fillcircle(590,360,10);
			gfx_color(255,255,255);
			gfx_fillcircle(590,380,10);
			gfx_fillcircle(603,393,10);
			a = gfx_wait();
			if(((gfx_xpos() > 300) && (gfx_xpos() < 460)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='k')
			{
				gfx_color(152,251,152); //pale green
				gfx_fillrectangle(300,536,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(380,570,60);
				gfx_color(152,251,152);
				gfx_fillrectangle(380,570,80,30);
				gfx_fillcircle(390,560,10);
				gfx_color(255,255,255);
				gfx_fillcircle(390,580,10);
				gfx_fillcircle(403,593,10);
				i++;
			}                    
			else if (((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='i'||a=='g'||a=='d'||a=='a'||a=='b'||a=='h'||a=='e'||a=='j'||a=='c'||a=='l')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,336,160,68);
				gfx_color(0,0,0);
				gfx_text("F",510,396);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 100 && gfx_xpos() < 260) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='j')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(100,536,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(180,553,30);
			gfx_fillcircle(160,566,30);
			gfx_fillcircle(180,566,30);
			gfx_fillcircle(200,566,30);
			gfx_fillcircle(167,585,30);
			gfx_fillcircle(193,585,30);
			gfx_color(221,160,221);
			gfx_fillcircle(180,570,15); 
			a = gfx_wait();
			if(((gfx_xpos() > 500) && (gfx_xpos() < 660)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='l')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(500,536,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(580,553,30);
				gfx_fillcircle(560,566,30);
				gfx_fillcircle(580,566,30);
				gfx_fillcircle(600,566,30);
				gfx_fillcircle(567,585,30);
				gfx_fillcircle(593,585,30);
				gfx_color(221,160,221);
				gfx_fillcircle(580,570,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='i'||a=='g'||a=='d'||a=='a'||a=='b'||a=='h'||a=='e'||a=='f'||a=='c'||a=='k')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(100,536,160,68);
				gfx_color(0,0,0);
				gfx_text("J",110,596);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		
		else if ((gfx_xpos() > 500 && gfx_xpos() < 660) && (gfx_ypos() > 536 && gfx_ypos() < 604)||a=='l')
        {
			gfx_color(221,160,221); //plum
			gfx_fillrectangle(500,536,160,68);
			gfx_color(255,255,255);
			gfx_fillcircle(580,553,30);
			gfx_fillcircle(560,566,30);
			gfx_fillcircle(580,566,30);
			gfx_fillcircle(600,566,30);
			gfx_fillcircle(567,585,30);
			gfx_fillcircle(593,585,30);
			gfx_color(221,160,221);
			gfx_fillcircle(580,570,15);  
			a = gfx_wait();
			if(((gfx_xpos() > 100) && (gfx_xpos() < 260)) && ((gfx_ypos() > 536) && (gfx_ypos() < 604))||a=='j')
			{
				gfx_color(221,160,221); //plum
				gfx_fillrectangle(100,536,160,68);
				gfx_color(255,255,255);
				gfx_fillcircle(180,553,30);
				gfx_fillcircle(160,566,30);
				gfx_fillcircle(180,566,30);
				gfx_fillcircle(200,566,30);
				gfx_fillcircle(167,585,30);
				gfx_fillcircle(193,585,30);
				gfx_color(221,160,221);
				gfx_fillcircle(180,570,15); 
				i++;
			}                    
			else if (((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 100) && (gfx_xpos() < 260) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 436) && (gfx_ypos() < 504)) || ((gfx_xpos() > 300) && (gfx_xpos() < 460) && (gfx_ypos() > 536) && (gfx_ypos() < 604)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 236) && (gfx_ypos() < 304)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 336) && (gfx_ypos() < 404)) || ((gfx_xpos() > 500) && (gfx_xpos() < 660) && (gfx_ypos() > 436) && (gfx_ypos() < 504))||a=='i'||a=='g'||a=='d'||a=='a'||a=='b'||a=='h'||a=='e'||a=='f'||a=='c'||a=='k')
			{
				gfx_color(255,255,255); //return to white
				gfx_fillrectangle(500,536,160,68);
				gfx_color(0,0,0);
				gfx_text("L",510,596);
				w++;
				Lose_chances_lvl_three(w);
			}
		}
		else if ((gfx_xpos() > 805 && gfx_xpos() < 895) && (gfx_ypos() > 588 && gfx_ypos() < 633) || a == '4')
		{
			h++;
			h = hint_level_three_three(h);
		}
	}
	end = time(NULL); 
	
	time3 = difftime(end, start);
	
	printf("Time3 is %d\n", time3);
	*ptime_lvl3 = time3;
	
	*pi_lvl3=i; *pw_lvl3=w;
	printf("*pi_lvl3=%d; *pw_lvl3=%d\n", *pi_lvl3, *pw_lvl3);
	
	/*Life and total played*/

	printf("i (Level 3) = %d\n", i);
	printf("w (Level 3) = %d\n", w);	
	
}

void random_lvl_three(int *pcount3, int *pwin_lvl3, int *pw_lvl3, int *pi_lvl3, int *ptime_lvl3)
{
	int lower = 1, upper = 3, count = 1; 

	// Use current time as 
	// seed for random generator 
	srand(time(0)); 

	int i, num; 
	for (i = 0; i < count; i++) { 
		int num = (rand() % (upper - lower + 1)) + lower; 
		printf("(Random) Level 3: Case %d\n ", num); 
		
		if (num==1)
		{
			level_three_one(pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3);
		}
		else if (num==2)
		{
			level_three_two(pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3);
		}
		else if (num==3)
		{
			level_three_three(pcount3,pwin_lvl3,pw_lvl3,pi_lvl3,ptime_lvl3);
		}
	} 
}

void win_lvl_three(int *ptime3, int w3) //pass time value
{
	int time3;
	char pt3[100];
	char pw3[100];
	//int *ptime1;
	
	/* White Rectangle Outer Line Box */
	gfx_color(255,255,255);
	gfx_rectangle(280,20,400,200);
	
	/* You Won */
	gfx_color(255,255,255);
	gfx_text("CONGRATULATIONS ! ! !", 430,45);
	gfx_text("YOU WON", 455,65);
	/* Next Level Box */
	gfx_color(255,153,153);
	gfx_rectangle(300,150,90,50);
	gfx_color(255,255,255);
	gfx_text("-",320,180);
	/* Return to main page Box*/
	gfx_color(204,204,255);
	gfx_rectangle(570,150,90,50);
	gfx_color(255,255,255);
	gfx_text("BACK TO",585,170);
	gfx_text("MAIN PAGE",585,190);
	
	/*Time used*/
	printf("The time used is %d seconds\n", *ptime3);
	sprintf(pt3,"TIME SPEND IN THIS ROUND   : %d seconds",*ptime3);
	gfx_color(255,255,255);
    gfx_text(pt3,300,100);
    
    /*Life remained*/
	printf("Life remained = %d\n", w3);
	sprintf(pw3,"CHANCES REMAINED           : %d",w3);
	gfx_color(255,255,255);
    gfx_text(pw3,300,130);
}

void Lose_chances_lvl_three(int Lose)
{
	if (Lose==1)
	{
		gfx_color(255,255,255);
		gfx_fillcircle(920,550,40);
	}
	else if (Lose==2)
	{
		gfx_color(255,255,255);
		gfx_fillcircle(920,550,40);
		gfx_fillcircle(850,550,40);
	}
	else if (Lose==3)
	{
		gfx_color(255,255,255);
		gfx_fillcircle(920,550,40);
		gfx_fillcircle(850,550,40);
		gfx_fillcircle(780,550,40);
		printf("\nLose==3");
	}
}

void Lose_lvl_three(int *ptime3, int *w3) //pass time value
{
	int a;
	int time3;
	char pt3[100];
	char pw3[100];
	//int *ptime1;
	
	//usleep(2500000);
	
	gfx_clear();
	
	/* White Rectangle Outer Line Box */
	gfx_color(255,255,255);
	gfx_rectangle(280,20,400,200);
	
	/* You Won */
	gfx_color(255,255,255);
	gfx_text("SORRY", 465,45);
	gfx_text("YOU LOSE", 455,65);
	/* Next Level Box */
	gfx_color(255,153,153);
	gfx_rectangle(300,150,90,50);
	gfx_color(255,255,255);
	gfx_text("TRY AGAIN",315,180);
	/* Return to main page Box*/
	gfx_color(204,204,255);
	gfx_rectangle(570,150,90,50);
	gfx_color(255,255,255);
	gfx_text("BACK TO",585,170);
	gfx_text("MAIN PAGE",585,190);
	
	/*Time used*/
	printf("The time used is %d seconds\n", *ptime3);
	sprintf(pt3,"TIME SPEND IN THIS ROUND   : %d seconds",*ptime3);
	gfx_color(255,255,255);
    gfx_text(pt3,300,90);
    
    /*Guess made correct*/
	printf("Life remained = %d\n", *w3);
	sprintf(pw3,"GUESS MADE CORRECT         : %d",*w3);
	gfx_color(255,255,255);
    gfx_text(pw3,300,115);
    
    /*Life remain*/
    gfx_text("CHANCES REMAINED           : 0", 300,140);
    
}

int hint_level_three_one(int h)
{
	gfx_color(255,255,255);
	gfx_text("Hint:", 100,636);
	if (h==1)
	{
		gfx_color(255,255,255);
		gfx_text("A and E are pale turquoise", 100,651);
		return (1);
	}
	else if (h==2)
	{	
		gfx_color(255,255,255);
		gfx_text("B and K is peach puff", 100,666);
		return (2);
	}
}

int hint_level_three_two(int h)
{
	gfx_color(255,255,255);
	gfx_text("Hint:", 100,636);
	if (h==1)
	{
		gfx_color(255,255,255);
		gfx_text("G and E are khaki", 100,651);
		return (1);
	}
	else if (h==2)
	{	
		gfx_color(255,255,255);
		gfx_text("K and I is plum", 100,666);
		return (2);
	}
}

int hint_level_three_three(int h)
{
	gfx_color(255,255,255);
	gfx_text("Hint:", 100,636);
	if (h==1)
	{
		gfx_color(255,255,255);
		gfx_text("E and I are pale turquoise", 100,651);
		return(1);
	}
	else if (h==2)
	{	
		gfx_color(255,255,255);
		gfx_text("D and G is peach puff", 100,666);
		return (2);
	}
}


