#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define clear() (printf("\033[2J\033[H"))

typedef struct {
    const int width;
    const int height;
    char* buffer;
} area_t;

area_t create_area(int width, int height) 
{
    #ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    #endif

    const int S = width * height;

    char* buf = malloc(S * sizeof(char));
    if (!buf) {
        exit(1);
    } else {
        memset(buf, ' ', S);
    }

    area_t area = {.width = width, .height = height, .buffer = buf};
    free(buf);

    return area;
}

void update(area_t area) 
{
    for (int i = 0; i < area.height; i++) {
        for (int i = 0; i < area.width; i++) {
           printf(area.buffer[i]); 
        }  
        printf("\n");
    } 
}

void change_buffer(area_t *area, char buffer[]) 
{
    area->buffer = buffer;
}

void update_with_buffer(area_t *area, char buffer[]) 
{
    change_buffer(&area, buffer);
    update(*area);
}
