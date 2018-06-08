/*************************** START HEADER ***********************************
 File:   tictactoe.c  

 Description:
   This module impliments main function of the tictactoe game

 Author:   Daniel B. Campau 

 Revision History:
   06/05/18 - DBC
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
        if ((resp_str[0]=='y') || (resp_str[0]=='Y'))
          b_play_again=1;
        else if ((resp_str[0]=='n') || (resp_str[0]=='N'))
          b_play_again=0;
        else
          b_invalid=1;
      }
      else
      {
        printf("Invalid reply: %s\n",resp_str);
        b_invalid=1;
      }
    } while (b_invalid);

  } while (b_play_again);
  return 0;
}

/**************************************************************************/
