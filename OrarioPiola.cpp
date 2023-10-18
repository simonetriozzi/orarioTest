//PIOLA
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
    
    int metroFeriali[5][7] = {
        {10, 18, 29, 33, 38, 46, 55},
        {20,  4, 13, 22, 30, 38, 50},
        {21,  0, 17, 33, 50, -1, -1},
        {22,  1, 14, -1, -1, -1, -1},
        {24, 59, -1, -1, -1, -1, -1}
    };
    
    int metroSabato[12][7] = {
        { 6, 10, 18, 29, 40, 50, -1},
        {10,  0, 15, 25, 45, -1, -1},
        {11,  5, 25, 45, -1, -1, -1},
        {12,  5, 25, 45, -1, -1, -1},
        {13,  5, 25, 45, -1, -1, -1},
        {14,  5, 25, 45, -1, -1, -1},
        {15,  5, 25, 45, -1, -1, -1},
        {16,  5, 25, 40, 50, -1, -1},
        {20,  0, 10, 20, 30, 40, 50},
        {21,  1, 16, 34, 59, -1, -1},
        {22, 14, -1, -1, -1, -1, -1},
        {24, 59, -1, -1, -1, -1, -1},
    };

    int metroDomenica[18][5] = {
        { 6, 33, -1, -1, -1},
        { 7,  5, 35, -1, -1},
        { 8, 11, 43, -1, -1},
        { 9, 13, 43, -1, -1},
        {10, 13, 43, -1, -1},
        {11, 13, 43, -1, -1},
        {12, 13, 41, -1, -1},
        {13,  5, 22, 42, -1},
        {14,  2, 22, 42, -1},
        {15,  2, 22, 42, -1},
        {16,  2, 22, 42, -1},
        {17,  2, 22, 42, -1},
        {18,  2, 22, 42, -1},
        {19,  2, 22, 42, -1},
        {20,  2, 22, 42, 48},
        {21,  9, 25, 45, 59},
        {22, 14, -1, -1, -1},
        {24, 59, -1, -1, -1}
    };

    bool bl = false;
    string message = "";
    //per i feriali
    for(int i = 0; i < 5 and giorno != 0 and giorno != 6; i++){
        if(bl){break;}
        for(int j=1; j<7; j++){
            if(ora > 6 and ora < 20){
                message="Metro ogni 5-12 minuti. ";
                bl=true;
                break;
            }
            else{
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
    }

    //per il sabato
    for(int i = 0; i < 12 and giorno == 6; i++){
        if(bl){break;}
        for(int j=1; j<7; j++){
            if((ora > 6 and ora < 10) or (ora>16 and ora<20)){
                message="Metro ogni 10 minuti ";
                bl=true;
                break;
            }
            else{
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
            }
        if(bl){break;}
        }
    }

    //per la domenica
    for(int i = 0; i < 18 and giorno == 0; i++){
        if(bl){break;}
        for(int j=1; j<5; j++){
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
    if(nextOra1!=0){
        cout<<"prossima metro:    "<<nextOra1<<":"<<nextMinuto1<<endl;
        cout<<"E poi anche alle:  "<<nextOra2<<":"<<nextMinuto2<<endl;
    }
    else{
        cout<<message;
    }
}