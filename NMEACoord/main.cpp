#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Nmea_Format.h"

using namespace std;

int main () {

	Nmea_Format nmeaf;	
	Nmea_Coord nmeac;
	
	nmeaf.version= "001\0";
	nmeaf.File_FullPath();
	
	ifstream inf;
	ofstream outf;

	char line[80] = {0, };
	//int size = 0;

	streampos size;
	char * memblock;

	inf.open(nmeaf.full_path);
	outf.open("nmea_coord.bin", ios::binary);
	int	bufIndex = 0;
	if (inf.is_open()) 
	{
		while (!inf.eof()) 
		{
			inf.getline(line, 80);

			nmeac.GPRMC(line);
			nmeac.GPGGA(line);
			
		}
		inf.seekg(0, ios::end);
		size = inf.tellg();

		
		//inf.seekg (0, ios::beg);

		//memblock = new char [size];
		//outf.write(memblock, size);
	}
	else 
	{
		cout << "������ ã�� �� �����ϴ�!" << endl;
	}

	//vector<char> buf(size);

	//inf.read(&buf[0], size);
	//outf.write(&buf[0], size);

	
	cout << "���� " << nmeaf.version << endl;
	cout << "���ϻ����� " << size << endl;
	cout << "ī��Ʈ " << nmeaf.count << endl;
	cout << "��ȣ �������� " << endl;

	inf.close();
	outf.close();
	return 0;
}