#include "stdafx.h"
#include "AISeek.h"
#include "Vector2f.h"

using namespace AILogic;

void AISeek::Update(const float dt)
{
	// Get agent position from agent's GameObject
	Vector2f vAgentPos = m_pAgent->GetPositionVector2f();

	// Get target position
	Vector2f vTargetPosition = m_pAgent->GetTargetVector2f();

	// Get the direction to the target
	Vector2f vDirection = vAgentPos.Direction(vTargetPosition);

	// Normalize the direction
	Vector2f vNormDir = vDirection.Normalised();

	// Multiply the direction by the speed
	Vector2f vVelocity = vDirection.Multiply(m_pAgent->GetSpeed());

	// Multiply the velocity by time
	Vector2f vStep = vVelocity.Multiply(dt);
	
	// Apply the new position to the agent's GameObject
	m_pAgent->AdjustPosition(vStep.x, vStep.y, 0.0f);
}