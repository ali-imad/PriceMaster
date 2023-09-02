//
// Created by Ali Hasan on 2023-09-02.
//

#ifndef PRICEMASTER_COMMODITY_H
#define PRICEMASTER_COMMODITY_H

#include <string>
#include <random>

namespace PriceMaster {

    class Commodity {
    public:
        static Commodity makeRandomCommodity();

        void setPrice(double p);

        void setDrift(double d);

        void setVol(double v);

        void setName(const std::string &n);

        void generateNextPrice();

        void generatePriceOverTime(double dt);

    private:
        static int _count;
        static std::random_device _rd;
        static std::mt19937 _rng;

        double price;
        double drift;
    public:
        double getPrice() const;

        double getDrift() const;

        double getVol() const;

        int getIid() const;

        const std::string &getName() const;

    private:
        double vol;
        int iid;
        std::string name;

        Commodity(double price, double drift, double vol, std::string name);

        static std::string genRandomName(int len);
    };

} // PriceMaster

#endif //PRICEMASTER_COMMODITY_H
//        double weight;
//        double weight;
