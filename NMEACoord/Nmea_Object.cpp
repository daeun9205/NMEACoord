#include <cstdlib>
#include <cstring>
#include <iostream>

#include"Nmea_Format.h"

void Nmea_Coord::GPRMC(char *line)
{
	temp = 3;
	bufIndex = 0;
	if(strstr(line, "GPRMC"))
	{	
		Token(line);
		Sentence = "RMC\0";
		Cal_Longitude(temp);
		Cal_Latitude(temp);
		UTC_time();
		KOR_time();
		count++;
		bufIndex++;
	}
}

void Nmea_Coord::GPGGA(char *line)
{
	temp = 2;
	bufIndex=0;
	if(strstr(line, "GPGGA"))
	{
		Token(line);
		Sentence = "GGA\0";
		Cal_Longitude(temp);
		Cal_Latitude(temp);
		UTC_time();
		KOR_time();
		count++;
		bufIndex++;
		//result[] = {Sentence, setLatitude[bufIndex], 
	}
}

void Nmea_Coord::Cal_Latitude(int temp)
{
	Latitude = atof(tok_buf[temp])/100;

	int degrees = (int) Latitude;
	
	double decMinutesSeconds = ((Latitude - degrees)) / .60;

	Latitude = degrees + decMinutesSeconds;

	//printf("%f\n", Latitude);

	//setLatitude[bufIndex]= Latitude;

	//printf("%f\n", setLatitude[bufIndex]);
	
}

void Nmea_Coord::Cal_Longitude(int temp)
{
	Longitude = atof(tok_buf[temp+2])/100;

	int degrees = (int) Longitude;

	double decMinutesSeconds = ((Longitude - degrees)) / .60;

	Longitude = degrees + decMinutesSeconds;
	
	//printf("%f\n", Longitude);

	//setLongitude[bufIndex]= Longitude;

	//printf("%f\n", setLongitude[bufIndex]);
}

void Nmea_Coord::UTC_time()
{
	int hour, min, sec, temp;
	
	UTCtime = atoi(tok_buf[1]);

	hour = UTCtime / 10000;
	temp =UTCtime % 10000;

	min = temp / 100;
	temp = temp % 100;

	sec = temp;

	setUTCtime[0] = hour;
	setUTCtime[1] = min;
	setUTCtime[2] = sec;
	setUTCtime[3] = '\0';

	//printf("%c, %c, %c \n", hour, min, sec);
}

void Nmea_Coord::KOR_time()
{
	int hour, min, sec, temp;

	KORtime = atoi(tok_buf[1]);

	hour = (KORtime / 10000) + 9;
	temp =KORtime % 10000;

	min = temp / 100;
	temp = temp % 100;

	sec = temp;

	setKORtime[0] = hour;
	setKORtime[1] = min;
	setKORtime[2] = sec;
	setKORtime[3] = '\0';

	//printf("%d, %d, %d \n", hour, min, sec);

}