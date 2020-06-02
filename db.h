#ifndef DB_H
#define DB_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <postgresql/libpq-fe.h>

/**
 * 
 * @param servidor
 * @param puerto
 * @param nombredb
 * @param usuario
 * @param contraseña
 * @return 
 */
PGconn* conectarDb(char* servidor, int puerto, char* nombredb, char* usuario, char* contrasena);

/**
 * 
 * @param conexion
 */
void desconectarDb(PGconn* conexion);

/**
 * 
 * @param conexion
 * @param sql
 * @return 
 */
PGresult* consultarDb(PGconn* conexion, char* sql);

/**
 * 
 * @param resultado
 * @return 
 */
long filasAfectadasDb(PGresult* resultado);

/**
 * 
 * @param resultado
 * @param fila
 * @param coluumna
 * @return 
 */
char* resultadoDb(PGresult* resultado, int fila, int columna);

/**
 * 
 * @param resultado
 */
void liberarResultadoDb(PGresult* resultado);

#endif /* DB_H */

