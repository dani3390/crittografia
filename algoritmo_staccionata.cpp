#include <iostream>
#include <string>

using namespace std; //usato per rendere più leggibile il codice. FYI Bad Programming

string Criptazione(int chiave, string parola){

    char contenitore[chiave][parola.size()]; //righe e colonne

    //riempio il contenitore di spazi vuoti, in modo da distinguerli più avanti dagli spazi occupati
    for(int i = 0; i < chiave;i++){     //righe
        for(int j = 0;j < parola.size();j++){ //colonne
            contenitore[i][j] = '\n'; //spazio vuoto
        }
    }

    bool sotto = false;
    int riga = 0, colonna = 0;

    for(int i = 0;i < parola.size();i++){

       //direzione verso cui leggere la criptazione. Una volta arrivato in fondo, sale. Quando arrivato in cima, scende.
        if (riga == 0 || riga == chiave - 1){
            sotto = !sotto;
        }

        contenitore[riga][colonna++] = parola[i]; //riempio il contenitore seguendo l'ordine a zig e zag (verso l'alto ed il basso) dell'algoritmo

        //cout << "riga: " << riga << " " << "colonna: " << colonna << " " << parola[i] << " " << endl;

        sotto ? riga++ : riga--; //se sotto è -true-, riga aumenta (quindi scendo), altrimenti riga diminuisce (salgo)
    }

    string parola_criptata;
    for(int i = 0; i < chiave; i++){
        for(int j = 0; j < parola.size();j++)
            if(contenitore[i][j]!='\n'){
                parola_criptata.push_back(contenitore[i][j]); //si occupa di concatenare ogni singolo carattere che andremo a prendere da -contenitore- in -parola_criptata-
            }
    }

    return parola_criptata;

}

string Decriptazione(int chiave, string criptata){

    char contenitore2[chiave][criptata.size()]; //righe e colonne

    //riempio il contenitore di spazi vuoti, in modo da distinguerli più avanti dagli spazi occupati
    for(int i = 0; i < chiave;i++){     //righe
        for(int j = 0;j < criptata.size();j++){ //colonne
            contenitore2[i][j] = '\n'; //spazio vuoto
        }
    }

    bool sotto = false;
    int riga = 0, colonna = 0;

    for(int i = 0;i < criptata.size();i++){


        if (riga == 0 || riga == chiave - 1){
            sotto = !sotto;
        }

        contenitore2[riga][colonna++] = '*'; //imposto asterischi nei punti in cui dovrebbero essere presenti le lettere

        sotto ? riga++ : riga--;
    }

    int numero = 0; //riempio le posizioni con asterischi con le lettere della parola criptata
       for (int i = 0; i < chiave; i++)
           for (int j = 0; j < criptata.size(); j++){
               if (contenitore2[i][j] == '*' && numero < criptata.size())
                   contenitore2[i][j] = criptata[numero++];
           }

       string parola_decriptata;
       sotto = false;
       riga = 0, colonna = 0;
           for (int i = 0; i < criptata.length(); i++)
           {
               if (riga == 0 || riga == chiave - 1){
                   sotto = !sotto;
               }

               if (contenitore2[riga][colonna] != '*'){
                   parola_decriptata.push_back(contenitore2[riga][colonna++]);
               }

               sotto ? riga++ : riga--;
           }

           return parola_decriptata;

}

int main()
{
    int chiave;
    string parola, criptata;

    cout << "Inserisci la chiave da usare: ";
    cin >> chiave;
    cout << "Inserisci la parola da criptare: ";
    cin >> parola;

    criptata = Criptazione(chiave, parola);

    cout << "Parola criptata: " << criptata << endl;

    cout << "Parola decriptata: " << Decriptazione(chiave, criptata) << endl;

    return 0;
}
