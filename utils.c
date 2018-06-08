/*************************** START HEADER ***********************************
 File:   utils.c -  utility functions for tic-tac-toe application

 Description:

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

/**************************************************************************/

char *PromptGetStringResponse(char *prompt)
{
  int ilen;
  char c;
  static char resp[MAX_BUFF_LEN];

  ilen = 0;
  bzero(resp,MAX_BUFF_LEN);
  printf(prompt);
  while (((c=getchar()) != 0x0a) && (ilen<MAX_BUFF_LEN-1))
  {
    resp[ilen++]=c;
  }
  // on overflow, flush the rest
  if (ilen==(MAX_BUFF_LEN-1))
    while ((c=getchar()) != 0x0a);

  resp[ilen]='\0';
  return resp;
}

/**************************************************************************/

int IntOutOfRange(int val, int min, int max)
{
  int   out_of_range;
  
  out_of_range = 0;
  
  if(val < min)
    out_of_range = 1;

  if(val > max)
    out_of_range = 1; 

  return(out_of_range);
}

/****************************************************************************/
