#include "resistance_calc.h"

using namespace std;

ResistanceCalc::ResistanceCalc() {
    populate_vector();
}

/**
 * Populates a vector with all the bands values.
 */
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

    _band.name = "red";
    _band.band = 2;
    _band.multiplier = 100;
    _band.tolerance = 2;
    values.push_back(_band);

    _band.name = "orange";
    _band.band = 3;
    _band.multiplier = 1000;
    _band.tolerance = NULL;
    values.push_back(_band);

    _band.name = "yellow";
    _band.band = 4;
    _band.multiplier = 10000;
    _band.tolerance = NULL;
    values.push_back(_band);

    _band.name = "green";
    _band.band = 5;
    _band.multiplier = 100000;
    _band.tolerance = 0.5;
    values.push_back(_band);

    _band.name = "blue";
    _band.band = 6;
    _band.multiplier = 1000000;
    _band.tolerance = 0.25;
    values.push_back(_band);

    _band.name = "violet";
    _band.band = 7;
    _band.multiplier = 10000000;
    _band.tolerance = 0.1;
    values.push_back(_band);

    _band.name = "gray";
    _band.band = 8;
    _band.multiplier = NULL;
    _band.tolerance = 0.05;
    values.push_back(_band);

    _band.name = "white";
    _band.band = 9;
    _band.multiplier = NULL;
    _band.tolerance = NULL;
    values.push_back(_band);

    _band.name = "gold";
    _band.band = NULL;
    _band.multiplier = 0.1;
    _band.tolerance = 5;
    values.push_back(_band);

    _band.name = "silver";
    _band.band = NULL;
    _band.multiplier = 0.01;
    _band.tolerance = 10;
    values.push_back(_band);
}

/**
 * Calculate the resistance based on a vector of strings with the band colors.
 *
 * @param bands Band name colors.
 * @return Resistance.
 */
int ResistanceCalc::calculate(vector<QString> bands) {
    QString res;
    int result = 0;

    for (size_t i = 0; i < bands.size() - 1; ++i) {
        band _band = get_band(bands[i].toStdString().c_str());

        // Check if it's the last band (multiplier).
        if (i == bands.size() - 2) {
            // Convert to number and apply the multiplier.
            result = res.toInt();
            result *= _band.multiplier;
        } else {
            // Append the value to the string.
            res += QString::number(_band.band);
        }
    }

    return result;
}

/**
 * Pretty-print a resistance value.
 *
 * @param value Resistance value.
 * @param color Band color.
 * @param use_symbol Use the ohms symbol?
 * @return Pretty-printed value.
 */
QString ResistanceCalc::pretty_print(int value, const char *color, bool use_symbol) {
    QString result;

    if (value >= 1000000) {
        result = QString::number(value / 1000000) + "M";
    } else if (value >= 1000) {
        result = QString::number(value / 1000) + "k";
    } else {
        result += QString::number(value);
    }

    if (use_symbol) {
        result += "\u2126";
    } else {
        result += " ohms";
    }

    result += " \u00B1" + QString::number(get_band(color).tolerance) + "%";
    return result;
}

/**
 * Gets a band struct based on a name.
 *
 * @param name Name to search.
 * @return A band struct.
 */
band ResistanceCalc::get_band(const char *name) {
    for (size_t i = 0; i < values.size(); ++i) {
        if (strcmp(values[i].name, name) == 0) {
            return values[i];
        }
    }

    band _band;
    _band.name = NULL;
    _band.band = NULL;
    _band.multiplier = NULL;
    _band.tolerance = NULL;
    return _band;
}
