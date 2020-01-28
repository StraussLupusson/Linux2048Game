#ifndef __SHOW_COLOR_H_
#define __SHOW_COLOR_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "font.h"


extern int color_fd;
extern char *colorp;

			
void showcolor_init();
void showcolor_uninit();
void show_color(int x,int y,int w,int h,int32_t color);
void show_word(wchar_t *a,int size,int word_color,int x,int y,int w,int32_t backcolor);//w表示字的数量

#endif