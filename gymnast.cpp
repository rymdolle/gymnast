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

#include <iostream>
#include <ctime>

// Definiera antalet deltagare och domare på ett ställe så man enkelt
// kan justera och testa större tävlingar.
#define TOTAL_PLAYERS 3
#define TOTAL_REFS    3

// Definiera domarpoängens omfång
#define SCORE_MIN 1
#define SCORE_MAX 100

int main() {
  // Ge slumptalsgeneratorn ett startvärde baserat på tiden i sekunder
  std::srand(std::time(nullptr));

  // Deklarera och och initiera deltagarnas poäng till noll
  int players[TOTAL_PLAYERS][TOTAL_REFS] = {};
  int total[TOTAL_PLAYERS] = {};
  size_t winner = 0;

  for (size_t player = 0; player < TOTAL_PLAYERS; player++) {
    for (size_t ref = 0; ref < TOTAL_REFS; ref++) {
      // Tilldela domarpoäng till deltagaren
      players[player][ref] = SCORE_MIN + std::rand() % (SCORE_MAX - SCORE_MIN + 1);

      // Räkna ut deltagarens totalpoäng
      total[player] += players[player][ref];
    }

    // Meddela deltagarens totalpoäng
    std::cout << "Deltagare " << player + 1 << " fick totalt " << total[player]
              << " poäng."
              << std::endl;

    // Utse deltagaren med högst totalpoäng
    if (total[player] > total[winner])
      winner = player;
  }

  std::cout << std::endl;

  for (size_t player = winner; player < TOTAL_PLAYERS; player++) {
    if (total[player] == total[winner]) {
      // Kora tävlingens vinnare
      std::cout << "Deltagare " << player + 1 << " vann tävlingen med " << total[player]
                << " poäng."
                << std::endl;
    }
  }
}
