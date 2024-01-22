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
        virtual void consulterListeTicketsEvenement() = 0;
        virtual void consulterListeTicketsDate() = 0;
        virtual void consulterListeTicketsLieu() = 0;
        virtual void consulterListeTicketsType() = 0;
        virtual void consulterListeTicketsPrix() = 0;

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