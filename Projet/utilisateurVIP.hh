#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateur.hh"

class UtilisateurVIP : public Utilisateur{
    public:
        UtilisateurVIP();
        UtilisateurVIP(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type):Utilisateur(nom, prenom, mail, telephone, login, mdp, type){};

        void acheterTicket(std::string nomEvenement);
        void annulerTicket(std::string nomEvenement);
        void consulterListeTicketsVIP();

    protected:
        std::vector<Evenement> listeTicketsVIP;
};