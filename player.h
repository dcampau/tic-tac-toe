#ifndef __PLAYER_H
#define __PLAYER_H

void PlayerInitialize(void);
void PlayerRegisterWin(int);
void PlayerRegisterDraw(int);

int PlayerGetWinCount(int);
int PlayerGetLossCount(int);
int PlayerGetDrawCount(int);

char *PlayerGetName(int);
int PlayerGetMarker(int);

#endif
