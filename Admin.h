#pragma once
#include"Korisnik.h"

class Admin : public Korisnik {
private:
    bool status; // aktivan/neaktivan radnik

public:
    Admin();
    void SetStatus(bool _status);
    bool GetStatus() const;
};