#include <iostream>

class Vehicle {
private:
    double fuelQt;
    double fuelCons;
    double tankCap;
public:
    void setFuel(double fQt) {
        if (fQt < tankCap)
        {
            fuelQt = fQt;
        }
        else {
            fuelQt = 0;
        }
    }
    void setFuelCons(double fCs) {
        fuelCons = fCs;
    }
    Vehicle() {
        fuelCons = 0;
        fuelQt = 0;
        tankCap = 50;
    };
    Vehicle(double fQ, double fC, double Cap) {
        tankCap = Cap;
        setFuel(fQ);
        setFuelCons(fC);
    }
    const virtual void drive(double km) = 0;
    const virtual void refuel(double litres) =0;
    double getfuelQt()const{
        return fuelQt;
    }
    double getfuelCons()const {
        return fuelCons;
    }
    double getTankCap()const {
        return tankCap;
    }
};

class Car: public Vehicle {
private:
public:
    Car():Vehicle() {};
    Car(double fQ, double fC, double tC) :Vehicle(fQ, fC, tC) {
        setFuelCons(fC + 0.9);
    }
    const virtual void drive(double km) override {
        if (getfuelQt() / (getfuelCons()) * 100 < km)
        {
            std::cout << "Car travelled " << getfuelQt() / (getfuelCons()) * 100 << " km" << std::endl;
            std::cout << "Car needs refueling" << std::endl;
            setFuel(0);
        }
        else {
            std::cout << "Car travelled " << km << " km" << std::endl;
            setFuel((getfuelQt() / (getfuelCons()) * 100 - km)*( getfuelCons())/100);
            std::cout << "Fuel left: " << getfuelQt() << std::endl;
        }
    }
    const virtual void refuel(double litres) override 
    {
        if (litres <= 0) {
            std::cout << "Fuel must be a positive number!" << std::endl;
        }
        else 
        {
            if (getfuelQt() + litres < getTankCap())
            {
                double newFuel = getfuelQt() + litres;
                setFuel(newFuel);
            }
            else {
                std::cout << "Car cannot fit that much fuel!" << std::endl;
            }
        }
    }
};



class Truck : public Vehicle 
{
private:
public:
    Truck() :Vehicle() {};
    Truck(double fQ, double fC, double tC) :Vehicle(fQ, fC, tC) {
        setFuelCons(fC + 1.6);
    }
    const virtual void drive(double km) override {
        if (getfuelQt() / (getfuelCons()) * 100 < km) {
            std::cout << "Truck travelled " << getfuelQt() / (getfuelCons()) * 100 << std::endl;
            std::cout << "Truck needs refueling" << std::endl;
        }
        else {
            std::cout << "Truck travelled " << km << " km" << std::endl;
            setFuel((getfuelQt() / (getfuelCons()) * 100 - km) * (getfuelCons()) / 100);
            std::cout << "Fuel left: " << getfuelQt() << std::endl;
        }
    }
    const virtual void refuel(double litres) override {
        if (litres <= 0)
        {
            std::cout << "Fuel must be a positive number" << std::endl;
        }
        else
        {
            if (getfuelQt() + litres < getTankCap())
            {
                double newFuel = getfuelQt() + (litres * 95 / 100);
                setFuel(newFuel);
            }
            else
            {
                std::cout << "Truck cannot fit that much fuel!" << std::endl;
            }
        }

    };

};

class Bus : public Vehicle
{
private:
    bool isFull = 1;
public:
    Bus() :Vehicle() {};
    Bus(double fQ, double fC, double tC, bool isF) :Vehicle(fQ, fC, tC)
    {
        isFull = isF;
        if (isFull)
        {
            setFuelCons(fC + 1.4);
        }
    }
    const virtual void drive(double km) override {
        if (getfuelQt() / (getfuelCons()) * 100 < km) {
            std::cout << "Bus travelled " << getfuelQt() / (getfuelCons() ) * 100 << " km" << std::endl;
            std::cout << "Bus needs refueling" << std::endl;
            setFuel(0);
        }
        else {
            std::cout << "Bus travelled " << km << " km" << std::endl;
            setFuel((getfuelQt() / (getfuelCons()) * 100 - km) * (getfuelCons()) / 100);
            std::cout << "Fuel left: " << getfuelQt() << std::endl;
        }
    }
    const virtual void refuel(double litres) override {
        if (litres <= 0) 
        {
            std::cout << "Fuel must be a positive number!" << std::endl;
        }
        else 
        {
            if (getfuelQt() + litres < getTankCap())
            {
                double newFuel = getfuelQt() + litres;
                setFuel(newFuel);
            }
            else {
                std::cout << "Bus cannot fit that much fuel!" << std::endl;
            }
        }
    }
};






int main()
{
    Car Ferari(50, 15, 100);
    Ferari.drive(50);
    Ferari.drive(100);
    Ferari.drive(300);
    Ferari.refuel(20);
    std::cout << Ferari.getfuelQt() << std::endl;
    std::cout << std::endl;

    Truck notVolvo(60,20,200);
    notVolvo.drive(100);
    notVolvo.drive(23);
    notVolvo.refuel(100);
    std::cout << notVolvo.getfuelQt() << std::endl;
    
    std::cout << std::endl;
    bool full1 = false;
    bool full2 = true;
    Bus Busss(400, 25, 300, full2);
    Busss.refuel(100);
    Busss.drive(50);
    Busss.drive(100); 
}