#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "evenement.hh"
#include "IBilleterie.hh"

Evenement::Evenement(){
    nom = "";
    date = "";
    lieu = "";
    description = "";
    type = "";
}

Evenement::Evenement(std::string nom, std::string date, std::string lieu, std::string description, std::string type){
    this->nom = nom;
    this->date = date;
    this->lieu = lieu;
    this->description = description;
    this->type = type;
}

Evenement::~Evenement(){
}

void Evenement::afficherEvenement(){
    std::cout << nom << std::endl;
    std::cout << date << std::endl;
    std::cout << lieu << std::endl;
    std::cout << description << std::endl;
    std::cout << type << std::endl;
}
