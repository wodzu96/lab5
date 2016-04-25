#pragma once
#include "Sample.h"
/*
- Stwórz klasę `Dataset`, zawierającą:
    - wektor obiektów klasy `Sample`,
    - metodę `push_back()`, dodającą nową próbkę do wektora:
        - metoda ta powinna sprawdzać, czy wektor `features` dla każdej z wprowadzanych próbek jest tej samej długości.
*/

class Dataset {
	public:
		bool push_back(Sample* Sample);
		std::vector <Sample*> vecSample;
		
};
