#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "evenement.hh"

class EvenementCeremonie : public Evenement{
    public:
        EvenementCeremonie();
        EvenementCeremonie(std::string nom, std::string date, std::string lieu,
                           std::string description, std::string type,
                           std::string ceremonie):Evenement(nom, date, lieu, description, type){
                                this->ceremonie = ceremonie;
        };
        ~EvenementCeremonie();

        std::string getSport(){return ceremonie;};
        void afficherEvenement();
protected:
        std::string ceremonie;
};