//
// Created by Andrei on 4/19/2022.
//

#ifndef PROIECT2POO_ANGAJAT_H
#define PROIECT2POO_ANGAJAT_H

//
// Created by Andrei on 3/16/2022.
//
#include <iostream>
#include "Masina.h"
using namespace std;

class Angajat{
private:
    string nume;
    Masina* MasiniReparate;
    int nrMasiniReparate;
    int salariu;
    bool isAngajat;

public:
    Angajat(string nume, int salariu)
    {
        this->nume = nume;
        this->salariu = salariu;
        this->isAngajat = true;
        this->nrMasiniReparate = 0;
    }
    Angajat()
    {
        this->nume = "inexistent";
        this->salariu = -1;
        this->isAngajat = false;
        this->MasiniReparate = NULL;
        this->nrMasiniReparate = -1;
    }
    Angajat(Angajat& aux)
    {
        this->nume = aux.nume;
        this->MasiniReparate = aux.MasiniReparate;
        this->salariu = aux.salariu;
        this->isAngajat = aux.isAngajat;
        this->nrMasiniReparate = aux.nrMasiniReparate;
    }
    friend istream& operator>>(istream& in, Angajat& a)
    {
        cout<<"Introduceti numele noului angajat: ";
        in>>a.nume;
        cout<<endl<<"Introduceti salariul noului angajat: ";
        in>>a.salariu;
        a.isAngajat = true;
        a.nrMasiniReparate = 0;
        return in;
    }
    friend ostream& operator<<(ostream& out, Angajat& a)
    {
        cout<<"Angajatul "<<a.nume<<" cu salariul "<<a.salariu<<" de lei, a reparat urmatoarele masini: ";
        for (int i = 0; i < a.nrMasiniReparate; i++)
        {
            cout<<a.MasiniReparate[i]<<endl;
        }
        return out;
    }
    Angajat& operator=(const Angajat& aux)
    {
        nume = aux.nume;
        nrMasiniReparate = aux.nrMasiniReparate;
        salariu = aux.salariu;
        isAngajat = aux.isAngajat;
        MasiniReparate = aux.MasiniReparate;
        return *this;
    }
#pragma region Getteri si Setteri
    const string &getNume() const {
        return nume;
    }

    void setNume(const string &nume) {
        Angajat::nume = nume;
    }

    Masina *getMasiniReparate() const {
        return MasiniReparate;
    }

    void setMasiniReparate(Masina *masiniReparate) {
        MasiniReparate = masiniReparate;
    }

    int getSalariu() const {
        return salariu;
    }

    void setSalariu(int salariu) {
        Angajat::salariu = salariu;
    }

    bool isAngajat1() const {
        return isAngajat;
    }

    void setIsAngajat(bool isAngajat) {
        Angajat::isAngajat = isAngajat;
    }

    int getNrMasiniReparate() const {
        return nrMasiniReparate;
    }

    void setNrMasiniReparate(int nrMasiniReparate) {
        Angajat::nrMasiniReparate = nrMasiniReparate;
    }
#pragma endregion
    ~Angajat()
    {

    }
    void adaugaMasinaAngajat(Masina m)
    {
        Masina* aux;
        aux = new Masina[this->nrMasiniReparate];
        aux = this->MasiniReparate;
        MasiniReparate = new Masina[this->nrMasiniReparate + 1];
        for (int i = 0; i < nrMasiniReparate; i++)
            MasiniReparate[i] = aux[i];
        MasiniReparate[this->nrMasiniReparate + 1] = m;
        this->nrMasiniReparate++;
    }
};



#endif //PROIECT2POO_ANGAJAT_H
