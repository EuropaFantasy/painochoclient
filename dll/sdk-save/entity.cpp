#include "entity.hpp"
#include "minecraft.hpp"

Entity::Entity(jobject obj, Minecraft *mc) : m_obj(obj), m_mc(mc)
{
  // MessageBox(NULL, "called", "status", MB_OK);
  // MessageBox(NULL, m_mc->getVersion(), "status", MB_OK);
  MessageBox(NULL, "called", "status", MB_OK);
  m_cls = m_mc->getEnv()->GetObjectClass(m_obj);

  if (m_mc->getClient() == Client::Forge)
  {
    m_setSprintingMID = m_mc->getEnv()->GetMethodID(m_cls, "func_70031_b", "(Z)V");
    m_isSneakingMID = m_mc->getEnv()->GetMethodID(m_cls, "func_225608_bj_", "()Z");
    m_ticksExistedFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70173_aa", "I");
    m_isDeadFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70128_L", "Z");
    m_motionXFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70159_w", "D");
    m_motionYFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70181_x", "D");
    m_motionZFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70179_y", "D");
    m_fallDistanceFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70143_R", "F");
    m_rotationYawFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70177_z", "F");
    m_rotationPitchFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70125_A", "F");
    m_getDistanceToEntityMID = m_mc->getEnv()->GetMethodID(m_cls, "func_70032_d", "(Lpk;)F");
    m_lastTickPosXFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70142_S", "D");
    m_lastTickPosYFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70137_T", "D");
    m_lastTickPosZFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70136_U", "D");
    m_posXFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70165_t", "D");
    m_posYFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70163_u", "D");
    m_posZFID = m_mc->getEnv()->GetFieldID(m_cls, "field_70161_v", "D");
    m_getEntityBoundingBoxMID = m_mc->getEnv()->GetMethodID(m_cls, "func_174813_aQ", "Laug;");
  }
  else if (m_mc->getClient() == Client::Lunar)
  {
    m_setSprintingMID = m_mc->getEnv()->GetMethodID(m_cls, "setSprinting", "(Z)V");
    m_isSneakingMID = m_mc->getEnv()->GetMethodID(m_cls, "isSneaking", "()Z");
    m_ticksExistedFID = m_mc->getEnv()->GetFieldID(m_cls, "ticksExisted", "I");
    m_isDeadFID = m_mc->getEnv()->GetFieldID(m_cls, "isDead", "Z");
    m_motionXFID = m_mc->getEnv()->GetFieldID(m_cls, "motionX", "D");
    m_motionYFID = m_mc->getEnv()->GetFieldID(m_cls, "motionY", "D");
    m_motionZFID = m_mc->getEnv()->GetFieldID(m_cls, "motionZ", "D");
    m_fallDistanceFID = m_mc->getEnv()->GetFieldID(m_cls, "fallDistance", "F");
    m_rotationYawFID = m_mc->getEnv()->GetFieldID(m_cls, "rotationYaw", "F");
    m_rotationPitchFID = m_mc->getEnv()->GetFieldID(m_cls, "rotationPitch", "F");
    m_getDistanceToEntityMID = m_mc->getEnv()->GetMethodID(m_cls, "getDistanceToEntity", "(Lpk;)F");
    m_lastTickPosXFID = m_mc->getEnv()->GetFieldID(m_cls, "lastTickPosX", "D");
    m_lastTickPosYFID = m_mc->getEnv()->GetFieldID(m_cls, "lastTickPosX", "D");
    m_lastTickPosZFID = m_mc->getEnv()->GetFieldID(m_cls, "lastTickPosZ", "D");
    m_posXFID = m_mc->getEnv()->GetFieldID(m_cls, "posX", "D");
    m_posYFID = m_mc->getEnv()->GetFieldID(m_cls, "posY", "D");
    m_posZFID = m_mc->getEnv()->GetFieldID(m_cls, "posZ", "D");
    m_getEntityBoundingBoxMID = m_mc->getEnv()->GetMethodID(m_cls, "getEntityBoundingBox", "Laug;");
  }
  else if (m_mc->getClient() == Client::Vanilla)
  {

    if (m_mc->getVersion() == Version::v189)
    {
      m_setSprintingMID = m_mc->getEnv()->GetMethodID(m_cls, "d", "(Z)V");
      m_isSneakingMID = m_mc->getEnv()->GetMethodID(m_cls, "av", "()Z");
      m_ticksExistedFID = m_mc->getEnv()->GetFieldID(m_cls, "W", "I");
      m_isDeadFID = m_mc->getEnv()->GetFieldID(m_cls, "I", "Z");
      m_motionXFID = m_mc->getEnv()->GetFieldID(m_cls, "v", "D");
      m_motionYFID = m_mc->getEnv()->GetFieldID(m_cls, "w", "D");
      m_motionZFID = m_mc->getEnv()->GetFieldID(m_cls, "x", "D");
      m_fallDistanceFID = m_mc->getEnv()->GetFieldID(m_cls, "O", "F");
      m_rotationYawFID = m_mc->getEnv()->GetFieldID(m_cls, "y", "F");
      m_rotationPitchFID = m_mc->getEnv()->GetFieldID(m_cls, "z", "F");
      m_getDistanceToEntityMID = m_mc->getEnv()->GetMethodID(m_cls, "g", "(Lpk;)F");
      m_lastTickPosXFID = m_mc->getEnv()->GetFieldID(m_cls, "P", "D");
      m_lastTickPosYFID = m_mc->getEnv()->GetFieldID(m_cls, "Q", "D");
      m_lastTickPosZFID = m_mc->getEnv()->GetFieldID(m_cls, "R", "D");
      m_posXFID = m_mc->getEnv()->GetFieldID(m_cls, "s", "D");
      m_posYFID = m_mc->getEnv()->GetFieldID(m_cls, "t", "D");
      m_posZFID = m_mc->getEnv()->GetFieldID(m_cls, "u", "D");
      m_getEntityBoundingBoxMID = m_mc->getEnv()->GetMethodID(m_cls, "aR", "Laug;");
    }
    else if (m_mc->getVersion() == Version::v1201 || m_mc->getVersion() == Version::v120)
    {
      MessageBox(NULL, "called", "status", MB_OK);
      m_setSprintingMID = m_mc->getEnv()->GetMethodID(m_cls, "g", "(Z)V");
    }
  }
}

