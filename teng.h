#ifndef TENG_H
#define TENG_H

typedef struct {
    const int width;
    const int height;
    char* buffer;
} area_t;

area_t create_area(int width, int height);
void update(area_t area);
void change_buffer(area_t *area, char buffer[]);
void update_with_buffer(area_t *area, char buffer[]);

#endif