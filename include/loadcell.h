#ifndef LOADCELL_H
#define LOADCELL_H

#include <HX711.h>
#include <stdint.h>
#include <stdbool.h>
#include "config.h"

class loadcell
{
private:
    HX711 scale;
    long currentResult;
public:
    loadcell(/* args */);
    ~loadcell();
    void init();
    long getWeight();
};

#endif //LOADCELL_H