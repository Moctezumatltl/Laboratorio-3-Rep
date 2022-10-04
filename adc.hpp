#pragma once
#include "adc.hpp"
#include <iostream>
#include <math.h>
/************************************************
*                 CLASE
************************************************/
class ADC{
  private:
    int resolucion;
    float frec_muestreo;
    int canal;
    float voltaje_entrada;
    int valor_salida;

  public:
/*************************************************************
		           CONSTRUCTOR
		***********************************************************/
    //ADC(int, int, int, float, int);
    ADC(int _resolucion, float _frec_muestreo, int _num_canales, float _voltaje, int _valor_salida);
/*************************************************************
		            GETTERS
		***********************************************************/
    int getValor();
    //void getValor(int _resolucion, float _voltaje);
/*************************************************************
		            SETTERS
		***********************************************************/
    void setVoltaje(float);
/*************************************************************
		            MOSTRAR
		***********************************************************/
    virtual void mostrarDatos();

    //void capturar
};