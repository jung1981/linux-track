#include "scp_form.h"
#include <iostream>

ScpForm::ScpForm(QWidget *parent) :QWidget(parent)
{
  ui.setupUi(this);
  yaw = new SCurve("Yaw", "Yaw - looking left/right", "Left", "Right", ui.SCPYaw);
  pitch = new SCurve("Pitch", "Pitch - looking up/down", "Up", "Down", ui.SCPPitch);
  roll = new SCurve("Roll", "Roll - tilting head left/right", 
		    "Counter-clockwise", "Clockwise", ui.SCPRoll);
  x = new SCurve("Xtranslation", "Sideways translation", "Left", "Right", ui.SCPX);
  y = new SCurve("Ytranslation", "Up/down translation", "Up", "Down", ui.SCPY);
  z = new SCurve("Ztranslation", "Back/forth translation", "Back", "Forth", ui.SCPZ);
}

void ScpForm::reinit()
{
  yaw->reinit();
  pitch->reinit();
  roll->reinit();
  x->reinit();
  y->reinit();
  z->reinit();
}

void ScpForm::setSlaves(QDoubleSpinBox *pitchLM, QDoubleSpinBox *pitchRM,
                        QDoubleSpinBox *rollLM, QDoubleSpinBox *rollRM,
                        QDoubleSpinBox *yawLM, QDoubleSpinBox *yawRM,
                        QDoubleSpinBox *xLM, QDoubleSpinBox *xRM,
                        QDoubleSpinBox *yLM, QDoubleSpinBox *yRM,
                        QDoubleSpinBox *zLM, QDoubleSpinBox *zRM
                        )
{
  pitch->setSlaves(pitchLM, pitchRM);
  roll->setSlaves(rollLM, rollRM);
  yaw->setSlaves(yawLM, yawRM);
  x->setSlaves(xLM, xRM);
  y->setSlaves(yLM, yRM);
  z->setSlaves(zLM, zRM);
}

ScpForm::~ScpForm()
{
  delete yaw;
  delete pitch;
  delete roll;
  delete x;
  delete y;
  delete z;
}

void ScpForm::on_SCPCloseButton_pressed()
{
  close();
}

void ScpForm::updatePitch(float newPitch)
{
  pitch->movePoint(newPitch);
}

void ScpForm::updateRoll(float newRoll)
{
  roll->movePoint(newRoll);
}

void ScpForm::updateYaw(float newYaw)
{
  yaw->movePoint(newYaw);
}

void ScpForm::updateX(float newX)
{
  x->movePoint(newX);
}

void ScpForm::updateY(float newY)
{
  y->movePoint(newY);
}

void ScpForm::updateZ(float newZ)
{
  z->movePoint(newZ);
}

