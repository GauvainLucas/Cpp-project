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
        void consulterTicket(std::string nomEvenement);
        void consulterListeTickets();
        void consulterListeTicketsVIP();
        void consulterListeTicketsEvenement(std::string nomEvenement);
        void consulterListeTicketsDate(std::string dateEvenement);
        void consulterListeTicketsLieu(std::string lieuEvenement);
        void consulterListeTicketsType(std::string typeEvenement);

        void modifierNom(std::string nom);
        void modifierPrenom(std::string prenom);
        void modifierMail(std::string mail);
        void modifierTelephone(std::string telephone);
        void modifierLogin(std::string login);
        void modifierMdp(std::string mdp);
    protected:
        std::vector<Evenement> listeTicketsVIP;
};