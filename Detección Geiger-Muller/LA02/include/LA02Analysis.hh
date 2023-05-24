/* 
 * LA02Analysis.hh: Header para la clase
 * LA02Analysis.
 * 
 * Archivo de ejemplo de Geant4 para la unidad 3
 * del curso de Laboratorio Avanzado ECFM-USAC
 * 
 * Héctor Pérez
 * abril 2021
 * 
 * Basado en el ejemplo B1 y B4 de Geant4.10.06.p03
 */

#ifndef LA02Analysis_h
#define LA02Analysis_h 1
/* includes para versiones previas a 11 de geant4 */
//#include "g4root.hh"
//#include "g4xml.hh"
//#include "g4csv.hh"
//#include "g4hdf5.hh"
/* para la version 11 o posterior de geant4 */

#include "G4CsvAnalysisManager.hh"

using G4AnalysisManager = G4CsvAnalysisManager;

#endif
