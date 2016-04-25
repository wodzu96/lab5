#include "Sample.h"
#include "Dataset.h"
#include "Prediction.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
#include <ctime>
/*
- Jako argumenty wiersza poleceń programu, przekaż nazwę pliku oraz liczbę całkowitą `k`,
- dla celów testowych, w repozytorium znajduje się plik `wine.csv`,
- wczytaj plik `wine.csv` do wektora obiektów typu `Sample` tak, aby pierwsza jego kolumna określała `label`, a pozostałe znalazły się w wektorze `features`,
- stwórz dwa obiekty klasy `Dataset`. Pierwszy nazwij `train`, drugi `test`,
- do `train` wprowadź losowe 20% wczytanych z pliku obiektów, a do `test`, resztę,
- zaimplementuj funkcję `knn()`, zwracającą wektor obiektów klasy `Prediction` przyjmującą jako argumenty dwa obiekty typu `Dataset` (`train` i `test`) i zmienną całkowitą `k`:
    - utwórz w niej wektor `predictions`:
    - do utworzonego wektora wprowadź kopie wszystkich obiektów (mają typ `Sample`) znajdujących się w `test`, uzupełniając dla nich wartość `prediction`, według następującego schematu:

>   Dla każdego obiektu ze zbioru testowego znajdź `k` obiektów ze zbioru uczącego, którego cechy (`features`) znajdują się w najmniejszej od niego [odległości](https://pl.wikipedia.org/wiki/Odległość). Za `prediction` uznaj `label`, który powtarza się najczęściej wśród znalezionych.
>   

- Wyświetl użytkownikowi informacje o zbiorze (nazwa pliku, liczba próbek, liczba cech) oraz jakość klasyfikacji (`accuracy()`).
*/

using namespace std;

vector <Prediction *> knn(Dataset *train, Dataset *test, int k);
double Sample_Distance(Sample sample1, Sample sample2);
void sort (double tab[][2], int left, int right);
int most_popular(double tab[][2], int k);
int main(int argc, char const *argv[])
{
	int k = atoi(argv[2]);
	string filename = argv[1];
	fstream plik;
	srand( time( NULL ) );
	vector <Sample *> vecSample;
	plik.open(filename, ios::in);
	string linia;
	if(plik.good() == true)
    {
        while(getline(plik, linia))
        {
            string liczba;
            stringstream ss(linia);
            int label = 0;
            vector <float> features;
            for(int i = 0; getline(ss, liczba, ','); ++i){
            if(!i)
				label = stoi(liczba);
			else
				features.push_back(stof(liczba));
				
        }
        vecSample.push_back(new Sample(features,label));
	}
        plik.close();
    
}
	Dataset train, test;
	int size = vecSample.size()/5;
	for(int i = 0; i<size; ++i){
		int random = rand()%vecSample.size();
		train.push_back(vecSample[random]);
		vecSample.erase(vecSample.begin()+random);
}
	size = vecSample.size();
	for (int i = 0; i<size; ++i){
	test.push_back(vecSample[0]);
	vecSample.erase(vecSample.begin());
	
}
	cout<<"Name: "<<filename<<endl<<
	"Number of samples: "<<train.vecSample.size()+test.vecSample.size()<<endl<<
	"Number of features: "<<train.vecSample[0]->get_features().size()<<endl<<
	"Quality of classification: "<<Prediction::accuracy(knn(&train, &test, k));
	
}
vector <Prediction *> knn(Dataset *train, Dataset *test, int k){
	vector <Prediction *> predictions;
	for (unsigned int i = 0; i<test->vecSample.size(); ++i){
		predictions.push_back( new Prediction(test->vecSample[i]->get_features(), test->vecSample[i]->get_label()));
		double distance[train->vecSample.size()][2];
		for(unsigned int j = 0; j<train->vecSample.size(); ++j){
			distance[j][0]=Sample_Distance(*train->vecSample[j], *test->vecSample[i]);
			distance[j][1]=train->vecSample[j]->get_label();
		}
		sort(distance, 0, train->vecSample.size()-1);
		predictions[i]->prediction = most_popular(distance, k);
		

	
}
	return predictions;
}
double Sample_Distance(Sample sample1, Sample sample2){
	double distance = 0;
	for(unsigned int i = 0; i<sample1.get_features().size(); ++i)
		distance += pow(sample1.get_features()[i]-sample2.get_features()[i],2);
	distance = sqrt(distance);
	return distance;
}
void sort( double tab[][2], int left, int right )
{
    int i = left;
    int j = right;
    double x = tab[( left + right ) / 2 ][0];
    do
    {
        while( tab[ i ][0] < x )
             i++;
        
        while( tab[ j ][0] > x )
             j--;        
        if( i <= j )
        {
            swap( tab[ i ][0], tab[ j ][0] );
             swap( tab[ i ][1], tab[ j ][1] );            
            i++;
            j--;
        }
    } while( i <= j );
    
    if( left < j ) sort( tab, left, j );
    
    if( right > i ) sort( tab, i, right );
    
}
int most_popular(double tab[][2], int k){
	int v = 0;
	for(int i =0; i<k; ++i)
		if(v<tab[i][1])
			v = tab[i][1];
	int table[v+1];
	for(int i = 0; i<=v; ++i)
		table[i]=0;
	for(int i = 0; i<k; ++i)
		++table[(int)tab[i][1]];
	int most_popular = 0;
	int out =0;
	for(int i = 0; i<=v; ++i){
		if(most_popular<table[i]){
			most_popular=table[i];
			out = i;}}
			
	return out;
}

