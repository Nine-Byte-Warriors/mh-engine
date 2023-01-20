#pragma once
#ifndef MAINMENU_UI
#define MAINMENU_UI

class Graphics;
#include "Shaders.h"
#include "Listener.h"
#include "TextRenderer.h"
#include "WidgetIncludes.h"

class UIScreen : public Listener
{
public:
	UIScreen() { AddToEvent(); }
	~UIScreen() { RemoveFromEvent(); }

	void Initialize( const Graphics& gfx, ConstantBuffer<Matrices>* mat, const std::vector<Widget>& widgets );
	void Update( const float dt, const std::vector<Widget>& widgets );
	void Draw( VertexShader& vtx, PixelShader& pix, XMMATRIX worldOrtho, TextRenderer* textRenderer );

	inline void SetWidgets( const std::vector<Widget>& widgets ) noexcept { m_vWidgets = widgets; }
	inline void SetScreenSize( XMFLOAT2 size ) noexcept { m_vScreenSize = size; }
	
	void AddToEvent() noexcept;
	void RemoveFromEvent() noexcept;
	void HandleEvent( Event* event ) override;
private:
	void UpdateWidgets();

	// Inputs
	MouseData m_mouseData;
	std::string m_sKeys;

	// UI Widgets
	std::vector<Button_Widget> m_vButtons;
	std::vector<ColourBlock_Widget> m_vColourBlocks;
	std::vector<DataSlider_Widget> m_vDataSliders;
	std::vector<DropDown_Widget> m_vDropDowns;
	std::vector<EnergyBar_Widget> m_vEnergyBars;
	std::vector<Image_Widget> m_vImages;
	std::vector<Input_Widget> m_vInputs;
	std::vector<PageSlider_Widget> m_vPageSliders;

	// Graphics
	XMFLOAT2 m_vScreenSize;
	std::vector<Widget> m_vWidgets;
	ConstantBuffer<Matrices>* m_cbMatrices;
	Microsoft::WRL::ComPtr<ID3D11Device> m_pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_pContext;
	
	// GitHub link
	bool m_bOpen = true;
	bool m_bOpenLink = false;

	// Page slider data
	bool m_bLoadFlag = true;
	bool m_bUpdateSlider = false;
	XMFLOAT2 m_fBoxPos, m_fBoxSize;
	float m_fCurrentY, m_fCurrentPY;

	// Widget data
	int m_iSliderStart = 50;
	UINT32 m_uLevelTo = 0;
	float m_fPlayerHealth;

	// Button state textures
	std::vector<std::string> m_textures =
	{
		"Resources\\Textures\\UI\\Button\\ButtonIdle.png",
		"Resources\\Textures\\UI\\Button\\ButtonActive.png",
		"Resources\\Textures\\UI\\Button\\ButtonActive.png"
	};

	std::vector<std::string> m_texturesDD =
	{
		"Resources\\Textures\\UI\\Drop-Down\\DropDownMain.png",
		"Resources\\Textures\\UI\\Drop-Down\\DropDownOther.png",
		"Resources\\Textures\\UI\\Drop-Down\\DropDownOther.png"
	};

	std::vector<std::string> m_texturesDDButton =
	{
		"Resources\\Textures\\UI\\Drop-Down\\DropDownButtonIdle.png",
		"Resources\\Textures\\UI\\Drop-Down\\DropDownButtonHover.png",
		"Resources\\Textures\\UI\\Drop-Down\\DropDownButtonHover.png"
	};

	// Logo from https://www.flaticon.com/free-icon/github_5968896
	std::vector<std::string> m_texturesGithub =
	{
		"Resources\\Textures\\github_logo.png",
		"Resources\\Textures\\github_logo.png",
		"Resources\\Textures\\github_logo.png"
	};
};

#endif