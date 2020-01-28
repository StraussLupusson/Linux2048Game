#ifndef __TS_H_
#define __TS_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <math.h>
#include <string.h>
#define UP    1
#define DOWN  2
#define RIGHT 3
#define LEFT  4
struct xy1
{
	int x1;
	int y1;
	int x2;
	int y2;
};

struct xy
{
	int x;
	int y;
	
};

struct xy  get_pos();
extern int ts_init(void);
extern void ts_uninit(void);
extern struct xy1  get_pos1();
extern int get_pos2();

#endif