#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateurVIP.hh"

class UtilisateurAdmin : public UtilisateurVIP, public IBilleterie{
    public:
        UtilisateurAdmin();
        UtilisateurAdmin(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type):UtilisateurVIP(nom, prenom, mail, telephone, login, mdp, type){};

        void acheterTicket();
        void vendreTicket();
        void annulerTicket();
        void modifierTicket();
        void consulterTicket();
        void consulterListeTickets();
        void consulterListeTicketsVIP();
        void consulterListeTicketsEvenement();
        void consulterListeTicketsDate();
        void consulterListeTicketsLieu();
        void consulterListeTicketsType();
        void consulterListeTicketsPrix();

};