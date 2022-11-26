#include <fstream>


class File
{
	public:
		std::ifstream in(const char* path = "./in.txt");
		std::ofstream out(const char* path = "./out.txt");
};

struct msg
{
  static const std::string err_fin;
  static const std::string err_fout;
	static const std::string err_size;
	static const std::string err_name;
	static const std::string err_num;
	static const std::string success;
};

enum field
{
	city,
	street,
	house,
	flat
};

class Location
{
	private:
		std::string city;
		std::string street;
		int house;
		int flat;
	public:
		Location(
				std::string city = "none", 
				std::string street = "none",
				int house = 0,
				int flat = 0
				);
		std::string strGet(std::string splitter = ", ");
		std::string cityGet();
		bool strSet(std::string val, field index);
};

class Sort
{
	private:
		Location* locations;
		int size;
	public:
		Sort(Location* locations, int size);
		void alphabet();
};
