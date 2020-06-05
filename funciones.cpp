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

std::vector<int> particion(std::vector<int> arreglo, int izquierda, int derecha) {
  // Elegimos el pivote, es el primero
  int pivote = arreglo[izquierda];
  // Ciclo infinito
  while (1) {
    // Mientras cada elemento desde la izquierda esté en orden (sea menor que el
    // pivote) continúa avanzando el índice
    while (arreglo[izquierda] < pivote) {
      izquierda++;
    }
    // Mientras cada elemento desde la derecha esté en orden (sea mayor que el
    // pivote) continúa disminuyendo el índice
    while (arreglo[derecha] > pivote) {
      derecha--;
    }
    /*
    Si la izquierda es mayor o igual que la derecha significa que no
    necesitamos hacer ningún intercambio
    de variables, pues los elementos ya están en orden (al menos en esta
    iteración)
    */
    if (izquierda >= derecha) {
      // Indicar "en dónde nos quedamos" para poder dividir el arreglo de nuevo
      // y ordenar los demás elementos
      return derecha;
    } else {//Nota: yo sé que el else no hace falta por el return de arriba, pero así el algoritmo es más claro
      /*
      Si las variables quedaron "lejos" (es decir, la izquierda no superó ni
      alcanzó a la derecha)
      significa que se detuvieron porque encontraron un valor que no estaba
      en orden, así que lo intercambiamos
      */
      intercambiar(&arreglo[izquierda], &arreglo[derecha]);
      /*
      Ya intercambiamos, pero seguimos avanzando los índices
      */
      izquierda++;
      derecha--;
    }
    // El while se repite hasta que izquierda >= derecha
  }
}

void intercambiar(int *a, int *b) {
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

void quicksort(std::vector<int> arreglo, int izquierda, int derecha) {
  if (izquierda < derecha) {
    int indiceParticion = particion(arreglo, izquierda, derecha);
    quicksort(arreglo, izquierda, indiceParticion);
    quicksort(arreglo, indiceParticion + 1, derecha);
  }
}