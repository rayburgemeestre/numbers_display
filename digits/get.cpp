/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#define guint int
#define guint8 unsigned char
#ifdef DIGIT
  #include DIGIT // change this to the number you are processing
#else
  static_assert(false, "Please compile this using -DDIGIT=X.c where X stands for the digit source file.");
#endif
#include <iostream>
#include <vector>

int main()
{
  unsigned char *r;
  unsigned char *g;
  unsigned char *b;
  unsigned char *a;
  unsigned char *pix;
  pix = (unsigned char *)gimp_image.pixel_data;
  std::vector<std::pair<bool, int>> map;
  bool current = false, previous = false;
  int num = 0;
  for (int y=0; y<127; y++) {
    for (int x=0; x<64; x++) {
      r = pix++;
      g = pix++;
      b = pix++;
      a = pix++;
      //std::cout << (((int)(*r)) == 255 ? " " : "X");
      //
      bool on = ((int)(*r)) == 255;
      if (num == 0) {
        current = on;
        num++;
      }
      else if (previous == on) {
        num++;
      }
      else {
        while (true) {
          std::cout << " emplacing: " << previous << " " << num << std::endl;
          if (num > 255) {
            map.emplace_back(previous, 255);
            num -= 255;
            map.emplace_back(!previous, 0);
          }
          else {
            map.emplace_back(previous, num);
            current = on;
            num = 1;
            break;
          }
        }
      }
      previous = on;
    }
    // std::cout << std::endl;
  }
  while (true) {
    std::cout << "!!" << std::endl;
    if (num > 255) {
      map.emplace_back(previous, 255);
      num -= 255;
      map.emplace_back(!previous, 0);
    }
    else {
      map.emplace_back(previous, num);
      break;
    }
  }
  //map.emplace_back(previous, num);

  {
    size_t i = 0;
    bool on = map[i].first;
    int num = map[i].second;
    for (int y=0; y<127; y++) {
      for (int x=0; x<64; x++) {
        if (!on) {
          std::cout << "_";
        } else {
          std::cout << " ";
        }
        num--;
        if (num == 0) {
          i++;
          on = map[i].first;
          num = map[i].second;
        }
      }
      std::cout << std::endl;
    }
  }

  std::cout << "bool values [] = {";
  bool first = true;
  for (const auto m : map) {
    if (!first) std::cout << ", ";
    std::cout << m.first;
    first = false;
  }

  std::cout << "};" << std::endl;

  std::cout << "unsigned char DIGIT [] = {";
  first = true;
  for (const auto m : map) {
    if (!first) std::cout << ", ";
    std::cout << m.second;
    first = false;
  }
  std::cout << "};" << std::endl;
  std::cout << map.size() << std::endl;
}
