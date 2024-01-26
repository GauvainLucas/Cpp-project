#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "evenement.hh"
#include <vector>

class EvenementSportif : public Evenement{
    public:
        EvenementSportif();
        EvenementSportif(std::string nom,
                         std::string date,
                         std::string lieu,
                         std::string description,
                         std::string type,
                         std::string sport):Evenement(nom, date, lieu, description, type){
                                this->sport = sport;
        };
        ~EvenementSportif();

        std::string afficherEvenements(const std::vector<Evenement*>& evenements);
        // get sport
        std::string getSport() override { return sport; };
protected:
        std::string sport;
};