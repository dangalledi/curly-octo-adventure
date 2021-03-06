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

void quickSort(std::vector<int>& a, int p,int q);
int partition(std::vector<int>& a, int p,int q);

#endif /* FUNCIONES_H */