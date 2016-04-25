#include "Sample.h"

using namespace std;

Sample::Sample(std::vector <float> features, int label){
	this->features = features;
	this->label = label;
}
int Sample::get_label(){
	return label;
}
vector <float> Sample::get_features(){
	return features;
}
