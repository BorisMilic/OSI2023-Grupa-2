#include "Admin.h"

Admin::Admin() : status(true) {}

void Admin::SetStatus(bool _status) {
    status = _status;
}

bool Admin::GetStatus() const {
    return status;
}