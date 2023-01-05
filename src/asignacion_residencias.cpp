#include "../include/asignacion_residencias.h"
#include "../include/cola.h"
#include <cstddef>

Asignacion asignarResidencias(nat m, nat* C, nat n, nat** hPrefs, nat** ePrefs){
  Asignacion resultado = crear_asignacion();
  nat** rankingDeEstudiante = new nat*[n];
  for (nat i = 0; i < n; i++){
    rankingDeEstudiante[i] = new nat[m];
    for (nat j = 0; j < m; j++){
      rankingDeEstudiante[i][ePrefs[i][j]] = j; 
    }
  }
  
  nat* parejaDeEstudiante = new nat[n]; //guarda el inidice del hospital que es pareja de e si no tiene guarda m.
  for (nat i = 0; i < n; i++){
    parejaDeEstudiante[i] = m;
  }
    
  //Me indica que hospitales tengo que revisar todavia, tambien me da la condición de parada diciendome que tengo que revisar hasta que esto este vacio.
  Cola hospitalesPorRevisar = crear_cola();
  for (nat i = 0; i < m; i++){
    encolar(i, hospitalesPorRevisar);
  }

  //Me indica a quienes ya le propuse es decir cuales lugares de la fila de la matriz de hospitales voy revisando para ese hospital
  nat* siguienteParaProponer = new nat[m];
  for (nat i = 0; i < m; i++){
    siguienteParaProponer[i] = 0;
  }
    
  while (!es_vacia_cola(hospitalesPorRevisar)){
    nat h = frente(hospitalesPorRevisar);
    if (C[h] != 0){
      nat eAlQueVoyAProponer = hPrefs[h][siguienteParaProponer[h]];
      if(parejaDeEstudiante[eAlQueVoyAProponer] == m){ //la m es mi variable de control para indicar que esta free
        parejaDeEstudiante[eAlQueVoyAProponer] = h;
        siguienteParaProponer[h]++; //Indico que es el siguiente en la lista para proponer
        C[h]--; //Le saco un cupo a h
      }else{ 
        if (rankingDeEstudiante[eAlQueVoyAProponer][parejaDeEstudiante[eAlQueVoyAProponer]] < rankingDeEstudiante[eAlQueVoyAProponer][h] ){//Aca va si quiere al que tiene sobre h   
          siguienteParaProponer[h]++;
        }else{
          nat hActual = parejaDeEstudiante[eAlQueVoyAProponer];
          if(C[hActual]== 0) encolar(hActual, hospitalesPorRevisar); //Si no tenia cupos ahora tiene 1 lo agrego a la cola de hospitales por revisar.
          C[hActual]++; //le suma un cupo al hActual el que se acaba de liberar
          C[h]--;
          siguienteParaProponer[h]++;
            
          parejaDeEstudiante[eAlQueVoyAProponer] = h; //actualiza la pareja actual del estudiante
        }
      }
    }else{//Probablemente tenga que desencolar en este else
      desencolar(hospitalesPorRevisar);
    }
  }//while

  for (nat i = 0; i < n; i++){
    nat n1 = i;
    nat n2 = parejaDeEstudiante[i];
    par p = {n1, n2};
    if(n2 != m)
      insertar_par(p, resultado);
  }
  for (nat i = 0; i < n; i++){
    delete [] rankingDeEstudiante[i];
  }
  delete [] rankingDeEstudiante;
  delete [] parejaDeEstudiante;
  delete [] siguienteParaProponer;
  destruir_cola(hospitalesPorRevisar);
    
  return resultado; // se debe retornar algo de tipo asignacion
}
