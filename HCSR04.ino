/* Copyright 2020 Gurol Gezer 2020.

  This file is part of HCSR04 library.

    HCSR04 is a free library: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    HCSR04 library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <https://www.gnu.org/licenses/>.*/

#include "HCSR04.h"

/* Example Code for HCSR04 class. Supports multiple sensors which might or might not share same pins.
  User can make a list of available sensors with defined trigger and echo pins. For each loop iteration
  the sensors measure and record distance to detect objects in the user defined order.
  User can print the distance (or the distance vector) to the Serial Monitor using plotSerial()
  /* sonar_list: array consisting of all available sensors indexed based on the order of activation
   Add or remove sensors if necessary. For each sensor specificy trigger and echo pins. */
HCSR04 sonar_list[] = {HCSR04(6, 0), HCSR04(6, 0), HCSR04(6, 0), HCSR04(6, 0), HCSR04(6, 0)};
/* N: number of sensors defined in sonar_list[]
   timeout: waiting time between previous sensor's echo reading and triggering of the next sensor in [ms] */
const byte N = sizeof(sonar_list) / sizeof(sonar_list[0]), timeout = 2;
/* distance: array consisting of the most recent distance measurements in [cm] */
word distance[N];
/* start_serial: set true to enable Serial communication, false to disable it */
const bool start_serial = true;

void setup() {
  if (start_serial)Serial.begin(9600);  //specify baud rate based on the board
}

/* At each iteration measure distances for each sensor, then if enabled print them using Serial communication */
void loop() {
  for (byte i = 0; i < N; i++) {
    distance[i] = sonar_list[i].readDistance();
    delay(timeout);
  }
  if (start_serial) plotSerial();
}

/* Prints the distance or the distance array in [cm] on the Serial Monitor */
void plotSerial() {
  for (byte i = 0; i < N; i++) {
    Serial.print(distance[i]);
    if (i < (N - 1)) Serial.print(" ");
    else Serial.print("\n");
  }
}
