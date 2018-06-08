/*************************** START HEADER ***********************************
 File:   tictactoe.c - 

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
#include "game.h"
#include "player.h"

/**************************************************************************/

int main()
{
  int b_play_again;
  int b_invalid;
  char resp;
  char resp_str[MAX_BUFF_LEN];

  PlayerInitialize();
  do 
  {
    GameInitialize();
    GamePlay();

    do 
    {
      b_invalid=0;
      sprintf(resp_str,"%s",PromptGetStringResponse("\n Play again? [y:n] "));
      if (strlen(resp_str)==1)
      {
        resp=resp_str[0];
        if ((resp=='y') || (resp=='Y'))
          b_play_again=1;
        else if ((resp=='n') || (resp=='N'))
          b_play_again=0;
        else
          b_invalid=1;
      }
      else
        b_invalid=1;
    } while (b_invalid);

  } while (b_play_again);
}

/**************************************************************************/
