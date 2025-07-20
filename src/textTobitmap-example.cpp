#include "basic/basic_font.h"
#include "text_renderer.h"
#include <memory>

int main()
{
  std::shared_ptr<bitmap> bm = std::make_shared<bitmap>("test", 400, 900);
  text_area txt{10, 10};
  std::string temp = "A B C D E F \nG H I J K L \nM N O P Q R \nS T U V W X \nY Z a b c d \ne f g h i j \nk l m n o p \nq r s t u v \nw x y z 0 1 \n2 3 4 5 6 7 \n8 9   ! @ # \n$ % ^ & * ( \n) - _ = + [ \n] { } \\";
  txt.text(temp, font::basic::kFontMap);

  txt.print(bm);
  bm->writeAsASCIIfileToDisk();
  bm->writeToDisk();
}