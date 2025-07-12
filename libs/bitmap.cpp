#include "bitmap.h"
#include <cstddef>
#include <fstream>
#include <ostream>

bool bitmap::is_out_of_bound(const uint16_t x, const uint16_t y) const
{
  if (x > (_width - 1) || y > (_height - 1))
  {
    return true;
  }

  return false;
}

uint8_t bitmap::_calculate_row_padding()
{
  uint8_t temp = _width * sizeof(pixel) % 4;
  if (temp == 0)
  {
    return 0;
  }
  return 4 - temp;
}

bool bitmap::setPixel(const pixel p, const uint16_t x, const uint16_t y)
{
  if (is_out_of_bound(x, y))
  {
    return false;
  }

  _pixels[y * _width + x] = p;

  return true;
};

const pixel &bitmap::getPixel(uint16_t x, uint16_t y)
{
  return _pixels[y * _width + x];
};

bool bitmap::scaleUpPixel(const pixel p, uint16_t x, uint16_t y, int8_t scale)
{
  bool status = true;

  for (size_t vy = 0; vy < scale; vy++)
  {
    for (size_t vx = 0; vx < scale; vx++)
    {
      status &= setPixel(p, x + vx, y + vy);
    }
  }

  return status;
};

bool bitmap::writeAsASCIItoDisk(const char space, const char character)
{
  std::ofstream file(_filename + ".txt");
  if (!file)
  {
    return false;
  }

  for (size_t i = 0; i < _height; i++)
  {
    for (size_t j = 0; j < _width; j++)
    {
      file << (_pixels[i * _width + j].blue == 0 ? character : space);
    }
    file << std::endl;
  }

  file.close();

  return true;
};

bool bitmap::writeToDisk()
{
  bitmap_file_header bfh;
  bitmap_info_header bih;

  bih.width = _width;
  bih.height = _height;

  bfh.data_offset = sizeof(bitmap_file_header) + sizeof(bitmap_info_header);
  bih.data_size = _width * _height * sizeof(pixel);
  bfh.file_size = bfh.data_offset + bih.data_size;

  std::ofstream file(_filename + ".bmp", std::ios::binary);
  if (!file)
  {
    return false;
  }

  file.write(reinterpret_cast<char *>(&bfh), sizeof(bfh));
  file.write(reinterpret_cast<char *>(&bih), sizeof(bih));

  uint8_t padding = _calculate_row_padding();
  for (ssize_t y = _height - 1; y >= 0; y--)
  {
    for (size_t x = 0; x < _width; x++)
    {
      file.write(reinterpret_cast<char *>(&_pixels[y * _width + x]), sizeof(pixel));
    }

    for (uint8_t i = 0; i < padding; i++)
    {
      file.write("\0", 1);
    }
  }

  file.write(reinterpret_cast<char *>(_pixels.data()), bih.data_size);

  file.close();

  return true;
};
