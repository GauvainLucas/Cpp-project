#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "IBilleterie.hh"

class Utilisateur /*: public IBilleterie*/{
    public:
        Utilisateur();
        Utilisateur(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type);

        void acheterTicket();
        void annulerTicket();
        void consulterTicket();
        void consulterListeTickets();
        void consulterListeTicketsEvenement();
        void consulterListeTicketsDate();
        void consulterListeTicketsLieu();
        void consulterListeTicketsType();
        void consulterListeTicketsPrix();

    protected:
        std::string nom;
        std::string prenom;
        std::string mail;
        std::string telephone;
        std::string login;
        std::string mdp;
        std::string type;

};