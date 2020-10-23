#pragma once
#include <iostream>
#include "Types.h"

class Reader {

private:

	std::istream& is;
	input_data read();

public:

	Reader(std::istream& input_stream);
	input_data read_input_data();

};


