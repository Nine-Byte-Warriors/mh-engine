#include "stdafx.h"
#include "UIElement.h"
#include "Graphics.h"

void UIElement::Initialize( const Graphics& gfx, ConstantBuffer<Matrices>* mat )
{
	m_cbMatrices = mat;
	m_pDevice = gfx.GetDevice();
	m_pContext = gfx.GetContext();
}

// Convert from unsigned char to understandble string fromat 
std::string UIElement::ConvertFromUnsignedCharToString( unsigned char input )
{
	std::string text;
	switch ( input )
	{
	// Other keys
	case VK_RETURN:
		text = "Return";
		break;

	case VK_SPACE:
		text = "Space";
		break;

	case VK_SHIFT:
	case VK_LSHIFT:
	case VK_RSHIFT:
		text = "Shift";
		break;

	case VK_CONTROL:
		text = "Ctrl";
		break;

	// Alt
	case VK_MENU:
		text = "alt";
		break;

	case VK_PAUSE:
		text = "Pause";
		break;

	case VK_ESCAPE:
		text = "ESC";
		break;

	case VK_CAPITAL:
		text = "CAPS LOCK";
		break;

	case VK_BACK:
		text = "BACKSPACE";
		break;

	case VK_TAB:
		text = "Tab";
		break;

	// Page up
	case VK_PRIOR:
		text = "page Up";
		break;

	// Page down
	case VK_NEXT:
		text = "page Down";
		break;

	case VK_END:
		text = "End";
		break;

	case VK_HOME:
		text = "Home";
		break;

	case VK_SELECT:
		text = "Select";
		break;

	case VK_INSERT:
		text = "Ins";
		break;

	case VK_DELETE:
		text = "Del";
		break;

	case VK_HELP:
		text = "Help";
		break;

	case VK_SCROLL:
		text = "Scr Lock";
		break;

	case VK_CLEAR:
		text = "Clear";
		break;

	// Arrow keys
	case VK_UP:
		text = "Up Arrow";
		break;

	case VK_DOWN:
		text = "Down Arrow";
		break;

	case VK_LEFT:
		text = "Left Arrow";
		break;

	case VK_RIGHT:
		text = "Right Arrow";
		break;

	// Function keys
	case VK_F1:
		text = "F1";
		break;

	case VK_F2:
		text = "F2";
		break;

	case VK_F3:
		text = "F3";
		break;

	case VK_F4:
		text = "F4";
		break;

	case VK_F5:
		text = "F5";
		break;

	case VK_F6:
		text = "F6";
		break;

	case VK_F7:
		text = "F7";
		break;

	case VK_F8:
		text = "F8";
		break;

	case VK_F9:
		text = "F9";
		break;

	case VK_F10:
		text = "F10";
		break;

	case VK_F11:
		text = "F11";
		break;

	case VK_F12:
		text = "F12";
		break;

	// Numpad
	case VK_NUMLOCK:
		text = "Numlock";
		break;

	case VK_NUMPAD0:
		text = "Numpad 0";
		break;

	case VK_NUMPAD1:
		text = "Numpad 1";
		break;

	case VK_NUMPAD2:
		text = "Numpad 2";
		break;

	case VK_NUMPAD3:
		text = "Numpad 3";
		break;

	case VK_NUMPAD4:
		text = "Numpad 4";
		break;

	case VK_NUMPAD5:
		text = "Numpad 5";
		break;

	case VK_NUMPAD6:
		text = "Numpad 6";
		break;

	case VK_NUMPAD7:
		text = "Numpad 7";
		break;

	case VK_NUMPAD8:
		text = "Numpad 8";
		break;

	case VK_NUMPAD9:
		text = "Numpad 9";
		break;

	// Math keys
	case VK_MULTIPLY:
		text = "*";
		break;

	case VK_ADD:
		text = "+";
		break;

	case VK_SEPARATOR:
		text = "";
		break;

	case VK_SUBTRACT:
		text = "-";
		break;
	
	case VK_DECIMAL:
		text = ".";
		break;

	case VK_DIVIDE:
		text = "/";
		break;

	// Number key codes
	case 219:
		text = "[";
		break;

	case 221:
		text = "]";
		break;

	case 222:
		text = "#";
		break;

	case 186:
		text = ";";
		break;

	case 192:
		text = "'";
		break;

	case 188:
		text = ",";
		break;

	case 187:
		text = "=";
		break;

	case 223:
		text = "`";
		break;

	case 220:
		text = "\\";
		break;

	case 191:
		text = "/";
		break;

	case 190:
		text = ".";
		break;

	// All other keys
	default:
		text = input;
		break;
	}

	return text;
}