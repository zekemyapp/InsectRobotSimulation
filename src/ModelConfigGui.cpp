#include "ModelConfigGui.h"
#include "cinder/CinderImGui.h"

namespace ui = ImGui;

void ModelConfigGui::setup(ModelConfig * _config)
{
	config = _config;
}
void  ModelConfigGui::show()
{
	ui::ScopedWindow window("Config");
	if (ui::DragFloat("Leg Home Distance", &config->homeDistance, 1, 0, 300)) config->isDirty = true;
	if (ui::DragFloat("Upper Leg Size", &config->upperLegSize, 1, 0, 300)) config->isDirty = true;
	if (ui::DragFloat("Lower Leg Size", &config->lowerLegSize, 1, 0, 300)) config->isDirty = true;
	ImGui::Separator();
	if (ui::DragFloat("stepHeight", &config->stepHeight, 1, 0, 100)) config->isDirty = true;
	if (ui::DragInt("stepPower", &config->stepPower, 1, 0, 20)) config->isDirty = true;
	if (ui::DragFloat("stepTime", &config->stepTime, 0.1f, 0.1f, 20)) config->isDirty = true;
	ImGui::Separator();
	if (ui::DragFloat("Front Leg Angle", &config->frontLegAngle, 0.01f,-3.1415f, 3.1415f)) config->isDirty = true;
	if (ui::DragFloat3("Front Leg Pos", &config->frontLegStart.x, 1)) config->isDirty = true;
	ImGui::Separator();
	if (ui::DragFloat("Middle Leg Angle", &config->middleLegAngle, 0.01f, -3.1415f, 3.1415f)) config->isDirty = true;
	if (ui::DragFloat3("Middle Leg Pos", &config->middleLegStart.x, 1)) config->isDirty = true;
	ImGui::Separator();
	if (ui::DragFloat("Back Leg Angle", &config->backLegAngle, 0.01f, -3.1415f, 3.1415f)) config->isDirty = true;
	if (ui::DragFloat3("Back Leg Pos", &config->backLegStart.x, 1)) config->isDirty = true;




	
	
}