
/* 
filename: 2048game.c
__author__:wwllaowang
 */
 
#include"game.h"


//改棋盘只需改4个宏W,H,BLOCK_H,BLOCK_W,和a[],photo[]数组图片大小，还有update函数的颜色值
//                  0    1    2    3    4     5     6      7      8      9     10       11
wchar_t *a[12] = {L"0",L"2",L"4",L"8",L"16",L"32",L"64",L"128",L"256",L"512",L"1024",L"2048"};
wchar_t  *num[H][W];
int i,j;



int main(int argc, char *argv[])
{
	game_init();
	show_num();
	printf("game begainning !\n");
	gamebegain();
	game_uninit();
}


void num_init(void)//数组初始化
{
	srand(time(NULL));
		for(j=0;j<H;j++)
	{
			for(i=0;i<W;i++)
			{
				num[j][i] = L"0";
			}
				
	}
	num[rand()%4][rand()%4] = L"2";
}

void drawline_init()//更新画面，不改变数组
{
	
	for(int i = 1;i<4;i++)
	{
		lcd_put_line(160,BLOCK_H*i,640,BLOCK_H*i,BLACK);
		lcd_put_line(160+BLOCK_W*i,0,160+BLOCK_W*i,480,BLACK);
	}
	
}

void game_init()
{
	ts_init();
	font_init();
	showcolor_init();
	show_color(160,0,480,480,WHITE);
	drawline_init();
	num_init();
	
}

void game_uninit()
{
	ts_uninit();
	font_uninit();
	showcolor_uninit();
	
}

//刷图，显示出画面
	void show_num(void)
{
	
	show_color(160,0,480,480,WHITE);
	drawline_init();
	for( j=0;j<W;j++)
		for( i=0;i<H;i++)
		{
			if( wcscmp(num[j][i],L"0") == 0)
				show_color(160+BLOCK_W*j,BLOCK_H*i,120,120,WHITE);
			else
			{
				//不同数字不同大小的字体
				int n = get_numvalue(num[j][i]);
				if( n == 1 ||n == 2||n == 3)
					show_hanzi(a[n],72,DBLUE, 1,205+BLOCK_W*j,BLOCK_H*i+85);
				if( n == 4 ||n == 5||n == 5)
					show_hanzi(a[n],72,DBLUE, 1,190+BLOCK_W*j,BLOCK_H*i+85);
				if( n == 7 ||n == 8||n == 9)
					show_hanzi(a[n],48,DBLUE, 1,185+BLOCK_W*j,BLOCK_H*i+80);
				if( n == 10 ||n == 11)
					show_hanzi(a[n],36,DBLUE, 1,180+BLOCK_W*j,BLOCK_H*i+72);
			}
				
			
		}
	drawline_init();
}

int get_numvalue(wchar_t *b)
{
	for(int k = 1;k<12;k++)
	{
		if( wcscmp(b,a[k]) == 0 )
			return k; 
	}
			
}


bool generator_num(int direct )
{
	switch(direct)
	{
		case UP:
					for(int i = 0;i<100;i++)
					{
						srand(time(NULL));
						int n = rand()%4;
						if( wcscmp(num[n][H-1],L"0") == 0 )
						{
							num[n][H-1] = L"2";
							return false;
						}
						else 
							continue;
						
					}
					
					
		case DOWN:
		
					for(int i = 0;i<100;i++)
					{
						srand(time(NULL));
						int n = rand()%4;
						if( wcscmp(num[n][0],L"0") == 0 )
						{
							num[n][0] = L"2";
							return false;
						}
						else 
							continue;
						
					}
					
		
		case LEFT:
		
					for(int i = 0;i<100;i++)
					{
						srand(time(NULL));
						int n = rand()%4;
						if( wcscmp(num[W-1][n],L"0") == 0 )
						{
							num[W-1][n] = L"2";
							return false;
						}
						else 
							continue;
						
					}
					
						
		case RIGHT:
		
					for(int i = 0;i<100;i++)
					{
						srand(time(NULL));
						int n = rand()%4;
						if( wcscmp(num[0][n],L"0") == 0 )
						{
							num[0][n] = L"2";
							return false;
						}
						else 
							continue;
						
					}
					
	}
	
}

bool is_gameover()
{
	
	for(int j=0;j<H;j++)
	{
		for(int i=0;i<W;i++)
		{
			if(  (i< W-1 && wcscmp(num[i][j],num[i+1][j]) == 0 ) || wcscmp(num[i][j],L"0") == 0 )
				return false;
			else
				continue;
		}
				
	}
	for(int i=0;i<W;i++)
	{
		for(int j=0;j<H;j++)
		{
			if(  (j< H-1 && wcscmp(num[i][j],num[i][j+1]) == 0 ) || wcscmp(num[i][j],L"0") == 0 )
				return false;
			else
				continue;
		}
				
	}
	return true;	
}

void gamebegain()
{
	printf("access gamebegain\n");
	int direct = -1;
	while(1)
	{
		direct = get_pos2();
		if( direct == UP )
		{
			printf("up ......\n");
			up_deal();
			show_num();
		}
		
		if( direct == DOWN )
		{
			printf("down ......\n");
			down_deal();
			show_num();
		}
		
		if( direct == RIGHT )
		{
			printf("right ......\n");
			right_deal();
			show_num();
		}
		
		if( direct == LEFT )
		{
			printf("left ......\n");
			left_deal();
			show_num();
		}
		
		if(is_gameover())
			break;
	}
	printf("game over \n");
}

