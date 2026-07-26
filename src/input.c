#include "input.h"

#include <string.h>

// #############################################################################
//                           Structs
// #############################################################################
typedef struct Keyboard
{
  bool curr_keys[KEY_COUNT];
  bool prev_keys[KEY_COUNT];
} Keyboard;

// #############################################################################
//                           Statics
// #############################################################################
static Keyboard keyboard;

// #############################################################################
//                           Keyboard
// #############################################################################
// Callbacks
void _key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (action == GLFW_PRESS)
  {
    keyboard.curr_keys[key] = TRUE;
  }
  else if (action == GLFW_RELEASE)
  {
    keyboard.curr_keys[key] = FALSE;
  }
}

// functions
bool key_down(KeyCode key)
{
  return keyboard.curr_keys[key];
}

bool key_up(KeyCode key)
{
  return !keyboard.curr_keys[key];
}

bool key_pressed(KeyCode key)
{
  return keyboard.curr_keys[key] && keyboard.prev_keys[key];
}

bool key_released(KeyCode key)
{
  return !keyboard.curr_keys[key] && keyboard.prev_keys[key];
}

// #############################################################################
//                           Mouse
// #############################################################################
// callbacks
void _mouse_cursor_pos_callback(GLFWwindow* window, double xPos, double yPos)
{

}

void _mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{

}

void _mouse_scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
{

}

// functions
float mouse_get_x()
{

}

float mouse_get_y()
{

}

bool mouse_button_down(MouseCode button)
{

}

bool mouse_button_up(MouseCode button)
{

}

bool mouse_button_pressed(MouseCode button)
{

}

bool mouse_button_released(MouseCode button)
{

}

float mouse_get_scroll_x()
{

}

float mouse_get_scroll_y()
{

}

// #############################################################################
//                           Common
// #############################################################################
void _input_end_frame()
{
  strcpy_s(keyboard.prev_keys, KEY_COUNT * sizeof(bool), keyboard.curr_keys);
}
