#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstddef>
#include "Nmea_Format.h"

using namespace std;

int Nmea_Format::count = 0;

void Nmea_Format::Token(char *line)
{
	bufIndex = 0;

	char *token = new char;

	token = strtok(line, ",");
	while (token != NULL)
	{
		tok_buf[bufIndex] = token;
		token = strtok (NULL, ",");
		bufIndex++;
	}
}

void Nmea_Format::File_FullPath()
{
	const wchar_t FilePath[] = L"C:\\test.txt";
	full_path[80];
	int ret;

	//printf ("wchar_t string: %ls \n",FilePath);

	ret = wcstombs ( full_path, FilePath, sizeof(full_path) );
	if (ret==80) 
		full_path[79]='\0';
	//if (ret) 
		//printf ("multibyte string: %s \n",full_path);
}

