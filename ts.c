/* 
filename: ts.c
__author__:wwllaowang
 */

#include "ts.h"

int ts_fd;


int  ts_init(void)
{
	//�򿪴�����
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



//�ṹ�庯�������ص�������������
struct xy  get_pos()
{

	//��Ŷ�ȡ���������Ϣ
	struct input_event key;
	struct xy pos;

	
    while(1)
    {
		//������ȡ��Ļ����
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //��������
		{
			if(key.code == ABS_X )  //X��
			{
				pos.x=  key.value;//��ȡx������
			}
			
			if(key.code == ABS_Y )
			{
				pos.y=  key.value; //��ȡy������
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
�����㷨


UP   �ϻ�
DOWN �»�
RIGHT  �һ�
LEFT   ��

*********************************************************************/
int get_pos2()
{

	//��Ŷ�ȡ���������Ϣ
	struct input_event key;
	struct xy1 pos;
	memset(&pos,0,sizeof (struct xy1));
	
    while(1)
    {
		//������ȡ��Ļ����
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //��������
		{
			if(key.code == ABS_X )  //X��
			{
				
				pos.x1=  key.value; //��ȡx������
			}
			
			if(key.code == ABS_Y )
			{
				pos.y1=  key.value; //��ȡy������
				if(pos.x1>0&&pos.y1>0)
				{
					break;
				}
			}
			
		}
	
		
	}	
			
     while(1)
    {
		//������ȡ��Ļ����
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //��������
		{
			if(key.code == ABS_X )  //X��
			{
				
				pos.x2=  key.value; //��ȡx������
			}
			
			if(key.code == ABS_Y )
			{
				pos.y2=  key.value; //��ȡy������
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

//�ṹ�庯�����������һ�����������������ֵ

struct xy1 get_pos1()
{

	//��Ŷ�ȡ���������Ϣ
	struct input_event key;
	struct xy1 pos;

	
    while(1)
    {
		//������ȡ��Ļ����
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //��������
		{
			if(key.code == ABS_X )  //X��
			{
				
				pos.x1=  key.value; //��ȡx������
			}
			
			if(key.code == ABS_Y )
			{
				pos.y1=  key.value; //��ȡy������
				if(pos.x1>0&&pos.y1>0)
				{
					break;
				}
			}
			
		}
	
		
	}	
			
     while(1)
    {
		//������ȡ��Ļ����
		read(ts_fd,&key,sizeof(struct input_event ));
		
				
		if(key.type == EV_ABS) //��������
		{
			if(key.code == ABS_X )  //X��
			{
				
				pos.x2=  key.value; //��ȡx������
			}
			
			if(key.code == ABS_Y )
			{
				pos.y2=  key.value; //��ȡy������
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



