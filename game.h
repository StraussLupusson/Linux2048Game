#ifndef __GAME_H_
#define __GAME_H_

#include <errno.h>
#include <stdlib.h>

#include"ts.h"
#include "font.h"
#include "show_color.h"
#include <stdbool.h>
#include <time.h>

#define H  4
#define W  4
#define BLOCK_H  120
#define BLOCK_W  120

void num_init(void);//棋盘初始化
void drawline_init();
void game_init();
void game_uninit();
void show_num(void);  
void gamebegain();
void up_deal();
void down_deal();
void left_deal();
void right_deal();
int get_numvalue(wchar_t *b);
bool generator_num(int direct );
bool is_gameover();
#endif