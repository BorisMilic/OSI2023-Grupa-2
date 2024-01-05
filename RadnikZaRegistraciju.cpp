#include "RadnikZaRegistraciju.h"

RadnikZaRegistraciju::RadnikZaRegistraciju() : status(true) {}

void RadnikZaRegistraciju::SetStatus(bool _status) {
    status = _status;
}

bool RadnikZaRegistraciju::GetStatus() const {
    return status;
}