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
	std::string plaintext = ".plaintext";
	std::string input_file_name_string(input_file_name);
	auto output_file_name = input_file_name_string + plaintext;

	std::ifstream input_file(input_file_name, std::ios::in);

	std::ofstream output_file(output_file_name, std::ios::out);

	// check if the file is open
	if (!input_file.is_open())
	{
		std::cout<<"No such file";
		exit(1);
	}

	Huffman huff;

	BitIO bitio(nullptr, &input_file);

	auto save = bitio.input_bit();
	auto decode_int = huff.decode(save);
	while (decode_int != Huffman::HEOF)	
	{
		if(decode_int != -1)
		{
			output_file.put(decode_int);
		}
		save = bitio.input_bit();
		decode_int = huff.decode(save);
		}


	return 0;
}
