#include "Writer.h"

void Writer::write(rectangle MER) {

	os << MER.lb.x << " ";
	os << MER.lb.y << " ";
	os << MER.rt.x << " ";
	os << MER.rt.y << " " << std::endl;

}

Writer::Writer(std::ostream& output_stream): os(output_stream) {


}

void Writer::write_output_data(rectangle MER) {

	write(MER);

}
