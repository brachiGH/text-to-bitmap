#include <sstream>

#include "text_renderer.h"
#include "bitmap_exceptions.hpp"

// Check if the line contains only valid chars before setting it
// if false if returned, this means the line is unvalid and not
// going to be set.
void line_t::setline(const std::string ln)
{
  for (auto c : ln)
  {
    if (m_font.find(c) == m_font.end())
    {
      throw unvalid_character(c, ln);
    }
  }

  m_line = ln;
};

void line_t::m_vector_to_bitmap(const uint16_t offset_x,
                                const uint16_t offset_y, std::shared_ptr<bitmap> bm,
                                const std::vector<bool> character) const
{
  for (size_t yi = 0; yi < FONT_CHAR_HEIGHT_IN_PIXELS; yi++)
  {
    for (size_t xi = 0; xi < FONT_CHAR_WIDTH_IN_PIXELS; xi++)
    {
      if (character[yi * FONT_CHAR_WIDTH_IN_PIXELS + xi])
      {
        uint16_t new_offset_x = offset_x + xi * m_font_size;
        uint16_t new_offset_y = offset_y + yi * m_font_size;
        bm->scaleUpPixel(m_color, new_offset_x, new_offset_y, m_font_size);
      }
    }
  }
}

// Inserts pxiels that forms the text in the line into the bitman
bool line_t::m_print(std::shared_ptr<bitmap> bm, const uint16_t offset_y) const
{
  uint16_t offset_x = m_offset_x;
  if (bm->is_out_of_bound(offset_x, offset_y))
  {
    return false;
  }

  for (auto c : m_line)
  {
    m_vector_to_bitmap(offset_x, offset_y, bm, m_font.at(c));
    offset_x += (FONT_CHAR_WIDTH_IN_PIXELS + m_character_spacing) * m_font_size;

    if (offset_x > bm->getWidth() - 1)
    {
      return false;
    }
  }

  return true;
}

bool line_t::print(std::shared_ptr<bitmap> bm) const
{
  return m_print(bm, m_offset_y);
}

// Get height of the line in pixels
uint16_t line_t::getHeight() const
{
  return FONT_CHAR_HEIGHT_IN_PIXELS * m_font_size;
}

// Get width of the line in pixels
uint16_t line_t::getWidth() const
{
  const int len = m_line.size();
  return (len * FONT_CHAR_WIDTH_IN_PIXELS + (len - 1) * m_character_spacing) *
         m_font_size;
}

// Returns the text in the Text Area
string text_area::text() const
{
  std::stringstream ss;

  for (auto ln : m_lines)
  {
    ss << ln->getline() << std::endl;
  }

  return ss.str();
}

// Set a text inside Text Area
void text_area::text(const string text)
{
  std::stringstream ss{text};
  string line;
  uint32_t offset_x = this->offsetX();
  uint32_t offset_y = this->offsetY();

  while (std::getline(ss, line))
  {
    line_t *ln = new line_t(offset_x, offset_y);
    ln->setline(line);

    m_lines.push_back(ln);
    offset_y += (FONT_CHAR_HEIGHT_IN_PIXELS + m_line_spacing) * fontSize();
  }
}

void text_area::linespacing(uint8_t ls)
{
  m_line_spacing = ls;

  // Update offsets of lines inside '_lines' vector
  std::string temp = text();
  text(temp);
}

void text_area::fontSize(uint8_t fs)
{
  line_t::fontSize(fs);

  // Update offsets of lines inside '_lines' vector
  std::string temp = text();
  text(temp);
};

// Get height of the text area in pixels
uint16_t text_area::getHeight() const
{
  return (m_lines.size() * FONT_CHAR_HEIGHT_IN_PIXELS +
          m_lines.size() * m_line_spacing * 2) *
         fontSize();
}

// Get width of the text area in pixels
uint16_t text_area::getWidth() const
{
  uint32_t max_chars = 0;
  for (auto ln : m_lines)
  {
    uint32_t len = ln->getline().length();
    if (len > max_chars)
    {
      max_chars = len;
    }
  }
  return (max_chars * FONT_CHAR_WIDTH_IN_PIXELS +
          (max_chars - 1) * this->characterSpacing()) *
         fontSize();
}

bool text_area::print(std::shared_ptr<bitmap> bm) const
{
  bool status = true;
  for (auto line : m_lines)
  {
    status &= line->print(bm);
  }
  return status;
}

text_area::~text_area()
{
  for (auto ln : m_lines)
  {
    delete ln;
  }
}

// Copy Constructor
text_area::text_area(const text_area &other)
{
  for (auto ln : other.m_lines)
  {
    m_lines.push_back(new line_t(*ln));
  }
}

// Assignment Operator
text_area &text_area::operator=(const text_area &other)
{
  if (this != &other)
  {
    for (auto ln : m_lines)
    {
      delete ln;
    }
    m_lines.clear();
    for (auto ln : other.m_lines)
    {
      m_lines.push_back(new line_t(*ln));
    }
  }
  return *this;
}