void up_deal()
{
	for(int z = 0;z<4;z++)//暴力消除法
	{
		for(j=0;j<W;j++)
		{
			for(i=0;i<H;i++)
			{
			
				if(i == 0 )
				{
					if( wcscmp(num[j][i],L"0") == 0 )
					{
						for(int k = 0; k <H-1;k++)
						{
							num[j][k] = num[j][k+1];
						}
						num[j][H-1] =L"0";
					}
						
						
				}
				
				else
				{
					if( wcscmp(num[j][i],L"0") == 0 )
					{
						for(int k = i; k <H-1;k++)
						{
							num[j][k] = num[j][k+1];
						}
						num[j][H-1] =L"0";
					}
					else if( wcscmp(num[j][i],num[j][i-1]) == 0 )
					{
						if(z == 0)//表示只执行一次
						{
							int n =get_numvalue(num[j][i]);
							//printf("n:%d\n",n);
							num[j][i-1] = a[n+1];
							for(int k = i; k <H-1;k++)
							{
								num[j][k] = num[j][k+1];
							}
							num[j][H-1] =L"0";

						}
					}
					
					
				}
				
				
			}
			
		}

	}
	
	//最后一行随机产生数字2
	 generator_num(UP) ;
	
		
	
		
}


void down_deal()
{
	for(int z = 0;z<4;z++)
	{
		for(j=0;j<W;j++)
		{
			for(i=H-1;i>0;i--)
			{
			
				if(i == H-1 )
				{
					if( wcscmp(num[j][i],L"0") == 0 )
					{
						for(int k = H-1; k > 0;k--)
						{
							num[j][k] = num[j][k-1];
						}
						num[j][0] =L"0";
					}
						
						
				}
				
				else
				{
					if( wcscmp(num[j][i],L"0") == 0 )
					{
						for(int k = i; k > 0;k--)
						{
							num[j][k] = num[j][k-1];
						}
						num[j][0] =L"0";
					}
					else if( wcscmp(num[j][i],num[j][i+1]) == 0 )
					{
						if( z == 0 )
						{
							int n =get_numvalue(num[j][i]);
							//printf("n:%d\n",n);
							num[j][i+1] = a[n+1];
							for(int k = i; k > 0;k--)
							{
								num[j][k] = num[j][k-1];
							}
							num[j][0] =L"0";
						}
					}
					
					
				}
			
			
				
				
			}
			
		}
	}
	//最后一行随机产生数字2
	generator_num(DOWN);
	
}

void left_deal()
{
	for(int z = 0;z<4;z++)
	{
		for(i=0;i<H;i++)
		{
			for(j=0;j<W;j++)
			{
			
				if(j == 0 )
				{
					if( wcscmp(num[j][i],L"0") == 0 )
					{
						for(int k = 0; k <W-1;k++)
						{
							num[k][i] = num[k+1][i];
						}
						num[W-1][i] =L"0";
					}
						
						
				}
				
				else
				{
					if( wcscmp(num[j][i],L"0") == 0 )
					{
						for(int k = j; k <W-1;k++)
						{
							num[k][i] = num[k+1][i];
						}
						num[W-1][i] =L"0";
					}
					else if( wcscmp(num[j][i],num[j-1][i]) == 0 )
					{
						if( z == 0)
						{
							int n =get_numvalue(num[j][i]);
							//printf("n:%d\n",n);
							num[j-1][i] = a[n+1];
							for(int k = j; k <W-1;k++)
							{
								num[k][i] = num[k+1][i];
							}
							num[W-1][i] =L"0";
						}
					}
					
					
				}
			
			
				
				
			}
			
		}
	}
	//最后一行随机产生数字2
	generator_num(LEFT);
	
		
}

void right_deal()
{
	for(int z = 0;z<4;z++)
	{
		for(i=0;i<H;i++)
		{
			for(j=W-1;j>0;j--)
			{
			
				if(j == W-1 )
				{
					if( wcscmp(num[j][i],L"0") == 0 )
					{
						for(int k = W-1; k >0;k--)
						{
							num[k][i] = num[k-1][i];
						}
						num[0][i] =L"0";
					}
						
						
				}
				
				else
				{
					if( wcscmp(num[j][i],L"0") == 0 )
					{
						for(int k = j; k >0;k--)
						{
							num[k][i] = num[k-1][i];
						}
						num[0][i] =L"0";
					}
					else if( wcscmp(num[j][i],num[j+1][i]) == 0 )
					{
						if(z == 0)
						{
							int n =get_numvalue(num[j][i]);
							//printf("n:%d\n",n);
							num[j+1][i] = a[n+1];
							for(int k = j; k >0;k--)
							{
								num[k][i] = num[k-1][i];
							}
							num[0][i] =L"0";
						}
					}
					
					
				}
			
			
				
				
			}
			
		}
	}
	//最后一行随机产生数字2
	generator_num(RIGHT);
	
		
}
