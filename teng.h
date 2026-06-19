#ifndef TENG-HEADER_H
#define TENG-HEADER_H

//скобки бессмысленные если нет параметров
#define clear printf("\033[2J\033[H")
//макросы внутри самой библеотеки нельзя вызывать извне
//В заголовке надо

typedef struct {
    const int width;
    const int height;
    char* buffer;
} area_t;

//В заголовке должны быть заголовки

//create_area - создаёт зону в терминале
//  width  - ширина
//  height - высота
area_t create_area(int width, int height);

//update - обновляет терминал
//  area - зона для обновления
void update(area_t area);

//change_buffer - обновляет буфер в зоне
//  area   - зона для обновления
//  buffer - новый буфер
void change_buffer(area_t area, char buffer[]);

//update_with_buffer - обновляет зону и вносит изменения в терминал
//  area   - зона для обновления
//  buffer - новый буфер
void update_with_buffer(area_t area, char buffer[]);

//push_char - добавлят символ в зону и обновляет терминал
//  area      - зона для обновления
//  character - символ для добавления
void push_char(area_t area, char character);

//Большинствов IDE показывают подсказки при наведении если есть комментарии над сигнатурой функции.

#endif