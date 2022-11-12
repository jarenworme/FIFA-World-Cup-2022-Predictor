#include<stdio.h>

#define NAMELEN 20

int points = 0;
char actual[16][NAMELEN];
char predictions[16][NAMELEN];

enum { P_GS = 1,
	P_BONUS = 2,
	P_RO16 = 2,
	P_QF = 2,
	P_SF = 4,
	P_3RD = 5,
	P_FINAL = 10
};
