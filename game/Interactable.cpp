#include "Interactable.h"

bool Interactable::isHighlighted() {
    return highlighted;
}

void Interactable::setHighlighted(bool highlighted) {
    if (highlighted) {
        if (!globalHighlighted) {
            globalHighlighted = true;
            this->highlighted = true;
        }
    } else if (this->highlighted) {
        globalHighlighted = false;
        this->highlighted = false;
    }
}
