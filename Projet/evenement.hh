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

        std::string getNom(){return nom;};
        std::string getDate(){return date;};
        std::string getLieu(){return lieu;};
        std::string getDescription(){return description;};
        std::string getType(){return type;};
    protected:
        std::string nom;
        std::string date;
        std::string lieu;
        std::string description;
        std::string type;
};