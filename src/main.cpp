#include <iostream>
#include "Commodity.h"

using namespace PriceMaster;

int main() {
    Commodity c = Commodity::makeRandomCommodity();
    std::cout << "Current price of #" << c.getIid() << " (name: " << c.getName() << "): $" << c.getPrice() << " VOL: "
              << c.getVol() << " DRIFT: " << c.getDrift() << std::endl;
    std::cout << "making three more commodities.." << std::endl;
    Commodity a = Commodity::makeRandomCommodity();
    Commodity b = Commodity::makeRandomCommodity();
    Commodity d = Commodity::makeRandomCommodity();
    std::cout << "Current price of #" << d.getIid() << " (name: " << d.getName() << "): $" << d.getPrice() << " VOL: "
              << d.getVol() << " DRIFT: " << d.getDrift() << std::endl;
    std::cout << "generating price of " << d.getName() << " over 1 time step" << std::endl;
    d.generateNextPrice();
    std::cout << "Current pride of #" << d.getIid() << " (name: " << d.getName() << "): $" << d.getPrice() << std::endl;
    std::cout << "generating price of " << c.getName() << " over 1 time step" << std::endl;
    c.generateNextPrice();
    std::cout << "Current price of #" << c.getIid() << " (name: " << c.getName() << "): $" << c.getPrice() << std::endl;
    std::cout << "generating price of " << c.getName() << " over 12 time steps" << std::endl;
    c.generatePriceOverTime(12.);
    std::cout << "Current price of #" << c.getIid() << " (name: " << c.getName() << "): $" << c.getPrice() << std::endl;
    std::cout << "generating price of " << d.getName() << " over 100 time steps" << std::endl;
    d.generatePriceOverTime(100);
    std::cout << "Current pride of #" << d.getIid() << " (name: " << d.getName() << "): $" << d.getPrice() << std::endl;
//    std::getline(std::cin, tmp);

    return 0;
}
