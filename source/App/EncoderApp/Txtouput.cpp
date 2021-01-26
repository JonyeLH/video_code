#include "TxtOutput.h"
#include <string>

wTxtOutput* MyOutput;


wTxtOutput::wTxtOutput() :m_SeqNum(-1), m_qp(0), m_psnr(0), m_bitrate(0)
{

}

wTxtOutput::~wTxtOutput()
{

}

void wTxtOutput::GetSequenceParas(std::string input_sequence, int qp)
{
	int k;
	std::string w_FileList[36] = {
		//A
		"Tango2_3840x2160_60f",
		"FoodMarket4_3840x2160_60",
		"Campfire_3840x2160_30",

		"CatRobot_3840x2160_60",
		"DaylightRoad2_3840x2160_60",
		"ParkRunning3_3840x2160_50",
		//B
		"MarketPlace_1920x1080_60",
		"RitualDance_1920x1080_60",
		"BasketballDrive_1920x1080_50",
		"BQTerrace_1920x1080_60",
		"Cactus_1920x1080_50",
		//C
		"RaceHorses_832x480_30",
		"BQMall_832x480_60",
		"PartyScene_832x480_50",
		"BasketballDrill_832x480_50",
		//D
		"BasketballPass_416x240_50",
		"BlowingBubbles_416x240_50",
		"BQSquare_416x240_60",
		"RaceHorses_416x240_30",
		//E
		"FourPeople_1280x720_60",
		"Johnny_1280x720_60",
		"KristenAndSara_1280x720_60",
		//F
		"ArenaOfValor_1920x1080_60",
		"BasketballDrillText_832x480_50",
		"SlideEditing_1280x720_30",
		"SlideShow_1280x720_20" 
	
		//HDR
		"BalloonFestival_1920x1080p_25_10b_pq_709_ct2020_420",
		"Hurdles_1920x1080p_50_10b_pq_709_ct2020_420_rev1",
		"Starting_1920x1080p_50_10b_pq_709_ct2020_420_rev1",
		"Market3_1920x1080p_50_10b_pq_709_ct2020_420_rev1",
		"ShowGirl2TeaserClip4000_1920x1080p_25_10b_pq_P3_ct2020_420_rev1",
		"SunRise_1920x1080p_25_10b_pq_709_ct2020_420",
		"DayStreet_3840x2160_60p_10bit_420_hlg",
		"FlyingBirds2_3840x2160p_60_10b_HLG_420",
		"PeopleInShoppingCenter_3840x2160_60p_10bit_420_hlg",
		"SunsetBeach2_3840x2160p_60_10b_HLG_420"

	};

	for (k = 0; k < 36; k++) {
		if (input_sequence.find(w_FileList[k]) != input_sequence.npos)//输入序列与测试序列对应
			break;
	}
	m_SeqNum = k;
	m_qp = qp;
}

void wTxtOutput::GetPSNR(double psnr)
{
	m_psnr = psnr;
}
void wTxtOutput::GetBitrate(double br)
{
	m_bitrate = br;
}

void wTxtOutput::TxtOutput(std::string output_file, double tot_time)
{
	//out 文件以输出方式打开(内存数据输出到文件)
	//app 以追加的方式打开文件
	std::ofstream fout(output_file, std::ios::out | std::ios::app);
	fout << m_SeqNum << "\t" << m_qp << "\t" << tot_time << "\t" << m_psnr << "\t" << m_bitrate << std::endl;
	fout.close();
}