#pragma once
#include <iostream>
#include <string>
#include <vector>
/*
- Stwórz klasę `Sample`, zawierającą:
    - zmienną całkowitą `label`,
    - wektor liczb zmiennoprzecinkowych `features`,
- w konstruktorze klasy `Sample` przyjmuj oba te parametry,
- stwórz też dla nich *gettery*.
*/

class Sample {
	private:
		int label;
		std::vector <float> features;
	public:
		Sample(std::vector <float> features, int label);
		virtual int get_label();
		std::vector <float> get_features();
		
		
	
};
