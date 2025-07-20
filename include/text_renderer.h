#ifndef TEXT_RENDERER_H_
#define TEXT_RENDERER_H_

#include "../font/basic/basic_font.h"
#include "bitmap.h"
#include "font.h"
#include <cstdint>
#include <string>
#include <vector>
#include <memory>

using std::string;
using color_t = pixel;

class line_t
{
private:
  // In pixels form the top left corner
  uint16_t m_offset_x;
  uint16_t m_offset_y;

  // the font is based of the height and width in the font file
  font_t m_font = font::basic::kFontMap;
  uint8_t m_font_size = 5;
  uint8_t m_character_spacing = 2;

  // the default color is black
  color_t m_color = {.blue = 0, .green = 0, .red = 0};
  string m_line;

  void m_vector_to_bitmap(const uint16_t x, const uint16_t y, std::shared_ptr<bitmap> bm,
                          const std::vector<bool> character) const;

  /*
   * @brief Inserts pxiels that forms the text in the line into the bitman
   */
  bool m_print(std::shared_ptr<bitmap> bm, const uint16_t offset_y) const;

public:
  /*
   * @brief New line with offset set to absolute postion
   */
  line_t() : m_offset_x(0), m_offset_y(0) {};
  line_t(int x, int y) : m_offset_x(x), m_offset_y(y) {};

  uint16_t offsetX() const { return m_offset_x; };
  void offsetX(const uint16_t x) { m_offset_x = x; };

  uint16_t offsetY() const { return m_offset_y; };
  void offsetY(const uint16_t y) { m_offset_y = y; };

  uint8_t fontSize() const { return m_font_size; };
  void fontSize(const uint8_t fs) { m_font_size = fs; };

  const color_t &color() const { return m_color; };
  void color(const color_t &c) { m_color = c; };
  void color(const uint8_t b, const uint8_t g, const uint8_t r)
  {
    m_color = {.blue = b, .green = g, .red = r};
  }

  const string getline() const { return m_line; };
  void setline(const string ln, const font_t &ft)
  {
    m_font = ft;
    setline(ln);
  };
  void setline(const string ln);

  void setfont(const font_t &ft) { m_font = ft; };
  const font_t &font() const { return m_font; };

  /*
   * @brief Set character spacing in pixels
   */
  uint8_t characterSpacing() const { return m_character_spacing; };
  void characterSpacing(const uint8_t cs) { m_character_spacing = cs; };

  virtual uint16_t getHeight() const;
  virtual uint16_t getWidth() const;

  virtual bool print(std::shared_ptr<bitmap> bm) const;

  virtual ~line_t() {}
};

class text_area : public line_t
{
private:
  std::vector<line_t *> m_lines;
  uint8_t m_line_spacing = 2; // in pixels
public:
  text_area(const int x, const int y) : line_t(x, y) {};

  const string &getline() = delete;
  void setline(const string ln) = delete;
  void setline(const string ln, const font_t &ft) = delete;

  /*
   * @brief Get Text inside the text area
   */
  string text() const;
  /*
   * @brief set the text inside the text area
   */
  void text(const string t, const font_t &ft)
  {
    setfont(ft);
    text(t);
  };
  void text(const string t);

  /*
   * @brief Set line spacing in pixels
   */
  uint8_t linespacing() const { return m_line_spacing; };
  void linespacing(const uint8_t ls);

  using line_t::fontSize; // uint8_t fontSize() const { return line_t::fontSize(); };
  void fontSize(const uint8_t fs);

  uint16_t getHeight() const override;
  uint16_t getWidth() const override;

  ~text_area();

  text_area(const text_area &other);
  text_area &operator=(const text_area &other);

  bool print(std::shared_ptr<bitmap> bm) const override;
};

#endif