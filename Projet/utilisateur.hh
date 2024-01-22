#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "evenement.hh"

class Utilisateur{
    public:
        Utilisateur();
        Utilisateur(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type);

        virtual void acheterTicket(std::string nomEvenement) = 0;
        virtual void annulerTicket(std::string nomEvenement) = 0;
        virtual void consulterTicket(std::string nomEvenement) = 0;
        virtual void consulterListeTickets() = 0;
        virtual void consulterListeTicketsEvenement(std::string nomEvenement) = 0;
        virtual void consulterListeTicketsDate(std::string dateEvenement) = 0;
        virtual void consulterListeTicketsLieu(std::string lieuEvenement) = 0;
        virtual void consulterListeTicketsType(std::string typeEvenement) = 0;

        virtual void modifierNom(std::string nom) = 0;
        virtual void modifierPrenom(std::string prenom) = 0;
        virtual void modifierMail(std::string mail) = 0;
        virtual void modifierTelephone(std::string telephone) = 0;
        virtual void modifierLogin(std::string login) = 0;
        virtual void modifierMdp(std::string mdp) = 0;

    protected:
        std::string nom;
        std::string prenom;
        std::string mail;
        std::string telephone;
        std::string login;
        std::string mdp;
        std::string type;
        std::vector<Evenement> listeTickets;
};