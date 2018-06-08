/*************************** START HEADER ***********************************
 File:   game.c - 

 Description:
   This module impliments tic-tac-toe game function and display

 Author:   Daniel B. Campau 

 Revision History:
   06/05/18 - DBC
   Original Release

   06/07/18 - DBC
   committed to git

 Notes:  

**************************** END HEADER ************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ttt_defs.h"
#include "utils.h"
#include "player.h"

static void            GameUpdateDisplay(void);
static int             GameCheckForWin(void);
static void            GameUpdateGridDisplay(void);
static void            GameUpdateScoreDisplay(void);

static unsigned char   square[9];  // squares in the game grid
static int             current_player=0;
static char            prompt[120];

/**************************************************************************/

void GameInitialize(void)
{
  int i;
  // initialize the squares in the grid with indices for selection
  for (i=0;i<9;i++)
    square[i]='0'+i+1;

  // player_X always starts
  current_player=0;

  GameUpdateDisplay();
}

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
        // check for resign request
        resp=resp_str[0];
        if ((resp=='r') || (resp=='R'))
        {
          printf("%s resigns\n",PlayerGetName(current_player));
          printf("%s wins!\n",PlayerGetName(!current_player));
          return;
        }
        // verify response is in range
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
          if ((square[ival-1]>=(int)'1') && (square[ival-1]<=(int)'9'))
          {
            square[ival-1]=PlayerGetMarker(current_player);
            GameUpdateDisplay();
      
            //valid move - see if it is a game winner
            if (GameCheckForWin())
            {
              PlayerRegisterWin(current_player);
              GameUpdateDisplay();
              printf("%s wins!\n",PlayerGetName(current_player));
              return;
            }

            // mark valid to get out of the loop, and switch players
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
  // played all squares without a winner - call it a draw
  PlayerRegisterDraw(current_player);
  GameUpdateDisplay();
  printf("Game is a draw\n");
}

/**************************************************************************/

static void GameUpdateDisplay(void)
{
  // clear screen
  printf("\033[2J\033[1;1H\n");

  GameUpdateScoreDisplay();
  GameUpdateGridDisplay();
}

/**************************************************************************/

static void GameUpdateScoreDisplay(void)
{
  printf("%s  \t\t%s\n",PlayerGetName(0),PlayerGetName(1));
  printf("wins :   %d\t\twins : %d\n",PlayerGetWinCount(0),PlayerGetWinCount(1));
  printf("losses : %d\t\tlosses : %d\n",PlayerGetLossCount(0),PlayerGetLossCount(1));
  printf("draws :  %d\t\tdraws : %d\n\n",PlayerGetDrawCount(0),PlayerGetDrawCount(1));
}

/**************************************************************************/

static void GameUpdateGridDisplay(void)
{
  printf("\t     |     |      \n");
  printf("\t  %c  |  %c  |  %c   \n",square[0],square[1],square[2]);
  printf("\t     |     |      \n");
  printf("\t__________________\n");
  printf("\t     |     |      \n");
  printf("\t  %c  |  %c  |  %c    \n",square[3],square[4],square[5]);
  printf("\t     |     |      \n");
  printf("\t__________________\n");
  printf("\t     |     |      \n");
  printf("\t  %c  |  %c  |  %c   \n",square[6],square[7],square[8]);
  printf("\t     |     |      \n\n");
}

/**************************************************************************/

static int GameCheckForWin(void)
{
  int b_win;
 
  // check for horizontal wins
  b_win=((square[0]==square[1])&&(square[1]==square[2]));
  b_win=(b_win||((square[3]==square[4])&&(square[4]==square[5])));
  b_win=(b_win||((square[6]==square[7])&&(square[7]==square[8])));
 
  // check for vertical wins
  b_win=(b_win||((square[0]==square[3])&&(square[3]==square[6])));
  b_win=(b_win||((square[1]==square[4])&&(square[4]==square[7])));
  b_win=(b_win||((square[2]==square[5])&&(square[5]==square[8])));
 
  // check for diagonal wins
  b_win=(b_win||((square[0]==square[4])&&(square[4]==square[8])));
  b_win=(b_win||((square[2]==square[4])&&(square[4]==square[6])));

  return b_win;
}

/****************************************************************************/
