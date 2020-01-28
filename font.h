#ifndef __FONT_H
#define __FONT_H

// 显示 横线 竖线 框 字符 汉字 字体 图像等
#include <sys/mman.h>
#include <stdio.h>
#include <linux/fb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <wchar.h>
#include <string.h>
#include "ascii.h"
#include<stdlib.h>
#include <sys/ioctl.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#define GREEN  0x0000FF00
#define RED    0x00FF0000
#define YELLOW 0x00FFFF00
#define BROWN  0x00CC6633
#define BLUE   0x0000FFFF
#define BLACK  0x00000000
#define DBLUE  0x003333FF
#define PURPLE 0x008B008B
#define WHITE  0xFFFFFFFF

#define LCD_WIDTH  			800
#define LCD_HEIGHT 			480
#define FB_SIZE				(LCD_WIDTH * LCD_HEIGHT * 4)



extern unsigned char *fb_mem;
//LCD初始化
extern void font_init(void);
//撤除LCD初始化
extern void font_uninit(void);

//将屏幕清成黑色
extern void lcd_clear_display(unsigned int c);
//LCD描点函数
extern void show_put_pixel(int x ,int y ,unsigned int color);

//画线函数
extern void lcd_put_line(int x1, int y1 , int x2, int y2 , unsigned int color);

//显示当个字符
void lcd_put_ascii(int x, int y , unsigned int bcolor,unsigned int wcolor,unsigned char c);
//只能显示很小的字串
void show_charword(int x,int y,int d, unsigned int wcolor,unsigned int bcolor,char *str);//d表示字符间隔
//显示GBK汉字码
extern void lcd_put_gbk(int x, int y, unsigned int wcolor,unsigned int bcolor,unsigned char *str );

//目标像素点显示
extern void draw_bitmap(int color,int flag, FT_Bitmap*  bitmap, FT_Int  x, FT_Int y);


/*******************************************
函数说明：显示汉字字符
wchar_t *wtext:传入的汉字或者字符
int size	  ：字体大小     
int color	  ：字体颜色
int flag	  ：有无底色，0显示底色 1 无底色
int start_x   ：显示的起点坐标X轴
int start_y   ：显示的起点坐标y轴

********************************************/
extern void show_hanzi(wchar_t *wtext,int size,int color, int flag,int start_x,int start_y);




#endif