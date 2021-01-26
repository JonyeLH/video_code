#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <algorithm>

#include "LH_RATE_CONTROL.h"
using namespace std;

#ifdef LH_RATE_CONTROL
RateControl* MY_TEST;
#endif 


RateControl::RateControl()
{

}

RateControl::~RateControl()
{

}

void RateControl:: INIT_FEATURE_FLAG()
{

}

void RateControl::cout_feature(bool outputflag, int lx, int ly, int lwidth, int lheight)
{
	if (outputflag) 
	{
		std::cout << lx << " " << ly << " " << lwidth << " " << lheight << " ______________________" << std::endl;
		std::cout
			<< " TargetBits: " << TargetBits
			<< std::endl
			<< " ActualBits: " << ActualBits
			<< std::endl
			<< " PIC_POC: " << PIC_POC
			<< std::endl
			<< " PIC_TId: " << PIC_TId
			<< std::endl
			<< " PIC_BPP: " << PIC_BPP
			<< std::endl
			<< " PIC_QP: " << PIC_QP
			<< std::endl
			<< " PIC_MSE: " << PIC_MSE
			<< std::endl
			<< " PIC_PSNR: " << PIC_PSNR
			<< std::endl
			<< " PIC_ALPHA: " << PIC_ALPHA
			<< std::endl
			<< " PIC_BETA: " << PIC_BETA
			<< std::endl
			//<< " ORI_QT_var: " << ORI_QT_var
			//<< std::endl
			//<< " ORI_BTH_var: " << ORI_BTH_var
			//<< std::endl
			//<< " ORI_BTV_var: " << ORI_BTV_var
			//<< std::endl
			//<< " ORI_TTH_var: " << ORI_TTH_var
			//<< std::endl
			//<< " ORI_TTV_var: " << ORI_TTV_var
			//<< std::endl
			<< " Action: " << Action
			<< std::endl;

	}
	outputflag = 0;
}

void RateControl::READ_RL_DATA(int lweight, int lheight)
{

}

void RateControl::save_RL_DATA(int lweight, int lheight)
{

}

void RateControl::reset_RL_DATA(int lweight, int lheight)
{

}

void RateControl::DQN_set_action(int lweight, int lheight)
{

}

