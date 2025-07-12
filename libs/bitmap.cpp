#include "bitmap.h"
#include <cstddef>
#include <fstream>
#include <ostream>

bool bitmap::setPixel(const pixel p, const uint16_t y, const uint16_t x) {
  // create a throw exception for out of range

  _pixels[y * _width + x] = p;

  return true;
};

pixel bitmap::getPixel(uint16_t x, uint16_t y) {
  return _pixels[y * _width + x];
};

bool bitmap::scaleUpPixel(const pixel p, uint16_t x, uint16_t y, int8_t scale) {
  for (size_t vy = 0; vy < scale; vy++) {
    for (size_t vx = 0; vx < scale; vx++) {
      setPixel(p, y + vy, x + vx);
    }
  }

  return true;
};

bool bitmap::writeToDisk() {
//   for (size_t i = 0; i < _height; i++) {
//     for (size_t j = 0; j < _width; j++) {
//       std::cout << (_pixels[i * _height + j].blue == 0 ? '#' : ' ');
//     }
//     std::cout << std::endl;
//   }
  std::ofstream file(_filename);
  if (!file) {
    return false;
  }

  for (size_t i = 0; i < _height; i++) {
    for (size_t j = 0; j < _width; j++) {
      file << (_pixels[i * _width + j].blue == 0 ? '#' : ' ');
    }
    file << std::endl;
  }

  file.close();

  return true;
};
