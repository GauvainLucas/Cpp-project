#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Evenement {
public:
    Evenement() {};

    Evenement(std::string nom, std::string date, std::string lieu, std::string description, std::string type) {
        this->nom = nom;
        this->date = date;
        this->lieu = lieu;
        this->description = description;
        this->type = type;
    };

    ~Evenement() {};

    //virtual std::string afficherEvenement(Evenement *evenement);

    std::string afficherEvenements(const std::vector<Evenement *> &evenements) {
        std::string affichage = "";
        for (auto evenement: evenements) {
            affichage += evenement->getNom() + "\n";
            affichage += evenement->getDate() + "\n";
            affichage += evenement->getLieu() + "\n";
            affichage += evenement->getDescription() + "\n";
            affichage += evenement->getType() + "\n";
            affichage += "--------------------------\n\n";
        }
        return affichage;
    }

    std::string getNom() { return nom; };

    std::string getDate() { return date; };

    std::string getLieu() { return lieu; };

    std::string getDescription() { return description; };

    std::string getType() { return type; };
protected:
    std::string nom;
    std::string date;
    std::string lieu;
    std::string description;
    std::string type;
};