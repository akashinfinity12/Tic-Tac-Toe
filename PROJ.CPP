#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>

typedef enum { false = 0, true } bool;

void main()
{

	clrscr();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	// 0: red, 1: cyan, 2: empty
	int gameState[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
	int c1[9] = {175, 175, 175, 325, 325, 325, 475, 475, 475};
	int c2[9] = {100, 250, 400, 100, 250, 400, 100, 250, 400};
	int color[2] = {12,11};
	int numberOfTurns=0,flag=0;

	int activePlayer = 0;
	bool gameActive = true;
	int c;

	settextstyle(8,0,2);
	outtextxy(140,180,"COMPUTER GRAPHICS PROJECT");
	outtextxy(240,220,"TIC-TAC-TOE");
	delay(3000);
	cleardevice();

	line(100, 175, 550, 175);
	line(100, 325, 550, 325);
	line(250, 50, 250, 450);
	line(400, 50, 400, 450);

	settextstyle(0,0,0);

	outtextxy(235,50,"0");
	outtextxy(235,180,"1");
	outtextxy(235,330,"2");
	outtextxy(385,50,"3");
	outtextxy(385,180,"4");
	outtextxy(385,330,"5");
	outtextxy(535,50,"6");
	outtextxy(535,180,"7");
	outtextxy(535,330,"8");

	char player1[40];
	char player2[40];

	cout<<"Please Enter Your Name";
	cout<<"\nPLAYER 1 : ";
	cin>>player1;
	cout<<"PLAYER 2 : ";
	cin>>player2;

	settextstyle(0,0,0);
	outtextxy(10,430,"Player 1: Red");
	outtextxy(10,450,"Player 2: Cyan");
	cout<<"ENTER YOUR CHOICE :\n";
	do
	{
		cin>>c;
		if (gameState[c] == 2 && gameActive) 
		{
			gameState[c] = activePlayer;
			circle(c1[c],c2[c],40);
			setfillstyle(LTBKSLASH_FILL,color[activePlayer]);
			floodfill(c1[c],c2[c],15);
			delay(500);
			activePlayer = activePlayer ? 0 : 1;
			++numberOfTurns;

			int winningPositions[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
			int winningPosition[3];
			bool winnerCheck = true;

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					winningPosition [j] = winningPositions[i][j];
				}

				if (gameState[winningPosition[0]] == gameState[winningPosition[1]] && gameState[winningPosition[1]] == gameState[winningPosition[2]] && gameState[winningPosition[0]] != 2)
					{
						gameActive = false;
						winnerCheck = false;

						if (activePlayer == 1)
						{
							cleardevice();
							settextstyle(8,0,2);
							outtextxy(170,200,"The winner is ");
							outtextxy(350,200,player1);
							getch();
						}
						else
						{
							cleardevice();
							settextstyle(8,0,2);
							outtextxy(170,200,"The winner is ");
							outtextxy(350,200,player2);
							getch();
						}

					}

			}
			if (numberOfTurns == 9 && winnerCheck)
			{
				gameActive = false;
				cleardevice();
				settextstyle(8,0,2);
				outtextxy(245,200,"MATCH TIED");
				getch();
			}
		}
	}while(gameActive);

	cleardevice();
	settextstyle(8,0,2);
	outtextxy(160,200,"THANK YOU FOR PLAYING");
	getch();
}