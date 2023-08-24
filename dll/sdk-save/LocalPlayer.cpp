#include "localPlayer.hpp"
#include "minecraft.hpp"

#include <cmath>

LocalPlayer::LocalPlayer(jobject obj, Minecraft *mc) : Player(obj, mc)
{
	m_sendQueueFID = m_mc->getEnv()->GetFieldID(m_cls, "a", "Lbcy;");
}

void LocalPlayer::strafe(float speed)
{
	if (!(getMoveStrafing() != 0.0 || getMoveForward() != 0.0))
		return;

	double yaw = getDirection();

	setMotionX(-sin(yaw) * speed);
	setMotionZ(cos(yaw) * speed);
}

double toRadians(float degrees)
{
	return degrees * (3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679 / 180);
}

double LocalPlayer::getDirection()
{
	float rotationYaw = getRotationYaw();
	if (this->getMoveForward() < 0.0f)
	{
		rotationYaw += 180.0f;
	}
	float forward = 1.0f;
	if (this->getMoveForward() < 0.0f)
	{
		forward = -0.5f;
	}
	else if (this->getMoveForward() > 0.0f)
	{
		forward = 0.5f;
	}
	if (this->getMoveStrafing() > 0.0f)
	{
		rotationYaw -= 90.0f * forward;
	}
	if (this->getMoveStrafing() < 0.0f)
	{
		rotationYaw += 90.0f * forward;
	}
	return toRadians(rotationYaw);
}

NetHandlerPlayClient *LocalPlayer::getSendQueue()
{
	return new NetHandlerPlayClient(m_mc->getEnv()->GetObjectField(m_obj, m_sendQueueFID), m_mc);
}