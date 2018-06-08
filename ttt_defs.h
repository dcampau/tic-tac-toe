#ifndef TTT_DEFS_H
#define TTT_DEFS_H

#define SW_MAJOR_VERSION  0
#define SW_MINOR_VERSION  1

#define GRID_SIZE         9
#define PLAYER_COUNT      2

#define MAX_BUFF_LEN 32

typedef struct
{
  char           name[MAX_BUFF_LEN];
  int            win_count;
  int            loss_count;
  int            draw_count;
  char           marker;   // 'X' or 'O' 
} PLAYER_STRUCT_TYPE;

#endif

