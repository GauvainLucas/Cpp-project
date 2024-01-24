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
    void acheterTicket(Evenement evenement);

    void annulerTicket(Evenement evenement) override {
        // Implementation for annulerTicket goes here
    }

    void consulterTicket(Evenement evenement) override {
        // Implementation for consulterTicket goes here
    }

    void consulterListeTickets() override {
        // Implementation for consulterListeTickets goes here
    }

    void consulterListeTicketsVIP();

    void consulterListeTicketsEvenement(std::string nomEvenement) override {
        // Implementation for consulterListeTicketsEvenement goes here
    }

    void consulterListeTicketsDate(std::string dateEvenement) override {
        // Implementation for consulterListeTicketsDate goes here
    }

    void consulterListeTicketsLieu(std::string lieuEvenement) override {
        // Implementation for consulterListeTicketsLieu goes here
    }

    void consulterListeTicketsType(std::string typeEvenement) override {
        // Implementation for consulterListeTicketsType goes here
    }

    /*void modifierNom(std::string nom) override {
        // Implementation for modifierNom goes here
    }

    void modifierPrenom(std::string prenom) override {
        // Implementation for modifierPrenom goes here
    }

    void modifierMail(std::string mail) override {
        // Implementation for modifierMail goes here
    }

    void modifierTelephone(std::string telephone) override {
        // Implementation for modifierTelephone goes here
    }

    void modifierLogin(std::string login) override {
        // Implementation for modifierLogin goes here
    }

    void modifierMdp(std::string mdp) override {
        // Implementation for modifierMdp goes here
    }

    void modifierType(std::string type) override {
        // Implementation for modifierType goes here
    }*/

    protected:
        std::vector<Evenement> listeTicketsVIP;
};