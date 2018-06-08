#ifndef TTT_DEFS_H
#define TTT_DEFS_H

#define SW_MAJOR_VERSION  0
#define SW_MINOR_VERSION  1

#define GRID_SIZE         9
#define PLAYER_COUNT      2

#define MAX_BUFF_LEN 32

typedef enum
{
  MARKER_X='X',
  MARKER_O='O'
} MARKER_TYPE;

typedef enum
{
  PLAYER_NONE=-1,
  PLAYER_1=0,
  PLAYER_2
} PLAYER_NUM_TYPE;

typedef enum
{
  GS_NO_GAME=-1,
  GS_ACTIVE=0,
  GS_PLAYER_1_WINS,
  GS_PLAYER_2_WINS,
  GS_DRAW
} GAME_STATE_TYPE;

typedef struct
{
  char           name[MAX_BUFF_LEN];
  int            win_count;
  int            loss_count;
  int            draw_count;
  char           marker;   // 'X' or 'O' 
} PLAYER_STRUCT_TYPE;

typedef struct 
{
//  unsigned int     grid_size;  // not needed for fixed grid size version
  unsigned int     grid[GRID_SIZE];
  GAME_STATE_TYPE  game_state; 
  PLAYER_NUM_TYPE  active_player;  
} GAME_STRUCT_TYPE;


#endif
