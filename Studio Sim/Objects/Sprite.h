#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "ConstantBuffer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "structures.h"
#include "Texture.h"

struct Vertex2D
{
	XMFLOAT3 Position;
	XMFLOAT2 TexCoord;
};

/// <summary>
/// Create a 2D sprite object.
/// Inherits from GameObject2D.h to allow for modification of position/rotation/scale data in 2D space.
/// </summary>
class Sprite
{
public:
	bool Initialize( ID3D11Device* device, ID3D11DeviceContext* context,
		std::string spritePath, ConstantBuffer<Matrices2D>& cb_vs_vertexshader_2d,
		float width = 64.0f, float height = 64.0f );
	bool Initialize( ID3D11Device* device, ID3D11DeviceContext* context,
		Colour spriteColour, ConstantBuffer<Matrices2D>& cb_vs_vertexshader_2d,
		float width = 64.0f, float height = 64.0f );

	void Draw( XMMATRIX worldMatrix, XMMATRIX orthoMatrix );
	void UpdateBuffers( ID3D11DeviceContext* context );

	inline float GetWidth() const noexcept { return m_fWidth; }
	inline void SetWidth( float width ) noexcept { m_fWidth = width; }

	inline float GetHeight() const noexcept { return m_fHeight; }
	inline void SetHeight( float height ) noexcept { m_fHeight = height; }

	inline int GetSSRows() const noexcept { return m_iRows; }
	inline void SetSSRows( int rows ) noexcept { m_iRows = rows; }

	inline int GetSSColumns() const noexcept { return m_iColumns; }
	inline void SetSSColumns( int columns ) noexcept { m_iColumns = columns; }

	void UpdateTex( ID3D11Device* device, std::string tex ) { texture->UpdateTexture( device, tex ); }
	void UpdateTex( ID3D11Device* device, Colour tex ) { texture->UpdateTexture( device, tex ); }
private:
	bool InitializeInternal( ID3D11Device* device, ID3D11DeviceContext* context,
		ConstantBuffer<Matrices2D>& cb_vs_vertexshader_2d, float width, float height );

	float m_fWidth;
	float m_fHeight;
	int m_iRows = 2;
	int m_iColumns = 2;

	std::unique_ptr<Texture> texture;
	ConstantBuffer<Matrices2D>* cb_vs_matrix_2d = nullptr;
	ConstantBuffer<Animation> m_cbAnimation;
	ID3D11DeviceContext* context = nullptr;

	VertexBuffer<Vertex2D> vertices;
	IndexBuffer indices;
	Colour colour;
};

#endif