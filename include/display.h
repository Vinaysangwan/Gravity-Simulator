#pragma once

#include "utils.h"

typedef struct Display Display;

Display* display_init(int width, int height, const char* title, bool is_resizable);
void display_free(Display* self);

void display_poll_events(Display* self);
void display_swap_buffers(Display* self);
void display_close(Display* self, bool close);

int display_get_width(const Display* self);
int display_get_height(const Display* self);
bool display_get_is_resizable(const Display* self);
bool display_should_close(const Display* self);
