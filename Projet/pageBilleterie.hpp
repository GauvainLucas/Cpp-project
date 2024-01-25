#ifndef PROJET_PAGEBILLETERIE_HPP
#define PROJET_PAGEBILLETERIE_HPP

#include <iostream>

// Define a structure to represent the data for each row
struct ChartData {
    std::string evenement;
    std::string date;
    std::string lieux;
    std::string type;
    std::string acces;
    std::string reserver;
};

void pageBilleterie();

#endif //PROJET_PAGEBILLETERIE_HPP
