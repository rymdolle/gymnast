/// Copyright 2023 Olle Mattsson
///
///  Licensed under the Apache License, Version 2.0 (the "License");
///  you may not use this file except in compliance with the License.
///  You may obtain a copy of the License at
///
///      http://www.apache.org/licenses/LICENSE-2.0
///
///  Unless required by applicable law or agreed to in writing, software
///  distributed under the License is distributed on an "AS IS" BASIS,
///  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
///  See the License for the specific language governing permissions and
///  limitations under the License.

#include <cstdlib>
#include <iostream>

#ifdef EXPERIMENTAL
#include <experimental/random>
// g++ -o gymnast -std=c++17 main.cpp -DEXPERIMENTAL
#else
#include <ctime>
// g++ -o gymnast -std=c++11 main.cpp
#endif

#define TOTAL_PLAYERS 3
#define TOTAL_REFS    3

int main(int argc, char* argv[]) {
  #ifndef EXPERIMENTAL
  std::srand(std::time(nullptr));
  #endif

  int players[TOTAL_PLAYERS][TOTAL_REFS] = {};
  int total[TOTAL_PLAYERS] = {};
  int winner = 0;

  std::cout << "PLAYER\t";
  for (size_t ref = 0; ref < TOTAL_REFS; ref++)
      std::cout << "REF" << ref << "\t";
  std::cout << "TOTAL" << std::endl;

  for (size_t player = 0; player < TOTAL_PLAYERS; player++) {
    std::cout << player << "\t";

    for (size_t ref = 0; ref < TOTAL_REFS; ref++) {
      #ifdef EXPERIMENTAL
      players[player][ref] = std::experimental::randint(1, 100);
      #else
      players[player][ref] = std::rand() % 100 + 1;
      #endif

      std::cout << players[player][ref] << "\t";
      total[player] += players[player][ref];
    }

    if (total[player] > total[winner])
      winner = player;

    std::cout << total[player] << std::endl;
  }

  std::cout << "WINNER\t" << winner << std::endl;

  return EXIT_SUCCESS;
}
