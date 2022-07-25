#ifndef SDL_WRAP_H
#define SDL_WRAP_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>
struct Colour {
  char r, g, b;
  operator SDL_Color() {
    return SDL_Color{r, g, b};
  }
};

struct Rect {
  SDL_Rect rect;
  Colour c;
};

struct Text {
  int x, y, w, h;
  SDL_Texture* texture;
  Text(int x, int y, int w, int h, SDL_Texture *t) : x{x}, y{y}, w{w}, h{h}, texture{t} {}
  Text(const Text &other) = delete;
  Text(Text &&o) noexcept : x{o.x}, y{o.y}, w{o.w}, h{o.h}, texture{o.texture} {
    o.texture = nullptr;
  }
  virtual ~Text() = 0;
};

struct OwningText : public Text {
  OwningText(int x, int y, int w, int h, SDL_Texture *t) : Text{x, y, w, h, t} {}
  OwningText(OwningText &&o) noexcept : Text{std::move(o)} {}
  ~OwningText() { SDL_DestroyTexture(texture); }
};

struct NonOwningText : public Text {
  NonOwningText(int x, int y, int w, int h, SDL_Texture *t) : Text{x, y, w, h, t} {}
  NonOwningText(NonOwningText &&o) noexcept : Text{std::move(o)} {}
  ~NonOwningText() { }
};

struct ImgDraw {
  std::string key;
  SDL_Rect r;
};


// This class just handles the start and end of SDL, just need to declare one at the start of your program,
// either globally or at the begining of main, and then do nothing with it.
class SDL_Runner {
  static int x;
 public:
  SDL_Runner();
  ~SDL_Runner();
};


// Class that represents your screen, currently can be used to draw rectangles.
class Screen {
  SDL_Window *window;
  SDL_Renderer *render;
  int w, h;
  std::string screenName;
  std::vector<Rect> rects;
  std::vector<Text*> msgs;
  std::unordered_map<std::string, TTF_Font *> fonts;
  std::unordered_map<std::string, SDL_Texture *> imgs;
 public:
  Screen(int w=640, int h=480, std::string screenName="");
  Screen(const Screen &) = delete;
  Screen(Screen && o) : window{o.window}, render{o.render}, w{o.w}, h{o.h}, screenName{std::move(o.screenName)}, rects{std::move(o.rects)},
    msgs{std::move(o.msgs)}, fonts{std::move(o.fonts)}, imgs{std::move(o.imgs)} { 
    o.window = nullptr; 
    o.render = nullptr;
  }
  Screen &operator=(const Screen &) = delete;
  Screen &operator=(Screen &&o) = delete;
  ~Screen();
  // Draw a coloured filled in rectangle.
  void draw_rect(int x, int y, int w, int h, Colour c);
  // Draw a string, requires a font to be loaded. By default font "FUTURAM28" is already loaded.
  // You can add additional ones by downloading True Type Font files and loading them with the
  // add_font function.
  void draw_string(std::string msg, int x, int y, Colour c, std::string fontKey="FUTURAM28");
  // Draws an image, requires that image already be loaded and associated with key. 
  void draw_img(std::string key, int x, int y);
  // Loads an image from the file designated at path, and associates it with key.
  void add_img(std::string key, std::string path);
  // Loads a font from the TTF file at path, and associates it with key, also sets
  // its point to point. The default loaded FUTURAM is point 28,
  void add_font(std::string key, std::string path, unsigned int point);
  // Updates the screen, displaying everything you've drawn since the last update.
  void update();
  int getWidth() { return w; }
  int getHeight() { return h; }
};


// For timing framerate - we can't have our
// loop for a GUI with input running at the
// max speed it can, it's too fast.
class Clock {
  int initTick = 0;
  bool started = false;
 public:
  Clock() {}
  void start();
  int getTicks();
};

#endif
