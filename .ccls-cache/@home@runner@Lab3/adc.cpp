#include "adc.hpp"
using namespace std;
/************************************************
*                  CONSTRUCTOR 
************************************************/
ADC::ADC(int _resolucion, float _frec_muestreo, int _canal, float _voltaje_entrada = 0, int _valor_salida = 0){
  resolucion = _resolucion;
  frec_muestreo = _frec_muestreo;
  canal = _canal;
  voltaje_entrada = _voltaje_entrada;
  valor_salida = _valor_salida;
}

/************************************************
*                  GETTERS
************************************************/
int ADC::getValor(){
  double elevado = pow(2,resolucion);
  //cout<<elevado<<endl;
  valor_salida = (voltaje_entrada*elevado-1)/3.3;
  return valor_salida;
}

/************************************************
*                  SETTERS
************************************************/
void ADC::setVoltaje(float _voltaje_entrada){
  voltaje_entrada = _voltaje_entrada;
}
/************************************************
*                  MOSTRAR
************************************************/
void ADC::mostrarDatos(){
  cout<<endl;
  cout<<"Resolucion del ADC "<<resolucion<<" bits"<<endl;
  cout<<"Frecuencia de muestreo del ADC "<<frec_muestreo<<" MHz"<<endl;
  cout<<"Canal activo AN"<<canal<<endl;
  cout<<"Voltaje de entrada: "<<voltaje_entrada<<" V"<<endl;
  cout<<"Valor convertido: "<<ADC::getValor()<<endl;
}