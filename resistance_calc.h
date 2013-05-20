#ifndef RESISTANCE_CALC_H
#define RESISTANCE_CALC_H

#include <vector>
#include <stdint.h>

struct band {
    const char *name;
    uint8_t band;
    uint8_t multiplier;
    uint8_t tolerance;
};

class ResistanceCalc {
    private:
        void populate_vector();

    public:
        std::vector<band> values;

        ResistanceCalc();
};

#endif // RESISTANCE_CALC_H
