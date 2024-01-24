#include "evenementSportif.hh"
#include <vector>

// Constructeur

/*
// affiche la liste des evenements
std::string EvenementSportif::afficherEvenement(Evenement* evenement){
    std::string affichage = "";
    affichage +=  evenement->getNom() + "\n";
    affichage +=  evenement->getDate() + "\n";
    affichage +=  evenement->getLieu() + "\n";
    affichage +=  evenement->getDescription() + "\n";
    //affichage +=  evenement->getType() + "\n";
    affichage +=  evenement->getType() + "\n";
    affichage += "--------------------------\n\n";
    return affichage;
}*/

std::string EvenementSportif::afficherEvenements(const std::vector<Evenement*>& evenements) {
    std::string affichage = "";
    for (auto evenement : evenements) {
        affichage += evenement->getNom() + "\n";
        affichage += evenement->getDate() + "\n";
        affichage += evenement->getLieu() + "\n";
        affichage += evenement->getDescription() + "\n";
        affichage += evenement->getType() + "\n";
        affichage += evenement->getSport() + "\n";
        affichage += "--------------------------\n\n";
    }
    return affichage;
}
