#include "bitmap.h"
#include <cstddef>
#include <fstream>
#include <ostream>

bool bitmap::is_out_of_bound(const uint16_t x, const uint16_t y) const
{
  if (x > (m_width - 1) || y > (m_height - 1))
  {
    return true;
  }

  return false;
}

uint8_t bitmap::m_calculate_row_padding()
{
  uint8_t temp = m_width * sizeof(pixel) % 4;
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

  m_pixels[y * m_width + x] = p;

  return true;
};

const pixel &bitmap::getPixel(uint16_t x, uint16_t y)
{
  return m_pixels[y * m_width + x];
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

bool bitmap::writeAsASCIIfileToDisk(const char whitespace, const char ASCIIcharacter)
{
  std::ofstream file(m_filename + ".txt");
  if (!file)
  {
    return false;
  }

  for (size_t i = 0; i < m_height; i++)
  {
    for (size_t j = 0; j < m_width; j++)
    {
      file << (m_pixels[i * m_width + j].blue == 0 ? ASCIIcharacter : whitespace);
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

  bih.width = m_width;
  bih.height = m_height;

  bfh.data_offset = sizeof(bitmap_file_header) + sizeof(bitmap_info_header);
  bih.data_size = m_width * m_height * sizeof(pixel);
  bfh.file_size = bfh.data_offset + bih.data_size;

  std::ofstream file(m_filename + ".bmp", std::ios::binary);
  if (!file)
  {
    return false;
  }

  file.write(reinterpret_cast<char *>(&bfh), sizeof(bfh));
  file.write(reinterpret_cast<char *>(&bih), sizeof(bih));

  uint8_t padding = m_calculate_row_padding();
  for (ssize_t y = m_height - 1; y >= 0; y--)
  {
    for (size_t x = 0; x < m_width; x++)
    {
      file.write(reinterpret_cast<char *>(&m_pixels[y * m_width + x]), sizeof(pixel));
    }

    for (uint8_t i = 0; i < padding; i++)
    {
      file.write("\0", 1);
    }
  }

  file.write(reinterpret_cast<char *>(m_pixels.data()), bih.data_size);

  file.close();

  return true;
};
