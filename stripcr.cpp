#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: stripcr <input file>" << std::endl;
		return -1;
	}
	
	std::ifstream ifs(argv[1] , std::ios::binary);
	
	if(!ifs.is_open())
	{
		std::cerr << "Error: unable to open " << argv[1] << std::endl;
		return -1;
	}
	else
	{
		std::string line;
		std::string outfile(argv[1]);
		outfile += "tmp";
		std::ofstream ofs(outfile, std::ios::binary);
		
		while(!ifs.eof())
		{
			std::getline(ifs,line);
			for(auto &c : line)
			{
				if( c != '\r')
					ofs << c;
			}
			ofs << '\n';
		}
		
		ofs.close();
		ifs.close();
		
		if(remove(argv[1]))
		{
			std::cerr << "Failed to delete file" << std::endl;
			return -1;
		}
		
		if(rename(outfile.c_str(), argv[1]))
		{
			std::cerr << "Failed to rename file" << std::endl;
			return -1;
		}
	}
	return 0;
}
