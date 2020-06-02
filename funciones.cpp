#include <random>

#include "funciones.h"

int aleatorio(){
    return aleatorio(0,2000000);
}

int aleatorio (int inferior, int superior){
    std::random_device dispositivo;
    
    std::uniform_int_distribution<int>distribucion(inferior, superior);
    
    return distribucion(dispositivo);
}

std::vector<int> generarVector(int largo){
    std::vector<int> arreglo;
    for(int i = 0; i < largo; i++){
        int numero = aleatorio();
        arreglo.push_back(numero);
    }
    return arreglo;
}

void imprimirVector(std::vector<int> arreglo){
    std::cout << std::endl << "=== Vector ===" << std::endl;
    for (long unsigned int i = 0; i < arreglo.size();i++){
        std::cout << std::endl << "Vector [" << i << "] = " << arreglo.at(i)<< std::endl;
    }
}

void participantes(){
    std::cout << std::endl << "=== generador ===" << std::endl;
    std::cout << std::endl << "Edgar Matus"; 
    std::cout << std::endl << "Oscar Peñaloza"; 
    std::cout << std::endl << "Daniela Galleguillos" << std::endl; 
}
