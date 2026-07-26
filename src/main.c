#include "display.h"
#include "utils.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main(void)
{
  // Init display
  Display *display = display_init(WINDOW_WIDTH, WINDOW_HEIGHT, "Gravity Sim", FALSE);
  if (!display) return -1;

  // main game loop
  while(!display_should_close(display))
  {
    display_poll_events(display);

    display_swap_buffers(display);
  }

  // cleanup
  display_free(display);
}
