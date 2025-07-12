#ifndef TEXT_RENDERER_H_
#define TEXT_RENDERER_H_

#include "../font/basic/basic_font.h"
#include "bitmap.h"
#include "font.h"
#include <cstdint>
#include <string>
#include <vector>

using std::string;
using color_t = pixel;

class line_t {
private:
  // In pixels form the top left corner
  uint16_t _offset_x;
  uint16_t _offset_y;

  // the font is based of the height and width in the font file
  uint8_t _font_size = 5;
  uint8_t _character_spacing = 2;

  // the default color is black
  color_t _color = {.blue = 0, .green = 0, .red = 0};
  string _line;
  font_t _font = font::basic::kFontMap;

  void _vector_to_bitmap(uint16_t x, uint16_t y, bitmap *bm,
                         const std::vector<bool> &character) const;

  // Inserts pxiels that forms the text in the line into the bitman
  void _print(bitmap *bm, uint16_t offset_y) const;

public:
  // New line with offset set to absolute postion
  line_t() : _offset_x(0), _offset_y(0) {};
  line_t(int x, int y) : _offset_x(x), _offset_y(y) {};

  uint16_t offsetX() const { return _offset_x; };
  uint16_t offsetY() const { return _offset_y; };
  void offsetX(uint16_t x) { _offset_x = x; };
  void offsetY(uint16_t y) { _offset_y = y; };

  uint8_t fontSize() const { return _font_size; };
  void fontSize(uint8_t fs) { _font_size = fs; };

  color_t color() const { return _color; };
  void color(color_t c) { _color = c; };
  void color(uint8_t b, uint8_t g, uint8_t r) {
    _color = {.blue = b, .green = g, .red = r};
  }

  string getline() const { return _line; };
  bool setline(string &ln, const font_t &ft) {
    _font = ft;
    return setline(ln);
  };
  bool setline(string &ln);

  void setfont(const font_t &ft) { _font = ft; };
  font_t font() const { return _font; };

  uint8_t characterSpacing() const { return _character_spacing; };
  void characterSpacing(uint8_t cs) { _character_spacing = cs; };

  virtual uint16_t getHeight() const;
  virtual uint16_t getWidth() const;

  virtual void print(bitmap *bm) const;

  virtual ~line_t() {}
};

class text_area : public line_t {
private:
  std::vector<line_t *> _lines;
  uint8_t _line_spacing = 2; // in pixels
public:
  text_area(int x, int y) : line_t(x, y) {};

  string getline() = delete;
  bool setline(string ln) = delete;

  string text() const; // get Text inside the text area
  // set the text inside the text area
  bool text(string &t, const font_t &ft) {
    setfont(ft);
    return text(t);
  };
  bool text(string &t);

  uint8_t linespacing() const { return _line_spacing; };
  void linespacing(uint8_t ls);

  // uint8_t fontSize() const { return line_t::fontSize(); };
  using line_t::fontSize;
  void fontSize(uint8_t fs);

  uint16_t getHeight() const override;
  uint16_t getWidth() const override;

  ~text_area();

  text_area(const text_area &other);
  text_area &operator=(const text_area &other);

  void print(bitmap *bm) const override;
};

#endif