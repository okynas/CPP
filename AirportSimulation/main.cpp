
#include "util.h"
#include "Queue.h"
#include "Plane.h"

#include <iostream>
#include <random>

using namespace std;

const int MAX_QUEUE_SIZE = 10;
int NUM_PLANES_ARRIVAL = 0;
int NUM_PLANES_DEPARTURE = 0;
int NUM_PLANES_REJECTED = 0;

/*
ALGORITME:

Les data/parameterverdier for simuleringen fra bruker

Initier begge k�ene til � v�re tomme

For hver tidssteg i simuleringen

    Trekk et tilfeldig antall nye fly som kommer for � lande

    For hvert nytt fly som kommer for � lande
        Hvis landingsk�en er full
            Avvis det nye flyet (henvis til annen flyplass)
        ellers
            Sett det nye flyet sist i landingsk�en

    Trekk et tilfeldig antall nye fly som kommer for � ta av

    For hvert nytt fly som kommer for � ta av
        Hvis avgangsk�en er full
            Avvis det nye flyet (avgang m� pr�ves senere)
        ellers
            Sett det nye flyet sist i avgangsk�en

    Hvis landingsk�en ikke er tom
        Ta ut f�rste fly i landingsk�en og la det f� lande
    ellers hvis avgangsk�en ikke er tom
        Ta ut f�rste fly i avgangsk�en og la det f� ta av
    ellers
        Flyplassen er tom for fly

Skriv til slutt ut resultater som gj.snittlig ventetid etc.
*/

/*
Velkommen til Halden Airport, tax-free butikken er dessverre stengt.

Hvor mange tidsenheter skal simuleringen g�? : 20
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
Antall fly klare til � ta av : 3
Prosent ledig tid            : 15
Gj.snitt. ventetid, landing  : 0.5 tidsenheter.
Gj.snitt. ventetid, avgang   : 1.33333 tidsenheter.
*/


int main()
{
    int time, plane_index = 0;
    float arrival, departure;

    default_random_engine generator;

    // Les data/parameterverdier for simuleringen fra bruker
	LOG("Velkommen til Halden Airport, tax-free butikken er dessverre stengt.");
    LOG("Hvor mange tidsenheter skal simuleringen g�? :");
    cin >> time;
    LOG("Forventet antall ankomster pr. tidsenhet ?   :");
    cin >> arrival;
    LOG("Forventet antall avganger pr. tidsenhet ?    :");
    cin >> departure;
    LOG("");

    // Initier begge k�ene til � v�re tomme
    Queue arrivals_queue;
    Queue departures_queue;

    gamma_distribution<double> departure_distribution(departure);
    gamma_distribution<double> arrival_distribution(arrival);

    // For hver tidssteg i simuleringen
    for (int i = 0; i < time; i++) {
        // Trekk et tilfeldig antall nye fly som kommer for � lande
        int arrival_count = (int)arrival_distribution(generator);

        //For hvert nytt fly som kommer for � lande
        for (int j = 0; j < arrival_count; j++) { 
            // Hvis landingsk�en er full
            if (arrivals_queue.size() == MAX_QUEUE_SIZE) {
                //Avvis det nye flyet(henvis til annen flyplass)
                LOG("Fly" << plane_index << " ble avvist!");
                NUM_PLANES_REJECTED++;
            }
            // ellers, Sett det nye flyet sist i landingsk�en
            else {
                Plane arrival_plane = Plane(plane_index);
                arrivals_queue.enqueue(arrival_plane);
                LOG("Fly" << arrival_plane.getId() << " klar for landing");
                NUM_PLANES_ARRIVAL++;
            }
            plane_index++;
        }

        // Trekk et tilfeldig antall nye fly som kommer for � ta av
        int departure_count = (int)departure_distribution(generator);
        
        //  For hvert nytt fly som kommer for � ta av
        for (int j = 0; j < departure_count; j++) {
            // Hvis avgangsk�en er full
            if (departures_queue.size() == MAX_QUEUE_SIZE) {
                // Avvis det nye flyet(avgang m� pr�ves senere)
                LOG("Fly" << plane_index << " ble avvist!");
                NUM_PLANES_REJECTED++;
            }
            else {
                // ellers Sett det nye flyet sist i avgangsk�en
                Plane departure_plane = Plane(plane_index);
                departures_queue.enqueue(departure_plane);
                LOG("Fly" << departure_plane.getId() << " klar for � ta av");
                NUM_PLANES_DEPARTURE++;
            }
            plane_index++;
        }
        
        // Hvis landingsk�en ikke er tom
        if (!departures_queue.isEmpty()) {
            // Ta ut f�rste fly i landingsk�en og la det f� lande
            Plane first_plane = departures_queue.dequeue();
            LOG("Fly" << first_plane.getId() << " tok av!");
        }
        // ellers hvis avgangsk�en ikke er tom
        else if (!arrivals_queue.isEmpty()) {
            // Ta ut f�rste fly i avgangsk�en og la det f� ta av
            Plane first_plane = arrivals_queue.dequeue();
            LOG("Fly" << first_plane.getId() << "  landet!");
        }
        else {
            // ellers Flyplassen er tom for fly
            LOG("Flyplassen er tom for fly!");
        }
       
    }

    int total_number_of_planes = plane_index;

    // Skriv til slutt ut resultater;
    LOG("");
    LOG("Simuleringen ferdig etter \t: " << time << " tidsenheter.");
    LOG("Total antall fly behandlet \t :" << total_number_of_planes);
    LOG("Antall fly landet \t :" << NUM_PLANES_ARRIVAL);
    LOG("Antall fly landet \t :" << NUM_PLANES_DEPARTURE);
    LOG("Antall fly avvist\t :" << NUM_PLANES_REJECTED);
    LOG("Antall fly klare for landing\t :" << arrivals_queue.size());
    LOG("Antall fly klare for � ta av\t :" << departures_queue.size());    
}

