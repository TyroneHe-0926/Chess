#include "sdl_wrap.h"
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int SDL_Runner::x = 0;

Text::~Text() {}

Screen::Screen(int w, int h, std::string screenName) : 
        window{SDL_CreateWindow(screenName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN)}, 
        render{SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)},
        w{w}, h{h}, screenName{screenName},  rects{} {
  fonts["FUTURAM28"] = TTF_OpenFont("16020_FUTURAM.ttf", 28);
  if (render == NULL) {
    cerr << "Couldn't load renderer " << SDL_GetError() << endl;
  }
}

Screen::~Screen() {
  for (auto &p: fonts) {
    TTF_CloseFont(p.second);
  }
  for (auto &t : msgs) {
    SDL_DestroyTexture(t->texture);
  }
  for (auto &i : imgs) {
    SDL_DestroyTexture(i.second);
  }
  SDL_DestroyRenderer(render);
  SDL_DestroyWindow(window);
}

void Screen::draw_rect(int xloc, int yloc, int w, int h, Colour c) {
  // No longer capped at 10 rects, we have a vector now.
  rects.emplace_back(Rect{SDL_Rect{xloc, yloc, w, h}, c});
}

void Screen::add_font(string key, string path, unsigned int point) {
  fonts[key] = TTF_OpenFont(path.c_str(), point);
  if(fonts[key] == NULL)
	{
		cerr << "Failed to load font: " << path << endl;
	}
}


void Screen::draw_string(string msg, int x, int y, Colour c, string fontKey) {
  SDL_Surface *textSurface = TTF_RenderText_Solid(fonts[fontKey], msg.c_str(), c);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(render, textSurface);
  if (texture == NULL) {
    cerr << "Error loading string texture: " << SDL_GetError() << endl;
  }
  msgs.emplace_back(new OwningText{x, y, textSurface->w, textSurface->h, texture});
  SDL_FreeSurface(textSurface);
}

void Screen::add_img(string key, string path) {
  SDL_Surface *imgSurface = IMG_Load(path.c_str());
  if (imgSurface == NULL) {
    cerr << "Error loading image at path: " << path << " - " << IMG_GetError() << endl;
    return;
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(render, imgSurface);
  if (texture == NULL) {
    cerr << "Unable to create texture from image with path " << path << " - " << SDL_GetError();
    return;
  }
  SDL_FreeSurface(imgSurface);
  if (imgs.find(key) != imgs.end()) SDL_DestroyTexture(imgs[key]);
  imgs[key] = texture;
}

void Screen::draw_img(std::string key, int x, int y) {
  int w, h;
  SDL_QueryTexture(imgs[key], NULL, NULL, &w, &h);
  msgs.emplace_back(new NonOwningText{x, y, w, h, imgs[key]});
}

void Screen::update() {
  SDL_RenderClear(render);
  for (auto &r : rects) {
    SDL_SetRenderDrawColor(render, r.c.r, r.c.g, r.c.b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(render, &r.rect);
  }
  for (auto &m: msgs) {
    SDL_Rect r{m->x, m->y, m->w, m->h};
    SDL_RenderCopy(render, m->texture, nullptr, &r);
  }
  SDL_RenderPresent(render);

  for (auto &m: msgs) {
    delete m;
  }
  msgs.clear();
  rects.clear();

  // All rects are erased each update.
}


void Clock::start() {
  started = true;
  initTick = SDL_GetTicks();
}

int Clock::getTicks() {
  if (started) {
    return SDL_GetTicks() - initTick;
  }
  return 0;
}



SDL_Runner::SDL_Runner() {
  if (!x) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
      cerr << "Error initializing SDL!" << endl;
    }
    if (TTF_Init() == -1) {
      cerr << "Error initializing SDL Fonts" << endl;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG )) {
      cerr << "Error initializing SDL image" << endl;
    }
    ++x;
  }
}
SDL_Runner::~SDL_Runner() { 
  TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}
