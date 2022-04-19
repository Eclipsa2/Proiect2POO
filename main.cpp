#include <iostream>
#include <stdlib.h>
#include "Masina.h"
#include "Motocicleta.h"
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;

void citireFisierReparate(int& nrMasiniReparate, int& nrMotocicleteReparate, vector <Vehicul*> &vehicule)
{
    string marca, model, nrInmatriculare, culoare, tipTransmisie;
    bool reparata;
    int  manopera, anFabricatie, caiPutere, auxVector[5], distantaRoti, masaTotala;
    ifstream f("C:\\Users\\Andrei\\CLionProjects\\Proiect2POO\\MasiniReparateVeriku");
    f>>nrMasiniReparate;
    for (int i = 0; i < nrMasiniReparate; i++)
    {
        f>>marca>>model>>nrInmatriculare>>culoare>>reparata;
        for (int i = 0; i<=5; i++)
        {
            f>>auxVector[i];
        }
        f>>manopera>>anFabricatie>>caiPutere;
        vehicule.push_back(new Masina(marca, model, anFabricatie, culoare, nrInmatriculare, reparata, auxVector, caiPutere));
    }
    f>>nrMotocicleteReparate;
    for (int i = 0; i < nrMotocicleteReparate; i++)
    {
        f>>marca>>model>>nrInmatriculare>>culoare>>reparata>>tipTransmisie;
        for (int i = 0; i<=5; i++)
        {
            f>>auxVector[i];
        }
        f>>manopera>>anFabricatie>>caiPutere>>distantaRoti>>masaTotala;
        vehicule.push_back(new Motocicleta(marca, model, anFabricatie, culoare, nrInmatriculare, tipTransmisie, masaTotala, distantaRoti, reparata, auxVector, caiPutere));
    }
    f.close();
}

void citireFisierService(int& nrMasiniService, int& nrMotocicleteService, vector <Vehicul*> &vehicule)
{
    string marca, model, nrInmatriculare, culoare, tipTransmisie;
    bool reparata;
    int  manopera, anFabricatie, caiPutere, auxVector[5], distantaRoti, masaTotala;
    ifstream f("C:\\Users\\Andrei\\CLionProjects\\Proiect2POO\\MasiniServiceVeriku");
    f>>nrMasiniService;
    for (int i = 0; i < nrMasiniService; i++)
    {
        f>>marca>>model>>nrInmatriculare>>culoare>>reparata;
        for (int i = 0; i<=5; i++)
        {
            f>>auxVector[i];
        }
        f>>manopera>>anFabricatie>>caiPutere;
        vehicule.push_back(new Masina(marca, model, anFabricatie, culoare, nrInmatriculare, reparata, auxVector, caiPutere));
    }
    f>>nrMotocicleteService;
    for (int i = 0; i < nrMotocicleteService; i++)
    {
        f>>marca>>model>>nrInmatriculare>>culoare>>reparata>>tipTransmisie;
        for (int i = 0; i<=5; i++)
        {
            f>>auxVector[i];
        }
        f>>manopera>>anFabricatie>>caiPutere>>distantaRoti>>masaTotala;
        vehicule.push_back(new Motocicleta(marca, model, anFabricatie, culoare, nrInmatriculare, tipTransmisie, masaTotala, distantaRoti, reparata, auxVector, caiPutere));
    }
    f.close();
}

void scriereFisierReparate(int nrMasiniReparate, int nrMotocicleteReparate, vector <Vehicul*> vehicule)
{
    ofstream g("C:\\Users\\Andrei\\CLionProjects\\Proiect2POO\\MasiniReparateVeriku") ;
    g<<nrMasiniReparate<<endl;
    int contor = 0;
    for(auto p = vehicule.begin(); p!= vehicule.end() and contor < nrMasiniReparate; p++)
    {
        if (dynamic_cast<Masina*>(*p)->isReparata() == true)
        {
            g<<dynamic_cast<Masina*>(*p)->getMarca()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getModel()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getNrInmatriculare()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getCuloare()<<" ";
            g<<dynamic_cast<Masina*>(*p)->isReparata()<<" ";
            const int* probleme = (dynamic_cast<Masina*>(*p)->getProbleme());
            for (int i = 0; i<=5; i++)
                g<<probleme[i]<<" ";
            g<<dynamic_cast<Masina*>(*p)->getManopera()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getAnFabricatie()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getCaiPutere()<<" ";
            g<<endl;
        }
        contor++;
    }
    g<<nrMotocicleteReparate<<endl;
    contor = 0;
    for(auto p = vehicule.begin(); p!= vehicule.end() and contor < nrMasiniReparate; p++)
    {
        g<<dynamic_cast<Motocicleta*>(*p)->getMarca()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getModel()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getNrInmatriculare()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getCuloare()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->isReparata()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getTipTransmisie()<<" ";
        const int* probleme = (dynamic_cast<Motocicleta*>(*p)->getProbleme());
        for (int i = 0; i<=5; i++)
            g<<probleme[i]<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getManopera()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getAnFabricatie()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getCaiPutere()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getDistantaRoti()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getMasaTotala()<<" ";
        g<<endl;
        contor++;
    }

    g.close();
}

