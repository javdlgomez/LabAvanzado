/*
 * ROOT script for read PAA files
 * 
 * @author: Héctor Pérez
 * date: 04/08/2020
 * 
 * collab by Javier de Leon
 * Added a way to detect double pulses of the dataset
 * Added a way to graph individual and collective
 * histograms of the time that it takes to make
 * a double pulse and compare them with an expo fit
 * 
 * 
 * 
 * Usage:
 * 1. Load this file into root with .L
 * 2. Call the function GetPAAPulse( "FileName.paa", <pulse number> );
 * 3. Call void GetAllPulses("FileName.paa")
 * 4. Call void GetAllPulses2("FileName.txt")
 * 
 *
 */ 

#include "TGraph.h"
#include "TCanvas.h"
#include <cassert>
#include <cmath>
 
#include "TH1.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TRandom.h"
 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


//hacemos una lista que van a ser los valores que alimentan el histograma

std::list<int> lista_valores_histograma;

void Histograma()
{
    TH1* h = new TH1D("Datos Medidos", "Histogram;Tiempo (ns);Frecuencia", lista_valores_histograma.size(), lista_valores_histograma.front(), lista_valores_histograma.back());
    
    for (auto val : lista_valores_histograma)
    {
        h->Fill(val);
    }
    
    // dibujamos el histograma
    TCanvas* c = new TCanvas;
    c->cd(1);
    h->Draw();
    //hacemos el fit exponencial
    TFitResultPtr r = h->Fit("expo", "S");
    h->Draw();
    c->Update();
    r->Print("V");
}

void GetPAAPulse(const char* PAAFileName, Int_t PulseNumber, bool graph)
{
    std::ifstream PAAFile(PAAFileName, std::ios::in | std::ios::binary );
    
    if(!PAAFile)
    {
        //std:cout << "Error openning file: " << PAAFileName << std::endl;
        return;
    }

    char ReadBuffer[512];

    PAAFile.getline(ReadBuffer,8);

    if( strcmp(ReadBuffer,"PAA 01") != 0 )
    {
        //std:cout << "Invalid file type" << std::endl;
        return;
    }

    PAAFile.seekg(8);
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;

    //std:cout << std::endl;

    PAAFile.seekg(524);
    uint32_t ps;
    PAAFile.read( (char*)&ps, 4);
    //std:cout << "Points per pulse: " << ps << std::endl;
    uint32_t pc;
    PAAFile.read( (char*)&pc, 4);
    //std:cout << "Pulses in this file: " << pc << std::endl;
    int32_t tl;
    PAAFile.read( (char*)&tl, 4);
    tl = -750;
    //std:cout << "Threshold level: " << tl << std::endl;

    if( ( PulseNumber < 0 ) || ( PulseNumber > (pc-1) ))
    {
        //std:cout << "Error: Bad pulse number" << std::endl;
        return;
    }
    
    uint32_t offset = 640 + 2*ps*PulseNumber;
    PAAFile.seekg( offset );
    Int_t pulse_data_v[ps];
    Int_t pulse_data_t[ps];
    uint16_t ipoint;

    // Hacemos esto para guardar solo eventos modulo 2

    int first = -1, second = -1;
    FILE *fptr;
    fptr = fopen("data.txt","a");

    for( int i = 0 ; i < ps; i++ )
    {
        PAAFile.read( (char*)&ipoint, 2);
        if( ipoint > 8191 )
            pulse_data_v[i] = ipoint - 16384;
        else
            pulse_data_v[i] = ipoint;
        pulse_data_t[i] = i;
        if(pulse_data_v[i] < tl)
        {
            Int_t lower = pulse_data_v[i];


            // hacemos esto para depurar los eventos
            //que son continuos debido a que corresponden al 
            //mismo pulso, colocamos un tiempo miniom de 25 ticks

            while(pulse_data_v[i] < tl){

                if(pulse_data_v[i] < lower){
                    lower = pulse_data_v[i];

                }

                i++;

                PAAFile.read( (char*)&ipoint, 2);

                if( ipoint > 8191 )
                    pulse_data_v[i] = ipoint - 16384;
                else
                    pulse_data_v[i] = ipoint;

                pulse_data_t[i] = i;

            }

            //std:cout << "Lower: " << std::endl; 
            //std:cout << lower << std::endl; 
            //std:cout << "Poisition: " << std::endl; 
            //std:cout << i << std::endl; 

            if(first == -1){ 

                first = i;
            }
            else if(second == -1 && i > first + 25){ 

                second = i;
            }
            
            if(first != -1 && second != -1){ 

                //fprintf(fptr,"%i, ", PulseNumber);
                //fprintf(fptr,"%i, ", first);
                //fprintf(fptr,"%i, ", second);
                int val = (second-first)*8;
                fprintf(fptr,"%i\n", val);
                lista_valores_histograma.push_back(val);

                first = -1;
                second = -1;
            }
        }
    }

    fclose(fptr);

    if(graph){
        TGraph *Pulse = new TGraph( ps, pulse_data_t, pulse_data_v);
        
        TCanvas *ShowGraph = new TCanvas("Pulse", "RP aqcuire tools: ROOT script", 600, 400);
        Pulse->Draw("AC*");
        ShowGraph->Update();

    }
    

    PAAFile.close();
}

//este metodo evalua todos las lineas de un archivo .paa

void GetAllPulses(const char* PAAFileName)
{
    std::ifstream PAAFile(PAAFileName, std::ios::in | std::ios::binary);
    
    if(!PAAFile)
    {
        //std:cout << "Error openning file: " << PAAFileName << std::endl;auto
        return;
    }

    char ReadBuffer[512];

    PAAFile.getline(ReadBuffer,8);

    if( strcmp(ReadBuffer,"PAA 01") != 0 )
    {
        //std:cout << "Invalid file type" << std::endl;
        return;
    }

    PAAFile.seekg(8);
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;
    PAAFile.getline(ReadBuffer,512);
    //std:cout << ReadBuffer << std::endl;

    //std:cout << std::endl;

    PAAFile.seekg(524);
    uint32_t ps;
    PAAFile.read( (char*)&ps, 4);
    //std:cout << "Points per pulse: " << ps << std::endl;
    uint32_t pc;
    PAAFile.read( (char*)&pc, 4);
    //std:cout << "Pulses in this file: " << pc << std::endl;
    int32_t tl;
    PAAFile.read( (char*)&tl, 4);
    tl = -150;
    //std:cout << "Threshold level: " << tl << std::endl;

    PAAFile.close();

    lista_valores_histograma.clear();
    for(int i = 0; i < pc; i++){
        
        GetPAAPulse(PAAFileName, i, false);
    }
    lista_valores_histograma.sort();

    //hacemos el histograma
    Histograma();
}

//este metodo grafica la base de datos total

void GetAllPulses2(const char* PAAFileName)
{
    std::ifstream infile(PAAFileName);
    
    lista_valores_histograma.clear();

    int val;

    while (infile >> val)
    {
        lista_valores_histograma.push_back(val);
    }
    lista_valores_histograma.sort();

    //hacemos el histograma
    Histograma();
}