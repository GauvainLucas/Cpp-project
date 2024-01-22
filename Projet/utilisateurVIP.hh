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

        void acheterTicket();
        void annulerTicket();
        void consulterTicket();
        void consulterListeTickets();
        void consulterListeTicketsVIP();
        void consulterListeTicketsEvenement();
        void consulterListeTicketsDate();
        void consulterListeTicketsLieu();
        void consulterListeTicketsType();
        void consulterListeTicketsPrix();

};