void Entity::setSprinting(bool sprinting)
{
  m_mc->getEnv()->CallVoidMethod(m_obj, m_setSprintingMID, sprinting);
}

bool Entity::isSneaking()
{
  return m_mc->getEnv()->CallBooleanMethod(m_obj, m_isSneakingMID);
}

int Entity::getTicksExisted()
{
  return m_mc->getEnv()->GetIntField(m_obj, m_ticksExistedFID);
}

bool Entity::isDead()
{
  return m_mc->getEnv()->GetBooleanField(m_obj, m_isDeadFID);
}

double Entity::getMotionX()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_motionXFID);
}

void Entity::setMotionX(double x)
{
  m_mc->getEnv()->SetDoubleField(m_obj, m_motionXFID, x);
}

double Entity::getMotionY()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_motionYFID);
}

void Entity::setMotionY(double y)
{
  m_mc->getEnv()->SetDoubleField(m_obj, m_motionXFID, y);
}

double Entity::getMotionZ()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_motionZFID);
}

void Entity::setMotionZ(double z)
{
  m_mc->getEnv()->SetDoubleField(m_obj, m_motionXFID, z);
}

float Entity::getFallDistance()
{
  return m_mc->getEnv()->GetFloatField(m_obj, m_fallDistanceFID);
}

void Entity::setFallDistance(float fallDistance)
{
  m_mc->getEnv()->SetFloatField(m_obj, m_fallDistanceFID, fallDistance);
}

float Entity::getRotationYaw()
{
  return m_mc->getEnv()->GetFloatField(m_obj, m_rotationYawFID);
}

void Entity::setRotationYaw(float yaw)
{
  m_mc->getEnv()->SetFloatField(m_obj, m_rotationYawFID, yaw);
}

float Entity::getRotationPitch()
{
  return m_mc->getEnv()->GetFloatField(m_obj, m_rotationPitchFID);
}

void Entity::setRotationPitch(float pitch)
{
  m_mc->getEnv()->SetFloatField(m_obj, m_rotationPitchFID, pitch);
}

float Entity::getDistanceToEntity(Entity *entity)
{
  return m_mc->getEnv()->CallFloatMethod(m_obj, m_getDistanceToEntityMID, entity->getObj());
}

double Entity::getLastTickPosX()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_lastTickPosXFID);
}

double Entity::getLastTickPosY()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_lastTickPosYFID);
}

double Entity::getLastTickPosZ()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_lastTickPosZFID);
}

double Entity::getPosX()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_posXFID);
}

double Entity::getPosY()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_posYFID);
}

double Entity::getPosZ()
{
  return m_mc->getEnv()->GetDoubleField(m_obj, m_posZFID);
}

AxisAlignedBB *Entity::getEntityBoundingBox()
{
  return new AxisAlignedBB(m_mc->getEnv()->CallObjectMethod(m_obj, m_getEntityBoundingBoxMID), m_mc);
}

jobject Entity::getObj()
{
  return m_obj;
}