void scriereFisierService(int nrMasiniService, int nrMotocicleteService, vector <Vehicul*> vehicule)
{
    ofstream g("C:\\Users\\Andrei\\CLionProjects\\Proiect2POO\\MasiniServiceVeriku") ;
    g<<nrMasiniService<<endl;
    int contor = 0;
    for(auto p = vehicule.begin(); p!= vehicule.end() and contor < nrMasiniService; p++)
    {
        if (dynamic_cast<Masina*>(*p)->isReparata() == false)
        {
            g<<dynamic_cast<Masina*>(*p)->getMarca()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getModel()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getNrInmatriculare()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getCuloare()<<" ";
            g<<dynamic_cast<Masina*>(*p)->isReparata()<<" ";
            const int* probleme = (dynamic_cast<Masina*>(*p)->getProbleme());
            for (int i = 0; i<=5; i++)
                g<<probleme[i]<<" ";
            g<<dynamic_cast<Masina*>(*p)->getManopera()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getAnFabricatie()<<" ";
            g<<dynamic_cast<Masina*>(*p)->getCaiPutere()<<" ";
            g<<endl;
        }
        contor++;
    }
    g<<nrMotocicleteService<<endl;
    contor = 0;
    for(auto p = vehicule.begin(); p!= vehicule.end() and contor < nrMasiniService; p++)
    {
        g<<dynamic_cast<Motocicleta*>(*p)->getMarca()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getModel()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getNrInmatriculare()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getCuloare()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->isReparata()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getTipTransmisie()<<" ";
        const int* probleme = (dynamic_cast<Motocicleta*>(*p)->getProbleme());
        for (int i = 0; i<=5; i++)
            g<<probleme[i]<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getManopera()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getAnFabricatie()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getCaiPutere()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getDistantaRoti()<<" ";
        g<<dynamic_cast<Motocicleta*>(*p)->getMasaTotala()<<" ";
        g<<endl;
        contor++;
    }

    g.close();
}

int menu()
{
    //system("cls");
    cout<<"Bine ati venit la Veriku Service! "<<endl;
    cout<<"1. Adaugati o masina noua in service"<<endl;
    cout<<"2. Vizualizati masinile aflate momentan in service"<<endl;
    cout<<"3. Vizualizati masinile reparate de service-ul nostru"<<endl;
    cout<<"4. Schimbare status masini"<<endl;
    cout<<"5. Soft arabesc masina"<<endl;
    cout<<"6. Adaugati o motocicleta noua in service"<<endl;
    cout<<"7. Vizualizati motocicletele aflate momentan in service"<<endl;
    cout<<"8. Vizualizati motocicletele reparate de service-ul nostru"<<endl;
    cout<<"9. Schimbare status motocicleta"<<endl;
    cout<<"0. Exit"<<endl;
    int optiune;
    cin>>optiune;
    while (optiune > 9)
    {
        cout<<endl<<"Optiune introdusa inexistenta!"<<endl;
        cin>>optiune;
    }
    return optiune;
}

