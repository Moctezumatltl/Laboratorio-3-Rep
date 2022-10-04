/******************************************************************************
 // FileName:        main.cpp
 // Program version: Replit
 // Company:         TECNM - ITCH
 // Description:     Laboratorio 3: Simulacion de un ADC
 // Authors:         CESAR GONZALEZ
 // Updated:         10/2022
 // Nota:            
 //            
******************************************************************************/

#include <iostream>
#include "adc.hpp"
#include "fs.hpp"
using namespace std;

void portadaLab();
int main(int argc, char** argv) {
  int opcion;
  int resolucion;
  float frec_muestreo;
  int ack;
  int canales;
  int ch[32];
  int error = 0;
  portadaLab();
  cout<<"Simulador de ADC"<<endl<<endl;
  
  do{
    cout<<"Desea ingresar la frecuencia de muestreo manualmente(Opcion 3) o ingresar el factor ACK para una frecuencia de oscilacion fija de 8MHz(Opcion 4): ";cin>>opcion;
    if(opcion == 3 || opcion == 4) error = 0;
    else{
      cout<<"ERROR, introduzca 3 o 4"<<endl;
        error = 1;
    }
  }while(error);
  //VALIDACION DE ENTRADA DE DATOS DE LA RESOLUCION DEL ADC
  do{
      cout<<"Inserte la resolucion del ADC (8, 10 o 12 bits): ";cin>>resolucion;
      if(resolucion == 8 || resolucion == 10 || resolucion == 12){
        error = 0;
      }
      else{
        cout<<"ERROR al introducir la resolucion, debe ser 8, 10 o 12 bits"<<endl;
        error = 1;
      }
  }while(error);
  //VALIDACION ENTRADA DE DATOS DE LA FRECUENCIA DE MUESTREO
  if(opcion == 3){
    do{
      cout<<"Frecuencia de muestreo en MHz: ";cin>>frec_muestreo;
      if(frec_muestreo>0){
        error = 0;
      }
      else{
        cout<<"ERROR al introducir la frecuencia de muestreo, debe ser > 0"<<endl;
        error = 1;
      }
    }while(error);
  }
  else if (opcion == 4){
    do{
      cout<<"Factor ACK para una f_osc de 8MHz: ";cin>>ack;
      if(ack == 2 || ack == 4 || ack == 8 || ack == 16 || ack == 32 || ack == 64){
        error = 0;
      }
      else{
        cout<<"ERROR, introduzca 2, 4, 8, 16, 32 o 64"<<endl;
        error = 1;
      }
    }while(error);
  }
  //VALIDACION ENTRADA DE DATOS DE LOS CANALES A USAR
  do{
      cout<<"Cantidad de canales a usar: ";cin>>canales;
      if(canales>=1 && canales<=32){
        error = 0;
      }
      else{
        cout<<"ERROR al introducir cantidad de canales, debe ser mayor que 1 y menor que 32"<<endl;
        error = 1;
      }
  }while(error);

  //CICLO FOR PARA GUARDAR EN UN ARREGLO CUALES CANALES SE VAN A USAR PARA LA LECTURA
  for(int i = 0; i < canales; i++){
    //VALIDACION DE DATOS DEL CANAL A UTILIZAR
    do{
      cout<<"Canal a utilizar (AN1 - AN32) Favor de introducir solo el numero: ";cin>>ch[i];
      if(ch[i]>=1 && ch[i]<=32) error = 0;
      else{
        cout<<"ERROR al introducir un canal, debe ser del AN1 al AN32"<<endl;
        error = 1;
      }
    }while(error);
    
  }

  float voltaje[32];
  //ADQUISICION DE VOLTAJES PARA CONVERSION
  for(int i=0; i<canales; i++){
    do{
      cout<<"Introduce el voltaje a leer del canal AN"<<i+1<<" (0 - 3.3V): ";cin>>voltaje[i];
      if(voltaje[i]>=0 && voltaje[i]<=3.3) error = 0;
      else{
        cout<<"ERROR al introducir un voltaje, debe estar entre 0 y 3.3V"<<endl;
        error = 1;
      }
  }while(error);
  }
  
  //for(int i = 0; i<canales; i++){
    

  //CREACION DE OBJETOS
  ADC *AN[32];
  Fs *_AN[32];
  if(opcion == 3){
    for(int i = 0; i<canales; i++){
    AN[i] = new ADC(resolucion, frec_muestreo, ch[i], voltaje[i],0);
    AN[i]->mostrarDatos();
    }
  }

  else if(opcion == 4){
    frec_muestreo = 8/ack;
    for(int i = 0; i<canales; i++){
    _AN[i] = new Fs(resolucion, frec_muestreo, ch[i], voltaje[i], 0, ack);
    _AN[i]->setAck(ack);
    _AN[i]->getFrecM();
    _AN[i]->mostrarDatos();
    }
  }
  /*
    if(opcion == 3){
      AN[i]->setVoltaje(voltaje);
      AN[i]->getValor();
      
    }
    else if(opcion == 4){
      _AN[i]->setAck(ack);
      _AN[i]->getFrecM();
      _AN[i]->setVoltaje(voltaje);
      _AN[i]->getValor();
      _AN[i]->mostrarDatos();
    }

  }*/
  for(int i = 0; i<canales; i++){
    if(opcion==3)
      delete AN[i];
    if(opcion==4)
      delete _AN[i];
  }
}

void portadaLab(){
  cout<<"\n              INSTITUTO TECNOLOGICO DE CHIHUAHUA\n\n";
  cout<<"\n                    INGENIERIA ELECTRONICA\n";
  cout<<"        ESPECIALIDAD EN SISTEMAS EMBEBIDOS INTELIGENTES\n\n";
  cout<<"\n     ARQUITECTURA DE PROGRAMACION PARA CONTROL DE HARDWARE\n\n";
  cout<<"\n          LABORATORIO 3.- POO HERENCIA Y POLIMORFISMO\n\n\n";
  cout<<"\nALUMNO: Cesar Alonso Gonzalez Hernandez\n";
  cout<<"\nNC: 19060752\n";
  cout<<"\nDOCENTE: M.C. Alfredo Chacon\n";
  cout<<"\nFECHA: 03 de octubre de 2022\n\n\n\n";
  
}