#ifndef BITMAP_H_
#define BITMAP_H_

#include <cstdint>
#include <string>
#include <utility>
#include <vector>

#pragma pack(push, 2) // The elements must start on 16-bit intervals

struct bitmap_file_header {
  char signature[2]{'B', 'M'};
  int32_t file_size;
  int32_t reserved{0};
  int32_t data_offset;
};

#pragma pack(pop) // Revert to default alignment

struct bitmap_info_header {
  int32_t header_size{40};
  int32_t width;
  int32_t height;
  int16_t planes{1};
  int16_t bits_per_pixel{24};
  int32_t compression{0};
  int32_t data_size{0};
  int32_t horizontal_resolution{2400};
  int32_t vertical_resolution{2400};
  int32_t colours{0};
  int32_t important_colours{0};
};

struct pixel {
  uint8_t blue;
  uint8_t green;
  uint8_t red;
};

class bitmap {
  uint16_t _height;
  uint16_t _width;
  std::string _filename;

  // default bg color set to white
  pixel _bg_color = {.blue = 255, .green = 255, .red = 255};
  std::vector<pixel> _pixels;

public:
  bitmap(std::string filename, uint16_t h, uint16_t w)
      : _filename(filename), _height(h), _width(w), _pixels(h * w, _bg_color) {}

  bool setPixel(const pixel p, uint16_t y, uint16_t x);
  pixel getPixel(uint16_t x, uint16_t y);
  bool scaleUpPixel(const pixel p, uint16_t y, uint16_t x, int8_t scale);
  bool writeToDisk();
};

#endif