#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
#define MAAX 3

int main(){
    char estudiantes[MAX][50];
    char asignaturas[MAAX][50];
    float promedios[MAX];
    float promasig[MAX][MAAX] = {0};
    int opcion;
    int canestu = 0;
    int canaasig = 0;
    int i, j, k;
    float nota = 0.0;
    float calif[MAX][MAAX] = {0};
    int idestu, notin, notgru;
    int idasig;
    float promin = 0.0;
    float sumin = 0.0;
    float progru = 0.0;
    float sumgru = 0.0;
    float notamax = 0.0;
    float notamin = 10.0;
    int mejor, peor;
    int aprobados = 0;
    int reprobados = 0;
    do{
        printf("¡Bienvenido!\n");
        printf("---Sistema de registro y calculo de calificaciones---\n");
        printf("(1) Registro de estudiantes\n");
        printf("(2) Registro de asignaturas\n");
        printf("(3) Registro de calificaciones\n");
        printf("(4) Promedio de calificacines por estudiante\n");
        printf("(5) Promedio de calificaciones por asignatura\n");
        printf("(6) Estudiantes con promedio general más alto y más bajo\n");
        printf("(7) Estudiantes con calificación más alta y más baja en cada asignatura\n");
        printf("(8) Estudiantes aprobados y reprobados en cada asignatura\n");
        printf("(9) Salir del programa\n");
        printf("\nIngrese lo que desea realizar(1-9)\n");
        scanf("%d", &opcion);
        
        switch(opcion){
            
        case 1:
            printf("==Registrar Estudiantes==\n");
            if(canestu < MAX){
                printf("Ingrese nombre del estudiante: \n");
                scanf(" %[^\n]", &estudiantes[canestu]);
                canestu++;
                printf("¡Estudiante registrado con éxito!\n");
            }
            else{
                printf("Error, cantidad máxima de registros alcanzada\n");
            }
            break;
        case 2:
            printf("==Registrar Asignaturas==\n");
            if(canaasig < MAAX){
                printf("Ingrese la asignatura: \n");
                scanf(" %[^\n]", &asignaturas[canaasig]);
                canaasig++;
                printf("¡Asignatura registrada con éxito!\n");
            }
            else{
                printf("Error, cantidad máxima de registros alcanzada\n");
            }
            break;
        case 3:
            printf("==Registrar calificaciones==\n");
            if(canestu == 0 || canaasig == 0){
                printf("Proceso no posible\n");
                printf("Sin datos registrados\n");
                break;
            }
            printf("--Selecciones el estudiante que desea asignar una nota--\n");
            for(i = 0; i < canestu; i++){
                printf("(%d) %s\n", i + 1, estudiantes[i]);
            }
            printf("Opción: \n");
            scanf("%d", &idestu);
            idestu--;
            printf("--Selecciones la asignatura--\n");
            for(j = 0; j < canaasig; j++){
                printf("(%d) %s\n", j + 1, asignaturas[j]);
            }
            printf("Opción: \n");
            scanf("%d", &idasig);
            idasig--;
            if(idestu >= 0 && idestu < canestu && idasig < canaasig && idasig >= 0){
                printf("Ingrese calificación: \n");
                scanf("%f", &nota);
                while(nota < 0 || nota > 10){
                    printf("Error en lectura\n");
                    printf("Ingrese una calificación de 0-10\n");
                    scanf("%f", &nota);
                }
                calif[idestu][idasig] = nota;
                promasig[idestu][idasig] = nota;
                printf("¡Calificación registrada exitosamente!\n");
            }
            else{
                printf("Proceso no posible\n");
                printf("Error en seleccion de estudiante o asignatura\n");
            }
            break;
        case 4:
            printf("==Promedio de nota por estudiante==\n");
            promin = 0;
            sumin = 0;
            if(canestu == 0 || canaasig == 0){
                printf("Proceso no posible\n");
                printf("Sin datos registrados\n");
                break;
            }
            printf("\n--Selecciones el estudiante que desea hacer promedio de notas--\n");
            for(i = 0; i < canestu; i++){
                printf("(%d) %s\n", i + 1, estudiantes[i]);
            }
            printf("Opción: \n");
            scanf("%d", &notin);
            notin--;
            if(notin >= 0 && notin < canestu){
                printf("\nNotas de %s: \n", estudiantes[notin]);
                printf("====================================\n");
                for(k = 0; k < canaasig; k++){
                    printf("- %s: %.2f\n", asignaturas[k], calif[notin][k]);
                    sumin += calif[notin][k];
                }
                promin = sumin / canaasig;
                promedios[notin] = promin;
                printf("Promedio General: %.2f\n", promin);
            }
            else{
                printf("\nError: Estudiante no válido\n");
            }
            
            break;
        case 5:
            progru = 0;
            sumgru = 0;
            printf("==Promedio General de estudiantes==\n");
            if(canestu == 0 || canaasig == 0){
                printf("Proceso no posible\n");
                printf("Sin datos registrados\n");
                break;
            }
            
            printf("--Selecciones la asignatura--\n");
            for(j = 0; j < canaasig; j++){
                printf("(%d) %s\n", j + 1, asignaturas[j]);
            }
            printf("Opción: \n");
            scanf("%d", &idasig);
            idasig--;
            
            printf("\n--Estudiantes de los que se realiza el promedio de calificaciones--\n");
            if(idasig >= 0 && idasig < canaasig){
                for(i = 0; i < canestu; i++){
                    printf("(%d) %s nota: %.2f\n", i + 1, estudiantes[i], calif[i][idasig]);
                    sumgru += calif[i][idasig];
                }
                progru = sumgru / canestu;
                printf("====================================================\n");
                printf("El promedio general de la materia es: %.2f\n", progru);
            }
            break;
        case 6:
            printf("==Promedio general más alto y más bajo==\n");
            if(canestu == 0 || canaasig == 0){
                printf("Proceso no posible\n");
                printf("Sin datos registrados\n");
                break;
            }
            for(i = 0; i < canestu; i++){
                if(promedios[i] > notamax){
                    notamax = promedios[i];
                    mejor = i;
                }
                if(promedios[i] < notamin){
                    notamin = promedios [i];
                    peor = i;
                }
            }
            printf("El estudiante con mejor promedio es: %s\n Nota: %.2f\n", estudiantes[mejor], notamax);
            printf("El estudiante con peor promedio es: %s\n Nota: %.2f\n", estudiantes[peor], notamin);
            break;
        case 7:
            printf("==Promedio general más alto y más bajo por asignatura==\n");
            if(canestu == 0 || canaasig == 0){
                printf("Proceso no posible\n");
                printf("Sin datos registrados\n");
                break;
            }
            printf("--Selecciones la asignatura--\n");
            for(j = 0; j < canaasig; j++){
                printf("(%d) %s\n", j + 1, asignaturas[j]);
            }
            printf("Opción: \n");
            scanf("%d", &idasig);
            idasig--;
            for(i = 0; i < canestu; i++){
                if(promasig[i][idasig] > notamax){
                    notamax = promasig[i][idasig];
                    mejor = i;
                }
                if(promasig[i][idasig] < notamin){
                    notamin = promasig[i][idasig];
                    peor = i;
                }
            }
            printf("El estudiante con mejor promedio en la asignatura es: %s\n Nota: %.2f\n", estudiantes[mejor], notamax);
            printf("El estudiante con peor promedio en la asignatura es: %s\n Nota: %.2f\n", estudiantes[peor], notamin);
            break;
        case 8:
            printf("==Aprobados y Reprobados por asignatura==\n");
            if(canestu == 0 || canaasig == 0){
                printf("Proceso no posible\n");
                printf("Sin datos registrados\n");
                break;
            }
            printf("--Selecciones la asignatura--\n");
            for(j = 0; j < canaasig; j++){
                printf("(%d) %s\n", j + 1, asignaturas[j]);
            }
            printf("Opción: \n");
            scanf("%d", &idasig);
            idasig--;
            for(i = 0; i < canestu; i++){
                if(promasig[i][idasig] >= 6){
                    aprobados++;
                }
                else{
                    reprobados++;
                }
            }
            printf("La cantidad de alumnos aprobados son: %d\n", aprobados);
            printf("La cantidad de alumnos reprobados son: %d\n", reprobados);
            break;
        case 9:
            printf("---Saliendo del programa---\n");
            exit(0);
        default:
            printf("Error en lectura\n");
            printf("Opción no disponible\n");
            break;
        }
        
    }while(opcion != 9);
    return 0;
}