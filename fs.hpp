#pragma once
#include "adc.hpp"
#include <iostream>

class Fs: public ADC{
  private:
    int _resolucion;
    float _frec_muestreo;
    int _canal;
    float _voltaje_entrada;
    int _valor_salida;
    int f_osc = 8;
    int ack;
  public:
//CONSTRUCTOR
    Fs(int _resolucion = 0, float _frec_muestreo = 0, int _canal = 0, float _voltaje_entrada = 0, int _valor_salida = 0, int _ack = 0);
//SETTERS
    void setVoltaje(float _voltaje);
    void setAck(int _ack);
//GETTERS
    void getValor();
    void getFrecM();
//METODOS
    void mostrarDatos();
    
};