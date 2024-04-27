// Programma per gestire le Task 

// Librerie necessarie
#include<iostream>
#include<string> 
#include<fstream>
//* mettere libreria per visualizzare n numeri dopo la virgola per la statistica

using namespace std;

// Prototipi
int menu();
void nuovaTask(int &nTask);
void deleteTask(int &nTask);
void modTask(int nTask);
void completeTask(int nTask);
void stampa(int nTask);
float statistiche(int nTask);
void classiTask(int nTask);
void avanti();

// Globale
const int maxTask=1000;
string task[maxTask];
bool check[maxTask];

string nomiClassi [5];
string e0 [maxTask];
string e1 [maxTask];
string e2 [maxTask];
string e3 [maxTask];
string e4 [maxTask];

int main(){

    int s,nTask=0;

    do{
        system("cls");
        s=menu();

        cin.ignore();

        switch(s){
            
            case 1:{
                nuovaTask(nTask);
                break;
            }

            case 2:{
                if(nTask>0){
                    modTask(nTask);
                }
                else{
                    cout<<"Non ci sono task da modificare!"<<endl;
                }
                
                break;
            }

            case 3:{
                if(nTask>0){
                    deleteTask(nTask);
                }
                else{
                    cout<<"Non ci sono task da eliminare!"<<endl;
                }
                break;
            }

            case 4:{
                if(nTask>0){
                    stampa(nTask);
                }
                else{
                    cout<<"Non ci sono task da visualizzare!"<<endl;
                }
                break;
            }

            case 5:{
                if(nTask>0){
                    completeTask(nTask);
                }
                else{
                    cout<<"Non ci sono task da completare!"<<endl;
                }
                
                break;
            }

            case 6:{
                if(nTask>0){
                    statistiche(nTask);
                }
                else{
                    cout<<"Non ci sono task da visualizzare!"<<endl;
                }
                break;
            }

            case 7:{ //VIsualizza classi per task
                if(nomiClassi[0]=="" || nTask==0){
                    
                    if(nomiClassi[0]==""){
                        cout<<"Non ci sono classi!"<<endl;

                        cout<<"Vuoi crearne una nuova? (S/N) ";
                        char ris;
                        cin>>ris;
                        ris=toupper(ris);

                        if(ris=='S'){
                            cout<<"Inserisci il nome della classe: ";
                            cin>>nomiClassi[0];
                        }
                        else{
                            cout<<"Arrivederci!"<<endl;
                        }
                    }
                    else if(nTask==0){
                        cout<<"Non ci sono task!"<<endl;

                        cout<<"Vuoi crearne una nuova? (S/N) ";
                        char ris;
                        cin>>ris;
                        ris=toupper(ris);

                        if(ris=='S'){
                            nuovaTask(nTask);
                        }
                        else{
                            cout<<"Arrivederci!"<<endl;
                        }
                    }
                }
                break;
            }

            case 0:{
                cout<<"Arrivederci!"<<endl;
                break;
            }

            default:{
                cout<<"Scelta non valida!"<<endl;
                break;
            }

        }

        avanti();

    }while(s!=0);

    return 0;
}

int menu(){

    int scelta;

    cout<<"\t -----Menu'-----\n";
    cout<<"1. Inserisci una nuova Task \n";
    cout<<"2. Modifica una Task \n";
    cout<<"3. Elimina una Task \n";
    cout<<"4. Visualizza tutte le Task \n";
    cout<<"5. Contransegna una Task come completata \n";
    cout<<"6. Visualizza le statistiche \n";
    cout<<"7. Visualizza i tag delle classi \n";
    cout<<"0. Esci \n\n";

    cout<<"Fai una scelta: ";
    cin>>scelta;

    return scelta;
}

void nuovaTask(int &nTask){

    cout<<"Inserisci la Task: ";
    getline(cin,task[nTask]);

    check[nTask]=false;

    cout<<"\nTask aggiunto! \n";
    nTask++;
}

void deleteTask(int &nTask){
    
    stampa(nTask);

    int pos;

   do{
        cout<<"Che task vuoi eliminare? ";
        cin>>pos;

        if(pos<1 || pos>nTask){
            cout<<"Inserisci una task esistente "<<endl;
        }

        cout<<endl;
   }while(pos<1 || pos>nTask);

   for(int i=pos-1; i<nTask;i++){
        task[i]=task[i+1];
        check[i]=check[i+1];
   }

   nTask--;

   avanti();
}

