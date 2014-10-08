// places.h ... interface to Places

#ifndef PLACES_H
#define PLACES_H

// Types of places (could have been enum)
typedef int PlaceType;
#define NUM_PLACE_TYPES 2

#define UNKNOWN 0
#define LAND 1
#define SEA  2

// Types of connections between places (enum?)
typedef int Transport;
#define NUM_TRANSPORT 3

#define NONE 0
#define ROAD 1
#define RAIL 2
#define BOAT 3
#define ANY  4

// Places (enum?)
typedef int Location;
#define NUM_PLACES 72

#define NOWHERE 0
#define ADRIATIC_SEA 1
#define ALICANTE 2
#define AMSTERDAM 3
#define ATHENS 4
#define ATLANTIC_OCEAN 5
#define BARCELONA 6
#define BARI 7
#define BAY_OF_BISCAY 8
#define BELGRADE 9
#define BERLIN 10
#define BLACK_SEA 11
#define BORDEAUX 12
#define BRUSSELS 13
#define BUCHAREST 14
#define BUDAPEST 15
#define CADIZ 16
#define CAGLIARI 17
#define CASTLE_DRACULA 18
#define CLERMONT_FERRAND 19
#define COLOGNE 20
#define CONSTANTA 21
#define DUBLIN 22
#define EDINBURGH 23
#define ENGLISH_CHANNEL 24
#define FLORENCE 25
#define FRANKFURT 26
#define GALATZ 27
#define GALWAY 28
#define GENEVA 29
#define GENOA 30
#define GRANADA 31
#define HAMBURG 32
#define IONIAN_SEA 33
#define IRISH_SEA 34
#define KLAUSENBURG 35
#define LEIPZIG 36
#define LE_HAVRE 37
#define LISBON 38
#define LIVERPOOL 39
#define LONDON 40
#define MADRID 41
#define MANCHESTER 42
#define MARSEILLES 43
#define MEDITERRANEAN_SEA 44
#define MILAN 45
#define MUNICH 46
#define NANTES 47
#define NAPLES 48
#define NORTH_SEA 49
#define NUREMBURG 50
#define PARIS 51
#define PLYMOUTH 52
#define PRAGUE 53
#define ROME 54
#define SALONICA 55
#define SANTANDER 56
#define SARAGOSSA 57
#define SARAJEVO 58
#define SOFIA 59
#define STRASBOURG 60
#define ST_JOSEPH_AND_ST_MARYS 61
#define SWANSEA 62
#define SZEGED 63
#define TOULOUSE 64
#define TYRRHENIAN_SEA 65
#define VALONA 66
#define VARNA 67
#define VENICE 68
#define VIENNA 69
#define ZAGREB 70
#define ZURICH 71

// given a Place number, return its name
char *idToName(Location place);

// given a Place number, return its type
PlaceType idToType(Location place);

// given a Place name, return its ID number
Location nameToID(char *name);

// given a Place abbreviation, return its ID number
Location abbrevToID(char *abbrev);

#define isLand(place)  (typeOf(place) == LAND)
#define isSea(place)  (typeOf(place) == SEA)

// should we count NOWHERE as a valid place?
#define validPlace(pid) (pid >= 0 && pid < NUM_PLACES)

#endif
