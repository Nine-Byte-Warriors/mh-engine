#pragma once
#ifndef COLLIDER_H
#define COLLIDER_H

#include "Vector2f.h"
#include "Transform.h"
#include "LayerMask.h"
#include <functional>

const enum class ColliderType
{
    None,
    Box,
    Circle
};

enum class CollisionState
{
    Entering,
    Staying,
    Leaving
};

class BoxCollider;
class CircleCollider;
class Collider
{
public:
    Collider() {}
    Collider(bool trigger, std::shared_ptr<Transform>& transform) : m_isTrigger(trigger), m_transform(transform) {}
    Collider(Collider& col);

protected:
    ColliderType m_type = ColliderType::None;
    bool m_isTrigger = false;
    LayerMask m_collisionMask = LayerMask(true, true, true, true);
    LayerNo m_layer = LayerNo::Enemy;

    std::shared_ptr<Transform> m_transform;
    Vector2f m_lastValidPosition = Vector2f(0, 0);

    std::vector<std::shared_ptr<Collider>> m_curCollisions;
    std::map<std::shared_ptr<Collider>, CollisionState> m_collisions;

    std::vector<std::function<void(Collider&)>> m_onEnterCallbacks;
    std::vector<std::function<void(Collider&)>> m_onLeaveCallbacks;

    std::vector<std::shared_ptr<Collider>> m_blackList;

public:
    //Helpers
    float Clamp(float min, float max, float value);
    template <typename T>
    void RemoveDuplicateElements(std::vector<T>& vec);

    //
    inline const ColliderType GetColliderType() { return m_type; }

    inline void SetIsTrigger(bool trigger) noexcept { m_isTrigger = trigger; }
    inline bool GetIsTrigger() noexcept { return m_isTrigger; };

    inline void SetLayer(LayerNo layer) { m_layer = layer; };
    inline LayerNo GetLayer() const noexcept { return m_layer; };

    inline void SetCollisionMask(LayerMask collisionMask) noexcept { m_collisionMask = collisionMask; m_collisionMask = collisionMask; }
    inline LayerMask GetCollisionMask() noexcept { return m_collisionMask; };

    inline std::shared_ptr<Transform> GetTransform() const noexcept { return m_transform; }

    inline Vector2f GetLastValidPosition() const noexcept { return m_lastValidPosition; }
    inline void UpdateLastValidPosition() noexcept { m_lastValidPosition = m_transform->GetPosition(); }//



    inline void LogCollision(std::shared_ptr<Collider>& col) { m_curCollisions.push_back(col); }


    virtual Vector2f ClosestPoint(Vector2f position) noexcept { return Vector2f(); }

    //Collision Checks
    virtual bool ToBox(BoxCollider& box) noexcept { return false; }
    virtual bool ToCircle(CircleCollider& circle) noexcept { return false; }
    virtual bool ToPoint(Vector2f point) noexcept { return false; }
    virtual bool CollisionCheck(std::shared_ptr<Collider> collider) noexcept { return false; }

    //Collision Resolution
    virtual void Resolution(std::shared_ptr<Collider> collider) noexcept {}

    //Events
    //example of use td::function<void(Collider&)> f = std::bind(&Player::foo, this, std::placeholders::_1);
    void OnEnter(Collider& col);
    void OnLeave(Collider& col);
    inline void AddOnEnterCallback(std::function<void(Collider&)> callback) { m_onEnterCallbacks.push_back(callback); };
    inline void AddOnExitCallback(std::function<void(Collider&)> callback) { m_onLeaveCallbacks.push_back(callback); };
    inline void ClearOnEnterCallbacks() { m_onEnterCallbacks.clear(); };
    inline void ClearOnExitCallbacks() { m_onLeaveCallbacks.clear(); };


    
    //Managing logged collisions against collider
    void ManageCollisions();
    void ProcessCollisions();

    void Update();

    //Blacklist ignore specific colliders
    inline void AddToBlackList(std::shared_ptr<Collider> collider) { m_blackList.push_back(collider); };
    inline std::vector<std::shared_ptr<Collider>> GetBlackList() { return m_blackList; };
    inline void RemoveBlackListEntry(int element) { m_blackList.erase(m_blackList.begin() + element); }
    inline void ClearBlackList() { m_blackList.clear(); };
    bool CheckBlackList(std::shared_ptr<Collider> collider);

};

#endif