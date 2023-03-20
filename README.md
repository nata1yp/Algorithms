# Algorithms and Complexity - NTUA

### roadtrip2
We need to find the cheapest car that can do this distance D in time(less than or equal to T). Each car has two modes, eco and sport. Each mode has its own time and capacity needed to cover 1km.
* In this problem the following form of input is given:
  * N,K,D,T - Where N is the number of cars, K the number of stations, D the distance we want to cover, T the time we need to cover the distance.
  * N pairs of P<sub>i</sub>, C<sub>i</sub>.
  * K numbers which are the in between stations.
  * T<sub>s</sub>, C<sub>s</sub>, T<sub>f</sub>, C<sub>f</sub>, which are time-capacity for eco mode, time-capacity for sport mode respectively.

### teleports
We need the maximum width of the narrowest portal that will be used so as each Morty go back to the Universe he belongs.
* In this problem the following form of input is given:
  * N,M - Where N is the number of Universes, M the number of portals.
  * The permutation c = (c<sub>1</sub>,...,c<sub>N</sub>), where c<sub>i</sub> shows the parallel universe that Morty of i<sub>th</sub> universe is.
  * K triplets of numbers a<sub>j</sub>, b<sub>j</sub>, w<sub>j</sub>, where a is the portal in one universe, b is the portal to the other universe and w is the width of the portal.


### chem
There are N chemical substances and we need to store them into K metal bottles. The substances are labeled from 1 to N and for safety reasons, the substances need to be stored with the right order. Each chemical substance needs to be stored in only one bottle (You can not store half of the chemical substance in one bottle and the other half in an other). Each metal bottle has enough capacity so as all the substances can be stored inside. 
However, there is a risk of a chemical reaction between the substances in the same bottle, at which time significant amounts of energy are attracted. Specifically for each pair (i, j) of substances in the same bottle, the chemical reaction between them produces energy equal to A[i, j] units.


### bazaar
The goal is to be able to buy N sets of equipment from the bazaar. The equipment is the set of armor, shield, sword. The armor is denoted by A, the sword by B and the shield by C. There are three dealers who sell this equipment (Denoted by numbers 1, 2 and 3 respectively). Each merchant can sell one or more items of any type.
Items sold by different merchants are not compatible and we can not complete a set from another merchant. Each set must be purchased exclusively from a dealer.
Each trader at the beginning of the bazaar, announces his offers, ie how many items of each type he sells and at what price. Usually the trader sells many different (foreign to each other) sets of the same item at a different price (eg trader 1 can sell 3 armors (1A) at a price of 100 and other 4 armors at a price of 800). The items mentioned in the offers are necessarily sold all together as a single. Finally, the minimum amount needed to purchase N total sets of equipment must be calculated.