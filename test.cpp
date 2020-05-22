#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	fstream output("objcode.txt", ios::out);

	output << "H^COPY^001000" << endl;
	output << "T^001000^10^000000^500000^6B0000^500000^454F46^F0" << endl;
	output << "T^001001^02^1010" << endl;
	output << "T^001004^02^1010" << endl;
	output << "T^001010^03^000001" << endl;
	output << "T^001007^02^1013" << endl;
	output << "T^001013^03^000002" << endl;
	output << "T^00100A^02^1016" << endl;
	output << "E^001000" << endl;
	return 0;
}