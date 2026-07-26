#include "display.h"
#include "utils.h"
#include "input.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main(void)
{
  // init display
  Display *display = display_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Gravity Sim", FALSE);
  if (!display) return -1;

  // main game loop
  while(!display_should_close(display))
  {
    display_update(display);

    if (key_down(KEY_ESCAPE))
    {
      display_close(display, TRUE);
    }

    display_swap_buffers(display);
  }

  // cleanup
  display_free(display);
}
