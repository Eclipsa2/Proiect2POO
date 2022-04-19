//
// Created by Andrei on 4/18/2022.
//

#ifndef PROIECT2POO_MASINA_H
#define PROIECT2POO_MASINA_H

#include "Vehicul.h"
#include <iostream>

using namespace std;

class Masina : public Vehicul{
private:
    string marca;
    string model;
    int probleme[6];
    int manopera;

public:
    Masina(string marca, string model, int anFabricatie, string culoare,string nrInmatriculare, bool reparata, int probleme[], int CaiPutere) : Vehicul(nrInmatriculare, culoare, reparata, anFabricatie, CaiPutere)
    {
        this->marca = marca;
        this->model = model;
        for(int i = 0; i <= 5; i++)
            this->probleme[i] = probleme[i];
        this->CalculManopera();
    }

    Masina() : Vehicul()
    {
        this->marca = "Inexistenta";
        this->model = "";
        for(int i = 0; i <= 5; i++)
            this->probleme[i] = -1;
    }

    Masina(Masina& aux) : Vehicul(aux)
    {
        this->marca = aux.marca;
        this->model = aux.model;
        for (int i = 0; i <= 5; i++)
            this->probleme[i] = aux.probleme[i];
        this->manopera = aux.manopera;
    }

    friend istream& operator>>(istream& in, Masina& m)
    {
        cout<<"Introduceti marca masinii"<<endl;
        in>>m.marca;
        cout<<"Introduceti modelul masinii"<<endl;
        in>>m.model;
        in>>(Vehicul&)m;
        m.setReparata(false);
        cout<<"Alegeti serviciile dorite: "<<endl<<"1. Reparatie frane"<<endl<<"2. Schimb ulei"<<endl<<"3. Reparatie climatizare"<<endl<<"4. Tinichigerie"<<endl<<"5. ITP"<<endl<<"6. Soft arabesc"<<endl<<"0. Toate serviciile au fost adaugate"<<endl;
        int codProblema;
        in>> codProblema;
        for (int i = 0; i<=5;i++)
            m.probleme[i] = 0;
        while (codProblema != 0)
        {
            m.probleme[codProblema - 1] = 1;
            cout<<endl<<"Problema Adaugata"<<endl;
            in>>codProblema;
        }
        m.CalculManopera();
        return in;
    }

    friend istream& operator>>(istream& in, Masina* m)
    {
        cout<<"Introduceti marca masinii"<<endl;
        in>>m->marca;
        cout<<"Introduceti modelul masinii"<<endl;
        in>>m->model;
        m->setReparata(false);
        in>>(Vehicul*)m;
        cout<<"Alegeti serviciile dorite: "<<endl<<"1. Reparatie frane"<<endl<<"2. Schimb ulei"<<endl<<"3. Reparatie climatizare"<<endl<<"4. Tinichigerie"<<endl<<"5. ITP"<<endl<<"6. Soft arabesc"<<endl<<"0. Toate serviciile au fost adaugate"<<endl;
        int codProblema;
        in>> codProblema;
        for (int i = 0; i<=5;i++)
            m->probleme[i] = 0;
        while (codProblema != 0)
        {
            m->probleme[codProblema - 1] = 1;
            cout<<endl<<"Problema Adaugata"<<endl;
            in>>codProblema;
        }
        m->CalculManopera();
        return in;
    }

    friend ostream& operator<<(ostream& out, Masina& m)
    {
        if (m.isReparata() == false)
        {
            cout<<endl<<"Pentru masina "<<m.marca<<" "<<m.model<<" cu numarul de inmatriculare "<<m.getNrInmatriculare()<<" de culoare "<<m.getCuloare()<<", din anul "<<m.getAnFabricatie()<<" cu "<<m.getCaiPutere()<<" CP, se ofera urmatoarele servicii:"<<endl;
            if (m.probleme[0] == 1)
                cout<<"Reparatie frane"<<endl;
            if (m.probleme[1] == 1)
                cout<<"Schimb ulei"<<endl;
            if (m.probleme[2] == 1)
                cout<<"Reparatie climatizarea"<<endl;
            if (m.probleme[3] == 1)
                cout<<"Tinichigerie"<<endl;
            if (m.probleme[4] == 1)
                cout<<"ITP"<<endl;
            if (m.probleme[5] == 1)
                cout<<"Soft arabesc"<<endl;
            cout<<"Costul total fiind: "<<m.manopera<<" lei";
        }
        else
        {
            cout<<endl<<"Masina "<<m.marca<<" "<<m.model<<" cu numarul de inmatriculare "<<m.getNrInmatriculare()<<" de culoare "<<m.getCuloare()<<", din anul "<<m.getAnFabricatie()<<" cu "<<m.getCaiPutere()<<" CP, a fost reparata cu succes, iar costul total fiind de: "<<m.manopera<<" lei";
        }
        return out;
    }

