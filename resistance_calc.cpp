#include "resistance_calc.h"

ResistanceCalc::ResistanceCalc() {
    populate_vector();
}

void ResistanceCalc::populate_vector() {
    band _band;

    _band.name = "black";
    _band.band = 0;
    _band.multiplier = 1;
    _band.tolerance = NULL;
    values.push_back(_band);

    _band.name = "brown";
    _band.band = 1;
    _band.multiplier = 10;
    _band.tolerance = 1;
    values.push_back(_band);
}
