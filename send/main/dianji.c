#include <reg52.h>
#include <dianji.h>
#include <delay.h>
void zz(int iterations)
{
	int j;
    for (j = 0; j < iterations; ++j){
        IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 1;
        delay1(500);
        IN1 = 0; IN2 = 0; IN3 = 0; IN4 = 1;
        delay1(500);
        IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 1;
        delay1(500);
        IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 0;
        delay1(500);
				IN1 = 0; IN2 = 1; IN3 = 1; IN4 = 0;
        delay1(500);
        IN1 = 0; IN2 = 1; IN3 = 0; IN4 = 0;
        delay1(500);
        IN1 = 1; IN2 = 1; IN3 = 0; IN4 = 0;
        delay1(500);
        IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 0;
        delay1(500);
    }
}
void fz(int iterations){
	int j;
				for (j = 0; j < iterations; ++j){
        IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 0;
        delay1(500);
        IN1 = 1; IN2 = 1; IN3 = 0; IN4 = 0;
        delay1(500);
        IN1 = 0; IN2 = 1; IN3 = 0; IN4 = 0;
        delay1(500);
        IN1 = 0; IN2 = 1; IN3 = 1; IN4 = 0;
        delay1(500);
				IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 0;
        delay1(500);
        IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 1;
        delay1(500);
        IN1 = 0; IN2 = 0; IN3 = 0; IN4 = 1;
        delay1(500);
        IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 1;
        delay1(500);
			}
}
void kz(int iterations)
{
	int j;
    for (j = 0; j < iterations; ++j){
        IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 0;
        delay1(200);
        IN1 = 1; IN2 = 1; IN3 = 0; IN4 = 0;
        delay1(200);
        IN1 = 0; IN2 = 1; IN3 = 0; IN4 = 0;
        delay1(200);
        IN1 = 0; IN2 = 1; IN3 = 1; IN4 = 0;
        delay1(200);
				IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 0;
        delay1(200);
        IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 1;
        delay1(200);
        IN1 = 0; IN2 = 0; IN3 = 0; IN4 = 1;
        delay1(200);
        IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 1;
        delay1(200);
    }
}
void mz(int iterations)
{
	int j;
    for (j = 0; j < iterations; ++j){
        IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 0;
        delay1(1000);
        IN1 = 1; IN2 = 1; IN3 = 0; IN4 = 0;
        delay1(1000);
        IN1 = 0; IN2 = 1; IN3 = 0; IN4 = 0;
        delay1(1000);
        IN1 = 0; IN2 = 1; IN3 = 1; IN4 = 0;
        delay1(1000);
				IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 0;
        delay1(1000);
        IN1 = 0; IN2 = 0; IN3 = 1; IN4 = 1;
        delay1(1000);
        IN1 = 0; IN2 = 0; IN3 = 0; IN4 = 1;
        delay1(1000);
        IN1 = 1; IN2 = 0; IN3 = 0; IN4 = 1;
        delay1(1000);
    }
}