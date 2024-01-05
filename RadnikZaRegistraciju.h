#pragma once
#include "Korisnik.h"

class RadnikZaRegistraciju : public Korisnik {
private:
    bool status; // aktivan/neaktivan radnik

public:
    RadnikZaRegistraciju();
    void SetStatus(bool _status);
    bool GetStatus() const;
};