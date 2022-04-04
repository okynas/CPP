
#include "util.h"
#include "Queue.h"
#include "Plane.h"

#include <iostream>
#include <random>
#include <format>

using namespace std;

const int MAX_QUEUE_SIZE = 0;

/*
ALGORITME:

Les data/parameterverdier for simuleringen fra bruker

Initier begge køene til å være tomme

For hver tidssteg i simuleringen

    Trekk et tilfeldig antall nye fly som kommer for å lande

    For hvert nytt fly som kommer for å lande
        Hvis landingskøen er full
            Avvis det nye flyet (henvis til annen flyplass)
        ellers
            Sett det nye flyet sist i landingskøen

    Trekk et tilfeldig antall nye fly som kommer for å ta av

    For hvert nytt fly som kommer for å ta av
        Hvis avgangskøen er full
            Avvis det nye flyet (avgang må prøves senere)
        ellers
            Sett det nye flyet sist i avgangskøen

    Hvis landingskøen ikke er tom
        Ta ut første fly i landingskøen og la det få lande
    ellers hvis avgangskøen ikke er tom
        Ta ut første fly i avgangskøen og la det få ta av
    ellers
        Flyplassen er tom for fly

Skriv til slutt ut resultater som gj.snittlig ventetid etc.
*/

/*
Velkommen til Halden Airport, tax-free butikken er dessverre stengt.

Hvor mange tidsenheter skal simuleringen gå? : 20
Forventet antall ankomster pr. tidsenhet ?   : 0.6
Forventet antall avganger pr. tidsenhet ?    : 0.4

 1: Fly 0 klar for landing.
    Fly 0 landet, ventetid 0 enheter.
 2: Flyplassen er tom.
 3: Fly 1 klar for landing.
    Fly 2 klar for landing.
    Fly 1 landet, ventetid 0 enheter.
 4: Fly 2 landet, ventetid 1 enheter.
 5: Fly 3 klar for landing.
    Fly 4 klar for avgang.
    Fly 3 landet, ventetid 0 enheter.
 6: Fly 5 klar for avgang.
    Fly 6 klar for avgang.
    Fly 4 tatt av, ventetid 1 enheter.
 7: Fly 5 tatt av, ventetid 1 enheter.
 8: Fly 6 tatt av, ventetid 2 enheter.
 9: Flyplassen er tom.
10: Fly 7 klar for landing.
    Fly 8 klar for landing.
    Fly 7 landet, ventetid 0 enheter.
11: Fly 8 landet, ventetid 1 enheter.
12: Flyplassen er tom.
13: Fly 9 klar for landing.
    Fly 9 landet, ventetid 0 enheter.
14: Fly 10 klar for landing.
    Fly 11 klar for avgang.
    Fly 10 landet, ventetid 0 enheter.
15: Fly 12 klar for landing.
    Fly 13 klar for landing.
    Fly 12 landet, ventetid 0 enheter.
16: Fly 14 klar for landing.
    Fly 15 klar for landing.
    Fly 16 klar for avgang.
    Fly 13 landet, ventetid 1 enheter.
17: Fly 14 landet, ventetid 1 enheter.
18: Fly 17 klar for landing.
    Fly 15 landet, ventetid 2 enheter.
19: Fly 18 klar for avgang.
    Fly 17 landet, ventetid 1 enheter.
20: Fly 19 klar for landing.
    Fly 19 landet, ventetid 0 enheter.

Simuleringen ferdig etter      20 tidsenheter.
Totalt antall fly behandlet  : 20
Antall fly landet            : 14
Antall fly tatt av           : 3
Antall fly avvist            : 0
Antall fly klare for landing : 0
Antall fly klare til å ta av : 3
Prosent ledig tid            : 15
Gj.snitt. ventetid, landing  : 0.5 tidsenheter.
Gj.snitt. ventetid, avgang   : 1.33333 tidsenheter.
*/


int main()
{
    int time;
    float arrival, departure;

    default_random_engine generator;

    // Les data/parameterverdier for simuleringen fra bruker
	LOG("Velkommen til Halden Airport, tax-free butikken er dessverre stengt.");
    LOG("Hvor mange tidsenheter skal simuleringen gå? :");
    cin >> time;
    LOG("Forventet antall ankomster pr. tidsenhet ?   :");
    cin >> arrival;
    LOG("Forventet antall avganger pr. tidsenhet ?    :");
    cin >> departure;

    // Initier begge køene til å være tomme
    Queue arrivals_queue;
    Queue departures_queue;

    gamma_distribution<double> departure_distribution(departure);
    gamma_distribution<double> arrival_distribution(arrival);

    // For hver tidssteg i simuleringen
    for (int i = 0; i < time; i++) {
        // Trekk et tilfeldig antall nye fly som kommer for å lande
        int arrival_count = arrival_distribution(generator);

        //For hvert nytt fly som kommer for å lande
        for (int j = 0; j < arrival_count; j++) { 
            // Hvis landingskøen er full
            if (arrivals_queue.size() == MAX_QUEUE_SIZE) {
                //Avvis det nye flyet(henvis til annen flyplass)
                LOG("Fly" << j << "ble avvist!");
            }
            // ellers, Sett det nye flyet sist i landingskøen
            else {
                Plane arrival_plane = Plane(j);
                arrivals_queue.enqueue(arrival_plane);
            }
        }

        // Trekk et tilfeldig antall nye fly som kommer for å ta av
        int departure_count = departure_distribution(generator);
        
        //  For hvert nytt fly som kommer for å ta av
        for (int j = 0; j < departure_count; j++) {
            // Hvis avgangskøen er full
            if (departures_queue.size() == MAX_QUEUE_SIZE) {
                // Avvis det nye flyet(avgang må prøves senere)
                LOG("Fly" << j << "ble avvist!");
            }
            else {
                // ellers Sett det nye flyet sist i avgangskøen
                Plane departure_plane = Plane(j);
                departures_queue.enqueue(departure_plane);
            }
        }

        // Hvis landingskøen ikke er tom
            // Ta ut første fly i landingskøen og la det få lande
         // ellers hvis avgangskøen ikke er tom
            // Ta ut første fly i avgangskøen og la det få ta av
         // ellers Flyplassen er tom for fly
       
    }

    // Skriv til slutt ut resultater som gj.snittlig ventetid etc.
    
}

