#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

class IBilleterie {
    public:
        virtual void acheterTicket() = 0;
        virtual void vendreTicket() = 0;
        virtual void annulerTicket() = 0;
        virtual void modifierTicket() = 0;
        virtual void consulterTicket() = 0;
        virtual void consulterListeTickets() = 0;
        virtual void consulterListeTicketsVIP() = 0;
        virtual void consulterListeTicketsEvenement() = 0;
        virtual void consulterListeTicketsDate() = 0;
        virtual void consulterListeTicketsLieu() = 0;
        virtual void consulterListeTicketsType() = 0;
        virtual void consulterListeTicketsPrix() = 0;
};