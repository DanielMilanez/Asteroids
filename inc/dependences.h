#ifndef DEPENDENCES_H
#define DEPENDENCES_H

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdint.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <wincon.h>

typedef enum{
    K_LEFT,
    K_RIGHT,
    K_UP,
    K_DOWN
} vk_typedef;

#define WIDTH 90
#define HEIGHT 30

#define true 1
#define false 0

void Delay(int ms);
void Hide_Cursor(void);
uint8_t Keyboard_Check(vk_typedef key);
void Render_Frame(CHAR_INFO buffer[HEIGHT][WIDTH]);
void Start_Up(int *x, int *y, CHAR_INFO buffer[HEIGHT][WIDTH]);

#endif