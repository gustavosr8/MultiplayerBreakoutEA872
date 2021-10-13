#include "../include/view.h"
#include "../include/controller.h"
#include "../include/tijolo.h"
#include "../include/bolinha.h"
#include "../include/barra.h"
#include "../include/pontos.h"
#include "../include/vida.h"
#include "../include/container.h"
#include "../include/json.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using nlohmann::json;
using std::cout; using std::cin;
using std::endl; using std::string;

int main(){
    
    //Inicializa os objetos da aplicação
    
    //Tijolos
    std::vector<tijolo> t;
    
    int k = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 1; j < 2; j++){
            tijolo NewTijolo(i, j);
            t.push_back(NewTijolo);
        }
    }


    container cntr;
    cntr.t = t;

    json j;
    j["Container"] = cntr;
    std::ofstream f;
    f.open("teste2.json");
    f << j;
    f.close();

    t.erase(t.begin()+5);

    for(int i=0; i<t.size(); i++){
        
        cout << "T[" << i << "]  x:" << t[i].getX() << "  y:"<< t[i].getY() << endl;
    } 

    std::ifstream f2;
    f2.open("teste2.json");
    f2 >> j;
    f2.close();
    cntr = j["Container"];
    t = cntr.t;

    for(int i=0; i<t.size(); i++){
        
        cout << "T[" << i << "]  x:" << t[i].getX() << "  y:"<< t[i].getY() << endl;
    } 

    return 0;
}