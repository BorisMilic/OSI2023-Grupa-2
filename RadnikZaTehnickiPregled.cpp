#include "RadnikZaTehnickiPregled.h"

RadnikTehnickiPregled::RadnikTehnickiPregled() : status(true) {}

void RadnikTehnickiPregled::SetStatus(bool _status) {
    status = _status;
}

bool RadnikTehnickiPregled::GetStatus() const {
    return status;
}