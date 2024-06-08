#pragma once
#include "Core.h"

#include <GLFW/glfw3.h>

namespace KMG
{
	using KeyCode = uint16_t;

	namespace Key
	{
		enum : KeyCode
		{
			// From glfw3.h
			Space = 32,

			Num0 = 48, /* 0 */
			Num1 = 49, /* 1 */
			Num2 = 50, /* 2 */
			Num3 = 51, /* 3 */
			Num4 = 52, /* 4 */
			Num5 = 53, /* 5 */
			Num6 = 54, /* 6 */
			Num7 = 55, /* 7 */
			Num8 = 56, /* 8 */
			Num9 = 57, /* 9 */

			A = 65,
			B = 66,
			C = 67,
			D = 68,
			E = 69,
			F = 70,
			G = 71,
			H = 72,
			I = 73,
			J = 74,
			K = 75,
			L = 76,
			M = 77,
			N = 78,
			O = 79,
			P = 80,
			Q = 81,
			R = 82,
			S = 83,
			T = 84,
			U = 85,
			V = 86,
			W = 87,
			X = 88,
			Y = 89,
			Z = 90,

			/* Function keys */
			Escape = 256,
			Enter = 257,
			Tab = 258,
			Right = 262,
			Left = 263,
			Down = 264,
			Up = 265,

			LeftShift = 340,
			LeftControl = 341,
			LeftAlt = 342,
		};

		static uint32_t Pressed = GLFW_PRESS;
		static uint32_t Released = GLFW_RELEASE;
	}

	using MouseCode = uint16_t;

	namespace Mouse
	{
		enum : MouseCode
		{
			// From glfw3.h
			ButtonLeft = 0,
			ButtonRight = 1,
		};

		static uint32_t Pressed = GLFW_PRESS;
		static uint32_t Released = GLFW_RELEASE;
	}

	class Input
	{
	public:
		static bool GetKeyDown(KeyCode key);
		static bool GetMouseButtonDown(MouseCode button);
		static glm::vec2 GetMousePosition();
	};

	class Cursor
	{
	public:
		static bool GetCursorVisible() { return m_Visible; }
		static void SetCursorVisible(bool visible);
	private:
		static bool m_Visible;
	};
}
