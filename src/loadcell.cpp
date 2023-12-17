#include "../include/loadcell.h"

loadcell::loadcell() {}

loadcell::~loadcell() {}

void loadcell::init() {
   scale.begin(DT_PIN, SCK_PIN);
   scale.set_scale(-2181.641);
   delay(1000);
   scale.tare();
   delay(1000);
}

long loadcell::getWeight() {
   if (scale.is_ready()) {
      currentResult = scale.get_units(10);
      return currentResult;
   }
}
