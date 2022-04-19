//
// Created by Andrei on 4/18/2022.
//

#ifndef PROIECT2POO_VEHICUL_H
#define PROIECT2POO_VEHICUL_H

#include <iostream>
using namespace std;

class Vehicul{
private:
    string nrInmatriculare;
    string culoare;
    bool reparata;
    int anFabricatie;
    int CaiPutere;

public:
    Vehicul(string nrInmatriculare, string culoare, bool reparata, int anFabricatie, int CaiPutere)
    {
        this->anFabricatie = anFabricatie;
        this->culoare = culoare;
        this->reparata = reparata;
        this->nrInmatriculare = nrInmatriculare;
        this->CaiPutere = CaiPutere;
    }

    Vehicul()
    {
        this->culoare = "";
        this->reparata = "Inexistenta";
    }

    Vehicul(Vehicul& aux)
    {
        this->culoare = aux.culoare;
        this->reparata = aux.reparata;
        this->anFabricatie = aux.anFabricatie;
        this->CaiPutere = aux.CaiPutere;
        this->nrInmatriculare = aux.nrInmatriculare;
    }

    friend istream& operator>>(istream& in, Vehicul& v)
    {
        cout<<"Introduceti numarul de inmatriculare al autovehiculului"<<endl;
        in>>v.nrInmatriculare;
        cout<<"Introduceti culoarea autovehiculului"<<endl;
        in>>v.culoare;
        cout<<"Introduceti anul fabriecatiei autovehiculului"<<endl;
        in>>v.anFabricatie;
        cout<<"Introduceti caii putere ai autovehiculului"<<endl;
        in>>v.CaiPutere;
        v.reparata = false;
        return in;
    }

    friend istream& operator>>(istream& in, Vehicul* v)
    {
        cout<<"Introduceti numarul de inmatriculare al autovehiculului "<<endl;
        in>>v->nrInmatriculare;
        cout<<"Introduceti culoarea autovehiculului"<<endl;
        in>>v->culoare;
        cout<<"Introduceti anul fabriecatiei autovehiculului"<<endl;
        in>>v->anFabricatie;
        cout<<"Introduceti caii putere ai autovehiculului"<<endl;
        in>>v->CaiPutere;
        v->reparata = false;
        return in;
    }

    friend ostream& operator<<(ostream& out, Vehicul& v)
    {
        out<<"Autovehiculul are numarul de inmatriculare "<<v.nrInmatriculare<<" si a fost fabricat in "<<v.anFabricatie;
        return out;
        return out;
    }

    Vehicul& operator=(const Vehicul& aux)
    {
        culoare = aux.culoare;
        reparata = aux.reparata;
        anFabricatie = aux.anFabricatie;
        CaiPutere = aux.CaiPutere;
        nrInmatriculare = aux.nrInmatriculare;
        return *this;
    }

    virtual void SoftArabesc()
    {

    }

#pragma region GETTERI si SETTERI

    const string &getNrInmatriculare() const {
        return nrInmatriculare;
    }

    void setNrInmatriculare(const string &nrInmatriculare) {
        Vehicul::nrInmatriculare = nrInmatriculare;
    }

    const string &getCuloare() const {
        return culoare;
    }

    void setCuloare(const string &culoare) {
        Vehicul::culoare = culoare;
    }

    bool isReparata() {
        return reparata;
    }

    void setReparata(bool reparata) {
        Vehicul::reparata = reparata;
    }

    int getAnFabricatie() const {
        return anFabricatie;
    }

    void setAnFabricatie(int anFabricatie) {
        Vehicul::anFabricatie = anFabricatie;
    }

    int getCaiPutere() const {
        return CaiPutere;
    }

    void setCaiPutere(int caiPutere) {
        CaiPutere = caiPutere;
    }

#pragma endregion

    ~Vehicul()
    {

    }
};

#endif //PROIECT2POO_VEHICUL_H
