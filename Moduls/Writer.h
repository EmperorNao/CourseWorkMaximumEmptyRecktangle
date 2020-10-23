#pragma once
#include <iostream>
#include "Types.h"

class Writer
{

private:

	std::ostream& os;
	void write(rectangle MER);

public:

	Writer(std::ostream& output_stream);
	void write_output_data(rectangle MER);

};

