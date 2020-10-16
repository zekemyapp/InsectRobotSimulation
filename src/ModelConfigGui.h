#pragma once
#include "ModelConfig.h"
class ModelConfigGui
{

public:
	ModelConfigGui()
		:config(nullptr) 
	{};
	void setup(ModelConfig * config);
	void show();

	ModelConfig * config;
};