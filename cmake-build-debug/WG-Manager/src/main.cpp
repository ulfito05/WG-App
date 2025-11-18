#include <iostream>
#include "model/WG.h"

int main() {
    WG myWg("Muster-WG");
    std::cout << "WG Manager gestartet für: " << myWg.getName() << std::endl;

    return 0;
}
