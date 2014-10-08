// Places.c ... implementation of Places

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Places.h"

typedef struct Place {
   char     *name;
   char     *abbrev;
   Location  id;
   PlaceType type;
} Place;

// Places should appear in alphabetic order
// Each entry should satisfy (places[i].id == i)
static Place places[] =
{
   {"Nowhere", "NO", NOWHERE, UNKNOWN},
   {"Adriatic Sea", "AS", ADRIATIC_SEA, SEA},
   {"Alicante", "AL", ALICANTE, LAND},
   {"Amsterdam", "AM", AMSTERDAM, LAND},
   {"Athens", "AT", ATHENS, LAND},
   {"Atlantic Ocean", "AO", ATLANTIC_OCEAN, SEA},
   {"Barcelona", "BA", BARCELONA, LAND},
   {"Bari", "BI", BARI, LAND},
   {"Bay of Biscay", "BB", BAY_OF_BISCAY, SEA},
   {"Belgrade", "BE", BELGRADE, LAND},
   {"Berlin", "BR", BERLIN, LAND},
   {"Black Sea", "BS", BLACK_SEA, SEA},
   {"Bordeaux", "BO", BORDEAUX, LAND},
   {"Brussels", "BU", BRUSSELS, LAND},
   {"Bucharest", "BC", BUCHAREST, LAND},
   {"Budapest", "BD", BUDAPEST, LAND},
   {"Cadiz", "CA", CADIZ, LAND},
   {"Cagliari", "CG", CAGLIARI, LAND},
   {"Castle Dracula", "CD", CASTLE_DRACULA, LAND},
   {"Clermont-Ferrand", "CF", CLERMONT_FERRAND, LAND},
   {"Cologne", "CO", COLOGNE, LAND},
   {"Constanta", "CN", CONSTANTA, LAND},
   {"Dublin", "DU", DUBLIN, LAND},
   {"Edinburgh", "ED", EDINBURGH, LAND},
   {"English Channel", "EC", ENGLISH_CHANNEL, SEA},
   {"Florence", "FL", FLORENCE, LAND},
   {"Frankfurt", "FR", FRANKFURT, LAND},
   {"Galatz", "GA", GALATZ, LAND},
   {"Galway", "GW", GALWAY, LAND},
   {"Geneva", "GE", GENEVA, LAND},
   {"Genoa", "GO", GENOA, LAND},
   {"Granada", "GR", GRANADA, LAND},
   {"Hamburg", "HA", HAMBURG, LAND},
   {"Ionian Sea", "IO", IONIAN_SEA, SEA},
   {"Irish Sea", "IR", IRISH_SEA, SEA},
   {"Klausenburg", "KL", KLAUSENBURG, LAND},
   {"Leipzig", "LI", LEIPZIG, LAND},
   {"Le Havre", "LE", LE_HAVRE, LAND},
   {"Lisbon", "LS", LISBON, LAND},
   {"Liverpool", "LV", LIVERPOOL, LAND},
   {"London", "LO", LONDON, LAND},
   {"Madrid", "MA", MADRID, LAND},
   {"Manchester", "MN", MANCHESTER, LAND},
   {"Marseilles", "MR", MARSEILLES, LAND},
   {"Mediterranean Sea", "MS", MEDITERRANEAN_SEA, SEA},
   {"Milan", "MI", MILAN, LAND},
   {"Munich", "MU", MUNICH, LAND},
   {"Nantes", "NA", NANTES, LAND},
   {"Naples", "NP", NAPLES, LAND},
   {"North Sea", "NS", NORTH_SEA, SEA},
   {"Nuremburg", "NU", NUREMBURG, LAND},
   {"Paris", "PA", PARIS, LAND},
   {"Plymouth", "PL", PLYMOUTH, LAND},
   {"Prague", "PR", PRAGUE, LAND},
   {"Rome", "RO", ROME, LAND},
   {"Salonica", "SA", SALONICA, LAND},
   {"Santander", "SN", SANTANDER, LAND},
   {"Saragossa", "SR", SARAGOSSA, LAND},
   {"Sarajevo", "SJ", SARAJEVO, LAND},
   {"Sofia", "SO", SOFIA, LAND},
   {"Strasbourg", "ST", STRASBOURG, LAND},
   {"St Joseph and St Marys", "JM", ST_JOSEPH_AND_ST_MARYS, LAND},
   {"Swansea", "SW", SWANSEA, LAND},
   {"Szeged", "SZ", SZEGED, LAND},
   {"Toulouse", "TO", TOULOUSE, LAND},
   {"Tyrrhenian Sea", "TS", TYRRHENIAN_SEA, SEA},
   {"Valona", "VA", VALONA, LAND},
   {"Varna", "VR", VARNA, LAND},
   {"Venice", "VE", VENICE, LAND},
   {"Vienna", "VI", VIENNA, LAND},
   {"Zagreb", "ZA", ZAGREB, LAND},
   {"Zurich", "ZU", ZURICH, LAND},
};

// given a Place number, return its name
char *idToName(Location p)
{
   assert(validPlace(p));
   return places[p].name;
}

// given a Place number, return its type
PlaceType idToType(Location p)
{
   assert(validPlace(p));
   return places[p].type;
}

// given a Place name, return its ID number
Location nameToID(char *name)
{
   // TODO: for Task 1
   return NOWHERE; // to keep gcc happy
}

// given a Place abbreviation (2 char), return its ID number
Location abbrevToID(char *abbrev)
{
   // TODO: for Task 1
   return NOWHERE; // to keep gcc happy
}
