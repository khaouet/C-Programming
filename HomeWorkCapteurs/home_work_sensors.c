/**
  * ---------------------------------------------------------------------------
  * @Source file : home_work_sensor_ts.c
  * @Author      : Khaled HAOUET
  * @Class       : L1-GEx
  * @Brief       :
  * @description :
  *
  *
  *
  * ---------------------------------------------------------------------------
  */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#define MAX_NB_SENSORS 10




typedef struct sensor_s sensor_t;

typedef enum {
    TEMP_SENSOR,
    PRESSURE_SENSOR,
    CURRENT_SENSOR
} sensor_type_id_t;

const char* Sensors_types[] = {"Temperature","Pressure","Current"};

struct sensor_s {
    int id;
    int type_id; // Temperature, Pressure, Current
    float value;
    int status;  // actif = 1 inactive = 0

};



// Functions declarations

void Saisir_Sensors(sensor_t* t, int size);
void affiche(sensor_t* t,int size ); // affiche tous les capteurs
void print_sensor(const sensor_t *p); // affiche les propriétés d'un seul capteur
void update_sensor(sensor_t *p, float value);
float moyenne_sensor(sensor_t *p, int size, sensor_type_id_t type_id);

int main()
{
    int nb_sensors;
    printf("%s\n",Sensors_types[TEMP_SENSOR]);
    printf("%s\n",Sensors_types[PRESSURE_SENSOR]);
    printf("%s\n",Sensors_types[CURRENT_SENSOR]);

    sensor_t mySensors[MAX_NB_SENSORS];
    printf("Nombre de capateurs:");
    scanf("%d",&nb_sensors);
    Saisir_Sensors(mySensors, nb_sensors);
    affiche(mySensors,nb_sensors );
    //update_sensor(&mySensors[0],100.0);
    float temp_moyenne = moyenne_sensor(mySensors,nb_sensors,TEMP_SENSOR);
    printf("%f",temp_moyenne);
    return 0;
}

// Functions Definitions
// un tableau en C c'est un pointeur constant sur son premier élément

//void Saisir_Sensors(sensor_t t[], int size)
//{
//    for(int i = 0 ; i < size ; i++ )
//    {
//        printf("Saisir capteur %d: ", i+1);
//        t[i].id = i+1;
//        printf("Saisir Type: ");
//        scanf("%s",t[i].type);
//        printf("Saisir valeur %s : ",t[i].type);
//        scanf("%f",&t[i].value);
//        t[i].status = 1;
//    }
//}

//void Saisir_Sensors(sensor_t* p, int size)
//{
//    for(int i = 0 ; i < size ; i++ )
//    {
//        printf("Saisir capteur %d: ", i+1);
//        (p+i)->id = i+1;
//        printf("Saisir Type: ");
//        scanf("%s",&(p+i)->type);
//        printf("Saisir valeur %s : ",(p+i)->type);
//        scanf("%f",&(p+i)->value);
//        (p+i)->status = 1;
//
//    }
//}

void Saisir_Sensors(sensor_t* p, int size)
{
    for(int i = 0 ; i < size ; i++  )
    {
        int type_id;
        printf("Saisir capteur %d: ", i+1);
        p->id = i+1;
        printf("Saisir Type (0-> Temperature, 1-> Pressure, 2-> Current) :");
        scanf("%d",&p->type_id);
        printf("Saisir valeur %s : ",Sensors_types[p->type_id]);
        scanf("%f",&p->value);
        p->status = 1;
        p++;
    }
}


void affiche(sensor_t t[],int size )
{
    sensor_t *p = t;
    for(int i = 0 ; i < size ; i++ )
    {
        //printf("[id:%d, Type=%s, Valeur:%0.2f, Etat:%s]\n",t[i].id,t[i].type,t[i].value,(t[i].status)?"Actif":"Inactif");
        print_sensor(p);
        p++;

    }
}



void print_sensor(const sensor_t *p)
{
    printf("[id:%d, Type=%s, Valeur:%0.2f, Etat:%s]\n",p->id,Sensors_types[p->type_id],p->value,(p->status)?"Actif":"Inactif");
}


void update_sensor(sensor_t *p, float val)
{
    p->value = val;
}

//
float moyenne_sensor(sensor_t *p, int size, sensor_type_id_t my_type_id)
{
    float moy = 0;
    int count_sensor_type = 0;
    for(int i=0 ; i < size; i++, p++)
    {
        if (p->type_id == my_type_id)
        {
            moy+= p->value;
            count_sensor_type++;
        }
    }
    if(count_sensor_type != 0)
        return moy/count_sensor_type;
    return FLT_MAX ;
}
