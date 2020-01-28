/* 
filename: ts.c
__author__:wwllaowang
 */

#include "ts.h"

int ts_fd;


int  ts_init(void)
{
	//打开触摸屏
	ts_fd = open("/dev/input/event0",O_RDWR);
	if(ts_fd == -1)
	{
		printf("open ts failure!\n");
		return -1;
	}	
	
}

void ts_uninit(void)
{
	close(ts_fd);
}



//结构体函数，返回单个触摸屏坐标
struct xy  get_pos()
{

	//存放读取坐标相关信息
	struct input_event key;
	struct xy pos;

	
    while(1)
    {
		//阻塞读取屏幕坐标
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //触摸类型
		{
			if(key.code == ABS_X )  //X轴
			{
				pos.x=  key.value;//获取x轴坐标
			}
			
			if(key.code == ABS_Y )
			{
				pos.y=  key.value; //获取y轴坐标
			}
			
		}
	
		
		
			
		if((pos.x>0&&pos.y>0)&&key.type == EV_KEY &&key.code == BTN_TOUCH &&key.value ==0)
		{
			
			break;
		}
		
		//printf(" X :  %d    Y: %d \n",pos.x,pos.y);
	}
	return pos;
}

/**************************************************************************
滑屏算法


UP   上滑
DOWN 下滑
RIGHT  右滑
LEFT   左滑

*********************************************************************/
int get_pos2()
{

	//存放读取坐标相关信息
	struct input_event key;
	struct xy1 pos;
	memset(&pos,0,sizeof (struct xy1));
	
    while(1)
    {
		//阻塞读取屏幕坐标
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //触摸类型
		{
			if(key.code == ABS_X )  //X轴
			{
				
				pos.x1=  key.value; //获取x轴坐标
			}
			
			if(key.code == ABS_Y )
			{
				pos.y1=  key.value; //获取y轴坐标
				if(pos.x1>0&&pos.y1>0)
				{
					break;
				}
			}
			
		}
	
		
	}	
			
     while(1)
    {
		//阻塞读取屏幕坐标
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //触摸类型
		{
			if(key.code == ABS_X )  //X轴
			{
				
				pos.x2=  key.value; //获取x轴坐标
			}
			
			if(key.code == ABS_Y )
			{
				pos.y2=  key.value; //获取y轴坐标
			}
			
		}
	
				
		if( pos.x2>0 && pos.y2>0 && key.type == EV_KEY &&key.code == BTN_TOUCH &&key.value ==0)
		{
			
			break;
		}
	}	
	//printf(" X :  %d    Y: %d \n",pos.x,pos.y);
	
	if( abs(pos.y2 - pos.y1) > abs(pos.x2 - pos.x1) )
	{
		if(pos.y2 > pos.y1)
			return DOWN;
		else 
			return UP;
	}
	else 
	{
		if(pos.x2 > pos.x1)
			return RIGHT;
		else 
			return LEFT;
	}
}

//结构体函数，处理左右滑动，返回两个坐标值

struct xy1 get_pos1()
{

	//存放读取坐标相关信息
	struct input_event key;
	struct xy1 pos;

	
    while(1)
    {
		//阻塞读取屏幕坐标
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //触摸类型
		{
			if(key.code == ABS_X )  //X轴
			{
				
				pos.x1=  key.value; //获取x轴坐标
			}
			
			if(key.code == ABS_Y )
			{
				pos.y1=  key.value; //获取y轴坐标
				if(pos.x1>0&&pos.y1>0)
				{
					break;
				}
			}
			
		}
	
		
	}	
			
     while(1)
    {
		//阻塞读取屏幕坐标
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //触摸类型
		{
			if(key.code == ABS_X )  //X轴
			{
				
				pos.x2=  key.value; //获取x轴坐标
			}
			
			if(key.code == ABS_Y )
			{
				pos.y2=  key.value; //获取y轴坐标
			}
			
		}
	
				
		if( pos.x2>0 && pos.y2>0 && key.type == EV_KEY &&key.code == BTN_TOUCH &&key.value ==0)
		{
			
			break;
		}
	}	
	//printf(" X :  %d    Y: %d \n",pos.x,pos.y);
	
	return pos;
}



