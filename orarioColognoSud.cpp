//COLOGNO SUD
#include <chrono>
#include <ctime>    
#include <time.h>
#include<iostream>
#include<string>
using namespace std;


int weekDay(){
    // Ottieni l'orario corrente
    auto now = chrono::system_clock::now();

    // Ottieni il tempo corrente come un oggetto std::tm
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm now_tm = *localtime(&now_c);

    // Estrai il giorno della settimana dall'oggetto std::tm
    int dayOfWeek = now_tm.tm_wday;

    // La variabile dayOfWeek conterrà il giorno della settimana,
    // dove 0 è Domenica, 1 è Lunedì, 2 è Martedì, ecc.

    return dayOfWeek; //0 domenica, 1:5 feriali, 6 il sabato
}

int hours(){
     // Ottieni l'orario corrente
    auto now = chrono::system_clock::now();
    
    // Converti l'orario corrente in un oggetto std::tm
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm now_tm = *localtime(&now_c);

    // Estrai ora dall'oggetto std::tm
    int hours = now_tm.tm_hour + 2;

    return hours;
}

int minutes(){
     // Ottieni l'orario corrente
    auto now = chrono::system_clock::now();
    
    // Converti l'orario corrente in un oggetto std::tm
    time_t now_c = chrono::system_clock::to_time_t(now);
    tm now_tm = *localtime(&now_c);

    // minuti dall'oggetto std::tm
    int minutes = now_tm.tm_min;

    return minutes;
}

