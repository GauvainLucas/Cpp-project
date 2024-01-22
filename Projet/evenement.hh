#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

class Evenement{
    public:
        Evenement();
        Evenement(std::string nom, std::string date, std::string lieu, std::string description, std::string type);
        ~Evenement();

        virtual void afficherEvenement();
    protected:
        std::string nom;
        std::string date;
        std::string lieu;
        std::string description;
        std::string type;
};