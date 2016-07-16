#pragma once


#include "engine/lumix.h"


namespace Lumix
{

	class IAllocator;
	struct Vec2;
	template <typename T> class DelegateList;

	class LUMIX_ENGINE_API InputSystem
	{
		public:
			enum InputType 
			{
				PRESSED,
				DOWN,
				MOUSE_X,
				MOUSE_Y,
				LTHUMB_X,
				LTHUMB_Y,
				RTHUMB_X,
				RTHUMB_Y,
				RTRIGGER,
				LTRIGGER
			};

			struct InputEvent
			{
				enum Type
				{
					POINTER_DOWN,
					POINTER_UP,
					POINTER_MOVE,
					KEY_DOWN,
					KEY_UP
				};

				Type type;
				union
				{
					struct {
						int button;
					} pointer;
					struct {
						int sym;
					} key;
				};
			};

		public:

			static InputSystem* create(IAllocator& allocator);
			static void destroy(InputSystem& system);

			virtual ~InputSystem() {}
			virtual void enable(bool enabled) = 0;
			virtual void update(float dt) = 0;
			virtual float getActionValue(uint32 action) = 0;
			virtual void injectEvent(InputEvent& event) = 0;
			virtual void injectMouseXMove(float rel, float abs) = 0;
			virtual void injectMouseYMove(float rel, float abs) = 0;
			virtual float getMouseXMove() const = 0;
			virtual float getMouseYMove() const = 0;
			virtual Vec2 getMousePos() const = 0;
			virtual void addAction(uint32 action, InputType type, int key, int controller_id) = 0;
			virtual DelegateList<void(InputEvent&)>& eventListener() = 0;
	};



} // ~namespace Lumix
