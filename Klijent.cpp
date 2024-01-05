#include "Klijent.h"
Klijent::Klijent() : status(true) {}
void Klijent::SetStatus(bool _status) {
    status = _status;
}
bool Klijent::GetStatus() const {
    return status;
}