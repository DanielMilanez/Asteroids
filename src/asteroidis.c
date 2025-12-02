#include "../inc/dependences.h"

int main(void){
    int x, y;
    CHAR_INFO screen_buffer[HEIGHT][WIDTH];
    
    Start_Up(&x, &y, screen_buffer);

    while (1){
        int prev_x = x;
        int prev_y = y;

        if (Keyboard_Check(K_LEFT))  x--;
        if (Keyboard_Check(K_RIGHT)) x++;
        if (Keyboard_Check(K_UP))    y--;
        if (Keyboard_Check(K_DOWN))  y++;
        
        if (x < 1) x = 1;
        if (x >= WIDTH - 1) x = WIDTH - 2;
        if (y < 1) y = 1;
        if (y >= HEIGHT - 1) y = HEIGHT - 2;

        if (x != prev_x || y != prev_y) {
            if (prev_y >= 1 && prev_y < HEIGHT - 1 && prev_x >= 1 && prev_x < WIDTH - 1) {
                screen_buffer[prev_y][prev_x].Char.UnicodeChar = L' ';
            }
        }

        screen_buffer[y][x].Char.UnicodeChar = L'@';
        screen_buffer[y][x].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY; 

        Render_Frame(screen_buffer);

        Delay(30);
    }

    return 0;
}