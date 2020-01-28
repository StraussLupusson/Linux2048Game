#ifndef __FONT_H
#define __FONT_H

// ��ʾ ���� ���� �� �ַ� ���� ���� ͼ���
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
//LCD��ʼ��
extern void font_init(void);
//����LCD��ʼ��
extern void font_uninit(void);

//����Ļ��ɺ�ɫ
extern void lcd_clear_display(unsigned int c);
//LCD��㺯��
extern void show_put_pixel(int x ,int y ,unsigned int color);

//���ߺ���
extern void lcd_put_line(int x1, int y1 , int x2, int y2 , unsigned int color);

//��ʾ�����ַ�
void lcd_put_ascii(int x, int y , unsigned int bcolor,unsigned int wcolor,unsigned char c);
//ֻ����ʾ��С���ִ�
void show_charword(int x,int y,int d, unsigned int wcolor,unsigned int bcolor,char *str);//d��ʾ�ַ����
//��ʾGBK������
extern void lcd_put_gbk(int x, int y, unsigned int wcolor,unsigned int bcolor,unsigned char *str );

//Ŀ�����ص���ʾ
extern void draw_bitmap(int color,int flag, FT_Bitmap*  bitmap, FT_Int  x, FT_Int y);


/*******************************************
����˵������ʾ�����ַ�
wchar_t *wtext:����ĺ��ֻ����ַ�
int size	  �������С     
int color	  ��������ɫ
int flag	  �����޵�ɫ��0��ʾ��ɫ 1 �޵�ɫ
int start_x   ����ʾ���������X��
int start_y   ����ʾ���������y��

********************************************/
extern void show_hanzi(wchar_t *wtext,int size,int color, int flag,int start_x,int start_y);




#endif