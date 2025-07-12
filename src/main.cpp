#include "basic/basic_font.h"
#include "text_renderer.h"

int main() {
  bitmap bm{"test", 280, 200};
  text_area txt{10, 10};
  std::string temp = "&test123456789\nABC";
  txt.text(temp, font::basic::kFontMap);

  txt.print(&bm);
  bm.writeAsASCIItoDisk();
  bm.writeToDisk();
}