int main() {
    int nrMasiniService = 0, nrMotocicleteReparate = 0, nrMotocicleteService = 0, nrMasiniReparate = 0, contorMasiniServiceAdaugate = 0, contorMotocicleteServiceAdaugate = 0, contorMasiniReparateAdaugate = 0, contorMotocicleteReparateAdaugate = 0;
    int contor = 0;
    vector<Vehicul*> vehiculeService;
    vector<Vehicul*> vehiculeReparate;
    citireFisierReparate(nrMasiniReparate, nrMotocicleteReparate, vehiculeReparate);
    citireFisierService(nrMasiniReparate, nrMotocicleteService, vehiculeService);
    int optiune = menu();
    while (optiune != 0)
    {
        switch (optiune)
        {
            case 1:
            {
                cout<<endl<<"Ati ales optiunea de adaugare a unei masini noi"<<endl;
                vehiculeService.push_back(new Masina);
                auto p = vehiculeService.end() - 1;
                cin>>dynamic_cast<Masina*>(*p);
                contorMasiniServiceAdaugate++;
                nrMasiniService++;
                cout<<endl<<"Masina noua a fost adaugata cu succes!";
                cout<<endl<<"1. Adaugati inca o masina noua"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                break;
            }
            case 2:
            {
                contor = 0;
                cout<<"Urmatoarele masini se afla momentan in Service-ul lui Veriku: "<<endl;
                for(auto p = vehiculeService.begin(); p!= vehiculeService.end(); p++)
                {
                    if(static_cast<Masina*>(*p)->isReparata() == false and typeid(**p) == typeid(Masina))
                        cout<<static_cast<Masina*>(*p);
                    contor++;
                }
                cout<<endl<<"1. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 1)
                    optiune = menu();
                break;
            }
            case 3:
            {
                contor = 0;
                cout<<"Urmatoarele masini au fost reparate in Service-ul lui Veriku: "<<endl;
                for(auto p = vehiculeService.begin(); p!= vehiculeService.end(); p++)
                {
                    if(static_cast<Masina*>(*p)->isReparata() == true and typeid(**p) == typeid(Masina))
                        cout<<static_cast<Masina*>(*p);
                    contor++;
                }
                cout<<endl<<"1. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 1)
                    optiune = menu();
                break;
            }
            case 4:
            {
                cout<<endl<<"Ati ales optiunea de a repara masina"<<endl;
                string nrInmatriculare;
                int ok = 0;
                cout<<endl<<"Introduceti numarul de inmatriculare al masinii reparate: ";
                cin>>nrInmatriculare;
                for(auto p = vehiculeService.begin(); p!= vehiculeService.end(); p++)
                {
                    if(static_cast<Masina*>(*p)->getNrInmatriculare() == nrInmatriculare and typeid(**p) == typeid(Masina))
                    {
                        static_cast<Masina*>(*p)->setReparata(true);
                        string marca = static_cast<Masina*>(*p)->getMarca(), model = static_cast<Masina*>(*p)->getModel(), nrInmatriculare = static_cast<Masina*>(*p)->getNrInmatriculare(), culoare = static_cast<Masina*>(*p)->getCuloare();
                        bool reparata = static_cast<Masina*>(*p)->isReparata();
                        int anFabricatie = static_cast<Masina*>(*p)->getAnFabricatie(), caiPutere = static_cast<Masina*>(*p)->getCaiPutere();
                        int* auxVector;
                        auxVector = static_cast<Masina*>(*p)->getProbleme();
                        vehiculeReparate.push_back(new Masina(marca, model, anFabricatie, culoare, nrInmatriculare, reparata, auxVector, caiPutere));
                        contorMasiniReparateAdaugate++;
                    }
                    contor++;
                }
                if (ok == 0)
                    cout<<"Masina cu nr de inmatriculare "<<nrInmatriculare<<" nu a fost gasita"<<endl;
                cout<<endl<<"1. Schimbati statusul unei alte masini"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                else
                    optiune = 4;
                break;
            }
            case 5:
            {
                cout<<endl<<"Ati ales specialitatea casei"<<endl;
                string nrInmatriculare;
                int ok = 0;
                cout<<endl<<"Introduceti numarul de inmatriculare al masinii reparate: ";
                cin>>nrInmatriculare;
                for(auto p = vehiculeService.begin(); p!= vehiculeService.end(); p++)
                {
                    if(static_cast<Masina*>(*p)->getNrInmatriculare() == nrInmatriculare and typeid(**p) == typeid(Masina))
                    {
                        static_cast<Masina *>(*p)->SoftArabesc();
                        ok = 1;
                    }
                }
                if (ok == 0)
                    cout<<"Masina cu nr de inmatriculare "<<nrInmatriculare<<" nu a fost gasita"<<endl;
                cout<<endl<<"1. Resoftare masina noua"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 2)
                    optiune = menu();
                else
                    optiune = 5;
                break;
            }
            case 6:
            {
                cout<<endl<<"Ati ales optiunea de adaugare a unei motociclete noi"<<endl;
                vehiculeService.push_back(new Motocicleta);
                auto p = vehiculeService.end() - 1;
                cin>>dynamic_cast<Motocicleta*>(*p);
                contorMotocicleteServiceAdaugate++;
                cout<<endl<<"Motocicleta noua a fost adaugata cu succes!";
                cout<<endl<<"1. Adaugati inca o motocicleta noua"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 1)
                    optiune = 6;
                if (optiune == 2)
                    optiune = menu();
                break;
            }
            case 7:
            {
                contor = 0;
                cout<<"Urmatoarele motociclete se afla momentan in Service-ul lui Veriku: "<<endl;
                for(auto p = vehiculeService.begin(); p!= vehiculeService.end(); p++)
                {
                    if(static_cast<Motocicleta*>(*p)->isReparata() == false and typeid(**p) == typeid(Motocicleta))
                        cout<<static_cast<Motocicleta*>(*p);
                    contor++;
                }
                cout<<endl<<"1. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 1)
                    optiune = menu();
                break;
            }
            case 8:
            {
                contor = 0;
                cout<<"Urmatoarele motociclete au fost reparate in Service-ul lui Veriku: "<<endl;
                for(auto p = vehiculeService.begin(); p!= vehiculeService.end(); p++)
                {
                    if(static_cast<Motocicleta*>(*p)->isReparata() == true and typeid(**p) == typeid(Motocicleta))
                        cout<<static_cast<Motocicleta*>(*p);
                    contor++;
                }
                cout<<endl<<"1. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 1)
                    optiune = menu();
                break;
            }
            case 9:
            {
                cout<<endl<<"Ati ales optiunea de a repara motocicleta"<<endl;
                string nrInmatriculare;
                int ok = 0;
                cout<<endl<<"Introduceti numarul de inmatriculare al motocicletei reparate: ";
                cin>>nrInmatriculare;
                for(auto p = vehiculeService.begin(); p!= vehiculeService.end() and contor < nrMotocicleteService; p++)
                {
                    if(static_cast<Motocicleta*>(*p)->getNrInmatriculare() == nrInmatriculare and typeid(**p) == typeid(Motocicleta))
                    {
                        static_cast<Motocicleta*>(*p)->setReparata(true);
                        string tipTransmisie = static_cast<Motocicleta*>(*p)->getTipTransmisie(), marca = static_cast<Motocicleta*>(*p)->getMarca(), model = static_cast<Motocicleta*>(*p)->getModel(), nrInmatriculare = static_cast<Motocicleta*>(*p)->getNrInmatriculare(), culoare = static_cast<Motocicleta*>(*p)->getCuloare();
                        bool reparata = static_cast<Motocicleta*>(*p)->isReparata();
                        int anFabricatie = static_cast<Motocicleta*>(*p)->getAnFabricatie(), caiPutere = static_cast<Motocicleta*>(*p)->getCaiPutere(), distantaRoti = static_cast<Motocicleta*>(*p)->getDistantaRoti(), masaTotala = static_cast<Motocicleta*>(*p)->getMasaTotala();
                        int* auxVector;
                        auxVector = static_cast<Motocicleta*>(*p)->getProbleme();
                        vehiculeReparate.push_back(new Motocicleta(marca, model, anFabricatie, culoare, nrInmatriculare, tipTransmisie, masaTotala, distantaRoti, reparata, auxVector, caiPutere));
                        contorMotocicleteReparateAdaugate++;
                    }
                }
                if (ok == 0)
                    cout<<"Motocicleta cu nr de inmatriculare "<<nrInmatriculare<<" nu a fost gasita"<<endl;
                cout<<endl<<"1. Schimbati statusul unei alte motociclete"<<endl<<"2. Exit submeniu"<<endl<<"0. Exit aplicatie"<<endl;
                cin>>optiune;
                cout<<endl;
                if (optiune == 1)
                    optiune = 8;
                if (optiune == 2)
                    optiune = menu();
                else
                    optiune = 0;
                break;
            }
        }
    }
    scriereFisierReparate(nrMasiniReparate, nrMotocicleteReparate, vehiculeReparate);
    scriereFisierService(nrMasiniService, nrMotocicleteService, vehiculeService);
    cout<<endl<<"O zi buna!\n";
    vehiculeService.clear();
    vehiculeReparate.clear();
    return 0;
}