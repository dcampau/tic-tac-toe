/*************************** START HEADER ***********************************
 File:   game.c - 

 Description:
   This module impliments tictactoe game

 Author:   Daniel B. Campau 

 Revision History:
   06/05/18 - Daniel B. Campau, 
   Original Release

 Notes:  

**************************** END HEADER ************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ttt_defs.h"
#include "utils.h"

void GameUpdateDisplay(void);
int GameCheckForWin(void);
void GameUpdateGridDisplay(void);
void GameUpdateScoreDisplay(void);

static unsigned char   val[9];
//static unsigned char   marker[2]={'X','O'};
//static char            player[2][32]={"player_X","player_O"};
static int             current_player=0;
static char            prompt[120];

/**************************************************************************/

void GamePlay(void)
{
  int ival;
  char resp;
  int imove;
  int b_invalid;
  char resp_str[32];

  for (imove=0;imove<9;imove++)
  {
    do
    {
      sprintf(prompt,"\n%s: \nmake your move [1..9] (r to resign) : ",PlayerGetName(current_player));
      sprintf(resp_str,"%s",PromptGetStringResponse(prompt));
      if (strlen(resp_str)==1)
      {
        resp=resp_str[0];
        if ((resp=='r') || (resp=='R'))
        {
          printf("%s resigns\n",PlayerGetName(current_player));
          printf("%s wins!\n",PlayerGetName(!current_player));
          return;
        }
        ival = resp - '0';
        b_invalid=IntOutOfRange(ival,1,9);
        if (b_invalid)
        {
          GameUpdateDisplay();
          printf("invalid response:'%c' \ntry again . . \n",resp);
        }
        else
        {
          // entry is in range - 
          // make sure selected square hasn't already been played
          // verify that the marker value currently in the square 
          // is digit between 1 and 9
          if ((val[ival-1]>=(int)'1') && (val[ival-1]<=(int)'9'))
          {
            val[ival-1]=PlayerGetMarker(current_player);
            GameUpdateDisplay();

            if (GameCheckForWin())
            {
              PlayerRegisterWin(current_player);
              GameUpdateDisplay();
              printf("%s wins!\n",PlayerGetName(current_player));
              return;
            }
            // mark valid and switch players
            b_invalid=0;
            current_player=!current_player;
          }
          else
          {
            printf("Illegal move - square has already been played\n");
            b_invalid=1;
          }
        }
      }
      else
      {
        b_invalid=1;
        printf("invalid response:'%s' \ntry again . . \n",resp_str);
        ival=-1;
      }
    } while (b_invalid);
  }
  PlayerRegisterDraw(current_player);
  GameUpdateDisplay();
  printf("Game is a draw\n");
}

/**************************************************************************/

void GameInitialize(void)
{
  int i;
  // initialize the grid with indices for selection
  for (i=0;i<9;i++)
    val[i]='0'+i+1;

  // player_X always starts
  current_player=0;

  GameUpdateDisplay();
}

/**************************************************************************/

void GameUpdateDisplay(void)
{
  // clear screen
  printf("\033[2J\033[1;1H\n");

  GameUpdateScoreDisplay();
  GameUpdateGridDisplay();
}

/**************************************************************************/

void GameUpdateScoreDisplay(void)
{
  printf("%s  \t\t%s\n",PlayerGetName(0),PlayerGetName(1));
  printf("wins :   %d\t\twins : %d\n",PlayerGetWinCount(0),PlayerGetWinCount(1));
  printf("losses : %d\t\tlosses : %d\n",PlayerGetLossCount(0),PlayerGetLossCount(1));
  printf("draws :  %d\t\tdraws : %d\n\n",PlayerGetDrawCount(0),PlayerGetDrawCount(1));
}

/**************************************************************************/

void GameUpdateGridDisplay(void)
{
  printf("\t     |     |      \n");
  printf("\t  %c  |  %c  |  %c   \n",val[0],val[1],val[2]);
  printf("\t     |     |      \n");
  printf("\t__________________\n");
  printf("\t     |     |      \n");
  printf("\t  %c  |  %c  |  %c    \n",val[3],val[4],val[5]);
  printf("\t     |     |      \n");
  printf("\t__________________\n");
  printf("\t     |     |      \n");
  printf("\t  %c  |  %c  |  %c   \n",val[6],val[7],val[8]);
  printf("\t     |     |      \n\n");
}

/**************************************************************************/

int GameCheckForWin(void)
{
  int b_win;
 
  // check for horizontal wins
  b_win=((val[0]==val[1])&&(val[1]==val[2]));
  b_win=(b_win||((val[3]==val[4])&&(val[4]==val[5])));
  b_win=(b_win||((val[6]==val[7])&&(val[7]==val[8])));
 
  // check for vertical wins
  b_win=(b_win||((val[0]==val[3])&&(val[3]==val[6])));
  b_win=(b_win||((val[1]==val[4])&&(val[4]==val[7])));
  b_win=(b_win||((val[2]==val[5])&&(val[5]==val[8])));
 
  // check for diagonal wins
  b_win=(b_win||((val[0]==val[4])&&(val[4]==val[8])));
  b_win=(b_win||((val[2]==val[4])&&(val[4]==val[6])));

  return b_win;
}

/****************************************************************************/
