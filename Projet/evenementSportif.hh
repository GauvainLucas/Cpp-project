#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "evenement.hh"

class EvenementSportif : public Evenement{
    public:
        EvenementSportif();
        EvenementSportif(std::string nom, std::string date, std::string lieu, std::string description, std::string type, std::string sport):Evenement(nom, date, lieu, description, sport){};  
        ~EvenementSportif();

        void afficherEvenement();
};