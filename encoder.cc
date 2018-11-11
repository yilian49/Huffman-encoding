#include <iostream>
#include "bitio.hh"
#include "huffman.hh"
#include <fstream>

int main(int argc, char** argv)
{
	if (argc < 1)
	{
		std::cout<<"need both input and output";
	}


	auto input_file_name = argv[1];
	std::string comp = ".comp";
	std::string input_file_name_string(input_file_name);
	auto output_file_name = input_file_name_string + comp;

	std::ifstream input_file(input_file_name, std::ios::in);

	std::ofstream output_file(output_file_name, std::ios::out);

	// check if the file is open
	if (!input_file.is_open())
	{
		std::cout<<"No such file";
		exit(1);
	}

	Huffman huff;
	char c;
	std::vector<bool> c_bits;

	BitIO bitio(&output_file, nullptr);

	while (input_file.get(c))
	{
		c_bits = huff.encode(c);
		for (long unsigned int i = 0; i < c_bits.size(); i++)
		{
			bitio.output_bit(c_bits[i]);
		}
	}

	for (auto b : huff.encode(Huffman::HEOF)) {
		bitio.output_bit(b);
	}

	return 0;
}
