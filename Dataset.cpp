#include "Dataset.h"
using namespace std;
	bool Dataset::push_back(Sample* Sample){
		if(this->vecSample.size()){
			if(Sample->get_features().size() != vecSample[0]->get_features().size())
					return false;
		}
		this->vecSample.push_back(Sample);
		return true;
	}
