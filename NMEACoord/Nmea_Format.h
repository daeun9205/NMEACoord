#ifndef Nmea_Format_
#define Nmea_Format_

using namespace std;

class Nmea_Format
{
private:
	
public:
	char *version;
	char full_path[80];
	static int count;


	char *tok_buf[32];
	int bufIndex;

	void File_FullPath();
	void CoordCount();
	void Token(char *line);
};


class Nmea_Coord : public Nmea_Format
{
private:

public:
	char *Sentence;
	double Latitude;
	double Longitude;
	int offset;
	int UTCtime;
	int KORtime;
	
	int temp;

	char setUTCtime[4];
	char setKORtime[4];

	char * result[5];

	void GPRMC(char *line);
	void GPGGA(char *line);
	void Cal_Latitude(int temp);
	void Cal_Longitude(int temp);
	void UTC_time();
	void KOR_time();
};

#endif