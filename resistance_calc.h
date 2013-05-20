#ifndef RESISTANCE_CALC_H
#define RESISTANCE_CALC_H

#include <iostream>
#include <vector>
#include <string>
#include <stdint.h>
#include <cstring>
#include <cstdio>

#include <QString>

// Resistor band.
struct band {
    const char *name;
    int band;
    int multiplier;
    double tolerance;
};

class ResistanceCalc {
    private:
        void populate_vector();

    public:
        std::vector<band> values;

        ResistanceCalc();

        int calculate(std::vector<const char*> bands);
        QString pretty_print(int value, const char *color, bool use_symbol = true);

        band get_band(const char *name);
};

#endif // RESISTANCE_CALC_H
