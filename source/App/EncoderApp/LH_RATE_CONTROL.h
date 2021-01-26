#pragma once
#include<iostream>
#include<fstream>
#include<cmath>

#define LH_RATE_CONTROL	//initQP +-2
#define LH_DEBUG	//基本测试
#define LH_TEST		//参数提取
#define LH_RL_USED	//网络的实现

/************************  训练数据生成	************************/
//#define GET_TRAIN_DATA
#define Generate_TAINDATA
#define GENERATE_SLICE_DATA

class RateControl
{
public:
	RateControl();
	~RateControl();

	int input_video_height = 0;
	int input_video_width = 0;

	/************************  INIT_FEATURE	************************/
	int TargetBits = 0;
	int ActualBits = 0;
	int PIC_POC = 0;
	int PIC_TId = 0;
	double PIC_BPP = 0;
	int PIC_QP = 0;
	double PIC_MSE = 0;
	double PIC_PSNR = 0;
	double PIC_ALPHA = 0;
	double PIC_BETA = 0;

	int Action = 0;

	void INIT_FEATURE_FLAG();

	bool outputflag = 0;

	void cout_feature(bool outputflag, int lx, int ly, int lwidth, int lheight);

	/**********************	  INIT_RL_DATA	 ************************/
	float RL_MAP_DATA[5][5][10] = { 0 };
	float RL_DATA[10] = { 0 };
	void READ_RL_DATA(int lweight, int lheight);
	void save_RL_DATA(int lweight, int lheight);
	void reset_RL_DATA(int lweight, int lheight);
	void DQN_set_action(int lweight, int lheight);

private:
	/************************   网络实现部分   ************************/
#ifdef LH_RL_USED
#define FEATURES 10
#define LAYER1_NURALNUM 16
#define OUTPUT_NUM 1


	/////////////	net_layer	///////////////////
	void fc_first_relu(
		float FEATURE1, float FEATURE2, float FEATURE3,
		float FEATURE4, float FEATURE5, float FEATURE6,
		float FEATURE7, float FEATURE8, float FEATURE9,
		float FEATURE10, float FEATURE11,
		float  w[][LAYER1_NURALNUM], float *b, int inputdim, int outputdim, float *fc_result);

	void fc(float *input, float w[][OUTPUT_NUM], float *b, int inputdim, int outputdim, float *fc_result, bool relu);


	///////////////	input_data	////////////////
	//need load from encoder


	///////////////	net_param	///////////////////
	//need load form train


	//////////////	Layer1	////////////////////
	//float **dqn_w1;
	float dqn_w1[FEATURES][LAYER1_NURALNUM];
	int dqn_w1_inputdim = FEATURES;
	int dqn_w1_outputdim = LAYER1_NURALNUM;

	float b1[LAYER1_NURALNUM];
	int b1_dim = LAYER1_NURALNUM;

	float fc1[LAYER1_NURALNUM];

	//////////////	Layer2	////////////////////
	//float **dqn_w2;
	float dqn_w2[LAYER1_NURALNUM][OUTPUT_NUM];
	int dqn_w2_inputdim = LAYER1_NURALNUM;
	int dqn_w2_outputdim = OUTPUT_NUM;

	float b2[OUTPUT_NUM];
	int b2_dim = OUTPUT_NUM;

	float fc2[OUTPUT_NUM];

#endif 

};

#ifdef LH_RATE_CONTROL
extern RateControl* MY_TEST;
#endif