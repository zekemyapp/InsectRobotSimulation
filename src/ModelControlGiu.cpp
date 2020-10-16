#include "ModelControlGui.h"
#include "cinder/CinderImGui.h"

namespace ui = ImGui;

void ModelControlGui::setup(ModelControl * _control) 
{
	control = _control;
}
void  ModelControlGui:: show() 
{
	ui::ScopedWindow window("Control");
	if (ui::DragFloat("stepSpeed", &control->timeScale, 0.1, 0.2, 5)) control->isDirty = true;
	if (ui::DragFloat("move Distance", &control->moveDistance, 1, 0, 45)) control->isDirty = true;
	if (ui::DragFloat("move Angle", &control->moveAngle, 0.01, -3.1415, 3.1415)) control->isDirty = true;

	if (ui::DragFloat("turnAngle", &control->turnAngle, 0.01, -3.1415 / 4, 3.1415 / 4)) control->isDirty = true;
	if (ui::Button("stop"))
	{
		control->isDirty = true;
		control->moveDistance = 0;
		control->moveAngle = 0;
		control->turnAngle = 0;
	}
	if (ui::Button("move"))
	{
		control->isDirty = true;
		control->moveDistance = 30;
		control->moveAngle = 0;
		control->turnAngle = 0;
	}
	ui::Separator();

	if (ui::DragFloat("body height", &control->rootHeight, 1, 0, 300)) control->isDirty = true;
	if (ui::DragFloat("body offset forward", &control->rootOffX, 1, -100, 100)) control->isDirty = true;
	if (ui::DragFloat("body offset sideways", &control->rootOffZ, 1, -100, 100)) control->isDirty = true;


	if (ui::DragFloat("body rotX", &control->rootRotX, 0.01, -3.1415, 3.1415)) control->isDirty = true;
	if (ui::DragFloat("body rotY", &control->rootRotY, 0.01, -3.1415, 3.1415)) control->isDirty = true;
	if (ui::DragFloat("body rotZ", &control->rootRotZ, 0.01, -3.1415, 3.1415)) control->isDirty = true;



	
	if (ui::Button("reset")) 
	{ 
		control->isDirty = true;
		control->rootOffX = 0;
		control->rootOffZ = 0;
		control->rootRotX = 0;
		control->rootRotY = 0;
		control->rootRotZ = 0;
	}
}