/*************************** START HEADER ***********************************
 File:   player.c - 

 Description:
   This module impliments tictactoe player

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

PLAYER_STRUCT_TYPE player[2];

/**************************************************************************/

void PlayerInitialize(void)
{
  int iplayer;
  sprintf(player[0].name,"player_X");
  player[0].marker='X';
  sprintf(player[1].name,"player_O");
  player[1].marker='Y';

  for (iplayer=0;iplayer<2;iplayer++)
  {
    player[iplayer].win_count=0;
    player[iplayer].loss_count=0;
    player[iplayer].draw_count=0;
  }
}

/**************************************************************************/

void PlayerRegisterWin(int iplayer)
{
//  player[iplayer].win_count++;
//  player[!iplayer].loss_count++;
  player[0].win_count++;
  player[1].loss_count++;
}

/**************************************************************************/

void PlayerRegisterDraw(int iplayer)
{
  player[iplayer].draw_count++;
  player[!iplayer].draw_count++;
}

/**************************************************************************/

int PlayerGetWinCount(int iplayer)
{
  if ((iplayer<0) || (iplayer>1))
    printf("PlayerGetWinCount invalid player index %d\n",iplayer);
  else
    return player[iplayer].win_count;
}

/**************************************************************************/

int PlayerGetLossCount(int iplayer)
{
  if ((iplayer<0) || (iplayer>1))
    printf("PlayerGetLossCount invalid player index %d\n",iplayer);
  else
    return player[iplayer].loss_count;
}

/**************************************************************************/

int PlayerGetDrawCount(int iplayer)
{
  if ((iplayer<0) || (iplayer>1))
    printf("PlayerGetDrawCount invalid player index %d\n",iplayer);
  else
    return player[iplayer].draw_count;
}

/**************************************************************************/

char *PlayerGetName(int iplayer)
{
  if ((iplayer<0) || (iplayer>1))
  {
    printf("PlayerGetName invalid player index %d\n",iplayer);
    return NULL;
  }
  else
    return player[iplayer].name;;
}

/**************************************************************************/

int PlayerGetMarker(int iplayer)
{
  if ((iplayer<0) || (iplayer>1))
    printf("PlayerGetMarker invalid player index %d\n",iplayer);
  else
    return player[iplayer].marker;
}

/**************************************************************************/
