#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateur.hh"

class UtilisateurVIP : public Utilisateur{
    public:
        UtilisateurVIP() = default;
        UtilisateurVIP(std::string nom, std::string prenom, std::string mail,
                       std::string telephone, std::string login, std::string mdp,
                       std::string type):Utilisateur(nom, prenom, mail, telephone, login, mdp, type){};

    std::string getNom(){return nom;};
    std::string getPrenom(){return prenom;};
    std::vector<Evenement> getListeTicketsVIP(){return listeTicketsVIP;};
    int acheterTicket(Evenement evenement);
    void consulterListeTicketsVIP();
    int annulerTicket(Evenement evenement);
    bool operator==(const UtilisateurVIP& other) const;
    friend std::ostream& operator<<(std::ostream& os, const UtilisateurVIP& user);

    protected:
        std::vector<Evenement> listeTicketsVIP;
};