void modTask(int nTask){
    
    stampa(nTask);
    int pos;
    char ris;

    cout<<"\nChe task vuoi modificare? ";
    cin>>pos;

    do{

        if(pos<1 || pos>nTask){
            cout<<"Non esiste la task "<<pos<<" vuoi creare una nuova task?(S/N) ";
            cin>>ris;
            ris=toupper(ris);

            if(ris=='S'){
                nuovaTask(nTask);
            }
            else{
                cout<<"Inserisci la nuova task da modificare: ";
                cin>>pos;
            }

        }

    }while(pos<1 || pos>nTask);

    cout<<"Modifica la task: ";
    cin.ignore();
    getline(cin, task[pos-1]);

    cout<<"\nTask modificata! \n";

}

void completeTask(int nTask){
    stampa(nTask);

    int pos;

    do{
        cout<<"\nChe task vuoi contrassegnare come completata? ";
        cin>>pos;

        if(pos<1 || pos>nTask){
            cout<<" \nInserisci una task esistente"<<endl;
        }

    }while (pos<1 || pos>nTask);

    check[pos-1]=true;
}

void stampa(int nTask){
    
    for(int i=0;i<nTask;i++){
        
        if(check[i]==true){
            cout<<i+1<<") [X] "<<task[i]<<endl;
        }
        else{
            cout<<i+1<<") [ ] "<<task[i]<<endl;
        }
    }

}

float statistiche(int nTask){

    int x=0;
    
    for(int i=0;i<nTask;i++){
        if(check[i]==true){
            x++;
        }
    }

    cout<<"\nHai completato "<<x<<" task su "<<nTask<<" task"<<endl;
    cout<<"\nHai completato un totale di "<<(float)x*100/nTask<<"%"<<endl;
    
   return (float)x*100/nTask;
}

void classiTask(int nTask){

    int scelta;

    cout<<"\t -----Classi-----\n";
    cout<<"1. Sposta la task in una classe \n";
    cout<<"2. Elimina una classe \n";
    cout<<"3. Visualizza le classi \n";
    cout<<"0. Esci \n\n";

    cout<<"Scelta: ";
    cin>>scelta;

    switch(scelta){

        case 1:{
            int scelta1;
            cout<<"-----Task-----\n";
            stampa(nTask);

            do{
                cout<<"\nQuale task vuoi spostare? ";
                cin>>scelta1;

                if(scelta1<1 || scelta1>nTask){
                    cout<<"Inserisci una task esistente"<<endl;
                }
            }while (scelta1<1 || scelta1>nTask);

            cout<<endl;

            cout<<"-----Classi-----\n";

            for(int i=0; i<size(nomiClassi);i++){
                cout<<i+1<<") "<<nomiClassi[i]<<endl;
            }

            int scelta2;

            do{
                cout<<"\nInserisci la classe in cui vuoi spostare la task: ";
                cin>>scelta2;

                if(scelta2<1 || scelta2>size(nomiClassi)){
                    cout<<"Inserisci una classe esistente"<<endl;

                    cout<<"\n Vuoi creare una nuova classe?(S/N) ";
                    char ris;
                    cin>>ris;
                    ris=toupper(ris);
                    if(ris=='S'){
                       // crea nuova classe 
                    }
                }
            }while (scelta2<1 || scelta2>size(nomiClassi));

            break;
        }
        case 2:{
            break;
        }
        case 3:{
            break;
        }
        default:{
            break;
        }

    }

    for(int i=0; i<size(nomiClassi);i++){
        cout<<i+1<<") "<<nomiClassi[i]<<endl;
    }
}


void avanti(){
    cout<<"\nPremi invio per andare avanti\n";
    cin.get();
}

//? Idee per soluzioni 
//*Classi: Creare un vettore che contiene il nome della classe 
// per ogni nome della stringa metto il numero in forma di stringa -> poi lo converto in int
// fare un vettore che contiene vettori. Provare.

// ? Aggiornamenti programma
// !IDEA: Implementare il salvataggio in un file .txt
// !IDEA: Aggiungere un icona all'eseguibile
// !IDEA: Mettere un opzione per tornare indietro 
// !IDEA: Aggiungere le scritte colorate 