    friend ostream& operator<<(ostream& out, Masina* m)
    {
        if (m->isReparata() == false)
        {
            cout<<endl<<"Pentru masina "<<m->marca<<" "<<m->model<<" cu numarul de inmatriculare "<<m->getNrInmatriculare()<<" de culoare "<<m->getCuloare()<<", din anul "<<m->getAnFabricatie()<<" cu "<<m->getCaiPutere()<<" CP, se ofera urmatoarele servicii:"<<endl;
            if (m->probleme[0] == 1)
                cout<<"Reparatie frane"<<endl;
            if (m->probleme[1] == 1)
                cout<<"Schimb ulei"<<endl;
            if (m->probleme[2] == 1)
                cout<<"Reparatie climatizarea"<<endl;
            if (m->probleme[3] == 1)
                cout<<"Tinichigerie"<<endl;
            if (m->probleme[4] == 1)
                cout<<"ITP"<<endl;
            if (m->probleme[5] == 1)
                cout<<"Soft arabesc"<<endl;
            cout<<"Costul total fiind: "<<m->manopera<<" lei";
        }
        else
        {
            cout<<endl<<"Masina "<<m->marca<<" "<<m->model<<" cu numarul de inmatriculare "<<m->getNrInmatriculare()<<" de culoare "<<m->getCuloare()<<", din anul "<<m->getAnFabricatie()<<" cu "<<m->getCaiPutere()<<" CP, a fost reparata cu succes, iar costul total fiind de: "<<m->manopera<<" lei";
        }
        return out;
    }

    Masina& operator=(const Masina& aux)
    {
        marca = aux.marca;
        model = aux.model;
        for (int i = 0; i <= 5; i++)
            probleme[i] = aux.probleme[i];
        manopera = aux.manopera;
        Vehicul::operator=(aux);
        return *this;
    }

    void CalculManopera()
    {
        int sumaTotala = 0;
        if (this->probleme[0] == 1)
            sumaTotala += 1000;
        if (this->probleme[1] == 1)
            sumaTotala += 100;
        if (this->probleme[2] == 1)
            sumaTotala += 500;
        if (this->probleme[3] == 1)
            sumaTotala += 2000;
        if (this->probleme[4] == 1)
            sumaTotala += 250;
        if (this->probleme[5] == 1)
            sumaTotala += 1500;
        this->manopera = sumaTotala;
    }

    void SoftArabesc()
    {
        cout<<endl<<"Cati caluti ii bagam veriku?"<<endl;
        int bonus;
        cin>>bonus;
        this->setCaiPutere(getCaiPutere() + bonus);
        cout<<"Am adaugat "<<bonus<<" CP la masina dvs.";
    }

    ~Masina()
    {

    }

#pragma region GETTERI si SETTERI

    const string &getMarca() const {
        return marca;
    }

    void setMarca(const string &marca) {
        Masina::marca = marca;
    }

    const string &getModel() const {
        return model;
    }

    void setModel(const string &model) {
        Masina::model = model;
    }

    void setProbleme(int V[])
    {
        for (int i = 0; i<=5; i++)
            Masina::probleme[i] = V[i];
    }

    int *getProbleme(){
        return probleme;
    }

    int getManopera() const {
        return manopera;
    }

    void setManopera(int manopera) {
        Masina::manopera = manopera;
    }

#pragma endregion
};

#endif //PROIECT2POO_MASINA_H
