#include "display.h"
#include <glad/glad.h>
#include "input.h"

#include <stdio.h>
#include <stdlib.h>

// #############################################################################
//                           Structs
// #############################################################################
typedef struct Display
{
  int width, height;
  const char* title;
  GLFWwindow* window;

  bool is_resizable;
} Display;

// #############################################################################
//                           Callbacks
// #############################################################################
void error_callback(int err_code, const char* msg)
{
  printf("GLFW ERROR[%i]: %s\n", err_code, msg);
}

// #############################################################################
//                           Functions
// #############################################################################
#define INIT_DEFER(...)       \
{                             \
  PRINTLN(__VA_ARGS__);       \
  display_free(self);         \
  return NULL;                \
}
Display* display_init(int width, int height, const char* title, bool is_resizable)
{
  // Init Display
  Display* self = malloc(sizeof(Display));
  if (!self)
  {
    PRINTLN("Failed to Allocate Memory for Display");
    return NULL;
  }
  
  self->width = width;
  self->height = height;
  self->title = title;
  self->is_resizable = is_resizable;

  // Init glfw error callback
  glfwSetErrorCallback(error_callback);

  // Init glfw
  if (!glfwInit())
  {
    INIT_DEFER("Failed to Init GLFW");
  }

  // glfw window hints
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, self->is_resizable ? GLFW_TRUE : GLFW_FALSE);
  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

  // create window
  self->window = glfwCreateWindow(self->width, self->height, self->title, NULL, NULL);
  if (!self->window)
  {
    INIT_DEFER("Failed to Create Window");
  }
  glfwMakeContextCurrent(self->window);

  // set glfw callbacks
  glfwSetKeyCallback(self->window, _key_callback);
  glfwSetCursorPosCallback(self->window, _mouse_cursor_pos_callback);
  glfwSetMouseButtonCallback(self->window, _mouse_button_callback);
  glfwSetScrollCallback(self->window, _mouse_scroll_callback);

  // init glad
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    INIT_DEFER("Failed to init glad");
  }

  // set v-sync
  glfwSwapInterval(1);

  // show window
  glfwShowWindow(self->window);

  return self;
}

void display_free(Display* self)
{
  // Destroy window
  glfwDestroyWindow(self->window);

  // set glfw Error Callback to null
  glfwSetErrorCallback(NULL);

  // terminate glfw
  glfwTerminate();
  
  // free display
  free(self);
}

void display_update(Display *self)
{
  glfwPollEvents();
}

void display_swap_buffers(Display *self)
{
  // Swap Buffers
  glfwSwapBuffers(self->window);

  // Input end frame
  _input_end_frame();
}

void display_close(Display* self, bool close)
{
  glfwSetWindowShouldClose(self->window, close ? GLFW_TRUE : GLFW_FALSE);
}

int display_get_width(const Display* self)
{
  return self->width;
}

int display_get_height(const Display* self)
{
  return self->height;
}

bool display_get_is_resizable(const Display *self)
{
  return self->is_resizable;
}

bool display_should_close(const Display *self)
{
  return glfwWindowShouldClose(self->window);
}
