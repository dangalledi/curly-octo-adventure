#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <random>

/**
 * 
 * @return un número entero aleatorio
 */
int aleatorio();

/**
 * 
 * @param inferior Limite inferior
 * @param superior Limite superior
 * @return un número aleatorio entre el rango
 */
int aleatorio (int inferior, int superior);

/**
 * 
 * @param largo Tamaño del arreglo de entrada
 * @return un vector con números aleatorios
 */
std::vector<int> generarVector(int largo);

/**
 * Imprime en la salida estándar un vector
 * @param arreglo Vector a mostrar
 */
void imprimirVector(std::vector<int> arreglo);

/**
 * Funcion que muestra los participantes del grupo
 */
void participantes();

std::vector<int> particion(std::vector<int> arreglo, int izquierda, int derecha);

void intercambiar(int *a, int *b);

void quicksort(std::vector<int> arreglo, int izquierda, int derecha);

#endif /* FUNCIONES_H */