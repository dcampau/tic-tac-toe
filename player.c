/*************************** START HEADER ***********************************
 File:   player.c - 

 Description:
   This module impliments tictactoe player

 Author:   Daniel B. Campau 

 Revision History:
   06/06/18 - DBC
   Original Release

   06/07/18 - DBC
   committed to git

 Notes:  

**************************** END HEADER ************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ttt_defs.h"

PLAYER_STRUCT_TYPE player[PLAYER_COUNT];

/**************************************************************************/

void PlayerInitialize(void)
{
  int iplayer;
  sprintf(player[0].name,"player_X");
  player[0].marker='X';
  sprintf(player[1].name,"player_O");
  player[1].marker='O';

  for (iplayer=0;iplayer<PLAYER_COUNT;iplayer++)
  {
    player[iplayer].win_count=0;
    player[iplayer].loss_count=0;
    player[iplayer].draw_count=0;
  }
}

/**************************************************************************/

void PlayerRegisterWin(int iplayer)
{
  player[iplayer].win_count++;
  player[!iplayer].loss_count++;
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
  {
    printf("PlayerGetWinCount invalid player index %d\n",iplayer);
    return -1;
  }
  else
    return player[iplayer].win_count;
}

/**************************************************************************/

int PlayerGetLossCount(int iplayer)
{
  if ((iplayer<0) || (iplayer>1))
  {
    printf("PlayerGetLossCount invalid player index %d\n",iplayer);
    return -1;
  }
  else
    return player[iplayer].loss_count;
}

/**************************************************************************/

int PlayerGetDrawCount(int iplayer)
{
  if ((iplayer<0) || (iplayer>1))
  {
    printf("PlayerGetDrawCount invalid player index %d\n",iplayer);
    return -1;
  }
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
  {
    printf("PlayerGetMarker invalid player index %d\n",iplayer);
    return '?';
  }
  else
    return player[iplayer].marker;
}

/**************************************************************************/
