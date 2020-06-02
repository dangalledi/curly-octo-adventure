#include "db.h"

PGconn* conectarDb(char* servidor, int puerto, char* nombredb, char* usuario, char* contrasena){
   PGconn* conexion = NULL;
   
   char* datosConexion = (char*) calloc(256, sizeof(char));
   snprintf(datosConexion, 256, "host='%s' port='%d' dbname='%s' user='%s' password='%s'",
           servidor, puerto, nombredb, usuario, contrasena);
   
   conexion = PQconnectdb(datosConexion);
   if(PQstatus(conexion) == CONNECTION_BAD) {
       fprintf(stderr,"\nNo pude conecrarme al motor : %s", PQerrorMessage(conexion));
        conexion = NULL;      
   }
   free(datosConexion);
   
   return conexion;
}

void desconectarDb(PGconn* conexion){
    PQfinish(conexion);
}

PGresult* consultarDb(PGconn* conexion, char* sql){
    PGresult* resultado = NULL;
    
    if (conexion != NULL && strlen(sql) > 5){
        resultado = PQexec(conexion, sql);
    }
    
    return resultado;
}

long filasAfectadasDb(PGresult* resultado){
    long filas = 0;
    
    if (resultado != NULL){
        char* tuplas = PQcmdTuples(resultado);
        filas = atol(tuplas);
    }
    
    return filas;
}

char* resultadoDb(PGresult* resultado, int fila, int columna){
    char* celda = NULL;
    
    if (resultado != NULL){
        celda = PQgetvalue(resultado, fila, columna);
    }
    
    return celda;
}

void liberarResultadoDb(PGresult* resultado){
    PQclear(resultado);
}