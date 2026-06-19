#include <stdio.h>
#include <stdlib.h>

#include <string.h>

//Без лишних импортов на Linux
#ifdef _WIN32
    #include <windows.h>
#endif

//Принято инклудить реализовываемый заголовок
#include "teng.h"

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

    area_t area = {.width = width, .height = height, .buffer = buf, .size = S};
    //передаеётся только указатель а не сам буфер.
    //если освободить буфер тут - Use-After-Free в дальнейшем

    return area;
}

void update(area_t area)
{
    for (int i1 = 0; i1 < area.height; i1++) { //Немного пахнет UB если создать два int i
        for (int i = 0; i < area.width; i++) {
            if (i <= area.size)
                printf(area.buffer[i]);
            else
                exit(1);
        }
        printf("\n");
    }
}

//Неудобно если половина функций просят area_t, а другая area_t*
//  плюс лишние разыменовывания
//Структура маленькая, можно держать на стеке.

void change_buffer(area_t area, char buffer[], size_t size)
{
    area.buffer = buffer;
    area.size   = size;
}

void update_with_buffer(area_t area, char buffer[], size_t size)
{
    change_buffer(area, buffer, size);
    update(area);
}

//Удобно чтобы не создавать отдельный буфер для каждого обновления
void push_char(area_t area, char character)
{
    int len = strlen(area.buffer); len++;
    if (area.size > len) {
        area.buffer[len] = character;
        area.buffer[++len] = '\0'; //на всякие случаи
        update(area);
    }
    else exit(1);
}

/* ВАЖНО:
 * Почитай про Raw Mode в терминале.
 * В этом режиме работают все Vim, Nano и тд.
 * Можешь убрать все комментарии если хочешь */