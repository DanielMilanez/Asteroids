#include "../inc/dependences.h"

void Hide_Cursor(void){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(consoleHandle, &info);
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void Delay(int ms){
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;
    nanosleep(&ts, NULL);
}

void Start_Up(int *x, int *y, CHAR_INFO buffer[HEIGHT][WIDTH]){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    *x = WIDTH / 2;
    *y = HEIGHT / 2;

    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            buffer[j][i].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
            if (j == 0 || j == HEIGHT - 1) {
                buffer[j][i].Char.UnicodeChar = L'-';
            } else if (i == 0 || i == WIDTH - 1) {
                buffer[j][i].Char.UnicodeChar = L'|';
            } else {
                buffer[j][i].Char.UnicodeChar = L' ';
            }
        }
    }
    Hide_Cursor();
}

uint8_t Keyboard_Check(vk_typedef key){
    int vk;
    switch(key){
        case K_LEFT:  vk = VK_LEFT;  break;
        case K_RIGHT: vk = VK_RIGHT; break;
        case K_UP:    vk = VK_UP;    break;
        case K_DOWN:  vk = VK_DOWN;  break;
    }
    return (GetAsyncKeyState(vk) & 0x8000) != 0;
}

void Render_Frame(CHAR_INFO buffer[HEIGHT][WIDTH]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {WIDTH, HEIGHT};
    COORD bufferCoord = {0, 0};
    SMALL_RECT writeRegion = {0, 0, WIDTH - 1, HEIGHT - 1};

    WriteConsoleOutput(
        hConsole,
        (CHAR_INFO*)buffer,
        bufferSize,
        bufferCoord,
        &writeRegion
    );
}