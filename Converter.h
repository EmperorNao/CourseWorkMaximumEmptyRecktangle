#pragma once
#include "Types.h"

class Converter {

private:

	MERdata convert(input_data d, int dist);

public:

	Converter();
	MERdata get_converted_data(input_data d, int dist);
	
};

