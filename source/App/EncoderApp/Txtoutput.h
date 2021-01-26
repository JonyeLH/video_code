#pragma once

#define _wTxtOutput
#include <iostream>
#include <fstream>
#include <time.h>
#define LH_OUTPUT

class wTxtOutput
{
private:
	int m_SeqNum;
	int m_qp;
	double m_psnr;
	double m_bitrate;

public:
	wTxtOutput();
	~wTxtOutput();
	void GetSequenceParas(std::string input_sequence, int qp);
	void GetPSNR(double psnr);
	void GetBitrate(double br);
	void TxtOutput(std::string output, double tot_time);

};

#ifdef LH_OUTPUT
extern wTxtOutput *MyOutput;
#endif


