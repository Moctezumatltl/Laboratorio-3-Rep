#include "fs.hpp"
#include <math.h>
using namespace std;

//CONSTRUCTOR
Fs::Fs(int _resolucion, float _frec_muestreo, int _canal, float _voltaje_entrada, int _valor_salida, int _ack):ADC(_resolucion, _frec_muestreo, _canal, _voltaje_entrada, _valor_salida){
  //cout<<"Objeto Fs creado"<<endl<<endl;
}
//SETTERS
void Fs::setAck(int _ack){
  ack = _ack;
}

void Fs::setVoltaje(float _voltaje){
  _voltaje_entrada = _voltaje;
}
//GETTERS
void Fs::getFrecM(){
  _frec_muestreo = f_osc/ack;
}

void Fs::getValor(){
  double elevado = pow(2,_resolucion);
  //cout<<elevado<<endl;
  _valor_salida = (_voltaje_entrada*elevado-1)/3.3;
}

//METODOS
void Fs::mostrarDatos(){
  cout<<endl<<"Datos para frecuencia de muestreo de "<<_frec_muestreo<<" MHz"<<endl;
  ADC::mostrarDatos();
}