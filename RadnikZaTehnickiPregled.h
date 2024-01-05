#pragma once
#include "Korisnik.h"

class RadnikTehnickiPregled : public Korisnik {
private:
    bool status; // aktivan/neaktivan radnik

public:
    RadnikTehnickiPregled();
    void SetStatus(bool _status);
    bool GetStatus() const;
};