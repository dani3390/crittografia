#include <iostream>
#include <math.h>
#include <random>
#include <time.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <stdio.h>
#include <cstring>

using namespace std;

int Numeri_Primi_Random_1_a_100(){
    int numeri_primi[100], l = 0; //numeri_primi impostato a 100, ma potrebbe essere anche di meno
    srand(time(NULL)); //imposto come seed l'orario

    for(int i = 3; i <= 100; i++){ //parto da 3 perchè 2 e 1 sono troppo piccoli
            bool prime = true;

            for(int j = 2; j < i; j++){
                if(i % j == 0 || i == j){
                    prime = false;
                    break; //se il numero non è primo esco dal ciclo attuale e proseguo a quello successivo
                }
            }

            if(prime){ // se prime è true, il numero è primo
                numeri_primi[l] = i; //aggiungo il numero primo all'array
                l++; //l lo uso per tenere conto dei numeri messi dentro l'array, per poi utilizzarlo con la funziona rand()
            }
        }

    return numeri_primi[rand() % l]; //il return ritorna un numero randomico preso dall'array

}

long int Cifratura_Decifratura(long int base, long int esponente, long int modulo) //Esponenziazione Modulare
{
    if (esponente == 0){ //un numero alla 0 fa 1
        return 1;
    }

    if (esponente == 1){ //con esponente uguale 1, ritorno il resto tra la base ed il modulo
        return base % modulo;
    }

    long long int t = Cifratura_Decifratura(base, esponente / 2, modulo); //ogni volta calcolo t con l'esponente dimezzato
    t = (t * t) % modulo; //calcolo ogni volta il nuovo valore t - resto del modulo - da usare nel calcolo successivo

    //esponente pari
    if (esponente % 2 == 0){
        return t;
    }

    //esponente dispari
    else{
        return ((base % modulo) * t) % modulo;
    }
}

int main()
{

    int p, q, n, f, e;

    float d;

    p = Numeri_Primi_Random_1_a_100();
    Sleep(1000); //sleep di 1 secondo per permettere di generare un numero randomico diverso
    q = Numeri_Primi_Random_1_a_100();
    n = p * q;
    f = (p - 1) * (q - 1);
    Sleep(1000);
    e = Numeri_Primi_Random_1_a_100();


    while(e > f && __gcd(e, f) != 1){ //controllo che e sia minore di f, e che sia coprimo. __gcd funzione di libreria
        Sleep(1000);
        e = Numeri_Primi_Random_1_a_100();
    }

    for(int k = 0;k < 100;k++){
    d = (((static_cast<float>(f) * k) + 1) / (static_cast<float>(e))); //non molto bello, si può fare di meglio
    if(ceilf(d) == d){
        break; //nel momento in cui trovo un valore intero, esco dal ciclo.
        }
    }

    cout << "Chiave pubblica = (" << e << "," << n << ")" << endl;
    cout << "Chiave privata = (" << d << "," << n << ")" << endl;


    long int le[100];
    string a;
    getline(cin, a);

    for(int i = 0;i < a.size();i++){
    le[i] = Cifratura_Decifratura(static_cast<int>(a[i]), e, n);
    }

    cout << "Messaggio cifrato: ";
    for(int i = 0;i < a.size();i++){
        cout << le[i];
    }

    cout << endl;

    long int lo[100];

    for(int i = 0;i < a.size();i++){
    lo[i] = Cifratura_Decifratura(le[i], d, n);
    }

    cout << "Messaggio decifrato: ";
    for(int i = 0;i < a.size();i++){
        cout << (static_cast<char>(lo[i]));
    }

    cout << endl;


    return 0;
}
