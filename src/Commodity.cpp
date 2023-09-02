//
// Created by Ali Hasan on 2023-09-02.
//

#include "Commodity.h"
#include <random>
#include <utility>

namespace PriceMaster {
    int Commodity::_count = 0;
    std::random_device Commodity::_rd;
    std::mt19937 Commodity::_rng(_rd());

    Commodity::Commodity(double price, double drift, double vol, std::string name) : price(price), drift(drift),
                                                                                     vol(vol), iid(_count++),
                                                                                     name(std::move(name)) {}

    Commodity Commodity::makeRandomCommodity() {
        // Generate random values
        std::gamma_distribution<double> priceGen(2., 4.);
        std::normal_distribution<double> driftGen(0.031, 0.0086);
        std::normal_distribution<double> volGen(0.1, 0.1);
//        std::gamma_distribution<double> weightGen(1.3, 2.);

        return {priceGen(_rng), driftGen(_rng),
                  fmax(0.03, volGen(_rng)), //fmin(0.1, volGen(_rng))),
                  genRandomName(12)};
    }

    void Commodity::setPrice(double p) {
        Commodity::price = p;
    }

    void Commodity::setDrift(double d) {
        Commodity::drift = d;
    }

    void Commodity::setVol(double v) {
        Commodity::vol = v;
    }

    void Commodity::setName(const std::string &n) {
        Commodity::name = n;
    }

    void Commodity::generateNextPrice() {
        std::normal_distribution<double> dist(0.0, 1.0);
        double rand_normal = dist(_rng);

        double dPrice = this->price * (this->drift + this->vol * rand_normal);
        this->price += dPrice;
    }

    void Commodity::generatePriceOverTime(double dt) {
        std::normal_distribution<double> dist(0.0, 1.0);
        double rand_normal = dist(_rng);

        double dPrice = this->price * (this->drift * dt + this->vol * rand_normal * sqrt(dt));
        this->price += dPrice;
    }

    std::string Commodity::genRandomName(int len) {
        static const char alphanum[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        std::string tmp_s;
        tmp_s.reserve(len);

        for (int i = 0; i < len; ++i) {
            tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        return tmp_s;
    }

    double Commodity::getPrice() const {
        return price;
    }

    double Commodity::getDrift() const {
        return drift;
    }

    double Commodity::getVol() const {
        return vol;
    }

    int Commodity::getIid() const {
        return iid;
    }

    const std::string &Commodity::getName() const {
        return name;
    }
} // PriceMaster