int main(){
    int giorno = weekDay();
    int ora = hours();
    int minuto = minutes();
    int nextOra1 = 0;
    int nextMinuto1 = 0;
    int nextOra2 = 0;
    int nextMinuto2 = 0;
    
    int metroFeriali[18][12] = {
        { 5, 53, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
        { 6,  8, 19, 27, 34, 41, 48, 56, -1, -1, -1, -1},
        { 7,  2,  9, 15, 21, 27, 33, 39, 45, 51, 57, -1},
        { 8,  2,  7, 12, 17, 22, 27, 32, 37, 43, 49, 55},
        { 9,  1,  7, 14, 21, 28, 35, 42, 49, 56, -1, -1},
        {10,  3, 11, 19, 31, 43, 55, -1, -1, -1, -1, -1},
        {11,  7, 19, 31, 43, 55, -1, -1, -1, -1, -1, -1},
        {12,  7, 19, 31, 43, 55, -1, -1, -1, -1, -1, -1},
        {13,  7, 19, 31, 43, 55, -1, -1, -1, -1, -1, -1},
        {14,  7, 19, 31, 43, 55, -1, -1, -1, -1, -1, -1},
        {15,  7, 19, 31, 43, 55, -1, -1, -1, -1, -1, -1},
        {16,  7, 19, 30, 44, 55, -1, -1, -1, -1, -1, -1},
        {17,  1,  7, 13, 19, 25, 31, 37, 43, 49, 55, -1},
        {18,  1,  7, 13, 19, 25, 31, 37, 43, 49, 55, -1},
        {19,  1,  7, 14, 21, 28, 35, 42, 49, 58, -1, -1},
        {20,  7, 17, 28, 40, 52, -1, -1, -1, -1, -1, -1},
        {21, 11, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {22, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    };
    
    int metroSabato[18][12] = {
        { 5, 53, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 6,  8, 20 ,31, 36, 49, 59, -1, -1, -1, -1, -1},
        { 7,  9, 19, 29, 39, 49, 59, -1, -1, -1, -1, -1},
        { 8,  9, 19, 29, 39, 49, 59, -1, -1, -1, -1, -1},
        { 9,  9, 19, 29, 39, 49, 59, -1, -1, -1, -1, -1},
        {10,  9, 24, 34, 54, -1, -1, -1, -1, -1, -1, -1},
        {11, 14, 34, 54, -1, -1, -1, -1, -1, -1, -1, -1},
        {12, 14, 34, 54, -1, -1, -1, -1, -1, -1, -1, -1},
        {13, 14, 34, 54, -1, -1, -1, -1, -1, -1, -1, -1},
        {14, 14, 34, 54, -1, -1, -1, -1, -1, -1, -1, -1},
        {15, 14, 34, 54, -1, -1, -1, -1, -1, -1, -1, -1},
        {16, 14, 34, 49, 59, -1, -1, -1, -1, -1, -1, -1},
        {17,  9, 19, 29, 39, 49, 59, -1, -1, -1, -1, -1},
        {18,  9, 19, 29, 39, 49, 59, -1, -1, -1, -1, -1},
        {19,  9, 19, 29, 39, 49, 59, -1, -1, -1, -1, -1},
        {20,  9, 20, 32, 44, 58, -1, -1, -1, -1, -1, -1},
        {21, 12, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {22, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    };

    int metroDomenica[18][12] = {
        { 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 6,  9, 30, 51, -1, -1, -1, -1, -1, -1, -1, -1},
        { 7, 18, 44, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 8, 10, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        { 9, 11, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {10, 11, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {11, 11, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {12, 11, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {13, 11, 31, 51, -1, -1, -1, -1, -1, -1, -1, -1},
        {14, 11, 31, 51, -1, -1, -1, -1, -1, -1, -1, -1},
        {15, 11, 31, 51, -1, -1, -1, -1, -1, -1, -1, -1},
        {16, 11, 31, 51, -1, -1, -1, -1, -1, -1, -1, -1},
        {17, 11, 31, 51, -1, -1, -1, -1, -1, -1, -1, -1},
        {18, 11, 31, 51, -1, -1, -1, -1, -1, -1, -1, -1},
        {19, 11, 31, 51, -1, -1, -1, -1, -1, -1, -1, -1},
        {20, 11, 31, 54, -1, -1, -1, -1, -1, -1, -1, -1},
        {21, 18, 43, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {22, 17, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
    };

    bool bl = false;

    //per i feriali
    for(int i = 0; i < 18 and giorno != 0 and giorno != 6; i++){
        if(bl){break;}
        for(int j=1; j<12; j++){
            if(metroFeriali[i][j]>0){
                if(metroFeriali[i][0]<ora ){ break;}
                if(metroFeriali[i][j]>minuto){

                    nextOra1 = metroFeriali[i][0];
                    nextMinuto1 = metroFeriali[i][j];
                    bl=true;

                    if(metroFeriali[i][j+1]!=-1){
                        nextOra2 = metroFeriali[i][0];
                        nextMinuto2 = metroFeriali[i][j+1];
                        
                    }
                    else{
                        nextOra2 = metroFeriali[i+1][0];
                        nextMinuto2 = metroFeriali[i+1][1];

                    }
                }
                if(bl){break;}
            }
        if(bl){break;}
        }
    }

    //per il sabato
    for(int i = 0; i < 18 and giorno == 6; i++){
        if(bl){break;}
        for(int j=1; j<12; j++){
            if(metroSabato[i][j]>0){
                if(metroSabato[i][0]<ora ){ break;}
                if(metroSabato[i][j]>minuto){

                    nextOra1 = metroSabato[i][0];
                    nextMinuto1 = metroSabato[i][j];
                    bl=true;

                    if(metroSabato[i][j+1]!=-1){
                        nextOra2 = metroSabato[i][0];
                        nextMinuto2 = metroSabato[i][j+1];
                        
                    }
                    else{
                        nextOra2 = metroSabato[i+1][0];
                        nextMinuto2 = metroSabato[i+1][1];

                    }
                }
                if(bl){break;}
            }
        if(bl){break;}
        }
    }

    //per la domenica
    for(int i = 0; i < 18 and giorno == 0; i++){
        if(bl){break;}
        for(int j=1; j<12; j++){
            if(metroDomenica[i][j]>0){
                if(metroDomenica[i][0]<ora ){ break;}
                if(metroDomenica[i][j]>minuto){

                    nextOra1 = metroDomenica[i][0];
                    nextMinuto1 = metroDomenica[i][j];
                    bl=true;

                    if(metroDomenica[i][j+1]!=-1){
                        nextOra2 = metroDomenica[i][0];
                        nextMinuto2 = metroDomenica[i][j+1];
                        
                    }
                    else{
                        nextOra2 = metroDomenica[i+1][0];
                        nextMinuto2 = metroDomenica[i+1][1];

                    }
                }
                if(bl){break;}
            }
        if(bl){break;}
        }
    }
    
    cout<<"ore: "<<ora<<":"<<minuto<<" del "<<giorno<<endl;
    cout<<"prossima metro:    "<<nextOra1<<":"<<nextMinuto1<<endl;
    cout<<"E poi anche alle:  "<<nextOra2<<":"<<nextMinuto2<<endl;
    
}
