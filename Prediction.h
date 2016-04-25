#pragma once
#include "Sample.h"

/*
- Stwórz klasę `Prediction`, dziedziczącą po klasie `Sample`, dodającą do niej zmienną `prediction`,
- Rozszerz ją o metodę statyczną `accuracy()`, przyjmującą wektor obiektów klasy `Prediction`, informującą o tym, w jakim odsetku ich zmienne `label` i `prediction` mają tę samą wartość.
*/
using namespace std;
class Prediction : public Sample
{
	public:
		int prediction;
		static float accuracy(std::vector <Prediction *> vecPrediction){
			int good = 0;
	for (vector <Prediction *>::iterator i = vecPrediction.end()-1; i != vecPrediction.begin()-1; --i){
		if((*i)->get_label()==(*i)->prediction)
			++good;
	}
	return (float)good/(float)vecPrediction.size();}
		Prediction(std::vector <float> features, int label) : Sample(features, label){}
		
};
