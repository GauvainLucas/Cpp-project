#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "utilisateur.hh"


class UtilisateurPublic : public Utilisateur{
    public:
        UtilisateurPublic();
        UtilisateurPublic(std::string nom, std::string prenom, std::string mail, std::string telephone, std::string login, std::string mdp, std::string type);
        // getters
        std::string getNom(){return nom;};
        std::string getPrenom(){return prenom;};
        /*
        void acheterTicket(std::string nomEvenement)=0;
        void annulerTicket(std::string nomEvenement)=0;
        void consulterTicket(std::string nomEvenement)=0;
        void consulterListeTickets()=0;
        void consulterListeTicketsEvenement(std::string nomEvenement)=0;
        void consulterListeTicketsDate(std::string dateEvenement)=0;
        void consulterListeTicketsLieu(std::string lieuEvenement)=0;
        void consulterListeTicketsType(std::string typeEvenement)=0;
        */
        void modifierNom(std::string nom){this->nom = nom;};
        void modifierPrenom(std::string prenom){this->prenom = prenom;};
        void modifierMail(std::string mail){this->mail = mail;};
        void modifierTelephone(std::string telephone){this->telephone = telephone;};
        void modifierLogin(std::string login){this->login = login;};
        void modifierMdp(std::string mdp){this->mdp = mdp;};
};