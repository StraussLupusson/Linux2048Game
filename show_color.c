#include "show_color.h"

char *colorp;
int color_fd;	
void showcolor_init()
{
	// 打开LCD设备
	color_fd = open("/dev/fb0", O_RDWR);

	if(color_fd == -1)
	{
		perror("打开LCD失败");	
		exit(0);
	}

	colorp = mmap(NULL, 
		       800*480*4, 
		       PROT_READ | PROT_WRITE, 
		       MAP_SHARED, 
		       color_fd, 
		       0    
		       );
}

void showcolor_uninit()
{
	
	// 5, 释放资源
	munmap(colorp, 800*480*4);
	close(color_fd);
}


void show_color(int x,int y,int w,int h,int32_t color)
{
	for(int j=y; j<y+h; j++)
	{
		for(int i=x; i<x+w; i++)
		{
			memcpy(colorp+4*i+800*4*j, &color, 4); //通过指针把颜色数据放到映射内存
		}
	}

}

//带底色的刷字      字符      字大小    字的颜色      字的位置x,y    字的个数        背景色
void show_word(wchar_t *a, int size, int word_color,   int x,int y,   int  w,      int32_t backcolor)
{
	//显示汉字
	show_color(x,y,w*size,size+5,backcolor);
	show_hanzi(a,size,word_color, 1,x,y+size);
}	

